// 01_504.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdlib.h>
using namespace std;
class Account
{
public:
	char xh[15];
	char mzi[15];
	char sex[10];
	float ywen;
	float sx;
	float Withdraw;
	float ave;
	float sum;
};
class SNode
{
public:
	Account Data;
	SNode * next;
};
class AccountMessages
{
private:
	SNode * Head;
	ifstream infile;
	ofstream outfile;

public:
	AccountMessages();      		//账户信息
	~AccountMessages();				//重载 
	SNode * InitHead();
	void LoginModule();				//验证模块
	int ChooseMenu();				//选择菜单
	void ChooseOperate();			//选择操作 
	void EnterMessages();			//传递信息
	void ShowMessages();			//显示消息
 	int AccountNumber();			//账户编号 
	void DeleteRecord();			//删除程序
	void InquiryRecord();			//询问记录
	void ModifyRecord();			//修改记录
	void InsertRecord();			//插入记录
	void Statistics();				//统计
	void SortScore();				//分类排序 
	void SaveRecord();
	void QuitSystem();				//中断系统
	void OutputSingle(Account &pt);	//输出账户信息表 
	bool EmptyRecord();				//清空记录  bool 布尔型判断真假 
	void ExtractMessages();			//提取信息 
};

AccountMessages::AccountMessages()
{
	Head = InitHead();
	LoginModule();
}

