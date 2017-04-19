/*
첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.
*/

#include<iostream>

using namespace std;

int main(){
  int A, B, C;

  cin >> A >> B >> C;
  A %= C;
  B %= C;
  int num = (A+B) %C;
  cout << num << endl;
  cout << num << endl;

  num = (A*B)%C;
  cout << num <<endl;
  cout << num << endl;

  return 0;
}
