// header file
#include "ArrayUtilities.h"

// constants defined here
const int CELL_WIDTH = 5;
const int MAX_ARRAY_SIDE = 25;
const int MIN_ARRAY_SIDE = 3;

const char THICK_DIVIDER_LINE = '=';
const char THIN_DIVIDER_LINE = '-';

int **clearTwoDimArray( int **array, int numCols )
   {
    int colIndex;

    for( colIndex = 0; colIndex < numCols; colIndex++ )
       {
        free( array[ colIndex ] );
       }

    free( array );

    return NULL;
   }

void copyArray( int **destArray, int **srcArray, int numRows, int numCols )
   {
     // Define Variables
     int rowIndex, colIndex;

     // Loop Through the Row Array
     for(rowIndex = 0; rowIndex < numRows; rowIndex++)
     {
       // Loop Through the Column Array
       for(colIndex = 0; colIndex < numCols; colIndex++)
       {
         // Copying Over the Elements
         destArray[rowIndex][colIndex] = srcArray[rowIndex][colIndex];
       }
     }
   }

int **createTwoDimArray( int numRows, int numCols )
   {
    int **twoDimPtr;
    int rowIndex, colIndex;

    twoDimPtr = (int **)malloc( numRows * sizeof( int *) );

    // should have been numRows instead of numCols in the parameters
    for( rowIndex = 0; rowIndex < numCols; rowIndex++ )
       {
        twoDimPtr[ rowIndex ] = (int *)malloc( numCols * sizeof( int ) );

        for( colIndex = 0; colIndex < numCols; colIndex++ )
           {
            twoDimPtr[ rowIndex ][ colIndex ] = 0;
           }
       }

    return twoDimPtr;
   }

void displayArray( int **array, int numRows, int numCols, char *title )
   {
     // Declare Variables
     int indexRow, indexCol;

     // Printing the Title
      // Function: printf
     printf("\nArray Display - %s\n", title);

     // Displaying the Table

      // Printing the First Thick Line
        // Function: displayDividerLine
      displayDividerLine(numCols, THICK_DIVIDER_LINE);

      // Looping Through the Rows
      for(indexRow = 0; indexRow < numRows; indexRow++)
      {
        // Printing the Thin Line
          // Function: displayDividerLine
        if(indexRow != 0)
        {
          displayDividerLine(numCols, THIN_DIVIDER_LINE);
        }
        // Printing the First Pipe
          // Function: printf
        printf("%c", PIPE);

      // Looping Through the Columns
      for(indexCol = 0; indexCol < numCols; indexCol++)
      {
        // Checking if the Element is Over Zero
        // When it is, Print the Element
        if(array[indexRow][indexCol] > 0)
        {
          // Printing the Element
            // Function: printf
          printf("%5d ", array[indexRow][indexCol]);
        }
        // Otherwise it will print asterisks
        else
        {
          // Printing the Asterisks
            // Function: printf
          printf("  *** ");
        }
        // Printing the Next Pipe
          // Function: printf
        printf("%c", PIPE);
      }
      // Printing a Newline
        // Function: printf
      printf("%c", NEWLINE_CHAR);
      }
      // Printing the End Line (Last Thick Line)
        // Function: displayDividerLine
      displayDividerLine(numCols, THICK_DIVIDER_LINE);
   }

void displayDividerLine( int horizNumCells, char thicknessChar )
   {
     // Define Variables
     int indexCell;

     // Printing the Pipe
      // Function: printf
    printf("%c", PIPE);

    // Looping Through the Cell
    for(indexCell = 0; indexCell < horizNumCells; indexCell++)
    {
      // Printing the Line
        // Function: printChars
      printChars(CELL_WIDTH, thicknessChar);

      // Printing the Second Pipe
        // Function: printf
      printf("%c", PIPE);
    }
    // Printing a New Line
      // Function: printf
    printf("%c", NEWLINE_CHAR);


   }

int getArraySide( int maxSideSize )
   {
     // Declaring Variables
     int sizing = 0;

     // Prompting the User for Size
      // Function: printf
    printf("Enter array side (%d - %d): ", MIN_ARRAY_SIDE, MAX_ARRAY_SIDE);
    // Using a Do While Loop to Make Sure Input is in Range
    do
    {
      // Storing the User Input in the Sizing Variable
        // Function: scanf
      scanf("%d", &sizing);

      // Testing the User Input
      if(sizing < MIN_ARRAY_SIDE || sizing > maxSideSize)
      {
        // If the Input is Out of Range, Display Error Message
          // Function: printf
        printf("Incorrect entry - Enter array side (%d - %d): ",
                MIN_ARRAY_SIDE, MAX_ARRAY_SIDE);
      }
    }
    // Keeps Prompting Until in Range
    while(sizing < MIN_ARRAY_SIDE || sizing > maxSideSize);

    // Print New Line
      // Function: printf
    printf("%c", NEWLINE_CHAR);

    // Returning the User Input
    return sizing;
   }

