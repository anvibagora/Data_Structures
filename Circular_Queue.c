#include <stdio.h>

#define n 5

struct Job
{
    int jobID;
    char documentTitle[50];
};

struct Job q[n];

int front = 0;
int rear = 0;

int isFull()
{
    if ((rear + 1) % n == front)
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
        printf("Queue Overflow! Print queue is full.\n");
    }
    else
    {
        rear = (rear + 1) % n;
        q[rear] = elem;
        printf("Print job added successfully.\n");
    }
}

struct Job dequeue()
{
    struct Job elem;

    if (isEmpty())
    {
        printf("Queue Underflow! No print jobs available.\n");
        elem.jobID = -1;
        return elem;
    }
    else
    {
        front = (front + 1) % n;
        elem = q[front];
        return elem;
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        i = (front + 1) % n;

        while (i != (rear + 1) % n)
        {
            printf("Job ID: %d\n", q[i].jobID);
            printf("Document Title: %s\n", q[i].documentTitle);

            i = (i + 1) % n;
        }
    }
}

/* Clears leftover bad input from stdin after a failed scanf */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
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
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("Enter Job ID: ");
                if (scanf("%d", &elem.jobID) != 1)
                {
                    printf("Invalid Job ID.\n");
                    clearInputBuffer();
                    break;
                }

                printf("Enter Document Title: ");
                scanf(" %49[^\n]", elem.documentTitle);

                enqueue(elem);
                break;

            case 2:
                elem = dequeue();

                if (elem.jobID != -1)
                {
                    printf("Processed Print Job:\n");
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
                printf("Invalid choice.\n");
        }
    }

    return 0;
}