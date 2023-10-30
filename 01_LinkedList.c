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

    afficheLinkedList(head);
    // insertFirstNode(&head, 23);
    // insertIndexNode(&head, 69, 3);
    push_back(&head, 14);
    push_back(&head, 15);
    // deleteByVal(&head, 14);
    // deleteByIndexLinked(&head, 2);
    deleteLastNode(&head);
    printf("\nAFTER: \n");
    afficheLinkedList(head);

    freeLinkedList(head);
}

struct Node* creationDuNode(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}


void afficheLinkedList(LinkedList head){
    while(NULL != head){
        printf("adress: %p, value: %d\n", head, head->val);
        head = head->next;
    }
}

void insertFirstNode(LinkedList *head, int new_data){
    struct Node* new_node = creationDuNode(new_data);
    new_node->next = *head;
    *head = new_node;
}

void insertAfter(LinkedList curr, int new_data){
    if (curr == NULL) {
        printf("the given node cann't be NULL");
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
    if (head == NULL) { insertFirstNode(head, new_data); }
    struct Node* curr = *head;
    struct Node* new_node = creationDuNode(new_data);

    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new_node;
}

void deleteByVal(LinkedList* head, int val){
    // If head is NULL, then the list is empty
    if (head == NULL) {
        return;
    }
    // If current node is the node to be deleted 
    if ((*head)->val == val) {
        struct Node* del_node = (*head);
        *head = (*head)->next;
        free(del_node);
        return;
    }
    
    deleteByVal(&((*head)->next), val); // Recursively call the function passing the reference and key to the node
}

void deleteByIndexLinked(LinkedList* head, int index){
    if (!index){
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
    if (*head == NULL) {
        printf("LinkedList est vide.\n");
        return;
    }
    if ((*head)->next == NULL){
        struct Node* del_node = (*head);
        *head = (*head)->next;
        free(del_node);
        return;
    }
    struct Node* curr = *head;

    while (curr->next->next != NULL) { curr = curr->next; }

    struct Node* del_node = curr;
    curr = (curr)->next;
    free(del_node);
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