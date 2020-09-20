#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Signs.h"
OperationType ADD_FUNCTION(OperationType a, OperationType b) {
    return a + b;
}
OperationType MINES_FUNCTION(OperationType a, OperationType b) {
    return a - b;
}
OperationType PR_FUNCTION(OperationType a, OperationType b) {
    return a * b;
}
OperationType DEL_FUNCTION(OperationType a, OperationType b) {
    return a / b;
}
void OUTPUT_FUNCTION(OperationType a) {
    Out(a);
}
Polym* INIC_FUNCTION(OperationType* Arr, int Size) {//конструктор *Polym
    Polym* Ans = malloc(sizeof(Polym));
    Polym* Head = Ans;
    for (int i = Size - 1; i >= 0; i--) {
        Ans->Power = i;
        Ans->Coef = Arr[i];
        Ans->head = Head;
        if (i != 0) {
            Ans->next = malloc(sizeof(Polym));
            Ans = Ans->next;
        }
        else
            Ans->next = NULL;
    }
    Ans = Ans->head;
    return Ans;
}
void PRINTPOLYM_FUNCTION(Polym* One) {
    while (One != NULL) {
        printf("(");
        Out(One->Coef);
        if (One->Power > 0) {
            printf("*x^%d)+", One->Power);
        }
        else
        {
            printf(")\n");
        }
        One = One->next;
    }
}