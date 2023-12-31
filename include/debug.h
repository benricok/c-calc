#include <stdio.h>
#include <stdlib.h>

#define DEBUG_ENABLED 1

#define debug(name, fmt, ...) \
    do { \
        if (DEBUG_ENABLED) { \
            fprintf(stderr, "\033[0;34m DEBUG %s[%d] %s() - " name ": " fmt "\n\033[0m", \
                __FILE__, \
                __LINE__, \
                __func__, \
                ##__VA_ARGS__); }; \
    } while (0)

#define error(name, fmt, ...) \
    do { \
        fprintf(stderr, "\033[0;1;31m ERROR\033[0;1;30m %s[%d] %s() - " name ": " fmt "\n\033[0m", \
            __FILE__, \
            __LINE__, \
            __func__, \
            ##__VA_ARGS__); \
    } while (0)

#define warning(message, fmt, ...) \
    do { \
        fprintf(stderr, "\033[0;1;33m WARNING: " message ": " fmt "\n\033[0m", \
            __FILE__, \
            __LINE__, \
            __func__, \
            ##__VA_ARGS__); \
    } while (0)

void expressionErr(char *message, char *buff, int pos, int max);

