//
// Created by 황나윤 on 2016. 12. 31..
//

#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int N = T;
    int len = 2*T-1;
    int star_num;
    char em_str = ' ';
    //N줄 출력
    for(int j = 0;j <T; j++) {
        star_num = len - 2*j;
        for(int i=0; i < j ; i++){
            cout << em_str;
        }
        for (int i = 0; i < star_num ; i++) {
            cout << "*";
        }
        cout << '\n';
    }

    for(int j = 1; j < T; j ++){
        star_num = 2*j+1;
        for(int i=T-1; i > j; i--){
            cout << em_str;
        }
        for(int i = 0; i < star_num; i++){
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}