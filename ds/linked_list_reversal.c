#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
void main(){
 struct node *head=NULL,*curr=NULL,*newNode,*prev,*next;
 int data,n,i;
 clrscr();
 printf("Enter length \n");
 scanf("%d",&n);
 head=(struct node*)malloc(sizeof(struct node));
 printf("Enter data for node 1 : ");
 scanf("%d",&data);
 head->data=data;
 head->next=NULL;
 curr=head;
 for(i=2;i<=n;i++){
  printf("Enter data for node %d : ",i);
  scanf("%d",&data);
  newNode=(struct node*)malloc(sizeof(struct node));
  curr->next=newNode;
  newNode->data=data;
  curr=curr->next;
  newNode->next=NULL;
 }
 curr=head;
 printf("Original List : \n");
 for(i=1;i<=n;i++){
  printf("%d \t",curr->data);
  curr=curr->next;
 }
 prev=NULL;
 next=NULL;
 curr=head;
 while(curr!=NULL){
  next=curr->next;
  curr->next=prev;
  prev=curr;
  curr=next;
 }
 head=prev;
 printf("After Reversal : \n");
 for(i=1;i<=n;i++){
  printf("%d \t",curr->data);
  curr=curr->next;
 }
 getch();
}













