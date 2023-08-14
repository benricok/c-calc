#define debug(name, fmt, ...) \
  do { \
    if (DEBUG_ENABLED) { \
      fprintf(stderr, "\033[0;34m DEBUG %s[%d] %s() - " name ": " fmt "\n\033[0m", \
              __FILE__, \
              __LINE__, \
              __func__, \
              ##__VA_ARGS__); }; \
  } while (0)


