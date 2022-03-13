#include <iostream>
#include <string>
using namespace std;

string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int endOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month, date;

int main(){
    cin>>month>>date;
    
    for(int i = 0; i<month ; i++){
        date += endOfMonth[i];
    }
    //cout<< date/7 <<"\n";
    //cout<< date%7 <<"\n";
    
    cout<<days[date%7]<<"\n";
}
