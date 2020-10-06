/*
Tree:
*InOrder
*PreOrder
*PostOrdder
*Given infix and postfix, generate a tree
#Given infix and prefix, generate a tree
InOrder - with stack
*Find min
*Fin max
*Find a node
*Find height
*Create the mirror of a tree
*Make a clone of a tree
*Compare two trees
Delete a tree
BST:
*Insertion - recursive
*Insertion - iterative
*Find a node - recursive
*Find a node -iterative
Deletion
*Find max
*Find min
*Find predecessor
Find successor
*/
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct binary_tree_node_t *Tree;
typedef void (*VoidIntFunction) (int);

# define PRINTPARENTS
# undef  PRINTPARENTS

struct binary_tree_node_t {
    int key;
    Tree parent;
    Tree left;
    Tree right;
};

Tree newTree(int key, Tree parent, Tree left, Tree right) {
    Tree tree = (Tree) calloc (1, sizeof(struct binary_tree_node_t));
    tree->key = key;
    tree->parent = parent;
    tree->left = left;
    tree->right = right;
    return tree;
}

int toInt(Tree tree) {
    return tree == NULL ? 0 : tree->key;
}

void inOrder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    inOrder(tree->left);
    # ifdef PRINTPARENTS
        printf("%d[%d] ", tree->key, toInt(tree->parent));
    # else
        printf("%d ", tree->key);
    # endif
    inOrder(tree->right);
}


//void inOrderOperation(Tree tree, void (*f)(int)) {
void inOrderOperation(Tree tree, VoidIntFunction f) {
    if (tree == NULL) {
        return;
    }
    inOrderOperation(tree->left, f);
    f(tree->key);
    inOrderOperation(tree->right, f);
}

void preOrder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    printf("%d ", tree->key);
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%d ", tree->key);
}

void printSquare(int x) {
    printf("%d ", x * x);
}

int searchIndex(int *in, int key, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == key) {
            return i;
        }
    }
    return -1;
}

Tree buildTreeHelper(int *in, int *post, int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    Tree tree = newTree(post[*postIndex], NULL, NULL, NULL);
    (*postIndex)--;
    int index = searchIndex(in, tree->key, inStart, inEnd);
    tree->right = buildTreeHelper(in, post, index + 1, inEnd, postIndex);
    tree->left = buildTreeHelper(in, post, inStart, index - 1, postIndex);
    return tree;
}

void fixParents(Tree tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->left) {
        tree->left->parent = tree;
        fixParents(tree->left);
    }
    if (tree->right) {
        tree->right->parent = tree;
        fixParents(tree->right);
    }
}

Tree buildTree(int *in, int *post, int n) {
    int postIndex = n - 1;
    Tree tree = buildTreeHelper(in, post, 0, n - 1, &postIndex);
    fixParents(tree);
    return tree;
}

void printTree(Tree tree) {
    printf("Preorder:  ");
    preOrder(tree);
    printf("\n");
    printf("Inorder:   ");
    inOrder(tree);
    printf("\n");
    printf("Postorder: ");
    postOrder(tree);
    printf("\n");
}


int toIntForMin(Tree tree) {
    return tree == NULL ? INT_MAX : tree->key;
}

Tree findMinTree(Tree tree) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return tree;
    }
    Tree leftMinTree = findMinTree(tree->left);
    Tree rightMinTree = findMinTree(tree->right);
    if (toIntForMin(leftMinTree ) > toIntForMin(tree) &&
        toIntForMin(rightMinTree) > toIntForMin(tree)) {
        return tree;
    } else if (toIntForMin(leftMinTree) < toIntForMin(tree) &&
               toIntForMin(leftMinTree) < toIntForMin(rightMinTree)) {
        return leftMinTree;
    } else {
        return rightMinTree;
    }
}

