#include <stdio.h>

class Some
{
private:
	mutable int temp;		// const의 기능을 상쇄시키기 위한 mutable

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