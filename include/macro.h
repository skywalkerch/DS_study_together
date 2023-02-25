#pragma once
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;
#ifdef _WIN32
#include <cstdlib>
void SetEncoding() {
	system("chcp 65001");
}
#else
void SetEncoding()
#endif
