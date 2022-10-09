#include <iostream>
using namespace std;

int main()
{
  int i=10;
  int *p= &i;
  int ** p2= &p;

  cout<<p2<<endl;
  cout<<&p<<endl;

  cout<<**p2<<endl;
  cout<<*p<<endl;
  cout<<i<<endl;

     int a = 100;
  int *p = &a;
  int **q = &p;
  int b = (**q)++;
  int *r = *q;
  (*r)++;
  cout << a << " " << b << endl;

  int a = 10;
  int *p = &a;
  int **q = &p;
  int b = 20;
  *q = &b;
  (*p)++;
  cout << *q<< endl;
  cout << p<< endl;
}