Tree findMaxTree(Tree tree) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return tree;
    }
    Tree leftMaxTree = findMaxTree(tree->left);
    Tree rightMaxTree = findMaxTree(tree->right);
    if (toInt(leftMaxTree ) < toInt(tree) &&
        toInt(rightMaxTree) < toInt(tree)) {
        return tree;
    } else if (toInt(leftMaxTree) > toInt(tree) &&
               toInt(leftMaxTree) > toInt(rightMaxTree)) {
        return leftMaxTree;
    } else {
        return rightMaxTree;
    }
}

Tree findTree(Tree tree, int key) {
    if (tree == NULL || tree->key == key) {
        return tree;
    }
    Tree found = findTree(tree->left, key);
    if (!found) {
        return findTree(tree->right, key);
    }
    return found;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int findHeight(Tree tree) {
    if (tree == NULL) {
        return -1;
    }
    return max(findHeight(tree->left), findHeight(tree->right)) + 1;
}

Tree createMirrorHelper(Tree tree) {
    if (tree == NULL) {
        return NULL;
    }
    Tree tempTree = newTree(tree->key, NULL, NULL, NULL);
    tempTree->left = createMirrorHelper(tree->right);
    tempTree->right = createMirrorHelper(tree->left);
    return tempTree;
}

Tree createMirror(Tree tree) {
    tree = createMirrorHelper(tree);
    fixParents(tree);
    return tree;
}

Tree cloneHelper(Tree tree) {
    if (tree == NULL) {
        return NULL;
    }
    Tree tempTree = newTree(tree->key, NULL, NULL, NULL);
    tempTree->left = cloneHelper(tree->left);
    tempTree->right = cloneHelper(tree->right);
    return tempTree;
}

Tree clone(Tree tree) {
    tree = cloneHelper(tree);
    fixParents(tree);
    return tree;
}

int compareTrees(Tree tree1, Tree tree2) {
    if (!tree1 && !tree2) {
        return 1;
    }
    if (( tree1 && !tree2) ||
        (!tree1 &&  tree2)) {
        return 0;
    }
    return (tree1->key == tree2->key) &&
            compareTrees(tree1->left,  tree2->left) &&
            compareTrees(tree1->right, tree2->right);
}

Tree deleteTree(Tree tree) {
    if (tree == NULL) {
        return NULL;
    }
    deleteTree(tree->left);   //A postOrder deletion
    deleteTree(tree->right);
    free(tree);
    return NULL;
}

/*    Two way of using recursion in trees as of line no. (284&340)
in insert(284) returned node is the root node or the parent node of the process
while in findTree returned node is the leaf node or the end node*/

Tree insertIntoBSTHelper(Tree tree, int key, Tree parent) {//parent is used as root nd leaf nodes will have varied parents
    if (!tree) {
        return newTree(key, parent, NULL, NULL);
    }
    if (tree->key > key) {
        tree->left = insertIntoBSTHelper(tree->left, key, tree);
    } else {
        tree->right = insertIntoBSTHelper(tree->right, key, tree);
    }
    return tree;
}

Tree insertIntoBST(Tree tree, int key) {
    return insertIntoBSTHelper(tree, key, NULL);
}

Tree insertIntoBSTIterative(Tree tree, int key) {
    Tree lastTree = NULL, root = tree;
    while (tree) {
        if (tree->key > key) {
            lastTree = tree;
            tree = tree->left;
        } else {
            lastTree = tree;
            tree = tree->right;
        }
    }
    if (lastTree) {
         if (lastTree->key > key) {
            lastTree->left = newTree(key, lastTree, NULL, NULL);
        } else {
            lastTree->right = newTree(key, lastTree, NULL, NULL);
        }
        return root;
    } else {
        return newTree(key, NULL, NULL, NULL);
    }
}

int driver1() {
    struct binary_tree_node_t t;
    Tree tree = newTree(1, NULL, NULL, NULL);
    tree->left = newTree(2, tree, NULL, NULL);
    tree->left->left = newTree(3, tree->left, NULL, NULL);
    tree->left->right = newTree(4, tree->left, NULL, NULL);
    tree->right = newTree(5, tree, NULL, NULL);
    printTree(tree);
    inOrderOperation(tree, printSquare);
    printf("\n");
    int in[] = {7, 90, 3,  11, 43, 5, 12, 21, 8, 10};
    int post[] = {7, 90, 11, 5, 43, 3, 21, 10, 8, 12};
    tree = buildTree(in, post, 10);
    printTree(tree);
    return 0;
}

Tree findTreeInBST(Tree tree, int key) {
    if (tree == NULL || tree->key == key) {
        return tree;
    }
    if (tree->key > key) {
        return findTreeInBST(tree->left, key);
    } else {
        return findTreeInBS
         T(tree->right, key);
    }
}

Tree findTreeInBSTIterative(Tree tree, int key) {
    while (tree) {
        //printf("%d == %d-> %d\n", key,  tree->key, tree->key == key);
        if (tree->key == key) {
            return tree;
        } else if (tree->key > key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return NULL;
}

Tree findMinTreeInBST(Tree tree) {
    while (tree && tree->left) {
        tree = tree->left;
    }
    return tree;
}

Tree findMaxTreeInBST(Tree tree) {
    while (tree && tree->right) {
        tree = tree->right;
    }
    return tree;
}

Tree findPredecessorInBST(Tree tree) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->left) {
        return findMaxTreeInBST(tree->left);
    }
    Tree parent = tree->parent;
    while (parent && parent->left == tree) {
        tree = parent;
        parent = tree->parent;
    }
    return parent;
}

Tree findSuccessorInBST(Tree tree) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->right) {
        return findMaxTreeInBST(tree->right);
    }
    Tree parent = tree->parent;
    while (parent && parent->right == tree) {
        printf("At: %d\n", tree->key);
        tree = parent;
        parent = tree->parent;
    }
    return parent;
}

