#include <iostream>

using namespace std;

int gcd(int num1, int num2){
  if(num2 == 0){
    return num1;
  }
  else{
    return gcd(num2, num1 % num2);
  }
}

int main(){
  int A, B;
  cin >> A >> B;
  int GCD;
  //using Euclidean Hoje
  GCD = gcd(A,B);
  cout << "최대공약수는 : " << GCD << endl;
  cout << "최소공배수는 : " << A*B/GCD << endl;

  return 0;

}
