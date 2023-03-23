#include<iostream>
#include <fstream>
#include<windows.h>
#include <string>
#include<mmSystem.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
#define LEN 50

//学生信息类型 
typedef struct
{
	char id[10];   //学号 
	char name[50];  //姓名
	char sex[20];   //性别
	char age[20];        //年龄
	char BirthPlace[20];    //籍贯
	char YuanXi[20];          //院系
	char ZhuanYe[20];        //专业
	char  BanJi[20];      //班级
	char xueji[20];//学籍变化信息 
}stu;

//学生信息顺序表类 
class stuList
{
private:
	stu data[LEN];  //数据表 
	int length;   //数据表长度 
public:
	stuList();   //构造函数 
	bool Readstu();   //读取文件     =void Student:Readstu()
	void Insert();  //录入学生信息(自动保存)
	void Modify();  //修改学生信息
	void Search();  //查询学生信息
	void Findxj();  //查询学生学籍状态 
	void Jiguanbiao();  //输出学生籍贯信息
	void Save();       //保存信息 
	void Sort();      //刷新学生信息 
	void Delect();   //删除学生信息		
	void Display();  //输出学生信息;  
};


class Teacher
{
private:
	char Id[10];  //账号
	char Name[50];  //姓名
	char paw[20];  //密码 
public:
	void Regist();	//注册
	void Login();	//登陆	
};


//注册
void Teacher::Regist()
{
	Teacher   a, b;
	char tmp[20] = { 0 };
	FILE* pf = NULL;
	pf = fopen("teacher.txt", "r");//用pf去指向文件 
	if (pf == NULL)
	{
		cout << "注册时打开文件失败" << endl;
		return;
	}
	cout << "\t\t\t欢迎来到注册界面" << endl << endl;
	cout << "\t\t\t输入账号->";
	scanf("%s", a.Id);
	while (strlen(a.Id) < 1 || strlen(a.Id) > 10)
	{
		cout << "输入格式错误，请重新输入（账号长度在1--10）";
		scanf("%s", a.Id);
	}
	//cout<<strlen(a.Id);
	cout << "输入成功!" << endl;

	fread(&b, sizeof(Teacher), 1, pf);
	//【判断】有没有注册过-比较字符串是否相等 
	//不相等->是否到文件尾 
	while (1)
	{
		if (strcmp(a.Id, b.Id) != 0)
		{
			if (feof(pf) == 0)//未到文件尾 
				fread(&b, sizeof(Teacher), 1, pf);
			else//到了文件尾仍然没有相同的字符串-说明输入的账号使新的 可以去注册界面 
			{
				cout << "账号未注册过，将跳转到注册界面" << endl;
				system("pause");
			}
			break;//利用break来跳出无限循环 
		}
		else
		{
			cout << "该账号已注册过" << endl;
			fclose(pf); pf = NULL;
			return;
		}
	}
	//【注册界面】 
	cout << "\t\t\t请输入用户名->";
	scanf("%s", a.Name);
	cout << "\t\t\t请输入密码->";
	scanf("%s", a.paw);
	while (strlen(a.paw) < 1 || strlen(a.paw) > 20)
	{
		cout << "输入格式错误，请重新输入（账号长度在1--20）";
		scanf("%s", a.paw);
	}
	cout << "\t\t\t请再输入一次密码->";
	do
	{
		scanf("%s", tmp);
		if (strcmp(tmp, a.paw) != 0)
		{
			cout << "\t\t\t两次输入密码不一致，请再输入一次密码->";
		}
		else
		{
			break;
		}
	} while (1);
	//两次密码一致
	fclose(pf);	pf = NULL;
	pf = fopen("teacher.txt", "a");
	//fwrite会在当前文件指针的位置写入数据
	//"w" 打开，文件指针指到头，只写；"a" 打开，指向文件尾
	fwrite(&a, sizeof(Teacher), 1, pf);
	cout << "\t\t\t注册成功!" << endl;
	fclose(pf);
	pf = NULL;//防止野指针
	system("cls");
	return;
}

