#include <iostream>
#include <Windows.h>
#include "UserHandler.h"
#include "comn_exception.h"

using namespace std;

UserHandler userManager;

user* login();
user* loginOrJoin();

int main(void)
{
	user* currentUser;
	do
	{
		currentUser = NULL;

		while (currentUser == NULL)
		{
			try
			{
				currentUser = loginOrJoin();
			}
			catch (consoleInputFailException& e)
			{
				e.clearBuffer();
				system("cls");
				e.showExceptionMessage();
			}

		}

		/* 로그인 후 프로그램 설계 */
	} while (1);

	return 0;
}

user* loginOrJoin(void)
{
	int select;
	user* currentUser;

	cout << "------------------------------------------" << endl;
	cout << "학생 지원 시스템에 오신 것을 환영합니다." << endl;
	cout << "무엇을 도와드릴까요?" << endl;
	cout << "1. 로그인" << endl;
	cout << "2. 회원가입" << endl;
	cout << "3. 프로그램 종료" << endl;
	cout << "선택: ";
	cin >> select;
	checkConsoleInput();
	system("cls");
	switch (select)
	{
	case 1:
	{
		currentUser = login();

		// 예외처리 :  해당 ID와 비밀번호가 일치하는 사용자가 없는 경우
		try
		{
			if (currentUser == NULL)
				throw currentUser;
		}
		catch (user* expn)
		{
			cout << "해당하는 사용자가 없습니다. 다시 입력해주세요." << endl;
			cout << "------------------------------------------------" << endl;
			return NULL;
		}
		system("cls");
		cout << currentUser->get_name() << "님, 환영합니다." << endl;
		return currentUser;
	}
	case 2:
		userManager.AddUser();
		return NULL;
	case 3:
		exit(0);
	default:
		cout << "잘못 입력하셨습니다. 다시 확인해주세요." << endl;
		cout << "------------------------------------------------" << endl;
	}
	return NULL;
}

user* login(void)
{
	int id;
	char password[LEN];
	user* currentUser;

	try
	{
		cout << "------------------------------------------------" << endl;
		cout << "ID: ";
		cin >> id;
		checkConsoleInput();
		cout << "비밀번호: ";
		cin >> password;
		currentUser = userManager.SearchUser(id, password);
		return currentUser;
	}
	catch (consoleInputFailException& e)
	{
		e.clearBuffer();
		e.showExceptionMessage();
		return NULL;
	}
}
