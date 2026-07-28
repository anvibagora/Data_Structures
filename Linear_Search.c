#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
char name[50];
int prn;
} Student;

int linearSearchPrn(Student arr[], int size, int target) {
for (int i = 0; i < size; i++) {
        if (arr[i].prn == target) {
            return i;
        }
    }
    return -1;
}

int linearSearchName(Student arr[], int size, char target[50]) {
for (int i = 0; i < size; i++) {
        if (arr[i].name == target) {
            return i;
        }
    }
    return -1;
}

int main() {
int n, ch, target, found;
char targetn[50];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];


    printf("\n--- Enter Student Details ---\n");
    for (int i = 0; i < n; i++) {
printf("\nStudent %d:\n", i + 1);

printf("  Name: ");
scanf("%s", students[i].name);

printf("  PRN: ");
scanf("%d", &students[i].prn);
    }


    printf("\n-----------------------------\n");
    printf("Search by 1.Name or 2. PRN\n");
    scanf("%d",&ch);
    switch(ch){
    case 1:
    printf("Enter Name  to search: ");
scanf("%s", targetn);
    found= linearSearchName(students, n, targetn);
    break;
    case 2:
printf("Enter PRN  to search: ");
scanf("%d", &target);
    found= linearSearchPrn(students, n, target);
    break;
    case 3:
    printf("ERROR! Operation not available");
    break;
    default:
    exit(0);
    }


    if (found != -1) {
printf("\nStudent Found at Index %d!\n", found);
printf("  Name  : %s\n", students[found].name);
printf("  PRN  : %d\n", students[found].prn);
    } else {
        printf("\nStudent with not found.\n");
    }

    return 0;
}