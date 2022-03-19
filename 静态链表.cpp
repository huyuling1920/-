#include<iostream>
#include<iomanip>
#define MAXSIZE 11
using namespace std;
struct NodeType
{
	char data[8];	//�ڵ��е�����
	int cur;		//��һ���ڵ���±꣬�൱��ָ��
};
struct SLinkList
{
	int elem;	//��̬����洢�ռ��ַ
	int length;	//��̬�����е�Ԫ����Ŀ
	int listSize;	//��̬����ǰ�����ɵ�Ԫ����Ŀ
};
NodeType space[MAXSIZE];	//����̬����Ϊȫ�ֱ���
SLinkList* temp;


//��ʼ����̬����
void InitNode()
{
	temp = new SLinkList;
	memset(space, 0, sizeof(space));
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[0].cur = 2;
	space[1].cur = 0;
	space[MAXSIZE - 1].cur = 0;
	temp->elem = 2;
	temp->length = 0;
	temp->listSize = 9;
}

//�����̬���������
void Show()
{
	for (int i = 0; i <= MAXSIZE - 1; i++)
	{
		cout << left << setw(8) << space[i].data;
		cout << right << setw(2) << space[i].cur;
		cout << endl;
	}
	for (int i = 0; i < 20; i++)
		cout << "*";
	cout << endl;
}
void Insert();
void Delete();
void Search();

int main(void)
{
	InitNode();
	string order;
	while (1)
	{
		cin >> order;
		if (order == "insert")
			Insert();
		else if (order == "show")
			Show();
		else if (order == "delete")
			Delete();
		else if (order == "search")
			Search();
		else
			break;
	}
}
int Malloc()//Ϊ����ı�������ռ�
{
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[space[0].cur].cur;
	return i;
}

void Insert()
{
	int n;
	cin >> n;
	int q = Malloc();	//��ȡ��λ�õ��±�
	cin >> space[q].data;
	int i = space[1].cur;
	int j = 1;
	while (i != 0 && j < n)	//��jͣ����n��ǰһ��λ�ã��Ҳ�Խ��
	{
		i = space[i].cur;	//�൱��i++
		j++;
	}
	space[q].cur = i;	//����һ����βָ�븳�������ݵ�ָ��
	space[n].cur = q;	//�������ݵĵ�ַ������һ�����ݵ�ָ��
}

void Delete()
{
	int temp;
	cin >> temp;
	int i = space[1].cur;
	int j = 1;
	while (i != 0 && j < temp)	//��ָ������Ŀ��ָ���ǰһ��
	{
		i = space[i].cur;
		j++;
	}
	space[j].cur = space[space[j].cur].cur;
	space[i].cur = space[0].cur;
	space[0].cur = i;
}

void Search()
{
	string temp;
	cin >> temp;
	int i = space[1].cur;
	bool flag = false;
	while (i != 0)
	{
		if (space[i].data == temp)
		{
			flag = true;
			break;
		}
		i = space[i].cur;
	}
	if (flag)
		cout << i << endl;
	else
		cout << "NO FOUND!" << endl;
	for (int j = 0; j < 20; j++)
		cout << "*";
	cout << endl;
}