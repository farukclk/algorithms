#include <malloc.h>
#include "../include/data.h"


//---------------------------------------FUNCTIONS----------------------------------------

ListNode2 *liste_basi(ListNode2 *list);                         // return head of the list
int is_sorted_recursive (ListNode *list);
int is_sorted_iterative(ListNode *list);
void swap(int *a, int *b);
//-----------------------------------------------------------------------------------------






// cift yolnu bagli listede basa don
ListNode2 *liste_basi(ListNode2 *list) {
    while (list->prev != NULL) {
        list = list->prev;
    }
    return list;
}





int is_sorted_iterative(ListNode *list) {

    while(list->next != NULL) {

        if (list->data > list->next->data)
            return 0;
        else
            list = list->next;
    }

    return 1;
}





int is_sorted_recursive(ListNode *list) {

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