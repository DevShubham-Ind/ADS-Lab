#include<iostream>
#include<queue>
using namespace std;

struct btnode{
    int data;
    struct btnode * lchild;
    struct btnode * rchild;
};

struct btnode * root = NULL;

void insertnode(){
    cout << "Enter data : ";
    int data;
    cin >> data;

    struct btnode * newptr = (struct btnode *)malloc(sizeof(struct btnode));
    newptr-> data = data;
    newptr->lchild = NULL;
    newptr->rchild = NULL;
    
    if(root == NULL){
        cout << "root node is empty so inserting in it" << endl;
        root = newptr;
    }
    else{
        struct btnode * temp = (struct btnode *)malloc(sizeof(struct btnode));
        temp = root;
        bool inserted = false;
        char direction;

        do{
            cout << "Enter the direction for new node" << endl;
            cout << "for left enter : l , for right enter : r" << endl;
            cin >> direction;
            cout << endl;

            if(direction == 'l'){
                if(temp-> lchild == NULL){
                    temp->lchild = newptr;
                    inserted = true;
                    cout << newptr->data << " inserted to " << direction << " child for " << temp->data << endl;
                }
                else{
                    cout << "shift temp to left child" << endl;
                    temp = temp->lchild;
                    // temp = newptr;
                }
            }
            else{
                if(temp->rchild == NULL){
                    temp->rchild = newptr;
                    inserted = true;
                    cout << newptr->data << " inserted to " << direction << " child for " << temp->data << endl;
                }
                else{
                    cout << "shift temp to right child" << endl;
                    temp = temp->rchild;
                    // temp = newptr;
                }
            }

        }
        while(!inserted);
    }
    cout << "-----------------------------------------------" << endl;

    int choice;
    cout << "Enter 1 to insert new : ";
    cin >> choice;
    if(choice == 1){
        insertnode();
    }
}

void print(struct btnode * parent){
    if(parent != NULL){
        cout << parent->data << " ";

        if(parent->lchild != NULL){
            cout << "\nprinting left" << endl;
            print(parent->lchild);
        }
        if(parent->rchild != NULL){
            cout << "\nprinting right" << endl;
            print(parent->rchild);
        }
        if(parent->lchild == NULL && parent->rchild == NULL){
            cout << "no child for->" << parent->data << endl;
        }
    }
    
}

void LevelOrderPrint(struct btnode * parent){
    queue<struct btnode*> q;
    q.push(parent);
    q.push(NULL);

    while(!q.empty()){
        struct btnode* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->lchild != NULL){
                q.push(temp->lchild);
            }
            if(temp->rchild != NULL){
                q.push(temp->rchild);
            }
        }
    }
}

int main(){

    insertnode();

    cout << "\nprint start here >>>>>>" << endl;
    print(root);
    cout << "------------------------------" << endl;

    cout << "\nprint end here >>>>>>" << endl;
    LevelOrderPrint(root);
    cout << "------------------------------" << endl;

    return 0;
}