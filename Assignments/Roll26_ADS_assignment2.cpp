#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node * left, * right;
};

struct node * root = NULL;
int noOfNodes = 0;
queue<struct node*> q;

// Leaf Node
int leafNode[10];
int index =0;

// Stack for Traversals
struct node * stack[10];
int top =-1;


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
struct node* peak(){
    return stack[top];
}
void clearStack(){
    if(isEmpty() == false){
        for(int i=0; i<(sizeof(stack) / sizeof(struct node*)); i++){
            pop();
        }
    }
}

// Insertion of Node 
void insert(){
    struct node * newptr = (struct node *)malloc(sizeof(struct node));
    newptr->left = NULL;
    newptr->right = NULL;
    cout << "Enter data : ";
    cin >> newptr->data;

    if(root == NULL){
        root = newptr;
        noOfNodes++;
        cout << "nodes : " << noOfNodes << endl;
    }
    else{
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = root;
        bool inserted = false;

        do{
            if(temp == NULL){
                temp = newptr;
                noOfNodes++;
                inserted = true;
            }
            else{
                if(temp->data < newptr->data){
                    if(temp->right == NULL){
                        temp->right = newptr;
                        noOfNodes++;
                        inserted = true;
                    }
                    else{
                        temp = temp->right;
                    }
                }
                else if(temp->data > newptr->data){
                    if(temp->left == NULL){
                        temp->left = newptr;
                        noOfNodes++;
                        inserted = true;
                    }
                    else{
                        temp = temp->left;
                    }
                }
            }
        }while(!inserted);
        
        cout << "nodes : " << noOfNodes << endl;
    }
}

// Non-Recursive Pre-Order Traversal
void preOrderTraversal(){
    clearStack();
    struct node * temp = root;
    push(temp);

    while(!isEmpty()){
        temp = pop();

        if(temp != NULL){
            cout << temp->data << " ";

            // Check for leaf node
            if(temp->left == NULL && temp->right == NULL){
                leafNode[index] = temp->data;
                index++;
            }

            push(temp->right);
            push(temp->left);
        }
    }
}

// Non Recursive Post-Order Traversal
void postOrderTraversal(){
    struct node * curr = new struct node;
    struct node * prev = new struct node;
    struct node * p = new struct node;
    curr = root;
    prev = NULL;
    clearStack();

    while(!isEmpty() || curr != NULL){
        // temp = pop();
        if(curr != NULL){
            push(curr);
            curr = curr->left; 
        }
        else {
            curr = peak();
            if(curr->right == NULL || curr->right == prev){
                cout << curr->data << " ";
                p = pop();
                prev = curr;
                curr = NULL;
            }
            else{
                curr = curr->right;
            }
            
        }
    }        
}

// Deletion of Node
void deletion(){
    cout << "Enter data to delete : ";
    int data;
    cin >> data;

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* parent = (struct node*)malloc(sizeof(struct node));
    temp = root;

    // Searching node
    while(temp != NULL){
        if(temp->data == data){
            break;
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
        cout << "element not found in tree" << endl;
    }
    else{
        // Deletion of Node with no child nodes
        if(temp->left == NULL && temp->right == NULL){
            if(parent->left == temp){
                parent->left = NULL;
                cout << parent->data << " left " << temp->data << endl;
                cout << parent->data << " left : " << parent->left << endl;
            }
            else{
                parent->right = NULL;
                cout << parent->data << " right " << temp->data << endl;
                cout << parent->data << " right : " << parent->left << endl;
            }
            free(temp);
        }

        // Deletion of Node with 2 child nodes
        else if(temp->left != NULL && temp->right != NULL){
            struct node* temp_succ = (struct node*)malloc(sizeof(struct node));
            struct node* temp_succ_prev = (struct node*)malloc(sizeof(struct node));
            temp_succ = temp->right;
            
            cout << "temp : " << temp->data << endl;
            cout << "temp_succ : " << temp_succ->data << endl;

            if(temp_succ->left == NULL){
                temp->data = temp_succ->data;
                temp->right = NULL;
            }
            else{
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
            }

            
            free(temp_succ);            
        }
        
        // Deletion of Node with 1 child node
        else if(temp->left != NULL || temp->right != NULL){
            if(temp->left != NULL && temp->right == NULL){
                if(parent->left == temp){
                    parent->left = temp->left;
                    cout << "connecting " << parent->data << " left to " << (temp->left)->data << endl;
                }
                else{
                    parent->right = temp->left;
                    cout << "connecting " << parent->data << " right to " << (temp->left)->data << endl;
                }
                free(temp);
            }
            else if(temp->left == NULL && temp->right != NULL){
                if(parent->left == temp){
                    parent->left = temp->right;
                    cout << "connecting " << parent->data << " left to " << (temp->left)->data << endl;
                }
                else{
                    parent->right = temp->right;
                    cout << "connecting " << parent->data << " right to " << (temp->left)->data << endl;
                }
                free(temp);
            }
        }
        else{
            cout << "Error 404 Unable to Delete node" << endl;
        }

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

int main(){
    int choice;
    do{
        cout << "\nEnter 1 to insert node" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;

        if(choice == 1){
            insert();
        }

    }while(choice != 0);

    print();

    cout << "\n\n1. PreOrder Traversal : ";
    preOrderTraversal();

    cout << "\n\n2. PostOrder Traversal : ";
    postOrderTraversal();

    cout << "\n\n3. No of Nodes : " << noOfNodes;

    cout << "\n\n4. Leaf Nodes : ";
    for(int i=0; i<(sizeof(leafNode) /sizeof(int)); i++){
        if (leafNode[i] != 0) {
            cout << leafNode[i] << " ";
        }
    }

    cout << "\n\n5. Deletion of Node : " << endl;
    deletion();
    cout << endl;
    print();

    return 0;
}
