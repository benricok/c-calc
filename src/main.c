#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <debug.h>
#include <util.h>

#define DEBUG_ENABLED 1
#define MAX_BUFF 50

char * newPrompt();

int main() {
  printf("\033[0;33mSuper Simple C Calculator\033[0m");

  //char input[MAX_BUFF], expression[MAX_BUFF] = "";
  int expressLength = 0;
  
  while (true) {

  char *input = newPrompt();
  char *expression = malloc(MAX_BUFF);
   
  // error("Hello", );  
  if (!memcmp(input, "exit", 4) || !memcmp(input, "EXIT", 4)) { 
    printf("Bye!\n");
    return 0; 
  }

  // Check if expression starts with a number
  // if ((int)input[0] == 0 || !(47 < (int)input[0] && (int)input[0] < 58)) {
  //  fprintf(stderr, "\033[0;31mWARNING: Your expression has to start with a number\n\033[0m");
  //  return 1;
  // }

  // Filter expression for only allowed characters and remove spaces
  for (int i = 0; i < MAX_BUFF; i++)
  {
    // Exit on buffer end
    if ((int)input[i] == 0) { break; };

    // Copy characters (, ), *, +, -, ., /, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    if (39 < (int)input[i] && (int)input[i] < 58)
    {
      // Convert , to . for numbers with decimals
      if ((int)input[i] == 44) {
        expression[expressLength] = 46;
      } else {
        expression[expressLength] = input[i];
      }
      expressLength++;
    }
  }

  int curIndex = 0;
  int indexState = 0;
  float valA = 0.0, valB = 0.0;
  enum MathOperator operator;
  
  debug("Filtered Expression","%s", expression);
  debug("Expression Length", "%d", expressLength);

  for (; curIndex < expressLength-1;) {
    debug("Current Index", "%d", curIndex);
    switch (indexState) {
      case 0:
        valA = getfloat(expression, expressLength, &curIndex);
        indexState++;
        break;
      case 1:
        operator = getOperator(expression, &curIndex);
        indexState++;
        break;
      case 2:
        valB = getfloat(expression, expressLength, &curIndex);
        valA = calc(valA, valB, operator);
        indexState++;
        break;
      case 3:
        operator = getOperator(expression, &curIndex);
        indexState = 2;
        break;
      default:
        break;
    }
  }

  printf("\n\033[0;32mResult: %f\033[0m", valA);
  free(input);
  free(expression);
  }
  return 0;
}

char * newPrompt() {
  char *buffer = malloc(MAX_BUFF);
  printf("\n>>> ");
  fgets(buffer, MAX_BUFF, stdin);
  return buffer;
}


