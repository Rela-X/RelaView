/*
 * RelaFixShell mainfile
 *
 * Copyright (C) Peter Berger, 2011
 * Modified 2012 by Andreas Schmitz
 */


#include "fileloader.h"

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

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>


FILE_INFO *file_info = 0;
RF_STACK *files = 0;
INPUT *input = 0;
int is_error;
int char_from_input;

int rf_lexer_need_char()
{
	if (char_from_input == RF_TRUE)
	{
		if (!input)
			return EOF;
		else if (!input->buffer)
			return EOF;
		else if (input->position >= input->buffer_size)
			return EOF;
		else if ((input->buffer[input->position]) == '\0')
			return EOF;
		else
			return input->buffer[input->position++];
	}
	else
	{
		if (!file_info)
			return EOF;
		else if (!(file_info->file))
			return EOF;
		else
			return fgetc(file_info->file);
	}
}

int rf_lexer_need_ungetc(int c)
{
	if (c == EOF)
		return 0;
	
	if (char_from_input == RF_TRUE)
	{
		if (!input)
			return 1;
		else if (!input->buffer)
			return 1;
		else if (input->position >= input->buffer_size)
			return 0;
		else if (input->position == 0)
			return 1;
		else
			return --input->position;
	}
	else
	{
		if (!file_info)
			return 1;
		else if (!(file_info->file))
			return 1;
		else
			return fseek(file_info->file, -1, SEEK_CUR);
	}
}

int rf_lexer_need_load_file(char *file, RF_LOCATION *location)
{
	if (!files || !location)
	{
		puts("error: program error\n");
        appendError("error: program error\n");
		return 1;
	}
	
	if (file_info)
	{
		if (file_info->file)
		{
			file_info->location = *location;
			rf_stack_push(files, file_info);
		}
		else
		{
			if (file_info->name)
				free(file_info->name);
			free(file_info);
		}
	}
	
	file_info = malloc(sizeof(FILE_INFO));
	file_info->name = file;
    file_info->file = fopen(file, "rb"); /* We open in byte mode cause fseek only works then! */
	if (!(file_info->file))
	{
		/*printf("File \"%s\" not found.\n\n", file);*/
		free(file_info->name);
		free(file_info);
		file_info = rf_stack_pop(files);
		/*is_error = RF_TRUE;*/
		return 1;
	}
	else
	{
		/*printf("File \"%s\" found.\nLoading...\n\n", file);*/
		
		file_info->location.first_column = 1;
		file_info->location.first_line = 1;
		file_info->location.last_column = 1;
		file_info->location.last_line = 1;
		rf_parser_set_location(&(file_info->location));
		
		char_from_input = RF_FALSE;
		
		return 0;
	}
}

void rf_parser_error(int line, int position, const char *text, int argc, ...)
{
	char *tmp;
	int i;

	va_list list;
	va_start(list, argc);

	if (text)
	{
        if (file_info){
            char *err =  " error: ";
            int size = digits(line) + digits(position) + strlen(file_info->name) + strlen(text) + strlen(err) + 1;
            size += 4; //for the colons and the wihitespace
            char* errstr = (char*) malloc(size * sizeof(char));

            sprintf(errstr, "%d:%d:%s%s: %s", line, position, err, file_info->name, text);
            printf(errstr);
            appendError(errstr);
            free(errstr);
        }else{
            char *err =  " error: ";
            int size = digits(line) + digits(position)+ strlen(text) + strlen(err) + 1;
            size += 2; //for the colons

            char *errstr = (char*) malloc(size *sizeof(char));

            sprintf(errstr, "%d:%d:%s%s", line, position, err,text);
            printf(errstr);
            appendError(errstr);
            free(errstr);
        }

        int size = 0; //string size for appendError
		for (i = 0; i < argc; i++){
			tmp = va_arg(list, char *);
            if (tmp){
                printf(tmp);
                size += strlen(tmp);
            }
		}
        printf("\n");

        size += 1; //\0 Symbol
        va_start(list, argc); //reset list position
        char *errstr = (char*) malloc(500*sizeof(char));
        strcpy(errstr, "");

        for (i = 0; i < argc; i++){
            tmp = va_arg(list, char *);
            if (tmp)
                strcat(errstr, tmp);
        }

        appendError(errstr);
        free(errstr);
        appendError("\n");

	}else{
        puts("x:x: error: unknown");
        appendError("x:x: error: unknown");
    }
	is_error = 1;
    puts("");
    appendError("");
}

