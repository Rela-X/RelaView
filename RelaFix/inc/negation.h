/*
 * RelaFixLib    Negation
 *
 * Copyright (C) Peter Berger, 2011
 */

/*! \file
 \brief Functions to work with negation function
 
 Declares functions to work on struct RF_NEGATION. RF_NEGATION represents the negation function
 of the Relafix language. The user can define the negation based on a domain in that language.
 */

#ifndef RF_NEGATION_H
#define RF_NEGATION_H

#include "defines.h"

char *			rf_negation_calc(RF_NEGATION *negation, char *element, RF_ERROR *error);
RF_NEGATION *	rf_negation_create(char *name, RF_DOMAIN *domain);
void			rf_negation_destroy(RF_NEGATION *negation);
RF_DOMAIN *		rf_negation_get_domain(RF_NEGATION *negation);
RF_LIST *		rf_negation_get_items(RF_NEGATION *negation);
char *			rf_negation_get_name(RF_NEGATION *negation);
RF_BOOL			rf_negation_has_name(RF_NEGATION *negation, char *name);
int				rf_negation_set_items(RF_NEGATION *negation, RF_LIST *items, RF_ERROR *error);

#endif
