/*
 * RelaFixLib    Relation
 *
 * Copyright (C) Peter Berger, 2011
 */
 
/*! \file
 \brief Functions to work with relations.
 
 Declares functions to work on struct RF_RELATION. RF_RELATION represents a mathematical
 relation. In the Relafix language relations are used in the form 'a leq b'. Here leq
 is the relation.
 */

#ifndef RF_RELATION_H
#define RF_RELATION_H

#include "defines.h"


int				rf_relation_build_table(RF_RELATION *relation, RF_PARSER_TABLE_DATA *table_data, RF_ERROR *error);
int				rf_relation_build_table_by_formula(RF_RELATION *relation, RF_FORMULA *formula, RF_ERROR *error);
int				rf_relation_calc(RF_RELATION *relation, char *element_1, char *element_2, RF_ERROR *error);
RF_RELATION *	rf_relation_copy(RF_RELATION *relation);
RF_RELATION *	rf_relation_create(char *name, RF_DOMAIN *domain_1, RF_DOMAIN *domain_2);
RF_RELATION *	rf_relation_create_bottom(RF_DOMAIN *domain, RF_ERROR *error);
RF_RELATION *	rf_relation_create_complement(RF_RELATION *relation, RF_ERROR *error);
RF_RELATION *	rf_relation_create_concatenation(RF_RELATION *relation_1, RF_RELATION *relation_2, RF_ERROR *error);
RF_RELATION *	rf_relation_create_converse(RF_RELATION *relation, RF_ERROR *error);
RF_RELATION *	rf_relation_create_empty(RF_DOMAIN *domain_1, RF_DOMAIN *domain_2, RF_ERROR *error);
RF_RELATION *	rf_relation_create_full(RF_DOMAIN *domain_1, RF_DOMAIN *domain_2, RF_ERROR *error);
RF_RELATION *	rf_relation_create_id(RF_DOMAIN *domain, RF_ERROR *error);
RF_RELATION *	rf_relation_create_intersection(RF_RELATION *relation_1, RF_RELATION *relation_2, RF_ERROR *error);
RF_RELATION *	rf_relation_create_subsetleq(RF_DOMAIN *domain, RF_ERROR *error);
RF_RELATION *	rf_relation_create_top(RF_DOMAIN *domain, RF_ERROR *error);
RF_RELATION *	rf_relation_create_union(RF_RELATION *relation_1, RF_RELATION *relation_2, RF_ERROR *error);
void			rf_relation_destroy(RF_RELATION *relation);
char *			rf_relation_find_infimum(RF_RELATION *relation, RF_DOMAIN *domain, RF_ERROR *error);
RF_DOMAIN *		rf_relation_find_lowerbound(RF_RELATION *relation, RF_DOMAIN *domain, RF_ERROR *error);
char *			rf_relation_find_maximum(RF_RELATION *relation, RF_ERROR *error);
char *			rf_relation_find_minimum(RF_RELATION *relation, RF_ERROR *error);
char *			rf_relation_find_supremum(RF_RELATION *relation, RF_DOMAIN *domain, RF_ERROR *error);
RF_DOMAIN *		rf_relation_find_upperbound(RF_RELATION *relation, RF_DOMAIN *domain, RF_ERROR *error);
RF_DOMAIN *		rf_relation_get_domain_1(RF_RELATION *relation);
RF_DOMAIN *		rf_relation_get_domain_2(RF_RELATION *relation);
char *			rf_relation_get_name(RF_RELATION *relation);
RF_TABLE *		rf_relation_get_table(RF_RELATION *relation);
RF_BOOL			rf_relation_has_name(RF_RELATION *relation, char *name);
int				rf_relation_is_antisymmetric(RF_RELATION *relation);
int				rf_relation_is_asymmetric(RF_RELATION *relation);
int				rf_relation_is_difunctional(RF_RELATION *relation);
int				rf_relation_is_equivalent(RF_RELATION *relation);
int				rf_relation_is_irreflexive(RF_RELATION *relation);
int				rf_relation_is_poset(RF_RELATION *relation);
int				rf_relation_is_preorder(RF_RELATION *relation);
int				rf_relation_is_reflexive(RF_RELATION *relation);
int				rf_relation_is_symmetric(RF_RELATION *relation);
int				rf_relation_is_transitive(RF_RELATION *relation);
void			rf_relation_set_name(RF_RELATION *relation, char *name);
void			rf_relation_set_table(RF_RELATION *relation, RF_TABLE *table);
int             rf_relation_gain_symmetric(RF_RELATION* relation, RF_BOOL fill);
int             rf_relation_gain_antisymmetric(RF_RELATION* relation, RF_BOOL upper);
int             rf_relation_gain_irreflexive(RF_RELATION* relation);
int             rf_relation_gain_reflexive(RF_RELATION* relation);
int             rf_relation_gain_transitive(RF_RELATION* relation, RF_BOOL fill);
int             rf_relation_gain_difunctional(RF_RELATION* relation, RF_BOOL fill);
int             rf_relation_gain_equivalent(RF_RELATION* relation, RF_BOOL fill);
int             rf_relation_gain_poset(RF_RELATION* relation, RF_BOOL fill);
int             rf_relation_gain_preorder(RF_RELATION* relation, RF_BOOL fill);
int             rf_relation_gain_asymmetric(RF_RELATION* relation, RF_BOOL upper);


#endif
