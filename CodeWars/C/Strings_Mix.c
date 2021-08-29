# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# define ALPHA_LEN 26


static const char ONE = '1';
static const char TWO = '2';
static const char SAME = '=';

typedef struct Data {
    char letter;
    int number;
    char src;
} Data;

int comp(const void * a, const void * b){
    Data * _a = (Data *) a, * _b = (Data *) b;
    if (_a->number != _b->number)
        return _a->number < _b->number;
    if (_a->src != _b->src)
        return _a->src > _b->src;
    return _a->letter > _b->letter;
}

char * mix(char * s1, char * s2) {
    int t1[ALPHA_LEN], t2[ALPHA_LEN];
    for (int i = 0; i < ALPHA_LEN; ++i)
        t1[i] = t2[i] = 0;
    int data_len = 0;
    for (int i = 0, len = strlen(s1); i < len; ++i){
        if (islower(s1[i])){
            int c = s1[i] - 'a';
            if (t1[c] == 1)
                ++data_len;
            ++t1[c];
        }
    }
    for (int i = 0, len = strlen(s2); i < len; ++i){
        if (islower(s2[i])){
            int c = s2[i] - 'a';
            if (t2[c] == 1 && t1[c] <= 1)
                ++data_len;
            ++t2[c];
        }
    }
    if (data_len == 0)
        return "";
    Data data[data_len];
    int res_len = -1; // The method below will overcount '/' one time
    for (int i = 0, cnt = 0; i < ALPHA_LEN && cnt < data_len; ++i){
        if (t1[i] > 1 || t2[i] > 1){
            int n = -1;
            char s;
            if (t2[i] < t1[i])
                n = t1[i], s = ONE;
            else if (t2[i] == t1[i])
                n = t1[i], s = SAME;
            else 
                n = t2[i], s = TWO;
            if (n != -1){
                data[cnt++] = (Data) {.letter = (char) i + 'a', .number = n, .src = s};
                res_len += 3 + n;
            }
        }
    }
    qsort(data, data_len, sizeof(Data), comp);
    char * res = (char *) malloc(sizeof(char) * (res_len + 1));
    for (int i = 0, cnt = 0; i < data_len; ++i){
        if (cnt) // need leading '/'
            res[cnt++] = '/';
        res[cnt++] = (char) data[i].src;
        res[cnt++] = ':';
        for (int j = 0; j < data[i].number; ++j)
            res[cnt++] = data[i].letter;
    }
    res[res_len] = '\0';
    return res;
}

int main(void){
    puts(mix("Are they here", "yes, they are here"));
    puts(mix("looping is fun but dangerous", "less dangerous than coding"));
}