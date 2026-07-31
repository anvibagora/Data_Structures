#include <stdio.h>
#include <math.h>

struct poly{
    int coef;
    int exp;
};

int main(){
    int max1,max2,i,x;
    struct poly p1[100],p2[100],p3[100];
    printf("Number of terms in 1st polynomial: ");
    scanf("%d",&max1);
    for(i=0;i<max1;i++){
        printf("Coeffecient: ");
        scanf("%d",&p1[i].coef);
        printf("Exponential: ");
        scanf("%d",&p1[i].exp);
    }
    printf("Number of terms in 2st polynomial: ");
    scanf("%d",&max2);
    for(i=0;i<max2;i++){
        printf("Coeffecient: ");
        scanf("%d",&p2[i].coef);
        printf("Exponential: ");
        scanf("%d",&p2[i].exp);
    }
    printf("Value of x: ");
    scanf("%d",&x);
    
}

void polyeval(struct poly p[100], int max1, int x){
    int sum=0;
    int i;
    for(i=0;i<=max1;i++){
        sum += p[i].coef*pow(x,p[i].exp);
    }
    return sum;
}

void polyadd(struct poly p1[100], struct poly p2[100], int max1, int max2){
    int i=0,j=0,k=0;
    int temp;
    struct poly p3[100];
    while(i<max1 && j<max2){
        if(p1[i].exp>p2[j].exp){
            p3[k]=p1[i];
            k++;
            i++;
        }else if(p1[i].exp<p2[j].exp){
            p3[k]=p2[i];
            k++;
            j++;
        }else{
            temp=p1[i].coef+p2[j].coef;
            if(temp!=0){
                p3[k].exp=p1[i].exp;
                p3[k].coef=temp;
                i++;
                j++;
                k++;
            }
        }
    }
    while(i<max1){
        p3[k]=p1[i];
        k++;
        i++;
    }
    while(i<max1){
        p3[k]=p2[j];
        k++;
        j++;
    }
}

