#include <iostream>
using namespace std;
#define USING_ENUM 
#define PI 3.1415926
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define DEBUG_OUTPUT_LINE cout<<__FILE__<<" "<<COLOR_GREEN<<__FUNCTION__<<"\033[0m"<<" "<<__LINE__<<endl;
enum SUBJECT{
	SUBJECT_CHINESE,
	SUBJECT_MATH,
	SUBJECT_ENGLISH,
	SUBJECT_BIOLOGY,	
	SUBJECT_MAX
};
enum SEX{
	SEX_MAN,
	SEX_WOMAN,
	SEX_MAX
};
class Student{
private:
	int sex; 	
public:
	Student()
	{
		DEBUG_OUTPUT_LINE;	
	}
	Student(int sex)
	{
		DEBUG_OUTPUT_LINE
		this->sex = sex;
	}
	Student(int sex,int age)
	{
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
	}
#if 1
#else	
	Student(int sex,int age,int chinese)
	{
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
		this->chinese = chinese;
	}
	Student(int sex,int age,int chinese,int maths)
	{
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
		this->chinese = chinese;
		this->maths = maths;
	}
	Student(int sex,int age,int chinese,int maths,int english)
	{
		DEBUG_OUTPUT_LINE
		this->sex = sex;
		this->age = age;
		this->chinese = chinese;
		this->maths = maths;
		this->english = english;
	}
#endif	
	int age;
	int getSex()
	{
		DEBUG_OUTPUT_LINE;
		return this->sex;
	}
	int setAge(int age)
	{
		this->age = age;
	}
	int setSex(int sex)
	{
		this->sex=sex;
	}
#if 1
	int subject[SUBJECT_MAX];
	void setSubject(int _score,int _subject)
	{
		subject[_subject] = _score;
	}
	int getSubject(int _subject)
	{
		return subject[_subject];
	}
	int getTotalScore()
	{
		DEBUG_OUTPUT_LINE;
		int sum = 0;
		for (int i = 0;i < SUBJECT_MAX;i++)
		{
			sum = sum + subject[i];
	    }
	    return sum;
	}
#else	
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
	int getMaths()
	{
		return maths;
	}
	int english;
	int setEnglish(int english)
	{
		this->english = english;
	}
	int getEnglish()
	{
		return english;
	}

	int totalScore;
	int setTotalScore()
	{
		this->chinese = chinese;
		this->maths = maths;
		this->english = english;
	}
	int getTotalScore()
	{
		DEBUG_OUTPUT_LINE;
		return chinese + maths + english;
	}
#endif		
	int sum(int a,int b)
	{
		return a+b;
	}
	double sum(double a, double b)
	{
		return a+b;
	}
	int operator++(int)
	{
		DEBUG_OUTPUT_LINE;
		age--;
	}
	int operator--(int)
	{
		DEBUG_OUTPUT_LINE;
		age -= 2;
	}
	int operator++()
	{
		age += 3;
	}
	int operator+=(int a)
	{
		this->age += a;
	}
	int operator+=(Student a){
		this->age += a.age;
	}
};
int main(){              
	Student Bob(SEX_WOMAN,10);

	Student max(SEX_MAN,12);
	cout << "Max's sex is " << ((max.getSex()==SEX_MAN)?"Boy":"Girl")<<" Age is "<<max.age << endl;
#if 1
	max.setSubject(100,SUBJECT_CHINESE);
	max.setSubject(100,SUBJECT_MATH);
	max.setSubject(100,SUBJECT_ENGLISH);
	max.setSubject(100,SUBJECT_BIOLOGY);
	cout << "Max's chinese score  is " << max.getSubject(SUBJECT_CHINESE) << endl;
	cout << "Max's maths score is " << max.getSubject(SUBJECT_MATH) << endl;
	cout << "Max's english score is " << max.getSubject(SUBJECT_ENGLISH) << endl;
	cout << "Max's biology score is " << max.getSubject(SUBJECT_BIOLOGY) << endl;
	cout << "Max's total score is " << max.getTotalScore() << endl;
#else	
	cout << "Max's chinese is " << max.chinese<< endl;
	cout << "Max's maths is " << max.maths<< endl;
	cout << "Max's endlish is " << max.english<< endl;
	cout << "Max's total score is " << max.getTotalScore()<< endl;
#endif	
	max++;
	cout << "Max's sex is " << ((max.getSex()==SEX_MAN)?"Boy":"Girl")<<" Age is "<<max.age << endl;
	max--;
	cout << "Max's sex is " << ((max.getSex()==SEX_MAN)?"Boy":"Girl")<<" Age is "<<max.age << endl;
	++max;
	cout << "Max's sex is " << ((max.getSex()==SEX_MAN)?"Boy":"Girl")<<" Age is "<<max.age << endl;
	max+=1;//==>max.+=(1);
	cout << "Max's sex is " << ((max.getSex()==SEX_MAN)?"Boy":"Girl")<<" Age is "<<max.age << endl;
	max+=Bob;//==>max.+=(Bob);
	cout << "Max's sex is " << ((max.getSex()==SEX_MAN)?"Boy":"Girl")<<" Age is "<<max.age << endl;
	
}

