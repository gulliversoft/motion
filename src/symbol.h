/*
 * symbol.h
 *
 *  Created on: 20.05.2019
 *      Author: Team OCP
 */

#pragma once

#include <string>
#include <sys/types.h>

class Symbol
{
private:
	std::string name;
	std::string type;
	uint64_t sizeOf;
	uint64_t offset;

public:
	Symbol() : name(""), type(""), sizeOf(0), offset(0){};
	~Symbol() = default;

	Symbol(Symbol const&) = default;
	Symbol& operator=(Symbol const&) = default;	

	Symbol(std::string symbolName, std::string symbolType, uint64_t size, uint64_t symbolOffset);

	bool operator==(Symbol const& symbol);

};

