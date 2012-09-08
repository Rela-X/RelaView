/*
 * RelaFix       Function
 *
 * Copyright (C) Peter Berger, 2011
 */
 
/*! \file
 * \brief	Declares structure and functions to handle systemfunctions of the relafix language
 */

#ifndef RF_FUNCTION_H
#define RF_FUNCTION_H

#include "defines.h"


RF_FUNCTION *	rf_function_create(char *name, void *function, int argc);
void			rf_function_destroy(RF_FUNCTION *function);
int				rf_function_get_argument_count(RF_FUNCTION *function);
char *			rf_function_get_description(RF_FUNCTION *function);
void *			rf_function_get_func(RF_FUNCTION *function);
char *			rf_function_get_name(RF_FUNCTION *function);
RF_BOOL			rf_function_has_name(RF_FUNCTION *function, char *name);
void			rf_function_set_description(RF_FUNCTION *function, char *description);

#endif
