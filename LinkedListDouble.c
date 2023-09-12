#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define N 21
#define MAXIMUM N

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} *DLinkedList;


void extraireDLinkedList(DLinkedList *head, DLinkedList node);

int main(void){
    // Linked List with 3 Nodes.
    DLinkedList head = (struct Node*)malloc(sizeof(struct Node));
    DLinkedList firstNode = (struct Node*)malloc(sizeof(struct Node));
    DLinkedList secondNode = (struct Node*)malloc(sizeof(struct Node));

    head->data = 21;
    head->next = firstNode;
    head->prev = NULL;

    firstNode->data = 31;
    firstNode->next = secondNode;
    firstNode->prev = head;

    secondNode->data = 41;
    secondNode->next = NULL;
    secondNode->prev = firstNode;

    //extraireDLinkedList(&head, head);
    extraireDLinkedList(&head, firstNode);
    //extraireDLinkedList(&head, secondNode);


    while(head != NULL){
        printf("value %d, current adress: %p\n", head->data, head);
        head = head->next;
    }
    // Free memory
    free(head);
    free(firstNode);
    free(secondNode);
    return 0;
}

void extraireDLinkedList(DLinkedList *head, DLinkedList node){

    if (*head == node){
        *head = (*head)->next;
        node->next = NULL;
        if (*head != NULL){
            (*head)->prev = NULL;
        }
    }

    else if (node->next == NULL){
            node -> prev->next = NULL;
            node->prev = NULL;
            }

    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
    }
}