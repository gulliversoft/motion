/*
 * DataExchangeBuffer.h
 *
 *  Created on: 02.01.2020
 *      Author: Shishkov Martin
 */

#pragma once

#include "IRIBBaseDataStruct.h"
#include <list>

using std::list;

///
/// Structure for data exchange
///
struct UserDataStruct : public IRIBBaseDataStruct
{
public:

	uint8_t diggermotionData[1024 * 100];

	list<Symbol> getSymbolList()
	{
		list<Symbol> symbolList;
		symbolList.push_back(Symbol("diggermotionData", "int8_t", sizeof(diggermotionData), OFFSET_OF_VARIABLE_IN_STRUCT(diggermotionData)));
		return symbolList;
	}
};

int send(char* data, unsigned int size);
int connect();
int disconnect();