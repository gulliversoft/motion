//////////////////////////////////////////////////////////////////////////////////////////
/// Rocket
/// Created on: 02.08.2020
///     Author: Shishkov Martin
///
/// \file motionRIB.cpp
///
//////////////////////////////////////////////////////////////////////////////////////////


#include "log_datalayer.h"
#include "motionRIB.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define OK		0
#define ERROR	-1

extern "C" int mainOld (int argc, char **argv);

int main (int argc, char **argv) {

    int (*RIB_connect)(void);
    char *error;

	void* handle = dlopen(".//libMotionExchangeBuffer.so", RTLD_NOW);
	if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
	dlerror();    /* Clear any existing error */

	*(void **) (&RIB_connect) = dlsym(handle, "RIB_connect");

	if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
	
	(*RIB_connect)();

	*(void **) (&RIB_send) = dlsym(handle, "RIB_send");

	if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

	mainOld (argc, argv);

	dlclose(handle);
}
