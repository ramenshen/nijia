#include <iostream>
#include <stdlib.h>
#include <string>
#include <cerrno>
#include <cstdlib>

using namespace std;
int main(){
	cout<<"==================WAY 1======================"<<endl;
	int a = 0;	
	char c;
	while ((c = getchar()) != '\n') { // read a line char by char
	  a <<= 1;                        // shift the uint32 a bit left
	  a += (c - '0') & 1;             // convert the char to 0/1 and put it at the end of the binary
	}	
	printf("%u\n", a);
	cout<<"==================WAY 2======================"<<endl;
	char input[100];
	char *endpointer;
	cin>>input;
	int n = (int) strtol(input, &endpointer, 2);
	cout<<n<<endl;
	
	const char* p = "10 200000000000000000000000000000 30 -40";
    char *end;
    std::cout << "Parsing '" << p << "':\n";
    for (long i = std::strtol(p, &end, 10);
         p != end;
         i = std::strtol(p, &end, 10))
    {
        std::cout << "'" << std::string(p, end-p) << "' -> ";
        p = end;
        if (errno == ERANGE){
            std::cout << "range error, got ";
            errno = 0;
        }
        std::cout << i << '\n';
    }
}
