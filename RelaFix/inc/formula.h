/*
 * RelaFixLib    Formula
 *
 * Copyright (C) Peter Berger, 2011
 */

/*! \file
\brief A structure that represents an expression tree.

Declares functions to work on struct RF_FORMULA. It will be used to store expressions for late
execution.
*/

#ifndef RF_FORMULA_H
#define RF_FORMULA_H


void				rf_formula_append_argument(RF_FORMULA *formula, RF_FORMULA *argument);
int					rf_formula_calc(RF_FORMULA *formula, char *element_1, char *element_2, RF_FORMULA_RESULT **result);
RF_FORMULA_RESULT *	rf_formula_calc_error(RF_LOCATION *location, char *error);
void				rf_formula_clear(RF_FORMULA *formula);
RF_FORMULA *		rf_formula_create();
RF_FORMULA_RESULT *	rf_formula_create_result();
void				rf_formula_destroy_result(RF_FORMULA_RESULT *result);
void				rf_formula_destroy(RF_FORMULA *formula);
void				rf_formula_set_arguments(RF_FORMULA *formula, RF_ARRAY *arguments);
void				rf_formula_set_domain(RF_FORMULA *formula, RF_DOMAIN *domain);
void				rf_formula_set_element(RF_FORMULA *forumula, char *element);
void				rf_formula_set_function(RF_FORMULA *formula, RF_FUNCTION *function);
void				rf_formula_set_location(RF_FORMULA *formula, int first_line, int first_column, int last_line, int last_column);
void				rf_formula_set_negation(RF_FORMULA *formula, RF_NEGATION *negation);
void				rf_formula_set_operation(RF_FORMULA *formula, RF_OPERATION *operation);
void				rf_formula_set_relation(RF_FORMULA *formula, RF_RELATION *relation);
void				rf_formula_set_variable(RF_FORMULA *formula, char variable);


#endif
