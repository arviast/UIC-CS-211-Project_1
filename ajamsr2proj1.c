// Arvinbayar Jamsranjav
// CS 211
// Project 1

#include <stdio.h>
#include <stdlib.h>

// function that finds target value by adding 2 indexes
// or returns to -1
//...
int TwoSumFunction(int arr[], int size, int target, int*index1, int* index2) {
    
    int startIndex = 0;              // initializing my low end to 0
    int endIndex = size - 1;         // initializing my high end to (size-1)
    int sum = 0;
    
    // iterate through the array and find sum of the 2 numbers
    // ...
    int i;
    for ( i = 0; i < size; i++) {
        sum = (arr[startIndex] + arr[endIndex]);
        // when sum is bigger than target input move high index to the left
        // ...
        if(sum > target) {
            endIndex--;
        }
        // when sum is smaller than target input move low index to the right
        // ...
        else if (sum < target) {
            startIndex++;
        }
        // if they didn't find anything and meets at one index then break
        // then it will return to -1
        // ...
        if(endIndex == startIndex) {
            break; 
        }
        // if we find target then assign index1 and index2
        // also return to 1
        // ...
        if (target == sum) {
            *index1 = startIndex;
            *index2 = endIndex;
            return 1;
        }
    }
    return -1;
}

// making a copy from original array before sorting
// ...
void makeArrayCopy (int fromArray[], int toArray[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        toArray[i] = fromArray[i];
    }
}

// using insertion sorting
// ...
void myFavoriteSort (int arr[], int size) {
    
    int i;
    int j;
    int compareValue;
    // iterating through array and finding compare value
    // j is index of previous array value
    // ...
    for (i = 1; i < size; i++) {
        compareValue = arr[i];
        j = i - 1;
        // if the value arr[j] is bigger then move small
        // value all the way to the front where it supposed
        // to be
        // ...
        while(j >= 0 && arr[j] > compareValue) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = compareValue;
    }
}

int main ()
{
 int arraySize = 10;                                        // starting my array size with 10
 int *origP;                                                // pointer to my original array
 int *largeP;                                               // pointer used for doubling the size of the array
 int *copyArray;                                            // pointer used in makeArrayCopy function
 int val = 0;                                               // declaring integer for user input
 int counter = 0;                                           // to count how many inputs user give to us
 origP = (int*)malloc(arraySize * sizeof(int));             // dynamically allocating our array

 /* prompt the user for input */
 printf ("Enter in a list of numbers ito be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 /* loop until the user enters -999 */
 scanf ("%d", &val);
 while (val != -999)
   {
    /* store the value into an array */
       // if userInput exceeds our size of array
       // then doubling the size, creating new large array,
       // copying back to my original array
       // ...
       if ( arraySize <= counter) {
           largeP = (int*)malloc(arraySize * 2 * sizeof(int));
           int i;
           for (i = 0; i <arraySize; i++) {
               largeP[i] = origP[i];
           }
           free(origP);
           arraySize = arraySize * 2;
           origP = (int*)malloc(arraySize * sizeof(int));
           int d;
           for(d = 0; d < counter; d++) {
               origP[d] = largeP[d];
           }
           free(largeP);
       }
       origP[counter] = val;
       counter++;
    
       
    /* get next value */
    scanf("%d", &val);
   }
    
 /* call function to make a copy of the array of values */
 copyArray = (int*)malloc(arraySize * sizeof(int));
 makeArrayCopy(origP, copyArray, counter);
 
 /* call function to sort one of the arrays */
 myFavoriteSort(copyArray, counter);

 // creating new array for target userInputs
 // size depends from user, so again dynamically
 // allocating it
 // ...
 int *targetArray;                                                  // pointer to new targetArray
 int sizeOfTarget = 10;                                             // initial size of that array = 10
 int numOfTarget = 0;                                               // counting actual number of targets
 int savedIndex1;                                                   // when we found target use this integer to save
 int savedIndex2;                                                   // when we found target use this integer to save
 targetArray = (int*)malloc(sizeOfTarget * sizeof(int));
 
//  loop until the user enters -999
 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);
 while (val != -999)
   {
    /* call function to perform target sum operation */
    targetArray[numOfTarget] = val;
    ++numOfTarget;
    // double the size if numOfTarget exceeds 10
    // used same method that I used on my original array
    // ...
    if (sizeOfTarget <= numOfTarget) {
        int* copyTargetArray;
        copyTargetArray = (int*)malloc(numOfTarget * sizeof(int));
        int j;
        for (j = 0; j < numOfTarget; j++) {
            copyTargetArray[j] = targetArray[j];
        }
        // after doubling the size copy back
        sizeOfTarget = sizeOfTarget * 2;
        targetArray = (int*)malloc(sizeOfTarget * sizeof(int));
        int l;
        for ( l = 0; l < numOfTarget; l++) {
            targetArray[l] = copyTargetArray[l];
        }
    }
    // saving return of TwoSumFunction to the integer "result"
    // ...
    int result = TwoSumFunction(copyArray, counter, val, &savedIndex1, &savedIndex2);
       
    /* print out info about the target sum results  */
    // fixed spacing
    // ...
    if (result == 1) {
       printf("%d", val);
        if(val < 10) {
            printf("   ");
        }
        else if(val < 100) {
            printf("   ");
        }
        else if(val < 1000) {
            printf("  ");
        }
        else if(val < 10000) {
            printf(" ");
        }
       printf(" Yes! at Index %d", savedIndex1);
       printf(" and Index %d\n", savedIndex2);
    }
    if (result == -1) {
        printf("%d", val);
        if(val < 10) {
            printf("     ");
        }
        else if(val < 100) {
            printf("    ");
        }
        else if(val < 1000) {
            printf("   ");
        }
        else if(val < 10000) {
            printf(" ");
        }
        printf("No!\n");
    }

    /* get next value */
    scanf("%d", &val);
   }


 printf ("Good bye\n");
 return 0;
}
