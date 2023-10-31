#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
}*LinkedList;


struct Node* creationDuNode(int data);

void afficheLinkedList(LinkedList head);

void afficheInverseLinkedList(LinkedList head);

void insertFirstNode(LinkedList* head, int new_data);

void insertAfter(LinkedList head, int new_data);

void insertIndexNode(LinkedList* head, int new_data, int index);

void push_back(LinkedList* head, int new_data);

void deleteByVal(LinkedList* head, int val);

void deleteByIndexLinked(LinkedList* head, int index);

void deleteLastNode(LinkedList* head);

int countNodes(LinkedList head);

int inLinkedList(LinkedList head, int value);

void freeLinkedList(LinkedList head);

struct Node* mergeTwoLists(struct Node* list1, struct Node* list2);     // added de Leetcode

struct Node* deleteDuplicates(struct Node* head);                       // added de Leetcode

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2);           // added de Leetcode

int hasCycle(struct Node *head);                                        // added de Leetcode


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
    push_back(&head, 14);
    push_back(&head, 14);
    push_back(&head, 15);
    head = deleteDuplicates(head);
    // deleteByIndexLinked(&head, 2);  // supprimer par index
    // deleteByVal(&head, 14);   // supprimer par value
    deleteLastNode(&head);    // supprimer dernière node
    printf("\nAFTER: \n");
    afficheLinkedList(head);  // affichage

    freeLinkedList(head);  // libérer la mémoire de toutes les nodes de LinkedList
    return 0;
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

void afficheInverseLinkedList(LinkedList head){
    if (head != NULL){
        afficheInverseLinkedList(head->next);
        printf("Value de dernière Node à première: %d\n", head->val);
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

int inLinkedList(LinkedList head, int value){
    struct Node* curr = head;
    while (curr != NULL){
        if (curr->val == value){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void freeLinkedList(LinkedList head) {
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}

struct Node* mergeTwoLists(struct Node* list1, struct Node* list2){  // merge two sorted LinkedList, Leetcode
    if (NULL == list1){ return list2;}
    if (NULL == list2){ return list1;}

    if (list1->val < list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

struct Node* deleteDuplicates(struct Node* head){  // Remove Duplicates from Sorted LinkedList, Leetcode
    if(!head) { return NULL; }
    
    struct Node* curr = head, *del_node;
    while(curr && curr->next){
        if(curr->val == curr->next->val){
            del_node = curr->next;
            curr->next = curr->next->next;
            free(del_node);
        }
        else { curr = curr->next; }
    }
    return head;
}

int hasCycle(struct Node *head) {  // Linked List Cycle, Leetcode
    if (NULL == head || NULL == head->next){ return 0;}
    struct Node* slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){ return 1; }
    } 
    return 0;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {  // Add the two numbers and return the sum LinkedList, Leetcode
    struct Node* ans = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = ans;
    int carry = 0, sum = 0;
    while(l1 && l2) {
        sum = l1->val + l2->val + carry;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = sum % 10;
        carry = sum / 10;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1) {
        sum = l1->val + carry;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = sum % 10;
        carry = sum / 10;
        temp = temp->next;
        l1 = l1->next;
    }
    while(l2) {
        sum = l2->val + carry;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = sum % 10;
        carry = sum / 10;
        temp = temp->next;
        l2 = l2->next;
    }
    if(carry) {
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = carry;
        temp = temp->next;
    }
    temp->next = NULL;
    return ans->next;
}
