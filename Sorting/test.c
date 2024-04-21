#include <stdio.h>

int main(int argc, char const *argv[])
{
    int random_array[] = {3, 2, 56, 12, 11, 98, 34, 123};
    int count = 8;
    printf("Unsorted Array: ");
    for (int index = 0; index < count; index++)
    {
        printf("%d", random_array[index], " ");
    }
    
    InsertionSort(random_array);

    printf("The ");
    return 0;
}

