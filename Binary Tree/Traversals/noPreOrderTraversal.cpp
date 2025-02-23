#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
};

struct node * root = NULL;

struct node * stack[10];
int top =-1;

void push(struct node* temp){
    if(!isFull()){
    stack[++top] = temp;
    }
    else{
        cout << "stack full | cannot push " << temp->data << endl; 
    }
}
struct node* pop(){
    if(!isEmpty()){
    return stack[top--];
    }
    return NULL;
}

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

void nonPreOrderTraversal(struct node* root){
    struct node * temp = root;

    push(temp);

    while(!isEmpty()){
        temp = pop();

        if(temp != NULL){
            cout << temp->data << " ";
            push(temp->rchild);
            push(temp->lchild);
        }
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

    cout << endl;
    cout << "Non Pre-Order Traversal : " << endl;
    nonPreOrderTraversal(root);
    cout << endl << endl;

    return 0;
}