int digits(int number)
{
    int digits = 0;
    while (number != 0){
        number /= 10;
        digits++;
    }
    return (digits == 0) ? 1 : digits;
}

void print_domain(RF_DOMAIN *domain)
{
	RF_LIST *list;
	RF_LIST_ITERATOR *iterator;
	RF_ELEMENT *element;
	int type;
	RF_BOOL is_first = RF_TRUE;

	if (!domain)
		return;

	list = rf_domain_get_list(domain);
	iterator = rf_list_get_begin(list);

	fputs("{", stdout);

	while (rf_list_has_next(iterator))
	{
		element = rf_list_next(iterator);
		if (!element)
			continue;

		type = rf_element_get_type(element);

		if (is_first == RF_TRUE)
			is_first = RF_FALSE;
		else
			fputs(", ", stdout);

		if (type == RF_ET_DOMAIN)
		{
			fputs(rf_domain_get_name(rf_element_get_data(element)), stdout);
			fputs(":", stdout);
			print_domain(rf_element_get_data(element));
		}
		else if (type == RF_ET_GLOBAL_DOMAIN)
		{
			fputs(rf_domain_get_name(rf_element_get_data(element)), stdout);
			fputs(":", stdout);
			print_domain(rf_element_get_data(element));
		}
		else if (type == RF_ET_NAME)
		{
			printf((char *)rf_element_get_data(element));
		}
		else
		{
			fputs("???", stdout);
		}
	}

	fputs("}", stdout);
	
	rf_list_delete_iterator(iterator);
}

void rf_parser_show_bool(RF_BOOL boolean)
{
	if (boolean)
		puts("true");
	else
		puts("false");
}

void rf_parser_show_domain(RF_DOMAIN *domain)
{
	if (!domain)
		return;

    //adding to domain list
	printf("%s: ", rf_domain_get_name(domain));

	print_domain(domain);
	puts("\n");

    createDomain(domain);
}

void rf_parser_show_element(char *id)
{
	if (!id)
		return;
	
    printf("%s\n", id);
}

