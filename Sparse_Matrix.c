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
	int a[10][10],b[10][10],c[10][10],d[10][10],m,n,i,j,k,q;
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

	//Simple transpose of compact form
	int t = b[0][2];
	if(t<=0){
		printf("ERROR! transpose cannot be performed!");
		exit(0);
	}else{
		c[0][0]=b[0][1];
		c[0][1]=b[0][0];
		c[0][2]=b[0][2];
		printf("Transpose of compact form of sparse matrix by Simple Transpose is: ");
		q=1;
		for(int col=0;col<n;col++){
			for(int p=1;p<=t;p++){
				if(b[p][1]==col){
					c[q][0]=b[p][1];
					c[q][1]=b[p][0];
					c[q][2]=b[p][2];
					q++;
				}
			}
		}
	}
	display(c,q,3);
	
	//Fast Transpose
	//s[n] is array for frequency of column number
	//t[n] is array to store index at which they start storing in transpose
	int S[n],T[n];
	d[0][0]=b[0][1];
	d[0][1]=b[0][0];
	d[0][2]=b[0][2];
	if(t<=0){
		printf("ERROR! transpose cannot be performed!");
		exit(0);
	}else{
		for(i=0;i<n;i++){
			S[i]=0;
		}
		for(i=0;i<=t;i++){
			S[b[i][1]]=S[b[i][1]]+1;
		}
		T[0]=1;
		for(i=1;i<n;i++){
			T[i]=T[i-1]+S[i-1];
		}
		for(i=0;i<=t;i++){
			j=b[i][1];
			d[T[j]][0] = b[i][1];
			d[T[j]][1] = b[i][0];
			d[T[j]][2] = b[i][2];
			T[j]=T[j]+1;
		}
	}
	printf("Transpose of compact form of sparse matrix by Fast Transpose is: ");
	display(d,q,3);
	return 0;
}