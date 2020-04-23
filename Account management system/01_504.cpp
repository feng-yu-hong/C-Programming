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
	AccountMessages();      		//�˻���Ϣ
	~AccountMessages();				//���� 
	SNode * InitHead();
	void LoginModule();				//��֤ģ��
	int ChooseMenu();				//ѡ��˵�
	void ChooseOperate();			//ѡ����� 
	void EnterMessages();			//������Ϣ
	void ShowMessages();			//��ʾ��Ϣ
 	int AccountNumber();			//�˻���� 
	void DeleteRecord();			//ɾ������
	void InquiryRecord();			//ѯ�ʼ�¼
	void ModifyRecord();			//�޸ļ�¼
	void InsertRecord();			//�����¼
	void Statistics();				//ͳ��
	void SortScore();				//�������� 
	void SaveRecord();
	void QuitSystem();				//�ж�ϵͳ
	void OutputSingle(Account &pt);	//����˻���Ϣ�� 
	bool EmptyRecord();				//��ռ�¼  bool �������ж���� 
	void ExtractMessages();			//��ȡ��Ϣ 
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
		cout << "�ڴ����ʧ�ܣ���" << endl;
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

LOGIN:                                                                                     // ��¼���� 

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
	cout << "$$$$$$$$$$$$$$$$$$$$$$      -> 1 ��½.       $$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$      -> 2 ע��.       $$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$                       $$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$540$$$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << endl << "��ѡ��: ";
	cin >> cho;
	while (cho != 1 && cho != 2)
	{
		cout << "������������������: ";
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
			cout << "\t��½�ɹ�!!!" << endl;
			cout << "\t�𾴵Ļ�Ա�����ã�"<<endl;
			infile.close();
			Sleep(2000);                                               //���ִ�Сд 
		}
		else
		{
			cout << "\n\t\t�˻����������������������룡" << endl;
			infile.close();
			system("pause");                                          //getchar()
			system("cls");                                           //�������� 
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
		cout << "\n\n\t\tע��ɹ�!!!" << endl;
		outfile.close();
		Sleep(2000);
		break;
	}
}

int AccountMessages::ChooseMenu()
{
	system("cls");
	cout << "�˵�" << endl;
	cout << "________________________________________________________________________" << endl;
	cout << "\t1�� ����˻�����.\t2�� ɾ���˻���¼.\t" << endl;
	cout << "\t3�� ��ѯ�˻���¼.\t4�� �޸��˻���¼.\t" << endl;
	cout << "\t5�� �����˻���¼.\t6�� ͳ���˻���¼.\t" << endl;
	cout << "\t7�� �˻���¼����.\t8   �����˻���¼.\t" << endl;
	cout << "\t9�� ��ʾ�˻���¼.\t0�� �˳�.        \t" << endl;
	cout << "________________________________________________________________________" << endl;

	int choice;
	cout << "��ѡ��: ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 0 && choice != 10)
	{
		cout << "������������������: ";
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
		cout << "��Ŀ���ļ�ʧ�ܣ�" << endl;
		exit(1);
	}
	cout << "�������˻��ı�ţ��������Ա𣬱��𡢴�ȡ��� # �ż��������룩: " << endl;
	while (1)
	{
		n = new SNode;
		if (NULL == n)
		{
			cout << "�ڴ����ʧ�ܣ�" << endl;
			exit(-1);
		}
		n->next = NULL;
		cout << "������� " << ++m << " ���˻�����Ϣ����#�ż�������: " << endl;
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
		cout << "û�и��˻���¼��" << endl;
		return;
	}

	cout << endl;
	cout << "�����������������������˻���Ϣ�� ����������������������������" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "���\t����\t�Ա�\t����\t���\tȡ��\t���" << endl;
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
	cout << "������Ҫɾ�����˻��ı�ţ�";
	cin >> t;

	while (p->next != NULL)
	{
		if (strcmp(p->next->Data.xh, t) == 0)
			break;
		p = p->next;
	}
	if (NULL == p->next)
	{
		cout << "û���ҵ����˻���¼��" << endl;
		return;
	}
	OutputSingle(p->next->Data);

LOOP:                                                                              //ѭ�� 
	cout << "�Ƿ�ȷ��Ҫɾ�����˻���Ϣ(Y / N)��";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		q = p->next;
		p->next = q->next;
		delete q;                                                                 //�ͷſռ� 
		cout << "ɾ���ɹ���" << endl;
	}
	else if (ch == 'N' || ch == 'n')
	{
		cout << "���˻�����Ϣδ��ɾ��." << endl;
		return;
	}
	else
	{
		cout << "�����������������룡" << endl;
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
	cout << "-------  1�� ����Ų���.  ------" << endl;
	cout << "-------  2�� ����������.  ------" << endl;
	cout << "|||||||||||||||||||||||||||||||||||" << endl;
	cout << endl;

CHOOSE:                                                                   //
	cout << "������Ҫ���ҵķ�ʽ(������ż���): ";
	cin >> cho;
	if (cho != 1 && cho != 2)
	{
		cout << "�����������������룡" << endl;
		goto CHOOSE;
	}

	switch (cho)
	{
	case 1:
		cout << "������Ҫ��ѯ���˻��ı��: ";
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
			cout << "����ʧ�ܣ�û���ҵ��й� " << xh << " ��ŵ��˻���Ϣ��" << endl;
		}
		break;
	case 2:
		int n = 0;
		cout << "������Ҫ��ѯ���˻�������: ";
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
			cout << "�� " << n << " ���� " << mzi << " ���˻�." << endl;
		}
		else if (n == 0)
		{
			cout << "����ʧ�ܣ�û���ҵ��й� " << mzi << " �˻�����Ϣ��" << endl;
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
		cout << "��ǰ�˻���ϢϵͳΪ�գ�����ִ���޸Ĳ�����" << endl << endl;
		return;
	}
	cout << "������Ҫ�޸ĵ��˻��ı��: ";
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

