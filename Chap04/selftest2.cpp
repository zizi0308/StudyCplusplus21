#include <stdio.h>
#include <string.h>

class CMember
{
private:
	char name[20];
	char phone_num[30];
	char addr[100];
	static int count;
	

public:
	CMember(const char* aname, const char* p_num, const char* aaddr) {
		strcpy(name, aname);
		strcpy(phone_num, p_num);
		strcpy(addr, aaddr);
		count++;
	}
	char* GetName() { return name; }
	/*void SetName(const char* aname) {		// �̷��� ���ư��� �����ڿ� Set�Լ� ��������
		strcpy(name, aname);				// �����ڿ��� �ٷ� �ʱ�ȭ
	}*/

	char* GetNum() { return phone_num; }
	/*void SetNum(int p_num) {
		phone_num = p_num;
	}*/

	char* GetAddr() { return addr; }
	/*void SetAddr(const char* aaddr) {
		strcpy(addr, aaddr);
	}*/
	~CMember() { count--; }
	/*static void InitCount() {
		count = 0;
	}*/
	static void OutCount() {
		printf("����ȸ������ %d�� �Դϴ�.", count);
	}

	void MemberPrint() {
		printf("��ȣ : %d , ȸ���̸�: %s  ��ȭ��ȣ: %s  ȸ���ּ�: %s\n",count, name, phone_num, addr);
	}
	
};
int CMember::count;

int main()
{
	CMember c1("������", "01011112222", "�λ걤���� ������");
	c1.MemberPrint();
	CMember::OutCount();
	CMember c2("ȫ�浿", "01022222222", "�λ걤���� ������");
	c2.MemberPrint();
}
