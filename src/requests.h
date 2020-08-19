/*
 * requests.h
 *
 *  Created on: 20.05.2019
 *      Author: Team OCP
 */

#pragma once

#include "shmDescriptionBase.h"
#include "symbol.h"
#include <string>

class Requests: public ShmDescriptionBase
{

public:
	Requests(Requests const&) = default;
	~Requests() = default;
	Requests(std::string descr, std::string version, std::list<Symbol> symbolList, std::string par_appName);

	const std::string getAppName() const;
	void setAppName(const std::string);

	bool operator== (const Requests& request);
	bool operator== (const std::string& par_appName);

};

