#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int oper2;
int oper3;

void merge(Node *L, int lenL, Node *R, int lenR, Node *A, int len)
{
    int c = 0, l = 0, r = 0;
    while (c < len)
    {
        if (l == lenL)
        {
            A[c].Element = R[r].Element;
            A[c].Row = R[r].Row;
            A[c++].Column = R[r++].Column;
            continue;
        }
        else if (r == lenR)
        {
            A[c].Element = L[l].Element;
            A[c].Row = L[l].Row;
            A[c++].Column = L[l++].Column;
            continue;
        }
        else
        {
            if ((L[l].Row > R[r].Row) || (L[l].Row == R[r].Row && L[l].Column > R[r].Column))
            {
                A[c].Element = R[r].Element;
                A[c].Row = R[r].Row;
                A[c++].Column = R[r++].Column;
            }
            else
            {
                A[c].Element = L[l].Element;
                A[c].Column = L[l].Column;
                A[c++].Row = L[l++].Row;
            }
        }
    }
}

void sort(Node *A, int len)
{
    if (len == 1)
        return;
    else
    {
        int mid = len / 2;
        Node L[mid], R[len - mid];
        for (int i = 0; i < mid; i++)
        {
            L[i].Element = A[i].Element;
            L[i].Row = A[i].Row;
            L[i].Column = A[i].Column;
        }
        for (int i = mid; i < len; i++)
        {
            R[i - mid].Element = A[i].Element;
            R[i - mid].Row = A[i].Row;
            R[i - mid].Column = A[i].Column;
        }
        sort(L, mid);
        sort(R, len - mid);
        merge(L, mid, R, len - mid, A, len);
    }
}
PtrNode createLinkedList()
{
    PtrNode newLinkedList = (PtrNode)malloc(sizeof(Node));
    newLinkedList->Row = -1;
    newLinkedList->Column = -1;
    newLinkedList->Element = 0;
    newLinkedList->NextNode = NULL;
    return newLinkedList;
}
PtrRow createMatrix()
{
    PtrRow newMatrix = (PtrRow)malloc(sizeof(Row));
    newMatrix->RowHead = NULL;
    newMatrix->NextRow = NULL;
    newMatrix->RowCount = -1;
    return newMatrix;
}
PtrPoint createRow()
{
    PtrPoint newList = (PtrPoint)malloc(sizeof(Point));
    newList->Column = -1;
    newList->Element = 0;
    newList->NextNode = NULL;
    return newList;
}
PtrNode TransposeMatrixArray(PtrNode Arr, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = Arr[i].Column;
        Arr[i].Column = Arr[i].Row;
        Arr[i].Row = temp;
    }
    sort(Arr, k);
    PtrNode Transpose = createLinkedList();
    PtrNode HeadTranspose = Transpose;
    for (int i = 0; i < k; i++)
    {
        PtrNode TmpCell = malloc(sizeof(Node));
        TmpCell->Element = Arr[i].Element;
        TmpCell->Row = Arr[i].Row;
        TmpCell->Column = Arr[i].Column;
        TmpCell->NextNode = NULL;
        Transpose->NextNode = TmpCell;
        Transpose = Transpose->NextNode;
    }
    return HeadTranspose;
}
PtrNode TransposeMatrix(PtrNode Head)
{
    int flag = 0;
    PtrNode Transpose = createLinkedList();
    PtrNode HeadTranspose = Transpose;
    while (Head->NextNode != NULL)
    {
        flag = 0;
        Head = Head->NextNode;
        PtrNode TmpCell = malloc(sizeof(Node));
        TmpCell->Element = Head->Element;
        TmpCell->Row = Head->Column;
        TmpCell->Column = Head->Row;
        TmpCell->NextNode = NULL;
        while (Transpose->NextNode != NULL)
        {
            if (Transpose->NextNode->Row > TmpCell->Row ||
                (Transpose->NextNode->Row == TmpCell->Row && Transpose->NextNode->Column > TmpCell->Column))
            {
                PtrNode TempNext = Transpose->NextNode;
                Transpose->NextNode = TmpCell;
                TmpCell->NextNode = TempNext;
                flag = 1;
                break;
            }
            Transpose = Transpose->NextNode;
        }
        if (flag == 0)
            Transpose->NextNode = TmpCell;
        Transpose = HeadTranspose;
    }
    return HeadTranspose;
}
int CountLLL(PtrNode A)
{
    int count = 0;
    while (A != NULL)
    {
        A = A->NextNode;
        count++;
    }
    return count;
}
PtrNode AddMatrix(PtrNode A, PtrNode B)
{
    int p = 0;
    int Sum;
    int flag = 0;
    PtrNode C = createLinkedList();
    PtrNode CHead = C;

    if (A->NextNode == NULL && B->NextNode == NULL)
        return C;
    else if (A->NextNode == NULL)
        return B;
    else if (B->NextNode == NULL)
        return A;
    while (A != NULL && B != NULL)
    {
        if (flag == 0)
        {
            A = A->NextNode;
            B = B->NextNode;
            flag = 1;
        }

        if (A->Row < B->Row || (A->Row == B->Row && A->Column < B->Column))
        {
            ++p;
            PtrNode TmpCell = malloc(sizeof(Node));
            TmpCell->Element = A->Element;
            TmpCell->Row = A->Row;
            TmpCell->Column = A->Column;
            TmpCell->NextNode = NULL;
            C->NextNode = TmpCell;
            C = C->NextNode;
            A = A->NextNode;
        }
        else if (A->Row > B->Row || (A->Row == B->Row && A->Column > B->Column))
        {
            ++p;
            PtrNode TmpCell = malloc(sizeof(Node));
            TmpCell->Element = B->Element;
            TmpCell->Row = B->Row;
            TmpCell->Column = B->Column;
            TmpCell->NextNode = NULL;
            C->NextNode = TmpCell;
            C = C->NextNode;
            B = B->NextNode;
        }
        else
        {
            Sum = A->Element + B->Element;
            if (Sum)
            {
                ++p;
                PtrNode TmpCell = malloc(sizeof(Node));
                TmpCell->Element = Sum;
                TmpCell->Row = B->Row;
                TmpCell->Column = B->Column;
                TmpCell->NextNode = NULL;
                C->NextNode = TmpCell;
                C = C->NextNode;
            }
            A = A->NextNode;
            B = B->NextNode;
        }
    }
    int count = 0;
    if (A != NULL)
    {
        C->NextNode = A;
        count = CountLLL(A);
    }
    else if (B != NULL)
    {
        C->NextNode = B;
        count = CountLLL(B);
    }
    oper2 = p + count;

    return CHead;
}
PtrRow Convert(PtrNode A)
{
    int flag = 0, flag1 = 0;
    PtrRow C = createMatrix();
    PtrRow CHead = C;
    int CurrRowCount;
    while (A != NULL)
    {
        if (flag == 0)
        {
            A = A->NextNode;
            flag = 1;
        }
        CurrRowCount = A->Row;
        PtrPoint NewNode = createRow();
        PtrPoint NewHead = NewNode;
        while (A->Row == CurrRowCount)
        {
            PtrPoint TmpCell = malloc(sizeof(Point));
            TmpCell->Element = A->Element;
            TmpCell->Column = A->Column;
            TmpCell->NextNode = NULL;
            NewNode->NextNode = TmpCell;
            NewNode = NewNode->NextNode;
            if (A->NextNode != NULL)
                A = A->NextNode;
            else
            {
                flag1 = 1;
                break;
            }
        }
        PtrRow TmpRow = malloc(sizeof(Row));
        TmpRow->RowCount = CurrRowCount;
        TmpRow->RowHead = NewHead;
        TmpRow->NextRow = NULL;
        C->NextRow = TmpRow;
        C = C->NextRow;
        if (flag1 == 1)
            break;
    }
    return (CHead);
}
void PrintMatrix(PtrNode Curr)
{
    while (Curr->NextNode != NULL)
    {
        Curr = Curr->NextNode;
        printf("%d %d %d", Curr->Row, Curr->Column, Curr->Element);
        printf("\n");
    }
}
PtrNode MultiplyMatrix(PtrRow A, PtrRow B)
{
    PtrNode C = createLinkedList();
    PtrNode CHead = C;
    int TempSum;
    PtrRow BHead = B;
    while (A->NextRow != NULL)
    {
        A = A->NextRow;
        PtrPoint ARowHead = A->RowHead;
        PtrPoint ARow = ARowHead;
        while (B->NextRow != NULL)
        {
            ARow = ARowHead;
            B = B->NextRow;
            TempSum = 0;
            PtrPoint BRowHead = B->RowHead;
            PtrPoint BRow = BRowHead;
            ARow = ARow->NextNode;
            BRow = BRow->NextNode;
            while (BRow != NULL && ARow != NULL)
            {

                if (ARow->Column > BRow->Column)
                {
                    if (BRow->NextNode == NULL)
                        break;
                    BRow = BRow->NextNode;
                }
                else if (ARow->Column < BRow->Column)
                {
                    if (ARow->NextNode == NULL)
                        break;
                    ARow = ARow->NextNode;
                }
                else
                {
                    TempSum += ARow->Element * BRow->Element;
                    ARow = ARow->NextNode;
                    BRow = BRow->NextNode;
                }
            }
            if (TempSum)
            {
                PtrNode TmpCell = malloc(sizeof(Node));
                TmpCell->Element = TempSum;
                TmpCell->Row = A->RowCount;
                TmpCell->Column = B->RowCount;
                TmpCell->NextNode = NULL;
                C->NextNode = TmpCell;
                C = C->NextNode;
                oper3++;
            }
        }
        B = BHead;
    }
    return CHead;
}
