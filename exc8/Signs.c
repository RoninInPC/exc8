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
OperationType* POLYMTOARR_FUNCTION(Polym* One, int* Size) {
    *Size = One->Power + 1;
    OperationType* Ans = malloc((*Size) * sizeof(OperationType));
    while (One != NULL) {
        Ans[One->Power] = One->Coef;
        One = One->next;
    }
    return Ans;
}
Polym* DELETEFREEZEROINPOLYM_FUNCTION(Polym* One) {
    int Size;
    OperationType* Ans = POLYMTOARR_FUNCTION(One, &Size);
    int j = 0;
    for (int i = Size-1; i >=1 ; i--) {
        if (Ans[i] == 0) {
            j++;
        }
        else break;
    }
    Size -= j;
    OperationType* Ans2 = malloc(Size * sizeof(OperationType));
    for (int i = 0; i < Size; i++) {
        Ans2[i] = Ans[i];
    }
    return INIC_FUNCTION(Ans2, Size);
}
Polym* SUMPOLYM_FUNCTION(Polym* One, Polym* Two) {
    int Size;
    OperationType* Arr = POLYMTOARR_FUNCTION(One, &Size);
    int Size2;
    OperationType* Arr2 = POLYMTOARR_FUNCTION(Two, &Size2);
    if (Size2 > Size) {
        return SUMPOLYM_FUNCTION(Two, One);
    }
    for (int i = 0; i < Size2; i++) {
        Arr[i] = ADD_FUNCTION(Arr[i], Arr2[i]);
    }
    return DELETEFREEZEROINPOLYM_FUNCTION(INIC_FUNCTION(Arr, Size));
}
void SUMPOLYMUP_FUNCTION(Polym** One, Polym* Two) {
    *One = SUMPOLYM_FUNCTION(*One, Two);
}
Polym* MINESPOLYM_FUNCTION(Polym* One, Polym* Two) {
    int Size;
    OperationType* Arr = POLYMTOARR_FUNCTION(One, &Size);
    int Size2;
    OperationType* Arr2 = POLYMTOARR_FUNCTION(Two, &Size2);
    if (Size2 > Size) {
        return MINESPOLYM_FUNCTION(Two, One);
    }
    for (int i = 0; i < Size2; i++) {
        Arr[i] = MINES_FUNCTION(Arr[i], Arr2[i]);
    }
    return DELETEFREEZEROINPOLYM_FUNCTION(INIC_FUNCTION(Arr, Size));
}
void MINESPOLYMUP_FUNCTION(Polym** One, Polym* Two) {
    *One = MINESPOLYM_FUNCTION(*One, Two);
}
Polym* PRPOLYM_FUNCTION(Polym* One, Polym* Two) {
    int Size;
    OperationType* Arr = POLYMTOARR_FUNCTION(One, &Size);
    int Size2;
    OperationType* Arr2 = POLYMTOARR_FUNCTION(Two, &Size2);
    int Size3 = (Size-1) + (Size2-1)+1;
    OperationType* Arr3 = malloc(Size3 * sizeof(OperationType));
    for (int i = 0; i < Size3; i++) {
        Arr3[i] = 0;
    }
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size2; j++) {
            Arr3[i + j] += Arr[i] * Arr2[j];
        }
    }
    return DELETEFREEZEROINPOLYM_FUNCTION(INIC_FUNCTION(Arr3, Size3));
}
void PRPOLYMUP_FUNCTION(Polym** One, Polym* Two) {
    One = PRPOLYM_FUNCTION(*One, Two);
}
Polym* DELPOLYM_FUNCTION(Polym* One, Polym* Two) {
    int Size;
    OperationType* Arr = POLYMTOARR_FUNCTION(One, &Size);
    int Size2;
    OperationType* Arr2 = POLYMTOARR_FUNCTION(Two, &Size2);
    if (Size2 > Size) {
        Polym* Ans = malloc(sizeof(Polym));
        Ans->Coef = 0;
        Ans->head = Ans;
        Ans->next = NULL;
        Ans->Power = 0;
        return Ans;
    }
    int Size3 = Size - Size2 + 1;
    int CopySize3 = Size3;
    OperationType* Arr3 = malloc(Size3 * sizeof(OperationType));
    for (int i = 0; i < Size3; i++) {
        Arr3[i] = 0;
    }
    while (Size >= Size2) {
        int CopySize2 = Size2;
  //      for (int i = 0; i < Size; i++) {
  //          Out(Arr[i]);
  //          printf(" ");
  //      }
    //    printf("\n");
        Arr3[Size3 - 1] = Arr[Size - 1] / Arr2[Size2 - 1];
        for (int i = Size - 1; i >= Size - 3; i--) {
            Arr[i] -= Arr2[CopySize2 - 1] * Arr3[Size3 - 1];
 //           Out(Arr[i]);
    //        printf(" ");
            CopySize2--;
        }
 //       printf("\n");
        Size--;
        Size3--;
    }
    
    return DELETEFREEZEROINPOLYM_FUNCTION(INIC_FUNCTION(Arr3, CopySize3));
}
void DELPOLYMUP_FUNCTION(Polym** One, Polym* Two) {
    *One = DELPOLYM_FUNCTION(*One, Two);
}
Polym* REMAINSPOLYM_FUNCTION(Polym* One, Polym* Two) {
    Polym* Del = DELPOLYM_FUNCTION(One, Two);
    Polym* Pr = PRPOLYM_FUNCTION(Two, Del);
    Polym* Mines = MINESPOLYM_FUNCTION(One, Pr);
    return MINESPOLYM_FUNCTION(One, PRPOLYM_FUNCTION(Two, DELPOLYM_FUNCTION(One, Two)));
}
void REMAINSPOLYMUP_FUNCTION(Polym** One, Polym* Two) {
    *One = REMAINSPOLYM_FUNCTION(*One, Two);
}
Polym* NODPOLYM_FUNCTION(Polym* One, Polym* Two) {
   // printf(" ");
   // PRINTPOLYM_FUNCTION(One);
   // printf(" ");
   // PRINTPOLYM_FUNCTION(Two);
    Polym* Remain= REMAINSPOLYM_FUNCTION(One, Two);
    if (Remain->Coef != 0 && Remain->Power == 0) {
        Polym* Ans = malloc(sizeof(Polym));
        Ans->Coef = 1;
        Ans->head = Ans;
        Ans->next = NULL;
        Ans->Power = 0;
        return Ans;
    }
    if (Remain->Coef == 0 && Remain->Power == 0) {
        return Two;
    }
    else
        return NODPOLYM_FUNCTION(Two, Remain);
}
OperationType VALUEINPOLYM_FUNCTION(Polym* One, OperationType Value) {
    OperationType Ans = 0;
    while (One != NULL) {
        Ans += One->Coef * POWER(Value, One->Power);
        One = One->next;
    }
    return Ans;
}