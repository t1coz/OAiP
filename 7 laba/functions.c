//char* getStr(char **s, int k){
//    int c, i = 0;
//    k++;
//    *s = realloc(*s, k * sizeof(char));
//    while(--k > 0 && (c = getchar())!=EOF && c != '\n')
//        s[i++] = c;   //Enter or Ctrl + Z
//    s[i] = '\0';
//    return s;
//}
char* getStr(){
    char*s;
    char c;
    int i = 0, n = 1;
    s=(char*)calloc(n, sizeof(char));
    while(n <= 1){
        while((c = getchar())!=EOF && c != '\n'){
            n++;
            //arr = (float*)malloc(n * sizeof(float));
            s = (char*)realloc(s, n * sizeof(char));
            s[i] = c;
            i++;
        }
    }
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
void output (char *str){
    int n = strLen(str), i;
    for (i=0; i<n ; i++)
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
void theMostFrequent(char* str){
    int freq, n = strLen(str);
    char* temp = (char*)calloc(n, sizeof(char));
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i+1; j < n; j++) {
            if (str[j]==str[i]){
                count++;
            }
        }
        if(count>=freq){
            temp[i] = str[i];
            freq = count;
        }
    }
}
//while(isLetter((*str)[i]) != 0 || (*str)[i] != '\0' ){
//    for(int k = i; k < n-1; k++) {
//        (*str)[k] = (*str)[k+1];
//    }
//    (*str)[n-1] = 0;
//    n--;
//    *str = realloc(*str, n * sizeof(char));
//    i--;
//}
void deletingWords(char** str, char c){
    int i = 0, n = strLen(*str);
    while((*str)[i] != '\0') {
        if((isLetter((*str)[i]) == 1 && i == 0) || (isLetter((*str)[i]) == 1 && isLetter((*str)[i+1]) == 0) || ((*str)[i] != '\0')){
            if((*str)[i]==c) {
                while ((isLetter((*str)[i]) == 1 && isLetter((*str)[i+1]) == 1) || (*str)[i] != '\0') {
                    for (int k = i; k < n - 1; k++) {
                        (*str)[k] = (*str)[k + 1];
                    }
                    (*str)[n - 1] = '\0';
                    n--;
                    *str = realloc(*str, n * sizeof(char));
                    //i--;

                }
                i--;
            }
        }
        i++;
    }
}
void task1(){
    int count;
    char* str;
    printf("Enter the string: ");
    str = getStr();
    output(str);
    count = countWords(str);
    printf("%d", count);
    //theMostFrequent(str);
}
void task2(){
    char c;
    char* str0;
    char* str;
    printf("Enter the \033[0;34mfirst\033[0m string: ");
    str = getStr();
//    printf("Enter the \033[0;34msecond\033[0m string: ");
//    str0 = getStr();
    printf("Enter the symbol \033[0;34mC\033[0m that you want to remove from the first string: ");
    printf("\n");
    c = inputChecking();
    printf("\n\033[0;34mInitial string:\033[0m\n");
    output(str);
    deletingWords(&str, c);
    printf("\n\033[0;34mFinal string:\033[0m\n");
    output(str);
}
