/*
 * RelaFixLib, definitions for the parser
 *
 * Copyright (C) Peter Berger, 2011
 */

#ifndef PARSE_H
#define PARSE_H

#include "defines.h"



extern int		rf_lexer_mode;
extern RF_BOOL	rf_parser_record;
extern RF_BOOL	rf_parser_with_variable;

int		rf_lexer_need_char();
int		rf_lexer_need_ungetc(int c);
int		rf_lexer_need_load_file(char *file, RF_LOCATION *location);


int						rf_parser_add_domain(RF_DOMAIN *domain);
int						rf_parser_add_function(RF_FUNCTION *function);
int						rf_parser_add_negation(RF_NEGATION *negation);
int						rf_parser_add_relation(RF_RELATION *relation);
int						rf_parser_add_operation(RF_OPERATION *operation);
RF_PARSER_TABLE_ROW *	rf_parser_create_table_row(char *name);
void					rf_parser_delete_domain(RF_DOMAIN *domain);
void					rf_parser_delete_relation(RF_RELATION *relation);
void					rf_parser_delete_operation(RF_OPERATION *operation);
void					rf_parser_delete_negation(RF_NEGATION *negation);
void					rf_parser_destroy_table_data(RF_PARSER_TABLE_DATA *table_data);
void					rf_parser_destroy_table_row(RF_PARSER_TABLE_ROW *row);
void					rf_parser_error(int line, int position, const char *text, int argc, ...);
RF_DOMAIN *				rf_parser_get_domain(char *name);
RF_FUNCTION *			rf_parser_get_function(char *name);
RF_NEGATION *			rf_parser_get_negation(char *name);
RF_RELATION *			rf_parser_get_relation(char *name);
RF_OPERATION *			rf_parser_get_operation(char *name);
char *					rf_parser_get_path();
void					rf_parser_list_domains();
void					rf_parser_list_relations();
void					rf_parser_list_operations();
void					rf_parser_list_negations();
void					rf_parser_list_functions();
void					rf_parser_record_append(char symbol);
void					rf_parser_record_clear();
char *					rf_parser_record_read();
void					rf_parser_register_system_functions();
void					rf_parser_set_location(RF_LOCATION *location);
void					rf_parser_set_path(char *path);
void					rf_parser_show_bool(RF_BOOL boolean);
void					rf_parser_show_domain(RF_DOMAIN *domain);
void					rf_parser_show_element(char *id);
void					rf_parser_show_negation(RF_NEGATION *negation);
void					rf_parser_show_relation(RF_RELATION *relation);
void					rf_parser_show_operation(RF_OPERATION *operation);
void					rf_parser_show_function(RF_FUNCTION *function);
void					rf_parser_show_string(char *string);
RF_LIST *				rf_parser_table_row_get_list(RF_PARSER_TABLE_ROW *row);

void	yyerror(char const *str);
int		yyparse(void);

#endif
