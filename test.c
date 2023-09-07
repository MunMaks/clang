#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct Node {
    int data;            // Data element
    struct Node* next;   // Pointer to the next node
}*LinkedList;


int sommesCroissantes(int li, int col, int tab[][col]);

void boo(int untab[],int deuxtab[]);

int LireChaine(char **s);

int countLinked(LinkedList head);

void push_head(LinkedList* head_ref, int new_data); // push in new head in Linked List

void insertAfter(LinkedList prev_node, int new_data); // insert in Linked List 

void append(LinkedList* head_ref, int new_data); // append at the end of Linked List

void truc(LinkedList lst);

void LastValLinkedList(LinkedList head, int new_val);

void PrintLinkedList(LinkedList head);

void manip(LinkedList *head);

bool inLinkedList(LinkedList head, int value);

void PrintInverseLinkedList(LinkedList head);

int AddTrie(LinkedList *head, int x);


int main(void){

    //int mat[5][5] = {{1, 2, 3, 4, 5},{2, 2, 3, 4, 5},{3, 2, 3, 4, 5}, {4, 2, 3, 4, 5}, {5, 2, 3, 4, 5}};
    //int res;
    //res = sommesCroissantes(5, 5, mat);
    //printf("res: %d\n", res);
    //int n;
    //char * Chaine;
    //n = LireChaine(&Chaine);
    //printf("%d\n", n);

    LinkedList head = (struct Node*)malloc(sizeof(struct Node));
    LinkedList secondNode = (struct Node*)malloc(sizeof(struct Node));
    LinkedList thirdNode = (struct Node*)malloc(sizeof(struct Node));
    LinkedList fourth = (struct Node*)malloc(sizeof(struct Node));
    LinkedList lastNode = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 2;
    head -> next = secondNode;

    secondNode -> data = 4;
    secondNode -> next = thirdNode;

    thirdNode -> data = 1;
    thirdNode -> next = fourth;

    fourth -> data = 16;
    fourth -> next = lastNode;

    lastNode -> data = 9;
    lastNode -> next = NULL;

    //int count = countLinked(head);

    //printf("Count: %d\n", count);

    //truc(head);

    manip(&head);
    //append(&head, 70);
    PrintLinkedList(head);
    printf("%d\n",countLinked(head));
    PrintInverseLinkedList(head);
    if (inLinkedList(head, 2)) {printf("%d in Linked List!\n", 2);}

    free(head);

    return 0;  
}


void boo(int untab[],int deuxtab[]){
    // le test de QCM;
    int tmp;
    tmp = *untab;
    *untab = *deuxtab;
    *deuxtab = tmp;
}


int sommesCroissantes(int li, int col, int tab[][col]){
    int i, j, sommeCourante = 0, sommePrecedente = 0;
    for(i = 0; i < li; i++){
        sommePrecedente = sommeCourante; 

        for(j = 0; j < col; j++)
            sommeCourante += tab[i][j];
            printf("sommeCourante: %i\n", sommeCourante);
        if(i > 0 && sommeCourante < sommePrecedente)
            return 0;

        sommeCourante = 0;
        printf("somme precesente: %i\n", sommePrecedente);
    }
    return 1;
}


int LireChaine(char **s){

    char seen[1025];
    int nbchar;
    scanf("%1024s", seen);
    nbchar = strlen(seen);

    *s = (char *) malloc (nbchar+1);
    
    if (*s == NULL){
        strcpy(*s, seen);
    }
    else nbchar -= 1;
    free(*s);
    return nbchar;
}


int countLinked(struct Node* head){
    struct Node* curr = head;
    int count = 0;
    while (curr != NULL){
        count++;
        curr = curr -> next;
    }
    free(curr);
    return count;
}


void push_head(LinkedList* head_ref, int new_data)
{
    LinkedList new_node = (struct Node*)malloc(sizeof(struct Node));    /* 1. allocate node */

    new_node -> data = new_data;       /* 2. put in the data  */

    new_node->next = (*head_ref);      /* 3. Make next of new node as head */

    (*head_ref) = new_node;            /* 4. move the head to point to the new node */
}


void insertAfter(LinkedList prev_node, int new_data) //insert in Linked List
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}


void append(LinkedList* head_ref, int new_data)  // append at the end of the Linked List
{
    /* 1. allocate node */
    LinkedList new_node
        = (LinkedList)malloc(sizeof(struct Node));
 
    LinkedList last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. This new node is going to be the last node, so
    make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
    * node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void truc(LinkedList lst){
    for(; lst != NULL; lst = lst -> next){
        lst -> data ++;
    }
}

void LastValLinkedList(LinkedList head, int new_val){

    while (head -> next != NULL) {
        head = head -> next; 
        }
    head -> data = new_val;
    head -> next = NULL;
}


void PrintLinkedList(LinkedList head){
    while (head != NULL){

        printf("Data: %d, Next: %p\n", head -> data, head -> next);
        head = head -> next;
    }
}

void PrintInverseLinkedList(LinkedList head){
    if (head != NULL){
        PrintInverseLinkedList(head -> next);
        printf("Value from last to first element: %d\n", head -> data);
    }
}

void manip(LinkedList *head){
    LinkedList tmp;
    int i = 1;
    if (i == 1) {
        tmp=(*head)->next->next;    /*1*/ 
        tmp->next->next=*head;      /*2*/ 
        *head=(*head)->next;        /*3*/ 
        (*head)->next=NULL;         /*4*/
        *head=tmp;                  /*5*/ 
        tmp=tmp->next;              /*6*/ 
    }
}

bool inLinkedList(LinkedList head, int value){

    while (head != NULL){
        if (head -> data == value){
            return true;
        }
        head = head -> next;
    }
    return false;
}

int AddTrie(LinkedList *head, int x){
    LinkedList tmp = (struct Node*)malloc(sizeof(struct Node));    
    LinkedList curr = *head; 
    if(tmp == NULL) return 0;
    
    if (*head == NULL) return *head = tmp;

    if (*head -> data >= x){
        tmp -> next = *head;
        *head = tmp;
    }
    else{
        while(curr -> next =! NULL && curr -> next-> data < x){
            curr = curr -> next;
        }
        tmp -> next = curr -> next;
        curr -> next = tmp;
    }
    
    
    free(tmp);
    free(curr);

    return 1;
}