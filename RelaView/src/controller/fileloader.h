/*
 * RelaFixShell mainfile
 *
 * Copyright (C) Peter Berger, 2011
 * Modified 2012 by Andreas Schmitz
 */


#ifndef FILELOADER_H
#define FILELOADER_H

#include "parse.h"
#include "stack.h"
#include "list.h"
#include "tools.h"
#include "domain.h"
#include "relation.h"
#include "operation.h"
#include "negation.h"
#include "function.h"
#include "table.h"

#include <stdio.h>

extern void createRelation(RF_RELATION* relation);
extern void createDomain(RF_DOMAIN* domain);
extern void appendError(char* str);

typedef struct
{
    char		*name;
    FILE		*file;
    RF_LOCATION	location;
} FILE_INFO;

typedef struct
{
    char	*buffer;
    int		position;
    int		buffer_size;
} INPUT;

int rf_lexer_need_char();
int rf_lexer_need_ungetc(int c);
int rf_lexer_need_load_file(char *file, RF_LOCATION *location);
void rf_parser_error(int line, int position, const char *text, int argc, ...);
int digits(int number);
void print_domain(RF_DOMAIN *domain);
void rf_parser_show_bool(RF_BOOL boolean);
void rf_parser_show_domain(RF_DOMAIN *domain);
void rf_parser_show_element(char *id);
void print_table(RF_DOMAIN *domain_1, RF_DOMAIN *domain_2, RF_TABLE *table);
void rf_parser_show_relation(RF_RELATION *relation);
void rf_parser_show_operation(RF_OPERATION *operation);
void rf_parser_show_negation(RF_NEGATION *negation);
void rf_parser_show_function(RF_FUNCTION *function);
void rf_parser_show_string(char *string);
void read_input(INPUT *input);
int parseFile(int argc, const char *name);


#endif // FILELOADER_H
