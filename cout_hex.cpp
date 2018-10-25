#include <iostream>

using namespace std;
int main() {
    int num = 100;
 
    // using fmtflags as class member constants:
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
    std::cout.setf(std::ios_base::showbase);
    std::cout << num << '\n';
 
    // using fmtflags as inherited class member constants:
    std::cout.setf (std::ios::hex , std::ios::basefield);
    std::cout.setf (std::ios::showbase);
    std::cout << num << '\n';
 
    // using fmtflags as object member constants:
    std::cout.setf(std::cout.hex, std::cout.basefield);
    std::cout.setf(std::cout.showbase);
    std::cout << num << '\n';
 
    // using fmtflags as a type:
    std::ios_base::fmtflags ff;
    ff = std::cout.flags();
    ff &= ~std::cout.basefield;   // unset basefield bits
    ff |= std::cout.hex;          // set hex
    ff |= std::cout.showbase;     // set showbase
    std::cout.flags(ff);
    std::cout << num << '\n';

    std::cout << "The number 100 in octal:   " << std::oct << num << '\n'
              << "The number 100 in decimal: " << std::dec << num << '\n'
              << "The number 100 in hex:     " << std::hex << num << '\n';
}