Tree deleteKey(Tree tree, int key) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->key > key) {
        tree->left = deleteKey(tree->left, key);
    } else if (tree->key < key){
        tree->right = deleteKey(tree->right, key);
    } else {
        // tree->key == key
        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            return NULL;
        } else if (tree->left && tree->right == NULL) {
            Tree leftTree = tree->left;
            leftTree->parent = tree->parent;
            free(tree);
            return leftTree;
        } else if (tree->left == NULL && tree->right) {
            Tree rightTree = tree->right;
            rightTree->parent = tree->parent;
            free(tree);
            return rightTree;
        } else {
            Tree smallest = findMinTreeInBST(tree->right);
            tree->key = smallest->key;
            tree->right = deleteKey(tree->right, smallest->key);
            return tree;
        }
    }
}

int driver2() {
    int in[] = {8, 4, 9, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    Tree tree = buildTree(in, post, 9);
    printTree(tree);
    printTree(findMinTree(tree));
    printTree(findMaxTree(tree));
    printTree(findTree(tree, 3));
    printf("Height: %d\n", findHeight(findTree(tree, 2)));
    Tree mirror = createMirror(tree);
    printTree(mirror);
    Tree cloneTree = clone(tree);
    printTree(cloneTree);
    printf("%d %d\n", compareTrees(tree, cloneTree), compareTrees(tree, mirror));
    Tree dangling = cloneTree;
    cloneTree = deleteTree(cloneTree);
    printTree(dangling);
}

int main(int argc, char *argv[]) {
    int n = 9; //8;//10;
    int roll[] = {90, 21, 98, 35, 9, 49, 84, 66, 97};// 65, 64, 63, 62};//, 10, 93};
    Tree tree = NULL;
    for (int i = 0; i < n; i++) {
        //tree = insertIntoBST(tree, roll[i]);
        tree = insertIntoBSTIterative(tree, roll[i]);
        printTree(tree);
    }
    //insertIntoBST(findTree(tree, 35), 120);
    //printTree(tree);
    printf("Here\n");
    printTree(findTreeInBSTIterative(tree, 66));
    printTree(findMinTreeInBST(tree));
    printTree(findMaxTreeInBST(tree));
        //printTree(findPredecessorInBST(findTreeInBST(tree, 62)));
    printf("Here 2\n");
    //printTree(findSuccessorInBST(findTreeInBST(tree, 84)));
    printTree(deleteKey(tree, 90));
}
