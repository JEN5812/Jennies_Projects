// header file
#include "ArrayUtilities.h"

int main()
   {
    // initialize program

       // initialize variables
       int numRows, numCols;
       RangeType rangeToRemove;
       int **intArray_1, **intArray_2;

       // show title
          // function: printf
       printf( "\nArray Manipulation Program\n" );
       printf( "==========================\n\n" );

       // initialize random seed
          // function: srand, time
       srand( time( NULL ) );

    // get user input

       // enter size of square array - one side length
          // function: enterArraySide
       numRows = getArraySide( MAX_ARRAY_SIDE );

       // set other side length for square array
       numCols = numRows;

       // enter range to be removed
          // function: getRangeToRemove
       getRangeToRemove( &rangeToRemove, numRows, numCols );

    // implement processing

       // create arrays
          // function: createTwoDimArray
       intArray_1 = createTwoDimArray( numRows, numCols );
       intArray_2 = createTwoDimArray( numRows, numCols );

       // load array with values
          // function: loadArrayWithValues
       loadArrayWithValues( intArray_1, numRows, numCols );

       // copy array
          // function: copyArray
       copyArray( intArray_2, intArray_1, numRows, numCols );

       // remove range of values from second array
          // function: removeRange
       removeRange( intArray_2, numRows, numCols, rangeToRemove );

    // display results

       // display full (first) array in cells
          // function: displayArray
       displayArray( intArray_1, numRows, numCols, "Original Array" );

       // display (second) array with removed values in cells
          // function: displayArray
       displayArray( intArray_2, numRows, numCols, "Values Removed" );

    // end program

       // clear dynamic two dimensional array
          // function: clearArray
       intArray_1 = clearTwoDimArray( intArray_1, numRows );
       intArray_2 = clearTwoDimArray( intArray_2, numRows );

       // display program end
          // function: printf
       printf( "\nEnd program\n" );

       // return program success
       return 0;
   }
