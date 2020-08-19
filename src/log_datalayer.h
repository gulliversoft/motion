/*
 * log_datalayer.h
 *
 *  Created on: 20.12.2018
 *      Author: Team OCP
 */

#pragma once

#include <string>

enum LOG_CAT
{
  STANDARD,
  DEBUG,
  ERROR
};

int log(LOG_CAT category, std::string location, std::string msg);

