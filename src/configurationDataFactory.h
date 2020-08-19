/*
 * configurationDataFactory.h
 *
 *  Created on: 21.05.2019
 *      Author: Team OCP
 */

#pragma once

#include "configurationData.h"

using namespace RIB;


class ConfigurationDataFactory {
public:

	ConfigurationDataFactory(){};

	// Creates a mimimal ConfigurationData object with minimal set of default data that can be used to connect to RIB.
	static ConfigurationData CreateDefaultConfiguration();
	
};

