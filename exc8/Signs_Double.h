#ifndef H_SIGNS_DOUBLE
#define H_SIGNS_DOUBLE
double AddDouble(double a, double b);
double MinesDouble(double a, double b);
double PrDouble(double a, double b);
double DelDouble(double a, double b);
void OutDouble(double a);
#pragma warning(push)
#pragma warning(disable : 4005)
#define OperationType double
#define Polynoms DoublePolym
#define Polym DoublePolym
#pragma warning(pop)
#include"Signs.h"
typedef struct DoublePolym DoublePolym;
DoublePolym* InicDoublePolym(double* Arr, int Size);
void PrintDoublePolym(DoublePolym* One);
#endif