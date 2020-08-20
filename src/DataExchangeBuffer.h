/*
 * DataExchangeBuffer.h
 *
 *  Created on: 02.01.2020
 *      Author: Shishkov Martin
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
int RIB_send(char* data, unsigned int size);
int RIB_connect();
int RIB_disconnect();
#ifdef __cplusplus
}
#endif