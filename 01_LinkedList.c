#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}*LinkedList;

/* Une remarque:
*  "LinkedList" == "struct Node*""
*  Autrement dit on peut remplacer LinkedList par struct Node* et à l'inverse
*/

struct Node* creationDuNode(int data);      // ligne 74

void afficheLinkedList(LinkedList head);    // ligne 82

void afficheInverseLinkedList(LinkedList head);     // ligne 90

void insertFirstNode(LinkedList* head, int value);  // ligne 97

void insertAfter(LinkedList head, int value);       // ligne 105

void insertIndexNode(LinkedList* head, int value, int index);   // ligne 114

void push_back(LinkedList* head, int value);    // ligne 112

void deleteByVal(LinkedList* head, int val);    // ligne 133

void deleteByIndexLinked(LinkedList* head, int index);  // ligne 147

void deleteLastNode(LinkedList* head);  // ligne 168

int countNodes(LinkedList head);    // ligne 180

int inLinkedList(LinkedList head, int value);   // ligne 190

void freeLinkedList(LinkedList head);   // ligne 199

struct Node* mergeTwoLists(struct Node* list1, struct Node* list2);         // added de Leetcode  ligne 208

struct Node* deleteDuplicates(struct Node* head);                           // added de Leetcode  ligne 222

struct Node* addTwoNumbers(struct Node* list_un, struct Node* list_deux);   // added de Leetcode  ligne 237

int hasCycle(struct Node *head);                                            // added de Leetcode  ligne 248


int main(int argc, char *argv[]){
    struct Node* head = NULL;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    afficheLinkedList(head);
    // insertFirstNode(&head, 23);  // ajouter au début
    // insertIndexNode(&head, 69, 1);  // ajouter par index
    push_back(&head, 14);  // ajouter à la fin
    push_back(&head, 14);
    push_back(&head, 14);
    push_back(&head, 15);
    // head = deleteDuplicates(head);
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

void insertFirstNode(LinkedList *head, int value){
    // ajout au début de LinkedList
    struct Node* new_node = creationDuNode(value);
    if (*head == NULL) {*head = new_node; return;}
    new_node->next = *head;
    *head = new_node;
}

void insertAfter(LinkedList curr, int value){
    if (curr == NULL) {
        printf("Node est NULL, réessayez!\n");
        return; }
    struct Node* new_node = creationDuNode(value);
    new_node->next = curr->next;
    curr->next = new_node;
}

void insertIndexNode(LinkedList *head, int value, int index){
    struct Node* curr = *head;
    int i;
    for (i = 0; curr != NULL && i < index-1; ++i) { curr = curr->next; }
    if (!i && !index){ insertFirstNode(head, value); }
    else { insertAfter(curr, value); }
}

void push_back(LinkedList* head, int value){
    // ajoute une nouvelle node à la fin
    struct Node* new_node = creationDuNode(value);

    if (*head == NULL) { *head = new_node; return; }
    struct Node* curr = *head;

    while (curr->next != NULL) { curr = curr->next; }
    curr->next = new_node;
}

void deleteByVal(LinkedList* head, int val){
    // Liste est vide, donc on fini
    if (head == NULL) { printf("Liste est vide!\n"); return; }
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

    if (curr == NULL) { printf("Index est invqlide\n"); return; }
    prev->next = curr->next;
    free(curr);
}

void deleteLastNode(LinkedList* head){
    if (NULL == (*head)) { printf("Liste est vide, réessayez! \n"); return; }
    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Traverser toute la liste avant dernière node
    while (curr->next != NULL) { prev = curr; curr = curr->next; }
    if (NULL == prev) { *head = NULL; } // vérifier s'il n'y a qu'un seul node in LinkedList
    else { prev->next = NULL; }         // plus qu'un node
    free(curr);
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
        if (curr->val == value){ return 1; }
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

struct Node* mergeTwoLists(struct Node* list_un, struct Node* list_deux){  // merge two sorted LinkedList, Leetcode
    if (NULL == list_un){ return list_deux;}
    if (NULL == list_deux){ return list_un;}

    if (list_un->val < list_deux->val){
        list_un->next = mergeTwoLists(list_un->next, list_deux);
        return list_un;
    }
    else{
        list_deux->next = mergeTwoLists(list_un, list_deux->next);
        return list_deux;
    }
}

struct Node* deleteDuplicates(struct Node* head){  // Remove Duplicates from Sorted LinkedList, Leetcode
    if(!head) { printf("Liste est vide\n"); return NULL; }  // (!head) est (NULL == head)
    
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

struct Node* addTwoNumbers(struct Node* list_un, struct Node* list_deux) {  // Add the two numbers and return the sum LinkedList, Leetcode
    struct Node* ans = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = ans;
    int carry = 0, sum = 0;
    while(list_un && list_deux) {  // tel que deux lists ont des nodes
        sum = list_un->val + list_deux->val + carry;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = sum % 10;
        carry = sum / 10;
        temp = temp->next;
        list_un = list_un->next;
        list_deux = list_deux->next;
    }
    while(list_un) {    // tel que première liste a des nodes
        sum = list_un->val + carry;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = sum % 10;
        carry = sum / 10;
        temp = temp->next;
        list_un = list_un->next;
    }
    while(list_deux) { // tel que deuxième liste a des nodes
        sum = list_deux->val + carry;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = sum % 10;
        carry = sum / 10;
        temp = temp->next;
        list_deux = list_deux->next;
    }
    if(carry) {     // s'il nous reste a diviser
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp->next->val = carry;
        temp = temp->next;
    }
    temp->next = NULL;
    return ans->next;
}
