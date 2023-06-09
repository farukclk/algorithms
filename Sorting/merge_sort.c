#include <stdio.h>



// usage: merge_sort(arr, 0, length - 1 )
void merge_sort(int arr[], int l, int r) {

    if (r == l) {
        return ;
    }

    int middle = (r + l) / 2 ;

    merge_sort(arr, l, middle);
    merge_sort(arr, middle + 1, r);


    //---------------------- MERGE OPERATION --------------------------
    int j = middle + 1;
    int left = l;

    int t_arr[r - l + 1];   // generate a new array
    int t_index = 0;


    while (1) {
        if (l <=middle && j <= r) {
            if (arr[l] < arr[j]) {
                t_arr[t_index++] = arr[l++];

            }
            else {
                t_arr[t_index++] = arr[j++];
            }
        }
        else if (l <= middle) {
            t_arr[t_index++] = arr[l++];
        }
        else if (j <= r) {
            t_arr[t_index++] = arr[j++];
        }
        else {
            break;
        }
    }


    int i = 0;
    while (i < t_index){
        arr[left++] = t_arr[i++];
    }
}




int main(void) {

    int length = 7;
    int arr[7] = { -1, 3, 4, 44, -2, 34, 2 };

    for(int i=0; i < length; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");


    merge_sort(arr, 0, length - 1);


    for(int i = 0; i < length; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t(sorted)\n");

}

