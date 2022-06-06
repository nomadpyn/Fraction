#include <iostream>
#include<algorithm>

using namespace std;

class Fraction
{
	int num;
	int den;
	
public:
	Fraction(int numP, int denP)
		: num{ numP }, den{ denP }{}
	Fraction() : Fraction(1, 1) {}
	~Fraction() {}	
	void print(){	
		cout << num << " / " << den << endl;
	}
	void setNum(int num) {
		this->num = num;
	}
	void setDen(int den) {
		this->den = den;
	}
	Fraction sum(Fraction a, Fraction b) {
		Fraction c;
		if (a.den == b.den) {
			c.num = a.num + b.num;
			c.den = a.den;
		}
		else {
			c.den = a.den * b.den;
			c.num = (a.num*b.den)+(b.num*a.den);
		}
		return c;
	}
	Fraction sum(Fraction a, int b) {
		Fraction c;
		c.den = a.den;
		c.num = a.num + (b * a.den);
		return c;
	}
	Fraction subt(Fraction a, Fraction b) {
		Fraction c;

	}

};
int main()
{
	
	Fraction a(1, 4);
	Fraction b(2,6);
	Fraction c;
	int d = 5;
	c =c.sum(a, d);
	c.print();
	
	return 0;
	
}