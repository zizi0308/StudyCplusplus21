#include <stdio.h>

class DBQuery
{
private:
	static int hCon;
	int Result;

public:
	DBQuery() {};
	static void DBConnect(const char* Server, const char* ID, const char* Pass);
	static void DBDisConnect();
	bool RunQuery(const char* SQL);
	// ...
};
int DBQuery::hCon;		// 초기화 안해도 자동으로 초기화 됨

void DBQuery::DBConnect(const char* Server, const char* ID, const char* Pass)
{
	// 여기서 DB서버에 접속한다.
	hCon = 1234;		// 포트번호
	puts("연결되었습니다.");
}

void DBQuery::DBDisConnect()	
{
	// 접속을 종료한다
	hCon = NULL;
	puts("연결이 끊어졌습니다.");
}

bool DBQuery::RunQuery(const char* SQL)
{
	// Query(hCon,SQL);
	puts(SQL);
	return true;
}

int main()
{
	DBQuery::DBConnect("Secret", "Adult", "doemfdmsrfk");
	DBQuery Q1, Q2, Q3;

	// 필요한 DB를 질의한다.
	Q1.RunQuery("select * from tblBuja where 나랑 친한사람");

	DBQuery::DBDisConnect();
}
