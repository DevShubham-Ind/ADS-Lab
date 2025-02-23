#include<iostream>
using namespace std;

struct graph{
    int g[10][10], n, e;
    char type;
};

int visited[10] = {0};

int stack[10];
int top= -1;

void push(int data){
    top++;
    stack[top] =data;
}
int pop(){
    int temp = stack[top];
    top--;
    return temp;
}
int front(){
    return stack[top];
}
int isEmpty(){
    if(top == -1){
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

struct graph* dfs(int i, struct graph* obj){
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for(int j=0; j<obj->n; j++){
        if(!visited[j] && obj->g[i][j]==1){
            obj = dfs(j, obj);
        }
    }
    return obj;
}

struct graph* dfs_noRecursive(int i, struct graph* obj){
    // reset visited to unvisited
    for (int k = 0; k < obj->n; ++k) {
        visited[k] = 0;
    }

    push(i);
    while (!isEmpty()) {
        // cout << "while" << endl;
        int curr = front();
        pop();
        if (!visited[curr]) {
            printf("%d ", curr);
            visited[curr] = 1;
        }
        for (int j = obj->n - 1; j >= 0; j--) {
            // cout << "for relation:" << obj->g[curr][j] << " && visited:" << visited[j] << endl;
            if (obj->g[curr][j] == 1 && !visited[j]) {
                // cout << "\npushing " << j << endl;
                push(j);
            }
        }
    }
    return obj;
}

int main(){
    struct graph* obj = (struct graph*)malloc(sizeof(struct graph));
    obj = create(obj);

    printAdjacency(obj);

    cout << "\nDFS               : ";
    obj = dfs(0,obj);

    cout << "\nDFS non Recursive : ";
    obj = dfs_noRecursive(0, obj);

    return 0;
}