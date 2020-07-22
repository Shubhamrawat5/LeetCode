#include<iostream>
using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int a[1000];
    int front;
    int size;
    int cap;
    MyCircularQueue(int k) {
       
        front=0;
        size=0;
        cap=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return 0;
       
            a[(front+size)%cap]=value;
        ++size;
        return 1;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return 0;
        front=(1+front)%cap;
        --size;
        return 1;
    }
    
    /** Get the front item from the queue. */
    int Front() {
   if(isEmpty()) return -1;
        return a[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return a[(front+size-1)%cap];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return !size;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size==cap;
    }
    
    void d()
    {
    	int i=0;
    	cout<<"\nDisplay queue"<<endl;
    	for(;i<size;++i)
    	cout<<a[(front+i)%cap]<<" ";
    	cout<<endl;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
	MyCircularQueue q(10);
	cout<<q.enQueue(6);
	cout<<q.Rear();
	cout<<q.Rear();
    q.d();
	cout<<q.enQueue(4);
	cout<<q.Rear();
	cout<<q.isFull();
	cout<<q.deQueue();
	q.d();
	cout<<q.enQueue(5);
	cout<<q.enQueue(55);
	q.d();
	cout<<q.Rear();
}