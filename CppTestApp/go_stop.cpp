#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cursor.h>				// ȭ����ü�� ���, �ʿ��� gotoxy�� delay�Լ��� �����ϴ� �������
#include <assert.h>
#include <iostream>
using namespace std;

/* �������� */
const int MaxCard = 48;			// ȭ���� ����
const int CardGap = 4;			// ī�尣�� ����
const int Speed = 1000;			// ī�� �� �� ���ð�
const int PromptSpeed = 2000;	// �޼��� ��� ���ð�

// ȭ�� ������ ǥ���ϴ� Ŭ����, ȭ������ �� �� ������
struct SCard					// ī��� ȭ���� ǥ���ϴ� �������� ���̹Ƿ� ����ü�� ����
{
	char Name[4];				// ȭ���̸�
	SCard() { Name[0] = 0; }	// ����Ʈ ������(ī�弯�� ��, ���濡�� �ǰ� ���� ��)
	SCard(const char* pName) {	// �����Ҵ�
		strcpy(Name, pName);
	}
	int GetNumber() const {		// ȭ������
		if (isdigit(Name[0])) return Name[0] - '0';		// ���ڰ� ���ڿ� ���ϴ��� �˻��ϴ� isdigit
		if (Name[0] == 'J') return 10;					// 10�� �̻��� ī�� ����ó��
		if (Name[0] == 'D') return 11;
		return 12;
	};
	int GetKind() const {		// ȭ������ 
		if (strcmp(Name + 1, "��") == 0) return 0;
		else if (strcmp(Name + 1, "��") == 0) return 1;
		else if (strcmp(Name + 1, "��") == 0) return 2;
		else return 3;		// ��
	}
	friend ostream& operator <<(ostream& c, const SCard& C) {	// Name����� ���
		return c << C.Name;
	}
	bool operator ==(const SCard& Other) const {	// �� ī�尡 ���� ī������ ��
		return (strcmp(Name, Other.Name) == 0);
	}
	bool operator <(const SCard& Other) const {		// �� ī���� ��� ��
		if (GetNumber() < Other.GetNumber()) return true;
		if (GetNumber() > Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true;
		return false;
	}
};

// ȭ���� �ʱ� ī�� ���
SCard HwaToo[MaxCard] = {
	"1��","1��","1��","1��","2��","2��","2��","2��","3��","3��","3��","3��",
	"4��","4��","4��","4��","5��","5��","5��","5��","6��","6��","6��","6��",
	"7��","7��","7��","7��","8��","8��","8��","8��","9��","9��","9��","9��",
	"J��","J��","J��","J��","D��","D��","D��","D��","B��","B��","B��","B��"
};

// ī���� ������ �����ϴ� Ŭ����
class CCardSet
{
protected:
	SCard Card[MaxCard];
	int Num;
	const int sx, sy;									// ī�������� �ܼ� ȭ��� ��ǥ(���⼭ ��µ�)
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
	int GetNum() { return Num; }						// �Լ� ��������
	SCard GetCard(int idx){ return Card[idx]; }			// ī��迭 Ȯ��(�б������Լ�)
	void Reset() {										
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;	// ��� ī�带 �ʱ�ȭ
		Num = 0;
	}
	void InsertCard(SCard C);							// ���ڼ������ ī�带 �����ϴ� �Լ�
	SCard RemoveCard(int idx);							// ������ �ִ� ī�带 ����� ����
	int FindSameCard(SCard C, int* pSame);				// ���� ī�带 ã�� �Լ�
	int FindFirstCard(const char* pName);				// ���ڳ� ������ ��ġ�ϴ� ������ ī�� �˻��ظ���
};

void CCardSet::InsertCard(SCard C) {
	int i;

	if (C.Name[0] == 0) return;
	for (i = 0; i < Num; i++) {										// ī�带 ������� ����
		if (C < Card[i]) break;										// ������ ��ġ�� ã��
	}
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));		// memmove �޸� �̵��Լ�, &Card[i + 1]�� �޸𸮿� &Card[i]�� �ٿ��ִ´�
	Card[i] = C;													// ��ī�� ����
	Num++;
}

