#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int oper3;
void reverseString(char *str, int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int *uniqueElements(int *arr, int length)
{
    int check[10001]={0};
    int c = 0;
    int arr2[length];
    for (int i = 0; i < length; i++)
    {
        if (check[arr[i]] == 0)
        {
            arr2[c++] = arr[i];
            check[arr[i]] = 1;
        }
    }
    oper3=c;
    int *unique = (int *)malloc(c * sizeof(int));
    for (int i = 0; i < c; i++)
        unique[i] = arr2[i];
    return unique;
}

char *compressString(char *str, int length)
{
    int char_count = 0;
    char *str_compressed = (char *)malloc((2 * length + 1) * sizeof(char));
    str_compressed[0] = '\0';
    for (int i = 0; i < length; i++)
    {
        char present = str[i];
        char next = str[i + 1];
        char_count = 1;
        while (present == next)
        {
            char_count++;
            i++;
            present = str[i];
            next = str[i + 1];
        }
        sprintf(str_compressed, "%s%c%d", str_compressed, present, char_count);
    }
    return (str_compressed);
}
int **transpose(int **matrix, int NumRow, int NumCol)
{
    int **matrix_transposed = (int **)malloc(NumCol * sizeof(int *));
    for (int i = 0; i < NumCol; i++)
        matrix_transposed[i] = (int *)malloc(NumRow * sizeof(int));
    for (int i = 0; i < NumRow; i++)
    {
        for (int j = 0; j < NumCol; j++)
        {
            matrix_transposed[j][i] = matrix[i][j];
        }
    }
    return (matrix_transposed);
}