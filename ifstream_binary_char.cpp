#include <iostream>
#include <fstream>

#pragma pack(push, r1, 1)
struct Header {
    char name[15];
    int chinese;
    int math;
};
#pragma pack(pop, r1)
using namespace std;
int main() {
  Header h = {"max", 100, 98};

  cout << "Length offset is "<< &(((struct Header *)0)->chinese) << endl;
  fstream fh;
  fh.open("test.txt", fstream::out | fstream::binary);
  fh.write((char*)&h, sizeof(Header));
  fh.close();

  fh.open("test.txt", fstream::in | fstream::binary);

  fh.read((char*)&h.name, sizeof(h.name));
  fh.read((char*)&h.chinese, sizeof(h.chinese));
  fh.read((char*)&h.math, sizeof(h.math));

  fh.close();

  cout << h.name << " " << h.chinese << " " << h.math << endl;
  
}
