#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream
#include <bitset>
#include <sstream>
#include <ostream>
using namespace std;


int main () {
  char str[256];

  std::cout << "Enter the name of an existing text file: ";
  std::cin.get (str,256);    // get c-string
  std::ifstream is(str);     // open file

  std::string strInput;
  int chinese=0, math=0 , english=0;
  cout << "std::streamsize" << sizeof(std::streamsize)<<endl;
 while (is >> strInput >> chinese >> math >> english)
    {
        // read stuff from the file into a string and print it
        cout << strInput << chinese << math << english << endl;
    }

  return 0;
}

