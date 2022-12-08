#include <stdio.h>
#include <stdlib.h>
int *memory(int n) {
    int *arr;
    arr = calloc(n, sizeof(int*));
    if(arr == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    return arr;
}
char **memoryChar(int n) {
    char **arr;
    arr = calloc(n, sizeof(int*));
    if(arr == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    return arr;
}
int isLetter(char s){
    if((s>='a'&&s<='z')||(s>='A'&&s<='Z'))
        return 1;
    return 0;
}
int strLen(char* string){
    int i=0;
    while (string[i] != '\0'){
        i++;
    }
    return i;
}
void strCopy(char *s1,char **s2){
    int i=0;
    int n = strLen(s1);
    (*s2)= (char *)calloc(n, sizeof(char));
    while (s1[i]!='\0'){
        (*s2)[i]=s1[i];
        i++;
    }
    (*s2)[i] = '\0';
}
int countWords(char **string){
    int cnt = 0, i;
    int n = strLen(*string);
    for (i = 0; i < n; i++) {
        if(isLetter((*string)[i]) == 1 && i == 0){
            cnt++;
        }
        if(isLetter((*string)[i]) == 0 && isLetter((*string)[i + 1]) == 1){
            cnt++;
        }
    }
    return cnt;
}
void merge(char ***arr, int **size, int left, int mid, int right) {
    int l = left, r = mid + 1;
    int len = right - left + 1;
    int *tempSize = (int *) calloc(len, sizeof(int));
    char **tempArr = (char **) calloc(len, sizeof(char *));
    int index = 0;
    while ((l <= mid) && (r <= right)) {
        if ((*size)[l] < (*size)[r]) {
            tempSize[index] = (*size)[l];
            tempArr[index] = (*arr)[l];
            l++;
        } else {
            tempSize[index] = (*size)[r];
            tempArr[index] = (*arr)[r];
            r++;
        }
        index++;
    }
    for (int i = l; i <= mid; i++) {
        tempSize[index] = (*size)[i];
        tempArr[index] = (*arr)[i];
        index++;
    }
    for (int i = r; i <= right; i++) {
        tempArr[index] = (*arr)[i];
        tempSize[index] = (*size)[i];
        index++;
    }
    for (int i = 0; i < len; i++) {
        (*size)[left + i] = tempSize[i];
        (*arr)[left + i] = tempArr[i];
    }
    free(tempSize);
    free(tempArr);
}
void mergeSort(char*** arr, int** sort, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(arr, sort, left, middle);
        mergeSort(arr, sort, middle + 1, right);
        merge(arr, sort, left, middle, right);
    }
}
void fillAndCopyArrays(int argc, char **inputStrings, char **argv, int **size) {
    for (int i = 1; i < argc; i++) {
        strCopy(argv[i], &inputStrings[i - 1]);
        (*size)[i - 1] = countWords(&inputStrings[i - 1]);
        printf("Count of the words: \033[0;34m%d\033[0m; %s\n", (*size)[i - 1], inputStrings[i - 1]);
    }
}
void deletingArr(char **arr, int n){
    if(n!=0){
        for (int i = 0; i < n; i++) free(arr[i]);
        free(arr);
    }
}
void printString(char* string){
    int i = 0;
    while(string[i] != '\0') {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}
void output(int argc, int* size, char **string){
    for (int i = 0; i < argc - 1; i++) {
        printf("Count of the words: \033[0;34m%d\033[0m; ", size[i]);
        printString(string[i]);
    }
}