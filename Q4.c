/*!*************************************************************************
****
\file Q4.c
\author Elson Tan Jun Hao
\par email: 2102036@sit.singaporetech.edu.sg
\par Course: RSE2203 - Data Structures and Algorithms
\date 26-09-2022
\brief
This file contains the algorithm to check user's input sentence is palindromes.
****************************************************************************
***/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/***************************************************************************/
/*!
\brief
This function tracks and compare the start point with the end point of the 
sentence. Then recursively calls back function until both start and end point meets.

\param strt
Initialize with the starting point of the sentence

\param end
Initialize with the ending point of the sentence
*/
/**************************************************************************/
bool RecurPalindrome(const unsigned char* strt, const unsigned char* end) {
///////////////Check the strt and end variable via recursion///////////////
  //printf("strt = %c, end = %c\n", *strt,*end);
///////////////////////////////////////////////////////////////////////////
  if (strt >= end) return true;
  if (*strt < 'A' || (*strt > 'Z' && *strt < 'a') || *strt > 'z') return RecurPalindrome(strt + 1, end);
  if (*end < 'A' || (*end > 'Z' && *end < 'a') || *end > 'z') return RecurPalindrome(strt, end - 1);

  return (*strt ^ *end | 32) == 32 && RecurPalindrome(strt + 1, end - 1);
}

int main() {
  unsigned char str[255] = "";
  printf("Enter string:\n");
  fgets(str, 255, stdin);
///////////////Check Input Sentence and Length of Sentence///////////////
  //int length = strlen(str) - 1;
  //printf("Input String: %sNumber of Alphabets: %i\n", str, length);
/////////////////////////////////////////////////////////////////////////
  RecurPalindrome(str, str + strlen(str) - 2) ? printf("palindrome: True\n") : printf("palindrome: False\n");

  return 0;
}
