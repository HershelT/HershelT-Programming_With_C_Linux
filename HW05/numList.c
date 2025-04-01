/*** stddef for NULL ***/
#include <stddef.h>

/*************************************************
*  numList.c
*  ---------
*  A program containing functions for implementing
*  a new data type that holds a list of numbers
*  using a single string.
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/


/********************************/
/**    SYMBOLIC CONSTANTS      **/
/********************************/

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 1.1
* function isValidNumList
* params:
* str (char*)
* Return 1 if a string is a valid number list
* and return 0 otherwise
*********************************/
int isValidNumList(const char* str);

/*********************************
* Problem 1.2
* function numWordsInList
* params:
* str (char*)
* Return the number of words in list
*********************************/
int numWordsInList(const char* str);

/*********************************
* Problem 1.3
* function get1stNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the first number in list (skipping spaces).
* If 1st word is not a valid number, return -1.0
* If list is empty, return -2.0
*********************************/
double get1stNumberValue(const char* numList);

/*********************************
* Problem 1.4
* function compactNumList
* params:
* numList (char*)
* Compacts the number list by removing
* consecutive spaces and leading 0s
* Returns a pointer to the num list
*********************************/
char* compactNumList(char* numList);

/*********************************
* Problem 1.5
* function getNextNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the next number in list.
* If next word is invalid number, return -1.0
* If reached end of list, return -2.0 and make
* sure that next call will return first number.
* Uses static variables to keep information
* from prev execution
*********************************/
double getNextNumberValue(const char* numList);

/*********************************
* Problem 1.6
* function performOperation
* params:
* numList (char*)
* op      (char)
* If op is '+' return the sum of all numbers in the list (0 if empty)
* If op is '*' return the product of all numbers in the list (1 if empty)
* If op is not '+' or '*' or one the list is not a valid number list, return -1
*********************************/
double performOperation(const char* numList, char op);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/
/*********************************
* Problem 1.1
* function isValidNumList
* params:
* str (char*)
* Return 1 if a string is a valid number list
* and return 0 otherwise
*********************************/
int isValidNumList(const char* str) {
   /***      !!!            DO NOT DEFINE ADDITIONAL LOCAL VARIABLES               !!!   ***/
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   // if the string is NULL, return 0
   if (str == NULL) {
      return 0;
   }
   // skip leading spaces uses * to get the value of the pointer
   while (*str != '\0') {
      // if the character is not a space or a digit, return 0
      if (*str != ' ' && (*str < '0' || *str > '9')) {
         return 0;
      }
      str++;
   }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   /*** should reach here iff str is a valid number list ***/
   return 1;
}

/*********************************
* Problem 1.2
* function numWordsInList
* params:
* str (char*)
* Return the number of words in list
*********************************/
int numWordsInList(const char* str) {
   int numWords = 0;
   /***      !!!   DO NOT DEFINE ADDITIONAL LOCAL VARIABLES (OTHER THAN numWords)  !!!   ***/
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   while (*str != '\0') {
      // skip leading spaces
      while (*str == ' ') {
         str++;
      }
      // if the character is not a space, increment numWords, and skip the word
      if (*str != ' ' && *str != '\0') {
         numWords++;
      }
      // skip the word
      while (*str != ' ' && *str != '\0') {
         str++;
      }
   }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numWords;
}

