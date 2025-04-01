#include <stdio.h>

/*************************************************
*  newWord.c
*  ---------
*  A program containing functions for implementing
*  a new data type for words.
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/


/********************************/
/**    SYMBOLIC CONSTANTS      **/
/********************************/
#define BITS_PER_ASI_BLOCK 6

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 1.1
* function charToASI
* params:
* ch (char)
* Return the ASI value corresponding to a given char.
*********************************/
int charToASI(char ch);

/*********************************
* Problem 1.2
* function ASItoChar
* params:
* ASIval (int)
* Return the char associated with a given ASI value.
*********************************/
char ASItoChar(int ASIval);

/*********************************
* Problem 1.3
* function getASIblock
* params:
* newWord (int)
* ind     (int)
* Return the ASI value of the charInd'th char
* in the word encoded by newWord.
*********************************/
int getASIblock(int newWord, int ind);

/*********************************
* Problem 1.4
* function isWordFull
* params:
* newWord (int)
* Return 1 if last ASI block of newWord is used
* and 0 otherwise
*********************************/
int isWordFull(int newWord);

/*********************************
* Problem 1.5
* function newWordType
* params:
* newWord (int)
* Returns a value associated with the word type
*********************************/
int newWordType(int newWord);
/*********************************
* Problem 1.6
* function appendWordChar
* params:
* newWord (int)
* ch      (char)
* Return the new word obtained by adding the ASI 
* value of char ch to the end of newWord.
*********************************/
int appendWordChar(int newWord, char ch);

/*********************************
* Problem 1.7
* function printNewWord
* params:
* newWord (int)
* Prints new word to the screen.
*********************************/
void printNewWord(int newWord);


/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/

/*********************************
* Problem 1.1
* function charToASI
* params:
* ch (char)
* Return the ASI value corresponding to a given char.
* If char is not a letter, digit, '.' or '\0'
* the function returns -1
*********************************/
int charToASI(char ch) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   if(ch=='.') return 1;
   if(ch>='A' && ch<='Z') return ch-'A' + 2;
   if(ch>='a' && ch<='z') return ch-'a' + 28;
   if(ch>='0' && ch<='9') return ch-'0'+54;
   if(ch=='\0') return 0;
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   /*** the function reaches this point if char is invalid ***/
   return -1;
}

/*********************************
* Problem 1.2
* function ASItoChar
* params:
* ASIval (int)
* Return the char associated with a given ASI value.
* If ASI value is out of bound return '!'
*********************************/
char ASItoChar(int ASIval) {
   int a,b;
   /*** replace 121 below with appropriate expression ***/
   if(ASIval > 63 || ASIval < 1) return '!';
   /*** replace 122 below with appropriate expression ***/
   a = (ASIval != 1) ? ((ASIval -2)/ 26) + 1 : 0;    // Splitting the 4 differentt types into numbers 0-3
   /*** replace 123 below with appropriate expression ***/
   b = (ASIval-2) % 26; //Getting the offset of the ASI Value to add to base of each type to get correct letter
   switch(a) {
      case(0):
         return  '.';
      case(1):
         /*** replace a+124 below with appropriate expression ***/
         return 'A' + b;
      case(2):
         /*** replace b+125 below with appropriate expression ***/
         return 'a' + b;
      case(3):
         /*** replace 126 below with appropriate expression ***/
         return '0' + b;
      default:
      /*** do nothing here, This code should not be reached ***/
   } // end of switch
   /*** this code should not be reached ***/
   return '!';
}

/*********************************
* Problem 1.3  
* function getASIblock
* params:
* newWord (int)
* ind     (int)
* Return the ASI value of the charInd'th char
* in the word encoded by newWord.
* Indices are 0-based, and if charInd exceeds
* the maximum number of chars in a word,
* the function returns 0
*********************************/
int getASIblock(int newWord, int ind) {
   /*** replace 131 below with appropriate expression (bitwise and arithmetic operators) ***/
   return newWord >> (ind*BITS_PER_ASI_BLOCK) & ((1 << BITS_PER_ASI_BLOCK) - 1); // Shifts the word to the right to get the correct block and then masks it to get the correct value
}

/*********************************
* Problem 1.4
* function isWordFull
* params:
* newWord (int)
* Return 1 if last ASI block of newWord is used
* and 0 otherwise
*********************************/
int isWordFull(int newWord) {
   /*** replace 141 below with appropriate expression ***/
   return getASIblock(newWord, ((sizeof(newWord)*8)/ BITS_PER_ASI_BLOCK) -1) != 0; // Checks if the last block is used by checking if it is not 0
}

