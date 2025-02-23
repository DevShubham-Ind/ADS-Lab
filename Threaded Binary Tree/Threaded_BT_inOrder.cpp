#include<iostream>
using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;
    int lbit, rbit;
};

struct node * head = NULL;
struct node * root = NULL;
int noOfNodes = 0;

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

struct node * inorder_succ(struct node * temp){
    if(temp->rbit == 1){
        return temp->right;
    }

    temp = temp->right;

    while(temp->lbit == 0){
        temp = temp->left;
    }

    return temp;
}

void inorder(){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp = root;

    while(temp->lbit != 1){
        temp = temp->left;
    }

    cout << "Inorder Traversal : ";
    
    for(int i=1; i<=noOfNodes; i++){
        cout << temp->data << " ";
        temp = inorder_succ(temp);
    }
    cout << "\n" << endl;
}

int main(){
    cout << "start " << endl;

    insert(50);
    insert(25);
    insert(75);
    insert(12);
    insert(37); 
    insert(62); 
    insert(87);

    inorder();

    return 0;
}