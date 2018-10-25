#include <iostream>
using namespace std;

// first name space
namespace first_space {
	int value = 0;
	typedef unsigned int uint32;
   void func() {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space {
	int value = 1;
   void func() {
      cout << "Inside second_space" << endl;
   }
}

int main () {
   // Calls function from first name space.
   first_space::func();
   cout<< "cout<< first_space::value "<<first_space::value<<endl;
   // Calls function from second name space.
   second_space::func(); 
   cout<< "cout<< second_space::value "<<second_space::value<<endl;
   first_space::uint32 i = 0;
   cout<< " i="<<i<<sizeof(first_space::uint32)<<endl;
   return 0;
}
