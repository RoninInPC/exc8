#include <stdio.h>
#include<stdlib.h>
#include "Signs_Int.h"
#include"Signs_Double.h"
int main() {
	int IntArr2[2] = { 3,1 };
	IntPolym* Arr11 = InicIntPolym(IntArr2, 2);
	PrintIntPolym(Arr11);
	int IntArr[2] = {2, 1};
	IntPolym* Arr = InicIntPolym(IntArr,2);
	PrintIntPolym(Arr);
	IntPolym* Arr3 = SumIntPolym(Arr11, Arr);
	PrintIntPolym(Arr3);
	IntPolym* Arr4 = MinesIntPolym(Arr11, Arr);
	PrintIntPolym(Arr4);
	IntPolym* Arr2 = PrIntPolym(Arr, Arr11);
	PrintIntPolym(Arr2);
	IntPolym* Arr5 = DelIntPolym(Arr11, Arr);
	PrintIntPolym(Arr5);
	IntPolym* Arr6 = NodIntPolym(Arr11, Arr);
	PrintIntPolym(Arr6);
	printf("%d\n", ValueInIntPolym(Arr11, 2));

	double DoubleArr1[3] = { 6.0,5.0,1.0 };
	DoublePolym* DA = InicDoublePolym(DoubleArr1, 3);
	PrintDoublePolym(DA);
	double DoubleArr2[2] = { 3.0,1.0 };
	DoublePolym* DA2 = InicDoublePolym(DoubleArr2, 2);
	PrintDoublePolym(DA2);
	PrintDoublePolym(SumDoublePolym(DA, DA2));
	PrintDoublePolym(MinesDoublePolym(DA, DA2));
	PrintDoublePolym(PrDoublePolym(DA, DA2));
	PrintDoublePolym(DelDoublePolym(DA, DA2));
	PrintDoublePolym(NodDoublePolym(DA, DA2));
	printf("%f\n", ValueInDoublePolym(DA, 2.0));
}