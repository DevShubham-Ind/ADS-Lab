#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
};
struct node * root = NULL;

void insertnode(int data){
    printf("Insertion for %d\n", data);
    
    struct node * newptr = (struct node*)malloc(sizeof(struct node));
    newptr->data = data;
    newptr->lchild = NULL;
    newptr->rchild = NULL;
    if(root == NULL){
        root = newptr;
        printf("root is NULL | INSERTING AT ROOT");
    }
    else{
        char dir;
        int inserted = 0;
        struct node* temp = root;
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

void preOrderTraversal(struct node* parent){
    if(parent != NULL){
        printf("%d ", parent->data);
        preOrderTraversal(parent->lchild);
        preOrderTraversal(parent->rchild);
    }
}

void postOrderTraversal(struct node* parent){
    if(parent != NULL){
        postOrderTraversal(parent->lchild);
        postOrderTraversal(parent->rchild);
        printf("%d ", parent->data);
    }
}

void inOrderTraversal(struct node* parent){
    if(parent != NULL){
        inOrderTraversal(parent->lchild);
        printf("%d ", parent->data);
        inOrderTraversal(parent->rchild);
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
    
    printf("\n-----------------------------------\n");
    printf("PreOrder Traversal : ");
    preOrderTraversal(root);
    printf("\n\n");
    printf("PostOrder Traversal : ");
    postOrderTraversal(root);
    printf("\n\n");
    printf("InOrder Traversal : ");
    inOrderTraversal(root);
    return 0;
}

