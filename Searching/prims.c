/* Prim's Algorithm for Minimum Spanning Tree (MST)

    example:


     *[0]                           [3]
       |  \                       /     \
       |     \ 4                /         \
       |        \         3  /              \  3 
       |          \        /                  \
     4 |            \   /            4          \
	   |	        [2]--------------------------[5]
	   |           /    \                        /
	   |        /          \                  /
	   |      / 2           2 \            / 3
	   |   /                    \       /
	  [1]                          [4]


*/


#include <stdio.h>


 // node number
int NODE = 6;      


// TABLE[NODE + 1] [ NODE + 1]
// table[0][*] and table[*][0] should be 0 for initialization
int TABLE[7][7] = {
    {0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 4, 4, 0, 0, 0},
    {0, 4, 0, 2, 0, 0, 0},
    {0, 4, 2, 0, 3, 2, 4},
    {0, 0, 0, 3, 0, 0, 3},
    {0, 0, 0, 2, 0, 0, 3},
    {0, 0, 0, 4, 3, 3, 0}
};


int main() {

    int max = 999999999;  // to reset min 
    int min = max;
    int min_row;
    int min_column;


    // start from node [0]
    TABLE[1][0] = 1;
    TABLE[0][1] = 1;


    printf("Edge      Weigth\n");

    for (int i = 1; i < NODE; i++) {  // node_num - 1  = edge_num 

        // find the shortest edge and print

        for (int row = 1; row < NODE + 1; row++) {
            
            if (TABLE[row][0] == 1) {      // visited row 
                for (int column = 1; column < 7; column++) {
                    if (TABLE[0][column] == 0) {    // unvisited column
                        if (TABLE[row][column] < min && TABLE[row][column] != 0) {
                            min = TABLE[row][column];
                            min_column = column;
                            min_row = row;
                        }
                    }
                }
            }
        }
        printf("%d - %d      %d\n",min_row - 1, min_column - 1, min);

        TABLE[0][min_column] = 1;
        TABLE[min_column][0] = 1;
        min = max; 
    }
}



