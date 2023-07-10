#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    PtrNode Head = malloc(sizeof(Node));
    Head->Element = 0;
    Head->NextNode = Head;
    int t;
    scanf("%d", &t);
    char operation_str[10];
    int operation;
    while (t--)
    {
        scanf("%s", operation_str);
        operation = operation_str[4] - '0';
        if (operation == 1)
        {
            int n;
            scanf("%d", &n);
            Insert(Head, n);
        }
        if (operation == 2)
        {
            int n;
            scanf("%d", &n);
            PtrNode SearchedNode = Find(Head, n);
        }
        if (operation == 3)
        {
            Print(Head);
        }
    }
}