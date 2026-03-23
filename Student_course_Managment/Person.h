#ifndef PERSON_H_
#define PERSON_H_
#include <string>
using namespace std;


class Person
{

protected:
	string name;

public:
	Person();
	Person(string name);
	virtual ~Person();
	string getName();

};
#endif 



