#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
  string a("hello,world");
  wstring wa(L"hello,world");
  cout<<a<<sizeof(string::value_type)<<endl;
  getline(cin,a);
  cout<<a<<sizeof(string::value_type)<<endl;
  wcout<<wa<<sizeof(wstring::value_type)<<endl;
  cout<<__cplusplus<<endl;
  
  string b(string("helloworld"),6);
  cout<<b<<endl;
    
  string c(string("helloworld"),6,string::npos);
  cout<<c<<endl;
  return 0;
}


