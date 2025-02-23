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
void postOrder();

void insert(int data){
    struct node * newptr = new struct node;
    newptr->data = data;
    newptr->left = NULL;
    newptr->right = NULL;
    newptr->lbit = 1;
    newptr->rbit = 1;

    if(root == NULL){
        root = newptr;
        root->left = head;
        noOfNodes++;
        cout << "Root : " << newptr->data << endl;
    }
    else{
        struct node * temp = (struct node*)malloc(sizeof(struct node));
        struct node * parent = (struct node*)malloc(sizeof(struct node));
        temp = root;
        parent = NULL;
        bool inserted = false;

        do{
            if(temp->data < newptr->data){
                if(temp->rbit == 1){
                    newptr->right = temp->right;
                    newptr->left = temp;
                    temp->right = newptr;

                    temp->rbit = 0;
                    noOfNodes++;
                    inserted = true;
                }
                else{
                    parent = temp;
                    temp = temp->right;
                }
            }
            else if(temp->data > newptr->data){
                if(temp->lbit == 1){ 
                    newptr->left = temp->left;
                    newptr->right = temp;
                    temp->left = newptr;

                    temp->lbit = 0;
                    noOfNodes++;
                    inserted = true;
                }
                else{
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
        cout << data << " inserted successfully" << endl;

        printf("No of nodes : %d\n\n", noOfNodes);
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

void inOrder(){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp = root;

    while(temp->lbit != 1){
        temp = temp->left;
    }

    cout << "In-order Traversal  : ";
    
    for(int i=1; i<=noOfNodes; i++){
        cout << temp->data << " ";
        temp = inorder_succ(temp);
    }
    cout << "\n" << endl;
}

struct node * preOrder_succ(struct node * t){
    if(t->lbit == 0){
        return t->left;
    }
    if(t->rbit == 0){
        return t->right;
    }

    // t is leaf node 
    // jump to up-right
    while(t->rbit == 1){
        t = t->right;
    }
    return t->right;
}

void preOrder(){
    struct node * temp = root;

    cout << "Pre-order Traversal : ";

    while(temp != head){
        cout << temp->data << " ";
        temp = preOrder_succ(temp);
    }
}

void postOrder(){
    struct node* current = root;
    struct node* lastNodeVisited = NULL;

    if (current == NULL) { // Check if the tree is empty
        cout << "Tree is empty!" << endl;
        return;
    }

    cout << "Post-order Traversal : ";

    while (current != head) {
        cout << "1 ";
        while (current->lbit == 0 && current->left != NULL) { // Traverse to the leftmost node
            current = current->left;
            cout << "2 ";
        }

        if (current->rbit == 0 || current->right == lastNodeVisited) { // Check if the right subtree is already processed
            cout << current->data << " ";
            lastNodeVisited = current;
            current = current->right;
        } else {
            lastNodeVisited = current;
            current = current->right;
            while (current->lbit == 1 && current->left != head) { // Traverse to the leftmost node in the right subtree
                current = current->left;
                cout << "3 ";
            }
        }
    }
}



int main(){
    cout << "start" << endl;

    // int choice=1;
    // int data;
    // while(choice){
    //     cout << "Enter 1 to insert | 0 to exit" << endl;
    //     cin >> choice;
    //     if(choice == 1){
    //         cout << "Enter Data : ";
    //         cin >> data;
    //         insert(data);
    //     }
    // }

    insert(50);
    insert(25);
    insert(75);
    insert(12);
    insert(37); 
    insert(62); 
    insert(87);

    inOrder();
    // preOrder();
    postOrder();

    cout << "\nend" << endl;
    return 0;
}