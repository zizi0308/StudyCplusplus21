#include <stdio.h>
#include <string.h>

class Date
{
protected:
	int year, month, day;

public:
	Date(int y, int m, int d) { year = y, month = m, day = d; }
	void OutDate() { printf("%d%d%d", year, month, day); }
};

class Product
{
private:
	char name[64];
	char company[32];
	Date validto;			// 상속을 하지 않고 클래스에 다른 클래스를 멤버로 집어넣은 형태 상속받는 클래스의 형이아니라 객체명을 통해 사용을 한다
	int price;

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) :
		validto(y, m, d) {	//  멤버변수이름주고(validto, !Date로 초기화 하는거 아님!) 초기화한다. 본체에서 초기화를 하는게 아니라 콜론초기화를 통해 쓸데없는 메모리 사용을 방지한다
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutPrint() {
		printf("이름:%s\n", name);
		printf("제조사:%d\n", company);
		printf("유효기간:");
		validto.OutDate();
		puts("");
		printf("가격:%d\n", price);
	}
};

int main()
{
	Product shrimp("새우깡", "농심", 2020, 8, 15, 900);
	shrimp.OutPrint();
}