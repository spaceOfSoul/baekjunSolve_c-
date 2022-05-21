#include <iostream>
using namespace std;

bool arr[101][101];
int answer;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n=4;
    while(n--){
        int x,y,x2,y2;
        cin >> x>>y>>x2>>y2;
        for(int i=x; i< x2; i++){
            for(int j=y; j<y2; j++){
                arr[i][j] = true;
            }
        }
    }

    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(arr[i][j])
                answer++;
        }
    }
    cout << answer;
}