int getRandBetween( int lowLimit, int highLimit )
   {
    int range = highLimit - lowLimit + 1;

    return rand() % range + lowLimit;
   }

void getRangeToRemove( RangeType *inputData, int numRows, int numCols )
   {
     // Declaring Variables
     int sideLimit = numRows * numCols;

     // User Input for Range Removal
       // Printing the Range Removal Entry Title
       // Function: printf
     printf("Range Removal Entry:\n");

     // Testing if it is in Range
     do
       {
            do
               {
                 // Prompting User for Low Limits
                  // Function: printf
                  printf("    - Enter low limit (1 - %d): ", sideLimit);

                 // Storing the User Input
                  // Function: scanf
                  scanf("%d", &inputData -> lowVal);

                  // Testing to See if it is in Range
                  if(inputData -> lowVal < 1 || inputData -> lowVal > sideLimit)
                    {
                      // Printing the Error Message
                        // Function: printf
                      printf("--- Incorrect entry - Retry: \n");
                    }
               }

               // Keep Prompting Until it is in Range
               while (inputData -> lowVal < 1 || inputData -> lowVal > sideLimit);

                 // Prompting User for High Limits
                   // Function: printf
                 printf("    - Enter high limit (%d - %d): ",
                                           inputData->lowVal + 1, sideLimit);

                // Storing the User Input
                 // Function: scanf
                 scanf("%d", &inputData->highVal);

                // Testing if High Limit Input is in Range
                 if(inputData->highVal < inputData->lowVal + 1 ||
                                           inputData->highVal > sideLimit)
                  {
                    // Printing the Error Message
                     // Function: printf
                    printf("--- Incorrect entry - Retry: \n");
                  }
               }
               while(inputData->highVal < inputData->lowVal + 1 ||
                                                inputData->highVal > sideLimit);
   }



bool isInArray( int **array, int numRows, int numCols, int searchVal )
   {
     // Define Variables
     int rowIndex, colIndex;

     // Loop Through the Row Array
     for(rowIndex = 0; rowIndex < numRows; rowIndex++)
     {
       // Loop Through the Column Array
       for(colIndex = 0; colIndex < numCols; colIndex++)
       {
         // Checking for the Search Value Array
         if(array[rowIndex][colIndex] == searchVal)
         {
           // Returning True if the Array is Found
           return true;
         }
       }
     }
     // Returning False
     return false;
   }

void loadArrayWithValues( int **array, int numRows, int numCols )
   {
     // Initialize Variables
     int indexRow, indexCol, replaceValue;

     // Looping Across the Rows
     for(indexRow = 0; indexRow < numRows; indexRow++)
     {
       // Looping Across the Columns
       for(indexCol = 0; indexCol < numCols; indexCol++)
       {

         // Looping to Make Sure No Number is the Same
         do
         {
           // Generating a New Value
            // Function: getRandBetween
            replaceValue = getRandBetween(1, numRows * numCols);
         }
         // To Keep Going as Long as it is in the Table
          // Function: isInArray
         while(isInArray(array, numRows, numCols, replaceValue));

         // Sending the New Value to the Array
         array[indexRow][indexCol] = replaceValue;

       }
     }
   }

void printChars( int numChars, char outChar )
   {
    if( numChars > 0 )
       {
        printChars( numChars - 1, outChar );
       }

    printf( "%c", outChar );
   }

void removeRange( int **array, int numRows, int numCols, RangeType range )
   {
     // Define Variables
     int removeIndex;

     // Loop from lowest range value to the highest range value (inclusive)
     for(removeIndex = range.lowVal; removeIndex <= range.highVal; removeIndex++)
     {
       setElementToZero(array, numRows, numCols, removeIndex);
     }
   }

bool setElementToZero( int **array, int numRows, int numCols, int searchValue)
   {
     // Define Variables
     int rowIndex, colIndex;

     // Loop Through Row Array
     for(rowIndex = 0; rowIndex < numRows; rowIndex++)
     {
       // Loop Through Column Array
       for(colIndex = 0; colIndex < numCols; colIndex++)
       {
         // Checking for Search Value Array
         if(array[rowIndex][colIndex] == searchValue)
         {
           // Making the Array set to Zero
           array[rowIndex][colIndex] = 0;

           // Returning True
           return true;
         }
       }
     }
     // Returning False
     return false;
   }
