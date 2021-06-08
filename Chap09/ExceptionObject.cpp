#include <stdio.h>

class Exception
{
private:
	int ErrorCode;

public:
	Exception(int ae) : ErrorCode(ae) {}
	int GetErrorCode() { return ErrorCode; }
	void ReportError() {
		switch (ErrorCode) {
		case 1:
			puts("메모리가 부족합니다.");
			break;
		case 2:
			puts("연산범위를 초과했습니다.");
			break;
		case 3:
			puts("하드 디스크가 가득 찼습니다.");
			break;
		}
	}
};

void report()			// 에러발생시 예외객체를 생성하며 던짐
{
	if (true/*예외발생*/) throw Exception(3);

	// 여기까지 왔으면 무사히 작업 완료했음
}

int main()
{
	try {
		report();
		puts("작업을 완료했습니다.");
	}
	catch (Exception &e) {		// 던져짐 당한 객체를 받아 에러코드를 얻어 메세지출력까지 예외객체에게 시킴
		printf("에러코드 = %d =>", e.GetErrorCode());
		e.ReportError();
	}
}