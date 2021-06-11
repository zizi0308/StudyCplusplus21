#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cursor.h>				// 화면전체를 사용, 필요한 gotoxy와 delay함수를 포함하는 헤더파일
#include <assert.h>
#include <iostream>
using namespace std;

/* 전역변수 */
const int MaxCard = 48;			// 화투패 개수
const int CardGap = 4;			// 카드간의 간격
const int Speed = 1000;			// 카드 낼 때 대기시간
const int PromptSpeed = 2000;	// 메세지 출력 대기시간

// 화투 한장을 표현하는 클래스, 화투숫자 비교 후 종류비교
struct SCard					// 카드는 화투를 표현하는 데이터일 뿐이므로 구조체로 선언
{
	char Name[4];				// 화투이름
	SCard() { Name[0] = 0; }	// 디폴트 생성자(카드섞을 때, 상대방에게 피가 없을 때)
	SCard(const char* pName) {	// 동적할당
		strcpy(Name, pName);
	}
	int GetNumber() const {		// 화투숫자
		if (isdigit(Name[0])) return Name[0] - '0';		// 문자가 숫자에 속하는지 검사하는 isdigit
		if (Name[0] == 'J') return 10;					// 10번 이상의 카드 숫자처리
		if (Name[0] == 'D') return 11;
		return 12;
	};
	int GetKind() const {		// 화투종류 
		if (strcmp(Name + 1, "광") == 0) return 0;
		else if (strcmp(Name + 1, "십") == 0) return 1;
		else if (strcmp(Name + 1, "오") == 0) return 2;
		else return 3;		// 피
	}
	friend ostream& operator <<(ostream& c, const SCard& C) {	// Name멤버를 출력
		return c << C.Name;
	}
	bool operator ==(const SCard& Other) const {	// 두 카드가 같은 카드인지 비교
		return (strcmp(Name, Other.Name) == 0);
	}
	bool operator <(const SCard& Other) const {		// 두 카드의 대소 비교
		if (GetNumber() < Other.GetNumber()) return true;
		if (GetNumber() > Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true;
		return false;
	}
};

// 화투의 초기 카드 목록
SCard HwaToo[MaxCard] = {
	"1광","1오","1피","1피","2십","2오","2피","2피","3광","3오","3피","3피",
	"4십","4오","4피","4피","5십","5오","5피","5피","6십","6오","6피","6피",
	"7십","7오","7피","7피","8광","8십","8피","8피","9십","9오","9피","9피",
	"J십","J오","J피","J피","D광","D피","D피","D피","B광","B십","B오","B피"
};

// 카드의 집합을 관리하는 클래스
class CCardSet
{
protected:
	SCard Card[MaxCard];
	int Num;
	const int sx, sy;									// 카드집합의 콘솔 화면상 좌표(여기서 출력됨)
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
	int GetNum() { return Num; }						// 함수 개수조사
	SCard GetCard(int idx){ return Card[idx]; }			// 카드배열 확인(읽기전용함수)
	void Reset() {										
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;	// 모든 카드를 초기화
		Num = 0;
	}
	void InsertCard(SCard C);							// 숫자순서대로 카드를 삽입하는 함수
	SCard RemoveCard(int idx);							// 가지고 있던 카드를 지우고 리턴
	int FindSameCard(SCard C, int* pSame);				// 같은 카드를 찾는 함수
	int FindFirstCard(const char* pName);				// 숫자나 종류가 일치하는 최초의 카드 검색해리턴
};

void CCardSet::InsertCard(SCard C) {
	int i;

	if (C.Name[0] == 0) return;
	for (i = 0; i < Num; i++) {										// 카드를 순서대로 정렬
		if (C < Card[i]) break;										// 정렬할 위치를 찾음
	}
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));		// memmove 메모리 이동함수, &Card[i + 1]의 메모리에 &Card[i]을 붙여넣는다
	Card[i] = C;													// 새카드 삽입
	Num++;
}

SCard CCardSet::RemoveCard(int idx) {								// 카드를 낼 때, 데크에서 카드를 뒤집을 때 해당카드를 제거하고 리턴
	assert(idx < Num);												// assert << 디버깅 시 오류를 검출하기위해 쓰는 함수
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--;
	return C;
}

int CCardSet::FindSameCard(SCard C, int* pSame) {					// 먹을 수 있는 카드가 있는지 없는지 찾아보는 함수 
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) {
		if (Card[i].GetNumber() == C.GetNumber()) {					// 먹을게 있으면
			num++;													// num증가
			*p++ = i;												
		}
	}
	*p = -1;														// 먹을게 없으면 카드 하나를 잃음
	return num;
}

