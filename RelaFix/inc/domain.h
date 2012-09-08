/*
 * RelaFixLib    Domain
 *
 * Copyright (C) Peter Berger, 2011
 */

/*! \file
 * \brief Functions to work on domains and elements.
 *
 * Declares functions to work on struct RF_DOMAIN. RF_DOMAIN represents the mathematical
 * domain that keeps elements (RF_ELEMENT).
 *
 * RF_DOMAIN is needed when relations and operations are defined.
 */

/* THIS FILE WAS CHANGED DUE TO THE FACT THAT TYPEDEF REDEFINITIONS 
CAUSED ERRORS WITH SOME COMPILERS */

#ifndef RF_DOMAIN_H
#define RF_DOMAIN_H

#include "defines.h"


int				rf_domain_check_elements(RF_LIST *elements, RF_ERROR *error);
RF_DOMAIN *		rf_domain_copy(RF_DOMAIN *domain);
RF_DOMAIN *		rf_domain_create(char *name);
RF_DOMAIN *		rf_domain_create_powerset(RF_DOMAIN *domain, RF_ERROR *error);
void			rf_domain_destroy(RF_DOMAIN *domain);
RF_ELEMENT *	rf_domain_get_element(RF_DOMAIN *domain, char *name);
RF_ELEMENT *	rf_domain_get_element_by_position(RF_DOMAIN *domain, int pos);
int				rf_domain_get_element_count(RF_DOMAIN *domain);
RF_LIST *		rf_domain_get_element_names(RF_DOMAIN *domain);
int				rf_domain_get_element_position(RF_DOMAIN *domain, char *element);
RF_LIST *		rf_domain_get_list(RF_DOMAIN *domain);
char *			rf_domain_get_name(RF_DOMAIN *domain);
RF_BOOL			rf_domain_has_element(RF_DOMAIN *domain, char *name);
RF_BOOL			rf_domain_has_name(RF_DOMAIN *domain, char *name);
RF_BOOL			rf_domain_is_partof(RF_DOMAIN *domain1, RF_DOMAIN *domain2);
void			rf_domain_set_list(RF_DOMAIN *domain, RF_LIST *list);
void			rf_domain_set_name(RF_DOMAIN *domain, char *name);


RF_ELEMENT *	rf_element_copy(RF_ELEMENT *element);
RF_ELEMENT *	rf_element_create(int type, void *data);
void			rf_element_destroy(RF_ELEMENT *element);
void *			rf_element_get_data(RF_ELEMENT *element);
char *			rf_element_get_name(RF_ELEMENT *element);
int				rf_element_get_type(RF_ELEMENT *element);




#endif
