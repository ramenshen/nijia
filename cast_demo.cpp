#include <iostream>
using namespace std;
int main(){
	const int &val=1;
	const int va2=2;
	float fval=1.0f;
	 
	//const_cast<int&>
	int &ncref1=const_cast<int&>(val);//ok
	ncref1=10;
	//int &ncref2=val;//error，不能将const变量赋值给非const引用
	cout<<"ncref1="<<ncref1<<",val="<<val<<endl;
	 
	//int ncref2=const_cast<int>(va2);//ok 
	 
	//static_cast<int>
	int ival1=(int)fval;//ok
	cout<<"ival1="<<ival1<<",fval="<<fval<<endl;
	int ival2=fval;//ok,float与int位数相等；如果将double赋值给int，则出现warning
	cout<<"ival2="<<ival1<<",fval="<<fval<<endl;
	//reinterpret_cast<int&>
	int iref1=reinterpret_cast<int&>(fval);
	cout<<"iref1="<<iref1<<endl;

	//iref1 = 1;
	//cout<<"iref1="<<iref1<<",fval="<<fval<<endl;
	 
	//static_cast<int>
	const int &iref2=(int&)fval;//由于返回的是临时int变量，所以必须使用const修饰
	cout<<"iref2="<<iref2<<endl;
	fval = 2.0; 
	cout<<"iref2="<<iref2<<endl;
	return 0;
}
