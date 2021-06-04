#include <stdio.h>
#include <string.h>

class Product
{
private:
	char name[64];
	char company[32];
	int price;

	class Date		// 클래스 클래스내에서만 사용할 때(중첩클래스)
	{
	protected:
		int year, month, day;
	public:
		Date(int y, int m, int d) { year = y, month = m, day = d; }
		void OutDate() { printf("%d%d%d", year, month, day); }
	};
	Date validto;	// 클래스 객체 생성

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) :
		validto(y, m, d) {
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}

	void OutProduct() {
		printf("이름:%s\n", name);
		printf("제조사:%s\n", company);
		printf("유효기간:");
		validto.OutDate();
		puts("");
		printf("가격: %d", price);
	}
};

int main()
{
	Product shrimp("새우깡", "농심", 2020, 4, 24, 1000);
	shrimp.OutProduct();

	// Date now(12, 34, 56);	// 에러 Date가 다른 클래스에 소속되어있으므로 Product::를 붙여야 함
}