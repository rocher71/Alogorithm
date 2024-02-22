#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>

using namespace std;

int arr[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, mult;
    cin>>a>>b>>c;
    mult = a*b*c;

    do {
        arr[mult%10]++;
        mult /= 10;
    } while (mult > 0);

    for(auto i : arr)
        cout<< i<< "\n";

    return 0;
}
