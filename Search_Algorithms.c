//A LOT OF CORRECTIONS ARE NEEDED

#include <stdio.h>
#include <stdlib.h>

int sentinel(int array[100], int key, int n){
    array[n]=key;
    int i=0;
    while(key!=array[i]){
        i++;
    }
    if(i<n){
        return i;
    }else{
        return -1;
    }
}

int linear(int array[100], int target, int n){
    int i;
    for(i=0;i<n;i++){
        if(array[i]==target){
            printf("\nTarget data found!");
            return i;
        }
    }
    if(i>=n){
        return -1;
    }
}

int binary(int array[100], int key, int n){
    int low=0;
    int high = n-1;
    int mid, flag;
    while(low<=high){
        mid = (low+high)/2;
        if(array[mid]==key){
            flag=1;
            return flag;
        }else if(key<array[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(flag==0){
        return flag;
    }
}

int main(){
    int a[100], n, i, key, ch;
    printf("Welcome! \nEnter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("The array is: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\nEnter element to find: ");
    scanf("%d",&key);

    printf("Search Choices:\n1.Sentinel Search\n2.Linear Search\n3.Binary Search\n4.Exit\nChoice of Search: ");
    scanf("%d",&ch);
    while(1){
        switch(ch){
            case 1: 
                sentinel(a, key, n);
                break;
            case 2: 
                linear(a, key, n);
                break;
            case 3: 
                binary(a, key, n);
                break;
            case 4: 
                printf("Thank you !");
                exit(0);
            default: 
                printf("\nERROR! Operation not available!");
                break;
        }
    }
}