/*
 * RelaFixLib    Defines
 *
 * Copyright (C) Peter Berger, 2011
 */
 
/*! \file
 * \brief	Definitions used by Library
 *
 * Defines structures and values that will be used by many other declarations in the Library.
 */

/* THIS FILE WAS CHANGED DUE TO THE FACT THAT TYPEDEF REDEFINITIONS 
CAUSED ERRORS WITH SOME COMPILERS */

#ifndef RF_DEFINES_H
#define RF_DEFINES_H

#define RF_FALSE	0
#define RF_TRUE		!0
/*! \brief boolean for relafix library
 *
 * Use RF_FALSE and RF_TRUE with this type
 */
typedef unsigned char RF_BOOL;


/*! \brief	Provides start and end position of textarea
 *
 * This structure is used in the library to remember the position of the
 * parsed token. If some error occures the library will use this structure in RF_ERROR
 * so that the position of the error can be transfered to the user.
 */
typedef struct rf_location
{
	int first_line;		/*!< \brief line where the textarea starts */
	int first_column;	/*!< \brief column where the textarea starts */
	int last_line;		/*!< \brief line where the textarea ends */
	int last_column;	/*!< \brief column where the thextarea ends */
} RF_LOCATION;








/*! \brief	Used to return message and location of an error
 *
 * A pointer to an instance of this structure should be given to a function that can
 * fail for many different reasons. If that function fails, it will fill out the structure.
 * The errormessage that is pointed to by 'string' must be on the heap and will be freed
 * outside of that function!
 */
typedef struct rf_error
{
	char		*string;	/*!< \brief Points to an errormessage on the heap. */
	RF_LOCATION	location;	/*!< \brief Textposition where the error occured */
} RF_ERROR;






/*!
\brief The item that builds the linked list.
*/
typedef struct rf_list_item
{
	struct rf_list_item	*prev; /*!< \brief The previous item. 0 if there is no previous item. */
	struct rf_list_item	*next; /*!< \brief The next item. 0 if there is no next item. */
	void				*data; /*!< \brief A pointer to the data saved at this node. */
}RF_LIST_ITEM;








/*!
\brief A dynamic double linked list.
 
Declares functions to work on struct RF_LIST. The list is build by nodes RF_LIST_ITEM and can
be traversed by the use of iterators (RF_LIST_ITERATOR). Use the list if you need often to add
and delete items from it.
*/
typedef struct rf_list
{
	int				count; /*!< \brief The number of elements in the list. */
	RF_LIST_ITEM	*first; /*!< \brief The first element in the list. */
	RF_LIST_ITEM	*last; /*!< \brief The last element in the list. */
}RF_LIST;








/*!
\brief The iterator that can be used to traverse a list.
*/
typedef struct rf_list_iterator
{
	RF_LIST			*list; /*!< \brief The list the iterator works on. */
	RF_LIST_ITEM	*prev; /*!< \brief The next item. 0 if there is no next item. */
	RF_LIST_ITEM	*mid; /*!< \brief The item that the iterator points on. 0 if at the begining or end.*/
	RF_LIST_ITEM	*next; /*!< \brief The next item. 0 if there is no next item. */
}RF_LIST_ITERATOR;







/*! \brief Represents a mathematical domain
 *
 * A domain has a name and a list of elements. Here the elements are of type RF_ELEMENT.
 * After starting using the domain, the elements should not be changed or sorted! That is because other
 * structs like RF_RELATION reley on the elements in the domain.
 * An element can be a string or an other domain.
 */
typedef struct rf_domain
{
	char	*name;		/*!< \brief domain name */
	
	/*! \brief elements in the domain.
	 *
	 * A list of pointers to struct RF_ELEMENT. This list should never be changed or sorted
	 * while the domain is in use of some other struct like RF_RELATION!
	 */
	RF_LIST	*elements;
} RF_DOMAIN;







enum rf_enum_et{RF_ET_NAME, RF_ET_DOMAIN, RF_ET_GLOBAL_DOMAIN};


enum rf_lexer_mode{RF_LEXER_NORMAL, RF_LEXER_CROSS, RF_LEXER_FILE};
enum rf_parser_ptd{RF_PTD_DATA, RF_PTD_RELATION, RF_PTD_OPERATION, RF_PTD_FORMULA};





/*! \brief Represents a mathematical element
 *
 * An element can be a name or a domain.
 */
typedef struct rf_element
{
	/*! \brief Describes what is in data. A value from ::rf_enum_et.
	 */
	int		type;
	
	/*! \brief name or domain
	 *
	 * The data pointed to depends on the value of type.
	 *
	 * - RF_ET_NAME: data has type char*
	 * - RF_ET_DOMAIN: data has type RF_DOMAIN*
	 * - RF_ET_GLOBAL_DOMAIN: data has type RF_DOMAIN*. Will not be freed when the element is destroyed.
	 */
	void	*data;
} RF_ELEMENT;










