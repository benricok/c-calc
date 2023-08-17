#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <debug.h>
#include <util.h>

float getfloat(char *arr, int size, int *ptr);
enum MathOperator getOperator(char *arr, int *ptr);
float calc(float a, float b, enum MathOperator OPERATOR);

enum MathFunc getFunc(char *arr, int *ptr); 

// Convert char array of float or integer type to float
// Note: ignores multiple decimal indicators '.'
float getfloat(char *arr, int size, int *ptr) {
  char buf[MAX_BUFF] = "";
  bool isFloat = false;
  float f = 0.0;
  int d = 0, j = 0;

  for (int i = *ptr; i < size; ++i)
  {
    if (i == size-1) { *ptr = i; };                // FIX

    // Copy number characters to buffer
    if (47 < (int)arr[i] && (int)arr[i] < 58) {
      buf[j] = arr[i];
      ++j;

    } else if (arr[i] == '.' && !isFloat) {
      isFloat = true;
      buf[j] = arr[i];
      ++j;

    } else if (arr[i] == '.' && isFloat) {
      ++j;

    } else {
      *ptr = i;
      break;
    }
  }

  debug("Buf value", "%s", buf);
  (isFloat) ? sscanf(buf, "%f", &f) : sscanf(buf, "%d", &d);
  return f + d;
}

enum MathFunc getFunc(char *arr, int *ptr) {
  debug("MathFunc start char: ", "%c", arr[*ptr]);
  int itr = *ptr;
  char token[] = "";

  for (int itr = *ptr; itr < MAX_BUFF; itr++) {

  
  }

}

enum MathOperator getOperator(char *arr, int *ptr) {
  debug("Operator", "%c", arr[*ptr]);
  int i = *ptr;
  *ptr = *ptr + 1;
  switch(arr[i]) {
    case '*':
      return MULTIPLY;
    case '/':
      return DEVIDE;
    case '+':
      return PLUS;
    case '-':
      return MINUS;
    default:
      return NONE;
  }
}

float calc(float a, float b, enum MathOperator OPERATOR) {
  switch (OPERATOR) {
    case MULTIPLY:
      return a * b;
    case DEVIDE:
      return a / b;
    case PLUS:
      return a + b;
    case MINUS:
      return a - b;
    default:
      if (a != 0) { return a; } else { return 0.0; };
      break;
  }
}

