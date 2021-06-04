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
	Date validto;			// ����� ���� �ʰ� Ŭ������ �ٸ� Ŭ������ ����� ������� ���� ��ӹ޴� Ŭ������ ���̾ƴ϶� ��ü���� ���� ����� �Ѵ�
	int price;

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) :
		validto(y, m, d) {	//  ��������̸��ְ�(validto, !Date�� �ʱ�ȭ �ϴ°� �ƴ�!) �ʱ�ȭ�Ѵ�. ��ü���� �ʱ�ȭ�� �ϴ°� �ƴ϶� �ݷ��ʱ�ȭ�� ���� �������� �޸� ����� �����Ѵ�
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutPrint() {
		printf("�̸�:%s\n", name);
		printf("������:%d\n", company);
		printf("��ȿ�Ⱓ:");
		validto.OutDate();
		puts("");
		printf("����:%d\n", price);
	}
};

int main()
{
	Product shrimp("�����", "���", 2020, 8, 15, 900);
	shrimp.OutPrint();
}