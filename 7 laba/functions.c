char **memory(int n) {
    char **arr;
    arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++){
        arr[i] = (char *)malloc(n * sizeof(char));
    }
    if(arr == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    return arr;
}
char* getStr(){
    char*s;
    char c;
    int i = 0, n = 1;
    s=(char*)calloc(n, sizeof(char));
    while(n <= 1){
        while((c = getchar())!=EOF && c != '\n'){
            n++;
            s = (char*)realloc(s, n * sizeof(char));
            s[i] = c;
            i++;
        }
    }
    s[n] = '\0';
    return s;
}
int isLetter(char s){
    if((s>='a'&&s<='z')||(s>='A'&&s<='Z'))
        return 1;
    return 0;
}
int strLen(char* str){
    int i=0;
    while (str[i]!='\0'){
        i++;
    }
    return i;
}
int strCmp(char *s1, char *s2){
    int i = 0;
    while(s1[i] != '\0'){
        if (s1[i]-s2[i] != 0)
            return s1[i]-s2[i];
        i++;
    }
    if (s1[i] == '\0')
        return -1;
    return 0;
}
void strCopy(char *s1,char **s2){
    int i=0;
    int n = strLen(s1);
    *s2 = (char *)calloc(n, sizeof(char));
    while (s1[i]!='\0'){
        (*s2)[i]=s1[i];
        i++;
    }
    (*s2)[i] = '\0';
}
void output (char *str){
    int n = strLen(str), i;
    for (i = 0; i < n ;i++)
        printf ("%c", str[i]);
    printf("\n");
}
char inputChecking(){
    char c;
    while (scanf("%c", &c) != 1) {
        printf("Try entering the symbol again: ");
        rewind(stdin);
    }
    return c;
}
int methodinputCh(){
    float num;
    while (scanf("%f", &num) != 1 || num != (int)num ||((int)num !=1 && (int)num !=2 && (int)num != 99) || getchar() != '\n') {
        printf("Try better:\n");
        rewind(stdin);
    }
    return num;
}
int countWords(char *s){
    int cnt = 0, i;
    int n = strLen(s);
    for (i = 0; i < n; i++) {
        if(isLetter(s[i])==1 && i == 0){
            cnt++;
        }
        if(isLetter(s[i])==0 && isLetter(s[i+1])==1){
            cnt++;
        }
    }
    return cnt;
}
//void insertionSort(char* arr, int n){
//    char key;
//    int i, j;
//    for (i = 1; i < n; i++) {
//        key = arr[i];
//        j = i - 1;
//        while (j >= 0 && arr[j] > key){
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = key;
//    }
//}
//void outputOf(char** words, char* str){
//    int n = strLen(str);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 15; j++) {
//            printf("%c", words[i][j]);
//        }
//        printf("\n");
//    }
//}
void outputOfTheMostFreqWord (char** words, int maxIndex){
    int len = 0;
    for (int i = 0; i < 15; i++) {
        if (isLetter(words[maxIndex][i]) == 0)
            break;
        len++;
    }
    for (int i = 0; i < len ; i++)
        printf ("%c", words[maxIndex][i]);
    printf("\n");
}
void splittingInAnotherArray(char* str, char*** words){
    int i, j, k, wordLength , lastSymbol = 0;
    int n = strLen(str);
    int counter = 0;
    for (i = 0; i < n+1; i++) {
        if (isLetter(str[i]) == 0 || str[i] == EOF) {
            wordLength = i - lastSymbol;
            k = 0;
            for (j = lastSymbol; j <= i; j++) {
                if (j == i){
                    (*words)[counter][k] = ' ';
                    break;
                }
                (*words)[counter][k] = str[j];
                k++;
            }
            if (wordLength == 0)
                counter--;
            counter++;
            lastSymbol = i + 1;
        }
    }
}
int mostRepeated(char*arr, char** words){
    int repeatCount = 0, maxRepeat = 0, maxIndex = 0, flag = 1;
    int wordCount = countWords(arr);
    int n = strLen(arr);
    for (int j = 0; j < wordCount; j++){
        for (int i = 0; i < wordCount; i++) {
            for (int k = 0; k < n; k++){
                if (words[j][k] != words[i][k]){
                    flag = 0;
                    break;
                }
            }
            if (flag == 1){
                repeatCount++;
            }
            flag = 1;
        }
        if (maxRepeat < repeatCount){
            maxRepeat = repeatCount;
            maxIndex = j;
        }
        repeatCount = 0;
    }
    return maxIndex;
}
void deletingAarr(char **arr, int n){
    for (int i = 0; i < n; ++i) free(arr[i]);
    free(arr);
}
//char findMostFrequentElement(char* str){
//    int n = strLen(str);
//    int max_count = 1, count = 1;
//    char res = str[0];
//    insertionSort(str, n);
//    for (int i = 1; i < n; i++){
//        if (str[i] == str[i - 1])
//            count++;
//        else {
//            if (count > max_count){
//                max_count = count;
//                res = str[i - 1];
//            }
//            count = 1;
//        }
//    }
//    if (count > max_count){
//        res = str[n - 1];
//    }
//    if(isLetter(res) != 1){
//        return '&';
//    }
//    return res;
//}
int beginningOfTheWord(char* str, int j){
    int i = 0, count = 1, n = strLen(str);
    while((isLetter(str[i])!=0 && isLetter(str[i+1])!=1)&& count!=j){
        i++;
        count++;
    }
    return i;
}
int endOfTheWord(char* str, int j){
    int i = 0, n = strLen(str);
    while(isLetter(str[i])!=0){
        i++;
    }
    return i;
}
void deletingWords(char** str, char c){
    int i = 0, n = strLen(*str);
    while((*str)[i] != '\0') {
        if((isLetter((*str)[i]) == 1 && i == 0) || (isLetter((*str)[i]) == 1 && isLetter((*str)[i+1]) == 0) || ((*str)[i] != '\0')){
            if((*str)[i]==c) {
                while ((isLetter((*str)[i+1]) != 0 && isLetter((*str)[i])!=0)  || (*str)[i] != '\0') {
                    for(int k = i; k < n-1; k++){                        //border
                        if ((*str)[k] ){
                            break;
                        }
                        (*str)[k] = (*str)[k+1];
                    }
                    (*str)[n-1] = '\0';
                    n--;
                    *str = realloc(*str, n * sizeof(float));
                }
                i--;
            }
        }
        i++;
    }
}
void task1(){
    int maxIndex;
    char* str;
    printf("Enter the string: ");
    str = getStr();
    int n = strLen(str);
    char** words;
    words = memory(n);
    splittingInAnotherArray(str, &words);
    maxIndex = mostRepeated(str, words);
    printf("\nThe most repeated word: \033[0;34m\033[0m\n");
    outputOfTheMostFreqWord(words, maxIndex);
    free(str);
    deletingAarr(words, n);
}
void task2(){
    char c;
    char* str0;
    char* str;
    printf("Enter the \033[0;34mfirst\033[0m string: ");
    str = getStr();
    int n = strLen(str);
    printf("Enter the \033[0;34msecond\033[0m string: ");
    str0 = getStr();
    printf("Enter the symbol \033[0;34mC\033[0m that you want to remove from the first string: ");
    printf("\n");
    c = inputChecking();
    printf("\n\033[0;34mInitial string:\033[0m\n");
    output(str);
    deletingWords(&str, c);
    //printf("%d", endOfTheWord(str, 2));
    printf("\n\033[0;34mFinal string:\033[0m\n");
    output(str);
    free(str);
    free(str0);
}
