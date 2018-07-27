#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct arrayQueue{
 int front, rear;
 int capacity;
 int *arr;
}

struct arrayQueue* createQueue(){
 struct arrayQueue *Q=(struct arrayQueue*)malloc(sizeof(struct arrayQueue));
 if(!Q)
  return NULL;
 Q->front=-1;
 Q->rear=-1;
 Q->capacity=1;
 Q->arr=(int*)malloc(Q->capacity*sizeof(int));
 if(!Q->arr)
  return NULL;
 printf("Queue Created \n");
 return Q;
}

int isQueueEmpty(struct arrayQueue *Q){
 return Q->front==-1;
}

int isQueueFull(struct arrayQueue *Q){
 return ((Q->rear+)%Q->capacity==Q->front);
}

int resizeQueue(struct arrayQueue *Q){
 int size=Q->capacity;
 Q->capacity=size*2;
 Q->arr=realloc(Q->array,Q->capacity);
 if(!Q->arr)
  return NULL;
 printf("Queue Resized \n");
 if(Q->front>Q->rear){
  for(int i=0;i<Q->front;i++){
   Q->arr[i+size]=Q->arr[i];
  }
  Q->rear=Q->rear+size;
 }
}

void enqueue(struct arrayQueue *Q, int x){
 if(isQueueFull(Q))
  resizeQueue(Q);
 Q->rear=(Q->rear+1)%Q->capacity;
 Q->arr[Q->rear]=x;
 if(Q->front==-1)
  Q->front=Q->rear;
 printf("Enqueued \n");
}

int dequeue(struct arrayQueue *Q){
 int data=-9999;
 if(isQueueEmpty(Q))
  return data;
 else{
  data=Q->arr[Q->front];
  if(Q->front==Q->rear)
   Q->front=Q->rear=-1;
  else
   Q->front=(Q->front+1)%Q->capacity;
 }
 printf("Dequeued \n");
 return data;
}
