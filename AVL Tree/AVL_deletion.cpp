#include<iostream>
using namespace std;

struct node {
    int data, height;
    struct node * left, *right;
};

// struct node * root = (struct node*)malloc(sizeof(struct node));

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(struct node * t){
    if(t == NULL){
        return 0;
    }
    return t->height;
}

int getBT(struct node * t){
    if(t == NULL){
        return 0;
    }
    return getHeight(t->left) - getHeight(t->right);
}

struct node* leftRotate(struct node * temp){
    struct node * y = temp->right;
    struct node * t2 = y->left;

    y->left = temp;
    temp->right = t2;

    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node* rightRotate(struct node * temp){
    struct node * x = temp->left;
    struct node * t2 = x->right;

    x->right = temp;
    temp->left = t2;

    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct node * insert(struct node * temp, int data){
    

    if(temp == NULL){
        struct node * newptr = (struct node*)malloc(sizeof(struct node));
        newptr->data = data;
        newptr->height = 1;
        newptr->left = NULL;
        newptr->right = NULL;
        temp = newptr;
    }
    else if(data < temp->data){
        temp->left = insert(temp->left, data);
    }
    else if(data > temp->data){
        temp->right = insert(temp->right, data);
    }
    else{
        cout << data << " element already exsist in tree" << endl;
        return temp;
    }

    temp->height = max(getHeight(temp->left), getHeight(temp->right)) +1;

    int balance = getBT(temp);

    // Left Left
    if(balance > 1 && data < (temp->left)->data){
        return rightRotate(temp);
    }
    // Left Right
    if(balance > 1 && data > (temp->left)->data){
        temp->left = leftRotate(temp->left);
        return rightRotate(temp);
    }

    // Right Right
    if(balance < -1 && data > (temp->right)->data){
        return leftRotate(temp);
    }
    // Right Left
    if(balance < -1 && data < (temp->right)->data){
        temp->right = rightRotate(temp->right);
        return leftRotate(temp);
    }
    
    return temp;
}

struct node * del(struct node * temp, int key){
    if(temp == NULL){
        return NULL;
    }
    else{
        if(key > temp->data){
            temp->right = del(temp->right, key);

            if(getBT(temp->left) > 0){
                temp = rightRotate(temp);
            }
            else{
                temp->left = leftRotate(temp);
                temp = rightRotate(temp);
               
            }
        }
        else if(key < temp->data){
            temp->left = del(temp->left, key);

            if(getBT(temp) == -2){
                if(getBT(temp->right) <= 0){
                    temp = rightRotate(temp);
                }
                else{
                    temp->right = rightRotate(temp);
                    temp = leftRotate(temp);
                }
            }
        }
        else{
            struct node * p = (struct node*)malloc(sizeof(struct node));
            if(temp->right != NULL){
                //Delete inorder Predecessor
                p = temp->right;

                while(p->left != NULL){
                    p = p->left;
                }

                temp->data = p->data;
                temp->right = del(temp->right, p->data);

                if(getBT(temp->left) ==2){
                    if(getBT(temp->left) >=0){
                        temp = rightRotate(temp);
                    }
                    else{
                        temp->left = leftRotate(temp);
                        temp = rightRotate(temp); 
                    }
                }
            }
            else{
                return (temp->left);
            }
        }
    }
    
    temp->height = getHeight(temp);
    return temp;
}

void preorder(struct node * temp){
    if(temp != NULL){
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void printBTs(struct node* temp){
    if(temp != NULL){
        cout << getBT(temp) << " ";
        printBTs(temp->left);
        printBTs(temp->right);
    }
}

int main(){
    struct node * root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);

    cout << "PreOrder Traversal : " << endl;
    preorder(root);
    cout << "\nBT for resp : " << endl;
    printBTs(root);
    
    int key;
    cout << "\n\nEnter data to delete : " << endl;
    cin >> key;
    del(root, key);

    cout << "\nPreOrder Traversal : " << endl;
    preorder(root);
    cout << "\nBT for resp : " << endl;
    printBTs(root);

    return 0;
}