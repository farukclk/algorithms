#include <stdio.h>


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



Node2 *liste_basi(Node2 *list);
void selectionSort(int array[], int length);
int is_sorted_recursive (Node *list);
int is_sorted_iterative(Node *list);





// cift yolnu bagli listede basa don
Node2 *liste_basi(Node2 *list) {
    while (list->prev != NULL) {
        list = list->prev;
    }
    return list;
}



// array[] sirala.  n = dizi uzunlugu. n verilmek zorunda yoksa NULL lar 0 olarak en basa siralanair
void selectionSort(int dizi[], int n) {

    int tmp ,min, min_index;
    for (int i=0; i<n; i++) {
        min = dizi[i];
        min_index = i;
        for (int j = i; j<n; j++) {
            if (dizi[j] < min) {
                min = dizi[j];
                min_index = j;

            }
        }

        tmp = dizi[i];
        dizi[min_index] = tmp;
        dizi[i] = min;
    }

}



// Node veya Node2
int is_sorted_iterative(Node *list) {
    Node *tmp;

    int first;

    while(list->next->sayi != NULL) {
        first = list->sayi;
        tmp = list;

        while(tmp->sayi != NULL) {
            if ( first > tmp->sayi) {
                return 0;
            }
            tmp = tmp->next;
        }

        list = list->next;

    }

    return 1;
}



// Node veya Node2
int is_sorted_recursive (Node *list) {

    int sonuc = -1;

    if (list->next->sayi != NULL) {

        sonuc = is_sorted_recursive(list->next);
    }

    if (sonuc == 0) { // sirali degilse direct çik
        return 0;
    }

    int first = list->sayi;

    while(list->sayi != NULL) {
        if (list->sayi < first) {
            return 0;
        }

        list = list->next;
    }

    return 1;
}
