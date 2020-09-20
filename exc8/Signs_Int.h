#ifndef H_SIGNS_INT
#define H_SIGNS_INT
int AddInt(int a, int b);
int MinesInt(int a, int b);
int PrInt(int a, int b);
int DelInt(int a, int b);
void OutInt(int a);
#pragma warning(push)
#pragma warning(disable : 4005)
#define OperationType int
#define Polynoms IntPolym
#define Polym IntPolym
#pragma warning(pop)
#include"Signs.h"
typedef struct IntPolym IntPolym;
IntPolym* InicIntPolym(int* Arr, int Size);
void PrintIntPolym(IntPolym* One);
#endif