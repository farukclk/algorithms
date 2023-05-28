#include <malloc.h>
#include "data.h"


//---------------------------------------FUNCTIONS----------------------------------------

void bubble_sort(int *arr, int length);
void build_heap(int *arr, int length);                  // heap sort
Node2 *liste_basi(Node2 *list);                         // return head of the list
void heapify_array(int *arr, int index, int length);    // heap sort
void heapify_tree(Tree *root);                          // heap sort
void heap_sort(int *arr, int length);
void insertion_sort(int *arr, int length);
int is_sorted_recursive (Node *list);
int is_sorted_iterative(Node *list);
void merge_sort(int array[], int l, int r);
void selection_sort(int array[], int length);
void quick_sort(int array[], int l, int r);
int partition(int array[], int l, int r);               // part of quick_sort()
void swap(int *a, int *b);
//-----------------------------------------------------------------------------------------





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




// cift yolnu bagli listede basa don
Node2 *liste_basi(Node2 *list) {
    while (list->prev != NULL) {
        list = list->prev;
    }
    return list;
}




// min-heap
void heapify_array(int *arr, int index, int length) {
    int left = index * 2 ;
    int right = left + 1;

    // iki taraf da null
    if (length < left) {
        return;
    }
        // sag node null
    else if (length == left) {
        if (arr[left-1] < arr[index-1]) {
            swap(&arr[left-1], &arr[index-1]);
        }
    }
    else {
        if (arr[index-1] < arr[left-1] && arr[index-1] < arr[right-1])
            return;
        else {
            if (arr[left-1] < arr[right-1]) {
                swap(&arr[left-1], &arr[index-1]);
                heapify_array(arr, left, length);
            }
            else {
                swap(&arr[right-1], &arr[index-1]);
                heapify_array(arr, right, length);
            }
        }
    }
}




// Min-Heap
// part of heap sort algorithm
void heapify_tree(Tree *root) {

    if (root == NULL) {
        return;
    }

    // yapraksa, iki taraf null oldugu durum, kıasy yapıcak baska eleman yok
    else if (root->left == NULL && root->right == NULL) {
        return;
    }

    // sag null ise
    else if(root->left != NULL  && root->right == NULL) {
         if (root->left->data < root->data)  
            swap(&root->left->data, &root->data);
    }

    // iki tarf dolu ise
    else {
        // subtree lere gec
        heapify_tree(root->left);
        heapify_tree(root->right);
         

        // uclu karsilastirmalari yap
        // left node en kucuk ise 
        if (root->left->data <= root->right->data &&  root->left->data < root->data) {
            swap(&root->left->data, &root->data);
            heapify_tree(root->left);
        }
        // right node en kucuk ise
        else if (root->left->data >= root->right->data &&  root->right->data < root->data) {
            swap(&root->right->data, &root->data);
            heapify_tree(root->right);
        }            
   }
}




// min-heap
void build_heap(int *arr, int length) {
    int floor = length / 2;
    for (int i = floor; i >= 1; i--) {
        heapify_array(arr, i, length);
    }
}




// max to min
void heap_sort(int *arr, int length) {
    build_heap(arr, length);
    while (length > 1) {
        swap(&arr[0], &arr[length -1]);
        heapify_array(arr, 1, --length);
    }
}




void insertion_sort(int *arr, int length) {
    int j;
    int tmp;

    for (int i = 1; i < length; i++) {
        j = i;
        tmp = arr[j];

        while (j >= 1) {
            if (arr[j - 1] > arr[j]) {
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                j--;
            }
            else
                break;
        }
    }
}



// Node or Node2
int is_sorted_iterative(Node *list) {

    while(list->next != NULL) {

        if (list->data > list->next->data)
            return 0;
        else
            list = list->next;
    }

    return 1;
}




// Node or Node2
// like selection sort
int is_sorted_recursive(Node *list) {

    if (list->next == NULL) {
        return 1;
    }
    else {
        if (is_sorted_recursive(list->next) == 0)
            return 0;
    }

    int first = list->data;
    while(list != NULL) {
        if (first > list->data ) {
            return 0;
        }

        list = list->next;
    }

    return 1;
}




// usage: mergeSort(arr, 0, length - 1 )
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




// array[] sirala.  n = dizi uzunlugu. n verilmek zorunda yoksa NULL lar 0 olarak en basa siralanair
void selection_sort(int dizi[], int n) {

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




// sort only one number(pivot)
// part of merge sort algorithm
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




void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}