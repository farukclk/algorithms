#include "include/tree.h"


int main() {
    
    printf("%d\n", decimal_to_binary(100, 0));

    int a[7] = {1,-20,11,22,11,23,-2};

    merge_sort(a, 0, 6);

    for(int i = 0;i < 7; i++)
        printf("%d  ", a[i]);

    printf("\n");

}