int CCardSet::FindFirstCard(const char* pName) {					// 숫자나 종류가 일치하는 카드의 존재여부를 신속하게 검색
	int i;

	for (i = 0; i < Num; i++) {
		if (strstr(Card[i].Name, pName) != NULL) {					// 문자열 안에서 문자열로 검색하는 함수, 숫자나 종류가 같은 카드가 있다면
			return i;												// 해당 첨자를 리턴
		}
	}
	return -1;
}

// 담요 중앙에 카드를 쌓아 놓는 데크
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }				// 콘솔화면에 띄우기 위한 좌표
	void Shuffle() {												// 카드를 섞을 때 필요한 함수
		int i, n;
		for (i = 0; i < MaxCard; i++) {
			do {
				n = random(MaxCard);								// 모든 카드를 무작위로 섞는다
			} while (Card[n].Name[0] != NULL);						// 무작위로 섞인 카드의 첫번째가 빈값이 아니면
			Card[n] = HwaToo[i];									// 화투에 카드의 번호를 대입해준다
			Num++;
		}
	}
	SCard Pop() { return RemoveCard(Num - 1); }						// 섞은 카드를 순서대로 한장씩 돌리기 위한 함수(RemoveCard의 마지막 하나를 리턴)
	bool IsEmpty() { return Num == 0; }								// 판이 비었음을 나타냄(종료)
	bool IsNotLast() { return Num > 1; }							// 카드가 아직 있음(게임이 마무리 되지않음)을 나타냄
	void Draw(bool bFlip) {
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");		// 중앙에 뒤집혀져있는 카드를 나타냄
	}
};

// 게임을 하는 플레이어
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }			// 카드의 집합을 상속
	void Draw(bool MyTurn) {										// 플레이어의 패를 그리는 함수
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {			// 카드의 패를 순서대로 그려줌 (카드간격도 함께)
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) {											// 자신의 차례일 때, 자신이 가지고 있는 카드의 일련번호를 띄워준다 
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// 게임이 진행되는 담요
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }			// 카드를 가지고 정렬상태로 표시하기 위해 Player를 상속받음
	void Draw() {
		CPlayer::Draw(false);										// 카드를 보여주는 역할을 하되 카드를 고를 필요는 없음(담요는 게임에 참여X)
	}
	void DrawSelNum(int* pSame) {									//  이름과 일치하는 카드가 2장일 때, 어떤 카드를 먹을지 선택받는 함수
		int n;														
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {				// 일치하는 카드가 2장일 때, 어떤 카드를 먹을지 선택(위쪽에 일련번호 출력)
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) {							// 먹을 카드 아래쪽에 출력하여 두 카드가 일치했을 때를 보여주는 함수
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// 플레이어가 먹은 카드의 집합
class CPlayerPae : public CCardSet									// 플레이어가 게임중에 먹은 패와 점수를 관리(카드의 집합을 나타내는 CCardSet을 상속)
{
private:
	int nGo;														// 고 횟수

public:
	int OldScore;													// 이전점수
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }	// 점수는 6점, 고 횟수는 0으로 초기화
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }	
	int GetGo() { return nGo; }										// 고 할때마다 출력함
	void IncreaseGo() { nGo++; }									// 고 횟수는 1회씩만 증가
	void Draw();													// 패 출력
	SCard RemovePee();												// 피를 뺏겨 점수가 줄어드는 상황
	int CalcScore();												// 점수를 계산
};

void CPlayerPae::Draw() {											// 먹은 패를 한번에 출력
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;						

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind < 3) {												// 광, 십, 오는 한줄로 출력
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else {														// 피는 여러줄로 출력
			gotoxy(x[3], py);										// 개행처리를 위한 py사용
			x[3] += CardGap;										// 종류별로 4개의 x좌표를 유지하며 해당종류의 카드가 나올 때마다 CardGap만큼 오른쪽이동 
			if (x[3] > 75) {										
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];											// 카드 출력
	}
	gotoxy(sx + 23, sy);
	cout << "점수:" << CalcScore() << "점, " << nGo << "고";		// 점수와 고의 위치 지정
}

SCard CPlayerPae::RemovePee() {							// 상대방이 세장을 한꺼번에 먹거나 싹쓸이했을 때 피한장을 주는 함수
	int idx;

	idx = FindFirstCard("피");
	if (idx != -1) {									// 피가 존재하면
		return RemoveCard(idx);							// 상대방의 먹은 패로 리턴
	}
	return SCard();										// 피가 없으면 그냥 놔둠
}

int CPlayerPae::CalcScore() {							// 고스톱 규칙대로 점수 계산
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };				// 광 갯수에 따른 계산(4광, 5광, 6광)

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();						
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;	// 비광이 포함된 광은 2점이므로 점수 -1
	if (n[1] >= 5) NewScore += (n[1] - 4);						// 특정카드 종류를 다 모았을 때 점수추가	
	if (n[2] >= 5) NewScore += (n[2] - 4);						
	if (n[3] >= 10) NewScore += (n[3] - 9);						
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5; // 십과 오는 5장부터 1점으로 계산
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;
	return NewScore;									// 새로운 점수를 리턴
}