AccountMessages::~AccountMessages()
{
	SNode * p = Head;
	SNode * q;
	while (p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
	delete p;
}

SNode * AccountMessages::InitHead()
{
	SNode * head;
	head = new SNode;
	if (NULL == head)
	{
		cout << "内存分配失败！！" << endl;
		exit(-1);
	}
	head->next = NULL;
	return head;
}

void AccountMessages::LoginModule()
{
	char UName[15];
	char Password[15];
	char FUName[15];
	char FPassword[15];
	int cho;

LOGIN:                                                                                     // 登录界面 

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$         $$$$  $$$$$$  $$$$  $$$$$$  $$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$  $$$$$$$$$$$$$  $$  $$$$$$  $$$$$$  $$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$         $$$$$$$$  $$$$$$$$          $$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$  $$$$$$$$$$$$$$$  $$$$$$$$  $$$$$$  $$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$  $$$$$$$$$$$$$$$  $$$$$$$$  $$$$$$  $$$$$$$$$$$$$$$" << endl;
  	cout << "$$$$$$$$$$$$$$  $$$$$$$$$$$$$$$  $$$$$$$$  $$$$$$  $$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$                       $$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$      -> 1 登陆.       $$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$      -> 2 注册.       $$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$                       $$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$540$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << endl << "请选择: ";
	cin >> cho;
	while (cho != 1 && cho != 2)
	{
		cout << "输入有误，请重新输入: ";
		cin >> cho;
	}

	switch (cho)
	{
	case 1:
		infile.open("UNamePassword.txt", ios::in);
		cout << endl << endl;
		cout << '\t' << "username: ";
		cin >> UName;
		cout << '\t' << "password: ";
		cin >> Password;
		infile >> FUName >> FPassword;
		if (strcmp(UName, FUName) == 0)
		{
			cout << "\n\n" << endl;
			cout << "\t登陆成功!!!" << endl;
			cout << "\t尊敬的会员，您好！"<<endl;
			infile.close();
			Sleep(2000);                                               //区分大小写 
		}
		else
		{
			cout << "\n\t\t账户名或密码有误，请重新输入！" << endl;
			infile.close();
			system("pause");                                          //getchar()
			system("cls");                                           //清屏操作 
			goto LOGIN;
		}
		break;

	case 2:
		outfile.open("UNamePassword.txt", ios::out);
		cout << endl << endl;
		cout << '\t' << "username: ";
		cin >> UName;
		outfile << UName << '\t';
		cout << '\t' << "passward: ";
		cin >> Password;
		outfile << Password << '\n';
		cout << "\n\n\t\t注册成功!!!" << endl;
		outfile.close();
		Sleep(2000);
		break;
	}
}

int AccountMessages::ChooseMenu()
{
	system("cls");
	cout << "菜单" << endl;
	cout << "________________________________________________________________________" << endl;
	cout << "\t1、 添加账户数据.\t2、 删除账户记录.\t" << endl;
	cout << "\t3、 查询账户记录.\t4、 修改账户记录.\t" << endl;
	cout << "\t5、 插入账户记录.\t6、 统计账户记录.\t" << endl;
	cout << "\t7、 账户记录排序.\t8   保存账户记录.\t" << endl;
	cout << "\t9、 显示账户记录.\t0、 退出.        \t" << endl;
	cout << "________________________________________________________________________" << endl;

	int choice;
	cout << "请选择: ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 0 && choice != 10)
	{
		cout << "输入有误，请重新输入: ";
		cin >> choice;
	}
	cout << endl;
	return choice;
}

void AccountMessages::ChooseOperate()
{
	int choice;

	while (1)
	{
		choice = ChooseMenu();
		switch (choice)
		{
		case 1:
			EnterMessages();
			system("pause");
			break;
		case 2:
			DeleteRecord();
			system("pause");
			break;
		case 3:
			InquiryRecord();
			system("pause");
			break;
		case 4:
			ModifyRecord();
			system("pause");
			break;
		case 5:
			InsertRecord();
			system("pause");
			break;
		case 6:
			Statistics();
			system("pause");
			break;
		case 7:
			SortScore();
			system("pause");
			break;
		case 8:
			SaveRecord();
			system("pause");
			break;
		case 9:
			ShowMessages();
			system("pause");
			break;
		case 0:
			QuitSystem();
			break;
		default:
			break;
		}
	}
}

void AccountMessages::EnterMessages()
{
	SNode * p = Head;
	SNode * n;
	outfile.open("Account1.txt", ios::app);
	int m = 0;

	if (!outfile)
	{
		cout << "打开目的文件失败！" << endl;
		exit(1);
	}
	cout << "请输入账户的编号，姓名，性别，本金、存款、取款（按 # 号键结束输入）: " << endl;
	while (1)
	{
		n = new SNode;
		if (NULL == n)
		{
			cout << "内存分配失败！" << endl;
			exit(-1);
		}
		n->next = NULL;
		cout << "请输入第 " << ++m << " 个账户的信息（按#号键结束）: " << endl;
		cin >> n->Data.xh;
		if (strcmp(n->Data.xh, "#") == 0)
			break;
		cin >> n->Data.mzi >> n->Data.sex >> n->Data.ywen >> n->Data.sx >> n->Data.Withdraw;
		n->Data.sum = n->Data.ywen + n->Data.sx-n->Data.Withdraw;
		n->Data.ave = n->Data.sum / 3.0;
		outfile << n->Data.xh << '\t' << n->Data.mzi << '\t' << n->Data.sex << '\t' << n->Data.ywen << '\t' << n->Data.sx << '\t' << n->Data.Withdraw << '\t' << n->Data.ave << '\t' << n->Data.sum << '\n';
		cout << endl;

		p->next = n;
		p = n;
	}
	outfile.close();
}

void AccountMessages::ShowMessages()
{
	ExtractMessages();
	SNode * p = Head->next;

	if (p == NULL)
	{
		cout << "没有改账户记录！" << endl;
		return;
	}

	cout << endl;
	cout << "———————————账户信息表 ——————————————" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "编号\t姓名\t性别\t本金\t存款\t取款\t余额" << endl;
	cout << "-------------------------------------------------------------" << endl;

	while (NULL != p)
	{
		cout << p->Data.xh << '\t' << p->Data.mzi << '\t' << p->Data.sex << '\t' << p->Data.ywen << '\t' << p->Data.sx << '\t' << p->Data.Withdraw << '\t' << p->Data.sum << endl;
		p = p->next;
	}
	cout << "-------------------------------------------------------------" << endl;
}

int AccountMessages::AccountNumber()
{
	SNode *p = Head;
	int n = 0;

	while (NULL != p->next)
	{
		++n;
		p = p->next;
	}
	return n;
}

void AccountMessages::DeleteRecord()
{
	SNode *p = Head;
	SNode *q;

	char t[5];
	char ch;
	cout << "请输入要删除的账户的编号：";
	cin >> t;

	while (p->next != NULL)
	{
		if (strcmp(p->next->Data.xh, t) == 0)
			break;
		p = p->next;
	}
	if (NULL == p->next)
	{
		cout << "没有找到该账户记录！" << endl;
		return;
	}
	OutputSingle(p->next->Data);

LOOP:                                                                              //循环 
	cout << "是否确定要删除该账户信息(Y / N)：";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		q = p->next;
		p->next = q->next;
		delete q;                                                                 //释放空间 
		cout << "删除成功！" << endl;
	}
	else if (ch == 'N' || ch == 'n')
	{
		cout << "该账户的信息未被删除." << endl;
		return;
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
		goto LOOP;
	}
	SaveRecord();
}

