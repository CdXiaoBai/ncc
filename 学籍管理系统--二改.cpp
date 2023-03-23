#include<iostream>
#include <fstream>
#include<windows.h>
#include <string>
#include<mmSystem.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
#define LEN 50

//ѧ����Ϣ���� 
typedef struct
{
	char id[10];   //ѧ�� 
	char name[50];  //����
	char sex[20];   //�Ա�
	char age[20];        //����
	char BirthPlace[20];    //����
	char YuanXi[20];          //Ժϵ
	char ZhuanYe[20];        //רҵ
	char  BanJi[20];      //�༶
	char xueji[20];//ѧ���仯��Ϣ 
}stu;

//ѧ����Ϣ˳����� 
class stuList
{
private:
	stu data[LEN];  //���ݱ� 
	int length;   //���ݱ��� 
public:
	stuList();   //���캯�� 
	bool Readstu();   //��ȡ�ļ�     =void Student:Readstu()
	void Insert();  //¼��ѧ����Ϣ(�Զ�����)
	void Modify();  //�޸�ѧ����Ϣ
	void Search();  //��ѯѧ����Ϣ
	void Findxj();  //��ѯѧ��ѧ��״̬ 
	void Jiguanbiao();  //���ѧ��������Ϣ
	void Save();       //������Ϣ 
	void Sort();      //ˢ��ѧ����Ϣ 
	void Delect();   //ɾ��ѧ����Ϣ		
	void Display();  //���ѧ����Ϣ;  
};


class Teacher
{
private:
	char Id[10];  //�˺�
	char Name[50];  //����
	char paw[20];  //���� 
public:
	void Regist();	//ע��
	void Login();	//��½	
};


//ע��
void Teacher::Regist()
{
	Teacher   a, b;
	char tmp[20] = { 0 };
	FILE* pf = NULL;
	pf = fopen("teacher.txt", "r");//��pfȥָ���ļ� 
	if (pf == NULL)
	{
		cout << "ע��ʱ���ļ�ʧ��" << endl;
		return;
	}
	cout << "\t\t\t��ӭ����ע�����" << endl << endl;
	cout << "\t\t\t�����˺�->";
	scanf("%s", a.Id);
	while (strlen(a.Id) < 1 || strlen(a.Id) > 10)
	{
		cout << "�����ʽ�������������루�˺ų�����1--10��";
		scanf("%s", a.Id);
	}
	//cout<<strlen(a.Id);
	cout << "����ɹ�!" << endl;

	fread(&b, sizeof(Teacher), 1, pf);
	//���жϡ���û��ע���-�Ƚ��ַ����Ƿ���� 
	//�����->�Ƿ��ļ�β 
	while (1)
	{
		if (strcmp(a.Id, b.Id) != 0)
		{
			if (feof(pf) == 0)//δ���ļ�β 
				fread(&b, sizeof(Teacher), 1, pf);
			else//�����ļ�β��Ȼû����ͬ���ַ���-˵��������˺�ʹ�µ� ����ȥע����� 
			{
				cout << "�˺�δע���������ת��ע�����" << endl;
				system("pause");
			}
			break;//����break����������ѭ�� 
		}
		else
		{
			cout << "���˺���ע���" << endl;
			fclose(pf); pf = NULL;
			return;
		}
	}
	//��ע����桿 
	cout << "\t\t\t�������û���->";
	scanf("%s", a.Name);
	cout << "\t\t\t����������->";
	scanf("%s", a.paw);
	while (strlen(a.paw) < 1 || strlen(a.paw) > 20)
	{
		cout << "�����ʽ�������������루�˺ų�����1--20��";
		scanf("%s", a.paw);
	}
	cout << "\t\t\t��������һ������->";
	do
	{
		scanf("%s", tmp);
		if (strcmp(tmp, a.paw) != 0)
		{
			cout << "\t\t\t�����������벻һ�£���������һ������->";
		}
		else
		{
			break;
		}
	} while (1);
	//��������һ��
	fclose(pf);	pf = NULL;
	pf = fopen("teacher.txt", "a");
	//fwrite���ڵ�ǰ�ļ�ָ���λ��д������
	//"w" �򿪣��ļ�ָ��ָ��ͷ��ֻд��"a" �򿪣�ָ���ļ�β
	fwrite(&a, sizeof(Teacher), 1, pf);
	cout << "\t\t\tע��ɹ�!" << endl;
	fclose(pf);
	pf = NULL;//��ֹҰָ��
	system("cls");
	return;
}