// 함수 원형
void Initialize();										// 데크의 패를 무작위로 섞어 카드를 초기화	
void DrawScreen();										// 화면을 지우고 모든 객체의 Draw함수를 차례대로 호출해 그림
void OutPrompt(const char* Mes, int Wait = 0);			// 하단에 메세지 출력후 사용자가 읽을 때까지 잠시 기다리는 함수
int InputInt(const char* Mes, int start, int end);		// 지정한 범위의 정수를 하나 입력받는 함수

// 전역 변수
CDeck Deck(18, 9);								// 화투를 쌓아두는 데크배치
CPlayer South(5, 20), North(5, 1);				// 남군, 북군 두명의 선수가 게임에 참여
CBlanket Blanket(5, 12);						// 중간에 담요위치
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);	// 남군의 패, 북군의 패
bool SouthTurn;									// 누가 카드를 낼 차례인지 기억하는 함수

// 프로그램을 총지휘하는 main 함수
int main()
{
	int i, ch;									
	int arSame[4], SameNum;
	char Mes[256];				
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;

	randomize();
	Initialize();				// 카드섞고 패를 나누어 게임판 생성
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {		// 전체게임루프 시작지점
		DrawScreen();			// 각 객체를 화면에 그림
		if (SouthTurn) {		// 패를 담요에 옮기고 먹은 카드를 패로 옮길 때 그 대상카드를 미리 조사해 이동시킴(내 패)
			Turn = &South;
			TurnPae = &SouthPae;	 
			OtherPae = &NorthPae;	 
		}
		else {					// 패를 담요에 옮기고 먹은 카드를 패로 옮길 때 그 대상카드를 미리 조사해 이동시킴(상대 패)
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());	// 낼 카드를 질문
		ch = InputInt(Mes, 0, Turn->GetNum());				// 플레이어가 가지고 있는 카드의 개수만큼만 질문받음
		if (ch == 0) {										// 끝낼 때
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)		// 종료하기 전 한번 더 확인
				return 0;									// 종료
			else
				continue;									// 계속
		}

		// 플레이어가 카드를 한장 낸다.
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;									// 플레이어의 카드에서 한장이 빠져나간다	
		UserCard = Turn->GetCard(UserIdx);					
		SameNum = Blanket.FindSameCard(UserCard, arSame);
		switch (SameNum) {
		case 0:		// 일치하는 카드가 없는 경우
			UserSel = -1;									// 아무것도 먹지 못함
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));	// 유저가 낸 카드를 담요에 삽입		
			DrawScreen();													
			break;	
		case 1:		// 일치하는 카드가 하나있는 경우
			UserSel = arSame[0];
			break;
		case 2:		// 일치하는 카드가 두 개인 경우
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {		// 두 카드가 같을 때
				UserSel = arSame[0];
			}
			else {																// 두 카드가 다를 때
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);	// 둘 중하나 선택메세지
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];				// 선택한 카드를 UserSel에 대입
			}
			break;
		case 3:
			UserSel = arSame[1];			// 세개가 일치하는 경우(UserSel을 가운데 대입하고)
			UserTriple = true;				// 세장을 먹었다고 표시해줌
			break;
		}
		if (UserSel != -1) {							// 카드를 먹었다면
			Blanket.DrawTempCard(UserSel, UserCard);	// 담요의 카드를 먹은 패로 이동시킨다
		}
		delay(Speed);									// 사용자가 보게 화면을 잠시 멈춰줌

		// 데크에서 한장을 뒤집는다.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop();				// 데크의 제일 위에 있는 카드를 꺼내 DeckCard에 대입
		SameNum = Blanket.FindSameCard(DeckCard, arSame);	// 데크에 뒤집은 카드와 담요의 카드가 일치하는 개수를 표시
		switch (SameNum) {					// 윗줄의 일치 갯수에 따라서 게임이 다르게 진행됨
		case 0:								// 일치하는게 없을 때
			DeckSel = -1;					// 먹을게 없음을 표시
			break;
		case 1:								// 하나만 일치하는 경우
			DeckSel = arSame[0];			// DeckSel에 일치하는 작은 글자를 대입
			if (DeckSel == UserSel) {		// 
				if (Deck.IsNotLast()) {		// 막판이 아닌 경우 모든 카드를 반납하고 아무것도 먹지못함(설사)
					Blanket.InsertCard(DeckCard);	// 모든 카드 반납
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));	// 먹었던 것들을 다시 지움
					OutPrompt("설사했습니다.", PromptSpeed);
					continue;
				}
				else {						// 막판인 경우
					DeckSel = -1;			// DeckSel에 -1을 대입해 사용자가 낸 카드를 가져온다
				}
			}
			break;
		case 2:								// 두 개가 일치하는 경우
			if (UserSel == arSame[0]) {		// 해당카드(앞순서)가 플레이어가 찜해놓은 카드와 일치한다면
				DeckSel = arSame[1];		// 나머지 카드를 DeckSel에 대입해준다
			}
			else if (UserSel == arSame[1]) {// 해당카드(뒷순서)가 플레이어가 찜해놓은 카드와 일치한다면
				DeckSel = arSame[0];		// 나머지 카드를 DeckSel에 대입해준다
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {	// 따닥
					DeckSel = arSame[0];
				}
				else {
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3:								// 세 개가 일치하는 경우
			DeckSel = arSame[1];			// 가운데 카드를 선택해 놓고
			DeckTriple = true;				// DeckTriple에 true를 대입한다		
			break;	
		}
		if (DeckSel != -1) {							// DeckSel이 -1이 아니면
			Blanket.DrawTempCard(DeckSel, DeckCard);	// 담요의 카드를 먹은 패로 이동시킨다
		}
		Deck.Draw(false);
		delay(Speed);

		// 일치하는 카드를 거둬 들인다. 세 장을 먹은 경우는 전부 가져 온다.
		if (UserSel != -1) {
			if (UserTriple) {
				for (i = 0; i < 3; i++) {	// 담요의 카드를 먹은 카드로 이동
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));	
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));	// 담요의 카드를 먹은 패로 이동		
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));			// 플레이어가 낸 카드도 이동
			if (DeckSel != -1 && DeckSel > UserSel) {
				DeckSel -= (UserTriple ? 3 : 1);
			}
		}
		if (DeckSel != -1) {
			if (DeckTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));	 
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
			}
			TurnPae->InsertCard(DeckCard);
		}
		else {
			Blanket.InsertCard(DeckCard);
		}

		// 쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏는다.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("쪽입니다.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("따닥입니다.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("싹쓸이입니다.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// 점수를 계산하고 고, 스톱 여부를 질문한다.
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {
			DrawScreen();
			if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:계속)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else {
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("게임이 끝났습니다.", 0);

}

