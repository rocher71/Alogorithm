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
#define MAX 1000001

int arr[MAX];
int x;

// 1. Bottom-up, [2], [3] 채워두고 시작
// 2. 새 숫자 x 만나면
//      1) -1 -> arr[-1] +1
//      2) x%2 == 0 -> arr[x/2] + 1
//      3) x%3 == 0 -> arr[x/3] + 1
// 3. 위 세개 중 최소값을 arr[x] 에 저장, arr[입력받은 수] 출력함

int solve(int num){
    
    for(int i = 4; i<= num; i++){
        int ans = MAX;
        
        ans = min(arr[i-1]+1, ans);
        
        if(i%2 == 0)
            ans = min(ans, arr[i/2]+1);
        if(i%3 == 0)
            ans = min(ans, arr[i/3]+1);
        
        arr[i] = ans;
    }
    return arr[num];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    
    cin>>x;
    
        
    cout << solve(x) <<"\n";
    
    
}
