#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
}*LinkedList;


struct Node* creationDuNode(int data);

void afficheLinkedList(LinkedList head);

void insertFirstNode(LinkedList* head, int new_data);

void insertAfter(LinkedList head, int new_data);

void insertIndexNode(LinkedList* head, int new_data, int index);

void push_back(LinkedList* head, int new_data);

void deleteByVal(LinkedList* head, int val);

void deleteByIndexLinked(LinkedList* head, int index);

void deleteLastNode(LinkedList* head);

int countNodes(LinkedList head);

void freeLinkedList(LinkedList head);


int main(int argc, char *argv[]){
    struct Node* head = creationDuNode(1);
    struct Node* first = creationDuNode(2);
    struct Node* second = creationDuNode(3);

    head->next = first;
    first->next = second;
    second->next = NULL;

    /* Une remarque:
    *  LinkedList == struct Node*
    *  Autrement dit on peut remplacer LinkedList par struct Node* et à l'inverse
    */

    afficheLinkedList(head);
    // insertFirstNode(&head, 23);  // ajouter au début
    // insertIndexNode(&head, 69, 1);  // ajouter par index
    push_back(&head, 14);  // ajouter à la fin
    push_back(&head, 15);
    // deleteByIndexLinked(&head, 2);  // supprimer par index
    deleteByVal(&head, 14);   // supprimer par value
    deleteLastNode(&head);    // supprimer dernière node
    printf("\nAFTER: \n");
    afficheLinkedList(head);  // affichage

    freeLinkedList(head);  // libérer la mémoire de toutes les nodes de LinkedList
}


struct Node* creationDuNode(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}


void afficheLinkedList(LinkedList head){
    struct Node* curr = head;
    while(NULL != curr){
        printf("adress: %p, value: %d\n", curr, curr->val);
        curr = curr->next;
    }
}

void insertFirstNode(LinkedList *head, int new_data){
    // ajout au début de LinkedList
    struct Node* new_node = creationDuNode(new_data);
    new_node->next = *head;
    *head = new_node;
}

void insertAfter(LinkedList curr, int new_data){
    if (curr == NULL) {
        printf("Node est NULL, réessayez!\n");
        return; }
    struct Node* new_node = creationDuNode(new_data);
    new_node->next = curr->next;
    curr->next = new_node;
}

void insertIndexNode(LinkedList *head, int new_data, int index){

    struct Node* curr = *head;
    int i;
    for (i = 0; curr != NULL && i < index-1; ++i) { curr = curr->next; }
    if (!i && !index){ insertFirstNode(head, new_data); }
    else { insertAfter(curr, new_data); }
}

void push_back(LinkedList* head, int new_data){
    // ajoute une nouvelle node à la fin
    if (head == NULL) { insertFirstNode(head, new_data); }
    struct Node* curr = *head;
    struct Node* new_node = creationDuNode(new_data);

    while (curr->next != NULL) { curr = curr->next; }
    curr->next = new_node;
}

void deleteByVal(LinkedList* head, int val){
    // Liste est vide, donc on fini
    if (head == NULL) {
        return;
    }
    // node qu'on va supprimer 
    if ((*head)->val == val) {
        struct Node* del_node = (*head);
        *head = (*head)->next;
        free(del_node);
        return;
    }
    // fonction récursive qui va supprimer élément par value
    deleteByVal(&((*head)->next), val); 
}

void deleteByIndexLinked(LinkedList* head, int index){
    if (!index){  // si index est première node
        struct Node* del_node = (*head);
        *head = (*head)->next;
        free(del_node);
        return;
    }
    struct Node* curr = *head;
    struct Node* prev = NULL;
    int i;

    for (i = 0; curr != NULL && i < index; ++i) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

void deleteLastNode(LinkedList* head){
    if (NULL == (*head)) {
        printf("Liste est vide, réessayez! \n");
        return;
    }
    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Traverser toute la liste avant dernière node
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    // vérifier s'il n'y a qu'une seule node in LinkedList
    if (prev == NULL) {
        free(curr);
        *head = NULL;
    }
    else{
        prev->next = NULL;
        free(curr);
    }

}

int countNodes(LinkedList head){
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL){
        curr = curr->next;
        ++count;
    }
    return count;
}

void freeLinkedList(LinkedList head) {
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}