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

  char c;
  while (is.get(c))  {        // loop getting single characters
    //std::cout << c;
    //std::bitset<8> x(c);
	//std::cout << x;
	//std::cout << std::hex << c;
	//printf("%.2X", c);
	std::cout << std::hex << (int)c;
  }

  return 0;
}