Modify:                                                                                //�����޸� 
	cout << "�Ƿ�ȷ��Ҫ�޸ĸ��˻�����Ϣ(Y / N): ";
	cin >> ch;
	cout << endl;
	if (ch == 'Y' || ch == 'y')
	{
		cout << "�������޸ĺ�ı�ţ��������Ա𣬱��𡢴�ȡ��ɼ�: " << endl;
		cin >> p->next->Data.xh >> p->next->Data.mzi >> p->next->Data.sex >> p->next->Data.ywen >> p->next->Data.sx >> p->next->Data.Withdraw;
		p->next->Data.sum = p->next->Data.ywen + p->next->Data.sx-p->next->Data.Withdraw;
		p->next->Data.ave = p->next->Data.sum / 3.0;
		cout << "�޸ĳɹ���" << endl;
		SaveRecord();
		ShowMessages();
	}
	else if (ch == 'N' || ch == 'n')
	{
		cout << "���˻�����Ϣδ���޸�." << endl;
		return;
	}
	else
	{
		cout << "�����������������룡" << endl;
		goto Modify;
	}
}

void AccountMessages::InsertRecord()
{
	SNode *p = Head;
	int loc, i = 0;
	int m = AccountNumber();

	cout << "������Ҫ�����λ��: ";
	cin >> loc;
	while ((loc < 1) || (loc > m + 1))
	{
		cout << "����λ������" << endl;
		cout << "����������Ҫ�����λ��: ";
		cin >> loc;
	}

	SNode * pNew;
	pNew = new SNode;
	if (pNew == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�" << endl;
		exit(0);
	}
	while ((NULL != p) && (i < loc - 1))
	{
		p = p->next;
		++i;
	}
	cout << "���������˻��ı�ţ��������Ա𣬱��𡢴�ȡ��ɼ�." << endl;
	cin >> pNew->Data.xh >> pNew->Data.mzi >> pNew->Data.sex >> pNew->Data.ywen >> pNew->Data.sx >> pNew->Data.Withdraw;
	pNew->Data.sum = pNew->Data.ywen + pNew->Data.sx - pNew->Data.Withdraw;
	pNew->Data.ave = pNew->Data.sum / 3.0;
	pNew->next = p->next;
	p->next = pNew;
	cout << endl;
	cout << "����ɹ���" << endl;
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
		if (strcmp(p->next->Data.sex, "��") == 0)
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
	

	cout << "ȫ������Ϊ: " << n << " ��" << endl;
	cout << "��: " << s1 << '\t' << "Ů: " << s2 << endl;
	cout << "���������: " << ch << endl;
	cout << "��������: " << ma << endl;
	cout << "ȡ�������: " << en << endl;
	cout << "�����: " << num << endl;
}

void AccountMessages::SortScore()
{
	SNode *p = Head->next;
	SNode *t, *r;
	int n = AccountNumber();
	int i, j;
	int cho;

	cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+++++++++++  1�� ���������.  +++++++++++" << endl;
	cout << "+++++++++++  2�� ���������.  +++++++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;

SORT:                                                                                     //������ 
	cout << "������Ҫ����ķ�ʽ(������ż���): ";
	cin >> cho;
	if (cho != 1 && cho != 2)
	{
		cout << "�����������������룡" << endl;
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

	cout << "����ɹ���" << endl;
	SaveRecord();
	ShowMessages();
}

void AccountMessages::SaveRecord()
{
	SNode *p = Head->next;
	outfile.open("Account1.txt", ios::out);

	if (!outfile)
	{
		cout << "��Ŀ���ļ�ʧ�ܣ�����error ==��" << endl;
		exit(1);
	}

	while (p != NULL)
	{
		outfile << p->Data.xh << '\t' << p->Data.mzi << '\t' << p->Data.sex << '\t' << p->Data.ywen << '\t' << p->Data.sx << '\t' << p->Data.Withdraw << '\t' << p->Data.ave << '\t' << p->Data.sum << '\n';
		p = p->next;
	}
	cout << "����ɹ���" << endl;
	outfile.close();
}

void AccountMessages::QuitSystem()
{
	SaveRecord();
	cout << "���˳���" << endl;
	exit(1);
}

void AccountMessages::OutputSingle(Account &pt)
{
	cout << "���˻���Ϣ���£�" << endl;
	cout << "��ţ�" << pt.xh << endl;
	cout << "������" << pt.mzi << endl;
	cout << "�Ա�" << pt.sex << endl;
	cout << "����" << pt.ywen << endl;
	cout << "��" << pt.sx << endl;
	cout << "ȡ�" << pt.Withdraw << endl;
	cout << "ƽ����" << pt.ave << endl;
	cout << "��" << pt.sum << endl << endl;
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
		cout << "��Դ�ļ�ʧ�ܣ�" << endl;
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