//登录界面
void Teacher::Login()
{
	system("mode con cols=70 lines=20");
	int i;
	char ch[8] = "WELCOME";
	Teacher a, b;
	FILE* pf = fopen("teacher.txt", "r");
	if (pf == NULL)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	cout << "欢迎来到登录界面!" << endl;
	cout << "请输入账号->";
	scanf("%s", a.Id);
	fread(&b, sizeof(Teacher), 1, pf);
	while (1)
	{
		if (strcmp(a.Id,b.Id)!= 0)
		{
			if (feof(pf) == 0)//未到文件尾 
			{
				fread(&b, sizeof(Teacher), 1, pf);
			}
			else
			{
				cout << "该账号不存在,请先注册" << endl;
				fclose(pf); pf = NULL;
				Regist();   //跳转到注册 
				return;
			}
		}
		else//账号注册过->跳到输入密码 
		{
			break; //退出无限循环，跳到输入密码 
		}

	}
	//system("pause");
	//【输入密码】 
	printf("请输入密码->");
	do {
		scanf("%s", a.paw);
		if (strcmp(a.paw, b.paw) != 0)
		{
			cout << "密码错误，请重新输入->";
		}
		else
		{
			break;
		}

	} while ((strcmp(a.paw, b.paw)) != 0);
	cout << "登录成功!" << endl;
	fclose(pf);
	pf = NULL;		//防止野指针 
	for (i = 1; i <= 100; i++)
	{
		cout << "\n\n\n\n\n\n\n\n\n";
		printf("\t\t\t\t加载:%d%", i);
		Sleep(3);				//头文件<windows.h>，停顿3毫秒
		system("cls");			//头文件<windows.h>，清屏
	}

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t加载完毕";
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
	cout << "\t\t\t\t\t\t\t请按任意键继续...";
	return;
}


//构造函数初始化 
stuList::stuList()
{
	length = 0;
}

//读取学生信息 
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
		cout << "文件不存在" << endl;
		exit(1);   //异常退出
	}
	int i = 0;  //记录行数
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
		cout << "无法打开文件" << endl;
		exit(1);
	}
	int b = i - 1;
	int j = 0;
	while (!feof(FP))

	{
		fscanf(FP, "%s  %s  %s  %s  %s  %s  %s  %s  %s\n", id, name, sex, age, BirthPlace, YuanXi, ZhuanYe, BanJi, xueji);
		strcpy(data[j].id, id);            //把数据复制到data 
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
	length = i;     //得到数据表长度 
	return true;; 
}

