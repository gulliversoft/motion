#pragma once

/*
 * clockUtils.h
 *
 *  Created on: 02.10.2019
 *  Author: Team OCP
 */

#include <stdint.h>

namespace RIB
{
    class ClockWrapperLinux;

    class ClockUtils
	{

	public:
		static constexpr uint64_t million = 1000000;
		static constexpr uint64_t thousand = 1000;

		ClockUtils(ClockWrapperLinux* clockWrapper);
		ClockUtils(ClockUtils& clockUtils) = default;

		~ClockUtils();
		
		ClockUtils& operator= (ClockUtils& clockUtils) = default;

	};
}
