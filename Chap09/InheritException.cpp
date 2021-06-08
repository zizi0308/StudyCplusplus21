#include <stdio.h>

class ExNagetive
{
protected:
	int number;

public:
	ExNagetive(int n) : number(n) {}
	virtual void PrintError() {
		printf("%d�� �����̹Ƿ� �߸��� ���Դϴ�.\n", number);
	}
};

class ExTooBig : public ExNagetive
{
public:
	ExTooBig(int n) : ExNagetive(n) {}
	virtual void PrintError() {
		printf("%d�� �ʹ� Ů�ϴ�. 100���� �۾ƾ� �մϴ�.\n", number);
	}
};

class ExOdd : public ExTooBig
{
public:
	ExOdd(int n) : ExTooBig(n) {}
	virtual void PrintError() {
		printf("%d�� Ȧ���Դϴ�. ¦������ �մϴ�.\n", number);
	}
};

int main()
{
	int n;

	for (;;) {
		try {
			printf("���ڸ� �Է��ϼ���(���� �� 0) : ");
			scanf("%d", &n);
			if (n == 0) break;
			if (n < 0) throw ExNagetive(n);
			if (n > 100) throw ExTooBig(n);
			if (n % 2 != 0) throw ExOdd(n);

			printf("%d�� ���ڴ� ��Ģ�� �´� �����Դϴ�.\n", n);
		}
		catch (ExNagetive& e) {
			e.PrintError();
		}
	}
}