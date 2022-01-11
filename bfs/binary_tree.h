typedef int myType;

typedef struct treeNode {
    myType element;     //值域元素
    struct treeNode *lchild;    //左孩子
    struct treeNode *rchild;    //右孩子
} Btree;

void createTree(Btree **T);

void preOrder(Btree *T);

void inOrder(Btree *T);

void postOrder(Btree *T);

int bfsMinDepth(Btree *T);