//添加学生信息 
void stuList::Insert()
{
	stu E[LEN];
	int n = 0;
	cout << "请输入要添加的学生数:";
	cin >> n;
	while (n <= 0 || n > LEN)
	{
		cout << "请重新输入要添加的学生数:";
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		cout << "请输入学号:" << endl;
		cin >> E[i].id;
		while (j < length)
		{
			if (strcmp(data[j].id, E[i].id) == 0)     //比较输入的学号与已经存在的学号 
			{
				cout << "该生已经存在，请重新输入:";
				cin >> E[i].id;
			}
			j++;
		}
		cout << "请输入姓名:" << endl;
		cin >> E[i].name;
		cout << "请输入性别:" << endl;
		cin >> E[i].sex;
		cout << "请输入年龄:" << endl;
		cin >> E[i].age;
		cout << "请输入籍贯;" << endl;
		cin >> E[i].BirthPlace;
		cout << "请输入院系;" << endl;
		cin >> E[i].YuanXi;
		cout << "请输入专业:" << endl;
		cin >> E[i].ZhuanYe;
		cout << "请输入班级:" << endl;
		cin >> E[i].BanJi;
		cout << "请输入学籍:" << endl;
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
				cout << "学生已存在!";
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
	length = length + n;    //数据表加n 
	cout << "请尽快保存信息!!";
	system("pause");
}


//查找学生信息
void stuList::Search()
{
	char id[10];
	char name[50];
	int i = 0;
	int choose = 0;
	if (length == 0)
	{
		cout << "没有数据，请先添加";
	}
	cout << "请输入要查询的方式  1.学号  2.姓名:" << endl;
	cin >> choose;
	if (choose == 1)
	{
		cout << "请输入学号:" << endl;
		cin >> id;
		while (strcmp(data[i].id, id) != 0 && i < length)
		{
			i++;
		}
		if (i >= length)
		{
			cout << "该生不存在!" << endl;
		}
		else
		{
			cout << "\t\t\t-----------------------------------------------" << endl;
			cout << "\t\t\t------------------学生查询---------------------" << endl;
			cout << "姓名:" << data[i].name << endl;
			cout << "性别:" << data[i].sex << endl;
			cout << "年龄:" << data[i].age << endl;
			cout << "籍贯:" << data[i].BirthPlace << endl;
			cout << "院系:" << data[i].YuanXi << endl;
			cout << "专业:" << data[i].ZhuanYe << endl;
			cout << "班级:" << data[i].BanJi << endl;
			cout << "学籍:" << data[i].xueji << endl;
		}
	}
	else if (choose == 2)
	{
		cout << "请输入姓名:" << endl;
		cin >> name;
		while (strcmp(data[i].name, name) != 0 && i < length)
		{
			i++;
		}
		if (i >= length)
		{
			cout << "该生不存在!" << endl;
		}
		else
		{
			cout << "\t\t\t-----------------------------------------------" << endl;
			cout << "\t\t\t------------------学生查询---------------------" << endl;
			cout << "学号:" << data[i].id << endl;
			cout << "姓名:" << data[i].name<<endl;
			cout << "性别:" << data[i].sex << endl;
			cout << "年龄:" << data[i].age << endl;
			cout << "籍贯:" << data[i].BirthPlace << endl;
			cout << "院系:" << data[i].YuanXi << endl;
			cout << "专业:" << data[i].ZhuanYe << endl;
			cout << "班级:" << data[i].BanJi << endl;
			cout << "学籍:" << data[i].xueji << endl;
		}
	}
	else
	{
		cout << "请输入正确的选项!" << endl;
	}
	system("pause");
}

//保存信息 
void stuList::Save()
{
	fstream fp;
	fp.open("stu.txt", ios::out | ios::binary);
	int i = 0;
	char c = 'Y';
	cout << "是否进行保存(Y/N)";
	cin >> c;
	while (c != 'Y'&&c!='y'&&c!='N'&&c!='n')
	{
		cout << "输入错误，请重新输入!" << endl;
		cin >> c;
	}
	if(c=='N'||c=='n')
	{
		return ;
	}
	if (!fp)
	{
		cout << "文件创建失败!" << endl;
		exit(1);
	}
	while (i < length)
	{
		fp << data[i].id << "  " << data[i].name << "  " << data[i].sex << "  " << data[i].age << "  "
			<< data[i].BirthPlace << "  " << data[i].YuanXi << "  " << data[i].ZhuanYe << "  "
			<< data[i].BanJi << "  " << data[i].xueji << endl;
		i++;
	}
	cout << "保存成功";
	fp.close();
	system("pause");
}

//删除学生信息
void stuList::Delect()
{
	char id[10];
	int i = 0, j = 0;
	int k = 0;  
	k = length;
	cout << "请输入要删除学生的学号:" << endl;
	cin >> id;
	while (strcmp(data[i].id, id) != 0 && i < length)
	{
		i++;
	}
	if (i >= length)
	{
		cout << "该生不存在!" << endl;
	}
	
	else
	{
		for (j = i; j < k - 1; j++)  //删除后个数少一，所以n-1
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
		cout << "删除成功" << endl;
	}
	length = length - 1;  //减少一组信息
	system("pause");
}

//修改学生信息
void stuList::Modify()
{
	int i = 0;
	if (length == 0);
	{
		cout << "无信息，请先添加";
	}
	char id[10] = { 0 };
	system("cls");
	cout << "\t\t\t*************** 修改信息 ***************" << endl << endl << endl;
	cout << "请输入要修改的学生学号:";
	cin >> id;
	while (strcmp(data[i].id, id) != 0 && i < length)
	{
		i++;
	}
	if (i >= length)
	{
		cout << "未找到该生" << endl;
	}
	else
	{
		cout << "-----------------------------------------------" << endl;
		cout << "该生信息如下:" << endl;
		cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t" << "年龄" << "\t" << "籍贯" << "\t" << "院系" << "\t\t"
			<< "专业" << "\t" << "班级" << "\t" << "学籍" << endl;
		cout << data[i].id << "\t" << data[i].name << "\t" << data[i].sex << "\t" << data[i].age << "\t" << data[i].BirthPlace << "\t" << data[i].YuanXi << "\t"
			<< data[i].ZhuanYe << "\t" << data[i].BanJi << "\t" << data[i].xueji << endl;
		cout << "请选择你要修改的选项   1.籍贯  2.院系  3.专业  4.班级  5.学籍" << endl;
		int input = 0;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "请输入修改后的籍贯:" << endl;
			cin >> data[i].BirthPlace;
			break;
		case 2:
			cout << "请输入修改后的院系:" << endl;
			cin >> data[i].YuanXi;
			cout << "请输入修改后的专业:" << endl;
			cin >> data[i].ZhuanYe;
			break;
		case 3:
			cout << "请输入修改后专业:" << endl;
			cin >> data[i].ZhuanYe;
			break;
		case 4:
			cout << "请输入修改后的班级:" << endl;
			cin >> data[i].BanJi;
			break;
		case 5:
			cout << "请输入修改后的学籍:" << endl;
			cin >> data[i].xueji;
			break;
		default:
			cout << "请输入正确的选项!" << endl;
			break;
		}
	}
	system("pause");
}

