#include <iostream>
#include <string>
using namespace std;

class Employee{
	public:
		int age;
		string name;
		string company;
		void introduce()
		{
			cout << "Hello my name is " << name << endl;
			cout << "from " << company << endl;
			cout << "i am " << age << endl;
		}
		
};


int main()
{
	Employee dit;
	dit.name = "Dit";
	dit.company = "google";
	dit.age = 15;
	dit.introduce();
}



