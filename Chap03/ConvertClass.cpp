#include <stdio.h>

class Fahrenheit;
class Celsous
{
public:
	double Tem;
	Celsous() {}
	Celsous(double aTem) :Tem(aTem) {}
	operator Fahrenheit();
	void OutTem() { printf("섭씨 = %f\n", Tem); }
};

class Fahrenheit
{
public:
	double Tem;
	Fahrenheit() {}
	Fahrenheit(double aTem) :Tem(aTem) {}
	operator Celsous();
	void OutTem() { printf("화씨 = %f\n", Tem); }
};

Celsous::operator Fahrenheit()		// 범위지정연산자를 통해 소속 오퍼레이터를 표시
{
	Fahrenheit F;
	F.Tem = Tem * 1.8 + 32;
	return F;
}

Fahrenheit::operator Celsous()
{
	Celsous C;
	C.Tem = (Tem - 32) / 1.8;
	return C;
}

int main()
{
	Celsous C(100);
	Fahrenheit F = C;
	C.OutTem();
	F.OutTem();

	printf("\n");
	Fahrenheit F2 = 120;
	Celsous C2 = F2;
	F2.OutTem();
	C2.OutTem();
}