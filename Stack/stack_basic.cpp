#include<iostream>
using namespace std;

int stack_arr[10];
int top = -1;
void display();

void push(int data){
    top++;
    stack_arr[top]= data;
}

int pop(){
    int temp = stack_arr[top];
    top--;
    return temp;
}

int peek() {return stack_arr[top];}

bool isEmpty() {return (top== -1) ? true : false;}

bool isFull() {return (top ==9) ? true : false;}

void display(){
    for(int i=0; i<=top; i++){
        cout << stack_arr[i] << " ";
    }
}

int main(){

    cout << "\nStack : " << endl;

    // cout << "stack is empty : " << isEmpty();
    // cout << "\nstack is full : " << isFull();
    // push(10);
    // display();

    // push(20);
    // display();
    
    // push(30);
    // display();
    
    // push(40);
    // display();
    
    // push(50);
    // display();
    
    // push(60);
    // display();

    // cout << "Peek of stack is " << peek();

    // pop();
    // display();
    // pop();
    // display();

    // cout << "\nstack is empty : " << isEmpty();
    // cout << "\nstack is full : " << isFull();

    // while(isEmpty() == true){
    //     pop();
    // }
    // display();

    cout << endl;

    for(int i=0; i<10; i++){
        push((rand() % (100 - 10 + 1)) + 10);
    }
    display();
    return 0;

}