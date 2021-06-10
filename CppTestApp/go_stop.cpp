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
		else return 3;
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
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
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
	void Shuffle() {
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
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Draw(bool MyTurn) {										// 카드배치자리 함수
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) {
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
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	void Draw() {
		CPlayer::Draw(false);
	}
	void DrawSelNum(int* pSame) {
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) {
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// 플레이어가 먹은 카드의 집합
class CPlayerPae : public CCardSet
{
private:
	int nGo;

public:
	int OldScore;
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }
	int GetGo() { return nGo; }
	void IncreaseGo() { nGo++; }
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

void CPlayerPae::Draw() {
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind < 3) {
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else {
			gotoxy(x[3], py);
			x[3] += CardGap;
			if (x[3] > 75) {
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];
	}
	gotoxy(sx + 23, sy);
	cout << "점수:" << CalcScore() << "점, " << nGo << "고";
}

SCard CPlayerPae::RemovePee() {
	int idx;

	idx = FindFirstCard("피");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard();
}

int CPlayerPae::CalcScore() {
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;
	return NewScore;
}

// 함수 원형
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// 전역 변수
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;

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
	Initialize();
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {
		DrawScreen();
		if (SouthTurn) {
			Turn = &South;
			TurnPae = &SouthPae;
			OtherPae = &NorthPae;
		}
		else {
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) {
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)
				return 0;
			else
				continue;
		}

		// 플레이어가 카드를 한장 낸다.
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx);
		SameNum = Blanket.FindSameCard(UserCard, arSame);
		switch (SameNum) {
		case 0:
			UserSel = -1;
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));
			DrawScreen();
			break;
		case 1:
			UserSel = arSame[0];
			break;
		case 2:
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
				UserSel = arSame[0];
			}
			else {
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
			}
			break;
		case 3:
			UserSel = arSame[1];
			UserTriple = true;
			break;
		}
		if (UserSel != -1) {
			Blanket.DrawTempCard(UserSel, UserCard);
		}
		delay(Speed);

		// 데크에서 한장을 뒤집는다.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop();
		SameNum = Blanket.FindSameCard(DeckCard, arSame);
		switch (SameNum) {
		case 0:
			DeckSel = -1;
			break;
		case 1:
			DeckSel = arSame[0];
			if (DeckSel == UserSel) {
				if (Deck.IsNotLast()) {
					Blanket.InsertCard(DeckCard);
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("설사했습니다.", PromptSpeed);
					continue;
				}
				else {
					DeckSel = -1;
				}
			}
			break;
		case 2:
			if (UserSel == arSame[0]) {
				DeckSel = arSame[1];
			}
			else if (UserSel == arSame[1]) {
				DeckSel = arSame[0];
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
					DeckSel = arSame[0];
				}
				else {
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3:
			DeckSel = arSame[1];
			DeckTriple = true;
			break;
		}
		if (DeckSel != -1) {
			Blanket.DrawTempCard(DeckSel, DeckCard);
		}
		Deck.Draw(false);
		delay(Speed);

		// 일치하는 카드를 거둬 들인다. 세 장을 먹은 경우는 전부 가져 온다.
		if (UserSel != -1) {
			if (UserTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
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

	Deck.Shuffle();
	for (i = 0; i < 10; i++) {
		South.InsertCard(Deck.Pop());
		North.InsertCard(Deck.Pop());
		if (i < 8) Blanket.InsertCard(Deck.Pop());
	}
}

void DrawScreen()
{
	clrscr();
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(_getch());
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) {
			return ch;
		}
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
	}
}
