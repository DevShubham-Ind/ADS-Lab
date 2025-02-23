#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head1;
struct node* head2;

void insertAtBegin(struct node* head, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;

    newnode->data = data;
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insertInBetween(struct node* head, int after, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;


    newnode->data = data;
    if(temp == NULL){
        printf("LinkedList is empty so adding new node at first position");
        temp = newnode;
    }
    else{
        struct node* temp = head;

        while(temp->data != after){
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertAtEnd(struct node* head, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;


    // printf("Enter data : ");
    // scanf("%d",&newnode->data);
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node* current = head;

        while(current->next != NULL){
            current = current->next;
        }

        current->next = newnode;
    }
}

void display(int number){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(number == 1){
        temp = head1;
    }
    else{
        temp = head2;
    }

    // struct node* temp = head;
    // printf("display start here");
    printf("\n");
    // printf("(data, address of next node)\n");

    while(temp != NULL){
        printf("(%d, %d) ", temp->data, temp->next);
        temp = temp->next;
    }

    printf("\n");

}

int main(){
    printf("start\n");

    printf("List 1\n");

    insertAtEnd(head1, 10);
    display(1);

    insertAtBegin(head1, 9);
    display(1);

    // insertAtEnd(&head1, 20);
    // display(1);

    // insertAtEnd(&head1, 30);
    // display(1);

    // insertInBetween(&head1, 20, 25);
    // display(1);

    // printf("List 2\n");

    // insertAtEnd(&head2, 30);
    // display(2);

    // insertAtBegin(&head2, 29);
    // display(2);

    // insertAtEnd(&head2, 40);
    // display(2);

    // insertAtEnd(&head2, 50);
    // display(2);

    // insertInBetween(&head2, 40, 45);
    // display(2);

    return 0;


}