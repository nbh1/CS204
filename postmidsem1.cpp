#include<bits/stdc++.h>
using namespace std;
long long int partition(long long int arr[], long long int l, long long int r, long long int k); 

long long int findMedian(long long int arr[], long long int n) 
{ 
    sort(arr, arr+n); 
    return arr[n/2];   
} 
  
long long int kthSmallest(long long int arr[], long long int l, long long int r, long long int k) 
{ 
   
    if (k > 0 && k <= r - l + 1) 
    { 
        long long int n = r-l+1; 
  
        
        long long int i, median[(n+4)/5];  
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        
        long long int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        
        long long int pos = partition(arr, l, r, medOfMed); 
  
         
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)   
            return kthSmallest(arr, l, pos-1, k); 
  
         
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    return  INT_MAX; 
} 
  
void swap(long long int *a, long long int *b) 
{ 
    long long int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
long long int partition(long long int arr[], long long int l, long long int r, long long int x) 
{ 
    long long int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    i = l; 
    for (long long int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
 int main(){
	long long int n;
	cin>>n;
	for(long long int i=0;i<n;i++){
		long long int w;
		cin>>w;
		long long int r;
		if(w%2==0){
			r=w/2;
		}
		if(w%2!=0){
			r=(w+1)/2;
		}
		long long int ax[w],ay[w];
		for(long long int j=0;j<w;j++){
			cin>>ax[j]>>ay[j];
		}
		long long int d[w];
		for (long long int v=0; v<w;v++){
			d[v]=(ax[v]*ax[v]+ay[v]*ay[v]);
		}
		float radius=sqrt(kthSmallest(d,0,w-1,r));
		cout<<"circle with smallest radius enclosing half polong long ints is"<<radius<<"\n";

	}
}