#pragma once

/*
 * clockWrapperLinux.h
 *
 *  Created on: 02.10.2019
 *  Author: Team OCP
 */
#include <stdint.h>
#include <time.h>

namespace RIB
{
	class ClockWrapperLinux
	{
	public:
		virtual ~ClockWrapperLinux();

		///
		/// Get the current systemtime 
		/// For detailed information see man-page of linux system function clock_gettime
		/// \param clk_id Clock to be used
		/// \param res current time - Attention: Unlike the linux system function this parameter requires a reference instead of a pointer due to testability reasons
		/// \return errorcode (0 on success)
		///
		virtual int _clock_gettime(clockid_t clk_id, struct timespec& res);
	};
}
