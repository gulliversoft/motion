/*
 * ConfigurationData.h
 *
 *  Created on: 03.05.2019
 *      Author: Team OCP
 */

#pragma once

#include "applicationData.h"
#include <string>

class ConfigurationData
{

public:
		
	~ConfigurationData() = default;
	ConfigurationData(ConfigurationData const&) = default;
	ConfigurationData& operator=(ConfigurationData const&) = default;
	bool operator==(ConfigurationData const&) const;

	ConfigurationData(const std::string type, const std::string version, ApplicationData applicationData, int sockFd = 0);

	const std::string& getDataType() const;

	const std::string& getInterfaceVersion() const;

    ApplicationData& getAppData();

	const ApplicationData& getAppData() const;

	std::string toString() const;

	bool isValid();

	int getSocketfd() const;

};

