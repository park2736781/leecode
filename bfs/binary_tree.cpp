#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "binary_tree.h"

void createTree(Btree **T)  //传入一个Btree的指针的地址
{
    myType data;
    scanf("%d", &data);

    if (data == -1) {    //-1代表终端节点值
        *T = NULL;
    } else {
        *T = (Btree *) malloc(sizeof(struct treeNode));
        (*T)->element = data;
        printf("请输入%d的左孩子节点：", data);
        createTree(&((*T)->lchild));
        printf("请输入%d的右孩子节点：", data);
        createTree(&((*T)->rchild));
    }
}

void preOrder(Btree *T) {
    if (T != NULL) {
        printf("%d ", T->element);  //访问根节点
        preOrder(T->lchild);    //先根序遍历左子树
        preOrder(T->rchild);    //先根序遍历右子树
    }
}

void inOrder(Btree *T) {
    if (T != NULL) {
        inOrder(T->lchild);     //中根序遍历左子树
        printf("%d ", T->element);  //访问根节点
        inOrder(T->rchild); //中根序遍历右子树
    }
}

void postOrder(Btree *T) {
    if (T != NULL) {
        postOrder(T->lchild);   //后根序遍历左子树
        postOrder(T->rchild);   //后根序遍历右子树
        printf("%d ", T->element);  //访问根节点
    }
}

int bfsMinDepth(Btree *T) {
    if (T == NULL) return 0;
    std::queue<Btree *> q;
    q.push(T);
    int depth = 1;
    while (!q.empty()) {
        int listSize = q.size();
        for (int i = 0; i < listSize; i++) {
            Btree *cur = q.front();
            q.pop();
            if (cur->lchild == NULL && cur->rchild == NULL) {
                return depth;
            }
            if (cur->lchild != NULL) {
                q.push(cur->lchild);
            }
            if (cur->rchild != NULL) {
                q.push(cur->rchild);
            }
        }
        depth++;
    }
    return depth;
}