//��¼����
void Teacher::Login()
{
	system("mode con cols=70 lines=20");
	int i;
	char ch[8] = "WELCOME";
	Teacher a, b;
	FILE* pf = fopen("teacher.txt", "r");
	if (pf == NULL)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	cout << "��ӭ������¼����!" << endl;
	cout << "�������˺�->";
	scanf("%s", a.Id);
	fread(&b, sizeof(Teacher), 1, pf);
	while (1)
	{
		if (strcmp(a.Id,b.Id)!= 0)
		{
			if (feof(pf) == 0)//δ���ļ�β 
			{
				fread(&b, sizeof(Teacher), 1, pf);
			}
			else
			{
				cout << "���˺Ų�����,����ע��" << endl;
				fclose(pf); pf = NULL;
				Regist();   //��ת��ע�� 
				return;
			}
		}
		else//�˺�ע���->������������ 
		{
			break; //�˳�����ѭ���������������� 
		}

	}
	//system("pause");
	//���������롿 
	printf("����������->");
	do {
		scanf("%s", a.paw);
		if (strcmp(a.paw, b.paw) != 0)
		{
			cout << "�����������������->";
		}
		else
		{
			break;
		}

	} while ((strcmp(a.paw, b.paw)) != 0);
	cout << "��¼�ɹ�!" << endl;
	fclose(pf);
	pf = NULL;		//��ֹҰָ�� 
	for (i = 1; i <= 100; i++)
	{
		cout << "\n\n\n\n\n\n\n\n\n";
		printf("\t\t\t\t����:%d%", i);
		Sleep(3);				//ͷ�ļ�<windows.h>��ͣ��3����
		system("cls");			//ͷ�ļ�<windows.h>������
	}

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t�������";
	Sleep(666);
	system("cls");

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t";
	for (i = 0; i < 7; i++)
	{
		cout << ch[i];
		Sleep(333);
	}

	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t�밴���������...";
	return;
}


//���캯����ʼ�� 
stuList::stuList()
{
	length = 0;
}

//��ȡѧ����Ϣ 
bool stuList::Readstu()
{
	char name[50];
	char id[20];
	char sex[20];
	char age[20];
	char BirthPlace[21];
	char YuanXi[21];
	char ZhuanYe[21];
	char xueji[21];
	char BanJi[20];
	FILE* fp;
	fp = fopen("stu.txt", "r");
	if (fp == NULL)
	{
		cout << "�ļ�������" << endl;
		exit(1);   //�쳣�˳�
	}
	int i = 0;  //��¼����
	while (!feof(fp))
	{
		fscanf(fp, "%s  %s  %s  %s  %s  %s  %s  %s  %s\n", id, name, sex, age, BirthPlace, YuanXi, ZhuanYe, BanJi, xueji);
		i++;
	}
	fclose(fp);
	FILE* FP;
	FP = fopen("stu.txt", "r");
	if (FP == NULL)
	{
		cout << "�޷����ļ�" << endl;
		exit(1);
	}
	int b = i - 1;
	int j = 0;
	while (!feof(FP))

	{
		fscanf(FP, "%s  %s  %s  %s  %s  %s  %s  %s  %s\n", id, name, sex, age, BirthPlace, YuanXi, ZhuanYe, BanJi, xueji);
		strcpy(data[j].id, id);            //�����ݸ��Ƶ�data 
		strcpy(data[j].name, name);
		strcpy(data[j].sex, sex);
		strcpy(data[j].age, age);
		strcpy(data[j].BirthPlace, BirthPlace);
		strcpy(data[j].YuanXi, YuanXi);
		strcpy(data[j].ZhuanYe, ZhuanYe);
		strcpy(data[j].BanJi, BanJi);
		strcpy(data[j].xueji, xueji);
		if (j == b)
		{
			break;
		}
		j++;
	}
	length = i;     //�õ����ݱ��� 
	return true;; 
}

