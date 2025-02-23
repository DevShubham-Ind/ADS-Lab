#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
};
struct node * root = NULL;
struct node * stack[10];
int top = -1;

int isFull();
int isEmpty();

void push(struct node* temp){
    if(!isFull()){
        stack[++top] = temp;
    }
    else{
        printf("stack full | cannot push %d\n", temp->data);
    }
}

struct node* pop(){
    if(!isEmpty()){
        return stack[top--];
    }
    return NULL;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(top == 9){
        return 1;
    }
    return 0;
}

struct node* peak(){
    return stack[top];
}

void makeEmpty(){
    if(isEmpty() == 0){
        for(int i=0; i<(sizeof(stack) / sizeof(stack[0])); i++){
            pop();
        }
    }
}

void insertnode(int data){
    printf("insertion for %d\n", data);

    struct node * newptr = (struct node*)malloc(sizeof(struct node));
    newptr->data = data;
    newptr->lchild = NULL;
    newptr->rchild = NULL;
    if(root == NULL){
        root = newptr;
        printf("root is NULL | inserting at root");
    }
    else{
        char dir;
        int inserted = 0;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = root;
        do{
            printf("Enter direction : ");
            scanf(" %c", &dir);
            if(dir == 'l'){
                if(temp->lchild == NULL){
                    temp->lchild = newptr;
                    inserted = 1;
                }
                else{
                    printf("moving to next level ( at %d )\n", temp->data);
                    temp = temp->lchild;
                }
            }
            else{
                if(temp->rchild == NULL){
                    temp->rchild = newptr;
                    inserted = 1;
                }
                else{
                    temp = temp->rchild;
                    printf("moving to next level ( at %d )\n", temp->data);
                }
            }
        }while(!inserted);
    }
}

void nonPreOrderTraversal(struct node* root){
    //Ensure stack in empty
    makeEmpty();

    struct node * temp = root;
    push(temp);
    while(!isEmpty()){
        temp = pop();
        if(temp != NULL){
            printf("%d ", temp->data);
            push(temp->rchild);
            push(temp->lchild);
        }
    }
}

void nonPostOrderTraversal(struct node* root) {
    //Ensure stack in empty
    makeEmpty();
    
    struct node* curr = root;
    struct node* prev = NULL;
    struct node* p = NULL;

    while (!isEmpty() || curr != NULL) {
        if (curr != NULL) {
            push(curr);
            curr = curr->lchild;
        } else {
            curr = peak();
            if (curr->rchild == NULL || curr->rchild == prev) {
                printf("%d ", curr->data);
                p = pop();
                prev = curr;
                curr = NULL;
            } else {
                curr = curr->rchild;
            }
        }
    }
}

void nonInOrderTraversal(struct node* root){
    //Ensure stack in empty
    makeEmpty();
    
    struct node * temp = root;

    while(!isEmpty() || temp!= NULL){
        if(temp != NULL){
            push(temp);
            temp = temp->lchild;
        }
        else{
            temp = pop();
            printf("%d ", temp->data);
            temp = temp->rchild;
        }
    }
}

int main(){
    int choice;
    int data;
    do{
        printf("\n\nEnter 1 to insert node\n");
        printf("Enter 0 to exit\n");
        scanf("%d" , &choice);

        if(choice == 1){
            printf("Enter data : ");
            scanf("%d", &data);
            insertnode(data);
        }
    }while(choice != 0);

    printf("\nNon Recursive PreOrder Traversal : \n");
    nonPreOrderTraversal(root);

    printf("\nNon Recursive PostOrder Traversal : \n");
    nonPostOrderTraversal(root);

    printf("\nNon Recursive InOrder Traversal : \n");
    nonInOrderTraversal(root);
    printf("\n");

    return 0;
}

