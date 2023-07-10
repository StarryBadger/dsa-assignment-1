#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
extern int oper1;

extern int oper5;

int* intersectionArray(int* arr1, int* arr2, int lenArr1, int lenArr2);

int countCharOccurrences(const char* str, int length, char ch);

char findFirstNonRepeatingChar(const char* str, int length);

char* findLongestCommonPrefix(char** str, int numStr, int maxLen);

int *maxMin(int *arr, int lenArr);

char* removeSubstring(char* str, int strLength, const char* substr, int substrLength);
#endif