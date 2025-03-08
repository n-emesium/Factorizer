#include "sort.h"

void swap(int *arr, int index1, int index2) {
    int elem = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = elem;
}

int piv(int *arr, int l, int r) {
    int pv = r - 1; //the pivot index
    int ipv = arr[pv]; //use for comparing
    int swap_index = l; //use for swapping   
    for (int i = l; i < pv; i++) { //loop until the final; range: [0, pv)
        if (arr[i] <= ipv) {
            swap(arr, i, swap_index);
            swap_index++; 
        }
    }
    swap(arr, pv, swap_index);
    return swap_index;
}

void mqsort(int *arr, int l, int r) { //right should start at actual length since piv subtracts 1
    if (l < r) { 
        int pvx = piv(arr, l, r);
        mqsort(arr, l, pvx); //piv uses len -1 as the last element
        mqsort(arr, pvx + 1, r);
    }
}

void sort(int *arr, int len) { //actual sorting function, in place, clone is not created
    mqsort(arr, 0, len); //use the literal length, not the last element or it will crash
}

bool check(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
} 