/*enum {__SINGLE_BLOCK, __MULTI_BLOCK};*/

/*!
 @brief A 2 dimensional array.
 
 The table abstracts a simple array. It is used
 in RF_OPERATION and RF_RELATION to hide the implementation of the array. The table can set to
 binary and string mode (::rf_enum_tt). In binary mode it uses every bit allocated. In string
 mode it stores pointers to strings.
 */
typedef struct rf_table
{
	int				type;	/*!< \brief Describes the data stored in data. Value must be from enum ::rf_enum_tt. */
	unsigned int	width;
	unsigned int	height;
	
	/*!
	 @brief The data stored in the table. Depends on the type (::rf_enum_tt).
	 - RF_TT_BINARY: data is of type char *. An array of char. Every bit is used!
	 - RF_TT_STRING: data is of type char **. An array of strings.
	 */
	void			*data;
} RF_TABLE;







/*! \brief Represents a mathematical relation
 
 An relation has a name and is based on 2 domains (domain_1 -> domain_2). The relation also has a table with
 all possible solutions. If the relation needs to be calculated, the solution is just picked
 from the right position in the table. The relation has the form "left_element relation right_element" in the Relafix language.
 */
typedef struct rf_relation
{
	char		*name;		/*!< \brief The name of the relation */
	RF_DOMAIN	*domain_1;	/*!< \brief The domain from which the left element must be. */
	RF_DOMAIN	*domain_2;	/*!< \brief The domain from which the right element must be. */
	RF_TABLE	*table;		/*!< \brief Contains the solutions in form of element names from domain boolean. The type of the table is RF_TT_BINARY. */
} RF_RELATION;








/*!
\brief This structure is used to parse the TABLE.

While the TABLE is parsed the rows are added to the structure RF_PARSER_TABLE_DATA.
*/
typedef struct
{
	char	*element; /*!< \brief The name of the row */
	RF_LIST	*values; /*!< \brief The values in the row matching the columncount. type of the value is char * */
} RF_PARSER_TABLE_ROW;






/*!
\brief Objects a formula node can take.

@relates RF_FORMULA
*/
enum rf_enum_ft{RF_FO_EMPTY, RF_FO_ELEMENT, RF_FO_ID, RF_FO_FUNCTION, RF_FO_OPERATION, RF_FO_RELATION,
	RF_FO_VARIABLE, RF_FO_NEGATION, RF_FO_DOMAIN, RF_FO_ERROR};






/*!
 @brief modes of RF_TABLE
 */
enum rf_enum_tt{RF_TT_BINARY, RF_TT_STRING};






/*!
 \brief An dynamic array that takes pointers to data.
 
 It will keep track of the arraysize and grow if its full. It will grow to the double of the
 size it had before. The pointers are stored in a void* buffer allocated with malloc().
 */
typedef struct rf_array
{
	unsigned int length;	/*!< \brief The allocated memory */
	unsigned int count;		/*!< \brief The elements in the memory. The size of the array */
	void **array;			/*!< \brief The array that stores the pointers to the data */
} RF_ARRAY;









/*!
 \brief A stack based on RF_ARRAY
 */
typedef struct rf_stack
{
    int pos;			/*!< \brief last position in the array (top of stack). */
    RF_ARRAY *array;	/*!< \brief the array that contains the data */
} RF_STACK;





/*! \brief Represents a systemfunction of the relafix language.
 
 The language of Relafix has some functions that can be used in the expressions. These
 functions will be represented with this structure in the relafix library.
 */
typedef struct rf_function
{
	char	*name;			/*!< \brief Name of the function */
	int		argument_count;	/*!< \brief The number of arguments the equivalent Relafix language function will take */
	void	*function;		/*!< \brief Points to the C function */
	char	*description;	/*!< \brief Description of the function. Will not be freed by rf_function_destroy()! */
} RF_FUNCTION;










/*!
 \brief Represents the negation function of the Relafix language.
 
 In the Relafix language the user can define the negation based on a domain. This structure is
 used in relafixlib to handle this.
 */
typedef struct rf_negation
{
	char		*name;		/*!< \brief Name of negation. */
	RF_DOMAIN	*domain;	/*!< \brief The domain keeping the elements that are negated */
	
	/*!
	 \brief List of elementnames (char *) and their negation.
	 
	 The list has the following format: 'original, negation, original, negation, ...'. That means,
	 that after a original always the negation to that original follows. The
	 list must have the double amount of elements then the domain has.
	 */
	RF_LIST		*items;	
} RF_NEGATION;







