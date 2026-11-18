#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1)
    {
        i++;

        if (i == SIZE)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[(index + i) % SIZE] = key;

    printf("Inserted %d at index %d\n",
           key, (index + i) % SIZE);
}

void display()
{
    int i;

    printf("\n--- Hash Table Contents ---\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
        {
            printf("Index %d: Empty\n", i);
        }
        else
        {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }

    printf("---------------------------\n");
}

int main()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    insert(12);
    insert(22);
    insert(42);
    insert(15);

    display();

    return 0;
}
