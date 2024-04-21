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

void nodeInsert(int Inputdata, linkedListnode** head)
{
    linkedListnode* newNode = malloc(sizeof(linkedListnode));
    newNode->next = NULL;
    newNode->data = Inputdata;

    linkedListnode* temp = *head;
    if(*head == NULL) {
        *head = newNode;
        temp = *head;
    } 
    else if((*head)->next == NULL)
    {
        if((*head)->data > Inputdata)
        {
            *head = newNode;
            (*head)->next = temp;
            temp->next = NULL;
            temp = *head;
        } else (*head)->next = newNode;
    }
    else {
        linkedListnode* fastTemp = (*head)->next;
        while (fastTemp != NULL && fastTemp->data <= Inputdata){
            fastTemp = fastTemp->next;
            temp = temp->next;
        }
        if(temp->data > Inputdata) 
        {
            *head = newNode;
            (*head)->next = temp;
        } 
        else {
            temp->next = newNode;
            newNode->next = fastTemp;
        }
    }
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

int main(int argc, char const *argv[])
{
    linkedListnode* head = NULL;
    int fata, n;
    printf("Enter number of new nodes: "); scanf("%d", &n); printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter data of node number %d: ", i); scanf("%d", &fata); printf("\n");
        nodeInsert(fata, &head);
    }

    nodePrint(&head);
    printf("\n");
    freier(&head);

    return 0;
}
