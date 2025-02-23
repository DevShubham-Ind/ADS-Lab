#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node * left, * right;
};

struct node * root = NULL;
int noOfNodes = 0;

int leafNode[10];
int atIndex =0;

struct node * stack[10];
int top =-1;

struct node * queue[15];
int front = 0;
int rear = -1;

bool isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool isFull(){
    if(top == 9){
        return true;
    }
    return false;
}

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

struct node* peak(){
    return stack[top];
}

void clearStack(){
    if(isEmpty() == false){
        for(int i=0; i<(sizeof(stack) / sizeof(struct node*)); i++){
            pop();
        }
    }
}

void inqueue(struct node * temp){
    rear++;
    queue[rear] = temp;
}
struct node * dequeue(){
    struct node * temp = queue[front];
    front++;
    return temp;
}
struct node * queueFront(){
    return queue[front];
}
bool queueEmpty(){
    if(front > rear){
        return true;
    }
    return false;
}

void insert(){
    struct node * newptr = (struct node *)malloc(sizeof(struct node));
    newptr->left = NULL;
    newptr->right = NULL;
    printf("Enter data : ");
    scanf("%d", &newptr->data);
    if(root == NULL){
        root = newptr;
        noOfNodes++;
        printf("nodes : %d\n", noOfNodes);
    }
    else{
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = root;
        bool inserted = false;
        
        do{
            if(temp->data < newptr->data){
                if(temp->right == NULL){
                    temp->right = newptr;
                    noOfNodes++;
                    inserted = true;
                }
                else{
                    temp = temp->right;
                }
            }
            else if(temp->data > newptr->data){
                if(temp->left == NULL){
                    temp->left = newptr;
                    noOfNodes++;
                    inserted = true;
                }
                else{
                    temp = temp->left;
                }
            }
        }while(!inserted);

        printf("nodes : %d\n", noOfNodes);
    }
}

void preOrderTraversal(){
    clearStack();
    struct node * temp = root;
    push(temp);
    while(!isEmpty()){
        temp = pop();
        if(temp != NULL){
            printf("%d ", temp->data);
            
            if(temp->left == NULL && temp->right == NULL){
                leafNode[atIndex] = temp->data;
                atIndex++;
            }
            push(temp->right);
            push(temp->left);
        }
    }
}

void postOrderTraversal(){
    struct node * curr = (struct node*)malloc(sizeof(struct node));
    struct node * prev = (struct node*)malloc(sizeof(struct node));
    struct node * p = (struct node*)malloc(sizeof(struct node));
    curr = root;
    prev = NULL;
    clearStack();
    while(!isEmpty() || curr != NULL){
        
        if(curr != NULL){
            push(curr);
            curr = curr->left; 
        }
        else {
            curr = peak();
            if(curr->right == NULL || curr->right == prev){
                printf("%d ", curr->data);
                p = pop();
                prev = curr;
                curr = NULL;
            }
            else{
                curr = curr->right;
            }
        }
    }        
}

void deletion(){
    printf("Enter data to delete : ");
    int data;
    scanf("%d", &data);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* parent = (struct node*)malloc(sizeof(struct node));
    temp = root;
    
    while(temp != NULL){
        if(temp->data == data){
            break;
        }
        if(temp->data < data){
            parent = temp;
            temp = temp->right;
        }
        else{
            parent = temp;
            temp = temp->left;
        }
    }
    if(temp == NULL){
        printf("element not found in tree\n");
    }
    else{
        
        if(temp->left == NULL && temp->right == NULL){
            if(parent->left == temp){
                parent->left = NULL;
                printf("%d left %d\n", parent->data, temp->data);
                printf("%d left : %d\n", parent->data, parent->left);
            }
            else{
                parent->right = NULL;
                printf("%d right %d\n", parent->data, temp->data);
                printf("%d right : %d\n", parent->data, parent->left);
            }
            free(temp);
        }
        
        else if(temp->left != NULL && temp->right != NULL){
            struct node* temp_succ = (struct node*)malloc(sizeof(struct node));
            struct node* temp_succ_prev = (struct node*)malloc(sizeof(struct node));
            temp_succ = temp->right;
            printf("temp : %d\n", temp->data);
            printf("temp_succ : %d\n", temp_succ->data);
            if(temp_succ->left == NULL){
                temp->data = temp_succ->data;
                temp->right = NULL;
            }
            else{
                while(temp_succ->left != NULL){
                    temp_succ_prev = temp_succ;
                    temp_succ = temp_succ->left;
                }
                temp->data = temp_succ->data;
                printf("new temp_succ_prev : %d\n", temp_succ_prev->data);
                printf("new temp_succ : %d\n", temp_succ->data);
                printf("new temp : %d\n", temp->data);
                
                if(temp_succ->right != NULL){
                    temp_succ_prev->left = temp_succ->right;
                    printf("after connection %d left to (%d right) : %d\n", temp_succ_prev->data, temp_succ->data, (temp_succ->right)->data);
                }
                else{
                    temp_succ_prev->left = NULL;
                }
            }
            free(temp_succ);            
        }
        
        else if(temp->left != NULL || temp->right != NULL){
            if(temp->left != NULL && temp->right == NULL){
                if(parent->left == temp){
                    parent->left = temp->left;
                    printf("connecting %d left to %d\n", parent->data, (temp->left)->data);
                }
                else{
                    parent->right = temp->left;
                    printf("connecting %d right to %d\n", parent->data, (temp->left)->data);
                }
                free(temp);
            }
            else if(temp->left == NULL && temp->right != NULL){
                if(parent->left == temp){
                    parent->left = temp->right;
                    printf("connecting %d left to %d\n", parent->data, (temp->left)->data);
                }
                else{
                    parent->right = temp->right;
                    printf("connecting %d right to %d\n", parent->data, (temp->left)->data);
                }
                free(temp);
            }
        }
        else{
            printf("Error 404 Unable to Delete node\n");
        }
    }
}

void print(){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp = root;
    inqueue(temp);
    inqueue(NULL);
    printf("\nTree : \n");
    while(!queueEmpty()){
        temp = queueFront();
        dequeue();
        if(temp == NULL){
            printf("\n");
            if(!queueEmpty()){
                inqueue(NULL);
            }
        }
        else{
            printf("%d ", temp->data);
            if(temp->left != NULL){
                inqueue(temp->left);
            }
            if(temp->right != NULL){
                inqueue(temp->right);
            }
        }
    }
}

int main(){
    int choice;
    do{
        printf("\nEnter 1 to insert node\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        if(choice == 1){
            insert();
        }
    }while(choice != 0);
    print();
    printf("\n\n1. PreOrder Traversal : ");
    preOrderTraversal();
    printf("\n\n2. PostOrder Traversal : ");
    postOrderTraversal();
    printf("\n\n3. No of Nodes : %d", noOfNodes);
    printf("\n\n4. Leaf Nodes : ");
    for(int i=0; i<(sizeof(leafNode) /sizeof(int)); i++){
        if (leafNode[i] != 0) {
            printf("%d ", leafNode[i]);
        }
    }
    printf("\n\n5. Deletion of Node : \n");
    deletion();
    printf("\n");
    print();
    return 0;
}


