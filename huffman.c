#include <malloc.h> 
#include <stdio.h>
#include "include/string.h"


typedef struct tree_node {
    char data;
    unsigned int freq;
    struct tree_node *left;
    struct tree_node *right;
} Tree;


typedef struct queue_node {
    struct tree_node *data;
    struct queue_node *next;
} Queue;



Queue *push(Queue *queue, Tree *tree);
void print_level(Tree *root, int level, int tmpLevel);
int get_level_of(Tree *root);
void print_tree(Tree *root);
int get_code(char *bits, Tree *tree, char character, int bit);

int main(void) {


    char text[] = "aaaaabbc";



    int text_length  = str_len(text);
    char unique_chars[256];           // text dizindeki benzersiz karakterler
    int unique_char_length = 0;
    char tmp_char;
    int tmp_int;

    for(int i = 0; i < text_length; i++) {
    
        tmp_char = text[i];
    
        if (! str_contains(unique_chars, tmp_char))
            unique_chars[unique_char_length++] = tmp_char;       // yazilanlara harflere kaydet

    }
    text[text_length] = '\0';                           // sorun cikmamasi icin onlem
    unique_chars[unique_char_length] = '\0';            //




    // frekans degerlerini hesapla
    int freq[unique_char_length];                        // fekans deger dizisi
    int tmp_freq[256];                                   // gecici frekans derger dizisi

    // gecici dizinin tum elemanlarını 0 yap
    for(int i=0; i < 256; i++)
        tmp_freq[i] = 0;

    for(int i =0; i < text_length; i++)
        tmp_freq[text[i]]++;

    tmp_int = 0;

    for (int i=0; i < 256; i++) {
        if (tmp_freq[i] != 0) {
            freq[tmp_int++] = tmp_freq[i];
        }
    }



    // harflerin frekanslarini ekrana yaz
    printf("\n---------------frekans degerleri: \n");
    for(int i = 0; i < unique_char_length; i++) {
            printf("%c: %d\n", unique_chars[i], freq[i]);     
    }



    Queue *priority_queue = NULL;
    Tree *tree = NULL;
    Tree *left = NULL, *right = NULL, *mid = NULL;

    // oncelik kuyruguna tum elemanlari ekle
    for (int i=0; i < unique_char_length; i++) {
        tree = (Tree*) malloc(sizeof(Tree));
        tree->data = unique_chars[i];
        tree->freq = freq[i];
        tree->left = NULL;
        tree->right = NULL;
        priority_queue = push(priority_queue, tree);
    }



    // oncelik sirasinda son bir tane node kalana kadar birlestirme islemi yap
    while (priority_queue->next != NULL) {

        left = priority_queue->data;
        right = priority_queue->next->data;
        priority_queue = priority_queue->next->next;

        mid = (Tree*) malloc(sizeof (Tree));             // yeni bir bellek alani olusturulması gerek
        mid->data = '-';
        mid->freq = left->freq + right->freq;
        mid->left = left;
        mid->right = right;

        priority_queue = push(priority_queue, mid);
    }

    tree = priority_queue->data;                            // oncelik kuyrugundaki kalan son nodu agac root unu tanımla



    printf("\n----------------agac yapisi (level order): \n");
    print_tree(tree);                                       // olusan agac yapisini ekrana yazdir




    printf("\n----------------Karakter huffman codu:\n");

    char bits[8];
    for (int i = 0; i < unique_char_length; i++) {
        get_code(bits, tree, unique_chars[i], 0);
        printf("%c: %s\n", unique_chars[i], bits);
    
    }



    printf("\ntext: %s\n", text);
    printf("encoded text: ");
     for(int i = 0; i < text_length; i++) {
        get_code(bits, tree, text[i], 0);
        printf("%s",bits);                       // her harfin kodunu sirayla yaz       
    }
    printf("\n");


}

// start bit = 0
int get_code(char *bits, Tree *tree, char character, int bit) {

    if (tree == NULL)
        return 0;

    else if (bit >= 8) {    // max bits num for one encoded chars
        bits[0] = '\0';
        return 0;
    }
    //---------

    if (bit == 0 ) {
        bits[0] = '\0';
    }


    if (tree->data == character) {
        bits[bit] = '\0';
        return 1;           // bulundu
    }

    else {

        bits[bit] = '0';
        bits[bit + 1] = '\0';

        if (get_code(bits, tree->left, character, bit + 1) == 0) {
            bits[bit] = '1';
            bits[bit + 1] = '\0';
            return get_code(bits, tree->right, character, bit + 1);
        }

        return 1;        
    }
}




// elemani frekans degerlerine gore sira bozulmicak sekilde ekler
// dusuk frekanstan yuksege dogru
Queue *push(Queue *queue, Tree *tree) {
    Queue *tmp = (Queue*) malloc(sizeof(Queue));
    tmp->data = tree;
    tmp->next = NULL;

    if (queue == NULL) {
        return tmp;
    }

    else if (queue->data->freq > tree->freq) {
        tmp->next = queue;
        queue = tmp;
    }

    else {
        queue->next = push(queue->next, tree);
    }

    return queue;
}




// print items base level order
// you have to set up tmpLevel as 0 when you call this function.
// dependents: get_level_of()
void print_tree(Tree *root) {

    int level =  get_level_of(root);

    for (int i = 0; i <=  level; i++) {
        print_level(root, i, 0);
        printf("\n");
    }

}


// calculate the level of binary tree
int get_level_of(Tree *root) {
    int right = 0, left = 0;
    if (root->left == NULL  && root->right == NULL) {
        return 0;
    }

        // node has lest one child
    else {

        // calculate left fork
        if (root->left != NULL  ) {
            left = get_level_of(root->left);
        }

        //calculate right fork
        if (root->right != NULL) {
            right = get_level_of(root->right);
        }

        // select bigger one and increase 1
        if (left>right)
            return ++left;
        else
            return ++right;

    }
}



// print items by level
// you have to set up tmpLevel as 0 when you call this function.
void print_level(Tree *root, int level, int tmpLevel) {

    if (root == NULL)
        return;

    else if (tmpLevel == level) {
        printf("%c  ", root->data);
    }

    else {
        print_level(root->left, level, tmpLevel + 1);
        print_level(root->right, level,  tmpLevel + 1);
    }

}
