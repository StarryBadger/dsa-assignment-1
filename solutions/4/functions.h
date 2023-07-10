#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
extern int oper2;
extern int oper3;
typedef struct Point *PtrPoint;
typedef struct Row *PtrRow;
typedef struct Point
{
    int Element;
    int Column;
    PtrPoint NextNode;
} Point;

typedef struct Row
{
    PtrPoint RowHead;
    PtrRow NextRow;
    int RowCount;
} Row;

typedef struct Node *PtrNode;
typedef struct Node
{
    int Element;
    int Row;
    int Column;
    PtrNode NextNode;
} Node;
void merge(Node *L, int lenL, Node *R, int lenR, Node *A, int len);
void sort(Node *A, int len);
PtrNode TransposeMatrixArray(PtrNode Arr, int k);
PtrNode TransposeMatrix(PtrNode Head);
void PrintMatrix(PtrNode);
PtrNode createLinkedList();
PtrRow createMatrix();
PtrPoint createRow();
PtrNode AddMatrix(PtrNode A, PtrNode B);
int CountLLL(PtrNode A);
PtrRow Convert(PtrNode);
PtrNode MultiplyMatrix(PtrRow A, PtrRow B);
#endif