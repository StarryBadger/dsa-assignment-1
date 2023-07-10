#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
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
            int length_to_rev;
            scanf("%d", &length_to_rev);
            char to_rev[length_to_rev + 1];
            scanf("%s", to_rev);
            reverseString(to_rev, length_to_rev);
            printf("%s\n", to_rev);
        }
        else if (operation == 2)
        {
            int length_to_compress;
            scanf("%d", &length_to_compress);
            char *to_compress = malloc(sizeof(char) * (length_to_compress + 1));
            scanf("%s", to_compress);
            char *compressed;
            compressed = compressString(to_compress, length_to_compress);
            free(to_compress);
            printf("%s\n", compressed);
            free (compressed);
        }
        else if (operation == 3)
        {
            int n;
            scanf("%d", &n);
            int *arr = (int *)malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            int *newarr = uniqueElements(arr, n);
            free(arr);
            for (int i = 0; i < oper3; i++)
                printf("%d ", newarr[i]);
            printf("\n");
            free(newarr);
        }
        else if (operation == 4)
        {
            int row, col;
            scanf("%d %d", &row, &col);
            int **matrix = malloc(row * sizeof(int *));
            for (int i = 0; i < row; i++)
            {
                matrix[i] = malloc(col * sizeof(int));
            }
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    scanf("%d", &matrix[i][j]);
            int **transposed = transpose(matrix, row, col);
            for (int i = 0; i < row; i++)
                free(matrix[i]);
            free(matrix);
            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                    printf("%d ", transposed[i][j]);
                printf("\n");
            }
            for (int i = 0; i < col; i++)
                free(transposed[i]);
            free(transposed);
        }
    }
}