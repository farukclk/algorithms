#include <stdio.h>



// array[] sirala.  n = dizi uzunlugu. n verilmek zorunda yoksa NULL lar 0 olarak en basa siralanair
void selection_sort(int arr[], int n) {

    int tmp, min_index;
    for (int i=0; i<n; i++) {

        min_index = i;
        for (int j = i; j<n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
        
    }

}




int main(void) {

    int arr[7] = { -1, 3, 4, 44, -2, 34, 2 };

    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t\n");


    selection_sort(arr, 7);


    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t(sorted)\n");

}
