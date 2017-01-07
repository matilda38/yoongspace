//
// Created by 황나윤 on 2017. 1. 5..
//

#include<iostream>
#include<string>

using namespace std;

string valid(string input){
    int cnt = 0;

    for(int i=0; i < input.size();i++){
        if(input[i]== '(' ){
            cnt += 1;
        }
        else if(input[i]==')'){
            cnt -= 1;
        }
        if(cnt < 0){
            return "NO";
        }
    }
    if(cnt == 0){
        return "YES";
    }
    else
        return "NO";

}

int main(){
    int n;
    cin >> n;

    while(n--){
        string input;
        cin >> input;
        cout << valid(input);
        cout << '\n';
    }
    return 0;
}