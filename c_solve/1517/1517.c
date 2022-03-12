#include <stdio.h>
#include <stdlib.h>

int n;
long long result;
int arr[500000];
int tmp[500000];

void merge_sort(int s, int e){
  if(s<e){
    int mid = (s+e)/2;
    
    merge_sort(s,mid);
    merge_sort(mid+1, e);
    
    int i=s, k=s, j=mid+1;//, tmp, 

    while(i<=mid && j<= e){
      if(arr[i] <= arr[j]){
        tmp[k] = arr[i];
        i++;
      }else{
        tmp[k] = arr[j];
        result += (mid-i+1);
        j++;
      }
      k++;
    }
    
    if(i > mid){
      for(int l = j; l<=e; l++){
        tmp[k] = arr[l];
        k++;
      }
    }else{
      for(int l = i; l<=mid; l++){
        tmp[k] = arr[l];
        k++;
      }
    }

    for(int l=s; l<=e; l++){
      arr[l] = tmp[l];
    }
  }
}

int main(void) {
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d", arr+i);
  }
  merge_sort(0,n-1);
  printf("%lld", result);
  
  return 0;
}