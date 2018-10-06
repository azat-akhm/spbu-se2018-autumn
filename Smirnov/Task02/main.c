#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int sort(int *arr, int size);

void parse(char *str, char *key, int *val) {
    int i = 0, cnt = 0;

    // Parametr's name extracting
    for (i = 2; i < strlen(str) && str[i] != '='; ++i)
        key[i - 2] = str[i];
    if (i == strlen(str))
        return;
    i++;

    // Number extracting
    char symbolVal[64];
    for ( ; i < strlen(str); ++i)
        if ('0' <= str[i] && str[i] <= '9')
            symbolVal[cnt++] = str[i];
    *(val) = atoi(symbolVal);
}

int main(int argc, char *argv[]) {
    int to, from;
    _Bool existTo = 0, existFrom = 0;
    for (int i = 1; i < argc; ++i) {
        char key[10] = "";
        int val;
        parse(argv[i], key, &val);
        if (key[0] == 't' && key[1] == 'o') {
            to = val;
            existTo = 1;
        }
        else if (key[0] == 'f' && key[1] == 'r' && key[2] == 'o' && key[3] == 'm') {
            from = val;
            existFrom = 1;
        }
    }
    int data[100], arr[100], count = 0, arrSize = 0;
    while (scanf("%d", &data[count])) {
        if (existFrom && data[count] <= from) {
            fprintf(stdout, "%d ", data[count]);
        }
        else {
            if (existTo && data[count] >= to)
                fprintf(stderr, "%d ", data[count]);
            else
                arr[arrSize++] = data[count];
        }
    }
    int ans = sort(arr, arrSize);
    return ans;
}
