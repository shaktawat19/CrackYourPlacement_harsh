#include<iostream>
#include<climits>
using namespace std;

class Stack{
    int *data;
    int nextIndex;
    int capacity;
    public:
        Stack(int capacity){
            this->capacity = capacity;
            data = new int[capacity];
            nextIndex = 0;
        }
        int size(){
            return nextIndex;
        }
        bool isEmpty(){
            return nextIndex == 0;
        }
        void push(int element){
            if(nextIndex == capacity){
                cout<<"Already full";
                return;
            }
            data[nextIndex++] = element;
        }
        int top(){
            if(isEmpty()){
                cout<<"empty stack";
                return INT_MIN;
            }
            return nextIndex-1;
        }
        int pop(){
            if(isEmpty()){
                cout<<"empty stack";
                return INT_MIN;
            }
            return data[--nextIndex];
        }
};

int main(){
    Stack s1(10);
    s1.push(100);
    s1.push(200);
    cout<<s1.pop();
    
    return 0;
}