/*********************************
* Problem 1.3
* function get1stNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the first number in list (skipping spaces).
* If 1st word is not a valid number, return -1.0
* If list is empty, return -2.0
*********************************/
double get1stNumberValue(const char* numList) {
   double value = 0.0;
   /***      !!!   DO NOT DEFINE ADDITIONAL LOCAL VARIABLES (OTHER THAN value)     !!!   ***/
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   // if the string is NULL or empty, return -2.0
   if (numList == NULL || numWordsInList(numList) == 0){
      return -2.0;
   }
   // skip leading spaces
   while (*numList == ' ') {
      numList++;
   }
   // if the character is a digit, convert it to a number
   while (*numList != ' ' && *numList != '\0') {
      // if the character is not a digit, return -1.0
      if (*numList < '0' || *numList > '9') {
         return -1.0;
      }
      value = value * 10 + (*numList - '0');
      numList++;
   }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

/*********************************
* Problem 1.4
* function compactNumList
* params:
* numList (char*)
* Compacts the number list by removing
* consecutive spaces and leading 0s
* Returns a pointer to the num list
*********************************/
char* compactNumList(char* numList) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   if (numList == NULL) {
        return NULL;
   }
   // Pointer to write the compacted version to
   char* writeNewNumList = numList; 
   // Pointer to read the original version from
   char* readNumList = numList;  

   // Skip initial spaces
   while (*readNumList == ' ') {
      readNumList++;
   }
   // Copy the compacted string
   while (*readNumList != '\0') {
      // Skip leading zeros for each number and deletes it if anything follows it
      while (*readNumList == '0' && (*(readNumList + 1) != ' ' && *(readNumList + 1) != '\0')) {
         readNumList++;
      }
      // Copy current word until the next space or end of string
      while (*readNumList != ' ' && *readNumList != '\0') {
         *writeNewNumList = *readNumList;
         //Increment the pointers
         writeNewNumList++;
         readNumList++;
      }
      // Skip spaces between words
      while (*readNumList == ' ') {
         readNumList++;
      }
      // Add a single space if there are more words
      if (*readNumList != '\0') {
         *writeNewNumList = ' ';
         writeNewNumList++;
      }
   }
    // Null-terminate the compacted string by adding a null character at the end
   *writeNewNumList = '\0';
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numList;
}

