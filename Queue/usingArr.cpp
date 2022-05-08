#include <iostream>
using namespace std;

class Queue
{
    int *data, nI, fI, size, capacity;

public:
    Queue(int capacity)
    {
        data = new int[capacity];
        size = 0;
        fI = -1;
        nI = 0;
        this->capacity = capacity;
    }
    int size()
    {
        return size;
    }
    bool empty()
    {
        return size == 0;
    }
    void push(int element)
    {
        if (size == capacity)
        {
            cout << "queue full" << endl;
            return;
        }
        data[nI] = element;
        size++;
        nI = (nI + 1) % capacity;
        if (fI == -1)
        {
            fI = 0;
        }
    }

    // dynamic array push:
    // void push(int element)
    // {
    //     if (size == capacity)
    //     {
    //         int *newQueue = new int[capacity * 2];
    //         int j = 0;
    //         for (int i = fI; i < capacity; ++i)
    //         {
    //             newQueue[j++] = data[i];
    //         }
    //         for (int i = 0; i < fI; ++i)
    //         {
    //             newQueue[j++] = data[i];
    //         }
    //         delete[] data;
    //         data = newQueue;
    //         fI = 0;
    //         nI = capacity;
    //         capacity = capacity * 2;
    //     }
    //     data[nI] = element;
    //     size++;
    //     nI = (nI + 1) % capacity;
    //     if (fI == -1)
    //     {
    //         fI = 0;
    //     }
    // }
    
    int front()
    {
        if (fI == -1)
        {
            cout << "empty queue" << endl;
            return 0;
        }
        return data[fI];
    }
    int pop()
    {
        if (empty())
        {
            cout << "empty queue" << endl;
            return 0;
        }
        int popedElem = data[fI];
        size--;
        fI = (fI + 1) % capacity;
        if (size == 0)
        {
            fI = -1;
            nI = 0;
        }
        return popedElem;
    }
};

int main()
{
    Queue q1(3);
    q1.push(100);
    q1.push(200);
    cout << q1.pop() << endl;
    q1.push(300);
    // cout<<q1.getSize();
    q1.push(400);
    cout << q1.size() << endl;
    q1.push(500);
    cout << q1.front();

    return 0;
}