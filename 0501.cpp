#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(float r=0.0,float i=0.0)//Complex(float r=0,float i=0)
	{
		this->r=r;
		this->i=i;
	}
	//Complex(float r){this->r=r;i=0;}//Complex(float a){x=a;y=0;}不需要转换构造函数啊
	friend void print(Complex c1);//friend complex print();fan hui complex lei dui xiang de zhi 
	friend Complex operator+(Complex c1,Complex c2);//,shi ji shang bubiyao.
	friend Complex operator-(Complex c1,Complex c2);
	friend Complex operator*(Complex c1,Complex c2);
	friend Complex operator-(Complex c1);
	Complex operator++();
	Complex operator--();
	Complex operator++(int);
	Complex operator--(int);
private:
	float r;
	float i;
};
int main()
{
	Complex C1(1.0);
	cout<<"C1= ";
	print(C1);
	Complex C2(1.0);
	cout<<"C2= ";
	print(C2);
	Complex C3(1.0);
	cout<<"C3= ";
	print(C3);
	Complex C;
	C=-C1+(C2--)+(3+C2)+2*C2+(++C1);
	cout<<"C=-C1+(C2--)+(3+C2)+2*C2+(++C1);"<<endl;
	cout<<"C= ";
	print(C);
}

Complex operator+(Complex c1,Complex c2)
{
	return Complex(c1.r+c2.r,c1.i+c2.i);
}
Complex operator-(Complex c1,Complex c2)//fan hui complex lei de xiang,yong dao gou zao han shu. 
{
	return Complex(c1.r-c2.r,c1.i-c2.i);
}
Complex operator*(Complex c1,Complex c2)
{
	return Complex(c1.r*c2.r-c1.i*c2.i,c1.r*c2.i+c1.i*c2.r);
}
Complex operator-(Complex c1)
{
	return Complex(-c1.r,-c1.i);
}
Complex Complex::operator++()
{
	this->r=this->r+1;
	this->i=this->i+1;
	return *this;
}
Complex Complex::operator--()
{
	this->r=(this->r)-1;
	this->i=(this->i)-1;
	return *this;
}
Complex Complex::operator--(int)
{
	Complex tmp = *this;
	this->r=this->r-1;
	this->i=this->i-1;
	return tmp;
}
Complex Complex::operator++(int)
{
	Complex tmp = *this;//对象的赋值，为啥不用copy构造函数，而直接=？
	this->r=this->r+1;
	this->r=this->r-1;
	return tmp;
}

void print(Complex c1)
{
	cout<<"("<<c1.r<<","<<c1.i<<")"<<endl;
}






	
	