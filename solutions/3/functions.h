#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
typedef struct Node *PtrNode;
typedef struct Node
{
    int Element;
    PtrNode NextNode;
} Node;

void Insert(PtrNode Head, int num);
PtrNode Find(PtrNode Head, int num);
void Print(PtrNode Head);
#endif
