//////////////////////////////////////////////////////////////////////////////////////////
/// Rocket
/// Created on: 02.01.2020
///     Author: Shishkov Martin
///
/// \file DataExchangeBuffer.cpp
///
//////////////////////////////////////////////////////////////////////////////////////////

#include "ribConnection.h"
#include "log_datalayer.h"
#include "consistentDataTransfer.h"
#include "clockWrapperLinux.h"
#include "DataExchangeBuffer.h"
#include "configurationDataFactory.h"
#include <signal.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <string.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <pthread.h>

#define OK	0
#define ERROR	-1
#define clear() printf("\033[H\033[J")

using namespace RIB;

const string appName = "Remote_open_control_kit_enabled_target_(Rocket)";
const uint32_t sizeOfUserDataStruct = sizeof(UserDataStruct);
UserDataStruct myUserDataStruct = { };

int push(char* data, unsigned int size);

int push(char* data, unsigned int size) {
	memcpy(myUserDataStruct.diggermotionData, data, size);
	return OK;
}

void *stayAlive(void *userDataStruct) {
	UserDataStruct *f = (UserDataStruct *) userDataStruct;

	ConfigurationData configData = ConfigurationDataFactory::CreateDefaultConfiguration();
	configData.getAppData().setApplicationName(appName);

	RibConnection providerRibConnection = RibConnection::Create(configData.toString());
	providerRibConnection.RequestRibEnvironmentConfig();
	RIB::ConsistentDataTransfer consistentDataTransfer = providerRibConnection.addLifetimeBuffer(
				appName + "Shm",
				"Rocket motion for Digger",
				"V0.1",
				10,
				myUserDataStruct,
				1,
				sizeOfUserDataStruct
	);

	providerRibConnection.Connect();
	if (!providerRibConnection.IsConnected()) {
		log(STANDARD, "connect()", "Connection to RIB not possible");
		pthread_exit (NULL);
	}

	while (providerRibConnection.IsConnected()) {

		consistentDataTransfer.writeUserData(f);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	pthread_exit (NULL);
}

int connect() {

	pthread_t threads[1];
	int rc = pthread_create(&threads[0], NULL, stayAlive,
			(void *) &myUserDataStruct);
	if (rc) {
		log(STANDARD, "connect(), stayAlive", "unable to create thread");
		return ERROR;
	}

	return OK;
}

int disconnect() {
	//providerRibConnection.Disconnect(); //not implemented
	munlockall();
	return OK;
}

int send(char* data, unsigned int size) {
	if (sizeOfUserDataStruct >= size) {
		return push(data, size);
	}
	return ERROR;
}
