#include "include/tree.h"



int main() {

    int a[7] = {1,-20,11,22,11,23,-2};

    TreeNode *treeNode = create_BST(a, 7);

    print_tree(treeNode );

}
