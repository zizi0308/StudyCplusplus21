#include <stdio.h>

class Some
{
public:
	int& total;
	Some(int &atotal) : total(atotal) //, n1(on1), n2(on2) << 일반변수 넣을 때 레퍼런스, const넣을 때는 :연산자 필요함
	{
		//this->n1 = n1;
		//this->n2 = n2;
	}
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	int value = 8;
	Some S(value);
	S.OutTotal();
}