//TRANSPOSE NOT WORKING LIKE IT SHOULD BE
#include <stdio.h>
#include <stdlib.h>

void accept(int a[10][10],int m,int n){
	int i,j;
	printf("\nEnter values of sparse matrix: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d",&a[i][j]);
		}
	}
}

void display(int a[10][10], int m,int n){
	int i,j;
	printf("\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int a[10][10],b[10][10],c[10][10],m,n,i,j,k;
	printf("\nEnter number of rows and columns for sparse matrix: ");
	scanf("%d%d", &m, &n);
	accept(a,m,n);
	display(a,m,n);
	
	//Sparse matrix to compact form
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
	printf("\nCompact form of the sparse matric is");
    display(b,k+1,3);

	//Transpose of compact form
	c[0][0]=b[0][1];
	c[0][1]=b[0][0];
	c[0][2]=b[0][2];
	int t=b[0][2];
	if(t<=0){
		printf("ERROR! transpose cannot be performed!");
		exit(0);
	}else{
		printf("Transpose of compact form of sparse matrix is: ");
		int q=1;
		for(int col=0;col<=n;col++){
			for(int p=1;p<=t;p++){
				if(a[p][1]==col){
					c[q][0]=b[q][1];
					c[q][1]=b[q][0];
					c[q][2]=b[q][2];
					q+=1;
				}
			}
		}
	}
	display(c,k+1,3);
	return 0;
}