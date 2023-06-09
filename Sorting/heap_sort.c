#include <stdio.h>
#include "../include/data.h"



void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
void heapify_tree(TreeNode *root) {

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
    
    for (int i = length / 2; i >= 1; i--) 
        heapify_array(arr, i, length);
        
}




// max to min
void heap_sort(int *arr, int length) {
  
    build_heap(arr, length);

    while (length > 1) {
        swap(&arr[0], &arr[--length]);
        heapify_array(arr, 1, length);
    }
}




int main(void) {

    int arr[7] = { -1, 3, 4, 44, -2, 34, 2 };

    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t\n");


    heap_sort(arr, 7);


    for(int i=0; i<7; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\t(sorted)\n");

}
