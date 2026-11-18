#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty()
{
    return top == NULL;
}

void push(int value)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack.\n", value);
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! The stack is empty.\n");
        return;
    }

    struct Node *temp = top;

    printf("Popped element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display()
{
    struct Node *temp = top;

    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements are:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n* STACK OPERATIONS *\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