//���ѧ����Ϣ 
void stuList::Insert()
{
	stu E[LEN];
	int n = 0;
	cout << "������Ҫ��ӵ�ѧ����:";
	cin >> n;
	while (n <= 0 || n > LEN)
	{
		cout << "����������Ҫ��ӵ�ѧ����:";
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		cout << "������ѧ��:" << endl;
		cin >> E[i].id;
		while (j < length)
		{
			if (strcmp(data[j].id, E[i].id) == 0)     //�Ƚ������ѧ�����Ѿ����ڵ�ѧ�� 
			{
				cout << "�����Ѿ����ڣ�����������:";
				cin >> E[i].id;
			}
			j++;
		}
		cout << "����������:" << endl;
		cin >> E[i].name;
		cout << "�������Ա�:" << endl;
		cin >> E[i].sex;
		cout << "����������:" << endl;
		cin >> E[i].age;
		cout << "�����뼮��;" << endl;
		cin >> E[i].BirthPlace;
		cout << "������Ժϵ;" << endl;
		cin >> E[i].YuanXi;
		cout << "������רҵ:" << endl;
		cin >> E[i].ZhuanYe;
		cout << "������༶:" << endl;
		cin >> E[i].BanJi;
		cout << "������ѧ��:" << endl;
		cin >> E[i].xueji;
	}

	int i = 0, j = 0, k = 0;
	for (i = length; i < length + n; i++)
	{
		/*while (j < length)
		{
			int a = atoi(data[j].id);
			int b = atoi(data[k].id);
			if (a == b)
			{
				cout << "ѧ���Ѵ���!";
				break;
			}
			j++;
		}
		j = 0;
		k++;*/
		strcpy(data[i].id, E[j].id);
		strcpy(data[i].name, E[j].name);
		strcpy(data[i].sex, E[j].sex);
		strcpy(data[i].age, E[j].age);
		strcpy(data[i].BirthPlace, E[j].BirthPlace);
		strcpy(data[i].YuanXi, E[j].YuanXi);
		strcpy(data[i].ZhuanYe, E[j].ZhuanYe);
		strcpy(data[i].BanJi, E[j].BanJi);
		strcpy(data[i].xueji, E[j].xueji);
		//j++;
	}
	length = length + n;    //���ݱ��n 
	cout << "�뾡�챣����Ϣ!!";
	system("pause");
}