void print_table(RF_DOMAIN *domain_1, RF_DOMAIN *domain_2, RF_TABLE *table)
{
	RF_LIST *names_1, *names_2;
	RF_LIST_ITERATOR *iterator_1, *iterator_2;
	char *tmp_name;
	int i, j, max_hori, max_verti, length, total;
	int *max_length;
	int table_type;
	
	if (!domain_1 || !domain_2 || !table)
	{
		puts("Table: error");
        appendError("Table: error");
		return;
	}
	
	table_type = rf_table_get_type(table);
	
	/* Find size of longest word for every column */
	names_1 = rf_domain_get_element_names(domain_1);
	names_2 = rf_domain_get_element_names(domain_2);
	iterator_1 = rf_list_get_begin(names_1);
	iterator_2 = rf_list_get_begin(names_2);
	max_hori = rf_table_get_width(table);
	max_verti = rf_table_get_height(table);
	max_length = calloc(rf_list_get_count(names_2) + 1, sizeof(int));
	
	/* first column */
	while (rf_list_has_next(iterator_1))
	{
		tmp_name = 0;
		tmp_name = rf_list_next(iterator_1);
		length = strlen(tmp_name);
		if (length > max_length[0])
			max_length[0] = length;
	}
	rf_list_delete_iterator(iterator_1);
	iterator_1 = 0;

	/* other columns headings */
	for (i = 1; rf_list_has_next(iterator_2); i++)
	{
		tmp_name = 0;
		tmp_name = rf_list_next(iterator_2);
		length = strlen(tmp_name);
		if (length > max_length[i])
			max_length[i] = length;
	}
	rf_list_delete_iterator(iterator_2);
	iterator_2 = 0;
	
	/* other columns */
	for (i = 0; i < max_hori; i++)
	{
		for (j = 0; j < max_verti; j++)
		{
			tmp_name = 0;
			if (table_type == RF_TT_BINARY)
			{
				if (rf_table_get_bit(table, i, j))
					tmp_name = "1";
				else
					tmp_name = "0";
			}
			else if (table_type == RF_TT_STRING)
			{
				rf_table_get_string(table, i, j, &tmp_name);
			}
			length = strlen(tmp_name);
			if (length > max_length[i + 1])
				max_length[i + 1] = length;
		}
	}
	
	
	/* print formated table */
	iterator_1 = rf_list_get_begin(names_1);
	iterator_2 = rf_list_get_begin(names_2);
	
	/* spaaaaaaace in first column of heading */
	printf("%*s", max_length[0] + 1, "");   /* +1 cause ':' will be added */
	
	/* headings */
	for (i = 1; rf_list_has_next(iterator_2); i++)
	{
		tmp_name = 0;
		tmp_name = rf_list_next(iterator_2);
		if (tmp_name)
			printf("  %-*s", max_length[i], tmp_name);
		else
			printf("  %-*s", max_length[i], "<?>");
	}
	puts("");
	
	/* hline */
	for (i = 1, total = 0; i <= max_hori; i++)
		total += max_length[i] + 2;
	printf("%*s+", max_length[0], " ");
	for (i = 0; i < total; i++)
		putc('-', stdout);
	puts("-");
	
	/* lines */
	for (i = 0; rf_list_has_next(iterator_1); i++)
	{
		tmp_name = 0;
		tmp_name = rf_list_next(iterator_1);
		if (tmp_name)
			printf("%*s|", max_length[0], tmp_name);
		else
			printf("%*s|", max_length[0], "<?>");
		
		for (j = 0; j < max_hori; j++)
		{
			tmp_name = 0;
			if (table_type == RF_TT_BINARY)
			{
				if (rf_table_get_bit(table, j, i))
					tmp_name = "1";
				else
					tmp_name = "0";
			}
			else if (table_type == RF_TT_STRING)
			{
				rf_table_get_string(table, j, i, &tmp_name);
			}
			if (tmp_name)
				printf("  %-*s", max_length[j + 1], tmp_name);
			else
				printf("  %-*s", max_length[j + 1], "<?>");
		}
		
		printf("\n");
	}
	
	puts("");
	rf_list_delete_iterator(iterator_1);
	rf_list_delete_iterator(iterator_2);
	rf_list_destroy(names_1, 0);
	rf_list_destroy(names_2, 0);
	free(max_length);
}

void rf_parser_show_relation(RF_RELATION *relation)
{
	RF_DOMAIN *domain_1, *domain_2;
	char *name;
	
	if (!relation)
	{
		puts("Some error occured in show relation.");
        appendError("Some error occured in show relation.");
		return;
	}
	
    name = rf_relation_get_name(relation);
	domain_1 = rf_relation_get_domain_1(relation);
	domain_2 = rf_relation_get_domain_2(relation);
	
    //printf("RELATION %s: %s -> %s\n", name, rf_domain_get_name(domain_1) , rf_domain_get_name(domain_2));
    //print_table(domain_1, domain_2, rf_relation_get_table(relation));


    createRelation(relation);

}

void rf_parser_show_operation(RF_OPERATION *operation)
{
	RF_DOMAIN *domain_1, *domain_2, *domain_3;
	char *name;
	
	if (!operation)
	{
		puts("Some error occured in show operation.");
		return;
	}
	
	name = rf_operation_get_name(operation);
	domain_1 = rf_operation_get_domain_1(operation);
	domain_2 = rf_operation_get_domain_2(operation);
	domain_3 = rf_operation_get_domain_3(operation);
	
	printf("OPERATION %s: %s x %s -> %s\n", name, rf_domain_get_name(domain_1) , rf_domain_get_name(domain_2),
		rf_domain_get_name(domain_3));
	print_table(domain_1, domain_2, rf_operation_get_table(operation));
}

void rf_parser_show_negation(RF_NEGATION *negation)
{
	RF_LIST *list;
	RF_LIST_ITERATOR *pos;
	RF_DOMAIN *domain;
	char *tmp;
	
	if (!negation)
	{
		puts("Some error occured in show negation.");
		return;
	}
	
	list = rf_negation_get_items(negation);
	pos = rf_list_get_begin(list);
	domain = rf_negation_get_domain(negation);
	
	printf("NEGATION %s: %s = ", rf_negation_get_name(negation), rf_domain_get_name(domain));
	
	while (rf_list_has_next(pos))
	{
		tmp = rf_list_next(pos);
		if (tmp)
			printf("%s/", tmp);
		else
			fputs("<?>/", stdout);
		
		if (rf_list_has_next(pos))
		{
			tmp = rf_list_next(pos);
			if (tmp)
				printf("%s", tmp);
			else
				fputs("<?>", stdout);
		}
		else
			fputs("<?>", stdout);
		
		if (rf_list_has_next(pos))
			fputs(", ", stdout);
	}
	
	puts(";\n");
	
	rf_list_delete_iterator(pos);
}

