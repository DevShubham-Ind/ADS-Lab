#include<iostream>
#include<stack>
using namespace std;

struct graph{
    int g[10][10], n, e;
    char type;
};

int visited[8] = {0};
stack<int> s;

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
    cout << "Enter type (d,u):";
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

int main(){
    struct graph* obj = (struct graph*)malloc(sizeof(struct graph));
    obj = create(obj);

    cout << "\nAdj Matrix: " << endl;
    for(int i=0; i<obj->e; i++){
        for(int j=0; j<obj->e; j++){
            cout << obj->g[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nDFS :";
    obj = dfs(0,obj);

    return 0;
}