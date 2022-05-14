#include<stdio.h>
#include<stdlib.h>
struct Linkedlist{
    int data;
    struct Linkedlist*next;
};
void printList(struct Linkedlist*);

int main(int argc, char const *argv[])
{  //define struct node
    struct Linkedlist*head=NULL;
    struct Linkedlist*second=NULL;
    struct Linkedlist*third=NULL;
    
    head=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    second=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    third=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
    
    head->data=2844;
    second->data=7229;
    third->data=1234;
    head->next=second;
    second->next=third;
    third->next=NULL;
    
    printList(head);

    return 0;
}
void printList(struct Linkedlist* node){
    while (node!=NULL){
        printf("The data value: %d\n",node->data);
        node=node->next;
    }
}