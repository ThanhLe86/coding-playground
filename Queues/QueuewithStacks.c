#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Stacks;

typedef struct Queue{
    Stacks* stack1;
    Stacks* stack2;
} Queue;

int popNode(Stacks** enqueueNodetop){
    Stacks* temp = (*enqueueNodetop)->next;
    int output = (*enqueueNodetop)->data;
    free(*enqueueNodetop);
    *enqueueNodetop = temp;
    return output;
}

void pushNode(Stacks** top, int data)
{
    Stacks* temp = *top;
    if(temp == NULL){
        temp = malloc(sizeof(Stacks));
        temp->data = data;
        temp->next = NULL;
    } else{
        Stacks* newNode = malloc(sizeof(Stacks));
        newNode->data = data;
        newNode->next = temp;
        *top = newNode;
    }
    
}

Queue* queueInit()
{
    Stacks* stack1 = NULL;
    Stacks* stack2 = NULL;
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->stack1 = stack1;
    newQueue->stack2 = stack2;
    return newQueue;
}

void Enqueue(int data, Queue** currentQueue) 
{
    Stacks* temp = (*currentQueue)->stack1;
    if(temp == NULL){
        temp = malloc(sizeof(Stacks));
        temp->data = data;
        temp->next = NULL;
    } else{
        Stacks* newNode = malloc(sizeof(Stacks));
        newNode->data = data;
        newNode->next = temp;
    }
}

int Dequeue(Queue** currentQueue)
{
    Stacks* stack2 = (*currentQueue)->stack2;
    Stacks* stack1 = (*currentQueue)->stack1;
    while (stack1 != NULL)
    {
        int dequeueData = popNode(&stack1);
        pushNode(&stack2, dequeueData);
    }
    int dequeued = popNode(&stack2);
    return dequeued; 
}

void printQueue(Queue* queue)
{
    Stacks* stack2 = queue->stack2;
    Stacks* stack1 = queue->stack1;
    while (stack1 != NULL)
    {
        int dequeueData = popNode(&stack1);
        pushNode(&stack2, dequeueData);
    }
    Stacks* temp = stack2;
    printf("The current queue is as follows: \n");
    while (temp != NULL) printf("%d ", temp->data);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
