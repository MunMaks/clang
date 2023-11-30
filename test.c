#include <stdio.h>
#include <stdlib.h>  // malloc(), calloc(), realloc()...

// Definir une structure pour les arbres
typedef struct node{
    unsigned int val;
    struct node *left;
    struct node *right;
} TreeNode;


// La creation des nodes
TreeNode* createNode(int value) {
    TreeNode* newNode = (struct node *)malloc(sizeof(struct node));
    // On peut ajouter la vérification si on a bien alloué la mémoire
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder traversal arbre
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

// 1 "key" dans arbre, 0 "key" n'est pas dans arbre
int searchNode(TreeNode *tree, unsigned int key)
{
    while(tree){
        if (key == tree->val) return 1;
        
        if (key > tree->val) tree = tree->right;
        else tree = tree->left;
    }
    return 0;
}


// libérer la mémoire
void freeTree(TreeNode* root) {
    if (root != NULL) {  // on supprime d'abord les nodes qui n'ont pas d'enfants
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(int argc, char* argv[]) {
    
    TreeNode* root = createNode(1);
    root->left = createNode(2);  // à gauche
    root->right = createNode(3); // à droite
    root->left->left = createNode(4);  // à gauche - à droite
    root->left->right = createNode(5);  // à gauche - à gauche

    printf("Inorder traversal arbre: ");
    inorderTraversal(root);
    
    // In a real-world scenario, you might want to implement a more sophisticated memory management system
    freeTree(root);
    return 0;
}