/*********************************
* Problem 1.5
* function newWordType
* params:
* newWord (int)
* Returns a value associated with the word type:
* - 0 for word with only '.'
* - 1 for word made up of letters (and .)
* - 2 for word made up of digits (and .)
* - 3 for word made up of letters and digits
*********************************/
int newWordType(int newWord) {
   int ASIval=0, ind=0, type=ASIval;
   /*** loop until reaching ASI value 0 ***/
   for(ind=0; ind*BITS_PER_ASI_BLOCK<8*sizeof(int); ind++) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
        ASIval = getASIblock(newWord, ind); // Get the ASI value of the block at a given index
        if(ASIval == 0) break;
        else if(ASIval >= 2 && ASIval <= 53) { 
             if(type == 0) type = 1;
             if(type == 2) type = 3;
        } else if(ASIval >= 54 && ASIval <= 63) {
             if(type == 0) type = 2;
             if(type == 1) type = 3;
        }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   } // end of for
   return type;
}

/*********************************
* Problem 1.6
* function appendWordChar
* params:
* newWord (int)
* ch      (char)
* Return the new word obtained by adding the ASI 
* value of char ch to the end of newWord.
* If newWord is full, then return original newWord.
* In the final partial block, only a '.'
* can be appended
*********************************/
int appendWordChar(int newWord, char ch) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
    return (charToASI(ch) == -1) ? newWord : ( //If invalid char, return the original word
           isWordFull(newWord) ?  //If the word is full, return the original word
           ((getASIblock(newWord, ((sizeof(newWord) * 8) / BITS_PER_ASI_BLOCK)) == 0 && ch == '.') ? //If the last block is empty and the char is a '.', add the char to the last block
           (newWord | (charToASI(ch) << (((sizeof(newWord) * 8 / BITS_PER_ASI_BLOCK)) * BITS_PER_ASI_BLOCK))) : //Else, if unable to add the char, return the original word
           newWord) : 
           (newWord | (charToASI(ch) << ( //Else, add the char to the end of the word using a for loop to find the first empty block and then add the char to that block
               ({ int ind = 0; for (ind = 0; ind < 8 * sizeof(int) / BITS_PER_ASI_BLOCK; ind++) if (getASIblock(newWord, ind) == 0) break; ind; }) * BITS_PER_ASI_BLOCK)))
           );
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
}

/*********************************
* Problem 1.7
* function printNewWord
* params:
* newWord (int)
* Prints new word to the screen.
* If last character is '.', prints a newline after it
*********************************/
void printNewWord(int newWord) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   int ASIval = 0, ind = 0;
   int lastNonZeroASI = 0;
   for (ind = 0; ind * BITS_PER_ASI_BLOCK < 8 * sizeof(int); ind++) {
      ASIval = getASIblock(newWord, ind); // Get the ASI value of the block at a given index
      if (ASIval == 0)
            break;
      lastNonZeroASI = ASIval; // Save the last non-zero ASI value
      printf("%c", ASItoChar(ASIval));
   }
   printf("%c", ASItoChar(lastNonZeroASI) == '.' ? '\n' : ' '); // Print a newline if the last character is a '.'
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return;
}

/*** end of file ***/













#include <stdio.h>

/*************************************************
*  newWordParser.c
*  ---------------
*  A program for parsing text in new word format
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Functions implemented in Problem 1
*********************************/
int  charToASI(char ch);
char ASItoChar(int ASIval);
int  getASIblock(int newWord, int ind);
int  isWordFull(int newWord);
int  newWordType(int newWord);
int  appendWordChar(int newWord, char ch);
void printNewWord(int newWord);


/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/
/*********************************
* Problem 2 - main function for program
*********************************/
int main() {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
    int newWord = 0;
    char ch;
    int broken = 0;
    int numWords[4] = {0, 0, 0, 0};
    while (scanf("%c", &ch) == 1) {
        if (ch == '$') {
            broken = 1;
            break;
        }
        if (appendWordChar(newWord, ch) == newWord) {
            printNewWord(newWord);
            numWords[newWordType(newWord)]++;
            if(charToASI(ch) > -1) newWord = charToASI(ch);
            else newWord = 0;
        } else {
            newWord = appendWordChar(newWord, ch);
            // printNewWord(newWord);
        }
    }
    if (!broken) {
        printNewWord(newWord);
    }
    printf("\n");
    numWords[newWordType(newWord)]++;
    printf("Number of words is %d\n", numWords[1]);
    printf("Number of numbers is %d\n", numWords[2]);
    printf("Number of mixed words is %d\n", numWords[3]);
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return 0;
}
/*** end of file ***/