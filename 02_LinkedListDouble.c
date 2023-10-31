#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
}*LinkedListD;


struct Node* creationDuNode(int val);

void push_back_Double(LinkedListD* head, int value);

void freeLinkedList(LinkedListD head);

void afficheLinkedList(LinkedListD head);


int main(int argc, char *argv[]){
    struct Node* head = creationDuNode(1);
    struct Node* first = creationDuNode(2);
    struct Node* second = creationDuNode(3);

    head->next = first;
    first->next = second;
    second->next = NULL;

    head->prev = NULL;
    first->prev = head;
    second->prev = first;
    afficheLinkedList(head);
    printf("After: \n");
    push_back_Double(&head, 55);
    afficheLinkedList(head);
    freeLinkedList(head);
    return 0;
}


struct Node* creationDuNode(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void afficheLinkedList(LinkedListD head){
    struct Node* curr = head;
    while(NULL != curr){
        printf("adress: %p, value: %d\n", curr, curr->val);
        curr = curr->next;
    }
}

void push_back_Double(LinkedListD* head, int value){
    struct Node* curr = *head;
    struct Node* new_node = creationDuNode(value);
    if (NULL == curr) { 
        curr->next = new_node;
        *head = new_node;
        free(curr);
        return;
    }

    while (curr->next != NULL){ curr = curr->next; }
    new_node->prev = curr;
    new_node->next = NULL;
    curr->next = new_node;
}




void freeLinkedList(LinkedListD head) {
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}