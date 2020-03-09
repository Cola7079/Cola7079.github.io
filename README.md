# Cola7079.github.io
Cola7079的个人博客

# 一直咕咕咕的猜数字终于开源啦！

#include<iostream>
#include<algorithm>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include<fstream>
#include<cmath>
#include<Windows.h>
using namespace std;
struct phb {
	int jl;
	string sing;
	int second;
	int year, month, day;
};
int a[10], passstep, shuru;
char huxke[20][10];
bool jiance = false, ltf = true, f[15], pass, colour;
//string username, password;
phb phbjl[10];
void SetPos(COORD a)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}
void SetPos(int i, int j)
{
	COORD pos = { i, j };
	SetPos(pos);
}
void getSystemTime(int x)
{
	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);

	phbjl[x].year = t_tm->tm_year + 1900;
	phbjl[x].month = t_tm->tm_mon + 1;
	phbjl[x].day = t_tm->tm_mday;
}
void load() {
	ifstream fin("data.txt");
	int jianche;
	fin >> jianche;
	if (jianche) {
		jiance = true;
		/*
		fin >> username >> password;
		passstep=password.length();
		*/
		int locor1, locor2;
		fin >> locor1 >> locor2;
		if (locor1) {
			ltf = true;
			if (locor2) {
				colour = true;
			}
			else {
				colour = false;
			}
		}
		else {
			ltf = false;
			if (locor2) {
				colour = true;
			}
			else {
				colour = false;
			}
		}
		for (int i = 1; i <= 5; i++) {
			fin >> phbjl[i].jl >> phbjl[i].sing >> phbjl[i].second >> phbjl[i].year >> phbjl[i].month >> phbjl[i].day;
		}
	}
	else {
		jiance = false;
	}
	fin.close();
}
void save() {
	ofstream fout("data.txt");
	fout << jiance << endl;
	if (jiance) {
		/*
		fout << username << " ";
		for(int i=0;i<passstep;i++)
		{
			fout<<password[i];
		}
		fout<<endl;
		*/
		fout << ltf << " " << colour << endl;
		for (int i = 1; i <= 5; i++) {
			fout << phbjl[i].jl << " " << phbjl[i].sing << " " << phbjl[i].second << " " << phbjl[i].year << " " << phbjl[i].month << " " << phbjl[i].day << endl;
		}
	}
	fout.close();
}
/*
void save(void){
	cout<<"保存进度中……   ";
	//guessnumber_node*p=NULL;
	char* str = new char[20];
	memset(str,0,20);
	sprintf(str,"%d",phbjl[1].jl);
	ofstream sm("phbjljl1.txt");
	if (!sm)
	{
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm.write(str,strlen(str));
	}
	delete str;
	char* str = new char[20];
	memset(str,0,20);
	sprintf(str,"%d",phbjl[2].jl);
	ofstream sm("phbjljl2.txt");
	if (!sm)
	{
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm.write(str,strlen(str));
	}
	delete str;
	char* str = new char[20];
	memset(str,0,20);
	sprintf(str,"%d",phbjl[3].jl);
	ofstream sm("phbjljl3.txt");
	if (!sm)
	{
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm.write(str,strlen(str));
	}
	delete str;
	char* str = new char[20];
	memset(str,0,20);
	sprintf(str,"%d",phbjl[4].jl);
	ofstream sm("phbjljl4.txt");
	if (!sm)
	{
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm.write(str,strlen(str));
	}
	delete str;
	char* str = new char[20];
	memset(str,0,20);
	sprintf(str,"%d",phbjl[5].jl);
	ofstream sm("phbjljl5.txt");
	if (!sm)
	{
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm.write(str,strlen(str));
	}
	delete str;
	/*
	FILE* mem;
	if((mem=fopen("memory.txt","w+"))==NULL){
		cout<<"存档失败！"<<endl;
		return 0;
	}
	for(int i=1;i<=5;i++){
		int length=phbjl[i].sing.length();
		fwrite(&phbjl[i].jl,sizeof(phbjl[i].jl),1,mem);
		fwrite(&length,sizeof(length),1,mem);
		for(int j=0;j<phbjl[i].sing.length();j++){
			int phbjlz=phbjl[i].sing[j]-'0';
			fwrite(&phbjlz,sizeof(phbjlz),1,mem);
		}
	}
	fclose(mem);
	*/
	/*
	system("cls");
	cout<<"完成！"<<endl;
	}
	void load(void){
	cout<<"读取进度中……   ";
	//guessnumber_node*p,*q;
	int m=1,i,j;
	FILE* mem;
	if((mem=fopen("memory.txt","r"))==NULL){
		cout<<"完成！"<<endl;
		exit(0);
	}
	for(int i=1;i<=5;i++){
		int length=phbjl[i].sing.length();
		fread(&phbjl[i].jl,sizeof(phbjl[i].jl),1,mem);
		fread(&length,sizeof(length),1,mem);
		for(int j=0;j<phbjl[i].sing.length();j++){
			int phbjlz=phbjl[i].sing[j]-'0';
			fread(&phbjlz,sizeof(phbjlz),1,mem);
		}
	}
	fclose(mem);
	cout<<"完成！"<<endl;
	}
	void load(void);
	char* str = new char[100005];
	int read(){

		cout<<"保存进度中……";
	//guessnumber_node*p=NULL;
	memset(str,0,100005);
	sprintf(str,"%d",phbjl[1].jl);
	ofstream sm("phbjljl1.txt");
	if (!sm)
	{
		system("cls");
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm.write(str,strlen(str));
	}
	delete str;
	memset(str,0,100005);
	sprintf(str,"%d",phbjl[2].jl);
	ofstream sm2("phbjljl2.txt");
	if (!sm)
	{
		system("cls");
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm2.write(str,strlen(str));
	}
	delete str;
	memset(str,0,100005);
	sprintf(str,"%d",phbjl[3].jl);
	ofstream sm3("phbjljl3.txt");
	if (!sm)
	{
		system("cls");
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm3.write(str,strlen(str));
	}
	delete str;
	memset(str,0,100005);
	sprintf(str,"%d",phbjl[4].jl);
	ofstream sm4("phbjljl4.txt");
	if (!sm)
	{
		system("cls");
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm4.write(str,strlen(str));
	}
	delete str;
	memset(str,0,100005);
	sprintf(str,"%d",phbjl[5].jl);
	ofstream sm5("phbjljl5.txt");
	if (!sm)
	{
		system("cls");
		cout << "保存进度失败！" << endl;
		return 0;
	}
	else
	{
		sm5.write(str,strlen(str));
	}
	delete str;
	FILE *fp = NULL;  //声明并初始化文件指针
	char str[100] = "123456";  //声明并赋值str字符串数组变量
	fp = fopen("phbjlsing1.txt","w"); //只读方式打开文件
	fputs(str,fp);   // 写入str内容
	fclose(fp);     //关闭文件
	/*
	FILE* mem;
	if((mem=fopen("memory.txt","w+"))==NULL){
		cout<<"存档失败！"<<endl;
		return 0;
	}
	for(int i=1;i<=5;i++){
		int length=phbjl[i].sing.length();
		fwrite(&phbjl[i].jl,sizeof(phbjl[i].jl),1,mem);
		fwrite(&length,sizeof(length),1,mem);
		for(int j=0;j<phbjl[i].sing.length();j++){
			int phbjlz=phbjl[i].sing[j]-'0';
			fwrite(&phbjlz,sizeof(phbjlz),1,mem);
		}
	}
	fclose(mem);
	system("cls");
	cout<<"完成！"<<endl;
	return 0;
	}
	*/
	/*
void create()
{
	bool isRight=true;
	system("cls");
	int step1 = 0, step2 = 0;
	if (!ltf)
	{
		cout << "Please create an Infer account:" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		char tu;
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				password[step1] = tu;
				step1++;
				cout << "*";
			}
			else
			{
				password[step1] = '\0';
				break;
			}
		}
		cout << endl;
		string passwordche;
		cout << "Repeat passowrd: ";
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				passwordche[step2] = tu;
				step2++;
				cout << "*";
			}
			else
			{
				passwordche[step2] = '\0';
				break;
			}
		}
		cout << endl;
		if (passwordche.length() == password.length())
		{
			for (int i = 0; i < password.length(); i++)
			{
				if (password[i] != passwordche[i])
				{
					cout << "Entered passwords differ!" << endl;
					cout << "Press any key to continue. . .";
					char yu;
					isRight=false;
					yu = _getch();
					create();
				}
			}
		}
		else
		{
			cout << "Entered passwords differ!" << endl;
			cout << "Press any key to continue. . .";
			char yu;
					isRight=false;
			yu = _getch();
			create();
		}
		if(isRight)
		{

		}
	}
	else
	{
		cout << "请创建一个Infer账户：" << endl;
		cout << "用户名：";
		cin >> username;
		cout << "密码：";
		char tu;
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				password[step1] = tu;
				step1++;
				cout << "*";
			}
			else
			{
				password[step1] = '\0';
				break;
			}
		}
		cout << endl;
		string passwordche;
		cout << "重复密码：";
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				passwordche[step2] = tu;
				step2++;
				cout << "*";
			}
			else
			{
				passwordche[step2] = '\0';
				break;
			}
		}
		cout << endl;
		if (passwordche.length() == password.length())
		{
			for (int i = 0; i < password.length(); i++)
			{
				if (password[i] != passwordche[i])
				{
					cout << "两次输入不一致！" << endl;
					system("pause");
					create();
				}
			}
		}
		else
		{
			cout << "两次输入不一致！" << endl;
			system("pause");
			create();
		}
	}
}
void login()
{
	system("cls");
	if (!ltf)
	{
		int step = 0;
		string usernameche, passwordche;
		cout << "Username: ";
		cin >> usernameche;
		cout << "Password: ";
		char tu;
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				passwordche[step] = tu;
				step++;
				cout << "*";
			}
			else
			{
				passwordche[step] = '\0';
				break;
			}
		}
		cout << endl;
		bool fast = false;
		if (password.length() == step && username.length() == usernameche.length())
		{
			for (int i = 0; i < step; i++)
			{
				if (password[i] != passwordche[i])
				{
					cout << "Wrong password!" << endl;

					fast = true;
					cout << "Press any key to continue. . .";
					char yu;
					yu = _getch();
					login();
				}
			}if (!fast)
			{
				for (int i = 0; i < usernameche.length(); i++)
				{
					if (username[i] != usernameche[i])
					{
						cout << "Wrong username!" << endl;

						cout << "Press any key to continue. . .";
						char yu;
						yu = _getch();
						login();
					}
				}
			}
		}
		else
		{
			cout << "Wrong password!" << endl;

			cout << "Press any key to continue. . .";
			char yu;
			yu = _getch();
			login();
		}
	}
	else
	{
		int step = 0;
		string usernameche, passwordche;
		cout << "用户名：";
		cin >> usernameche;
		cout << "密码：";
		char tu;
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				passwordche[step] = tu;
				step++;
				cout << "*";
			}
			else
			{
				passwordche[step] = '\0';
				break;
			}
		}
		cout << endl;
		bool fast = false;
		if (password.length() == step && username.length() == usernameche.length())
		{
			for (int i = 0; i < step; i++)
			{
				if (password[i] != passwordche[i])
				{
					cout << "密码错误！" << endl;
					fast = true;
					system("pause");
					login();
				}
			}
			if (!fast)
			{
				for (int i = 0; i < usernameche.length(); i++)
				{
					if (username[i] != usernameche[i])
					{
						cout << "用户名错误！" << endl;

						system("pause");
						login();
					}
				}

			}

		}
		else
		{
			cout << "密码错误！" << endl;

			system("pause");
			login();
		}
	}
}
*/
void Suiji(int x) {
	int n = rand() % 10;
	if (!f[n]) {
		a[x] = n;
		f[n] = true;
	}
	else {
		Suiji(x);
	}
}
int main() {
	if (!jiance) {
		CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
		load();
		if (!jiance)
		{
			jiance = true;
			//system("mode con cols=120 lines=30");
			system("color 07");
			colour = true;
			cout << "1. 中文" << endl << "2. English";
			char lan;
			do {
				lan = _getch();
			} while (lan != '1'&&lan != '2');
			if (lan == '2') {
				ltf = false;
				system("cls");
				cout << "1. Light" << endl << "2. Dark";
				char col;
				do {
					col = _getch();
				} while (col != '1'&&col != '2');
				if (col == '1') {
					colour = false;
					system("color 70");
				}
				else
				{
					colour = true;
					system("color 07");
				}
				system("cls");
				phbjl[1].jl = phbjl[2].jl = phbjl[3].jl = phbjl[4].jl = phbjl[5].jl = 999;
				phbjl[1].sing = phbjl[2].sing = phbjl[3].sing = phbjl[4].sing = phbjl[5].sing = "Anonymity";
				phbjl[1].second = phbjl[2].second = phbjl[3].second = phbjl[4].second = phbjl[5].second = 999;
				phbjl[1].year = phbjl[2].year = phbjl[3].year = phbjl[4].year = phbjl[5].year = 2008;
				phbjl[1].day = phbjl[2].day = phbjl[3].day = phbjl[4].day = phbjl[5].day = 1;
				phbjl[1].month = phbjl[2].month = phbjl[3].month = phbjl[4].month = phbjl[5].month = 1;
				/*
				for (int i = 0; i <= 100; i++)
				{
					system("cls");
					cout << endl << endl;
					for (int k = 1; k <= 53; k++) {
						cout << " ";
					}
					cout << "Bulls ans Cows" << endl << endl << endl << endl << endl;
					for (int k = 1; k <= 51; k++) {
						cout << " ";
					}
					cout << "Health game advice" << endl << endl << endl << endl;
					for (int k = 1; k <= 37; k++) {
						cout << " ";
					}
					cout << "Resist unhealthy games, refuse pirated games. " << endl << endl << endl << endl;
					for (int k = 1; k <= 30; k++) {
						cout << " ";
					}
					cout << "Pay attention to self-protection, prevent being deceived by. " << endl << endl << endl << endl;
					for (int k = 1; k <= 28; k++) {
						cout << " ";
					}
					cout << "Moderate game beneficial brain, addicted to games hurt the body. " << endl << endl << endl << endl;
					for (int k = 1; k <= 33; k++) {
						cout << " ";
					}
					cout << "Reasonable arrangements of time, enjoy a healthy life." << endl << endl << endl << endl;
					cout << "      ";
					for (int j = 1; j <= i; j++) {
						cout << ">";
					}
					for (int j = i + 1; j < 105; j++) {
						cout << " ";
					}
					cout << i << "%";
				}
				*/
			}
			else {
				system("cls");
				cout << "1. 浅色" << endl << "2. 深色";
				char col;
				do {
					col = _getch();
				} while (col != '1'&&col != '2');
				if (col == '1') {
					colour = false;
					system("color 70");
				}
				else
				{
					colour = true;
					system("color 07");
				}
				system("cls");
				phbjl[1].jl = phbjl[2].jl = phbjl[3].jl = phbjl[4].jl = phbjl[5].jl = 999;
				phbjl[1].sing = phbjl[2].sing = phbjl[3].sing = phbjl[4].sing = phbjl[5].sing = "匿名";
				phbjl[1].second = phbjl[2].second = phbjl[3].second = phbjl[4].second = phbjl[5].second = 999;
				phbjl[1].year = phbjl[2].year = phbjl[3].year = phbjl[4].year = phbjl[5].year = 2008;
				phbjl[1].day = phbjl[2].day = phbjl[3].day = phbjl[4].day = phbjl[5].day = 1;
				phbjl[1].month = phbjl[2].month = phbjl[3].month = phbjl[4].month = phbjl[5].month = 1;
				/*
				for (int i = 0; i <= 100; i++)
				{
					system("cls");
					cout << endl << endl;
					for (int k = 1; k <= 58; k++) {
						cout << " ";
					}
					cout << "猜数" << endl << endl << endl << endl << endl;
					for (int k = 1; k <= 54; k++) {
						cout << " ";
					}
					cout << "健康游戏忠告" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "抵制不良游戏，拒绝盗版游戏。" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "注意自我保护，预防受骗上当。" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "适度游戏益脑，沉迷游戏伤身。" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "合理安排时间，享受健康生活。" << endl << endl << endl << endl;
					cout << "      ";
					for (int j = 1; j <= i; j++) {
						cout << ">";
					}
					for (int j = i + 1; j < 105; j++) {
						cout << " ";
					}
					cout << i << "%";
				}
				*/
			}
		}
		else
		{
			if (colour)
			{
				system("color 07");
			}
			else
			{
				system("color 70");
			}
		}
		if (!ltf)
		{
			cout << "Bulls ans Cows" << endl;
			cout << "Health game advice: Resist unhealthy games, refuse pirated games. Pay attention to self-protection, prevent being deceived by. Moderate game beneficial brain, addicted to games hurt the body. Reasonable arrangements of time, enjoy a healthy life." << endl;
			cout << "Loading. . .";
		}
		else
		{
			cout << "猜数字" << endl;
			cout << "健康游戏忠告：抵制不良游戏，拒绝盗版游戏。注意自我保护，预防受骗上当。适度游戏益脑，沉迷游戏伤身。 合理安排时间，享受健康生活。" << endl;
			cout << "加载中……";
		}
	}
	if (!ltf) {
		system("cls");
		cout << "1. New game" << endl;
		cout << "2. Ranking" << endl;
		cout << "3. Rules" << endl;
		cout << "4. Settings" << endl;
		cout << "5. About" << endl;
		cout << "6. Exit";
		char ch;
		do {
			ch = _getch();
		} while (ch != '1'&&ch != '2'&&ch != '3'&&ch != '4'&&ch != '5'&&ch != '6');
		if (ch == '2') {
			system("cls");
			for (int i = 1; i <= 5; i++) {
				cout << i << ". " << phbjl[i].sing << "  " << "Try " << phbjl[i].jl << " time(s)  " << phbjl[i].second << " second(s)  " << phbjl[i].year << "/" << phbjl[i].month << "/" << phbjl[i].day << endl;
			}
			cout << "Press any key to continue...";
			char huj;
			huj = _getch();
			system("cls");
			cout << "1. Back to title" << endl;
			cout << "2. Exit";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				//void save(void);
				save();
				cout << "Welcome back!";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '3') {
			system("cls");
			cout << "The answer is A four-digit number that does not repeat for each person. You have 10 chances to guess the number. For each guess, there is A hint: if the number of guesses is in the answer and the position is A, the number of guesses is in the answer but the position is B, you need to infer the answer based on the clues and get the victory." << endl;
			cout << "Sample:" << endl;
			cout << "Guess:  1 3 2 5" << endl;
			cout << "        | \\ /" << endl;
			cout << "        |  X" << endl;
			cout << "        | / \\" << endl;
			cout << "Answer: 1 2 3 4" << endl;
			cout << "        | \\ |" << endl;
			cout << "        |  \\|" << endl;
			cout << "        |   |" << endl;
			cout << "Hint:   1 A 2 B" << endl;
			cout << "In the sample, the guess number and the answer both include \"1\", \"2\" and \"3\", however: \"1\" is in the correct position, so the value of A which stands for perfectly correct is 1; the position of \"2\" and \"3\" is wrong, so the value of B which stands for not completely correct is 2." << endl;
			cout << "Press any key to continue...";
			char huj;
			huj = _getch();
			system("cls");
			cout << "1. Back to title" << endl;
			cout << "2. Exit";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				//void save(void);
				save();
				cout << "Welcome back!";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '4') {
			system("cls");
			cout << "1. Languages" << endl << "2. Themes"/* << endl << "3. Account"*/;
			char sett;
			do {
				sett = _getch();
			} while (sett != '1'&&sett != '2');
			if (sett == '1') {
				system("cls");
				cout << "1. 中文" << endl;
				cout << "2. English";
				char huj;
				do {
					huj = _getch();
				} while (huj != '1'&&huj != '2');
				if (huj == '2') {
					ltf = false;
					if (phbjl[1].sing == "匿名") {
						phbjl[1].sing = "Anonymity";
					}
					if (phbjl[2].sing == "匿名") {
						phbjl[2].sing = "Anonymity";
					}
					if (phbjl[3].sing == "匿名") {
						phbjl[3].sing = "Anonymity";
					}
					if (phbjl[4].sing == "匿名") {
						phbjl[4].sing = "Anonymity";
					}
					if (phbjl[5].sing == "匿名") {
						phbjl[5].sing = "Anonymity";
					}
					cout << endl << "Press any key to continue...";
					char huj;
					huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				else {
					ltf = true;
					if (phbjl[1].sing == "Anonymity") {
						phbjl[1].sing = "匿名";
					}
					if (phbjl[2].sing == "Anonymity") {
						phbjl[2].sing = "匿名";
					}
					if (phbjl[3].sing == "Anonymity") {
						phbjl[3].sing = "匿名";
					}
					if (phbjl[4].sing == "Anonymity") {
						phbjl[4].sing = "匿名";
					}
					if (phbjl[5].sing == "Anonymity") {
						phbjl[5].sing = "匿名";
					}
					cout << endl;
					system("pause");
					system("cls");
					cout << "1. 返回主页" << endl;
					cout << "2. 退出游戏";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
			}
			/*
			else if(sett=='3')
			{
				system("cls");
				cout<<"1. Change username"<<endl;
				cout<<"2. Change passowrd";
				char huj;
				huj=_getch();
				if(huj=='2')
				{
					int totstep=0;
		char tu;
					string passwordche,new1,new2;
					system("cls");
					cout<<"Old password: ";
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				passwordche[totstep] = tu;
				totstep++;
				cout << "*";
			}
			else
			{
				passwordche[totstep] = '\0';
				break;
			}
		}
		cout << endl;
					cout << "New password: ";
					int step1=0,step2=0;
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				new1[step1] = tu;
				step1++;
				cout << "*";
			}
			else
			{
				new1[step1] = '\0';
				break;
			}
		}
		cout << endl;
		cout << "Repeat new passowrd: ";
		while (tu = _getch())
		{
			if (tu != '\r')
			{
				new2[step2] = tu;
				step2++;
				cout << "*";
			}
			else
			{
				new2[step2] = '\0';
				break;
			}
		}
		cout << endl;
			if(totstep==password.length())
			{
				for(int i=0;i<password.length();i++)
				{
					if(password[i]!=passwordche[i])
					{
						cout<<"Wrong old password!"<<endl;
					cout << "Press any key to continue. . .";
					char huj;
					huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing = _getch();
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
					}
				}
			}
			else
			{
						cout<<"Wrong old password!"<<endl;
					cout << "Press any key to continue. . .";
					char huj;
					huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing = _getch();
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
			}
		if (step1 == step2)
		{
			for (int i = 0; i < step1; i++)
			{
				if (new1[i] != new2[i])
				{
					cout << "Entered new passwords differ!" << endl;
					cout << "Press any key to continue. . .";
					char huj;
					huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing = _getch();
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
			}
		}
		else
		{
			cout << "Entered new passwords differ!" << endl;
			cout << "Press any key to continue. . .";
					char huj;
					huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing = _getch();
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
		}
				string password;
				for(int i=0;i<step1;i++)
				{
					password[i]=new1[i];
				}
				password[step1]='\0';
				}
			cout << "Press any key to continue. . .";
					huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing = _getch();
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
			}
			*/
			else {
				if (!ltf) {
					system("cls");
					cout << "1. Light" << endl << "2. Dark";
					char colors;
					do {
						colors = _getch();
					} while (colors != '1'&&colors != '2');
					if (colors == '1') {
						colour = false;
						system("color 70");
					}
					else {
						colour = true;
						system("color 07");
					}
					cout << endl << "Press any key to continue...";
					char huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				else {
					system("cls");
					cout << "1. 浅色" << endl << "2. 深色";
					char colorss;
					do {
						colorss = _getch();
					} while (colorss != '1'&&colorss != '2');
					if (colorss == '1') {
						colour = false;
						system("color 70");
					}
					else {
						colour = true;
						system("color 07");
					}
					cout << endl;
					system("pause");
					system("cls");
					cout << "1. 返回主页" << endl;
					cout << "2. 退出游戏";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						save();
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
			}
		}
		else if (ch == '5') {
			system("cls");
			cout << "Version：6.1" << endl;
			cout << "If you have any question during game, please send your valuable advice to the writer's QQ 3111747264(Cola), we'll reply soon." << endl;
			cout << "Press any key to continue...";
			char huj;
			huj = _getch();
			system("cls");
			cout << "1. Back to title" << endl;
			cout << "2. Exit";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				//void save(void);
				save();
				cout << "Welcome back!";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '6') {
			system("cls");
			save();
			//void save(void);
			cout << "Welcome back!";
			exit(0);
		}
		else {
			double tim, tim1, tim2, totim = 0;
			int tim3;
			system("cls");
			for (int j = 1; j <= 10; j++) {
				f[j] = false;
			}
			srand((unsigned)time(NULL));
			Suiji(1);
			Suiji(2);
			Suiji(3);
			Suiji(4);
			for (int i = 1; i <= 10; i++) {
				int A = 0, B = 0;
				string s;
				if (colour)
				{
					if (i > 0 && i < 6)
					{
						system("color 02");
					}
					if (i == 8 || i == 6 || i == 7 || i == 9 || i == 10)
					{
						system("color 06");
					}
				}
				else
				{
					if (i > 0 && i < 6)
					{
						system("color 72");
					}
					if (i == 8 || i == 6 || i == 7 || i == 9 || i == 10)
					{
						system("color 76");
					}
				}
				if (i == 1) {
					cout << "1st attempt: ";
				}
				else if (i == 2) {
					cout << "2nd attempt: ";
				}
				else if (i == 3) {
					cout << "3rd attempt: ";
				}
				else {
					cout << i << "th attempt: ";
				}
				shuru = 0;
				tim1 = (double)clock() / CLOCKS_PER_SEC;
				while (shuru <= 4) {
					if (shuru == 4) {
						char ch;
						do {
							ch = _getch();
						} while (ch != '\r'&&ch != '\b');
						if (ch == '\r') {
							break;
						}
						else {
							shuru--;
							SetPos(shuru + 13, i - 1);
							cout << " ";
							SetPos(shuru + 13, i - 1);
							continue;
						}
					}
					else if (shuru != 0) {
						if (shuru == 1) {
							do {
								s[shuru] = _getch();
							} while ((s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0'&&s[shuru] != '\b') || s[shuru] == s[0]);
						}
						else if (shuru == 2) {
							do {
								s[shuru] = _getch();
							} while ((s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0'&&s[shuru] != '\b') || s[shuru] == s[0] || s[shuru] == s[1]);
						}
						else {
							do {
								s[shuru] = _getch();
							} while ((s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0'&&s[shuru] != '\b') || s[shuru] == s[0] || s[shuru] == s[1] || s[shuru] == s[2]);
						}
						if (s[shuru] == '\b') {
							shuru--;
							SetPos(shuru + 13, i - 1);
							cout << " ";
							SetPos(shuru + 13, i - 1);
							continue;
						}
						cout << s[shuru];
						shuru++;
					}
					else {
						do {
							s[shuru] = _getch();
						} while (s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0');
						cout << s[shuru];
						shuru++;
					}
				}
				tim2 = (double)clock() / CLOCKS_PER_SEC;
				tim = tim2 - tim1;
				tim3 = ceil(tim);
				totim += tim3;
				if (s[0] == s[1] || s[0] == s[2] || s[0] == s[3] || s[1] == s[2] || s[1] == s[3] || s[2] == s[3] || (s[0] != '0'&&s[0] != '1'&&s[0] != '2'&&s[0] != '3'&&s[0] != '4'&&s[0] != '5'&&s[0] != '6'&&s[0] != '7'&&s[0] != '8'&&s[0] != '9') || (s[1] != '0'&&s[1] != '1'&&s[1] != '2'&&s[1] != '3'&&s[1] != '4'&&s[1] != '5'&&s[1] != '6'&&s[1] != '7'&&s[1] != '8'&&s[1] != '9') || (s[2] != '0'&&s[2] != '1'&&s[2] != '2'&&s[2] != '3'&&s[2] != '4'&&s[2] != '5'&&s[2] != '6'&&s[2] != '7'&&s[2] != '8'&&s[2] != '9') || (s[3] != '0'&&s[3] != '1'&&s[3] != '2'&&s[3] != '3'&&s[3] != '4'&&s[3] != '5'&&s[3] != '6'&&s[3] != '7'&&s[3] != '8'&&s[3] != '9')) {
					if (colour)
					{
						system("color 04");
					}
					else
					{
						system("color 74");
					}
					cout << "   System error!" << endl;
					cout << "Press any key to continue...";
					char huj;
					huj = _getch();
					system("cls");
					if (colour)
					{
						system("color 07");
					}
					else
					{
						system("color 70");
					}
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				for (int j = 0; j < 4; j++) {
					if (s[j] - '0' == a[j + 1]) {
						A++;
					}
					else {
						for (int k = 1; k <= 4; k++) {
							if (s[j] - '0' == a[k]) {
								B++;
							}
						}
					}
				}
				if (A == 4) {
					if (colour)
					{
						system("color 02");
					}
					else
					{
						system("color 72");
					}
					cout << "   4A0B" << endl << "You win!" << endl;
					string sting;
					if (i < phbjl[1].jl || (i == phbjl[1].jl&&totim < phbjl[1].second)) {
						for (int l = 5; l >= 2; l--) {
							phbjl[l].jl = phbjl[l - 1].jl;
							phbjl[l].day = phbjl[l - 1].day;
							phbjl[l].month = phbjl[l - 1].month;
							phbjl[l].year = phbjl[l - 1].year;
							phbjl[l].second = phbjl[l - 1].second;
							swap(phbjl[l].sing, phbjl[l - 1].sing);
						}
						cout << "You have broken the game record, please input your name here: ";
						cin >> sting;
						getSystemTime(1);
						phbjl[1].second = totim;
						phbjl[1].jl = i;
						swap(sting, phbjl[1].sing);
					}
					else if (i < phbjl[5].jl || (i == phbjl[5].jl&&totim < phbjl[5].second)) {
						int xunzhao;
						for (int l = 1; l <= 5; l++) {
							if (i < phbjl[l].jl) {
								xunzhao = l;
								break;
							}
							else if (i == phbjl[l].jl&&totim < phbjl[l].second)
							{
								xunzhao = l;
								break;
							}
						}
						for (int l = 5; l > xunzhao; l--) {
							phbjl[l].jl = phbjl[l - 1].jl;
							phbjl[l].day = phbjl[l - 1].day;
							phbjl[l].month = phbjl[l - 1].month;
							phbjl[l].year = phbjl[l - 1].year;
							phbjl[l].second = phbjl[l - 1].second;
							swap(phbjl[l].sing, phbjl[l - 1].sing);
						}
						phbjl[xunzhao].jl = i;
						cout << "Please input your name here: ";
						cin >> sting;
						getSystemTime(xunzhao);
						phbjl[xunzhao].second = totim;
						swap(sting, phbjl[xunzhao].sing);
					}
					cout << "Press any key to continue...";
					char huj;
					huj = _getch();
					system("cls");
					if (colour)
					{
						system("color 07");
					}
					else
					{
						system("color 70");
					}
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				if (i == 10 && A != 4) {
					if (colour)
					{
						system("color 04");
					}
					else
					{
						system("color 74");
					}
					cout << "   " << A << "A" << B << "B" << endl << "You lose!   Answer: " << a[1] << a[2] << a[3] << a[4] << endl;
					cout << "Press any key to continue...";
					char huj;
					huj = _getch();
					system("cls");
					if (colour)
					{
						system("color 07");
					}
					else
					{
						system("color 70");
					}
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				cout << "   " << A << "A" << B << "B" << endl;
			}
		}
	}
	else {
		system("cls");
		cout << "1. 开始游戏" << endl;
		cout << "2. 游戏排行" << endl;
		cout << "3. 游戏规则" << endl;
		cout << "4. 游戏设置" << endl;
		cout << "5. 关于游戏" << endl;
		cout << "6. 退出游戏";
		char ch;
		do {
			ch = _getch();
		} while (ch != '1'&&ch != '2'&&ch != '3'&&ch != '4'&&ch != '5'&&ch != '6');
		if (ch == '2') {
			system("cls");
			for (int i = 1; i <= 5; i++) {
				cout << i << ". " << phbjl[i].sing << " 尝试" << phbjl[i].jl << "次 " << phbjl[i].second << "秒 " << phbjl[i].year << "/" << phbjl[i].month << "/" << phbjl[i].day << endl;
			}
			system("pause");
			system("cls");
			cout << "1. 返回主页" << endl;
			cout << "2. 退出游戏";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				save();
				//void save(void);
				cout << "欢迎再次游戏！";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '3') {
			system("cls");
			cout << "答案为一个每一位都不重复的四位数，你共有10次机会来猜这个数。对于每一次猜测，会有一个提示：若答案里有猜的数且位置正确为A, 答案里有猜的数但位置不同为B。你需要根据提示推理得出答案，获得胜利。" << endl;
			cout << "样例：" << endl;
			cout << "猜数：1 3 2 5" << endl;
			cout << "      | \\ /" << endl;
			cout << "      |  X" << endl;
			cout << "      | / \\" << endl;
			cout << "答案：1 2 3 4" << endl;
			cout << "      | \\ |" << endl;
			cout << "      |  \\|" << endl;
			cout << "      |   |" << endl;
			cout << "提示：1 A 2 B" << endl;
			cout << "在样例中，猜数和答案里均包括“1”、“2”和“3”，其中：“1”的位置是正确的，故代表完全正确的A的值为1；“2”和“3”的位置是错误的，故代表不完全正确的B的值为2。" << endl;
			system("pause");
			system("cls");
			cout << "1. 返回主页" << endl;
			cout << "2. 退出游戏";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				save();
				//void save(void);
				cout << "欢迎再次游戏！";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '4') {
			system("cls");
			cout << "1. 语言" << endl << "2. 主题";
			char sett;
			do {
				sett = _getch();
			} while (sett != '1'&&sett != '2');
			if (sett == '1') {
				system("cls");
				cout << "1. 中文" << endl;
				cout << "2. English";
				char huj;
				do {
					huj = _getch();
				} while (huj != '1'&&huj != '2');
				if (huj == '2') {
					ltf = false;
					if (phbjl[1].sing == "匿名") {
						phbjl[1].sing = "Anonymity";
					}
					if (phbjl[2].sing == "匿名") {
						phbjl[2].sing = "Anonymity";
					}
					if (phbjl[3].sing == "匿名") {
						phbjl[3].sing = "Anonymity";
					}
					if (phbjl[4].sing == "匿名") {
						phbjl[4].sing = "Anonymity";
					}
					if (phbjl[5].sing == "匿名") {
						phbjl[5].sing = "Anonymity";
					}
					cout << endl << "Press any key to continue...";
					char huj;
					huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						save();
						system("cls");
						//void save(void);
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				else {
					ltf = true;
					if (phbjl[1].sing == "Anonymity") {
						phbjl[1].sing = "匿名";
					}
					if (phbjl[2].sing == "Anonymity") {
						phbjl[2].sing = "匿名";
					}
					if (phbjl[3].sing == "Anonymity") {
						phbjl[3].sing = "匿名";
					}
					if (phbjl[4].sing == "Anonymity") {
						phbjl[4].sing = "匿名";
					}
					if (phbjl[5].sing == "Anonymity") {
						phbjl[5].sing = "匿名";
					}
					cout << endl;
					system("pause");
					system("cls");
					cout << "1. 返回主页" << endl;
					cout << "2. 退出游戏";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
			}
			else {
				if (!ltf) {
					system("cls");
					cout << "1. Light" << endl << "2. Dark";
					char colors;
					do {
						colors = _getch();
					} while (colors != '1'&&colors != '2');
					if (colors == '1') {
						colour = false;
						system("color 70");
					}
					else {
						colour = true;
						system("color 07");
					}
					cout << endl << "Press any key to continue...";
					char huj = _getch();
					system("cls");
					cout << "1. Back to title" << endl;
					cout << "2. Exit";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "Welcome back!";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				else {
					system("cls");
					cout << "1. 浅色" << endl << "2. 深色";
					char colorss;
					do {
						colorss = _getch();
					} while (colorss != '1'&&colorss != '2');
					if (colorss == '1') {
						colour = false;
						system("color 70");
					}
					else {
						colour = true;
						system("color 07");
					}
					cout << endl;
					system("pause");
					system("cls");
					cout << "1. 返回主页" << endl;
					cout << "2. 退出游戏";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "欢迎再次游戏！";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
			}
		}
		else if (ch == '5') {
			system("cls");
			cout << "版本：6.1" << endl;
			cout << "若在游戏中有任何疑问，请发送您的宝贵意见至作者的QQ账号3111747264（Cola）上，我们会及时给您答复，谢谢。" << endl;
			system("pause");
			system("cls");
			cout << "1. 返回主页" << endl;
			cout << "2. 退出游戏";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				save();
				//void save(void);
				cout << "欢迎再次游戏！";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '6') {
			save();
			system("cls");
			cout << "欢迎再次游戏！";
			exit(0);
		}
		else {
			double tim, tim1, tim2, totim = 0;
			int tim3;
			system("cls");
			for (int j = 1; j <= 10; j++) {
				f[j] = false;
			}
			srand((unsigned)time(NULL));
			Suiji(1);
			Suiji(2);
			Suiji(3);
			Suiji(4);
			for (int i = 1; i <= 10; i++) {
				if (colour)
				{
					if (i > 0 && i < 6)
					{
						system("color 02");
					}
					if (i == 8 || i == 6 || i == 7 || i == 9 || i == 10)
					{
						system("color 06");
					}
				}
				else
				{
					if (i > 0 && i < 6)
					{
						system("color 72");
					}
					if (i == 8 || i == 6 || i == 7 || i == 9 || i == 10)
					{
						system("color 76");
					}
				}
				int A = 0, B = 0;
				string s;
				cout << "第" << i << "次尝试：";
				shuru = 0;
				tim1 = (double)clock() / CLOCKS_PER_SEC;
				while (shuru <= 4) {
					if (shuru == 4) {
						char ch;
						do {
							ch = _getch();
						} while (ch != '\r'&&ch != '\b');
						if (ch == '\r') {
							break;
						}
						else {
							shuru--;
							SetPos(shuru + 11, i - 1);
							cout << " ";
							SetPos(shuru + 11, i - 1);
							continue;
						}
					}
					else if (shuru != 0) {
						if (shuru == 1) {
							do {
								s[shuru] = _getch();
							} while ((s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0'&&s[shuru] != '\b') || s[shuru] == s[0]);
						}
						else if (shuru == 2) {
							do {
								s[shuru] = _getch();
							} while ((s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0'&&s[shuru] != '\b') || s[shuru] == s[0] || s[shuru] == s[1]);
						}
						else {
							do {
								s[shuru] = _getch();
							} while ((s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0'&&s[shuru] != '\b') || s[shuru] == s[0] || s[shuru] == s[1] || s[shuru] == s[2]);
						}
						if (s[shuru] == '\b') {
							shuru--;
							SetPos(shuru + 11, i - 1);
							cout << " ";
							SetPos(shuru + 11, i - 1);
							continue;
						}
						cout << s[shuru];
						shuru++;
					}
					else {
						do {
							s[shuru] = _getch();
						} while (s[shuru] != '1'&&s[shuru] != '2'&&s[shuru] != '3'&&s[shuru] != '4'&&s[shuru] != '5'&&s[shuru] != '6'&&s[shuru] != '7'&&s[shuru] != '8'&&s[shuru] != '9'&&s[shuru] != '0');
						cout << s[shuru];
						shuru++;
					}
				}
				tim2 = (double)clock() / CLOCKS_PER_SEC;
				tim = tim2 - tim1;
				tim3 = ceil(tim);
				totim += tim3;
				if (s[0] == s[1] || s[0] == s[2] || s[0] == s[3] || s[1] == s[2] || s[1] == s[3] || s[2] == s[3] || (s[0] != '0'&&s[0] != '1'&&s[0] != '2'&&s[0] != '3'&&s[0] != '4'&&s[0] != '5'&&s[0] != '6'&&s[0] != '7'&&s[0] != '8'&&s[0] != '9') || (s[1] != '0'&&s[1] != '1'&&s[1] != '2'&&s[1] != '3'&&s[1] != '4'&&s[1] != '5'&&s[1] != '6'&&s[1] != '7'&&s[1] != '8'&&s[1] != '9') || (s[2] != '0'&&s[2] != '1'&&s[2] != '2'&&s[2] != '3'&&s[2] != '4'&&s[2] != '5'&&s[2] != '6'&&s[2] != '7'&&s[2] != '8'&&s[2] != '9') || (s[3] != '0'&&s[3] != '1'&&s[3] != '2'&&s[3] != '3'&&s[3] != '4'&&s[3] != '5'&&s[3] != '6'&&s[3] != '7'&&s[3] != '8'&&s[3] != '9')) {
					if (colour)
					{
						system("color 04");
					}
					else
					{
						system("color 74");
					}
					cout << "   系统错误！" << endl;
					system("pause");
					system("cls");
					if (colour)
					{
						system("color 07");
					}
					else
					{
						system("color 70");
					}
					cout << "1. 返回主页" << endl;
					cout << "2. 退出游戏";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						cout << "欢迎再次游戏！";
						exit(0);
					}
					else {
						system("cls");
						save();
						main();
					}
				}
				for (int j = 0; j < 4; j++) {
					if (s[j] - '0' == a[j + 1]) {
						A++;
					}
					else {
						for (int k = 1; k <= 4; k++) {
							if (s[j] - '0' == a[k]) {
								B++;
							}
						}
					}
				}
				if (A == 4) {
					if (colour)
					{
						system("color 02");
					}
					else
					{
						system("color 72");
					}
					cout << "   4A0B" << endl << "你赢了！" << endl;
					string sting;
					if (i < phbjl[1].jl || (i == phbjl[1].jl&&totim < phbjl[1].second)) {
						for (int l = 5; l >= 2; l--) {
							phbjl[l].jl = phbjl[l - 1].jl;
							phbjl[l].day = phbjl[l - 1].day;
							phbjl[l].month = phbjl[l - 1].month;
							phbjl[l].year = phbjl[l - 1].year;
							phbjl[l].second = phbjl[l - 1].second;
							swap(phbjl[l].sing, phbjl[l - 1].sing);
						}
						phbjl[1].jl = i;
						cout << "已破游戏记录，请输入您的尊姓大名：";
						cin >> sting;
						getSystemTime(1);
						phbjl[1].second = totim;
						swap(sting, phbjl[1].sing);
					}
					else if (i < phbjl[5].jl || (i == phbjl[5].jl&&totim < phbjl[5].second)) {
						int xunzhao;
						for (int l = 1; l <= 5; l++) {
							if (i < phbjl[l].jl) {
								xunzhao = l;
								break;
							}
							else if (i == phbjl[l].jl&&totim < phbjl[l].second)
							{
								xunzhao = l;
								break;
							}
						}
						for (int l = 5; l > xunzhao; l--) {
							phbjl[l].jl = phbjl[l - 1].jl;
							phbjl[l].day = phbjl[l - 1].day;
							phbjl[l].month = phbjl[l - 1].month;
							phbjl[l].year = phbjl[l - 1].year;
							phbjl[l].second = phbjl[l - 1].second;
							swap(phbjl[l].sing, phbjl[l - 1].sing);
						}
						phbjl[xunzhao].jl = i;
						getSystemTime(xunzhao);
						cout << "请输入您的尊姓大名：";
						cin >> sting;
						phbjl[xunzhao].second = totim;
						swap(sting, phbjl[xunzhao].sing);
					}
					system("pause");
					system("cls");
					if (colour)
					{
						system("color 07");
					}
					else
					{
						system("color 70");
					}
					cout << "1. 返回主页" << endl;
					cout << "2. 退出游戏";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						cout << "欢迎再次游戏！";
						save();
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				if (i == 10 && A != 4) {
					if (colour)
					{
						system("color 04");
					}
					else
					{
						system("color 74");
					}
					cout << "   " << A << "A" << B << "B" << endl << "你输了！   答案：" << a[1] << a[2] << a[3] << a[4] << endl;
					system("pause");
					system("cls");
					if (colour)
					{
						system("color 07");
					}
					else
					{
						system("color 70");
					}
					cout << "1. 返回主页" << endl;
					cout << "2. 退出游戏";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "欢迎再次游戏！";
						exit(0);
					}
					else {
						system("cls");
						main();
					}
				}
				cout << "   " << A << "A" << B << "B" << endl;
			}
		}
	}
}
