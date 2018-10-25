#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
struct MyStruct
{
    int key;
    std::string stringValue;

    MyStruct(int k, const std::string& s) : key(k), stringValue(s) {}
};

struct less_than_key
{
    inline bool operator() (const MyStruct& struct1, const MyStruct& struct2)
    {
        return (struct1.key < struct2.key);
    }
};
bool cmp(const MyStruct &a, const MyStruct &b){  
    return a.key>b.key;  
} 
using int_vector = std::vector<int>;
int main ()
{
  int_vector myvector;
  std::vector<int>::size_type x;
  // set some content in the vector:
  for (int i=0; i<50; i++) {
  
  	myvector.push_back(rand());

 	 //std::cout << "size: " << (int) myvector.size() << '\n';
  	 //std::cout << "capacity: " << (int) myvector.capacity() << '\n';
 	// std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}
	std::vector<int>::reverse_iterator i = myvector.rbegin();
	for(;i!=myvector.rend();i++)
		std::cout<<*i<<" ";
	std::sort(myvector.begin(), myvector.end());
	std::cout<<"#########################"<<std::endl;
	std::vector<int>::iterator t = myvector.begin();
	for(;t!=myvector.end();t++)
		std::cout<<*t<<" ";
		
	std::cout << "size_type: " << sizeof(x)<< '\n';



std::vector < MyStruct > vec;

vec.push_back(MyStruct(4, "test"));
vec.push_back(MyStruct(3, "a"));
vec.push_back(MyStruct(2, "is"));
vec.push_back(MyStruct(1, "this"));

    std::sort(vec.begin(), vec.end(), less_than_key());
	
	std::vector<MyStruct>::iterator z = vec.begin();
	for(;z!=vec.end();z++)
		std::cout<<z->stringValue<<std::endl;

#if 0
  // set some content in the vector:
  for (int i=0; i<100; i++) mydeque.push_back(i);

  std::cout << "size: " << (int) mydeque.size() << '\n';
  std::cout << "capacity: " << (int) mydeque.capacity() << '\n';
  std::cout << "max_size: " << (int) mydeque.max_size() << '\n';
#endif  
  getchar();
  return 0;
}