void Initialize()
{
	int i;

	Deck.Shuffle();									// 카드 무작위로 섞어 초기화
	for (i = 0; i < 10; i++) {					
		South.InsertCard(Deck.Pop());				// 플레이어 10장
		North.InsertCard(Deck.Pop());				// 상대 플레이어 10장
		if (i < 8) Blanket.InsertCard(Deck.Pop());	// 담요에 8장의 카드를 깐다 
	}
}

void DrawScreen()					// 화면을 지우고 모든 객체의 Draw함수를 차례대로 호출하여 그림
{
	clrscr();						// 화면을 지우는 명령어 clrscr
	South.Draw(SouthTurn);			// 턴이 왔을 때 플레이어의 화면을 그린다
	North.Draw(!SouthTurn);			// 턴이 왔을 때 상대 플레이어의 화면을 그린다
	Blanket.Draw();					// 담요를 그린다
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

void OutPrompt(const char* Mes, int Wait/*=0*/)		// 하단에 짧은 메시지 출력 후 사용자가 읽을 때까지 기다린다
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

int InputInt(const char* Mes, int start, int end)	// 지정한 범위의 정수하나를 입력받는 함수
{
	int ch;	

	OutPrompt(Mes);					
	for (;;) {
		ch = tolower(_getch());							// _getch()의 값이 대문자일때 소문자로 바꿔주는 함수 tolower
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;		// ch가 10이 아니거나 a가 아니면 계속
		if (ch == 'a') ch = 10; else ch = ch - '0';		// 최초카드가 a이면 ch에 10을 대입해주고, 마지막이면 0을 빼준다
		if (ch >= start && ch <= end) {					// ch가 처음이나 끝이 아니라면, 
			return ch;									// ch를 리턴해준다
		}
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
	}
}

