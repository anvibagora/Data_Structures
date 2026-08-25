#include <stdio.h>

#define size 5

struct Job
{
    int jobID;
    char documentTitle[50];
};

struct Job q[size];

int front = -1;
int rear = -1;

int isFull()
{
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

void enqueue(struct Job elem)
{
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = rear + 1;
        q[rear] = elem;
    }
}

struct Job dequeue()
{
    struct Job elem;

    if (isEmpty())
    {
        printf("Queue is empty\n");
        elem.jobID = -1;
        return elem;
    }
    else
    {
        front = front + 1;
        elem = q[front];
        return elem;
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = front + 1; i <= rear; i++)
        {
            printf("Job ID: %d\n", q[i].jobID);
            printf("Document Title: %s\n", q[i].documentTitle);
        }
    }
}

int main()
{
    int choice;
    struct Job elem;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &elem.jobID);

                printf("Enter Document Title: ");
                scanf(" %[^\n]", elem.documentTitle);

                enqueue(elem);
                break;

            case 2:
                elem = dequeue();

                if (elem.jobID != -1)
                {
                    printf("Job ID: %d\n", elem.jobID);
                    printf("Document Title: %s\n", elem.documentTitle);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}