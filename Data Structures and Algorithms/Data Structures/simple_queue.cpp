#include <iostream>
using namespace std;

class queue{
    int front,rear,*Q,size;
public:
    queue(int size);
    void enqueue();
    void dequeue();
    void traverse();
};

queue::queue(int size) {
    front=-1;
    rear=-1;
    this->size=size;
    Q=new int[this->size];
}

void queue::enqueue() {
    int data;
    cout << "Enter data:";
    cin >> data;
    if ((rear + 1) % size == front) {
        cout << "Overflow" << endl;
        return;
    }
    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else if (rear == size - 1 && front != 0)
        rear = 0;
    else
        rear = (rear + 1) % size;
    Q[rear] = data;
}

void queue::dequeue() {
    if (front==-1 && rear==-1)
        cout<<"Underflow"<<endl;
    else if (front==rear)
        front=rear=-1;
    else if (front==size-1)
        front=0;
    else
        front=front+1;
}

void queue::traverse() {
    if (front==-1)
        cout<<"Underflow"<<endl;
    else{
        int i=front;
        if (front<=rear)
            while (i<=rear)
                cout<<Q[i++]<<" ";
        else{
            while (i<=size-1)
                cout<<Q[i++]<<" ";
            i=0;
            while (i<=rear)
                cout<<Q[i++]<<" ";
        }
    }
}



int main(){
    int i;
    cin>>i;
    queue q(i);
    q.traverse();
    for (int j=0;j<i;j++)
        q.enqueue();
    return 0;
}