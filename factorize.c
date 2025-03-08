#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "sort.h"
#include "stack.h"
#define MAXLEN 50
//this is the max digit size
int matoi(char *c) {
    int d = 0;
    bool flag = false;
    if (c[0] == '-') {
        flag = !flag;
        c++;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        d = 10 * d + (c[i] - '0');
    }
    return (flag ? -1 * d : d);
}

void flush(char *c, int len) {
    for (int i = 0; i < len; i++) {
        c[i] = '\0';
    }
}

int *fact(int n) { //implement the factorization logic here
    stack *s = new();
    for (int i = 1; i <= sqrt(n); i++) { 
            if (n % i != 0) {
                continue;
            }
            char buffer[MAXLEN];
            snprintf(buffer, MAXLEN, "%d", i);
            push(s, buffer);
            //flush(c, MAXLEN);
            int x = n / i;
            if (x != i) { //this is done to avoid adding double roots as diff elements
                flush(buffer, MAXLEN); //only call flush if another is to be added
                snprintf(buffer, MAXLEN, "%d", x);
                //no need to flush
                push(s, buffer);
            }
    }
    int *arr = malloc(sizeof(int) * (s->len + 1)); //free later
    int i = 0;                                   
    for (; i < s->len; i++) {
        arr[i] = matoi(s->args[i]);
    }
    sort(arr, s->len); //call it with one less to not mess up the terminator
    arr[i] = INT_MIN; 
    del(s);
    return arr;
}

int len(int *arr) {
    int c = 0;
    for (; arr[c] != INT_MIN; c++);
    return c;
}

int main(int argc, char **args) {
    printf("\n\n"); //this is done to clear the terminal
    for (int x = 1; x < argc; x++) {
        int n = matoi(args[x]);
        printf("Factorizing: %d\n", n);        
        int *arr = fact(n);
        int sz = len(arr);
        for (int i = 0; i < sz / 2; i++) {
            printf("%d * %d\n", arr[i], arr[sz - 1 - i]);
        }
        if (sz % 2 != 0) {
            printf("%d * %d\n", arr[sz / 2], arr[sz / 2]);
        }
        free(arr);
        printf("\n\n");
    }
    return 0;
}
