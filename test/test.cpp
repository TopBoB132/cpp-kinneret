#include <iostream>
using namespace std;
class C
{
protected: 
int i;
public:
C(int i=5):i(i){cout<<"C"<<endl;}
C(const C& o) { cout << "CC" << endl; *this=o; }
void operator+(int i) {this->i+=i;}
const C& operator=(const C& c)
{ i=c.i+2; return *this; }
virtual void print(C &c) { cout<<"c.i="<<c.i<<endl;}
~C(){ cout<<"~C"<<endl; }
friend class D;
};
class D: public C
{
C c; public:
D(C &o, int y1=10):c(o),C(y1){cout<<"D"<<endl;}
void operator+(int i) {this->i+=i;this->c.i+=i;}
void print() { cout<<"i="<<i--<<endl; C::print(c); }
void print (C &o) {cout<<"i="<<i<<endl; o.print(o);}
virtual ~D(){cout<<"~D"<<endl;}
};
int main()
{
C c;
C *p =new D(c); C o=*p;
p->print(c); delete p;
}