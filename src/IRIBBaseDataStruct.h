/*
 * IRIBBaseDataStruct.h
 *
 *  Created on: 03.07.2019
 *      Author: Team OPC
 */

#pragma once

#include "symbol.h"
#include <list>

using std::list;

///
/// Interface for a basic RIB data structure 
///

//TODO: To be verfied whether offset calculation is valid and secure 
//-> Different Compiler might generate different memory layout for the same code. In that case, is this calculation still valid
#define OFFSET_OF_VARIABLE_IN_STRUCT(x) reinterpret_cast<uint64_t>(std::addressof(x)) - reinterpret_cast<uint64_t>(std::addressof(*this))

class IRIBBaseDataStruct
{
	public:

		///
		/// Access the symbols description for the RIB-Configuration.
		/// /// \return A list of Symbol objects describing the data within a shared memory.
		/// 
		virtual list<Symbol> getSymbolList(void) = 0;
};

