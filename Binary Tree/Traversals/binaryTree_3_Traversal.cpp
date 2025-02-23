#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
};

struct node * root = NULL;

void insertnode(int data){
    cout << "\n\ninsertion for " << data << endl;
    // int data;
    // cout << "Enter data : ";
    // cin >> data;

    struct node * newptr = (struct node*)malloc(sizeof(struct node));
    newptr->data = data;
    newptr->lchild = NULL;
    newptr->rchild = NULL;

    if(root == NULL){
        root = newptr;
        cout << "root is NULL | INSERTING AT ROOT";
    }
    else{
        char dir;
        bool inserted = false;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = root;

        do{
            cout << "Enter direction : ";
            cin >> dir;
            

            if(dir == 'l'){
                if(temp->lchild == NULL){
                    temp->lchild = newptr;
                    inserted = true;
                }
                else{
                    cout << "moving to next level ( at " << temp->data << " )" << endl ;
                    temp = temp->lchild;
                }
            }
            else{
                if(temp->rchild == NULL){
                    temp->rchild = newptr;
                    inserted = true;
                }
                else{
                    temp = temp->rchild;
                    cout << "moving to next level ( at " << temp->data << " )" << endl ;
                }
            }
        }while(!inserted);
    }
}

//  PreOrder Traversal [DISPLAY LEFT RIGHT]
void preOrderTraversal(struct node* parent){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = parent;
    if(temp != NULL){
        cout << temp->data << " ";
        preOrderTraversal(temp->lchild);
        preOrderTraversal(temp->rchild);
    }
}

// PostOrder Traversal [Left Right Display]
void postOrderTraversal(struct node* parent){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = parent;
    if(temp != NULL){
        postOrderTraversal(temp->lchild);
        postOrderTraversal(temp->rchild);
        cout << temp->data << " ";
    }
}

// InOrder Traversal [Left Display Right]
void inOrderTraversal(struct node* parent){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = parent;
    if(temp != NULL){
        inOrderTraversal(temp->lchild);
        cout << temp->data << " ";
        inOrderTraversal(temp->rchild);
    }
}

int main(){
    cout << "start" ;

    //       11

    // 21          22
    //         31      32
    //             41


    insertnode(11);

    insertnode(21);
    insertnode(22);

    insertnode(31);
    insertnode(32);

    insertnode(41);

    cout << "-------------------------" << endl;
    preOrderTraversal(root);
    cout << "\n-------------------------" << endl;
    postOrderTraversal(root);
    cout << "\n-------------------------" << endl;
    inOrderTraversal(root);

    return 0;
}