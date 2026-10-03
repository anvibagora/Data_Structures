#include <stdio.h>
#include <stdlib.h>

struct node {
    int RollNo;
    char Name[50];
    struct node *next;
};

void create(struct node *H) {
    struct node *temp = H;
    char choice;
    
    do {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter Roll Number : ");
        scanf("%d", &curr->RollNo);
        printf("Enter Name : ");
        scanf("%s", curr->Name);
        curr->next = NULL;
        temp->next = curr;
        temp = curr; 
        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void display(struct node *H) {
    if (H->next == NULL) {
        printf("list is empty\n");
    } else {
        struct node *curr = H->next;
        printf("\nLinked List elements: ");
        while (curr != NULL) {
            printf("%d \t %s ", curr->RollNo, curr->Name);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int len(struct node *H) {
    int i = 0;
    struct node *curr = H->next;
    while (curr != NULL) {
        i++;
        curr = curr->next;
    }
    return i;
}

void InsertionByPos(struct node *H) {
    int i = 0, pos, k;
    struct node *curr = H;
    struct node *nnode = (struct node *)malloc(sizeof(struct node));

    k = len(H);
    
    if (pos > k + 1 || pos < 1) {
        printf("Data can't be inserted\n");
        free(nnode);
    } else {
        while (curr != NULL && i < pos - 1) {
            i++;
            curr = curr->next;
        }
        
    	printf("Enter Roll Number: ");
    	scanf("%d", &nnode->RollNo);
    	printf("Enter Name: ");
    	scanf("%s", nnode->Name);
    	printf("Enter position: ");
    	scanf("%d", &pos);
    	nnode->next = NULL;
        
        if (curr != NULL) {
            nnode->next = curr->next;
            curr->next = nnode;
            printf("Node inserted successfully at position %d.\n", pos);
        }
    }
}

int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    
    int choice;
    
    while (1) {
        printf("\nSingly Linked List Menu\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Find Length\n");
        printf("4. Insert by Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Length of linked list: %d\n", len(head));
                break;
            case 4:
                InsertionByPos(head);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    }
    
    return 0;
}