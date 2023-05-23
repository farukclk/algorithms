// tek yonlu node
typedef struct node {
    int data;
    struct node *next;
} Node;


// cift yonlu node
typedef struct node2 {
    int data;
    struct node2 *prev;
    struct node2 *next;
} Node2;


// binary tree node
typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

