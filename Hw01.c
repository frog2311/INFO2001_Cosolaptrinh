// selection dai hon bubble  
#include <stdio.h> 
//bubble sort 
void bubbleSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) { 
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
	int a[10]={1,3,5,7,9,-2,-4,-6,-8,0};
	int i;
	
	bubbleSort(a,10);
	for(i=0;i<10;i++){
		printf("%d ", a[i]); 
	} 	
	
	selectionSort(a,10);
	for(i=0;i<10;i++){
		printf("%d ", a[i]); 
	} 
	return 0; 
} 

