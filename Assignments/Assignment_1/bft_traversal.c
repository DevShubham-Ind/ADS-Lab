#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
void insert(int data);
void bfsTraversal();

struct node* queue[10];
int head=0;
int rear=-1;
int no = 0; 
int newlineAt = 1; 
void inqueue(struct node* newNode);
struct node* dequeue();
int isEmpty();


void inqueue(struct node* newNode){
    rear++;
    queue[rear] = newNode;
}
struct node* dequeue(){
    struct node* temp = queue[head];
    head++;
    return temp;
}
int isEmpty(){
    if(head > rear){
        return 1;
    }
    return 0;
}


void insertnode(int data){
    printf("For data : %d\n", data);
    struct node* newptr = (struct node*)malloc(sizeof(struct node));
    newptr->data = data;
    newptr->left = NULL;
    newptr->right = NULL;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = root;
    if(root == NULL){
        printf("root is empty || inserting in root\n\n");
        root = newptr;
    }
    else{
        int inserted = 0;
        do{
            printf("Enter direction(l, r) %d : ", temp->data);
            char dir;
            scanf(" %c", &dir);
            if(dir == 'l'){
                if(temp->left == NULL){
                    temp->left = newptr;
                    printf("%d inserted at left of %d\n", data, temp->data);
                    inserted = 1;
                }
                else{
                    temp = temp->left;
                    printf("left is not empty | moving to next level\n");
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = newptr;
                    printf("%d inserted at right of %d\n", data, temp->data);
                    inserted = 1;
                }
                else{
                    temp = temp->right;
                    printf("right is not empty | moving to next level\n");
                }
            }
        }
        while(!inserted);
        printf("insertion success : %d\n\n", inserted);
    }
}


void bfsTraversal(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = root;
    int data;
    inqueue(temp);
    printf("BFS : \n");
    do{
        temp = dequeue();
        data = temp->data;
        printf("%d ", temp->data);
        if(temp != NULL){
            if(temp->left != NULL){
                inqueue(temp->left);
            }
            if(temp->right != NULL){
                inqueue(temp->right);
            }
        }
    }
    while(!isEmpty());
    printf("\n\n");
}

int main(){
    
    //             11
    //         /       \
    //     21            22
    //        \         /   \
    //         31     41      32
    //       /                 \
    //     51                  42
    //       \
    //       61

    //  21  22  31  32  41  42  51  61 
    //  l   r   lr  rr  rl  rrr lrl lrlr

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

    bfsTraversal();
    return 0;
}

