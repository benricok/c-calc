#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <inttypes.h>

typedef void (*cmd_handler)(void *);

struct cmd {
    int nameLen;
    char * name;
    cmd_handler cmd;
};

static void cmd_help(void * data);
static void cmd_exit(void * data);

void checkForCmd(char *prompt, int length);


