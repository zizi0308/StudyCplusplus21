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
	/*void SetName(const char* aname) {		// 이렇게 돌아가서 생성자에 Set함수 쓰지말고
		strcpy(name, aname);				// 생성자에서 바로 초기화
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
		printf("현재회원수는 %d명 입니다.", count);
	}

	void MemberPrint() {
		printf("번호 : %d , 회원이름: %s  전화번호: %s  회원주소: %s\n",count, name, phone_num, addr);
	}
	
};
int CMember::count;

int main()
{
	CMember c1("조희지", "01011112222", "부산광역시 금정구");
	c1.MemberPrint();
	CMember::OutCount();
	CMember c2("홍길동", "01022222222", "부산광역시 수영구");
	c2.MemberPrint();
}
