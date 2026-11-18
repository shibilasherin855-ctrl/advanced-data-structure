#include <stdio.h>

#define MAX 100

int parent[MAX];

void makeSet(int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
}

int find(int i)
{
    while (parent[i] >= 0)
    {
        i = parent[i];
    }

    return i;
}

void unionSets(int i, int j)
{
    int rootI = find(i);
    int rootJ = find(j);

    if (rootI != rootJ)
    {
        parent[rootJ] = rootI;

        printf("Union completed: %d joined under %d\n",
               rootJ, rootI);
    }
    else
    {
        printf("Elements are already in the same set.\n");
    }
}

void display(int n)
{
    int i;

    printf("\nElement : ");

    for (i = 0; i < n; i++)
    {
        printf("%4d", i);
    }

    printf("\nParent  : ");

    for (i = 0; i < n; i++)
    {
        printf("%4d", parent[i]);
    }

    printf("\n");
}

int main()
{
    int n = 7;

    makeSet(n);

    printf("Initial Disjoint Sets:\n");
    display(n);

    unionSets(0, 1);
    unionSets(2, 3);
    unionSets(1, 3);
    unionSets(4, 5);

    printf("\nAfter Union Operations:\n");
    display(n);

    printf("\nRepresentative of element 3 is: %d\n",
           find(3));

    printf("Representative of element 5 is: %d\n",
           find(5));

    return 0;
}
