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

int binary_nonrecursive(int array[100], int key, int low, int high){
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

int binary_recursive(int a[100],int low, int high, int key){
    int mid;
    if(low<=high){
        mid=(low+high)/2;
        if(a[mid]==key){
            return mid;
        }else if(key<a[mid]){
            return binary_recursive(a, low, mid-1, key);
        }else{
            return binary_recursive(a, mid+1, high, key);
        }
    }else{
        return -1;
    }
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int bubble(int a[100], int n){
    int i,j;
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

void selection(int a[100], int n){
    int i,j,minpos;
    for(i=0;i<=n-2;i++){
        minpos=i;
        for(j=0;j<=n-1;j++){
            if(a[j]<a[minpos]){
                minpos=j;
            }
        }
        if(minpos!=i){
            swap(a[i],a[minpos]);
        }
    }
}

int main(){
    int a[100], n, low, high, i, key, ch1, ch2, ch3;
    printf("Welcome! \nEnter number of elements: ");
    scanf("%d",&n);

    low=0;
    high=n-1;

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

    printf("\n1.Search\n2.Sort\n3.Exit\nEnter choice: ");
    scanf("%d",&ch1);

    switch(ch1){
        case 1:
            printf("Search Choices:\n1.Sentinel Search\n2.Linear Search\n3.Binary Non-Recirsive Search\n4.Binary Recirsive Search\n5.Exit\nEnter choice: ");
            scanf("%d",&ch2);
                switch(ch2){
                    case 1: 
                        sentinel(a, key, n);
                        break;
                    case 2: 
                        linear(a, key, n);
                        break;
                    case 3: 
                        binary_nonrecursive(a, key, low, high);
                        break;
                    case 4: 
                        binary_recursive(a, low, high, key);
                        break;
                    case 5: 
                        printf("Thank you !");
                        exit(0);
                    default: 
                        printf("\nERROR! Operation not available!");
                }
            break;
        case 2:
            printf("Sort Choices:\n1.Bubble Search\n2.Selection Search\n3.Exit\nEnter choice: ");
            scanf("%d",&ch3);
                switch(ch3){
                    case 1: 
                        bubble(a,n);
                        break;
                    case 2: 
                        selection(a,n);
                        break;
                    case 3: 
                        printf("Thank you !");
                        exit(0);
                    default: 
                        printf("\nERROR! Operation not available!");
            break;
        }
    }
    return 0;
}