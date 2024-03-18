// data_structures.c

#include "data_structures.h"



// Linked List Functions
int main(){
    struct Node* head =NULL;
    append(&head,10);
    insertAtBeginning(&head,20);
    append(&head,30);
    insertAtBeginning(&head,40);
    allData(head);
    printf("\n");
    printf("backward display : ");
    displayBackward(head);


    printf("forward display : ");
    displayForward(head);


    printf("\n");
    delete(&head,10);
    printf("after delete \n");
    allData(head);

    printf("\nStack Function\n");
    Stack stack[MAX_SIZE];
    init(stack);
    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    pop(stack);
    peek(stack);


    return 0;
}