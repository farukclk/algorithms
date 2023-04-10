#include <malloc.h>
// tek yonlu node
typedef struct node {
    int sayi;
    struct node *next;
} Node;

// cift yonlu node
typedef struct node2 {
    int sayi;
    struct node2 *prev;
    struct node2 *next;
} Node2;


//---------------------------------------FUNCTIONS----------------------------------------

Node2 *liste_basi(Node2 *list);                // return first node of list
void selectionSort(int array[], int length);   
int is_sorted_recursive (Node *list);
int is_sorted_iterative(Node *list);
void merge_sort(int array[], int l, int r);
void quick_sort(int array[], int l, int r);
int partition(int array[], int l, int r);      // part of quick_sort()
//-----------------------------------------------------------------------------------------





// cift yolnu bagli listede basa don
Node2 *liste_basi(Node2 *list) {
    while (list->prev != NULL) {
        list = list->prev;
    }
    return list;
}




// array[] sirala.  n = dizi uzunlugu. n verilmek zorunda yoksa NULL lar 0 olarak en basa siralanair
void selectionSort(int dizi[], int n) {

    int tmp, min_index;
    for (int i=0; i<n; i++) {

        min_index = i;
        for (int j = i; j<n; j++) {
            if (dizi[j] < dizi[min_index]) {
                min_index = j;
            }
        }

        tmp = dizi[i];
        dizi[i] = dizi[min_index];
        dizi[min_index] = tmp;
        
    }

}




// Node or Node2
int is_sorted_iterative(Node *list) {
 
    int first, second;

    while(list->next != NULL) {
        first = list->sayi;
        second = list->next->sayi;

        if (first > second)
            return 0;
        else
            list = list->next;
    }

    return 1;
}




// Node or Node2
// like selection sort
int is_sorted_recursive (Node *list) {

    if (list->next == NULL) {
        return 1;
    }
    else {
        if (is_sorted_recursive(list->next) == 0)
            return 0;
    }

    int first = list->sayi;
    while(list != NULL) {
        if (first > list->sayi ) {
            return 0;
        }

        list = list->next;
    }

    return 1;
}




// usage: mergeSort(arr, 0, length - 1 )
void mergeSort(int arr[], int l, int r) {

    if (r == l) {
        return ;
    }

    int middle = (r + l) / 2 ;

    mergeSort(arr, l, middle);
    mergeSort(arr, middle + 1, r);


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




// sort only one number(pivot)
int partition(int arr[], int l, int r) {

    if ( l >= r )
        return l;

    int p = arr[l];   // define the leftmost number as the pivot
    int i = l + 1;
    int j = r;
    int tmp;

    while (j > i) {
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




void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}
