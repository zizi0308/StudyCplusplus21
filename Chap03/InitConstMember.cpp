#include <stdio.h>

class Some
{
public:
	const int total;		// const는 스택영역에 저장 X, 정적영역에 저장
	Some(int atotal) : total(atotal) {}		// 초기화 리스트 방식 const는 변경할 수 없는 값이므로 객체생성이전(값 넣어지기 전에)에 특별한 리스트영역 만들어 초깃값을 할당한다.
	/*Some(int atotal) {	// const 때문에 일반적인 대입연산을 통한 초기화방식은 쓸 수 없다.
		total = atotal;
	}*/
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);			// S라는 이름으로 메모리를 할당 이후 생성자 호출로 5를 전달받음
	S.OutTotal();
}