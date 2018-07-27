#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct arrayStack{
 int top;
 int capacity;
 int *arr;
};

struct arrayStack* createStack(){
 struct arrayStack *S=(struct arrayStack*)malloc(sizeof(struct arrayStack));
 if(!S)
  return NULL;
 S->capacity=1;
 S->top=-1;
 S->arr=(int*)malloc(S->capacity*sizeof(int));
 if(!S->arr)
  return NULL;
 return S;
}

int isStackFull(struct arrayStack *S){
 return (S->top==S->capacity-1);
}

void doubleStack(struct arrayStack *S){
 S->capacity=S->capacity*2;
 S->arr=realloc(S->arr,S->capacity*sizeof(int));
 printf("Doubled Stack \n");
}

void push(struct arrayStack *S,int x){
 if(isStackFull(S))
  doubleStack(S);
 S->arr[++S->top]=x;
 printf("Pushed %d \n",x);
}

int isStackEmpty(struct arrayStack *S){
 return S->top==-1;
}

int pop(struct arrayStack *S){
 if(isStackEmpty(S))
  return -9999;
 return S->arr[S->top--];
}

void deleteStack(struct arrayStack *S){
 if(S){
  if(S->arr)
   free(S->arr);
  free(S);
 }
 printf("Deleted Stack \n");
}
