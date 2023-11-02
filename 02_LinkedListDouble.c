#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
}*LinkedListDLL;

// DLL = Doubly Linked List

struct Node* creation_DLL(int val);     // ligne 70

void affiche_DLL(struct Node* head);    // ligne 78

void push_back_DLL(struct Node** head, int value);      // ligne 85

void insertFirst_DLL(struct Node** head, int value);    // ligne 96

void insertAfter_DLL(struct Node* curr, int value);     // ligne 102

void insert_Index_DLL(struct Node** head, int value, int index);    // ligne 112

void deleteByVal_DLL(struct Node** head, int value);    // ligne 121

void deleteLastNode_DLL(struct Node** head);    // ligne 143

void free_DLL(struct Node* head);   // ligne 156



int main(int argc, char *argv[]){
    struct Node* head = NULL;
    affiche_DLL(head);
    push_back_DLL(&head, 1);
    push_back_DLL(&head, 2);
    push_back_DLL(&head, 3);
    // Quand on appelle 3 fois la fonction ajouter à la fin, on ces liens entre eux:
    /*
    struct Node* head = creation_DLL(1);
    struct Node* first = creation_DLL(2);
    struct Node* second = creation_DLL(3);
    
    head->next = first;
    first->next = second;
    second->next = NULL;

    head->prev = NULL;
    first->prev = head;
    second->prev = first;
    */

    // On commence à travailler avec DLL
    push_back_DLL(&head, 2023);
    // Les opéraitons différents:

    // deleteLastNode_DLL(&head);
    // insert_Index_DLL(&head, 55, i);  // où i est index from 0 to quantité des nodes
    // deleteByVal_DLL(&head, 1);
    // deleteByVal_DLL(&head, 23);

    printf("After: \n");
    affiche_DLL(head);
    free_DLL(head);  // libérer la mémoire
    return 0;
}


struct Node* creation_DLL(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void affiche_DLL(struct Node* head){
    if (NULL == head) { printf("Liste est vide\n"); return; }
    while(NULL != head){
        printf("adress : %p, value: %d\n", head, head->val);
        head = head->next; }
}

void push_back_DLL(struct Node** head, int value){
    struct Node* new_node = creation_DLL(value);
    if (NULL == *head) { *head = new_node; }
    else {
        struct Node* curr = *head;
        while (curr->next != NULL){ curr = curr->next; }
        new_node->prev = curr;
        new_node->next = NULL;
        curr->next = new_node; }
}

void insertFirst_DLL(struct Node** head, int value){
    struct Node* new_node = creation_DLL(value);
    new_node->next = *head;
    *head = new_node;
}

void insertAfter_DLL(struct Node* curr, int value){
    if (curr == NULL) { printf("Node est NULL, réessayez!\n"); return; }

    struct Node* new_node = creation_DLL(value);
    new_node->next = curr->next;
    if (NULL != curr->next) { curr->next->prev = new_node; }
    new_node->prev = curr;
    curr->next = new_node;
}

void insert_Index_DLL(struct Node** head, int value, int index){
    struct Node* curr = *head;
    int i;
    for (i = 0; curr != NULL && i < index-1; ++i) { curr = curr->next; }

    if (!i && !index) { insertFirst_DLL(head, value); }     // au premier node
    else { insertAfter_DLL(curr, value); }                  // ajouter au index-ième node
}

void deleteByVal_DLL(struct Node** head, int value){
    if (NULL == (*head)) { printf("Liste est vide, réessayez.\n"); return; }

    struct Node* curr = *head;
    int i;
    for (i = 0; NULL != curr; ++i){
        if (curr->val == value){  // node qu'on va supprimer 
            if (!i){  // si on supprime premier node
                *head = (*head)->next;
                (*head)->prev = NULL;
            }
            else {  // les autres nodes
                curr->prev->next = curr->next;
                if (NULL != curr->next) { curr->next->prev = curr->prev; }  // tel qu'on est pas au dernier node
            }
            free(curr);  // libérer la mémoire du node qu'on supprime
            return;
        }
        curr = curr->next;
    }
}

void deleteLastNode_DLL(struct Node** head){
    if (NULL == (*head)) { printf("Liste est vide, réessayez.\n"); return; }
    struct Node* curr = *head;
    struct Node* prev = NULL;

    while(NULL != curr->next){ prev = curr; curr = curr->next; }
    if (NULL == prev) { *head = NULL;}  // s'il n'y a qu'un seul node in DLL

    else { prev->next = NULL;}
    free(curr);
}


void free_DLL(struct Node* head) {
    struct Node* curr = head;
    while (NULL != curr) {
        struct Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}