#include<pthread.h> 
#include<stdio.h>
#include<asm/unistd.h>

int sum;
int m1[100][100];
int m2[100][100];

void* RowColProduct(void* param);

int main(){
	int m, n, k1, k2;
	printf("Enter dimensions of matrix 1 : ");
	scanf("%d %d", &m, &k1);
	printf("Enter dimensions of matrix 2 : ");
	scanf("%d %d", &k2, &n);

	if(k1 <= 0 || k2 <= 0 || m <= 0 || n <= 0 || k1 != k2){
		printf("Can't Multiply, Inconsistent dimensions");
		return 0;
	}

	int i, j;
	printf("Enter Matrix 1 : \n");
	for(i=0; i<m; i++){
		for(j=0; j<k1; j++){
			scanf("%d", &m1[i][j]);
		}
	}

	printf("Enter Matrix 2 : \n");
	for(i=0; i<k2; i++){
		for(j=0; j<n; j++){
			scanf("%d", &m2[i][j]);
		}
	}

	pthread_t tid[m][n];

	int arr[m][n][3];
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			arr[i][j][0] = i;
			arr[i][j][1] = j;
			arr[i][j][2] = k1;
		}
	}

	sum = 0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			pthread_attr_t attr; 
			pthread_attr_init(&attr);
			pthread_create(&tid[i][j], &attr, RowColProduct, arr[i][j]);
		}
	}

	int ans[m][n];

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			pthread_join(tid[i][j], (void *) &ans[i][j]);
		}
	}
	printf("Product is: \n");

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}

void* RowColProduct(void* param){
	int i;
	int val = 0;
	int *arr = (int *) param;
	int r = arr[0];
	int c = arr[1];
	int d = arr[2];

	for(i=0; i<d; i++){
		val += (m1[r][i] * m2[i][c]);
	}
	return((void *) val);
}