#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int prn;
} Student;


int linearSearchPrn(Student arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i].prn == target) return i;
    }   
    return -1; 
}

int linearSearchName(Student arr[], int size, char target[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, target) == 0) return i; 
    }   
    return -1; 
}

int binarySearchPrn(Student arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].prn == target) return mid;
        if (arr[mid].prn < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchName(Student arr[], int size, char target[]) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = strcmp(arr[mid].name, target);
        if (res == 0) return mid;
        if (res < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}


void bubbleSort(Student arr[], int size, int sortByPrn) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int condition = sortByPrn; 
                (arr[j].prn > arr[j + 1].prn); 
                (strcmp(arr[j].name, arr[j + 1].name) > 0);
            
            if (condition) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(Student arr[], int size, int sortByPrn) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            int condition = sortByPrn; 
                (arr[j].prn < arr[minIdx].prn); 
                (strcmp(arr[j].name, arr[minIdx].name) < 0);
            
            if (condition) minIdx = j;
        }
        if (minIdx != i) {
            Student temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void insertionSort(Student arr[], int size, int sortByPrn) {
    for (int i = 1; i < size; i++) {
        Student key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && (sortByPrn ? (arr[j].prn > key.prn) : (strcmp(arr[j].name, key.name) > 0))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void displayStudents(Student arr[], int size) {
    printf("\n%-10s %-20s %-10s\n", "Index", "Name", "PRN");
    for (int i = 0; i < size; i++) {
        printf("%-10d %-20s %-10d\n", i, arr[i].name, arr[i].prn);
    }
}

int main() {
    int n, ch, subCh, target, found = -1;
    char targetn[50];

    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    Student students[n]; 

    printf("\n--- Enter Student Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("  Name: ");
        scanf("%s", students[i].name); 
        printf("  PRN: ");
        scanf("%d", &students[i].prn);
    }

    printf("\n------ MAIN MENU -----\n");
    printf("1. Search\n2. Sort\n3. Exit\nChoice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("\n--- Search Menu ---\n");
        printf("1. Linear Search by Name\n2. Linear Search by PRN\n");
        printf("3. Binary Search by Name\n4. Binary Search by PRN\nChoice: ");
        scanf("%d", &subCh);

        switch (subCh) {
            case 1:
                printf("Enter Name to search: ");
                scanf("%s", targetn);
                found = linearSearchName(students, n, targetn);
                break;
            case 2:
                printf("Enter PRN to search: ");
                scanf("%d", &target);
                found = linearSearchPrn(students, n, target);
                break;
            case 3:
                printf("Sorting records by Name first...\n");
                insertionSort(students, n, 0);
                displayStudents(students, n);
                printf("Enter Name to search: ");
                scanf("%s", targetn);
                found = binarySearchName(students, n, targetn);
                break;
            case 4:
                printf("Sorting records by PRN first...\n");
                insertionSort(students, n, 1);
                displayStudents(students, n);
                printf("Enter PRN to search: ");
                scanf("%d", &target);
                found = binarySearchPrn(students, n, target);
                break;
            default:
                printf("Invalid Choice!\n");
                return 0;
        }

        if (found != -1) {
            printf("\n--> Student Found at Index %d!\n", found);
            printf("    Name : %s\n", students[found].name);
            printf("    PRN  : %d\n", students[found].prn);
        } else {
            printf("\n--> Student not found.\n");
        }

    } else if (ch == 2) {
        int sortCriterion;
        printf("\n--- Sort Menu ---\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nChoice: ");
        scanf("%d", &subCh);
        
        printf("\nSort By:\n1. Name\n2. PRN\nChoice: ");
        scanf("%d", &sortCriterion);

        int sortByPrn = (sortCriterion == 2);

        switch (subCh) {
            case 1:
                bubbleSort(students, n, sortByPrn);
                break;
            case 2:
                selectionSort(students, n, sortByPrn);
                break;
            case 3:
                insertionSort(students, n, sortByPrn);
                break;
            default:
                printf("Invalid Choice!\n");
                return 0;
        }

        printf("\nSuccessfully Sorted Records:");
        displayStudents(students, n);
    }

    return 0;
}