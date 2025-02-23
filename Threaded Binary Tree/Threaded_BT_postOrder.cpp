#include<iostream>
using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;
    int lbit, rbit;
};

struct node* root = nullptr;
struct node* head = nullptr;
int noOfNodes =1;
struct node * preOrder_succ(struct node * t);

void insert(int data){
    struct node * newptr = new struct node;
    newptr->data = data;
    newptr->left = NULL;
    newptr->right = NULL;
    newptr->lbit = 1;
    newptr->rbit = 1;
    cout << "\nFor new node : " << data << endl;

    if(root == NULL){
        root = newptr;
        root->left = head;
        noOfNodes++;
        cout << "root is new node sucess" << endl;
    }
    else{
        struct node * temp = (struct node*)malloc(sizeof(struct node));
        struct node * parent = (struct node*)malloc(sizeof(struct node));
        temp = root;
        parent = NULL;
        bool inserted = false;

        do{
            if(temp->data < newptr->data){
                cout << "moving to right" << endl;
                if(temp->rbit == 1){
                    cout << "right is NULL" << endl;
                    newptr->right = temp->right;
                    newptr->left = temp;
                    temp->right = newptr;

                    temp->rbit = 0;
                    noOfNodes++;
                    inserted = true;
                    cout << "Inserted status : " << inserted << endl;
                }
                else{
                    cout << "shifting to right"<< endl;
                    parent = temp;
                    temp = temp->right;
                }
            }
            else if(temp->data > newptr->data){
                cout << "moving to left" << endl;
                if(temp->lbit == 1){ 
                    cout << "left is NULL" << endl;                   
                    newptr->left = temp->left;
                    newptr->right = temp;
                    temp->left = newptr;

                    temp->lbit = 0;
                    noOfNodes++;
                    inserted = true;
                    cout << "Inserted status : " << inserted << endl;
                }
                else{
                    cout << "shifting to left"<< endl;
                    parent = temp;
                    temp = temp->left;
                }
            }
            else{
                cout << data << " already exsist in tree" << endl;
                cout << "Unable to insert" << endl;
                break;
            }
        }while(!inserted);

    }
        cout << data << " inserted success" << endl;

        printf("nodes : %d\n\n", noOfNodes);
}

void preOrder(){
    struct node * temp = root;

    cout << "Pre-order Traversal : ";

    while(temp != head){
        cout << temp->data << " ";
        temp = preOrder_succ(temp);
    }
}

struct node * preOrder_succ(struct node * t){
    if(t->lbit == 0){
        return t->left;
    }
    if(t->rbit == 0){
        return t->right;
    }

    // t is left node 
    // jump to up-right
    while(t->rbit == 1){
        t = t->right;
    }
    return t->right;
}

int main(){
    cout << "Let's go" << endl;
    head = new struct node;
    head->left = root;
    insert(10);
    insert(8);
    insert(9);
    insert(13);
    insert(11);

    preOrder();

    return 0;
}


// error in 
/*
parent lbit & rbit updation 
*/