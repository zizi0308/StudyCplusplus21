#include <stdio.h>

class Some
{
private:
	mutable int temp;		// const�� ����� ����Ű�� ���� mutable

public:
	Some() {}
	void method() const {
		temp = 0;
		printf("%d", temp);
	}
};

int main()
{
	Some s;
	s.method();

	const Some t;
	t.method();
}