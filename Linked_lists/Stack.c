#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
    char charctr;
    struct Node* next;
};

typedef struct Node Stack;

Stack* createNode(char inputChar){
    Stack* newNode = malloc(sizeof(Stack));
    newNode->charctr = inputChar;
    newNode->next = NULL;
    return newNode;
}

void freeNode(Stack* node){
    node->next = NULL;
    free(node); 
}

void freeList(Stack* Top) {
    Stack* current = Top;
    while (current != NULL) {
    Stack* temp = current;
    current = current->next;
    free(temp);
  }
}

void pushNode(Stack** top, char inputChar) {
    Stack* temp = *top;
    *top = createNode(inputChar);
    (*top)->next = temp;
}

char popNode(Stack** top){
    Stack* temp = (*top)->next;
    char output = (*top)->charctr;
    freeNode(*top);
    *top = temp;
    return output;
}

int main(int argc, char const *argv[])
{
    Stack* topoStack;
    char iterator;
    char newChar[] = "My Brother, shit is edible if you tried hard enough";
    int len = strlen(newChar);
    for (int index = 0; index < len; index++) pushNode(&topoStack, newChar[index]);
    printf("The current string: \n"); printf("%s", newChar); printf("\n");
    printf("The reversed string: \n");
    for (int index = 0; index < len; index++)
    {
        iterator = popNode(&topoStack);
        printf("%c", iterator);
    }
    printf("\n");
    return 0;
}
