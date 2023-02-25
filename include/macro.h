#pragma once
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
#define TRUE 1
#define FALSE 0
typedef int Status;
#ifdef _WIN32

#include <cstdlib>

void SetEncoding() {
    system("chcp 65001");
}

#else
void SetEncoding()
#endif
