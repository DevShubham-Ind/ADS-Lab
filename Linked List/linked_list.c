#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

void insertAtBegin(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insertInBetween(int after, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    if(head == NULL){
        printf("LinkedList is empty so adding new node at first position");
        head = newnode;
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

void insertAtEnd(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

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

void display(){
    struct node* temp = head;

    printf("\n");
    // printf("(data, address of next node)\n");

    while(temp != NULL){
        printf("(%d, %d) ", temp->data, temp->next);
        temp = temp->next;
    }

    printf("\n");

}

int main(){
    printf("start");
    int data;
    int after;
    int choice;
    int i=1;

    insertAtEnd(10);
    display();

    insertAtBegin(9);
    display();

    insertAtEnd(20);
    display();

    insertAtEnd(30);
    display();

    insertInBetween(20, 25);
    display();

    while(i<7){

        printf("\nEnter 1 to insert at begin\n");
        printf("Enter 2 to insert in between\n");
        printf("Enter 3 to insert at end\n");
        scanf("%d",&choice);

        switch(choice){
            case 1 : printf("Enter data : ");
                    scanf("%d",&data);
                    insertAtBegin(data);
                    display();
                    break;
            case 2 : printf("Enter data : ");
                    scanf("%d",&data);
                    printf("Enter after which element do you want to add : ");
                    scanf("%d",&after);
                    insertInBetween(after, data);
                    display();
                    break;
            case 3 : printf("Enter data : ");
                    scanf("%d",&data);
                    insertAtEnd(data);
                    display();
                    break;
        }

        i++;
    }


    // insertAtEnd(40);
    // display();

    // insertAtEnd(50);
    // display();

    // insertAtEnd(60);
    // display();

    printf("\nend\n");

    return 0;
}