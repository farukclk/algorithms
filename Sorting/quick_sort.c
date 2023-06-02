#include <stdio.h>



// sort only one number(pivot)
int partition(int arr[], int l, int r) {

    if ( l >= r )
        return l;

    int p = arr[l];   // define the leftmost number as the pivot
    int i = l + 1;
    int j = r;
    int tmp;

    while (j >= i) {
        while (arr[i] <= p) {
            i++;
        }

        while (arr[j] > p) {
            j--;
        }

        if (j > i) {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }

    tmp = arr[j];
    arr[j] = arr[l];
    arr[l] = tmp;

    return j;

}




// usage: quick_sort(arr, 0, length - 1 )
void quick_sort(int arr[], int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quick_sort(arr, l, p -1);
        quick_sort(arr, p + 1, r);
    }
}




int main(void) {

    int arr[7] = { -1, 3, 4, 44, -2, 34, 2 };

    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t\n");


    quick_sort(arr, 0, 6);


    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t(sorted)\n");

}
