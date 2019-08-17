#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <vector>
using namespace std;
void list_print(int& a) {
	cout<<setw(4)<<a<<" ";
}
void vector_print(int& a) {
	cout<<setw(4)<<a<<" ";
}
static bool abs_compare(int& a, int& b) {
	return (std::abs(a) < std::abs(b));
}
bool mygreater(const int &lhs, const int &rhs)  
{
    return lhs%10 > rhs%10;
}
struct my_struct_greater{
	bool operator()(const int &lhs, const int &rhs)  
	{
	    return lhs%5 > rhs%5;
	}
};
int main() {
	std::srand(std::time(NULL)); // use current time as seed for random generator
	std::cout << "Random value on [0 " << RAND_MAX << "]: " << '\n';
	list<int> lt;
	// roll a 6-sided die 20 times
	for (int n=0; n != 20; ++n) {
		lt.push_back(rand()%100-50);
	}
	for_each(lt.begin(),lt.end(),list_print);
	cout<<endl;
	std::list<int>::iterator result;
	 
	result = std::max_element(lt.begin(), lt.end());
	std::cout << "max element is "<<setw(4)<<*result<<" at: " <<setw(4)<< std::distance(lt.begin(), result) << '\n';

	result = std::max_element(lt.begin(), lt.end(),abs_compare);
	std::cout << "max element is "<<setw(4)<<*result<<" at: " <<setw(4)<< std::distance(lt.begin(), result) << '\n';
	cout<<"using accumulate....."<<endl;
	int sum = accumulate(lt.begin(), lt.end(), 0);
	std::cout << "sum is "<<sum<< '\n';
	int max = 0;
	for(int j=1; j<=lt.size(); j++) {
		for(int i=0; i<lt.size(); i++) {
			if((i+j)<=lt.size()) {
				list<int>::iterator it_b=lt.begin();
				list<int>::iterator it_e=lt.begin();
				advance(it_b,i);
				advance(it_e,i+j);
				int temp = accumulate(it_b, it_e, 0);
				max<temp?max=temp:(max);
				std::cout <<setw(4)<< temp<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"The maxinum is "<<max<<endl;
	
	int a[]={5, 6, 4, 3, 2, 6, 7, 9, 3};
	std::vector<int> v;
 	cout<<"Dumping vector...."<<endl;
 	cout<<"Dumping vector...."<<v.size()<<endl;
 	for(int i=0;i<sizeof(a)/sizeof(int);i++){
 		v.push_back(a[i]);
	 }
 	for_each(v.begin(),v.end(),vector_print);
 	cout<<endl; 
    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    std::cout << "The median is " << v[v.size()/2] << '\n';
 
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
    std::cout << "The second largest element is " << v[1] << '\n';
    cout<<"using my greater...."<<endl;
    std::nth_element(v.begin(), v.begin()+1, v.end(), mygreater);
    std::cout << "The second largest element is " << v[1] << '\n';
    
    cout<<"using my struct greater...."<<endl;
    std::nth_element(v.begin(), v.begin()+1, v.end(), my_struct_greater());
    std::cout << "The second largest element is " << v[1] << '\n';
   
	cout<<"using copy......"<<endl;
	vector<int> bv;
	copy(v.begin(),v.end(),back_inserter(bv));
	for_each(bv.begin(),bv.end(),list_print);

}
