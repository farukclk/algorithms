#include <malloc.h>
#include "../include/data.h"


//---------------------------------------FUNCTIONS----------------------------------------

Node2 *liste_basi(Node2 *list);                         // return head of the list
int is_sorted_recursive (Node *list);
int is_sorted_iterative(Node *list);
void swap(int *a, int *b);
//-----------------------------------------------------------------------------------------






// cift yolnu bagli listede basa don
Node2 *liste_basi(Node2 *list) {
    while (list->prev != NULL) {
        list = list->prev;
    }
    return list;
}





int is_sorted_iterative(Node *list) {

    while(list->next != NULL) {

        if (list->data > list->next->data)
            return 0;
        else
            list = list->next;
    }

    return 1;
}





int is_sorted_recursive(Node *list) {

    if (list->next ==  NULL)
        return 1;
    
    if (list->data > list->next->data)
        return 0;
    else 
        return is_sorted_recursive(list->next);
    
}




void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}