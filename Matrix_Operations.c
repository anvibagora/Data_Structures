# include <stdio.h>
# include <stdlib.h>

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

void addition(int a[10][10], int b[10][10], int m, int n, int x, int y){
	int c[10][10],i ,j;
	if(x==m && y==n){
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				c[i][j] = a[i][j] + b[i][j];
			}
		}
	}
	display(c,m,n);
}
	
void subtraction(int a[10][10], int b[10][10], int m, int n, int x, int y){
	int c[10][10],i ,j;
	if(x==m && y==n){
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				c[i][j] = a[i][j] - b[i][j];
			}
		}
	}
	display(c,m,n);
}

void multiplication(int a[10][10], int b[10][10], int m, int n, int x, int y){
	int c[10][10]={0},i ,j,k;
	if(n==x){
		for(i=0; i<m; i++){
			for(j=0; j<y; j++){
				c[i][j]=0;
				for(k=0; k<n; k++){
					c[i][j] += a[i][k] * b[k][j];
				}	
			}
		}
	}
	display(c,m,y);
}

void transpose(int a[10][10], int m, int n){
	int c[10][10],i ,j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			c[i][j] = a[j][i];
		}
	}
	display(c,m,n);
}

int main(){
	int a[10][10], b[10][10], m, n, ch, x, y;
	
	printf("\nEnter number of rows and columns for matrices A: ");
	scanf("%d%d", &m, &n);
	accept(a,m,n);
	display(a,m,n);
	printf("\nEnter number of rows and columns for matrices A: ");
	scanf("%d%d", &x, &y);
	accept(b,x,y);
	display(b,x,y);
	
	while(1){
		printf("\n1. Addition");
		printf("\n2. Subtarction");
		printf("\n3. Multiplication");
		printf("\n4. Transpose");
		printf("\n5. Exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1: addition(a,b,m,n,x,y);
				break;
			case 2: subtraction(a,b,m,n,x,y);
				break;
			case 3: multiplication(a,b,m,n,x,y);
				break;
			case 4: transpose(a,m,n);
				break;
			case 5: exit(0);
				break;
			default: printf("ERROR! Operation does not exist!");
		}
	
}
}
