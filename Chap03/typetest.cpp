#include <iostream>

class CTest {
private:
	int m_num;
	int* ptr;

public:
	CTest(int num) {	// 19번 라인의 값을 초기화 해주기위해 생성자생성(원래있는 디폴트생성자는 인수가 없기때문에 쓰지못함), 인수를 하나가지는 변환생성자
		m_num = num;
		printf("생성자 호출 : %d\n", m_num);
	}
	CTest() {			// 디폴트 생성자 생성 >> 새로 생성자를 생성하면 디폴트 생성자가 사라지기 때문에 다시 생성해줌
		printf("디폴트 생성자 \n");
	};					

	CTest(int num, int* ptr) {  // 복사생성자는 인수가 하나이므로 깊은 복사를 하기위한 생성자 호출(동적할당을 하고 그 포인터를 받아 별도의 주소를 가리키게 함)
		this->m_num = num;		// 동적할당을 하면 얕은 복사에서 원본을 삭제했을때 없는 데이터의 주소를 가리키는 것을 방지 할 수 있다.
		this->ptr = new int;	// int 타입 메모리 동적할당 동적할당받은 시작주소값을 this->ptr에 넣어줌
		this->ptr = ptr;		// ptr에 this->ptr넣어줌
		printf("인자 두개 생성자 호출 : %d, %p", m_num, ptr);
	}

	CTest(const CTest&other) {	// 어떤함수의 인수로 객체를 사용(레퍼런스 없이) >> 복사생성자 호출 >> 그 생성자의 객체 >> 복사생성자호출 (재귀호출에 빠짐)
		this->m_num = other.m_num;
		this->ptr = new int;	// int 타입 메모리 동적할당 동적할당받은 시작주소값을 this->ptr에 넣어줌
		this->ptr = other.ptr;
		printf("복사생성자 호출 : %d, %p", m_num, ptr);
	}

	~CTest() {
		delete ptr;				// 동적할당을 한 경우 소멸자에서 해제시킨다.
	}
	void GetData() {
		printf("%d\n", m_num);
	}
};

int main()
{
	/* 기본자료형 */
	int a = 10;
	int b(20);			// C++에서 제공하는 타입, 일반변수도 클래스와 비슷하게 만들 수 있음
	int c(a);
	printf("%d %d %d\n", a, b, c);
	/* 사용자 자료형 */
	CTest c1(100);		// 인수 1개의 생성자 호출
	CTest c2;			// 디폴트 생성자 호출
	CTest c3(c1);		// 복사생성자 호출(얕은 복사 >> 주소를 복사한다(참조를 전달받기 때문))
	CTest c4(50, nullptr);
	c3.GetData();
	return 0;
}