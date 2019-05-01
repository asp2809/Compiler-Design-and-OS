
#include<bits/stdc++.h>
using namespace std;
#include "symTab.h"


#define CHAIN_LENGTH 53
#define M 128


struct symbol_info{
    const char *name;
    const char *classtype;
    int size;
    struct symbol_info *next;
} *block[CHAIN_LENGTH];


int Hash(const char* name){
    int idx = 0;
    for(int i = 0; name[i]; ++i){
        idx = idx + name[i];
    }
    return (idx % CHAIN_LENGTH);
}

void insertSymTab(const char* name, const char* classtype, int size){
    int pos = Hash(name);

    if( block[pos] == NULL ){
        block[pos] = new symbol_info();
        block[pos]->name = name;
        block[pos]->classtype = classtype;
        block[pos]->size = size;
        block[pos]->next = NULL;
    }
    else{
        symbol_info* newNode = new symbol_info();
        newNode->name = name;
        newNode->classtype = classtype;
        newNode->size = size;

        symbol_info* nextNode = block[pos];
        block[pos] = newNode;
        newNode->next = nextNode;
    }
}


bool searchSymTab(const char* name){
    int pos = Hash(name);

    symbol_info* temp = block[pos];

    while( temp != NULL ){
        if( !strcmp( temp->name, name )){
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void printTable(){
    for(int i = 0; i < CHAIN_LENGTH; ++i){
        symbol_info* temp = block[i];

        while( temp != NULL ){
            if (temp->name != NULL && temp->size != -1){
                printf("%s %s Size: %d", temp->classtype, temp->name, temp->size);
                temp = temp->next;
                printf("\n");
            }
            else{
                printf("%s %s", temp->classtype, temp->name);
                temp = temp->next;
                printf("\n");
            }
        }
    }
}
