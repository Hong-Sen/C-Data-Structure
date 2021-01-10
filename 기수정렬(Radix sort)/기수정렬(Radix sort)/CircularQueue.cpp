#include <iostream>
using namespace std;
#define MAX 100

class CircularQueue{
    //구현하기 나름이지만, queue와 달리 Circular Queue는 rear, front를 모두 0으로 넣고 시작한다.
    int rear = 0;
    int front = 0;
    int Q[MAX];
public:
    
    void enQueue(int item)
    {
     if (isFull())
     {
      cout << "Queue is Full" << endl;
      exit(1);
     }
     else//mod 연산 사용
     {
      rear = (rear + 1) % MAX;
      Q[rear] = item;
     }
    }

    
    int deQueue()
    {
     if (isEmpty())
     {
      cout << "Queue is Empty" << endl;
      exit(1);
     }
     else
     //mod 연산 사용
     {
      front = (front + 1) % MAX;
      return Q[front];
     }
    }


    bool isEmpty()
    {
     if (front == rear)
      return true;
     else return false;
    }

     

    bool isFull()
    {
     //일반 Queue와 다른 Full 조건
     if ((rear + 1)% MAX == front)
      return true;
     else
      return false;
    }

};

