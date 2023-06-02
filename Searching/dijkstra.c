/*
 *  example undirected graph:
 *
 *
 *                                  (8)             (7)
 *                          [1]-----------[2]-----------------[3]\
 *                         /               |\                   |  \
 *                   (4)  /            (2) |   \                |     \ (9)
 *                       /                 |     \              |       \
 *                      /                  |       \            |         \
 *   start here  =>   [0]                 [8]         \(4)      |(14)      [4]
 *                      \               /  |            \       |         /
 *                       \       (7) /     |              \     |       /
 *                    (8) \        /       | (6)            \   |     / (10)
 *                         \    /          |                   \|   /
 *                          [7]-----------[6]------------------[5]/
 *                                  (1)               (2)
 *
 *
 */

#include <stdio.h>
#include <malloc.h>

int NODE_COUNT;
int INFINITY = 99999;


typedef struct dict_node {
    struct graph_node *node;
    int distance;               // one vector length to node
    struct dict_node *next;
} Dictionary;

typedef struct graph_node {
    char character;
    int distance;               // sum of all vectors in path
    int visited;
    Dictionary *dictionary;     // <vertex> <distance>
    struct graph_node *next;
} Node;


Dictionary *dict_put(Dictionary *dictionary, Node *_node, int distance);
Node *create_vertex(char name);
void add_vector(Node *node_from, Node *node_to, int distance);
int calculate_distances(Node **node_list, int table[][NODE_COUNT + 1], int iteration);
void print_table(int table[][NODE_COUNT + 1]);
void create_table(int table[][NODE_COUNT + 1], Node **list);
void print_path(int table[][NODE_COUNT + 1], char name);


int main(void) {
    //-------------------------------- example code
    // create vertex
    Node *node0, *node1, *node2, *node3, *node4, *node5, *node6,*node7, *node8 ;
    node0 = create_vertex('0');
    node1 = create_vertex('1');
    node2 = create_vertex('2');
    node3 = create_vertex('3');
    node4 = create_vertex('4');
    node5 = create_vertex('5');
    node6 = create_vertex('6');
    node7 = create_vertex('7');
    node8 = create_vertex('8');

    node0->distance = 0;             // set as start node


    // add vectors
    add_vector(node0, node1, 4);
    add_vector(node0, node7, 8);
    add_vector(node7, node1, 11);

    add_vector(node1, node2, 8);
    add_vector(node7, node8, 7);
    add_vector(node7, node6, 1);
    add_vector(node6, node8, 6);
    add_vector(node8, node2, 2);

    add_vector(node2, node3, 7);
    add_vector(node2, node5, 4);
    add_vector(node6, node5, 2);

    add_vector(node5, node4, 10);
    add_vector(node5, node3, 14);
    add_vector(node3, node4, 9);


    Node *node_list[9] = {node0, node1, node2, node3, node4, node5, node6, node7, node8};
    NODE_COUNT = 9;

    //---------------------------------------------------------

    // create table
    int table[NODE_COUNT + 1][NODE_COUNT + 1];
    create_table(table, node_list);

    calculate_distances(node_list, table, 1);

    print_table(table);


    // print shortest paths
    printf("\nshortest paths to each node: \n");
    for (int i = 0; i < NODE_COUNT; i++)
        print_path(table, node_list[i]->character);




    printf("\nshortest distances: \n");
    for (int i = 0; i< NODE_COUNT; i++)
        printf("%c : %d\n",  node_list[i]->character, node_list[i]->distance);


}




Node *create_vertex(char name) {

    Node *new_node = (Node*) malloc(sizeof (Node));
    new_node->dictionary = NULL;
    new_node->distance = INFINITY;
    new_node->character = name;
    new_node->visited = 0;
    new_node->next = NULL;

    return new_node;
}



Dictionary *dict_put(Dictionary *dictionary, Node *_node, int distance) {

    Dictionary *new_dict_node = (Dictionary*) malloc(sizeof (Dictionary));
    new_dict_node->node = _node;
    new_dict_node->distance = distance;
    new_dict_node->next = NULL;

    if (dictionary != NULL)
        new_dict_node->next = dictionary;


    return new_dict_node;

}



void add_vector(Node *node_from, Node *node_to, int distance) {

    node_from->dictionary =  dict_put(node_from->dictionary, node_to, distance);

    // below line is for undirected graphs, if you work with directed graphs make comment line
    node_to->dictionary = dict_put(node_to->dictionary, node_from, distance);

}



void create_table(int table[][NODE_COUNT + 1], Node **list) {
    table[0][0] = 45;       //  '-'

    // first row
    for (int i = 1; i < NODE_COUNT + 1; i++) {
        table[0][i] = list[i-1]->character;
    }

    for (int row = 1; row < NODE_COUNT + 1; row++) {

        table[row][0] = 45;

        for (int j = 1; j < NODE_COUNT + 1; j++)
            table[row][j] = list[j-1]->distance;
    }
}




// find the min node and calculate its vectors
// set iteration = 1 when call this function
int calculate_distances(Node **node_list, int table[][NODE_COUNT + 1], int iteration) {

    Node *min_node = NULL;
    int node_distance;

    // ilk visited olamayn nodu baslangıc nodu olarak ata
    for (int i = 0; i < NODE_COUNT; i++) {
        if (node_list[i]->visited == 0) {
            min_node = node_list[i];
            break;
        }
    }

    if (min_node == NULL) {     // all nodes are visited
        return 1;
    }


    node_distance = min_node->distance;

    // find the minimum and also unvisited node
    for (int i = 0; i < NODE_COUNT; i++) {
        if (node_list[i]->visited == 0 && node_distance > node_list[i]->distance) {
            min_node = node_list[i];
            node_distance = min_node->distance;
        }
    }


    Dictionary *dictionary = min_node->dictionary;
    Node *target_node = NULL;
    int vector_to_target;


    while (dictionary != NULL) {
        target_node = dictionary->node;
        vector_to_target = dictionary->distance;        // w(u, v)

        if (target_node->visited == 0)
            if (target_node->distance > node_distance + vector_to_target)   // d[v] > d[u] + w(u, v)
                target_node->distance = node_distance + vector_to_target;


        dictionary = dictionary->next;

    }


    table[iteration][0] = (int) min_node->character;

    for(int i = 1; i < NODE_COUNT + 1; i++) {
        table[iteration + 1][i] = node_list[i-1]->distance;
    }

    min_node->visited = 1;
    return calculate_distances(node_list, table, iteration + 1);

}





void print_path(int table[][NODE_COUNT + 1], char name) {
    int column;

    printf("%c",name);

    for (int i = 1; i < NODE_COUNT+1; i++) {
        if (table[0][i] == (int) name)
            column = i;
    }

    for (int row = NODE_COUNT; row > 1; row--) {
        if (table[row][column] == table[row - 1][column])
            continue;
        else {

            printf(" <= %c", table[row - 1][0]);

            // new column
            for (int i = 1; i < NODE_COUNT+1; i++)
                if (table[0][i] == table[row - 1][0])
                    column = i;
        }
    }

    printf("\n");

}





void print_table(int table[][NODE_COUNT + 1]) {
    for (int i = 0; i < NODE_COUNT + 1; i++) {

        for (int j = 0; j < NODE_COUNT + 1; j++) {

            if (j == 0 || i == 0)
                printf("%6c |",  table[i][j]);
            else {
                if (table[i-1][j] == table[i][j] &&  table[i][j] != INFINITY)
                    printf("       |");
                else
                    printf("%6d |", table[i][j]);
            }
        }
        printf("\n");
    }
}

