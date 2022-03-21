#include <iostream>
#include <string>
#include<algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
#include <deque>
#include <cmath>
using namespace std;
#define MAX 1001
#define mod  10007

int arr[MAX][10];
int n;

//1. arr[i][j] = i 자리수 숫자 중 끝 숫자가 j 에 해당하는 가짓수
//2. 점화식 : arr[i][j] = arr[i-1][j] + ... + arr[i-1][9];

int solve(int num){
    
    for(int i = 2; i <= num; i++){
        for(int j = 0; j<= 9; j++){
            for(int k = j; k<= 9; k++){
                arr[i][j] += arr[i-1][k] % mod;
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i<= 9; i++){
        sum =  ( sum + arr[num][i] ) % mod;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    
    for(int i = 0; i<= 9; i++){
        arr[1][i] = 1;
    }
    
    cout << solve(n) <<"\n";


}
