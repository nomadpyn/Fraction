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
		reduct();
		}
	Fraction() : Fraction(1, 1) {}
	~Fraction() {}	
	void setNod() {
		int x = this->num;
		int y = this->den;
		if (x < 0)
			x = x * -1;
		while (x != y) {
			if (x > y) {
				x = x - y;
			}
			else {
				y = y - x;
			}
		}
		this->nod = x;
	}
	void reduct() {
		setNod();
		this->num = this->num / this->nod;
		this->den = this->den / this->nod;

	}

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
		cout << endl;
			
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
		c.reduct();
		return c;
	}
	Fraction sum(Fraction a, int b) {
		Fraction c;
		c.den = a.den;
		c.num = a.num + (b * a.den);
		c.reduct();
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
		c.reduct();
		return c;
	}
	Fraction subt(Fraction a, int b) {
		Fraction c;
		c.den = a.den;
		c.num = a.num - (b * a.den);
		c.reduct();
		return c;
	}
	Fraction mult(Fraction a, Fraction b) {
		Fraction c;
		c.num = a.num * b.num;
		c.den = a.den * b.den;
		c.reduct();
		return c;
	}
	Fraction mult(Fraction a, int b) {
		Fraction c;
		c.num = a.num * b;
		c.den = a.den;
		c.reduct();
		return c;
	}
};
int main()
{
	
	Fraction a(1, 18);
	Fraction b(2, 5);
	Fraction c;
	int d = 24;
	c = c.sum(a, b);
	c.print();
	c = c.sum(a, d);
	c.print();
	c = c.subt(a, b);
	c.print();
	c = c.subt(a, d);
	c.print();
	c.print();
	c = c.mult(a, b);
	c.print();
	c = c.mult(a, d);
	c.print();
	
	return 0;
	
}

