#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "a.h"
#include<stdio.h>
#include<assert.h>
#define BUCKET_COUNT 1024
#define true 1
#define false 0
struct Binding{
    const char* key;
    int value;
    struct Binding* next;
};

struct HashTable{
    
    struct Binding* buckets[BUCKET_COUNT];
};

struct HashTable* create(){
    struct HashTable *hashThable=malloc(sizeof(struct HashTable)*BUCKET_COUNT);
    return hashThable;
}

unsigned int hash(const char* key){

    int total=0;
    for (size_t i = 0; i < strlen(key); i++)
    {
        total+=key[i];
    }
    return total%BUCKET_COUNT;    
}

bool add(struct HashTable* table, const char* key, int value){
    
    unsigned int hashValue=hash(key);
    struct Binding*temp=table->buckets[hashValue];
    
    if(temp==NULL){
    struct Binding*newBInding=malloc(sizeof(struct Binding));
        newBInding->key=key;
        newBInding->value=value;
        table->buckets[hashValue]=newBInding;
    return true;    
    }
    while (temp->next!=NULL){
        if (strcmp(key,temp->key)==0){
            temp->value=value;
            return false;
        }

        temp=temp->next;
    }
    if(strcmp(temp->key,key)==0){
        temp->value=value;
        return false;
    }
    struct Binding*newBInding=malloc(sizeof(struct Binding));
    newBInding->key=key;
    newBInding->value=value;
    newBInding->next=table->buckets[hashValue];
    table->buckets[hashValue]=newBInding;
    return true;
}

struct Binding* find(struct HashTable* table, const char* key){
    
    unsigned int hashValue=hash(key);
    struct Binding *temp=table->buckets[hashValue];
    while (temp!=NULL){
        if(strcmp(temp->key,key)==0){
            return temp;
        }
        temp=temp->next;

    }
    return NULL;
        
}
bool remover(struct HashTable* table, const char* key){
    unsigned int hashValue=hash(key);
    
    struct Binding*temp=table->buckets[hashValue];
    struct Binding*prev=NULL;

    if(temp==NULL){
        free(temp);
        temp=NULL;
        return false;
    }

    if(strcmp(temp->key,key)==0){
        struct Binding *first = table->buckets[hashValue];
        table->buckets[hashValue]=table->buckets[hashValue]->next;
        free(first);

        return true;
    }
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        
        if(strcmp(key,temp->key)==0){
            prev->next=temp->next;
            free(temp);
            temp=NULL;
            return true;
        }
    }
    return false;
        
}
void delete_table(struct HashTable* table){
    for (size_t i = 0; i < BUCKET_COUNT; i++)
    {
        if (table->buckets[i]!=NULL){
            free(table->buckets[i]);
        }
    }
    
    free(table);
}
void printer(struct HashTable* table,const char*key){
    unsigned int hashValue=hash(key);
    struct Binding * node=table->buckets[hashValue];
    while (node!=NULL)
    {
        printf("%d %d\n",node->value,hashValue);
        node=node->next;
    }
    

}

int main(int argc, char const *argv[])
{
    
struct HashTable* table = create();

    assert( find(table, "Test Key") == NULL);
    assert( add(table, "Test Key", 11) == true);
    assert( add(table, "abc", 10) == true);
    assert( add(table, "acb", 12) == true);
    assert( add(table, "cba", 13) == true);
    assert( add(table, "Test Key", 11) == false);
    struct Binding* binding =  find(table, "Test Key");
    assert( binding != NULL &&  binding->value == 11);
    assert(remover(table,"acb")==true);
    printer(table,"abc");
    delete_table(table);

    return 0;
}

