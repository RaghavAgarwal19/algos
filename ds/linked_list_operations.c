#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};

struct node* createList(int data){
 struct node *newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data=data;
 newNode->next=NULL;
 printf("\nCreated New Linked List with 1 node \n");
 return newNode;
}

struct node* insertAtStart(struct node *head, int data){
 struct node *newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data=data;
 newNode->next=head;
 head=newNode;
 printf("\nInserted new node at beginning of Linked List \n");
 return head;
}

void insertAtEnd(struct node *head,int data){
 struct node *p=head;
 struct node *newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data=data;
 newNode->next=NULL;
 while(p->next!=NULL)
  p=p->next;
 p->next=newNode;
 printf("\nInserted new node at end of Linked List \n");
}

void insertInMiddle(struct node *head,int pos,int data){
 int k=1;
 struct node *p=head,*q,*newNode;
 newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data=data;
 while(p->next!=NULL && k<pos){
  k++;
  q=p;
  p=p->next;
 }
 q->next=newNode;
 newNode->next=p;
 printf("\nInserted data at position %d\n",pos);
}

void traverseList(struct node *head){
 struct node *p=head;
 printf("\nCurrent Linked List \n");
 while(p!=NULL){
  printf("%5d",p->data);
  p=p->next;
 }
}

struct node* deleteHead(struct node *head){
 struct node *temp=head;
 head=temp->next;
 free(temp);
 printf("\nDeleted head node \n");
 return head;
}

void deleteAtEnd(struct node *head){
 struct node *p=head,*q;
 while(p->next!=NULL){
  q=p;
  p=p->next;
 }
 q->next=NULL;
 free(p);
 printf("\nDeleted Last Node \n");
}

void deleteAtMiddle(struct node *head,int pos){
 int k=1;
 struct node *p=head,*q;
 while(p->next!=NULL && k<pos){
  k++;
  q=p;
  p=p->next;
 }
 q->next=p->next;
 free(p);
 printf("\nDeleted node at %d position \n",pos);
}