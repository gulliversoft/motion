/*
 * motionRIB.h
 *
 *  Created on: 02.08.2020
 *      Author: Shishkov Martin
 */

#pragma once
const unsigned int MAX_RIB_SIZE = 1024 * 80;
#ifdef __cplusplus
extern "C"
{
#endif
int (*RIB_send)(char*, unsigned int);
#ifdef __cplusplus
}
#endif