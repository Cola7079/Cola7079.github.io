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
	cout<<"��������С���   ";
	//guessnumber_node*p=NULL;
	char* str = new char[20];
	memset(str,0,20);
	sprintf(str,"%d",phbjl[1].jl);
	ofstream sm("phbjljl1.txt");
	if (!sm)
	{
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
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
		cout<<"�浵ʧ�ܣ�"<<endl;
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
	cout<<"��ɣ�"<<endl;
	}
	void load(void){
	cout<<"��ȡ�����С���   ";
	//guessnumber_node*p,*q;
	int m=1,i,j;
	FILE* mem;
	if((mem=fopen("memory.txt","r"))==NULL){
		cout<<"��ɣ�"<<endl;
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
	cout<<"��ɣ�"<<endl;
	}
	void load(void);
	char* str = new char[100005];
	int read(){

		cout<<"��������С���";
	//guessnumber_node*p=NULL;
	memset(str,0,100005);
	sprintf(str,"%d",phbjl[1].jl);
	ofstream sm("phbjljl1.txt");
	if (!sm)
	{
		system("cls");
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
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
		cout << "�������ʧ�ܣ�" << endl;
		return 0;
	}
	else
	{
		sm5.write(str,strlen(str));
	}
	delete str;
	FILE *fp = NULL;  //��������ʼ���ļ�ָ��
	char str[100] = "123456";  //��������ֵstr�ַ����������
	fp = fopen("phbjlsing1.txt","w"); //ֻ����ʽ���ļ�
	fputs(str,fp);   // д��str����
	fclose(fp);     //�ر��ļ�
	/*
	FILE* mem;
	if((mem=fopen("memory.txt","w+"))==NULL){
		cout<<"�浵ʧ�ܣ�"<<endl;
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
	cout<<"��ɣ�"<<endl;
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
		cout << "�봴��һ��Infer�˻���" << endl;
		cout << "�û�����";
		cin >> username;
		cout << "���룺";
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
		cout << "�ظ����룺";
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
					cout << "�������벻һ�£�" << endl;
					system("pause");
					create();
				}
			}
		}
		else
		{
			cout << "�������벻һ�£�" << endl;
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
		cout << "�û�����";
		cin >> usernameche;
		cout << "���룺";
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
					cout << "�������" << endl;
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
						cout << "�û�������" << endl;

						system("pause");
						login();
					}
				}

			}

		}
		else
		{
			cout << "�������" << endl;

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
			cout << "1. ����" << endl << "2. English";
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
				cout << "1. ǳɫ" << endl << "2. ��ɫ";
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
				phbjl[1].sing = phbjl[2].sing = phbjl[3].sing = phbjl[4].sing = phbjl[5].sing = "����";
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
					cout << "����" << endl << endl << endl << endl << endl;
					for (int k = 1; k <= 54; k++) {
						cout << " ";
					}
					cout << "������Ϸ�Ҹ�" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "���Ʋ�����Ϸ���ܾ�������Ϸ��" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "ע�����ұ�����Ԥ����ƭ�ϵ���" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "�ʶ���Ϸ���ԣ�������Ϸ����" << endl << endl << endl << endl;
					for (int k = 1; k <= 46; k++) {
						cout << " ";
					}
					cout << "������ʱ�䣬���ܽ������" << endl << endl << endl << endl;
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
			cout << "������" << endl;
			cout << "������Ϸ�Ҹ棺���Ʋ�����Ϸ���ܾ�������Ϸ��ע�����ұ�����Ԥ����ƭ�ϵ����ʶ���Ϸ���ԣ�������Ϸ���� ������ʱ�䣬���ܽ������" << endl;
			cout << "�����С���";
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
				cout << "1. ����" << endl;
				cout << "2. English";
				char huj;
				do {
					huj = _getch();
				} while (huj != '1'&&huj != '2');
				if (huj == '2') {
					ltf = false;
					if (phbjl[1].sing == "����") {
						phbjl[1].sing = "Anonymity";
					}
					if (phbjl[2].sing == "����") {
						phbjl[2].sing = "Anonymity";
					}
					if (phbjl[3].sing == "����") {
						phbjl[3].sing = "Anonymity";
					}
					if (phbjl[4].sing == "����") {
						phbjl[4].sing = "Anonymity";
					}
					if (phbjl[5].sing == "����") {
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
						phbjl[1].sing = "����";
					}
					if (phbjl[2].sing == "Anonymity") {
						phbjl[2].sing = "����";
					}
					if (phbjl[3].sing == "Anonymity") {
						phbjl[3].sing = "����";
					}
					if (phbjl[4].sing == "Anonymity") {
						phbjl[4].sing = "����";
					}
					if (phbjl[5].sing == "Anonymity") {
						phbjl[5].sing = "����";
					}
					cout << endl;
					system("pause");
					system("cls");
					cout << "1. ������ҳ" << endl;
					cout << "2. �˳���Ϸ";
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
					cout << "1. ǳɫ" << endl << "2. ��ɫ";
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
					cout << "1. ������ҳ" << endl;
					cout << "2. �˳���Ϸ";
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
			cout << "Version��6.1" << endl;
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
		cout << "1. ��ʼ��Ϸ" << endl;
		cout << "2. ��Ϸ����" << endl;
		cout << "3. ��Ϸ����" << endl;
		cout << "4. ��Ϸ����" << endl;
		cout << "5. ������Ϸ" << endl;
		cout << "6. �˳���Ϸ";
		char ch;
		do {
			ch = _getch();
		} while (ch != '1'&&ch != '2'&&ch != '3'&&ch != '4'&&ch != '5'&&ch != '6');
		if (ch == '2') {
			system("cls");
			for (int i = 1; i <= 5; i++) {
				cout << i << ". " << phbjl[i].sing << " ����" << phbjl[i].jl << "�� " << phbjl[i].second << "�� " << phbjl[i].year << "/" << phbjl[i].month << "/" << phbjl[i].day << endl;
			}
			system("pause");
			system("cls");
			cout << "1. ������ҳ" << endl;
			cout << "2. �˳���Ϸ";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				save();
				//void save(void);
				cout << "��ӭ�ٴ���Ϸ��";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '3') {
			system("cls");
			cout << "��Ϊһ��ÿһλ�����ظ�����λ�����㹲��10�λ������������������ÿһ�β²⣬����һ����ʾ���������вµ�����λ����ȷΪA, �����вµ�����λ�ò�ͬΪB������Ҫ������ʾ����ó��𰸣����ʤ����" << endl;
			cout << "������" << endl;
			cout << "������1 3 2 5" << endl;
			cout << "      | \\ /" << endl;
			cout << "      |  X" << endl;
			cout << "      | / \\" << endl;
			cout << "�𰸣�1 2 3 4" << endl;
			cout << "      | \\ |" << endl;
			cout << "      |  \\|" << endl;
			cout << "      |   |" << endl;
			cout << "��ʾ��1 A 2 B" << endl;
			cout << "�������У������ʹ����������1������2���͡�3�������У���1����λ������ȷ�ģ��ʴ�����ȫ��ȷ��A��ֵΪ1����2���͡�3����λ���Ǵ���ģ��ʴ�����ȫ��ȷ��B��ֵΪ2��" << endl;
			system("pause");
			system("cls");
			cout << "1. ������ҳ" << endl;
			cout << "2. �˳���Ϸ";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				save();
				//void save(void);
				cout << "��ӭ�ٴ���Ϸ��";
				exit(0);
			}
			else {
				system("cls");
				main();
			}
		}
		else if (ch == '4') {
			system("cls");
			cout << "1. ����" << endl << "2. ����";
			char sett;
			do {
				sett = _getch();
			} while (sett != '1'&&sett != '2');
			if (sett == '1') {
				system("cls");
				cout << "1. ����" << endl;
				cout << "2. English";
				char huj;
				do {
					huj = _getch();
				} while (huj != '1'&&huj != '2');
				if (huj == '2') {
					ltf = false;
					if (phbjl[1].sing == "����") {
						phbjl[1].sing = "Anonymity";
					}
					if (phbjl[2].sing == "����") {
						phbjl[2].sing = "Anonymity";
					}
					if (phbjl[3].sing == "����") {
						phbjl[3].sing = "Anonymity";
					}
					if (phbjl[4].sing == "����") {
						phbjl[4].sing = "Anonymity";
					}
					if (phbjl[5].sing == "����") {
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
						phbjl[1].sing = "����";
					}
					if (phbjl[2].sing == "Anonymity") {
						phbjl[2].sing = "����";
					}
					if (phbjl[3].sing == "Anonymity") {
						phbjl[3].sing = "����";
					}
					if (phbjl[4].sing == "Anonymity") {
						phbjl[4].sing = "����";
					}
					if (phbjl[5].sing == "Anonymity") {
						phbjl[5].sing = "����";
					}
					cout << endl;
					system("pause");
					system("cls");
					cout << "1. ������ҳ" << endl;
					cout << "2. �˳���Ϸ";
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
					cout << "1. ǳɫ" << endl << "2. ��ɫ";
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
					cout << "1. ������ҳ" << endl;
					cout << "2. �˳���Ϸ";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "��ӭ�ٴ���Ϸ��";
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
			cout << "�汾��6.1" << endl;
			cout << "������Ϸ�����κ����ʣ��뷢�����ı�����������ߵ�QQ�˺�3111747264��Cola���ϣ����ǻἰʱ�����𸴣�лл��" << endl;
			system("pause");
			system("cls");
			cout << "1. ������ҳ" << endl;
			cout << "2. �˳���Ϸ";
			char bingbing;
			do {
				bingbing = _getch();
			} while (bingbing != '1'&&bingbing != '2');
			if (bingbing == '2') {
				system("cls");
				save();
				//void save(void);
				cout << "��ӭ�ٴ���Ϸ��";
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
			cout << "��ӭ�ٴ���Ϸ��";
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
				cout << "��" << i << "�γ��ԣ�";
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
					cout << "   ϵͳ����" << endl;
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
					cout << "1. ������ҳ" << endl;
					cout << "2. �˳���Ϸ";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						cout << "��ӭ�ٴ���Ϸ��";
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
					cout << "   4A0B" << endl << "��Ӯ�ˣ�" << endl;
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
						cout << "������Ϸ��¼���������������մ�����";
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
						cout << "�������������մ�����";
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
					cout << "1. ������ҳ" << endl;
					cout << "2. �˳���Ϸ";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						//void save(void);
						cout << "��ӭ�ٴ���Ϸ��";
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
					cout << "   " << A << "A" << B << "B" << endl << "�����ˣ�   �𰸣�" << a[1] << a[2] << a[3] << a[4] << endl;
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
					cout << "1. ������ҳ" << endl;
					cout << "2. �˳���Ϸ";
					char bingbing;
					do {
						bingbing = _getch();
					} while (bingbing != '1'&&bingbing != '2');
					if (bingbing == '2') {
						system("cls");
						save();
						//void save(void);
						cout << "��ӭ�ٴ���Ϸ��";
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
