#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int oper1;
int oper5;
int *intersectionArray(int *arr1, int *arr2, int lenArr1, int lenArr2)
{
    int frequencyArr1[10001] = {0};
    int frequencyArr2[10001] = {0};
    int intersect[lenArr1];
    int c = 0;
    for (int i = 0; i < lenArr1; i++)
    {
        frequencyArr1[arr1[i]]++;
    }
    for (int i = 0; i < lenArr2; i++)
    {
        frequencyArr2[arr2[i]]++;
    }
    for (int i = 0; i < 10001;)
    {
        if ((frequencyArr1[i]--) && (frequencyArr2[i]--))
            intersect[c++] = i;
        else
            i++;
    }

    int *final = (int *)(malloc(c * sizeof(int)));
    for (int i = 0; i < c; i++)
    {
        final[i] = intersect[i];
    }
    oper1 = c;
    return final;
}
int countCharOccurrences(const char *str, int length, char ch)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ch)
            count++;
    }
    return count;
}
char findFirstNonRepeatingChar(const char *str, int length)
{
    int frequencyArrASCII[256] = {0};
    for (int i = 0; i < length; i++)
    {
        frequencyArrASCII[str[i] + 128]++;
    }
    for (int i = 0; i < length; i++)
    {
        if (frequencyArrASCII[str[i] + 128] == 1)
            return str[i];
    }
    return '#';
}

char *findLongestCommonPrefix(char **str, int numStr, int maxLen)
{
    char st[101];
    int c = 0;
    char character_for_first_string;
    for (int i = 0; i < maxLen; i++)
    {
        int flag = 1;
        for (int j = 0; j < numStr; j++)
        {
            character_for_first_string = str[0][i];
            if (str[j][i] != character_for_first_string)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            st[c++] = character_for_first_string;
        else
            break;
    }
    char *LongestPrefix = (char *)malloc(sizeof(char) * (c + 1));
    st[c] = '\0';
    for (int i = 0; i < c + 1; i++)
        LongestPrefix[i] = st[i];
    return LongestPrefix;
}

int *maxMin(int *arr, int lenArr)
{
    int maxTillOneBefore[lenArr];
    int minFromNext[lenArr];
    int solnArr[lenArr];
    int count = 0;
    maxTillOneBefore[0] = 0;
    minFromNext[lenArr - 1] = 1000001;
    for (int i = 1; i < lenArr; i++)
    {
        maxTillOneBefore[i] = (maxTillOneBefore[i - 1] > arr[i - 1]) ? maxTillOneBefore[i - 1] : arr[i - 1];
    }
    for (int i = lenArr - 2; i >= 0; i--)
    {
        minFromNext[i] = (minFromNext[i + 1] < arr[i + 1]) ? minFromNext[i + 1] : arr[i + 1];
    }
    for (int i = 0; i < lenArr; i++)
    {
        if (arr[i] > maxTillOneBefore[i] && arr[i] < minFromNext[i])
            solnArr[count++] = i;
    }
    int *final_soln = (int *)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++)
    {
        final_soln[i] = solnArr[i];
    }
    oper5 = count;
    return final_soln;
}

char *removeSubstring(char *str, int strLength, const char *substr, int substrLength)
{
    int flag = 0, c = 0;
    char edited[strLength + 1];
    for (int i = 0; i < strLength;)
    {
        flag = 0;
        for (int j = 0; j < substrLength; j++)
        {
            if (substrLength > strLength - i)
                flag = 1;
            else
            {
                if (str[i + j] != substr[j])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
        {
            edited[c++] = str[i];
            i++;
        }
        else
            i += substrLength;
    }
    edited[c] = '\0';
    char *editedFinal = (char *)malloc(sizeof(char) * (c + 1));
    for (int i = 0; i < c + 1; i++)
    {
        editedFinal[i] = edited[i];
    }
    return editedFinal;
}