SCard CCardSet::RemoveCard(int idx) {								// ī�带 �� ��, ��ũ���� ī�带 ������ �� �ش�ī�带 �����ϰ� ����
	assert(idx < Num);												// assert << ����� �� ������ �����ϱ����� ���� �Լ�
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--;
	return C;
}

int CCardSet::FindSameCard(SCard C, int* pSame) {					// ���� �� �ִ� ī�尡 �ִ��� ������ ã�ƺ��� �Լ� 
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) {
		if (Card[i].GetNumber() == C.GetNumber()) {					// ������ ������
			num++;													// num����
			*p++ = i;												
		}
	}
	*p = -1;														// ������ ������ ī�� �ϳ��� ����
	return num;
}

int CCardSet::FindFirstCard(const char* pName) {					// ���ڳ� ������ ��ġ�ϴ� ī���� ���翩�θ� �ż��ϰ� �˻�
	int i;

	for (i = 0; i < Num; i++) {
		if (strstr(Card[i].Name, pName) != NULL) {					// ���ڿ� �ȿ��� ���ڿ��� �˻��ϴ� �Լ�, ���ڳ� ������ ���� ī�尡 �ִٸ�
			return i;												// �ش� ÷�ڸ� ����
		}
	}
	return -1;
}

// ��� �߾ӿ� ī�带 �׾� ���� ��ũ
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }				// �ܼ�ȭ�鿡 ���� ���� ��ǥ
	void Shuffle() {												// ī�带 ���� �� �ʿ��� �Լ�
		int i, n;
		for (i = 0; i < MaxCard; i++) {
			do {
				n = random(MaxCard);								// ��� ī�带 �������� ���´�
			} while (Card[n].Name[0] != NULL);						// �������� ���� ī���� ù��°�� ���� �ƴϸ�
			Card[n] = HwaToo[i];									// ȭ���� ī���� ��ȣ�� �������ش�
			Num++;
		}
	}
	SCard Pop() { return RemoveCard(Num - 1); }						// ���� ī�带 ������� ���徿 ������ ���� �Լ�(RemoveCard�� ������ �ϳ��� ����)
	bool IsEmpty() { return Num == 0; }								// ���� ������� ��Ÿ��(����)
	bool IsNotLast() { return Num > 1; }							// ī�尡 ���� ����(������ ������ ��������)�� ��Ÿ��
	void Draw(bool bFlip) {
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");		// �߾ӿ� ���������ִ� ī�带 ��Ÿ��
	}
};

