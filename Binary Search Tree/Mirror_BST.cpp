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

        // cout << newptr->data << " inserted !" << endl;
    }
}

void print(){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp = root;
    q.push(temp);
    q.push(NULL);

    cout << "\nTree : " << endl;

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

void mirror(struct node* parent){
    struct node * temp = (struct node*)malloc(sizeof(struct node));

    if(parent != NULL){
        temp = parent->left;
        parent->left = parent->right;
        parent->right = temp;

        mirror(parent->left);
        mirror(parent->right);
    }
}

int main(){
    cout << "bst start here" << endl;
    //             10
    //           /    \
    //         9       12
    //        /       /   \
    //      6       11     14
    //     / \            /  \
    //   3    8         13    27
    //     \                 /  \
    //      5               24   30
    //     /               /  \
    //    4               20  26
    //                   /  \
    //                  16  21
    //                  /
    //                 15

    insert(10);
    insert(9);
    insert(12);
    insert(6);
    insert(11);
    insert(14);
    insert(3);
    insert(8);
    insert(13);
    insert(27);
    insert(5);
    insert(24);
    insert(30);
    insert(4);
    insert(20);
    insert(26);
    insert(16);
    insert(21);
    insert(15);
    

    cout << "\ninsertion end here -------" << endl;

    print();

    cout << "-------------------------" << endl;

    mirror(root);
    cout << "Tree mirrored successfully" << endl;

    cout << "-------------------------" << endl;
    print();

    cout << "-------------------------" << endl;
}