#include "debug.h"
#include <stdio.h>

void expressionErr(char *message, char *buff, int pos, int max) {
    char * idx = (char *) malloc(max);
    for (int i = 0; i < max; i++) {
        idx[i] = 32;
    }
    
    idx[pos] =  94;
    fprintf(stdout, "\033[0;1;33m\nWARNING: Error parsing at index %d:\033[0m", pos + 1);
    fprintf(stdout, "\n%s",buff);
    fprintf(stdout, "\n\033[0;33m%s", idx);
    fprintf(stdout, "\n%s\033[0m\n\n", message);
    free(idx);
}
