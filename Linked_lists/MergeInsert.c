#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linkedListnode{
    int data;
    struct linkedListnode* next;
};

typedef struct linkedListnode linkedListnode;

void freier(linkedListnode** head){
    linkedListnode* temp = *head;
    while (temp != NULL)
    {
        *head = (*head)->next;
        free(temp);
        temp = *head;
    }
    printf("Freeing completed");
}

void nodePrint(linkedListnode** head)
{
    linkedListnode* temp = *head;
    printf("Data from this linked list: \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void nodeInsert(int newData, linkedListnode** head, int* size)
{
    linkedListnode* temp = *head;
    while(temp->next != NULL) temp = temp->next;
    linkedListnode* newNode = malloc(sizeof(linkedListnode));
    newNode->data = newData;
    newNode->next = NULL;
    (*size)++;
}

void mergeSort(linkedListnode* firstHalf, linkedListnode* secondHalf, int firstSize, int secondSize)
{
    
}

void split(linkedListnode** head, int size)
{
    if(size == 1) return;
    int newSize1 = size / 2;
    int newSize2 = newSize1 + 1;
    linkedListnode* temp = *head;
    linkedListnode* temp2 = temp;
    for(int index = 0; index < newSize2; index++) temp2 = temp2->next;
    for(int index = 0; index < newSize1; index++) temp = temp->next; temp->next = NULL; temp = *head;
    split(temp, newSize1); 
    split(temp2, newSize2);

    mergeSort(newSize1, newSize2, newSize1, newSize2);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
