# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct treenode_t *Tree;

struct treenode_t {
    int key;
    Tree left;
    Tree right;
    int height;
};

Tree newTree(int key) {
    Tree tree = (Tree) calloc(1, sizeof(struct treenode_t));
    tree->key = key;
    tree->height = 1; // A node is assigned at a leaf
    return tree;
}

int max(int a, int b) {
    return a > b? a : b;
}

int findHeight(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    int leftHeight = findHeight(tree->left);
    int rightHeight = findHeight(tree->right);
    return max(leftHeight, rightHeight) + 1;
}
int isBalancedTreeHelper(Tree tree, int *pIsBalanced) 
{
    if (tree == NULL) {
        return 0;
    }
    int leftHeight = isBalancedTreeHelper(tree->left, pIsBalanced);
    int rightHeight = isBalancedTreeHelper(tree->right, pIsBalanced);
    int balanceFactor = leftHeight - rightHeight;
    if (balanceFactor < -1 || balanceFactor > 1) {
        *pIsBalanced = 0;
    }
    return max(leftHeight, rightHeight) + 1;
}
int isBalancedTree(Tree tree) {
    int isBalanced = 1;
    isBalancedTreeHelper(tree, &isBalanced);
    return isBalanced;
}

int getHeight(Tree tree) {
    return tree == NULL ? 0 : tree->height;
}

/*
        x                        y
       / \     rotateRight(x)   / \
      /   \                    /   \
     y    T3        ===>      T1    x
    / \                            / \
   /   \                          /   \
  T1   T2                        T2    T3
*/

Tree rotateRight(Tree tree) {
    printf("rotateRight(%d)\n", tree->key);
    Tree x = tree;
    Tree y = x->left;
    //Tree T1 = y->left;
    Tree T2 = y->right;
    //Tree T3 = x->right;
    // Now rotate right
    y->right = x;
    x->left = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}