// ������ �ϴ� �÷��̾�
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }			// ī���� ������ ���
	void Draw(bool MyTurn) {										// �÷��̾��� �и� �׸��� �Լ�
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {			// ī���� �и� ������� �׷��� (ī�尣�ݵ� �Բ�)
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) {											// �ڽ��� ������ ��, �ڽ��� ������ �ִ� ī���� �Ϸù�ȣ�� ����ش� 
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// ������ ����Ǵ� ���
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }			// ī�带 ������ ���Ļ��·� ǥ���ϱ� ���� Player�� ��ӹ���
	void Draw() {
		CPlayer::Draw(false);										// ī�带 �����ִ� ������ �ϵ� ī�带 �� �ʿ�� ����(���� ���ӿ� ����X)
	}
	void DrawSelNum(int* pSame) {									//  �̸��� ��ġ�ϴ� ī�尡 2���� ��, � ī�带 ������ ���ù޴� �Լ�
		int n;														
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {				// ��ġ�ϴ� ī�尡 2���� ��, � ī�带 ������ ����(���ʿ� �Ϸù�ȣ ���)
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) {							// ���� ī�� �Ʒ��ʿ� ����Ͽ� �� ī�尡 ��ġ���� ���� �����ִ� �Լ�
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// �÷��̾ ���� ī���� ����
class CPlayerPae : public CCardSet									// �÷��̾ �����߿� ���� �п� ������ ����(ī���� ������ ��Ÿ���� CCardSet�� ���)
{
private:
	int nGo;														// �� Ƚ��

public:
	int OldScore;													// ��������
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }	// ������ 6��, �� Ƚ���� 0���� �ʱ�ȭ
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }	
	int GetGo() { return nGo; }										// �� �Ҷ����� �����
	void IncreaseGo() { nGo++; }									// �� Ƚ���� 1ȸ���� ����
	void Draw();													// �� ���
	SCard RemovePee();												// �Ǹ� ���� ������ �پ��� ��Ȳ
	int CalcScore();												// ������ ���
};

void CPlayerPae::Draw() {											// ���� �и� �ѹ��� ���
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;						

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind < 3) {												// ��, ��, ���� ���ٷ� ���
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else {														// �Ǵ� �����ٷ� ���
			gotoxy(x[3], py);										// ����ó���� ���� py���
			x[3] += CardGap;										// �������� 4���� x��ǥ�� �����ϸ� �ش������� ī�尡 ���� ������ CardGap��ŭ �������̵� 
			if (x[3] > 75) {										
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];											// ī�� ���
	}
	gotoxy(sx + 23, sy);
	cout << "����:" << CalcScore() << "��, " << nGo << "��";		// ������ ���� ��ġ ����
}

SCard CPlayerPae::RemovePee() {							// ������ ������ �Ѳ����� �԰ų� �Ͼ������� �� �������� �ִ� �Լ�
	int idx;

	idx = FindFirstCard("��");
	if (idx != -1) {									// �ǰ� �����ϸ�
		return RemoveCard(idx);							// ������ ���� �з� ����
	}
	return SCard();										// �ǰ� ������ �׳� ����
}

int CPlayerPae::CalcScore() {							// ���� ��Ģ��� ���� ���
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };				// �� ������ ���� ���(4��, 5��, 6��)

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();						
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B��") != -1) NewScore--;	// ���� ���Ե� ���� 2���̹Ƿ� ���� -1
	if (n[1] >= 5) NewScore += (n[1] - 4);						// Ư��ī�� ������ �� ����� �� �����߰�	
	if (n[2] >= 5) NewScore += (n[2] - 4);						
	if (n[3] >= 10) NewScore += (n[3] - 9);						
	if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1) NewScore += 5; // �ʰ� ���� 5����� 1������ ���
	if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1) NewScore += 3;
	if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1) NewScore += 3;
	if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1) NewScore += 3;
	return NewScore;									// ���ο� ������ ����
}

// �Լ� ����
void Initialize();										// ��ũ�� �и� �������� ���� ī�带 �ʱ�ȭ	
void DrawScreen();										// ȭ���� ����� ��� ��ü�� Draw�Լ��� ���ʴ�� ȣ���� �׸�
void OutPrompt(const char* Mes, int Wait = 0);			// �ϴܿ� �޼��� ����� ����ڰ� ���� ������ ��� ��ٸ��� �Լ�
int InputInt(const char* Mes, int start, int end);		// ������ ������ ������ �ϳ� �Է¹޴� �Լ�

// ���� ����
CDeck Deck(18, 9);								// ȭ���� �׾Ƶδ� ��ũ��ġ
CPlayer South(5, 20), North(5, 1);				// ����, �ϱ� �θ��� ������ ���ӿ� ����
CBlanket Blanket(5, 12);						// �߰��� �����ġ
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);	// ������ ��, �ϱ��� ��
bool SouthTurn;									// ���� ī�带 �� �������� ����ϴ� �Լ�

