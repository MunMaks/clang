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

void deleteHead(LinkedList* head);

void deleteByIndexLinked(LinkedList* head, int index);

void deleteLastLinked(LinkedList* head);

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

    printf("\nAFTER: \n");
    afficheLinkedList(head);
    int count = countNodes(head);

    printf("nb nodes: %d\n", count);
    deleteLastLinked(&head);

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

void deleteHead(LinkedList* head){
    if (*head == NULL) {
        printf("LinkedList est vide.\n");
        return;
    }

    struct Node* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void deleteByIndexLinked(LinkedList* head, int index){
    if (!index){ deleteHead(head); return; }
    struct Node* curr = *head;
    int i;
    for (i = 0; curr != NULL && i < index-1; ++i) { curr = curr->next; }
    if (curr == NULL || curr->next == NULL) { printf("Index n'est pas valide\n"); return; }

    struct Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

void deleteLastLinked(LinkedList* head){
    if (*head == NULL) {
        printf("LinkedList est vide.\n");
        return;
    }
    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* curr = *head;

    while (curr->next->next != NULL) { curr = curr->next; }

    free(curr->next);
    curr->next = NULL;
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