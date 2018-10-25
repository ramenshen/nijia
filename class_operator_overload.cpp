#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream
#include <bitset>
#include <sstream>
#include <ostream>
using namespace std;

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int,int);
    CVector operator + (CVector);
    friend ostream& operator << (ostream&,CVector);
    operator int() {
            std::cout << "int reading\n"; 
			return x;
    }
     operator bool() {
            std::cout << "bool reading\n"; 
			return x+y;
    }
    operator char() {
            std::cout << "char reading\n"; 
			return y;
    }
};

CVector::CVector (int a, int b) {
  x = a;
  y = b;
}

CVector CVector::operator+ (CVector param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return (temp);
}

ostream& operator<< (ostream& os,CVector param) {
  os << param.y;
  return os;
}

int main () {

 CVector y(1,2);
 cout<<y<<endl;
 cout<<"y";
 if(y)
 	cout<<"xxxxxxxxxx"<<endl;
  return 0;
}
