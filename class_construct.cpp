#include <iostream>
using namespace std;
#define PI 3.1415926
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define DEBUG_OUTPUT_LINE cout<<__FILE__<<" "<<COLOR_GREEN<<__FUNCTION__<<"\033[0m"<<" "<<__LINE__<<endl;
class Student{
private:
	int sex;
	
public:
	Student(){
		DEBUG_OUTPUT_LINE;	
	}
	Student(int sex){
		DEBUG_OUTPUT_LINE
		this->sex = sex;
	}
	Student(int sex,int age){
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
	}
	Student(int sex,int age,int chinese){
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
		this->chinese = chinese;
	}
	Student(int sex,int age,int chinese,int maths){
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
		this->chinese = chinese;
		this->maths = maths;
	}
	Student(int sex,int age,int chinese,int maths,int english){
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
		this->chinese = chinese;
		this->maths = maths;
		this->english = english;
	}
	int age;
	int getSex()
	{
		DEBUG_OUTPUT_LINE;
		return this->sex;
	}
	int setAge(int age){
		this->age = age;
	}
	int setSex(int sex){
		this->sex=sex;
	}
	int chinese;
	int setChinese(int chinese)
	{
		this->chinese = chinese;
	}
	int getChinese()
	{
		return this->chinese;
	}
	int maths;
	int setMaths(int maths)
	{
		this->maths = maths;
	}
	int getMaths(){
		return maths;
	}
	int english;
	int setEnglish(int english)
	{
		this->english = english;
	}
	int getEnglish(){
		return english;
	}
	int totalScore;
	int setTotalScore(){
		this->chinese = chinese;
		this->maths = maths;
		this->english = english;
	}
	int getTotalScore()
	{
		DEBUG_OUTPUT_LINE;
		return chinese + maths + english;
	}
	int sum(int a,int b){
		return a+b;
	}

	double sum(double a, double b){
		return a+b;
	}

};
int main(){
	Student Bob(1);
	Student max(1,12,100,100,150);
	cout << "Max's sex is " << max.getSex()<< " Age is "<<max.age << endl;
	cout << "Max's chinese is " << max.chinese<< endl;
	cout << "Max's maths is " << max.maths<< endl;
	cout << "Max's endlish is " << max.english<< endl;
	cout << "Max's total score is " << max.getTotalScore()<< endl;
	// Student max;
	// max.setSex(1);
	// max.setAge(11);
	// max.setChinese(100);
	// max.setEnglish(100);
	// max.setMaths(150);
	// cout<<"Max's age is "<<max.age<<endl;
	// cout<<"Max's sex is "<<max.getSex()<<endl;
	// cout << "Max's chinese score is " << max.getChinese() << endl;
	// cout << "Max's maths score is " << max.getMaths() << endl;
	// cout << "Max's chinese score is " << max.getEnglish() << endl;
	// cout << "Max's total score is " << max.getTotalScore() << endl;
	// cout << "Max's sum  is " << max.sum(1,2) << endl;
	// cout << "Max's sum  is " << max.sum(1.0,2.0) << endl;
	
}