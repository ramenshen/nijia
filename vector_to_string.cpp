// C++ program transform a vector into 
// a string. 
#include <vector> 
#include <string> 
#include <algorithm> 
#include <sstream> 
#include <iterator> 
#include <iostream> 
  
int main() 
{ 
  std::vector<int> vec; 
  vec.push_back(1); 
  vec.push_back(2); 
  vec.push_back(3); 
  vec.push_back(4); 
  vec.push_back(5); 
  vec.push_back(6); 
  
  std::ostringstream vts; 
  
  if (!vec.empty()) 
  { 
    // Convert all but the last element to avoid a trailing "," 
    std::copy(vec.begin(), vec.end()-1, 
        std::ostream_iterator<int>(vts, ", ")); 
  
    // Now add the last element with no delimiter 
    vts << vec.back(); 
  } 
  
  std::cout << vts.str() << std::endl; 
  std::ostream_iterator<int> o(std::cout, ", "); 
  *o=1;
  *o=2;
  *o='s';
  
} 

