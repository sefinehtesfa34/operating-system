#include<stdio.h>
#include<stdlib.h>
struct Linkedlist{
    int data;
    struct Linkedlist*next;
};
void printList(struct Linkedlist*);
void push(struct Linkedlist**,int);
void pop(struct Linkedlist**);
void add(struct Linkedlist**,int,int);

int main(int argc, char const *argv[])
{  //define struct node
    struct Linkedlist*head=NULL;
    struct Linkedlist*second=NULL;
    struct Linkedlist*third=NULL;
    int data;
    
    head=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    second=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    third=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    
    head->data=2844;
    second->data=7229;
    third->data=1234;
    head->next=second;
    second->next=third;
    third->next=NULL;
    
    printf("push a node at the front of the linked list: \n");
    scanf("%d",&data);
    push(&head,data);
    pop(&head);
    add(&head,2000,3);
    
    printList(head);

    return 0;
}
void printList(struct Linkedlist* node){
    while (node!=NULL){
        printf("The data value: %d\n",node->data);
        node=node->next;
    }
}

void push(struct Linkedlist**temp,int data){
    struct Linkedlist*newNode=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    newNode->data=data;
    newNode->next=(*temp);
    (*temp)=newNode;
}

void pop(struct Linkedlist**temp){
    struct Linkedlist*newNode=(*temp);
    
    if ((newNode)->next==NULL){
        (newNode)=NULL;
    }
    while((newNode)->next->next!=NULL){

        (newNode)=(newNode)->next;
    }
    (newNode)->next=NULL;
}

void add(struct Linkedlist**head_refrernce,int data,int position){
    struct Linkedlist*newNode=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    struct Linkedlist*temp=(*head_refrernce);
    while (position>2){
        position-=1;
        temp=temp->next;
    }
    newNode->data=data;
    newNode->next=temp->next;
    temp->next=newNode;
    
}






























