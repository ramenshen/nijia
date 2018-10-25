#include <iostream>
#include <bitset>
#include <climits>

template<typename T>
void show_bin(const T& a)
{
    const char* beg = reinterpret_cast<const char*>(&a);
    const char* end = beg + sizeof(a);
    while(beg != end)
        std::cout << std::bitset<CHAR_BIT>(*beg++) << ' ';
    std::cout << '\n';
}
int main()
{
    char a, b;
    short c;
    int d=100;
    a = -58;
    c = -315;    
    b = a >> 3;
    show_bin(a);
    show_bin(b);
    show_bin(c);
    show_bin(d);
    float f = 3.14;
    show_bin(f);
}