/*********************************
* Problem 1.5
* function getNextNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the next number in list.
* If next word is invalid number, return -1.0
* If reached end of list, return -2.0 and make
* sure that next call will return first number.
* Uses static variables to keep information
* from prev execution
*********************************/
double getNextNumberValue(const char* numList) {
   /*** static local variables keeping track of
        inforamtion from the last call to this function:
        prevNumList    - last numList argument passed to function
        nextNumInList  - pointer to first char in next number in list
   ***/
   static const char* prevNumList   = NULL;
   static const char* nextNumInList = NULL;
   double value = 0.0;
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   if (numList == NULL) {
        // If numList is NULL, reset internal state
        prevNumList = prevNumList;
        nextNumInList = prevNumList;
        return -2.0;
    }


   // If this is the first call or the numList is different from the previous one, reset
   if (numList != prevNumList) {
      prevNumList = numList;
      nextNumInList = numList;
   }
   
   // Skip space characters in front
   while (*nextNumInList == ' ') {
      nextNumInList++;
   }

   // If we've reached the end of the list, reset by pointing to the beginning of the list
   if (*nextNumInList == '\0') {
      nextNumInList = prevNumList;
      return -2.0;
   }

   // Use get1stNumberValue to get the value of the next number
   value = get1stNumberValue(nextNumInList);

   // Move nextNumInList to the next word while skipping spaces
   while (*nextNumInList != ' ' && *nextNumInList != '\0') {
      nextNumInList++;
   }

   // Skip spaces in order to point to the next number
   while (*nextNumInList == ' ') {
      nextNumInList++;
   }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

/*********************************
* Problem 1.6
* function performOperation
* params:
* numList (char*)
* op      (char)
* If op is '+' return the sum of all numbers in the list (0 if empty)
* If op is '*' return the product of all numbers in the list (1 if empty)
* If op is not '+' or '*' or one the list is not a valid number list, return -1
*********************************/
double performOperation(const char* numList, char op) {
   double value = 0.0;
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   
   //reset getNextNumberValue before using
   getNextNumberValue(NULL);
   // Check if the numList is valid and return -1 if it is not
   if (!isValidNumList(numList)) {
      return -1.0;
   }

   // Check if the operator is valid
   if (op != '+' && op != '*') {
      return -1.0;
   }

   // If the list is empty, return 0.0 for '+' and 1.0 for '*'
   if (numWordsInList(numList) == 0) {
      if (op == '+') {
         return 0.0;
      } else if (op == '*') {
         return 1.0;
      }
   }

   // Perform the operation
   double currentNumber;
   if (op == '*') {
      value = 1.0; // Initialize sum to 1 for multiplication
   } 


   
   // char* tempNum = compactNumList(numList);
   while ((currentNumber = getNextNumberValue(numList)) != -2.0) {
      if (op == '+') {
         value += currentNumber;
      } else if (op == '*') {
         value *= currentNumber;
      }
   }

   //reset getNextNumberValue after using
   getNextNumberValue(NULL);
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

/*** end of file ***/
























#include <stdio.h>
#include <string.h>

/*************************************************
*  simpleCalc.c
*  ------------
*  A program for computing simple arithmetic
*  operations on numbers
*************************************************/


/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Functions implemented in Problem 1
*********************************/
int    isValidNumList(const char* str);
int    numWordsInList(const char* str);
double get1stNumberValue(const char* numList);
char*  compactNumList(char* numList);
double getNextNumberValue(const char* numList);
double performOperation(const char* numList, char op);

/*** symbolic constant for the max num of chars
     that are allowed per number list
***/
#define MAX_CHARS_IN_LIST 100
/***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
int main() {
      // Local variables
      char numList[MAX_CHARS_IN_LIST + 1] = {0}; // Array to hold the number list
      char ch; // Character read from the input stream
      int numOfWords = 0;
      int numOfCharsInNumber = 0;
      double result; // Result of the operation
      int i = 0; // Index of the word that is not a number

      // Read characters from the input stream
      while (scanf("%c", &ch) != EOF) {
         //checks if i is greater than 100 and aborts
         if (i > 100) {
            printf("Aborting because number list contains more than 100 characters\n");
            return 2;
         }
         // checks if the number of characters in the next number is greater than 5 and aborts
         if (numOfCharsInNumber > 5) {
            printf("Aborting because number list contains more than 5 characters\n");
            return 2;
         }

         //If arrives at an operator, perform the operation
         if (ch == '+' || ch == '*') {
            //if the number list is empty or the number of words is 0, return 0
            if (numWordsInList(numList) == 0 || numOfWords == 0) {
               return 0;
            }
            //compact the number list
            compactNumList(numList);
            //perform the operation
            result = performOperation(numList, ch);
            //if the result is -1 or the number list is not valid, return 1
            if (result == -1 || isValidNumList(numList) == 0) {
               printf("Not Valid! Aborting because word #%d in list is not a valid number\n", i + 1);
              return 1;
            }
            //if the result is not -1, print the result
            //by going through each number in the list and seperating it by the operator
            for (int j = 0; j < strlen(numList); j++) {
               if (numList[j] == ' ') {
                  printf("%c", ch);
               }
               else {
                  printf("%c", numList[j]);
               }
            }
            // print the result
            printf("=%0.0f\n", result);

            //reset the number list, numOfWords, numOfCharsInNumber, and i
            numList[0] = '\0';
            numOfWords = 0;
            numOfCharsInNumber = 0;
            i = 0;
         }     
         if (ch == ' ' || (ch >= '0' && ch <= '9')) {
            if (ch >= '0'  && ch <= '9') {
               numOfWords++;
               numOfCharsInNumber++;
            }
            else {
               numOfCharsInNumber = 0;
            }
            numList[i] = ch;
            i++;
         }
         else if (ch != '+' && ch != '*') {
            printf("Aborting because word #%d in list is not a valid number\n", numOfWords-1);
            return 1;
         }
     }
     return 0;
}
/***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/

/*** end of file ***/