Tree rotateLeft(Tree tree) {
    printf("rotateLeft(%d)\n", tree->key);
    Tree x = tree;
    Tree y = x->right;
    //Tree T1 = x->left;
    Tree T2 = y->left;
    //Tree T3 = y->right;

    x->right = T2;
    y->left = x;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Tree insertIntoBST(Tree tree, int key) {
    if (tree == NULL) {
        return newTree(key);
    } else if (key < tree->key) { // go left
        printf("BST~insert>> Going left at %d to insert %d\n", tree->key, key);
        tree->left = insertIntoBST(tree->left, key);
    } else if (key > tree->key) { // go right
        printf("BST~insert>> Going right at %d to insert %d\n", tree->key, key);
        tree->right = insertIntoBST(tree->right, key);
    } else { // tree-> == key
        printf("BST~insert>> Duplicate key %d\n");
        return tree;
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    return tree;
}

Tree insertIntoAVLTree(Tree tree, int key) {
    if (tree == NULL) {
        return newTree(key);
    } else if (key < tree->key) { // go left
        printf("AVL~insert>> Going left at %d to insert %d\n", tree->key, key);
        tree->left = insertIntoAVLTree(tree->left, key);
    } else if (key > tree->key) { // go right
        printf("AVL~insert>> Going right at %d to insert %d\n", tree->key, key);
        tree->right = insertIntoAVLTree(tree->right, key);
    } else { // tree-> == key
        printf("AVL~insert>> Duplicate key %d\n");
        return tree;
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    int balanceFactor = getHeight(tree->left) - getHeight(tree->right);
    // Left left
    if (balanceFactor > 1 && key < tree->left->key) {
        printf("AVL~insert>> LL at %d while inserting %d\n", tree->key, key);
        return rotateRight(tree);
    }
    // Left Right
    if (balanceFactor > 1 && key > tree->left->key) {
        printf("AVL~insert>> LR at %d while inserting %d\n", tree->key, key);
        tree->left = rotateLeft(tree->left);
        return rotateRight(tree);
    }
    // Right Right
    if (balanceFactor < -1 && key > tree->right->key) {
        printf("AVL~insert>> RR at %d while inserting %d\n", tree->key, key);
        return rotateLeft(tree);
    }
    // Right Left
    if (balanceFactor < -1 && key < tree->right->key) {
        printf("AVL~insert>> RL at %d while inserting %d\n", tree->key, key);
        tree->right = rotateRight(tree->right);
        return rotateLeft(tree);
    }
    return tree;
}

Tree findMinTreeInBST(Tree tree) {
    for (; tree && tree->left; tree = tree->left)
        ;
    return tree;
}

int getBalanceFactor(Tree tree) {
    return tree == NULL ? 0 : getHeight(tree->left) - getHeight(tree->right);
}

Tree deleteFromBST(Tree tree, int key) {
    if (tree == NULL) {
        printf("BST~delete>> Key %d is not found\n", key);
        return NULL;
    } else if (key < tree->key) {
        printf("BST~delete>> Going left at %d to delete %d\n", tree->key, key);
        tree->left = deleteFromBST(tree->left, key);
    } else if (key > tree->key) {
        printf("BST~delete>> Going right at %d to delete %d\n", tree->key, key);
        tree->right = deleteFromBST(tree->right, key);
    } else {
        if (tree->left == NULL && tree->right == NULL) {
            printf("BST~delete>> Both the subtrees are NULL at %d\n", tree->key, key);
            free(tree);
            return NULL;
        } else if (tree->left && tree->right == NULL) {
            printf("BST~delete>> The right subtree is NULL at %d\n", tree->key, key);
            Tree tempTree = tree;
            tree = tree->left;
            free(tempTree);
        } else if (tree->left == NULL && tree->right) {
            printf("BST~delete>> The left subtree is NULL at %d\n", tree->key, key);
            Tree tempTree = tree;
            tree = tree->right;
            free(tempTree);
        } else {
            Tree tempTree = findMinTreeInBST(tree->right);
            printf("BST~delete>> Need to delete %d to delete %d\n", tempTree->key, key);
            tree->key = tempTree->key;
            tree->right = deleteFromBST(tree->right, tempTree->key);
        }
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    return tree;
}

Tree deleteFromAVLTree(Tree tree, int key) {
    if (tree == NULL) {
        printf("AVL~delete>> Key %d is not found\n", key);
        return NULL;
    } else if (key < tree->key) {
        printf("AVL~delete>> Going left at %d to delete %d\n", tree->key, key);
        tree->left = deleteFromAVLTree(tree->left, key);
    } else if (key > tree->key) {
        printf("AVL~delete>> Going right at %d to delete %d\n", tree->key, key);
        tree->right = deleteFromAVLTree(tree->right, key);
    } else {
        if (tree->left == NULL && tree->right == NULL) {
            printf("AVL~delete>> Both the subtrees are NULL at %d\n", tree->key, key);
            free(tree);
            return NULL;
        } else if (tree->left && tree->right == NULL) {
            printf("AVL~delete>> The right subtree is NULL at %d\n", tree->key, key);
            Tree tempTree = tree;
            tree = tree->left;
            free(tempTree);
        } else if (tree->left == NULL && tree->right) {
            printf("AVL~delete>> The left subtree is NULL at %d\n", tree->key, key);
            Tree tempTree = tree;
            tree = tree->right;
            free(tempTree);
        } else {
            Tree tempTree = findMinTreeInBST(tree->right);
            printf("AVL~delete>> Need to delete %d to delete %d\n", tempTree->key, key);
            tree->key = tempTree->key;
            tree->right = deleteFromAVLTree(tree->right, tempTree->key);
        }
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;

    int balanceFactor = getBalanceFactor(tree);

    // Left left
    if (balanceFactor > 1 && getBalanceFactor(tree->left) >= 0) {
        printf("AVL~delete>> LL at %d while inserting %d\n", tree->key, key);
        return rotateRight(tree);
    }
    // Left right
    if (balanceFactor > 1 && getBalanceFactor(tree->left) < 0) {
        printf("AVL~delete>> LR at %d while inserting %d\n", tree->key, key);
        tree->left = rotateLeft(tree->left);
        return rotateRight(tree);
    }
    // Right right
    if (balanceFactor < -1 && getBalanceFactor(tree->right) <= 0) {
        printf("AVL~delete>> RR at %d while inserting %d\n", tree->key, key);
        return rotateLeft(tree);
    }
    // Right left
    if (balanceFactor < -1 && getBalanceFactor(tree->right) > 0) {
        printf("AVL~delete>> RL at %d while inserting %d\n", tree->key, key);
        tree->right = rotateRight(tree->right);
        return rotateLeft(tree);
    }

    return tree;
}

void inorder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    inorder(tree->left);
    printf("%d ", tree->key);
    inorder(tree->right);
}

void driver1() {
    int a[] = {9, 35, 70, 0, 78, 71, 72, 84, 66, 56, 88, 15};
    //int a[] = {1, 2, 3 ,4, 5 , 6, 7, 8, 9, 10, 11, 12};
    int n = 12;
    Tree tree = NULL;
    for (int i = 0; i < n; i++) {
        printf("Inserting %d\n", a[i]);
        tree = insertIntoAVLTree(tree, a[i]);
        inorder(tree);
        printf(" --> %d\n\n", isBalancedTree(tree));
    }

    printf("Tree creation complete!\n\n");
    printf("Press a key to continue...");
    getchar();
    for (int i = 0; i < n; i++) {
        printf("Deleting %d\n", a[i]);
        tree = deleteFromAVLTree(tree, a[i]);
        inorder(tree);
        printf(" --> %d\n\n", isBalancedTree(tree));
    }
}

# define COMPACT

int _print_t(Tree tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->key);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
} else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';
} else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

void print_t(Tree tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}


void driver2() {
    Tree bst = NULL;
    Tree avl = NULL;
    char command[80];
    while (1) {
        printf("[bs-avl@tree ~]$ ");
        scanf("%s", command);
        if (strcmpi(command, "exit") == 0) {
            break;
        } else if (strcmpi(command, "insert") == 0) {
            int key = 0;
            scanf("%d", &key);
            bst = insertIntoBST(bst, key);
            avl = insertIntoAVLTree(avl, key);
        } else if (strcmpi(command, "delete") == 0) {
            int key = 0;
            scanf("%d", &key);
            bst = deleteFromBST(bst, key);
            avl = deleteFromAVLTree(avl, key);
        } else if (strcmpi(command, "print") == 0) {
            scanf("%s", command);
            if (strcmpi(command, "avl") == 0) {
                print_t(avl);
            } else if (strcmpi(command, "bst") == 0) {
                print_t(bst);
            }
        }
    }
}


int main(int argc, char *argv[]) {
    driver1();
    return 0;
}
