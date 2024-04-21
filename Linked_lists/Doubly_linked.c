#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Node
{
    int info;
    int key;
    struct Node* next;
    struct Node* previous;
};
typedef struct Node linkedListNode;

void createNode(linkedListNode* tail, int size, int value){
    linkedListNode* newNode = malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->key = size + 1;
    tail->next = newNode;
    newNode->previous = tail;
    newNode->next = NULL;
}

bool get(linkedListNode* head, linkedListNode* tail, int schlussel)
{
    linkedListNode* temp = head;
    linkedListNode* temp2 = tail;
    if(schlussel > tail->key){
        printf("No such cache data exists \n");
        return false;
    } else{
        for(int index = 0; index <= schlussel; index++) temp = temp->next;
        printf("Cache data fetch completed: %d", temp->info);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
