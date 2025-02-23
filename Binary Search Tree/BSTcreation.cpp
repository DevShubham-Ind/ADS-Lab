#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * root = NULL;
queue<struct node *> q;

void insert(int data){
    struct node * newptr = (struct node*)malloc(sizeof(struct node));
    newptr->data = data;
    newptr->left = NULL;
    newptr->right = NULL;

    if(root == NULL){
        root = newptr;
    }
    else{
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = root;
        bool inserted = false;

        do{
            if(temp == NULL){
                temp = newptr;
                inserted = true;
            }
            else{
                if(temp->data < newptr->data){
                    if(temp->right == NULL){
                        temp->right = newptr;
                        inserted = true;
                    }
                    else{
                        temp = temp->right;
                    }
                }
                else if(temp->data > newptr->data){
                    if(temp->left == NULL){
                        temp->left = newptr;
                        inserted = true;
                    }
                    else{
                        temp = temp->left;
                    }
                }
            }
        }while(!inserted);

        cout << newptr->data << " inserted !" << endl;
    }
}

void print(){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp = root;
    q.push(temp);
    q.push(NULL);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL){
                q.push(temp->left);
            
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

}

int main(){
    cout << "bst start here" << endl;
    //             10
    //         9       12
    //      8       11    14
    //   5                   15
    //      7
    //    6

    insert(10);
    insert(9);
    insert(12);
    insert(11);
    insert(14);
    insert(8);
    insert(15);
    insert(5);
    insert(7);
    insert(6);

    cout << "inserted end here -------" << endl;

    print();

    cout << "-------------------------" << endl;
}