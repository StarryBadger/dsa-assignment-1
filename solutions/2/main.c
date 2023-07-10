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
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            int arr1[n1];
            int arr2[n2];
            for (int i = 0; i < n1; i++)
                scanf("%d", &arr1[i]);
            for (int i = 0; i < n2; i++)
                scanf("%d", &arr2[i]);
            int *intersection = intersectionArray(arr1, arr2, n1, n2);
            if (oper1 == 0)
                printf("-1\n");
            else
            {
                for (int i = 0; i < oper1; i++)
                {
                    printf("%d ", intersection[i]);
                }
                printf("\n");
                free(intersection);
            }
        }
        else if (operation == 2)
        {
            int n;
            scanf("%d", &n);
            char str[n + 1];
            scanf("%s", str);
            getchar();
            char ch;
            scanf("%c", &ch);
            int count = countCharOccurrences(str, n, ch);
            printf("%d\n", count);
        }
        else if (operation == 3)
        {
            int n;
            scanf("%d", &n);
            char str[n + 1];
            scanf("%s", str);
            char firstNonRepeating = findFirstNonRepeatingChar(str, n);
            if (firstNonRepeating == '#')
                printf("-1\n");
            else
                printf("%c\n", firstNonRepeating);
        }
        else if (operation == 4)
        {
            int n;
            scanf("%d", &n);
            char **strList = malloc(n * sizeof(char *));
            for (int i = 0; i < n; i++)
            {
                strList[i] = malloc(101 * sizeof(char));
            }
            int currLen;
            int maxLen = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &currLen);
                scanf("%s", strList[i]);
                getchar();
                maxLen = (maxLen > currLen) ? maxLen : currLen;
            }
            char *prefix = findLongestCommonPrefix(strList, n, maxLen);
            if (prefix[0] == '\0')
                printf("-1\n");
            else
            {
                printf("%s\n", prefix);
                for (int i = 0; i < n; i++)
                    free(strList[i]);
                free(strList);
                free(prefix);
            }
        }
        else if (operation == 5)
        {
            int n;
            scanf("%d", &n);
            int Arr[n];
            for (int i = 0; i < n; i++)
                scanf("%d", &Arr[i]);
            int *solnArr = maxMin(Arr, n);
            if (oper5 == 0)
                printf("-1\n");
            else
            {

                for (int i = 0; i < oper5; i++)
                    printf("%d ", solnArr[i]);
                printf("\n");
                free(solnArr);
            }
        }
        else if (operation == 6)
        {
            int n, m;
            scanf("%d %d", &n, &m);
            char str[n + 1];
            char substr[m + 1];
            getchar();
            scanf("%s", str);
            getchar();
            scanf("%s", substr);
            char *edited = removeSubstring(str, n, substr, m);
            if (edited[0] == '\0')
                printf("-1\n");
            else
            {
                printf("%s\n", edited);
                free(edited);
            }
        }
    }
}