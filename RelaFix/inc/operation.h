/*
 * RelaFixLib    Operation
 *
 * Copyright (C) Peter Berger, 2011
 */
 
/*! \file
 \brief Functions to work with operations.
 
 Declares functions to work on struct RF_OPERATION. RF_OPERATION represents a mathematical
 operation. In the Relafix language operations are used in the form 'a + b'.
 */

#ifndef RF_OPERATION_H
#define RF_OPERATION_H

#include "defines.h"


int				rf_operation_build_table(RF_OPERATION *operation, RF_PARSER_TABLE_DATA *table_data, RF_ERROR *error);
int				rf_operation_build_table_by_formula(RF_OPERATION *operation, RF_FORMULA *formula, RF_ERROR *error);
int				rf_operation_calc(RF_OPERATION *operation, char *element_1, char *element_2, char **element_out);
RF_OPERATION *	rf_operation_copy(RF_OPERATION *operation);
RF_OPERATION *	rf_operation_create(char *name, RF_DOMAIN *domain_1, RF_DOMAIN *domain_2, RF_DOMAIN *domain_3);
RF_OPERATION *	rf_operation_create_meet(RF_RELATION *relation, RF_ERROR *error);
RF_OPERATION *	rf_operation_create_join(RF_RELATION *relation, RF_ERROR *error);
void			rf_operation_destroy(RF_OPERATION *operation);
RF_OPERATION *	rf_operation_generate_join(RF_RELATION *leq);
RF_OPERATION *	rf_operation_generate_meet(RF_RELATION *leq);
RF_DOMAIN *		rf_operation_get_domain_1(RF_OPERATION *operation);
RF_DOMAIN *		rf_operation_get_domain_2(RF_OPERATION *operation);
RF_DOMAIN *		rf_operation_get_domain_3(RF_OPERATION *operation);
char *			rf_operation_get_name(RF_OPERATION *operation);
RF_TABLE *		rf_operation_get_table(RF_OPERATION *operation);
RF_BOOL			rf_operation_has_name(RF_OPERATION *operation, char *name);
void			rf_operation_set_name(RF_OPERATION *operation, char *name);
void			rf_operation_set_table(RF_OPERATION *operation, RF_TABLE *table);

#endif
