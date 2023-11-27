 #include <stdio.h>

//tim kiem tuyen tinh 
int linearSearch(int a[], int n,int x){
	int i;
	for(i=0;i<n;i++){
		if(x==a[i]){
			return i+1; 
		} 
	} 
	return 0; 
} 

//sap xep ham tu nho den lon 
void sorting(int a[], int n){
	int i,o;
	int s=a[0]; 
	for(i=0;i<n-1;i++){
		for(o=0;o<n-i-1;o++){
		 	if(a[i]>a[o]){
		 		int s=a[i];
				a[i]=a[o];
				a[o]=s; 
			} 
		} 
	} 
} 

//tim kiem nhi phan
int binarySearch(int a[], int n, int x){
	int i, s=n/2;
	while(){
    	if(x==a[s]){
		    return a[s]; 
	    } 
	    if(x<a[s]){
		    for(i=0;i<s;i++){
		    	if(x==a[i]){
		    		return i+1; 
				} 
			} 
	    } else{
		    for(i=s+1;i<n;i++){
		    	if(x==a[i]){
		    		return i+1; 
				} 
			}	    	
		} 
	} 
	return 0; 
} 
int main(){
	int a[10]={1,3,5,7,-6,-2,-4,-6,-8,0};
	
	int x;
	printf("nhap vao gia tri x can tim : ");
	scanf("%d", &x);
	 
	int m=linearSearch(a, 10, x);
	
	if(m!=0){
		printf("tim thay gia tri %d trong mang tai vi tri %d ", x,m); 
	} else{
		if(x==0){
			printf("tim thay gia tri %d trong mang tai vi tri %d ", x,m); 
		} else{
			printf("khong tim thay gia tri %d trong mang", x); 
		} 
	} 
	
	return 0; 
} 

