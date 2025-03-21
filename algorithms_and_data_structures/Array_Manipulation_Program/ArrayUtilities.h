#ifndef ARRAY_UTILITIES_H
#define ARRAY_UTILITIES_H

// header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "StandardConstants.h"

// constants made available to other files here
extern const int CELL_WIDTH;
extern const int MAX_ARRAY_SIDE;

extern const char THICK_DIVIDER_LINE;
extern const char THIN_DIVIDER_LINE;

// Data structures
typedef struct RangeTypeStruct
   {
    int lowVal;

    int highVal;
   } RangeType;

/*
Name: clearTwoDimArray
Process: returns allocated memory to the operating system
Function Input/Parameters: pointer to two dimensional array (int **),
                           number of columns(int)
Function Output/Parameters: none
Function Output/Returned: NULL
Device Input/---: none
Device Output/---: none
Dependencies: free (5 lines of code)
*/
int **clearTwoDimArray( int **array, int numCols );

/*
Name: copyArray
Process: copies values from one two dimensional array to another
Function Input/Parameters: pointer to source array (int **),
                           number of rows and columns (int)
Function Output/Parameters: pointer to destination array (int **)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: none (4 lines of code)
*/
void copyArray( int **destArray, int **srcArray, int numRows, int numCols );

/*
Name: createTwoDimArray
Process: creates two dimensional array of integer values
         using given row and column limits,
         sets all elements to zero
Function Input/Parameters: number of rows and columns (int)
Function Output/Parameters: none
Function Output/Returned: pointer to two dimensional array (int **)
Device Input/---: none
Device Output/---: none
Dependencies: malloc, sizeof (C keyword) (6 lines of code)
*/
int **createTwoDimArray( int numRows, int numCols );

/*
Name: displayArray
Process: displays two dimensional array of integer values greater than zero
         using given row and column limits,
         values are formatted and displayed in character cells,
         values below one are displayed as asterisks
Function Input/Parameters: pointer to two dimensional array (int **),
                           number of rows and columns (int),
                           subtitle to display (char *)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: data displayed as specified
Dependencies: displayDividerLine, printf (14 lines of code)
*/
void displayArray( int **array, int numRows, int numCols, char *title );

/*
Name: displayDividerLine
Process: displays horizontal divider line of correct width, 
         with vertical divider lines (PIPE) dividing the cells
         (of width CELL_WIDTH),
         and with given divider line thickness,
         top and bottom rows are thick dividers,
         internal rows are thin dividers
Function Input/Parameters: number of horizontal cells (int), 
                           thickness character (char)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: divider line displayed as specified
Dependencies: printf, printChars (6 lines of code)
*/
void displayDividerLine( int horizNumCells, char thicknessChar );

/*
Name: getArraySide
Process: provides user data entry for one array side 
         to be used with a square two-dimensional array,
         value entered by user must be greater than two
         and less then the maximum parameter value;
         function repeats entry process until constraints are met
Function Input/Parameters: maximum side size allowed (int)
Function Output/Parameters: none
Function Output/Returned: user entered value (int)
Device Input/keyboard: data entered by user
Device Output/monitor: prompts provided
                prompt: "Enter array side (<min side size> - <max side size>): "
                error prompt: "Incorrect entry - <original prompt>"
                Text display lines may not be repeated in code
Dependencies: printf, scanf (11 lines of code)
*/
int getArraySide( int maxSideSize );

/*
Name: getRandBetween
Process: generates random value between a given low and high value inclusive
Function Input/Parameters: low and high limits (int)
Function Output/Parameters: none
Function Output/Returned: value generated as specified
Device Input/---: none
Device Output/---: none
Dependencies: rand (2 lines of code)
*/
int getRandBetween( int lowLimit, int highLimit );

/*
Name: getRangeToRemove
Process: prompts use for range to remove, between 1 as lowest
         to highest value within array for highest;
         lowest entry must be less than highest entry,
         repeats entry until input data is correct
Function Input/Parameters: given maximum side size (int),
                           number of rows and columns (int)
Function Output/Parameters: lowest and highest range values (RangeType *)
Function Output/Returned: none
Device Input/keyboard: data entered by user
Device Output/monitor: prompts provided
prompt: "Enter low limit (1 - <max array value >): "
        "Enter high limit (<low limit plus one> - <max array value>): "
        error prompt: "Incorrect entry - Retry:", 
        then repeat above entry statements
        Text display lines may not be repeated in code
Dependencies: printf, scanf (13 lines of code)
*/
void getRangeToRemove( RangeType *inputData, int numRows, int numCols );

/*
Name: isInArray
Process: searches two dimensional array, returns true if specified value
         is found in array, false otherwise;
         must return true as soon as it is found in the test
Function Input/Parameters: pointer to two dimensional array (int **),
                           number of rows and columns (int),
                           search value (int)
Function Output/Parameters: none
Function Output/Returned: Boolean result of test as specified
Device Input/---: none
Device Output/---: none
Dependencies: none (6 lines of code)
*/
bool isInArray( int **array, int numRows, int numCols, int searchVal );

/*
Name: loadArrayWithValues
Process: given the number of rows and columns,
         loads two dimensional array with unique random values
         (no two values may be the same),
         values must start at one, and end at the maximum possible value
         for the array
Function Input/Parameters: pointer to two dimensional array (int **), 
                           number of rows and columns (int)
Function Output/Parameters: pointer to updated two dimensional array (int **)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: getRandBetween, isInArray (8 lines of code)
*/
void loadArrayWithValues( int **array, int numRows, int numCols );

/*
Name: printChars
Process: recursively prints a specified number of specified characters
Function Input/Parameters: number of characters (int),
                           character to display (char)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: character(s) displayed as specified
Dependencies: printf, printChars (recursively) (3 lines of code)
*/
void printChars( int numChars, char outChar );

/*
Name: removeRange
Process: removes a range of values within a two dimensional array
Function Input/Parameters: pointer to two dimensional array (int **),
                           number of rows and columns (int),
                           range (low, high) limits (RangeType)
Function Output/Parameters: pointer to updated two dimensional array (int **)
Function Output/Returned: void
Device Input/---: none
Device Output/---: none
Dependencies: setElementToZero (3 lines of code)
*/
void removeRange( int **array, int numRows, int numCols, RangeType range );

/*
Name: setElementToZero
Process: searches two dimensional array for value;
         if found, sets value to zero and returns true
         immediately upon making the assignment,
         otherwise returns false
Function Input/Parameters: pointer to two dimensional array (int **), 
                           number of rows and columns (int),
                           search value (int)
Function Output/Parameters: pointer to updated two dimensional array (int **)
Function Output/Returned: Boolean result of specified action
Device Input/---: none
Device Output/---: none
Dependencies: none (7 lines of code)
*/
bool setElementToZero( int **array, int numRows, int numCols, int searchValue );

#endif   // ARRAY_UTILITIES_H
