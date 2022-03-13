#include <iostream>
#include <string>
using namespace std;

int main(){
    for(int i =0;i < 100;i ++){
        string str;
        getline(cin, str);
        
        if(cin.eof())
            return 0;
        
        cout<<str<<"\n";
    }
}