// ���α׷��� �������ϴ� main �Լ�
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
	Initialize();				// ī�弯�� �и� ������ ������ ����
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {		// ��ü���ӷ��� ��������
		DrawScreen();			// �� ��ü�� ȭ�鿡 �׸�
		if (SouthTurn) {		// �и� ��信 �ű�� ���� ī�带 �з� �ű� �� �� ���ī�带 �̸� ������ �̵���Ŵ(�� ��)
			Turn = &South;
			TurnPae = &SouthPae;	 
			OtherPae = &NorthPae;	 
		}
		else {					// �и� ��信 �ű�� ���� ī�带 �з� �ű� �� �� ���ī�带 �̸� ������ �̵���Ŵ(��� ��)
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1~%d,0:����) ", Turn->GetNum());	// �� ī�带 ����
		ch = InputInt(Mes, 0, Turn->GetNum());				// �÷��̾ ������ �ִ� ī���� ������ŭ�� ��������
		if (ch == 0) {										// ���� ��
			if (InputInt("���� �����̴ϱ�?(0:��,1:�ƴϿ�)", 0, 1) == 0)		// �����ϱ� �� �ѹ� �� Ȯ��
				return 0;									// ����
			else
				continue;									// ���
		}

		// �÷��̾ ī�带 ���� ����.
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;									// �÷��̾��� ī�忡�� ������ ����������	
		UserCard = Turn->GetCard(UserIdx);					
		SameNum = Blanket.FindSameCard(UserCard, arSame);
		switch (SameNum) {
		case 0:		// ��ġ�ϴ� ī�尡 ���� ���
			UserSel = -1;									// �ƹ��͵� ���� ����
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));	// ������ �� ī�带 ��信 ����		
			DrawScreen();													
			break;	
		case 1:		// ��ġ�ϴ� ī�尡 �ϳ��ִ� ���
			UserSel = arSame[0];
			break;
		case 2:		// ��ġ�ϴ� ī�尡 �� ���� ���
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {		// �� ī�尡 ���� ��
				UserSel = arSame[0];
			}
			else {																// �� ī�尡 �ٸ� ��
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);	// �� ���ϳ� ���ø޼���
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];				// ������ ī�带 UserSel�� ����
			}
			break;
		case 3:
			UserSel = arSame[1];			// ������ ��ġ�ϴ� ���(UserSel�� ��� �����ϰ�)
			UserTriple = true;				// ������ �Ծ��ٰ� ǥ������
			break;
		}
		if (UserSel != -1) {							// ī�带 �Ծ��ٸ�
			Blanket.DrawTempCard(UserSel, UserCard);	// ����� ī�带 ���� �з� �̵���Ų��
		}
		delay(Speed);									// ����ڰ� ���� ȭ���� ��� ������

		// ��ũ���� ������ �����´�.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop();				// ��ũ�� ���� ���� �ִ� ī�带 ���� DeckCard�� ����
		SameNum = Blanket.FindSameCard(DeckCard, arSame);	// ��ũ�� ������ ī��� ����� ī�尡 ��ġ�ϴ� ������ ǥ��
		switch (SameNum) {					// ������ ��ġ ������ ���� ������ �ٸ��� �����
		case 0:								// ��ġ�ϴ°� ���� ��
			DeckSel = -1;					// ������ ������ ǥ��
			break;
		case 1:								// �ϳ��� ��ġ�ϴ� ���
			DeckSel = arSame[0];			// DeckSel�� ��ġ�ϴ� ���� ���ڸ� ����
			if (DeckSel == UserSel) {		// 
				if (Deck.IsNotLast()) {		// ������ �ƴ� ��� ��� ī�带 �ݳ��ϰ� �ƹ��͵� ��������(����)
					Blanket.InsertCard(DeckCard);	// ��� ī�� �ݳ�
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));	// �Ծ��� �͵��� �ٽ� ����
					OutPrompt("�����߽��ϴ�.", PromptSpeed);
					continue;
				}
				else {						// ������ ���
					DeckSel = -1;			// DeckSel�� -1�� ������ ����ڰ� �� ī�带 �����´�
				}
			}
			break;
		case 2:								// �� ���� ��ġ�ϴ� ���
			if (UserSel == arSame[0]) {		// �ش�ī��(�ռ���)�� �÷��̾ ���س��� ī��� ��ġ�Ѵٸ�
				DeckSel = arSame[1];		// ������ ī�带 DeckSel�� �������ش�
			}
			else if (UserSel == arSame[1]) {// �ش�ī��(�޼���)�� �÷��̾ ���س��� ī��� ��ġ�Ѵٸ�
				DeckSel = arSame[0];		// ������ ī�带 DeckSel�� �������ش�
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {	// ����
					DeckSel = arSame[0];
				}
				else {
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3:								// �� ���� ��ġ�ϴ� ���
			DeckSel = arSame[1];			// ��� ī�带 ������ ����
			DeckTriple = true;				// DeckTriple�� true�� �����Ѵ�		
			break;	
		}
		if (DeckSel != -1) {							// DeckSel�� -1�� �ƴϸ�
			Blanket.DrawTempCard(DeckSel, DeckCard);	// ����� ī�带 ���� �з� �̵���Ų��
		}
		Deck.Draw(false);
		delay(Speed);

		// ��ġ�ϴ� ī�带 �ŵ� ���δ�. �� ���� ���� ���� ���� ���� �´�.
		if (UserSel != -1) {
			if (UserTriple) {
				for (i = 0; i < 3; i++) {	// ����� ī�带 ���� ī��� �̵�
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));	
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));	// ����� ī�带 ���� �з� �̵�		
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));			// �÷��̾ �� ī�嵵 �̵�
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

		// ��, ����, �Ͼ��� ������ �����ϰ� ������ �Ǹ� ���´�.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("���Դϴ�.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("�����Դϴ�.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("�Ͼ����Դϴ�.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// ������ ����ϰ� ��, ���� ���θ� �����Ѵ�.
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {
			DrawScreen();
			if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0:����, 1:���)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else {
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("������ �������ϴ�.", 0);

}