//����ѧ����Ϣ
void stuList::Search()
{
	char id[10];
	char name[50];
	int i = 0;
	int choose = 0;
	if (length == 0)
	{
		cout << "û�����ݣ��������";
	}
	cout << "������Ҫ��ѯ�ķ�ʽ  1.ѧ��  2.����:" << endl;
	cin >> choose;
	if (choose == 1)
	{
		cout << "������ѧ��:" << endl;
		cin >> id;
		while (strcmp(data[i].id, id) != 0 && i < length)
		{
			i++;
		}
		if (i >= length)
		{
			cout << "����������!" << endl;
		}
		else
		{
			cout << "\t\t\t-----------------------------------------------" << endl;
			cout << "\t\t\t------------------ѧ����ѯ---------------------" << endl;
			cout << "����:" << data[i].name << endl;
			cout << "�Ա�:" << data[i].sex << endl;
			cout << "����:" << data[i].age << endl;
			cout << "����:" << data[i].BirthPlace << endl;
			cout << "Ժϵ:" << data[i].YuanXi << endl;
			cout << "רҵ:" << data[i].ZhuanYe << endl;
			cout << "�༶:" << data[i].BanJi << endl;
			cout << "ѧ��:" << data[i].xueji << endl;
		}
	}
	else if (choose == 2)
	{
		cout << "����������:" << endl;
		cin >> name;
		while (strcmp(data[i].name, name) != 0 && i < length)
		{
			i++;
		}
		if (i >= length)
		{
			cout << "����������!" << endl;
		}
		else
		{
			cout << "\t\t\t-----------------------------------------------" << endl;
			cout << "\t\t\t------------------ѧ����ѯ---------------------" << endl;
			cout << "ѧ��:" << data[i].id << endl;
			cout << "����:" << data[i].name<<endl;
			cout << "�Ա�:" << data[i].sex << endl;
			cout << "����:" << data[i].age << endl;
			cout << "����:" << data[i].BirthPlace << endl;
			cout << "Ժϵ:" << data[i].YuanXi << endl;
			cout << "רҵ:" << data[i].ZhuanYe << endl;
			cout << "�༶:" << data[i].BanJi << endl;
			cout << "ѧ��:" << data[i].xueji << endl;
		}
	}
	else
	{
		cout << "��������ȷ��ѡ��!" << endl;
	}
	system("pause");
}

//������Ϣ 
void stuList::Save()
{
	fstream fp;
	fp.open("stu.txt", ios::out | ios::binary);
	int i = 0;
	char c = 'Y';
	cout << "�Ƿ���б���(Y/N)";
	cin >> c;
	while (c != 'Y'&&c!='y'&&c!='N'&&c!='n')
	{
		cout << "�����������������!" << endl;
		cin >> c;
	}
	if(c=='N'||c=='n')
	{
		return ;
	}
	if (!fp)
	{
		cout << "�ļ�����ʧ��!" << endl;
		exit(1);
	}
	while (i < length)
	{
		fp << data[i].id << "  " << data[i].name << "  " << data[i].sex << "  " << data[i].age << "  "
			<< data[i].BirthPlace << "  " << data[i].YuanXi << "  " << data[i].ZhuanYe << "  "
			<< data[i].BanJi << "  " << data[i].xueji << endl;
		i++;
	}
	cout << "����ɹ�";
	fp.close();
	system("pause");
}

//ɾ��ѧ����Ϣ
void stuList::Delect()
{
	char id[10];
	int i = 0, j = 0;
	int k = 0;  
	k = length;
	cout << "������Ҫɾ��ѧ����ѧ��:" << endl;
	cin >> id;
	while (strcmp(data[i].id, id) != 0 && i < length)
	{
		i++;
	}
	if (i >= length)
	{
		cout << "����������!" << endl;
	}
	
	else
	{
		for (j = i; j < k - 1; j++)  //ɾ���������һ������n-1
		{
			strcpy(data[j].id, data[j + 1].id);
			strcpy(data[j].name, data[j + 1].name);
			strcpy(data[j].sex, data[j + 1].sex);
			strcpy(data[j].age, data[j + 1].age);
			strcpy(data[j].BirthPlace, data[j + 1].BirthPlace);
			strcpy(data[j].YuanXi, data[j + 1].YuanXi);
			strcpy(data[j].ZhuanYe, data[j + 1].ZhuanYe);
			strcpy(data[j].BanJi, data[j + 1].BanJi);
			strcpy(data[j].xueji, data[j + 1].xueji);
		}
		cout << "ɾ���ɹ�" << endl;
	}
	length = length - 1;  //����һ����Ϣ
	system("pause");
}

