#include<iostream>
#include<iomanip>
#define MAXSIZE 11
using namespace std;
struct NodeType
{
	char data[8];	//节点中的数据
	int cur;		//下一个节点的下标，相当于指针
};
struct SLinkList
{
	int elem;	//静态链表存储空间基址
	int length;	//静态链表中的元素数目
	int listSize;	//静态链表当前可容纳的元素数目
};
NodeType space[MAXSIZE];	//将静态链表定为全局变量
SLinkList* temp;


//初始化静态链表
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

//输出静态链表的数据
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
int Malloc()//为插入的变量分配空间
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
	int q = Malloc();	//获取新位置的下标
	cin >> space[q].data;
	int i = space[1].cur;
	int j = 1;
	while (i != 0 && j < n)	//让j停留在n的前一个位置，且不越界
	{
		i = space[i].cur;	//相当于i++
		j++;
	}
	space[q].cur = i;	//将上一个的尾指针赋给新数据的指针
	space[n].cur = q;	//将本数据的地址赋给上一个数据的指针
}

void Delete()
{
	int temp;
	cin >> temp;
	int i = space[1].cur;
	int j = 1;
	while (i != 0 && j < temp)	//将指针移向目标指针的前一个
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