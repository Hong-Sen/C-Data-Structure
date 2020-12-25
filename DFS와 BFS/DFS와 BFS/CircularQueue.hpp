#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

//inline void error(char* str){
//    fprintf(stderr, "%s\n", str);
//    exit(1);
//}

class CircularQueue{
    //구현하기 나름이지만, queue와 달리 Circular Queue는 rear, front를 모두 0으로 넣고 시작한다.
    int rear = 0;
    int front = 0;
    int data[MAX_QUEUE_SIZE];
public:
    CircularQueue() {front=reae=0;}
    ~CircularQueue(){ }
    
    bool isEmpty() {return front==rear;}
    bool isFull() {return (rear+1) % MAX_QUEUE_SIZE == front;}
    
    void enqueue(int val)
    {
     if (isFull())
     {
         printf("Queue is Full\n");
         system("pause");
     }
     else//mod 연산 사용
     {
      rear = (rear + 1) % MAX_QUEUE_SIZE;
      data[rear] = val;
     }
    }

    
    int dequeue()
    {
     if (isEmpty())
     {
         printf("Queue is Empty\n");
            system("wait");
     }
     else
     //mod 연산 사용
     {
      front = (front + 1) % MAX_QUEUE_SIZE;
      return data[front];
     }
    }

    int peek(){
        if(isEmpty()){
            printf("Queue is Empty\n");
            system("wait");
        }
        else{
            return data[(front + 1) % MAX_QUEUE_SIZE];
        }
    }
    
    void display(){
        printf("큐 내용: ");
        int maxi = (front<rear) ? rear:rear+MAX_QUEUE_SIZE;
        for(int i=front+1; i<=maxi; i++)
        printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
        printf("\n");
    }

};

