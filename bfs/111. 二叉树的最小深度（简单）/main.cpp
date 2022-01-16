#include <stdio.h>
#include "binary_tree.h"

int main() {
    Btree *root;
    createTree(&root);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    printf("the binary tree min depth is :%d\n", bfsMinDepth(root));
}