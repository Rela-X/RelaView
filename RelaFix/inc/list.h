/*
 * RelaFixLib    List
 *
 * Copyright (C) Peter Berger, 2011
 */

/*! \file
 \brief A dynamic double linked list.
 
 Declares functions to work on struct RF_LIST. The list is build by nodes RF_LIST_ITEM and can
 be traversed by the use of iterators (RF_LIST_ITERATOR). Use the list if you need often to add
 and delete items from it.
 */

#ifndef RF_LIST_H
#define RF_LIST_H

#include "defines.h"



void				rf_list_append(RF_LIST *list, void *data);
RF_LIST_ITERATOR *	rf_list_copy_iterator(RF_LIST_ITERATOR *iterator);
RF_LIST *			rf_list_create();
void *				rf_list_delete_item(RF_LIST_ITERATOR *iterator, void (*)(void *data));
void				rf_list_delete_iterator(RF_LIST_ITERATOR *iterator);
void				rf_list_destroy(RF_LIST *list, void (*)(void *data));
RF_LIST_ITERATOR *	rf_list_get_begin(RF_LIST *list);
void *				rf_list_get_by_position(RF_LIST *list, int position);
int					rf_list_get_count(RF_LIST *list);
RF_LIST_ITERATOR *	rf_list_get_end(RF_LIST *list);
RF_BOOL				rf_list_has_next(RF_LIST_ITERATOR *iterator);
RF_BOOL				rf_list_has_prev(RF_LIST_ITERATOR *iterator);
void				rf_list_merge(RF_LIST *list_1, RF_LIST *list_2);
void *				rf_list_next(RF_LIST_ITERATOR *iterator);
void *				rf_list_prev(RF_LIST_ITERATOR *iterator);
int					rf_list_set_by_position(RF_LIST *list, int position, void *data);

#endif
