#include <iostream>
#include<algorithm>

using namespace std;
// класс Дробь
class Fraction
{
// поля для числителя, знаменателя и наибольшего общего делителя
	int num{};
	int den{};
	int nod{};
	
public:
// конструктор с параметрами у методом сокращения дроби
	Fraction(int numP, int denP)
		: num{ numP }, den{ denP }{
		reduct();
		}
// конструктор по умолчанию		
	Fraction() : Fraction(1, 1) {}
// деструктор	
	~Fraction() {}	
// вычисление наибольшего общего делителя	
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
// метод сокращения дроби	
	void reduct() {
		setNod();
		this->num = this->num / this->nod;
		this->den = this->den / this->nod;

	}
// метод вывода дроби на экран
	void print() const{
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
// сеттер для числителя	
	void setNum(int num) {
		this->num = num;
	}
// сеттер для знаменателя	
	void setDen(int den) {
		this->den = den;
	}
// метод вычисления суммы двух дробей	
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
// метод вычисления суммы дроби и целого числа	
	Fraction sum(Fraction a, int b) {
		Fraction c;
		c.den = a.den;
		c.num = a.num + (b * a.den);
		c.reduct();
		return c;
	}
// метод вычисления разности двух дробей
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
// метод вычисления разности дроби и целого числа
	Fraction subt(Fraction a, int b) {
		Fraction c;
		c.den = a.den;
		c.num = a.num - (b * a.den);
		c.reduct();
		return c;
	}
// метод вычисления произведения двух дробей
	Fraction mult(Fraction a, Fraction b) {
		Fraction c;
		c.num = a.num * b.num;
		c.den = a.den * b.den;
		c.reduct();
		return c;
	}
// метод вычисления произведения дроби и целого числа	
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

