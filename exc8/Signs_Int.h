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
int* IntPolymToIntArr(IntPolym* One, int* Size);
IntPolym* DeleteFreeZeroInIntPolym(IntPolym* One);
IntPolym* SumIntPolym(IntPolym* One, IntPolym* Two);
void SumUpIntPolym(IntPolym** One, IntPolym* Two);
IntPolym* MinesIntPolym(IntPolym* One, IntPolym* Two);
void MinesUpIntPolym(IntPolym** One, IntPolym* Two);
IntPolym* PrIntPolym(IntPolym* One, IntPolym* Two);
void PrUpIntPolym(IntPolym** One, IntPolym* Two);
IntPolym* DelIntPolym(IntPolym* One, IntPolym* Two);
void DelUpIntPolym(IntPolym** One, IntPolym* Two);
IntPolym* RemainIntPolym(IntPolym* One, IntPolym* Two);
void RemainUpIntPolym(IntPolym** One, IntPolym* Two);
IntPolym* NodIntPolym(IntPolym* One, IntPolym* Two);
int ValueInIntPolym(IntPolym* One, int Value);
#endif