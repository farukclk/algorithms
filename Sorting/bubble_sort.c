#include <stdio.h>
#include "sorting.h"


void bubble_sort(int *arr, int length) {
    int tmp = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length -1 -i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}




int main(void) {

    int arr[7] = { -1, 3, 4, 44, -2, 34, 2 };

    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t\n");


    bubble_sort(arr, 7);


    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t(sorted)\n");

}
