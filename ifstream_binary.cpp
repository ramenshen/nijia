#include <iostream>
#include <fstream>
#include <vector>

#pragma pack(push, r1, 1)
struct Header {
    char name[15];
    int chinese;
    int math;
};
#pragma pack(pop, r1)

#if 1
Header make_header(char *name,int x, int y) {
    Header t = {*name, x, y};
    return t;
}
#endif
//a.push_back(make_point(0, 1));

using namespace std;
int main() {
  Header all_students_info[] = {
  	{"max", 100, 98},
  	{"jerry", 98, 94},
  };
  vector<Header> all_students_v;
 // for(int i = 0; i < sizeof(all_students_info)/sizeof(Header);i++)
  all_students_v.push_back(make_header(const_cast<char*>("max"), 100, 98));
 // all_students_v.push_back(make_header("jerry", 70, 98));
 // cout.setf(ios::right);
 // cout.width(40);
  //cout << "Length offset is "<< &(((struct Header *)0)->chinese) << endl;
  cout.setf(ios::right);
  cout.width(20);
  cout << "Length offset is ";
  cout.setf(ios::left|ios::dec);
  cout.width(20);
  cout<< &(((struct Header *)0)->chinese)<<"hello" << endl;
  
  cout.setf(std::cout.hex, std::cout.basefield);
  cout.setf(std::cout.showbase);
  cout<< 100 << endl;
  fstream fh;
  fh.open("test.txt", fstream::out | fstream::binary);
  fh.write(reinterpret_cast<const char*>(&all_students_v[0]), all_students_v.size()*sizeof(Header));
  fh.close();
  
}
