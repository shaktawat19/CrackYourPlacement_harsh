#include<iostream>
#include<climits>
using namespace std;

class Stack{
    int *data, nextIndex, capacity;
    public:
        Stack(){
            this->capacity = 4;
            data = new int[capacity];
            nextIndex = 0;
        }
        int size(){
            return nextIndex;
        }
        bool isEmpty(){
            return nextIndex == 0;
        }
        int top(){
            if(isEmpty()){
                cout<<"empty";
                return INT_MIN;
            }
           return nextIndex - 1;
        }
        int pop(){
            if(isEmpty()){
                cout<<"empty";
                return INT_MIN;
            }
            return data[--nextIndex];
        }
        void push(int element){
            if(nextIndex == capacity){
                int *newData = new int[2*capacity];
                for(int i=0;i<capacity;i++){
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
                capacity *= 2;
            }
            data[nextIndex++] = element;
        }
};

int main(){
    Stack s;
    cout<<s.top(); 

    return 0;
}