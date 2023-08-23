#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


// Takes in a string format
//  - {a-z}(...)
//  - (...)
//  - ...
float getfloat(char *buff, int size) {
  char * val = (char *) malloc(size) ;
  bool isFloat = false;
  float f = 0.0;
  int d = 0, j = 0;

  for (int i = 0; i < size; i++)
  {
    // Copy number characters to value arr
    if (47 < (int)arr[i] && (int)arr[i] < 58) {
      val[j] = arr[i];
      ++j;

    } else if (arr[i] == '.' && !isFloat) {
      isFloat = true;
      val[j] = arr[i];
      ++j;

    } else if (arr[i] == '.' && isFloat) {
      ++j;

    } else {
      *ptr = i;
      break;
    }
  }

  debug("val arr value", "%s", val);
  (isFloat) ? sscanf(val, "%f", &f) : sscanf(val, "%d", &d);
  free(val);
  return f + d;
}
