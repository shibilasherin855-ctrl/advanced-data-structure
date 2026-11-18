#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool contains(int set[], int size, int element)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (set[i] == element)
        {
            return true;
        }
    }

    return false;
}

void printSet(int set[], int size)
{
    int i;

    printf("{ ");

    for (i = 0; i < size; i++)
    {
        printf("%d", set[i]);

        if (i < size - 1)
        {
            printf(", ");
        }
    }

    printf(" }\n");
}

void findUnion(int A[], int sizeA,
               int B[], int sizeB)
{
    int result[MAX];
    int count = 0;
    int i;

    for (i = 0; i < sizeA; i++)
    {
        result[count++] = A[i];
    }

    for (i = 0; i < sizeB; i++)
    {
        if (!contains(result, count, B[i]))
        {
            result[count++] = B[i];
        }
    }

    printf("Union (A U B): ");
    printSet(result, count);
}

void findIntersection(int A[], int sizeA,
                      int B[], int sizeB)
{
    int result[MAX];
    int count = 0;
    int i;

    for (i = 0; i < sizeA; i++)
    {
        if (contains(B, sizeB, A[i]))
        {
            result[count++] = A[i];
        }
    }

    printf("Intersection (A n B): ");
    printSet(result, count);
}

void findDifference(int A[], int sizeA,
                    int B[], int sizeB,
                    const char *label)
{
    int result[MAX];
    int count = 0;
    int i;

    for (i = 0; i < sizeA; i++)
    {
        if (!contains(B, sizeB, A[i]))
        {
            result[count++] = A[i];
        }
    }

    printf("%s", label);
    printSet(result, count);
}

int main()
{
    int setA[] = {1, 3, 5, 7, 9};
    int setB[] = {2, 3, 5, 8, 9, 10};

    int sizeA = 5;
    int sizeB = 6;

    printf("Set A: ");
    printSet(setA, sizeA);

    printf("Set B: ");
    printSet(setB, sizeB);

    printf("-----------------------------------\n");

    findUnion(setA, sizeA, setB, sizeB);

    findIntersection(setA, sizeA, setB, sizeB);

    findDifference(setA, sizeA, setB, sizeB,
                   "Difference (A - B): ");

    findDifference(setB, sizeB, setA, sizeA,
                   "Difference (B - A): ");

    return 0;
}
