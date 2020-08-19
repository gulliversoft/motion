/* * ribConnection.h * * Created on : 27.06.2019 * Author : Team OCP */

#pragma once

#include "configurationData.h"
#include "consistentDataTransfer.h"
#include <string>

class IRIBBaseDataStruct;

using std::string;

namespace RIB
{

	class RibConnection
	{

	public:

		///
		/// Creates a RIB Connection object based on the given connectionConfiguration string which represents a valid RIB json configuration.
		/// \param connectionConfiguration String with the connection configuration
		/// \return RibConnection object
		///
		static RibConnection Create(const string& connectionConfiguration);

		///
		/// get configuration data
		/// \return A ConfigurationData object which contains info to be able to connect to the RIB
		///
		ConfigurationData& getConfig();

		///
		/// Add a shared memory given information to build a Provides object and a struct containing the variables to be shared
		/// \param shmId string with shared memory identifier (name)
		/// \param descr optional description of the provided data set
		/// \param version optional version of the provided data set
		/// \param signal signal is raised when the provided data has changed
		/// \param dataStruct structure which contains the variables to be shared
		/// \param cycleTimeInMicroSeconds cycletime which is given to
		/// \param sizeOfUserDataStruct size of user data struct
		/// \return A ConsistentDataTransfer object to write consistent user data to the lifetime buffer
		///
		ConsistentDataTransfer addLifetimeBuffer(
			const string& shmIdentifier,
			const string& descr,
			const string& version,
			int signal,
			IRIBBaseDataStruct& dataStruct,
			uint64_t cycleTimeInMicroSeconds = 1,
			uint32_t sizeOfUserDataStruct = 0);


		///
		/// Requests the configuration data of the RIB environment.
		///
		void RequestRibEnvironmentConfig();


		///
		/// Establishes a connection to the RIB based on the given configuration.
		///
		void Connect();

		///
		/// Indicates if a connection to the RIB is established.
		/// \return true when the connection is established, otherwise false
		///
		bool IsConnected() const;
	};
}
