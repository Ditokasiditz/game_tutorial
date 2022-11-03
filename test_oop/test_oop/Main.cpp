#include <iostream>
using std::string;

class employee{
public:
	string name;
	string company;
	int age;

	void display_infor() 
	{
		printf("name:%s\n", name);
		printf("company:%s\n", company);
		printf("age:%d", age);
	}



};

int main() {
	
	employee number1;
	number1.age = 12;
	number1.name = "lkjlj";
	number1.company = "gtu";
	number1.display_infor();

	return 0;
}