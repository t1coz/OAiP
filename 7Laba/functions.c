char **memory(int n) {
    char **arr;
    arr = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++){
        arr[i] = calloc(n, sizeof(char));
    }
    if(arr == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    return arr;
}
char* getStrV2(){
    int size = 16;
    char *buffer = malloc(sizeof(char) * size);
    int input = 0;
    int num_data = 0;
    while (1){
        if (num_data == size){
            size *= 2;
            buffer = realloc(buffer, sizeof(char) * size);
            printf("Buffer size: %d\n", size);
        }
        printf("Enter (-1 to quit): ");
        scanf("%d", &input);
        if (input == -1) break;
        else buffer[num_data] = input;
        num_data++;
    }
    return buffer;
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
int sizeM(char **arr, int row){
    int size = 1;
    for (int i = 0; ; i++) {
        if(isLetter(arr[row][i]) != 0){
            size++;
        }else{
            break;
        }
    }
    return size;
}
int strLen(char* str){
    int i=0;
    while (str[i]!='\0'){
        i++;
    }
    return i;
}
void output (char *str){
    int n = strLen(str), i;
    for (i = 0; i < n ;i++)
        printf ("%c", str[i]);
    printf("\n");
}
char inputChecking(){
    char c;
    while (scanf("%c", &c)!=1) {
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
void outputOf(char** words, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizeM(words, i); j++) {
            if (isLetter(words[i][j]) == 0){
                break;
            }
            printf("%c", words[i][j]);
        }
        printf(" ");
    }
}
void outputOfTheMostFreqWord (char** words, int n, int maxIndex){
    int len = 0;
    for (int i = 0; i < n; i++) {
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
void deletingArr(char **arr, int n){
    if(n!=0){
        for (int i = 0; i < n; i++) free(arr[i]);
        free(arr);
    }
}
//2 task

void deletingWordWithRow(char*** strSplited, int *wordCount, int k, int m){
    int i;
    for(i = k; i<*wordCount-1; i++){
        for(int j=0; j < m; j++)
            (*strSplited)[i][j] = (*strSplited)[i+1][j];
    }
    (*wordCount)--;
    (*strSplited) = (char**)realloc((*strSplited), (*wordCount) * sizeof(char*));
}

void finalArrAfterDeleting(char*** strSplited, char** str0Splited, char* str, char c, int n, int ket, int* wordCount, int wordCount0){
    int i, j, repeatCount = 0, flag = 1;
    for (j = 0; j < (*wordCount); j++){
        for (i = 0; i < wordCount0; i++){
            for (int k = 0; k < ket; k++){
                if ((*strSplited)[j][k] != str0Splited[i][k]){
                    flag = 0;
                    break;
                }
            }
            if (flag == 1){
                repeatCount++;
            }
            flag = 1;
        }
        if (repeatCount == 0 && (*strSplited)[j][0] == c){
            deletingWordWithRow(strSplited, wordCount, j, n);
        }
        repeatCount = 0;
    }
}

void task1(){
    int maxIndex;
    char* str;
    printf("Enter the string: ");
    str = getStr();
    int n = strLen(str);
    char** words = memory(n);
    splittingInAnotherArray(str, &words);
    maxIndex = mostRepeated(str, words);
    printf("\nThe most repeated word: \033[0;34m\033[0m\n");
    outputOfTheMostFreqWord(words, n, maxIndex);
    free(str);
    deletingArr(words, n);
}
void task2(){
    char c;
    char* str;
    char* str0;
    //initial information
    //first row
    printf("Enter the \033[0;34mfirst\033[0m string: ");
    str = getStrV2();
    int countWord = countWords(str);
    //second row
    printf("Enter the \033[0;34msecond\033[0m string: ");
    str0 = getStr();
    int countWord0 = countWords(str0);
    //symbol
    printf("Enter the symbol \033[0;34mC\033[0m, that is the beginning of a word: ");
    printf("\n");
    c = inputChecking();
    printf("\n\033[0;34mInitial string:\033[0m\n");
    output(str);
    //manipulations
    //two 2d arrays nxn
    char** strSplited = memory(countWord);
    splittingInAnotherArray(str, &strSplited);
    char** str0Splited = memory(countWord);
    splittingInAnotherArray(str0, &str0Splited);
    finalArrAfterDeleting(&strSplited, str0Splited, str, c, strLen(str), strLen(str0),&countWord, countWord0);
    printf("\n\033[0;34mFinal string:\033[0m\n");
    //deletingWordWithRow(strSplited, &n, 0);
    outputOf(strSplited, countWord);
    free(str);
    free(str0);
    deletingArr(strSplited, countWord);
    deletingArr(str0Splited, countWord0);
}

