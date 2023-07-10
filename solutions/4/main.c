#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
int  main()
{
    char operation[10];
    scanf("%s", operation);
    char oper = operation[0];
    if (oper == 'T')
    {
        int k, n, m;
        int element, row, column;
        scanf("%d %d %d", &n, &m, &k);
        int k1 = k;
        Node MatrixArray[k];
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d %d", &row, &column, &element);
            MatrixArray[i].Element = element;
            MatrixArray[i].Row = row;
            MatrixArray[i].Column = column;
        }
        PtrNode Transpose = TransposeMatrixArray(MatrixArray, k);
        printf("%d\n", k1);
        PrintMatrix(Transpose);
    }
    else if (oper == 'A')
    {
        PtrNode A = createLinkedList();
        PtrNode B = createLinkedList();
        PtrNode AHead = A;
        PtrNode BHead = B;
        int k1, k2, n, m;
        int element, row, column;
        scanf("%d %d %d %d", &n, &m, &k1, &k2);
        while (k1--)
        {
            scanf("%d %d %d", &row, &column, &element);
            PtrNode TmpCell = malloc(sizeof(Node));
            TmpCell->Element = element;
            TmpCell->Row = row;
            TmpCell->Column = column;
            TmpCell->NextNode = NULL;
            A->NextNode = TmpCell;
            A = A->NextNode;
        }
        while (k2--)
        {
            scanf("%d %d %d", &row, &column, &element);
            PtrNode TmpCell = malloc(sizeof(Node));
            TmpCell->Element = element;
            TmpCell->Row = row;
            TmpCell->Column = column;
            TmpCell->NextNode = NULL;
            B->NextNode = TmpCell;
            B = B->NextNode;
        }
        PtrNode Added = AddMatrix(AHead, BHead);
        printf("%d\n", oper2);
        PrintMatrix(Added);
    }
    else if (oper == 'M')
    {
        PtrNode A = createLinkedList();
        PtrNode AHead = A;
        int k1, k2, n, m, l;
        int element, row, column;
        scanf("%d %d %d %d %d", &n, &m, &l, &k1, &k2);
        while (k1--)
        {
            scanf("%d %d %d", &row, &column, &element);
            PtrNode TmpCell = malloc(sizeof(Node));
            TmpCell->Element = element;
            TmpCell->Row = row;
            TmpCell->Column = column;
            TmpCell->NextNode = NULL;
            A->NextNode = TmpCell;
            A = A->NextNode;
        }
        Node MatrixArray[k2];
        for (int i = 0; i < k2; i++)
        {
            scanf("%d %d %d", &row, &column, &element);
            MatrixArray[i].Element = element;
            MatrixArray[i].Row = row;
            MatrixArray[i].Column = column;
        }
        PtrNode BTrans = TransposeMatrixArray(MatrixArray, k2);
        PtrRow AModified = Convert(AHead);
        PtrRow BModified = Convert(BTrans);
        PtrNode Multiplied = MultiplyMatrix(AModified, BModified);
        printf("%d\n", oper3);
        PrintMatrix(Multiplied);
    }
}