#ifndef SORT_H
#define SORT_H
#include <stdbool.h>

//quicksort implementation
void sort(int *, int); //arr, len
void mqsort(int *, int, int); //arr, int start, int end
void swap(int *, int, int); //arr, index1, index2
int piv(int *, int, int); //arr, int l, int r
bool check(int *, int); //for debugging purposes, second is for len

#endif
