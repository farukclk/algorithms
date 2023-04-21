#include <stdio.h>
#include "mathematic.h"

// binary tree node
typedef struct treeNode {
    int sayi;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;



int get_level(int length);                     // calculate level of full and complate binary trees using number of items
int get_level_of(TreeNode *root);              // calculate level of binary tree
int get_root_index(int length);                // return root index as a full or complate binary tree
TreeNode *tree(int array[], int length);       // generate binary tree from int array[]
void print_tree(TreeNode *root);
int aralikta_olmayan_eleman_sayisi(TreeNode *root, int min, int max);



// calculate the level of binary tree using item number
// dependents: uslu_sayi()
int get_level(int length) {
    int level = 0;

    while(1) {
        if (length < uslu_sayi(2 , level)) {
            level--;
            break;
        }
        else
            level++;
    }
    return level;
}



// calculate the level of binary tree
int get_level_of(TreeNode *root) {
    int right, left;
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



// print level by level from (int level) to root (0)
//   you have to set up tmpLevel as 0 when you call this function.
// printLevel(root, 0, get_level_of(root);
// dependents: get_level_of()
void print_level(TreeNode *root, int tmpLevel, int level) {

    // print leaf
    if (tmpLevel == level) {
        printf("%d  ",root->sayi);
    }

    else if (tmpLevel < level) {

        if (root->left != NULL) {
            print_level(root->left, tmpLevel + 1 , level);
        }

        if (root->right !=NULL ) {
            print_level(root->right, tmpLevel + 1, level);
        }


        /* this block runs only on the root node. */
        if (tmpLevel == 0) {
            print_level(root, 0, level - 1);  // items which level equals level has been writed, now write (level -1 ) items
        }

    }
}





// calculate the root index of sorted list using length
// bagimliliklar: uslu_sayi()
int getRootIndex(int length) {
    if (length == 1)
        return 0;


    int index;
    int ust_ucgen_eleman_sayisi;  // level -1 e kadar olan tum elemanlar toplami

    int level = get_level(length); // eleman sayisindan binary tree levelini hesapla

    ust_ucgen_eleman_sayisi = uslu_sayi(2, level ) -1;

    // System.out.println("level :" +level);
    //System.out.println("ust ucgen eleman sayi: "  +ust_ucgen_eleman_sayisi);

    if ((length - ust_ucgen_eleman_sayisi ) > uslu_sayi(2, level-1) ) {
        index = (ust_ucgen_eleman_sayisi-1) / 2 + uslu_sayi(2,level-1);
    }
    else {
        index = (ust_ucgen_eleman_sayisi-1) /2 + (length-ust_ucgen_eleman_sayisi);
    }

    return index;
}



// sirali bir int array[] i  binary tree ye donustur
TreeNode *tree(int dizi[], int length) {

    if (length < 0)
        return 0;

    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));

    if (length == 1) {
        root->sayi = dizi[0];
        root->left = NULL;
        root->right = NULL;
    }
    else if (length == 2) {
        root->sayi = dizi[1];

        TreeNode *left = (TreeNode*) malloc(sizeof(TreeNode));
        left->sayi = dizi[0];
        left->left = NULL;
        left->right = NULL;

        root->left = left;
        root->right = NULL;
    }
    else { // 3 ve uzeri

        int root_index = getRootIndex(length);
        root->sayi = dizi[root_index];

        // root a gore
        int *sol_dizi = (int *) malloc(sizeof(int));
        int *sag_dizi = (int *) malloc(sizeof(int));

        int key = 0, sol_index=0, sag_index =0;

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

        root->left = tree(sol_dizi, sol_index);
        root->right = tree(sag_dizi, sag_index);
    }
    return root;
}



// print tree from root
void printTree(TreeNode *root) {
    if (root == NULL)
        return;

    printf("  %d   \n", root->sayi);
    printTree(root->left);
    printTree(root->right);

}



// binary tree deki 2 sayi asarisnda olmayan eleman sayisini bul
int aralikta_olmayan_eleman_sayisi(TreeNode *root, int min, int max) {
    if (root == NULL)
        return 0;

    int sonuc = 0;

    if(root->sayi < min  || root->sayi > max)
        sonuc++;


    sonuc += aralikta_olmayan_eleman_sayisi(root->left, min, max);
    sonuc += aralikta_olmayan_eleman_sayisi(root->right, min, max);

    return sonuc;

}
