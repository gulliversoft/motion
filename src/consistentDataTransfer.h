/*
 * consistentDataTransfer.h
 *
 *  Created on: 21.08.2019
 *      Author: Team OCP
 */

#pragma once

#include "IRIBBaseDataStruct.h"

namespace RIB
{
	struct Header;

	class ConsistentDataTransfer {

	public:
		///
		/// Copy constructor for test matters
		///
		ConsistentDataTransfer(const ConsistentDataTransfer&) = default;

		///
		/// Overload of operator= for test matters
		/// return a reference to a ConsistentDataTransfer object
		///
		ConsistentDataTransfer& operator=(const ConsistentDataTransfer&) = default;

		///
		/// Writes user data into a buffer for consistency matters
		/// \param userData pointer to struct with user data
		///
		void writeUserData(IRIBBaseDataStruct* const userData);
	};
}
