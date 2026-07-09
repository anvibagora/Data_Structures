//GOTTA WORK ON THIS 

#include <stdio.h>

void accept(int a[10][10],int m,int n){
	int i,j;
	printf("\nEnter values of matrix: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d",&a[i][j]);
		}
	}
}

void display(int a[10][10], int m,int n){
	int i,j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int a[10][10], b[10][10], m, n,i,j,k;
	
	printf("\nEnter number of rows and columns for matrix: ");
	scanf("%d%d", &m, &n);
	accept(a,m,n);
	display(a,m,n);

    b[0][0]=m;
    b[0][1]=n;
    k=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                k++;
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
            }
        }
    }
    b[0][2]=k;

    display(b,m+1,3);
}