//�޸�ѧ����Ϣ
void stuList::Modify()
{
	int i = 0;
	if (length == 0);
	{
		cout << "����Ϣ���������";
	}
	char id[10] = { 0 };
	system("cls");
	cout << "\t\t\t*************** �޸���Ϣ ***************" << endl << endl << endl;
	cout << "������Ҫ�޸ĵ�ѧ��ѧ��:";
	cin >> id;
	while (strcmp(data[i].id, id) != 0 && i < length)
	{
		i++;
	}
	if (i >= length)
	{
		cout << "δ�ҵ�����" << endl;
	}
	else
	{
		cout << "-----------------------------------------------" << endl;
		cout << "������Ϣ����:" << endl;
		cout << "ѧ��" << "\t" << "����" << "\t" << "�Ա�" << "\t" << "����" << "\t" << "����" << "\t" << "Ժϵ" << "\t\t"
			<< "רҵ" << "\t" << "�༶" << "\t" << "ѧ��" << endl;
		cout << data[i].id << "\t" << data[i].name << "\t" << data[i].sex << "\t" << data[i].age << "\t" << data[i].BirthPlace << "\t" << data[i].YuanXi << "\t"
			<< data[i].ZhuanYe << "\t" << data[i].BanJi << "\t" << data[i].xueji << endl;
		cout << "��ѡ����Ҫ�޸ĵ�ѡ��   1.����  2.Ժϵ  3.רҵ  4.�༶  5.ѧ��" << endl;
		int input = 0;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "�������޸ĺ�ļ���:" << endl;
			cin >> data[i].BirthPlace;
			break;
		case 2:
			cout << "�������޸ĺ��Ժϵ:" << endl;
			cin >> data[i].YuanXi;
			cout << "�������޸ĺ��רҵ:" << endl;
			cin >> data[i].ZhuanYe;
			break;
		case 3:
			cout << "�������޸ĺ�רҵ:" << endl;
			cin >> data[i].ZhuanYe;
			break;
		case 4:
			cout << "�������޸ĺ�İ༶:" << endl;
			cin >> data[i].BanJi;
			break;
		case 5:
			cout << "�������޸ĺ��ѧ��:" << endl;
			cin >> data[i].xueji;
			break;
		default:
			cout << "��������ȷ��ѡ��!" << endl;
			break;
		}
	}
	system("pause");
}

//�鿴ѧ��״̬
void stuList::Findxj()
{
	char id[10];
	int i = 0;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t----------------------ѧ��---------------------" << endl;
	cout << "������Ҫ����ѧ����ѧ��:";
	cin >> id;
	while (strcmp(data[i].id, id) != 0 && i < length)
	{
		i++;
	}
	if (i == length)  //���������ֵ
	{
		cout << "����������!" << endl;
	}
	else
	{
		cout << "����Ŀǰѧ��״̬Ϊ:";
		cout << data[i].xueji << endl;
	}
	system("pause");
}

//��������
void stuList::Jiguanbiao()
{
	int i = 0;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t---------------------�����--------------------" << endl;
	cout << "\t\t\tѧ��                  ����                    ����\t\t\t" << endl;
	for (i = 0; i < length; i++)
	{
		cout << "\t\t\t" << data[i].id << "                 " << data[i].name << "                    " << data[i].BirthPlace << endl;

	}
	cout << "\t\t\t-----------------------------------------------" << endl;
	system("pause");
}

