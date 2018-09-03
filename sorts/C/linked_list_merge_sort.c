#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};

struct node* merge(struct node *list1,struct node *list2){
 if(list1==NULL)
  return list2;
 if(list2==NULL)
  return list1;

  if(list1->data>list2->data){
   list2->next=merge(list1,list2->next);
   return list2;
  }
  else{
   list1->next=merge(list1->next,list2);
   return list1;
  }
}

struct node* mergesort(struct node* list){
 struct node *mid=NULL,*tmp=list;
 struct node *list1,*list2;
 if(list==NULL || list->next==NULL)
  return list;
 while(tmp && tmp->next){
  mid=mid?mid->next:tmp;
  tmp=tmp->next->next;
 }
 list2=mergesort(mid->next);
 mid->next=NULL;
 list1=mergesort(list);

 return merge(list1,list2);
}

void printList(struct node *head){
 while(head!=NULL){
  printf("%d\t",head->data);
  head=head->next;
 }
 printf("\n");
}

void main(){
 struct node *head,*newNode,*curr;
 int i;
 clrscr();
 head=(struct node*)malloc(sizeof(struct node));
 head->data=5;
 head->next=NULL;
 curr=head;
 for(i=4;i>0;i--){
  newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=i;
  curr->next=newNode;
  curr=curr->next;
 }
 printList(head);
 head=mergesort(head);
 printList(head);
 getch();
}
