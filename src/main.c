#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <debug.h>
#include <wchar.h>

#define DEBUG_ENABLED 1
#define MAX_PROMPT_LENGTH 100

char * newPrompt(int promptLength);

int main(/*int argc, char *argv[]*/)
{
  printf("\033[0;33mSuper Simple C Calculator\033[0m");

  while (true) {
    char *prompt = newPrompt(MAX_PROMPT_LENGTH);
    warning("TEST", );
    if(!memcmp(prompt, "EXIT", 4)) {
      printf("bye!\n");
      return EXIT_SUCCESS;
    }

    debug("Prompt", "%s", prompt);
    debug("Prompt length", "%lu", strlen(prompt));
    free(prompt);
  }
  return EXIT_SUCCESS;
}

char * newPrompt(int promptLength) {
  int buffIdx = -1;
  char * prompt = (char*) malloc(promptLength);
  char * buff = (char*) malloc(promptLength);
  printf("\n>>> ");
  fgets(prompt, promptLength, stdin);

  for (int i = 0; i < MAX_PROMPT_LENGTH; i++) {
    // Filter chars: A-Z a-z ( ) * + , - . / ^
    int c = (int)prompt[i];
    if ((40 <= c && c <= 57) 
    || ( 65 <= c && c <= 90)
    || ( 97 <= c && c <= 122)
    || (c == 94)) {
      buffIdx++;
      buff[buffIdx] = toupper(c);
    }
  }

  char * filtered = (char*) malloc(buffIdx+1);
  memcpy(filtered, buff, buffIdx + 1);
  free(prompt);
  free(buff);
  return filtered;
}
