#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<deque>
using namespace std;
#define MAX 1001

int arr[MAX];
int n;

int solve(int n)
{
    for(int i = 4; i<=n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
        //cout<< i <<" "<< arr[i]<<"\n";
    }
    return arr[n];
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    
    cin>>n;
    
    cout<< solve(n) <<"\n";
    
}

