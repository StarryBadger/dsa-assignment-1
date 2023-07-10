#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void Insert(PtrNode Head, int num)
{
    PtrNode TmpCell = malloc(sizeof(Node));
    TmpCell->Element = num;
    if (Head->NextNode == Head)
    {
        TmpCell->NextNode = Head;
        Head->NextNode = TmpCell;
    }
    else
    {
        PtrNode Temp = Head->NextNode;
        Head->NextNode = TmpCell;
        TmpCell->NextNode = Temp;
    }
}
PtrNode Find(PtrNode Head, int num)
{
    int flag = 0;
    PtrNode Prev=Head;
    PtrNode Curr = Head->NextNode;
    while (Curr->Element != num)
    {
        Prev = Curr;
        Curr = Curr->NextNode;
        if (Curr == Head)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return NULL;
    Prev->NextNode = Curr->NextNode;
    PtrNode Temp = Head->NextNode;
    Head->NextNode = Curr;
    Curr->NextNode = Temp;
    PtrNode TmpCell = malloc(sizeof(Node));
    TmpCell = Curr;
    return TmpCell;
}
void Print(PtrNode Head)
{
    PtrNode Curr = Head;
    while (Curr->NextNode != Head)
    {
        Curr = Curr->NextNode;
        printf("%d ", Curr->Element);
    }
    printf("\n");
}