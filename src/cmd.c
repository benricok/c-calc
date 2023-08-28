#include "cmd.h"

static void cmd_help(void * data) {
    printf("help called");
}

static void cmd_exit(void *data) {
    printf("bye!\n");
    exit(0);
}

struct cmd commands[] = {
    {
        4,
        "exit",
        cmd_exit,
    }, {
        4,
        "help",
        cmd_help,
    }
};

void checkForCmd(char *prompt, int length) {
    size_t size = sizeof(commands) / sizeof(commands[0]);
    
    for (int i = 0;  i < size; i++) {
        if (length >= commands[i].nameLen) {
            if (!memcmp(prompt, commands[i].name, commands[i].nameLen)) {
                commands[i].cmd(0);
            }     
        }
    } 
}
