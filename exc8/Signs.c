#pragma once
#include<stdio.h>
#include<stdlib.h>
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