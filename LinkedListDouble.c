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

void appendDLinkedList(DLinkedList *head, int val);

void InsertAfterDLinkedList(DLinkedList prev_node, int val);

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
    //extraireDLinkedList(&head, firstNode);
    //extraireDLinkedList(&head, secondNode);
    
    appendDLinkedList(&head, 59);


    while(head != NULL){
        printf("value %d, current adress: %p\n", head->data, head);
        head = head->next;
        if (head->data == 41){
            //InsertAfterDLinkedList(head, 111);
            continue;        
        }
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

void appendDLinkedList(DLinkedList *head, int val){
    DLinkedList curr = *head;
    DLinkedList new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = val;
    new_node->next = NULL;
    if (*head == NULL){
        *head = new_node;
        return;
    }

    while ((curr->next) != NULL){
        curr = curr->next;
    }
    
    curr->next = new_node;
    new_node->prev = curr;
    //free(new_node);
}

void InsertAfterDLinkedList(DLinkedList prev_node, int val){

    if (prev_node == NULL){
        printf("The given previous node can not be NULL");
        return;
    }

    DLinkedList new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;

    prev_node->next->prev = new_node;
    new_node->next = prev_node->next;

    new_node->prev = prev_node;
    prev_node->next = new_node;
}