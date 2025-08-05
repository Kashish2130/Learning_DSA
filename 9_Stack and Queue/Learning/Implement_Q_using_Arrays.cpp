//! QUEUE FOLLOWS FIFO
// implementation of queue using arrays
// tc : o(1) for all operations
// sc : o(size of array) because we are using a fixed-size array which becomes its limitation

#include <bits/stdc++.h>
using namespace std;

class QueueImp
{
private:
    int frontIndex = -1;
    int rearIndex = -1;
    int size = 10;
    int queue[10];
    int currsize = 0;

public:
    void enqueue(int n)
    {
        if (currsize == size)
        {
            cout << "queue is full";
        }

        if (currsize == 0)
        {
            frontIndex = 0;
            rearIndex = 0;
        }
        else
        {
            rearIndex = (rearIndex + 1) % size;
            queue[rearIndex] = n;
            currsize += 1;
        }
    }

    int dequeue()
    {
        if (currsize == 0)
        {
            cout << "queue is empty";
        }

        int ele = queue[frontIndex];
        if (currsize == 1)
        {
            frontIndex = rearIndex = -1;
        }
        else
        {
            frontIndex = (frontIndex + 1) % size;
        }

        currsize -= 1;
        return ele;
    }

    int front() {
        if(currsize == 0)
        {
            cout <<"queue is empty";
        }

        return queue[frontIndex];
    }

    int size() {
        return currsize;
    }
};

int main()
{
    QueueImp q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);

    q.front();

    q.dequeue();

    q.size();

    return 0;
}