#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node* Queue;
Queue Create_Node(){
    Queue newNode = malloc(sizeof(struct Node));
    newNode->data = 20;
    newNode->next = NULL;
}

void freeList(Queue Top) {
    Queue current = Top;
    while (current != NULL) {
    Queue temp = current;
    current = current->next;
    free(temp);
  }
}

void Enqueue(Queue addage, Queue tail){
    tail->next = addage;
    tail = addage;
}

void Dequeue(Queue head){
    Queue Temp = head;
    head = head->next;
    free(Temp);
}

int main(int argc, char const *argv[])
{
    Queue head = Create_Node();
    Queue tail = head;   
    
    return 0;
}
