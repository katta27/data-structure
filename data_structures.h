// data_structures.h

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "stdio.h"
#include "stdlib.h"

//linklStruct
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

//stack

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;


//stack
void init(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
void peek(Stack* stack);

//linklisted
struct Node* createNode(int newData);
void insertAtBeginning(struct Node** head,int newData);
void append(struct Node** head, int newData);
void allData(struct Node* node);
void displayForward(struct Node* node);
void displayBackward(struct Node* node);



struct Node* createNode(int newData){

    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node) );
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertAtBeginning(struct Node** head,int newData){

    struct Node* newNode = createNode(newData);
    newNode->next=*head;
    if(*head != NULL){

        (*head)->prev = newNode;

    }
    *head = newNode;
}

void append(struct Node** head, int newData){

    struct Node* newNode = createNode(newData);
    struct Node* last = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while (last->next != NULL){
        last = last->next;
    }
    last->next = newNode;

    newNode->prev = last;

}

void allData(struct Node* node){

    if(node == NULL){
        return;
    }
    while ( node!= NULL ){
        printf("Data : %d\n",node->data);
        node = node->next;
    }

}

void displayForward(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void displayBackward(struct Node* node) {
    struct Node* last = NULL;
    while (node != NULL) {
        last = node;
        node = node->next;
    }
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

void delete(struct Node** head_ref, int newdata) {
    if (*head_ref == NULL) {
        printf("empty\n");
        return;
    }

    struct Node* current = *head_ref;

    while (current != NULL && current->data != newdata) {
        current = current->next;
    }

    if (current == NULL) {
        printf("not found\n");
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    if (current == *head_ref) {
        *head_ref = current->next;
    }

    free(current);
}


// Array Functions

void init(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}
void peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    } else {
        printf("top value is : %d", stack->arr[stack->top]);
    }

}


#endif /* DATA_STRUCTURES_H */
