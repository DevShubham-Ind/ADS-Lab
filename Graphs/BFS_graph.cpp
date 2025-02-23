#include<iostream>
using namespace std;

struct graph{
    int g[10][10], n, e;
    char type;
};

int visited[10] = {0};
int queue[30];
int front =0;
int rear =-1;

void inqueue(int data){
    rear++;
    queue[rear] = data;
}
int dequeue(){
    int temp = queue[front];
    front++;
    return temp;
}
int isEmpty(){
    if(front > rear){
        return 1;
    }
    return 0;
}

struct graph* insert(int vi, int vj, struct graph* obj){
    if(obj->type == 'u'){
        obj->g[vi][vj] =1;
        obj->g[vj][vi] =1;
    }
    if(obj->type == 'd'){
        obj->g[vi][vj] =1;
    }

    return obj;
}

struct graph* create(struct graph* obj){
    cout << "Enter no of Nodes: ";
    cin >> obj->n;
    cout << "Enter no of Edges: ";
    cin >> obj->e;
    int vi, vj;
    cout << "Enter type (d,u): ";
    cin >> obj->type;

    for(int i=0; i<obj->e; i++){
        for(int j=0; j<obj->e; j++){
            obj->g[i][j] =0;
        }
    }

    for(int i=0; i<obj->e; i++){
        cout << "\nvi: ";
        cin >> vi;
        cout << "vj: ";
        cin >> vj;
        obj = insert(vi, vj, obj);

    }

    return obj;
}

void printAdjacency(struct graph* obj){
    cout << "\nAdjacency Matrix: " << endl;
    for(int i=0; i<obj->e; i++){
        for(int j=0; j<obj->e; j++){
            // cout << obj->g[i][j] << " ";
            printf("%2d ",obj->g[i][j]);
        }
        cout << "\n";
    }
}

struct graph * bfs_noRecursive(int data, struct graph* obj){
    inqueue(data);
    visited[data] = 1;
    cout << data << " ";
    while(!isEmpty()){
        int curr = dequeue();
        // cout << "For " << curr << " : ";

        for(int i=0; i<obj->n; i++){
            if(obj->g[curr][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                cout << i << " ";
                inqueue(i);
            }
        }
        // cout << endl;
        // cout << "Queue : ";
        // for(int i=front; i<= rear; i++){
        //     cout << queue[i] << " ";
        // }
        // cout << "\n--------------" << endl;
    }

    return obj;
}


int main(){
    struct graph* obj = (struct graph*)malloc(sizeof(struct graph));
    obj = create(obj);

    printAdjacency(obj);

    cout << "\nBFS non Recursive : ";
    obj = bfs_noRecursive(0, obj);

    return 0;
}