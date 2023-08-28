#include <inttypes.h>
#include <stddef.h>
#include <string.h>
#include <tokeniser.h>

// Takes in a string format
//  - {a-z}(...)
//  - (...)
//  - ...
float parseValFromStr(char *str, int length) {
  char * buff = (char *) malloc(length);
  bool isFloat = false;
  float f = 0.0;
  int d = 0, j = 0;

  for (int i = 0; i < length; i++)
  {
    // Copy number characters to value str
    if (47 < (int)str[i] && (int)str[i] < 58) {
      buff[j] = str[i];
      ++j;

    } else if (str[i] == '.' && !isFloat) {
      isFloat = true;
      buff[j] = str[i];
      ++j;

    } else if (str[i] == '.' && isFloat) {
      ++j;

    } else {
      break;
    }
  }

  debug("buff arr value", "%s", buff);
  (isFloat) ? sscanf(buff, "%f", &f) : sscanf(buff, "%d", &d);
  free(buff);
  return f + d;
}

//typedef void (*command_handler)(void *);
//command_handler command_handlers[] = { exit, help };

// enum registeredCommands {
//     exit,
//     help,
// }




