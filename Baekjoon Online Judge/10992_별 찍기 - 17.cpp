#include <iostream>
#include <string>
using namespace std;

int n;

int main(){
    
    cin>>n;
    
    if(n == 1){
        cout<<"*\n";
        return 0;
    }
    
    for(int i=0;i <n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout<<" ";
        }
        cout<<"*";
        
        if(i == 0){
            cout<<"\n";
            continue;
        }
        
        for(int j = 0; j< 2*i - 1; j++){
            cout<<" ";
        }
        cout<<"*\n";
    }
    
    for(int i = 0;i < 2 * n -1 ; i++){
        cout<<"*";
    }
    cout<<"\n";
}