//查看学籍状态
void stuList::Findxj()
{
	char id[10];
	int i = 0;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t----------------------学籍---------------------" << endl;
	cout << "请输入要查找学生的学号:";
	cin >> id;
	while (strcmp(data[i].id, id) != 0 && i < length)
	{
		i++;
	}
	if (i == length)  //大于了最大值
	{
		cout << "该生不存在!" << endl;
	}
	else
	{
		cout << "该生目前学籍状态为:";
		cout << data[i].xueji << endl;
	}
	system("pause");
}

//输出籍贯表
void stuList::Jiguanbiao()
{
	int i = 0;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t---------------------籍贯表--------------------" << endl;
	cout << "\t\t\t学号                  姓名                    籍贯\t\t\t" << endl;
	for (i = 0; i < length; i++)
	{
		cout << "\t\t\t" << data[i].id << "                 " << data[i].name << "                    " << data[i].BirthPlace << endl;

	}
	cout << "\t\t\t-----------------------------------------------" << endl;
	system("pause");
}

//降序排序（冒泡）
void stuList::Sort()
{
	char t[100] = { 0 };  //中间暂存字符数组
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t----------------------排序---------------------" << endl;
	int i, j;
	//双循环
	for (i = 0; i < (length - 1); i++)
	{
		for (j = 0; j < (length - 1); j++)
		{
			int m, n;
			m = atoi(data[j].id);        //强制转换为int，进行比较 
			n = atoi(data[j + 1].id);
			if (m < n)
			{
				//交换学号
				strcpy(t, data[j + 1].id);
				strcpy(data[j + 1].id, data[j].id);
				strcpy(data[j].id, t);
				//交换姓名
				strcpy(t, data[j + 1].name);
				strcpy(data[j + 1].name, data[j].name);
				strcpy(data[j].name, t);
				//交换性别
				strcpy(t, data[j + 1].sex);
				strcpy(data[j + 1].sex, data[j].sex);
				strcpy(data[j].sex, t);
				//交换年龄 
				strcpy(t, data[j + 1].age);
				strcpy(data[j + 1].age, data[j].age);
				strcpy(data[j].age, t);
				//交换籍贯
				strcpy(t, data[j + 1].BirthPlace);
				strcpy(data[j + 1].BirthPlace, data[j].BirthPlace);
				strcpy(data[j].BirthPlace, t);
				//交换院系
				strcpy(t, data[j + 1].YuanXi);
				strcpy(data[j + 1].YuanXi, data[j].YuanXi);
				strcpy(data[j].YuanXi, t);
				//交换专业
				strcpy(t, data[j + 1].ZhuanYe);
				strcpy(data[j + 1].ZhuanYe, data[j].ZhuanYe);
				strcpy(data[j].ZhuanYe, t);
				//交换班级
				strcpy(t, data[j + 1].BanJi);
				strcpy(data[j + 1].BanJi, data[j].BanJi);
				strcpy(data[j].BanJi, t);
				//交换学籍
				strcpy(t, data[j + 1].xueji);
				strcpy(data[j + 1].xueji, data[j].xueji);
				strcpy(data[j].xueji, t);
			}
		}
	}
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "该生信息如下:" << endl;
	cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t" << "年龄" << "\t" << "籍贯" << "\t" << "院系" << "\t\t"
		<< "专业" << "\t" << "班级" << "\t" << "学籍" << endl;
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

//输出信息 
void stuList::Display()
{
	int i;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t----------------------输出---------------------" << endl;
	cout << "\t\t\t-----------------------------------------------" << endl;
	cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t" << "年龄" << "\t" << "籍贯" << "\t" << "院系" << "\t"
		<< "\t" << "专业" << "\t" << "班级" << "\t" << "学籍" << endl;
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

//教师登录界面 
void Teachershow()
{
     Teacher A;
	int input = -1, n = 10;
	do
	{
		cout << "\t\t\t----------------------------------" << endl;
		cout << "\t\t\t|           1.登录               |" << endl;
		cout << "\t\t\t|           2.注册               |" << endl;
		cout << "\t\t\t|           0.退出               |" << endl;
		cout << "\t\t\t----------------------------------" << endl;
		cout << "请选择功能->";
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
		case 0:puts("退出成功"),
			exit(0);
			system("cls");
		}
	} while (n);

}


//初始界面
void zhu()
{
	int num = 0;
	int m;
	do
	{
		cout << "\t\t\t----------------------------------" << endl;
		cout << "\t\t\t|           1.老师               |" << endl;
		cout << "\t\t\t|           0.退出系统           |" << endl;
		cout << "\t\t\t----------------------------------" << endl;
		cin >> m;
		switch (m)
		{
		case 1: Teachershow();
			m = 0;;
			break;
		case 0: cout << "退出成功";
			exit(0);
		}
	} while (m);
	return;
}


int main()
{
	int select = 0;
	stuList L;  //学生信息表 
	stu E[LEN]; //学生数 
	L.Readstu();
	system("title 学籍管理系统----马渝钦");
	system("color 79");		//Windows头文件(颜色) 
	mciSendString(TEXT("open 烟火.mp3 alias m1"), NULL, 0, NULL);
	mciSendString("play m1",NULL,0,NULL); 
	mciSendString("setaudio m1 volume to 150", NULL, 0, NULL);
	zhu();
	while (1)
	{
		system("mode con cols=100 lines=45");
		cout << endl;
		cout << "\t\t——————————————————————————\t\t" << endl;
		cout << "\t\t*************欢迎使用学生学籍管理系统***************\t\t" << endl;
		cout << "\t\t*                                                  *\t\t" << endl;
		cout << "\t\t********************系统功能菜单********************\t\t" << endl;
		cout << "\t\t*                                                  *\t\t" << endl;
		cout << "\t\t*                 0.刷新学生信息                   *\t\t" << endl;
		cout << "\t\t*                 1.添加学生信息                   *\t\t" << endl;
		cout << "\t\t*                 2.修改学生信息                   *\t\t" << endl;
		cout << "\t\t*                 3.删除学生信息                   *\t\t" << endl;
		cout << "\t\t*                 4.查找学生信息                   *\t\t" << endl;
		cout << "\t\t*                 5.输出学生籍贯表                 *\t\t" << endl;
		cout << "\t\t*                 6.查看学生学籍变化               *\t\t" << endl;
		cout << "\t\t*                 7.查看所有信息                   *\t\t" << endl;
		cout << "\t\t*                 8.暂停音乐                       *\t\t" << endl;
		cout << "\t\t*                 9.退出系统                       *\t\t" << endl;
		cout << "\t\t*                 10.保存信息                      *\t\t" << endl;
		cout << "\t\t*                 11.继续播放                      *\t\t" << endl;
		cout << "\t\t——————————————————————————\t\t" << endl;

		cout << " 请输入要选择的功能选项:";
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
			cout << "退出查询成功!" << endl;
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