void AccountMessages::InquiryRecord()
{
	SNode *p = Head;
	int cho;
	char xh[15], mzi[15];

	cout << "|||||||||||||||||||||||||||||||||||" << endl;
	cout << "-------  1、 按编号查找.  ------" << endl;
	cout << "-------  2、 按姓名查找.  ------" << endl;
	cout << "|||||||||||||||||||||||||||||||||||" << endl;
	cout << endl;

CHOOSE:                                                                   //
	cout << "请输入要查找的方式(输入序号即可): ";
	cin >> cho;
	if (cho != 1 && cho != 2)
	{
		cout << "输入有误，请重新输入！" << endl;
		goto CHOOSE;
	}

	switch (cho)
	{
	case 1:
		cout << "请输入要查询的账户的编号: ";
		cin >> xh;
		cout << endl << endl;
		while (p->next != NULL)
		{
			if (strcmp(p->next->Data.xh, xh) == 0)
			{
				OutputSingle(p->next->Data);
				break;
			}
			p = p->next;
		}
		if (NULL == p->next)
		{
			cout << "查找失败，没有找到有关 " << xh << " 编号的账户信息！" << endl;
		}
		break;
	case 2:
		int n = 0;
		cout << "请输入要查询的账户的姓名: ";
		cin >> mzi;
		cout << endl << endl;
		while (p->next != NULL)
		{
			if (strcmp(p->next->Data.mzi, mzi) == 0)
			{
				++n;
				OutputSingle(p->next->Data);
			}
			p = p->next;
		}
		if (n > 1)
		{
			cout << "有 " << n << " 个叫 " << mzi << " 的账户." << endl;
		}
		else if (n == 0)
		{
			cout << "查找失败，没有找到有关 " << mzi << " 账户的信息！" << endl;
		}
		break;
	}
}

void AccountMessages::ModifyRecord()
{
	SNode *p = Head;
	char xh[15], ch;

	if (EmptyRecord())
	{
		cout << "当前账户信息系统为空，不能执行修改操作！" << endl << endl;
		return;
	}
	cout << "请输入要修改的账户的编号: ";
	cin >> xh;
	while (p->next != NULL)
	{
		if (strcmp(p->next->Data.xh, xh) == 0)
		{
			break;
		}
		p = p->next;
	}
	OutputSingle(p->next->Data);

Modify:                                                                                //插入修改 
	cout << "是否确定要修改该账户的信息(Y / N): ";
	cin >> ch;
	cout << endl;
	if (ch == 'Y' || ch == 'y')
	{
		cout << "请输入修改后的编号，姓名，性别，本金、存款、取款成绩: " << endl;
		cin >> p->next->Data.xh >> p->next->Data.mzi >> p->next->Data.sex >> p->next->Data.ywen >> p->next->Data.sx >> p->next->Data.Withdraw;
		p->next->Data.sum = p->next->Data.ywen + p->next->Data.sx-p->next->Data.Withdraw;
		p->next->Data.ave = p->next->Data.sum / 3.0;
		cout << "修改成功！" << endl;
		SaveRecord();
		ShowMessages();
	}
	else if (ch == 'N' || ch == 'n')
	{
		cout << "该账户的信息未被修改." << endl;
		return;
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
		goto Modify;
	}
}

void AccountMessages::InsertRecord()
{
	SNode *p = Head;
	int loc, i = 0;
	int m = AccountNumber();

	cout << "请输入要插入的位置: ";
	cin >> loc;
	while ((loc < 1) || (loc > m + 1))
	{
		cout << "插入位置有误！" << endl;
		cout << "请重新输入要插入的位置: ";
		cin >> loc;
	}

	SNode * pNew;
	pNew = new SNode;
	if (pNew == NULL)
	{
		cout << "内存分配失败！" << endl;
		exit(0);
	}
	while ((NULL != p) && (i < loc - 1))
	{
		p = p->next;
		++i;
	}
	cout << "请输入新账户的编号，姓名，性别，本金、存款、取款成绩." << endl;
	cin >> pNew->Data.xh >> pNew->Data.mzi >> pNew->Data.sex >> pNew->Data.ywen >> pNew->Data.sx >> pNew->Data.Withdraw;
	pNew->Data.sum = pNew->Data.ywen + pNew->Data.sx - pNew->Data.Withdraw;
	pNew->Data.ave = pNew->Data.sum / 3.0;
	pNew->next = p->next;
	p->next = pNew;
	cout << endl;
	cout << "插入成功！" << endl;
	SaveRecord();
	cout << endl;
}

