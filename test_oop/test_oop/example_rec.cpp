#include<iostream>
using namespace std;
class rectangle
{
public:
	rectangle(int max1,int max2);
	~rectangle();
	int width;
	int high;
	void inputparameter();
	void area();
	void perimeter();

private:
	int max_width;
	int max_high;

};

rectangle::rectangle(int max1,int max2)
{
	max_width = max1;
	max_high = max2;
}

rectangle::~rectangle()
{
		cout << "good bye human";
}

void rectangle::inputparameter()
{
	cout << "enter your parameter:";
	cin >> width >> high;
}

void rectangle::area() 
{
	if (width <= max_width && high <= max_high)
		cout << "the are :" << width * high << endl;
	else
		cout << "the parameter out of range" << endl;
}

void rectangle::perimeter()
{
	if (width <= max_width && high <= max_high)
		cout << "the perimeter :" << (width + high) * 2 << endl;
	else
		cout << "the parameter out of range" << endl;
}

int main()
{
	rectangle rec(100, 50);
	rec.inputparameter();
	rec.area();
	rec.perimeter();

	return 0;
}