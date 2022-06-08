#include <iostream>
#include<algorithm>

using namespace std;

class Fraction
{
	int num{};
	int den{};
	int nod{};
	
public:
	Fraction(int numP, int denP)
		: num{ numP }, den{ denP }{
		}
	Fraction() : Fraction(1, 1) {}
	~Fraction() {}	
	void print(){
		if (num < 0) {
			cout << "  "<<num * -1 <<endl;
			cout << "- -" << endl;
			cout << "  " << den << endl;
		}
		else {
			cout << "  " << num  << endl;
			cout << "  -" << endl;
			cout << "  " << den << endl;
		}
			
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
		if (a.den == b.den) {
			c.num = a.num - b.num;
			c.den = a.den;
		}
		else {
			c.den = a.den * b.den;
			c.num = (a.num * b.den) - (b.num * a.den);
		}
		if (c.num == 0) {
			c.den = 0;
			c.num = 0;
		}
		return c;
	}
	Fraction subt(Fraction a, int b) {
		Fraction c;
		c.den = a.den;
		c.num = a.num - (b * a.den);
		return c;
	}
	Fraction mult(Fraction a, Fraction b) {
		Fraction c;
		c.num = a.num * b.num;
		c.den = a.den * b.den;
		return c;
	}
	Fraction mult(Fraction a, int b) {
		Fraction c;
		c.num = a.num * b;
		c.den = a.den;
		return c;
	}
};
int main()
{
	
	Fraction a(1, 5);
	a.print();
	Fraction b(2,5);
	Fraction c;
	int d = 4;
	c = c.subt(a,b);
	c.print();
	
	return 0;
	
}