void AccountMessages::Statistics()
{
	SNode *p = Head;
	int n;
	int s1 = 0, s2 = 0;
	int c = 0, m = 0, e = 0;
	float ch = 0, ma = 0, en = 0, num = 0;

	n = AccountNumber();
	while (p->next != NULL)
	{
		if (strcmp(p->next->Data.sex, "男") == 0)
			++s1;
		else
			++s2;
		if (p->next->Data.ywen < 60)
			++c;
		if (p->next->Data.sx < 60)
			++m;
		if (p->next->Data.Withdraw < 60)
			++e;
		ch += p->next->Data.ywen;
		ma += p->next->Data.sx;
		en += p->next->Data.Withdraw;
		num += p->next->Data.sum;
		p = p->next;
	}
	

	cout << "全部人数为: " << n << " 人" << endl;
	cout << "男: " << s1 << '\t' << "女: " << s2 << endl;
	cout << "本金总余额: " << ch << endl;
	cout << "存款总余额: " << ma << endl;
	cout << "取款总余额: " << en << endl;
	cout << "总余额: " << num << endl;
}

void AccountMessages::SortScore()
{
	SNode *p = Head->next;
	SNode *t, *r;
	int n = AccountNumber();
	int i, j;
	int cho;

	cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+++++++++++  1、 按编号排序.  +++++++++++" << endl;
	cout << "+++++++++++  2、 按余额排序.  +++++++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;

SORT:                                                                                     //排序函数 
	cout << "请输入要排序的方式(输入序号即可): ";
	cin >> cho;
	if (cho != 1 && cho != 2)
	{
		cout << "输入有误，请重新输入！" << endl;
		goto SORT;
	}

	switch (cho)
	{
	case 1:
		r = new SNode;
		for (i = 0; i < n - 1; ++i)
		{
			t = p;
			for (j = 0; j < n - i - 1; ++j)
			{
				if (strcmp(t->Data.xh, t->next->Data.xh) > 0)
				{
					r->Data = t->next->Data;
					t->next->Data = t->Data;
					t->Data = r->Data;
				}
				t = t->next;
			}
		}
		delete r;
		break;
	case 2:
		r = new SNode;
		for (i = 0; i < n - 1; ++i)
		{
			t = p;
			for (j = 0; j < n - i - 1; ++j)
			{
				if (t->Data.sum < t->next->Data.sum)
				{
					r->Data = t->next->Data;
					t->next->Data = t->Data;
					t->Data = r->Data;
				}
				t = t->next;
			}
		}
		delete r;
		break;
	}

	cout << "排序成功！" << endl;
	SaveRecord();
	ShowMessages();
}

void AccountMessages::SaveRecord()
{
	SNode *p = Head->next;
	outfile.open("Account1.txt", ios::out);

	if (!outfile)
	{
		cout << "打开目的文件失败！！！error ==！" << endl;
		exit(1);
	}

	while (p != NULL)
	{
		outfile << p->Data.xh << '\t' << p->Data.mzi << '\t' << p->Data.sex << '\t' << p->Data.ywen << '\t' << p->Data.sx << '\t' << p->Data.Withdraw << '\t' << p->Data.ave << '\t' << p->Data.sum << '\n';
		p = p->next;
	}
	cout << "保存成功！" << endl;
	outfile.close();
}

void AccountMessages::QuitSystem()
{
	SaveRecord();
	cout << "已退出！" << endl;
	exit(1);
}

void AccountMessages::OutputSingle(Account &pt)
{
	cout << "该账户信息如下：" << endl;
	cout << "编号：" << pt.xh << endl;
	cout << "姓名：" << pt.mzi << endl;
	cout << "性别：" << pt.sex << endl;
	cout << "本金：" << pt.ywen << endl;
	cout << "存款：" << pt.sx << endl;
	cout << "取款：" << pt.Withdraw << endl;
	cout << "平均金额：" << pt.ave << endl;
	cout << "余额：" << pt.sum << endl << endl;
}

bool AccountMessages::EmptyRecord()
{
	SNode *p = Head;
	if (NULL == p->next)
		return true;
	else
		return false;
}

void AccountMessages::ExtractMessages()
{
	SNode *p = Head;
	SNode *q;
	infile.open("Account1.txt");

	if (!infile)
	{
		cout << "打开源文件失败！" << endl;
		exit(1);
	}

	while (!infile.eof())
	{
		q = new SNode;
		infile >> q->Data.xh >> q->Data.mzi >> q->Data.sex >> q->Data.ywen >> q->Data.sx >> q->Data.Withdraw >> q->Data.ave >> q->Data.sum;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	SNode *pt = Head;
	while (pt->next->next != NULL)
		pt = pt->next;
	q = pt->next;
	pt->next = NULL;
	delete q;

	infile.close();
}
int main()
{
	AccountMessages stu1;
	stu1.ChooseOperate();
}