void rf_parser_show_function(RF_FUNCTION *function)
{
	if (!function)
	{
		puts("Some error occured in show function.\n");
		return;
	}
	
	puts("-------------------------------------------------------------------------------");
	printf("%s\n", rf_function_get_description(function));
	puts("-------------------------------------------------------------------------------\n");
}

void rf_parser_show_string(char *string)
{
	if (!string)
		puts("no string to show.\n");
	else
		fputs(string, stdout);
}

void read_input(INPUT *input)
{
    puts("read input");
	int c = 0;
	int position = 1;
	char junk[20];
	junk[0] = 0;
	
	if (!input)
		return;
	
	if (!input->buffer)
	{
		input->buffer = malloc(40 * sizeof(char));
		input->buffer_size = 40;
		input->buffer[0] = '\0';
	}
	
	input->position = 0;
	
	printf("%d>", position);
	
	while (1)
	{
		if ((c = getchar()) == EOF)
		{
			perror("program error - reached end of file");
			break;
		}
		
		if (input->position + 1 >= input->buffer_size)
		{
			input->buffer_size *= 2;
			input->buffer = realloc(input->buffer, input->buffer_size * sizeof(char));
			if (!input->buffer)
				return;
		}
		input->buffer[input->position] = c;
		input->position++;
		
		if (c == ';')
		{
			while (1)
			{
				if (fgets(junk, 20, stdin) == 0)
				{
					perror("program error - reached end of file");
					break;
				}
				else if (junk[strlen(junk)-1] == '\n')
					break;
			};
			break;
		}
		else if (c == '\n')
		{
			printf("%d>", ++position);
		}
	}
	
	
	input->buffer[input->position] = '\0';
	input->position = 0;
}

int parseFile(int argc, const char *name)
{
	int is_input_mode;
	RF_LOCATION location = {1, 1, 1, 1};
	
	puts("\nRelaFix           1.0");
	puts("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"");


	files = rf_stack_create();
	file_info = 0;
	
	if (argc == 1)
	{
		is_input_mode = RF_TRUE;
		char_from_input = RF_TRUE;
		input = malloc(sizeof(INPUT));
		input->buffer = 0;
		input->position = 0;
		input->buffer_size = 0;
	}
	else if (argc == 2)
    {
		is_input_mode = RF_FALSE;
        rf_lexer_need_load_file(rf_string_copy(name), &location);
	}
	else
	{
		puts("Too many arguments.\nUse: rfcli.exe <file> for loading a file\n"
			"Use: rfcli.exe  to start input mode");
		rf_stack_destroy(files, 0);
		return 0;
	}
	
	do
	{
		if (is_input_mode)
		{
			if (char_from_input == RF_TRUE)
			{
				read_input(input);
				puts("");
			}
			else
				char_from_input = RF_TRUE;
			
			if (!input)
			{
				puts("error: no memory");
				break;
			}
			else if (!input->buffer)
			{
				puts("error: no memory");
				break;
			}
			else if (strcmp(input->buffer, "quit;") == 0)
			{
				break;
			}
		}
		
		
		do
		{
			rf_parser_set_location(&location);
			
			if (yyparse())
				is_error = 1;
	
			if (file_info)
			{
				if (file_info->file)
                    fclose(file_info->file);
				if (file_info->name)
					free(file_info->name);
				free(file_info);
				file_info = 0;
			}
		} while (file_info = rf_stack_pop(files));
	
		if (!is_error)
		{
			if (is_input_mode == RF_FALSE)
				puts("Ok\n");
		}
		else
		{
			is_error = RF_FALSE;
			puts("Error\n");
		}
	} while (is_input_mode == RF_TRUE);


    fflush(stdout);

	rf_stack_destroy(files, 0);
	return 0;
}
