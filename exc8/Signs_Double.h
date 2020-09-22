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
void  PrintDoublePolym(DoublePolym* One);
double* DoublePolymToDoubleArr(DoublePolym* One, int* Size);
DoublePolym* DeleteFreeZeroInDoublePolym(DoublePolym* One);
DoublePolym* SumDoublePolym(DoublePolym* One, DoublePolym* Two);
void SumUpDoublePolym(DoublePolym** One, DoublePolym* Two);
DoublePolym* MinesDoublePolym(DoublePolym* One, DoublePolym* Two);
void MinesUpDoublePolym(DoublePolym** One, DoublePolym* Two);
DoublePolym* PrDoublePolym(DoublePolym* One, DoublePolym* Two);
void PrUpDoublePolym(DoublePolym** One, DoublePolym* Two);
DoublePolym* DelDoublePolym(DoublePolym* One, DoublePolym* Two);
void DelUpDoublePolym(DoublePolym** One, DoublePolym* Two);
DoublePolym* RemainDoublePolym(DoublePolym* One, DoublePolym* Two);
void RemainUpDoublePolym(DoublePolym** One, DoublePolym* Two);
DoublePolym* NodDoublePolym(DoublePolym* One, DoublePolym* Two);
double ValueInDoublePolym(DoublePolym* One, double Value);
#endif