//��������ð�ݣ�
void stuList::Sort()
{
	char t[100] = { 0 };  //�м��ݴ��ַ�����
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t----------------------����---------------------" << endl;
	int i, j;
	//˫ѭ��
	for (i = 0; i < (length - 1); i++)
	{
		for (j = 0; j < (length - 1); j++)
		{
			int m, n;
			m = atoi(data[j].id);        //ǿ��ת��Ϊint�����бȽ� 
			n = atoi(data[j + 1].id);
			if (m < n)
			{
				//����ѧ��
				strcpy(t, data[j + 1].id);
				strcpy(data[j + 1].id, data[j].id);
				strcpy(data[j].id, t);
				//��������
				strcpy(t, data[j + 1].name);
				strcpy(data[j + 1].name, data[j].name);
				strcpy(data[j].name, t);
				//�����Ա�
				strcpy(t, data[j + 1].sex);
				strcpy(data[j + 1].sex, data[j].sex);
				strcpy(data[j].sex, t);
				//�������� 
				strcpy(t, data[j + 1].age);
				strcpy(data[j + 1].age, data[j].age);
				strcpy(data[j].age, t);
				//��������
				strcpy(t, data[j + 1].BirthPlace);
				strcpy(data[j + 1].BirthPlace, data[j].BirthPlace);
				strcpy(data[j].BirthPlace, t);
				//����Ժϵ
				strcpy(t, data[j + 1].YuanXi);
				strcpy(data[j + 1].YuanXi, data[j].YuanXi);
				strcpy(data[j].YuanXi, t);
				//����רҵ
				strcpy(t, data[j + 1].ZhuanYe);
				strcpy(data[j + 1].ZhuanYe, data[j].ZhuanYe);
				strcpy(data[j].ZhuanYe, t);
				//�����༶
				strcpy(t, data[j + 1].BanJi);
				strcpy(data[j + 1].BanJi, data[j].BanJi);
				strcpy(data[j].BanJi, t);
				//����ѧ��
				strcpy(t, data[j + 1].xueji);
				strcpy(data[j + 1].xueji, data[j].xueji);
				strcpy(data[j].xueji, t);
			}
		}
	}
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "������Ϣ����:" << endl;
	cout << "ѧ��" << "\t" << "����" << "\t" << "�Ա�" << "\t" << "����" << "\t" << "����" << "\t" << "Ժϵ" << "\t\t"
		<< "רҵ" << "\t" << "�༶" << "\t" << "ѧ��" << endl;
	cout << "\t\t\t-----------------------------------------------" << endl;
	for (i = 0; i < length; i++)
	{
		cout << data[i].id << "\t" << data[i].name << "\t" << data[i].sex << "\t" << data[i].age << "\t"
			<< data[i].BirthPlace << "\t" << data[i].YuanXi << "\t" << data[i].ZhuanYe << "\t" << data[i].BanJi
			<< "\t" << data[i].xueji << endl;
	}
	Save();
	system("pause");
}

//�����Ϣ 
void stuList::Display()
{
	int i;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t----------------------���---------------------" << endl;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "ѧ��" << "\t" << "����" << "\t" << "�Ա�" << "\t" << "����" << "\t" << "����" << "\t" << "Ժϵ" << "\t"
		<< "\t" << "רҵ" << "\t" << "�༶" << "\t" << "ѧ��" << endl;
	cout << "\t\t\t-----------------------------------------------" << endl;

	for (i = 0; i < length; i++)
	{
		cout << data[i].id << "\t" << data[i].name << "\t" << data[i].sex << "\t" << data[i].age << "\t"
			<< data[i].BirthPlace << "\t" << data[i].YuanXi << "\t" << data[i].ZhuanYe << "\t" << data[i].BanJi
			<< "\t" << data[i].xueji << endl;
	}
	cout << "\t\t\t-----------------------------------------------" << endl;
	system("pause");
}

//��ʦ��¼���� 
void Teachershow()
{
     Teacher A;
	int input = -1, n = 10;
	do
	{
		cout << "\t\t\t----------------------------------" << endl;
		cout << "\t\t\t|           1.��¼               |" << endl;
		cout << "\t\t\t|           2.ע��               |" << endl;
		cout << "\t\t\t|           0.�˳�               |" << endl;
		cout << "\t\t\t----------------------------------" << endl;
		cout << "��ѡ����->";
		cin >> input;
		n = input;
		switch (input)
		{
		case 1:A.Login(),
			n = 0;;
			break;
		case 2:A.Regist(),
			n = 0;;
			break;
		case 0:puts("�˳��ɹ�"),
			exit(0);
			system("cls");
		}
	} while (n);

}


