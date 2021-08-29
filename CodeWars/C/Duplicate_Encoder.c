# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char * toLowerCase(char * str){
    int size = strlen(str);
    char * res = (char *) malloc(sizeof(char) * size + 1);
    int diff = 'a' - 'A';
    for (int i = 0; i < size; ++i)
        res[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + diff : str[i];
    res[size] = '\0';
    return res;
}

char * DuplicateEncoder(char * str){
    int table[128];
    for (int i = 0; i < 128; table[i++] = 0);
    char * newStr = toLowerCase(str);
    for (char * p = newStr; * p != '\0'; ++table[(int) (*p++)]);
    for (char * p = newStr; * p != '\0'; ++p)
        * p = table[(int) * p] == 1 ? '(' : ')';
    return newStr;
}

int main(void){
    printf("%s\n", DuplicateEncoder("|"));
}