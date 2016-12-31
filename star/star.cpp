#include<iostream>

using namespace std;

int main(){
    string str = " ";
    int T;
    cin >> T;
    int arr_len=2*T;
    int len,num;

    //N줄 출력
    for(int j= 1; j <= T; j++) {
        num = 2*j;
        len = (arr_len - num);
        for (int i = 0; i < j; i++) {
            cout << "*";
        }
        for(int i= 0; i < len; i++){
            cout << str;
        }
        for (int i = 0; i < j; i++) {
            cout << "*";
        }
        cout << '\n';
    }

    for(int j= T; j > 1; j--) {
        num = 2*(j-1);
        len = (arr_len - num);
        for (int i = 0; i < j-1; i++) {
            cout << "*";
        }
        for(int i= 0; i < len; i++){
            cout << str;
        }
        for (int i = 0; i < j-1; i++) {
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}