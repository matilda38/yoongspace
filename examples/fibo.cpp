#include<iostream>
#include<cstdlib>
#include<map>

using namespace std;
class Fibonacci
{
public:
  static map<int, long> fibomemo;
  static long fibo(int n);
};

map<int, long> Fibonacci::fibomemo;

long Fibonacci::fibo(int n)
{
  if(n < 0) return 0;
  if(n == 1) return 1;

  if(Fibonacci::fibomemo.find(n)!= Fibonacci::fibomemo.end())
  {
    return fibomemo[n];
  }
  else
  {
    long value = fibo(n-1)+fibo(n-2);
    Fibonacci::fibomemo[n] = value;
    return value;
  }
}
int main()
{
    int num;
    cin >> num;
    cout << Fibonacci::fibo(num);

    return 0;
}
