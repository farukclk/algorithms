#include <stdio.h>
#include "mathematic.h"
#include "sorting.h"



//---------------------------------------FUNCTIONS----------------------------------------

int aralikta_olmayan_eleman_sayisi(TreeNode *root, int min, int max);
TreeNode *create_BST(int *dizi, int length);
TreeNode *create_tree(int *dizi, int length);           // generate binary tree from int array[]
int length_of_BT(TreeNode *root);
int get_level(int length);                              // calculate level of full and complated binary trees using number of items
int get_level_of(TreeNode *root);                       // calculate level of binary tree
int get_root_index(int length);                         // return root index as a full or complate binary tree
void print_tree(TreeNode *root);                        // print binary tree level order
void print_tree2(TreeNode *root, int tmp, int level);
void print_level(TreeNode *root, int level, int tmp);
TreeNode *root_sil(TreeNode *tree);
//-----------------------------------------------------------------------------------------




// binary tree deki 2 sayi asarisnda olmayan eleman sayisini bul
int aralikta_olmayan_eleman_sayisi(TreeNode *root, int min, int max) {
    if (root == NULL)
        return 0;

    int sonuc = 0;

    if(root->data < min  || root->data > max)
        sonuc++;


    sonuc += aralikta_olmayan_eleman_sayisi(root->left, min, max);
    sonuc += aralikta_olmayan_eleman_sayisi(root->right, min, max);

    return sonuc;

}




TreeNode *create_BST(int *dizi, int length) {
    bubble_sort(dizi, length);
    return create_tree(dizi,length);
}




// calculate the tree level, using number of items
// dependents: pow_int()
int get_level(int length) {

    int level = 0;

    while (length > pow_int(2, level) -1) {
        level++;
    }

    return --level;

}




// calculate the level of binary tree
int get_level_of(TreeNode *root) {
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




// calculate the root index of sorted list using length
// bagimliliklar: pow_int()
int get_root_index(int length) {

    int index;
    int n = get_level(length);


    int ust_ucgen_root = (pow_int(2, n-1 +1) -1 -1) / 2;
    //printf("\nn: %d   ust ucen root: %d\n",n, ust_ucgen_root);


    int ust_ucgen_eleman_sayisi = pow_int(2, n -1 +1) - 1;

    if (length - ust_ucgen_eleman_sayisi >= pow_int(2, n -1))
        index = ust_ucgen_root + pow_int(2, n -1);
    else
        index = ust_ucgen_root + length - ust_ucgen_eleman_sayisi;

    return index;

}




// convert array to tree
// for binary search tree use any sort func before call this func
TreeNode *create_tree(int *dizi, int length) {

    if (length <= 0) {
        return NULL;
    }

    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));

    if (length == 1) {

        root->data = dizi[0];
        root->left = NULL;
        root->right = NULL;
    }
    else if (length == 2) {

        TreeNode *left = (TreeNode*) malloc(sizeof(TreeNode));
        left->data = dizi[0];
        left->left = NULL;
        left->right = NULL;

        root->data = dizi[1];
        root->left = left;
        root->right = NULL;
    }
    else { // 3 ve uzeri


        int root_index = get_root_index(length);

        root->data = dizi[root_index];


        int sol_dizi[root_index];
        int sag_dizi[length - root_index - 1];

        int sol_index = 0;
        int sag_index= 0;

        int key = 0;
        for (int i = 0; i < length; i++) {
            if (i == root_index) {
                key = 1;

            }
            else {
                if (key == 0) {
                    sol_dizi[sol_index++] = dizi[i];
                }
                else {
                    sag_dizi[sag_index++] = dizi[i];
                }
            }
        }
        
        root->left = create_tree(sol_dizi, sol_index);
        root->right = create_tree(sag_dizi, sag_index);
 
    }
    return root;
}




// return number of nodes
int length_of_BT(TreeNode *root) {

    if (root == NULL)
        return 0;

    int length = 1;    
  
    length += length_of_BT(root->left);
    length += length_of_BT(root->right);

    return length;
}




// print items by level 
// you have to set up tmpLevel as 0 when you call this function.
void print_level(TreeNode *root, int level, int tmpLevel) {

    // print leaf
    if (tmpLevel == level) {
        printf("%d  ",root->data);
    }

    else {
        if (root->left != NULL) {
            print_level(root->left, level, tmpLevel + 1);
        }

        if (root->right !=NULL ) {
            print_level(root->right, level,  tmpLevel + 1);
        }
    }
}




// print items base level order
// you have to set up tmpLevel as 0 when you call this function.
// dependents: get_level_of()
void print_tree(TreeNode *root) {

    int level =  get_level_of(root);

    for (int i = 0; i <=  level; i++) {
        print_level(root, i, 0);
        printf("\n");
    }

}




// print items as reverse level order
// you have to set up tmpLevel as 0 when you call this function.
// printLevel(root, 0, get_level_of(root);
// dependents: get_level_of()
void print_tree2(TreeNode *root, int tmpLevel, int level) {

    // print leaf
    if (tmpLevel == level) {
        printf("%d  ",root->data);
    }

    else if (tmpLevel < level) {

        if (root->left != NULL) {
            print_tree2(root->left, tmpLevel + 1 , level);
        }

        if (root->right !=NULL ) {
            print_tree2(root->right, tmpLevel + 1, level);
        }


        /* this block runs only on the root node. */
        if (tmpLevel == 0) {
            print_tree2(root, 0, level - 1);  // items which level equals level has been writed, now write (level -1 ) items
        }
    }
}




// heap sort icin
// agacin son elamınını keserek roota yapıstır
TreeNode *root_sil(TreeNode *root) {
    TreeNode *iter = root;

    int level = get_level_of(root);
    int ust_ucgen = pow_int(2, level) -1;
    int length = length_of_BT(root);

    // exception
    if (length == 1 ) {
        return NULL;
    }

    while (level > 1) { // en uc uclu elemana kadar ilerle

        if (length - ust_ucgen <= pow_int(2, level - 1)) {  // son eleman rootun solunda, sola git
            if (iter->left->left != NULL || iter->left->right != NULL) {
                iter = iter->left;
            }
        }
        else {  // son eleman rootun saginda, saga git
            if (iter->right->left != NULL || iter->right->right != NULL) {
                iter = iter->right;
            }
        }

        level = get_level_of(iter);
        ust_ucgen = pow_int(2, level) - 1;
        length = length_of_BT(iter);


    }

    // iki taraf bos
    if (iter->right != NULL) { // sag yapragi sil
        root->data = iter->right->data;  // son elemani root a kopyala
        iter->right = NULL;              // son elemanin yerini sil
    }

    // sag yaprak bos
    else if(iter->left != NULL) {
        root->data = iter->left->data;    // almost complated binary tree varsayıyoruz
        iter->left = NULL;
    }

    return root;

}