/*! \brief Represents a mathematical operation
 
 An operation has a name and is based on 3 domains (domain_1 X domain_2 -> domain_3). The operation also has a table with
 all possible solutions. If the operation needs to be calculated, the solution is just picked
 from the right position in the table. The operation has the form "left_element operation right_element" in the Relafix language.
 */
typedef struct rf_operation
{
	char		*name;		/*!< \brief The name of the operation */
	RF_DOMAIN	*domain_1;	/*!< \brief The domain from which the left element must be. */
	RF_DOMAIN	*domain_2;	/*!< \brief The domain from which the right element must be. */
	RF_DOMAIN	*domain_3;	/*!< \brief The domain from which the element of the solution must be. */
	RF_TABLE	*table;		/*!< \brief Contains the solutions in form of element names from domain_3. The type of the table is RF_TT_STRING. */
} RF_OPERATION;








/*!
\brief The node of an formula tree.

Depending on the type (rf_enum_ft) it contains an object. arguments is a list of RF_FORMULA structs.
It can be understood as childnodes of the curent one. In location the position in the sourcefile is
been saved for later use. A formula can be calculated with a call to the function rf_formula_calc().
*/
typedef struct rf_formula
{
    int				type; /*!< \brief The type of the object saved in the node. Must be from rf_enum_ft */
    RF_LOCATION		location; /*!< \brief The location in the sourcecode. Will be used to create an useful errormessage */
    RF_ARRAY		*arguments; /*!< \brief If type is RF_FO_FUNCTION, RF_FO_NEGATION, RF_FO_OPERATION or RF_FO_RELATION then arguments is a list to RF_FORMULA* that are the arguments of the object. */
    char			*element; /*!< \brief If type is RF_FO_ELEMENT or RF_FO_ITEM */
    RF_FUNCTION		*function; /*!< \brief If type is RF_FO_FUNCTION */
    RF_NEGATION		*negation; /*!< \brief If type is RF_FO_NEGATION */
    RF_OPERATION	*operation; /*!< \brief If type is RF_FO_OPERATION */
    RF_RELATION		*relation; /*!< \brief If type is RF_FO_RELATION */
    RF_DOMAIN		*domain; /*!< \brief If type is RF_FO_DOMAIN */
    char			variable; /*!< \brief If type is RF_FO_VARIABLE, this can be X or Y */
} RF_FORMULA;










/*!
\brief This structure is used to parse the TABLE.

After the TABLE is parsed, the real table is created with the help of this structure
(To fit the parserrules it also contains other types then table)
*/
typedef struct rf_parser_table_data
{
    int				type; /*!< \brief Must be from ::rf_parser_ptd */
    RF_LIST			*rows; /*!< \brief The rows of the table. Type is RF_PARSER_TABLE_ROW *. type is RF_PTD_DATA */
    RF_LIST			*columns; /*!< \brief The columnnames of the table. Type is char *. type is RF_PTD_DATA */
    RF_RELATION		*relation; /*!< \brief If type is RF_PTD_RELATION */
    RF_OPERATION	*operation; /*!< \brief If type is RF_PTD_OPERATION */
    RF_FORMULA		*formula; /*!< \brief If type is RF_PTD_FORMULA	*/
} RF_PARSER_TABLE_DATA;








/*!
\brief Represents the result of the execution of an formula.

It is important to understand the meaning of the fields is_temporary and can_delete!
is_temporary means that the object in the result is only temporary available. The user can take the ownership
of the object, but he must set can_delete to false!!! can_delete is important for the rf_formula_destroy_result() function.
The function decides on this flag if it will delete the object if it is temporary. If is_temporary is false, then this means that the
object is a global one. For example a global domain.
*/
typedef struct rf_formula_result
{
    int				type; /*!< \brief The type of the object contained. Must be from rf_enum_ft */
    RF_ARRAY		*arguments; /*!< \brief If the type is negation, operation or relation, then here are the arguments for them */
    char			*element; /*!< \brief If the type is RF_FO_ELEMENT or RF_FO_ID */
    RF_NEGATION		*negation; /*!< \brief If the type is RF_FO_NEGATION */
    RF_OPERATION	*operation; /*!< \brief If the type is RF_FO_OPERATION */
    RF_RELATION		*relation; /*!< \brief If the type is RF_FO_RELATION */
    RF_DOMAIN		*domain; /*!< \brief If the type is RF_FO_DOMAIN */
    char			*error; /*!< \brief If the type is RF_FO_ERROR, here is a pointer to an error message */
    RF_LOCATION		location; /*!< \brief If the type is RF_FO_ERROR, here goes the location where the error did occur */
    RF_BOOL			is_temporary; /*!< \brief If true the object in this struct is only temporary available. Else it is a global object. */
    RF_BOOL			can_delete; /*!< \brief If true, a call to function rf_formula_destroy_result() will delete the object if it is temporary! */
} RF_FORMULA_RESULT;



#endif
