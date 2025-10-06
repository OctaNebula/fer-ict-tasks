#include <stdio.h>
#include <stdarg.h>

int Printf(const char *format, ...) { // vibecoded printf but worse for testing purposes lol
    va_list args;
    int result;
    va_start(args, format);
    result = vprintf(format, args);
    va_end(args);
    return result;
}

int main () {
    Printf("hi");
    return 0;
}