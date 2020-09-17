#pragma once
struct Polynoms {
    OperationType Coef;
    int Power;
    struct Polynoms* head;
    struct Polynoms* next;
};