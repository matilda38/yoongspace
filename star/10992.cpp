//
// Created by 황나윤 on 2016. 12. 31..
//


#include <iostream>

using namespace std;
int main(){
    int T, len;
    cin >> T;
    len = T*2-1;
    for(int i=0; i< T; i++){
        for(int j=i;j<T-1;j++){
            cout << " ";
        }
        if(i==0){
            cout << "*";
        }
        else if(i==T-1){
            for(int j=0;j< len;j++){
                cout << "*";
            }
        }
        else{
            cout << "*";
            for(int j=0; j< 2*i-1;j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << '\n';
    }
}