//��ʼ����
void zhu()
{
	int num = 0;
	int m;
	do
	{
		cout << "\t\t\t----------------------------------" << endl;
		cout << "\t\t\t|           1.��ʦ               |" << endl;
		cout << "\t\t\t|           0.�˳�ϵͳ           |" << endl;
		cout << "\t\t\t----------------------------------" << endl;
		cin >> m;
		switch (m)
		{
		case 1: Teachershow();
			m = 0;;
			break;
		case 0: cout << "�˳��ɹ�";
			exit(0);
		}
	} while (m);
	return;
}


int main()
{
	int select = 0;
	stuList L;  //ѧ����Ϣ�� 
	stu E[LEN]; //ѧ���� 
	L.Readstu();
	system("title ѧ������ϵͳ----������");
	system("color 79");		//Windowsͷ�ļ�(��ɫ) 
	mciSendString(TEXT("open �̻�.mp3 alias m1"), NULL, 0, NULL);
	mciSendString("play m1",NULL,0,NULL); 
	mciSendString("setaudio m1 volume to 150", NULL, 0, NULL);
	zhu();
	while (1)
	{
		system("mode con cols=100 lines=45");
		cout << endl;
		cout << "\t\t����������������������������������������������������\t\t" << endl;
		cout << "\t\t*************��ӭʹ��ѧ��ѧ������ϵͳ***************\t\t" << endl;
		cout << "\t\t*                                                  *\t\t" << endl;
		cout << "\t\t********************ϵͳ���ܲ˵�********************\t\t" << endl;
		cout << "\t\t*                                                  *\t\t" << endl;
		cout << "\t\t*                 0.ˢ��ѧ����Ϣ                   *\t\t" << endl;
		cout << "\t\t*                 1.���ѧ����Ϣ                   *\t\t" << endl;
		cout << "\t\t*                 2.�޸�ѧ����Ϣ                   *\t\t" << endl;
		cout << "\t\t*                 3.ɾ��ѧ����Ϣ                   *\t\t" << endl;
		cout << "\t\t*                 4.����ѧ����Ϣ                   *\t\t" << endl;
		cout << "\t\t*                 5.���ѧ�������                 *\t\t" << endl;
		cout << "\t\t*                 6.�鿴ѧ��ѧ���仯               *\t\t" << endl;
		cout << "\t\t*                 7.�鿴������Ϣ                   *\t\t" << endl;
		cout << "\t\t*                 8.��ͣ����                       *\t\t" << endl;
		cout << "\t\t*                 9.�˳�ϵͳ                       *\t\t" << endl;
		cout << "\t\t*                 10.������Ϣ                      *\t\t" << endl;
		cout << "\t\t*                 11.��������                      *\t\t" << endl;
		cout << "\t\t����������������������������������������������������\t\t" << endl;

		cout << " ������Ҫѡ��Ĺ���ѡ��:";
		cin >> select;
		switch (select)
		{
		case 0:
			L.Sort();
			break;
		case 1:
			L.Insert();
			break;
		case 2:
			L.Modify();
			break;
		case 3:
			L.Delect();
			break;
		case 4:
			L.Search();
			break;
		case 5:
			L.Jiguanbiao();
			break;
		case 6:
			L.Findxj();
			break;
		case 7:
			L.Display();
			break;
		case 8:
			mciSendString("pause m1", 0, 0, 0);
			break;
		case 9:
			cout << "�˳���ѯ�ɹ�!" << endl;
			exit(0);
			break;
		case 10:
			L.Save();
			break;
		case 11:
			mciSendString("resume m1", 0, 0, 0);
			break;
		}
		system("cls");
	}
}
