#include <stdio.h>



void insertion_sort(int *arr, int length) {
    int key, j;

    for (int i = 1; i < length; i++) {
        key = arr[i];

        j = i;
        while (j >= 1) {
            if (arr[j - 1] > key) {
                arr[j] = arr[j - 1];
                j--;
            }
            else
                break;
        }
        arr[j] = key;
    }
}




int main(void) {

    int arr[7] = { -1, 3, 4, 44, -2, 34, 2 };

    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t\n");


    insertion_sort(arr, 7);


    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t(sorted)\n");

}
