//
// Created by 황나윤 on 2016. 12. 31..
//

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    char str= ' ';
    for (int i =1; i <= T ; i++){
        for(int j=0; j< T - i; j++){
            cout << str;
        }
        for(int j=0; j< i ; j++){
            cout << "*";
        }
        cout << '\n';
    }
    for (int i=1; i< T; i++){
        for(int j=0; j<i;j++){
            cout << str;
        }
        for(int j= T;  j > i; j--){
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}