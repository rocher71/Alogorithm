#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>

using namespace std;

int cnt[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int room;
    cin>> room;

    while(room > 0){
        cnt[room%10]++;
        room /= 10;
    }

    cnt[6] = ceil(((cnt[6] + cnt[9]) /2.0));
    cnt[9] = cnt[6];

    sort(cnt, cnt+10);
    cout<< cnt[9]<<"\n";

    return 0;
}
