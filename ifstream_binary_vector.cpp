#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

#pragma pack(push, r1, 1)
struct Header {
    char name[15];
    int chinese;
    int math;
};
#pragma pack(pop, r1)

#if 0
Header make_header(char* name,int x, int y) {
    Header t = {name, x, y};
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
  for(int i = 0; i < sizeof(all_students_info)/sizeof(Header);i++)
	  all_students_v.push_back(all_students_info[i]);
 
  cout << "Length offset is "<< &(((struct Header *)0)->chinese) << endl;
 
  fstream fh;
  fh.open("test.txt", fstream::out | fstream::binary);
  fh.write(reinterpret_cast<const char*>(&all_students_v[0]), all_students_v.size()*sizeof(Header));
  fh.close();

  fh.open("test.txt", fstream::in | fstream::binary);
  if(fh)
  {
  		  //get file size
		  fh.ignore( std::numeric_limits<std::streamsize>::max() );
		  streamsize length = fh.gcount();
		  fh.clear();   //  Since ignore will have set eof.
		  
		  fh.seekg( 0, std::ios_base::beg );
		  const size_t count = length / sizeof(Header);
		  cout << "length " << length << " Count "<<count<<endl;
		  vector<Header> r_students_v(count);
		  fh.read(reinterpret_cast<char*>(&r_students_v[0]), count*sizeof(Header));
		  fh.close();
		  
		  for(vector<Header>::iterator i=r_students_v.begin();i!=r_students_v.end();i++)
			  	cout << i->name << " " << i->chinese << " " << i->math << endl;
	}
  system("pause");
}
