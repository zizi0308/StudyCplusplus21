#include <stdio.h>

class Some
{
public:
	const int total;		// const�� ���ÿ����� ���� X, ���������� ����
	Some(int atotal) : total(atotal) {}		// �ʱ�ȭ ����Ʈ ��� const�� ������ �� ���� ���̹Ƿ� ��ü��������(�� �־����� ����)�� Ư���� ����Ʈ���� ����� �ʱ갪�� �Ҵ��Ѵ�.
	/*Some(int atotal) {	// const ������ �Ϲ����� ���Կ����� ���� �ʱ�ȭ����� �� �� ����.
		total = atotal;
	}*/
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);			// S��� �̸����� �޸𸮸� �Ҵ� ���� ������ ȣ��� 5�� ���޹���
	S.OutTotal();
}