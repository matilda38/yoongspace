//
// Created by 황나윤 on 2016. 12. 31..
//

#include <iostream>

using namespace std;
int main(){
    int T;
    cin >> T;

    for(int i=1;i <= T; i++){
        for(int j= i;j<= T-1; j++){
            cout << ' ';
        }
        for(int j=0; j < i;j++){
            cout << "* ";
        }
        cout << '\n';
    }
    return 0;
}