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

void deletion(int data){
    // cout << "Enter data to delete : ";
    // int data;
    // cin >> data;

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* parent = (struct node*)malloc(sizeof(struct node));
    temp = root;


    // while loop to find node (to delete)
    while(temp != NULL){
        if(temp->data == data){
            break; // since we found node 
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
        cout << "\nElement not found in tree" << endl;
    }
    else{
        cout << "\nElement  found in tree" << endl;

        if(temp->left != NULL && temp->right != NULL){
            struct node* temp_succ = (struct node*)malloc(sizeof(struct node));
            struct node* temp_succ_prev = (struct node*)malloc(sizeof(struct node));
            temp_succ = temp->right;
            
            cout << "temp : " << temp->data << endl;
            cout << "temp_succ : " << temp_succ->data << endl;

            while(temp_succ->left != NULL){
                temp_succ_prev = temp_succ;
                temp_succ = temp_succ->left;
            }
            
            temp->data = temp_succ->data;

            cout << "new temp_succ_prev : " << temp_succ_prev->data << endl;
            cout << "new temp_succ : " << temp_succ->data << endl;
            cout << "new temp : " << temp->data << endl;

            //connecting temp_succ right next node to temp_succ previous node
            if(temp_succ->right != NULL){
                temp_succ_prev->left = temp_succ->right;
                cout << "after connection " << temp_succ_prev->data << " left to (" << temp_succ->data << " right) : " << ((temp_succ->right)->data) << endl;
            }
            else{
                temp_succ_prev->left = NULL;
            }
            
            delete(temp_succ);            
        }
        else{
            cout << "Since node have 0 child or 1 child" << endl;
            cout << "Unable to delete node with data : " << data << endl;
        }

    }

    cout << "\ndeletion process ends here" << endl;

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

    deletion(5);
    deletion(14);

    cout << "-------------------------" << endl;
    print();

    cout << "-------------------------" << endl;
}