void Initialize()
{
	int i;

	Deck.Shuffle();									// ī�� �������� ���� �ʱ�ȭ
	for (i = 0; i < 10; i++) {					
		South.InsertCard(Deck.Pop());				// �÷��̾� 10��
		North.InsertCard(Deck.Pop());				// ��� �÷��̾� 10��
		if (i < 8) Blanket.InsertCard(Deck.Pop());	// ��信 8���� ī�带 ��� 
	}
}

void DrawScreen()					// ȭ���� ����� ��� ��ü�� Draw�Լ��� ���ʴ�� ȣ���Ͽ� �׸�
{
	clrscr();						// ȭ���� ����� ��ɾ� clrscr
	South.Draw(SouthTurn);			// ���� ���� �� �÷��̾��� ȭ���� �׸���
	North.Draw(!SouthTurn);			// ���� ���� �� ��� �÷��̾��� ȭ���� �׸���
	Blanket.Draw();					// ��並 �׸���
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

void OutPrompt(const char* Mes, int Wait/*=0*/)		// �ϴܿ� ª�� �޽��� ��� �� ����ڰ� ���� ������ ��ٸ���
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

int InputInt(const char* Mes, int start, int end)	// ������ ������ �����ϳ��� �Է¹޴� �Լ�
{
	int ch;	

	OutPrompt(Mes);					
	for (;;) {
		ch = tolower(_getch());							// _getch()�� ���� �빮���϶� �ҹ��ڷ� �ٲ��ִ� �Լ� tolower
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;		// ch�� 10�� �ƴϰų� a�� �ƴϸ� ���
		if (ch == 'a') ch = 10; else ch = ch - '0';		// ����ī�尡 a�̸� ch�� 10�� �������ְ�, �������̸� 0�� ���ش�
		if (ch >= start && ch <= end) {					// ch�� ó���̳� ���� �ƴ϶��, 
			return ch;									// ch�� �������ش�
		}
		OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���.");
	}
}

