#include <stdio.h>
#include<stdlib.h>
#include "Signs_Int.h"
#include"Signs_Double.h"
int main() {
	OutInt(AddInt(10, 20));
	OutDouble(AddDouble(0.1, 0.2));
	int IntArr[3] = {1, 2, 1};
	double DoubleArr[3] = { 1.1,1.21,1.1 };
	IntPolym* Arr = InicIntPolym(IntArr,3);
	DoublePolym* Arr2 = InicDoublePolym(DoubleArr,3);	
	PrintIntPolym(Arr);
	PrintDoublePolym(Arr2);
}