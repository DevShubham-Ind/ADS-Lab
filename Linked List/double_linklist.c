#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head = NULL;

void insertAtBegin(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(head == NULL){
        head = newNode;
        head->prev = NULL;
        head->next = NULL;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAfter(int data, int after){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    struct node * prevNode = head;
    if(prevNode == NULL){
        printf("Unable to insert Linklist Empty |||\n");
        return;
    }
    while(prevNode->data != after){
        prevNode = prevNode->next;
    }

    newNode->next = prevNode->next;
    (prevNode->next)->prev = newNode;
    newNode->prev = prevNode;
    prevNode->next = newNode;
}

void display(){
    struct node * temp = head;
    printf("\nLinklist : ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    insertAtBegin(10);
    display();
    printf("\n------------------------\n");
    insertAtEnd(20);
    display();
    printf("\n------------------------\n");
    insertAtEnd(30);
    display();
    printf("\n------------------------\n");
    insertAtEnd(40);
    display();
    printf("\n------------------------\n");
    insertAtBegin(5);
    display();
    printf("\n------------------------\n");
    insertAfter(25, 20);
    display();
    printf("\n------------------------\n");

    return 0;
}