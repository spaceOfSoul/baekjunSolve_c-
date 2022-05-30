#include <stdio.h>

int n;
int arr[10000];
int dp[10000];

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    dp[0]=arr[0];dp[1]=arr[0]+arr[1];
    dp[2]=max(dp[1],max(arr[2]+arr[1], arr[2]+arr[0]));
    for(int i=3; i<n; i++){
        dp[i] = max(arr[i]+arr[i-1]+dp[i-3], arr[i]+dp[i-2]);
        dp[i] = max(dp[i],dp[i-1]);
    }
    printf("%d",dp[n-1]);
}