#include <iostream>
#include <cstring>
#include <Windows.h>
#include "UserHandler.h"
#include "comn_exception.h"
#define LEN 50

using namespace std;

void UserHandler::AddUser(void)
{
	int id;
	char name[LEN];
	char password[LEN];
	char email[LEN];
	char phone[LEN];
	char major[LEN];
	int select = 0;

	try
	{
		cout << "------------------------------------------------" << endl;
		cout << "정보 입력" << endl;
		cout << "ID: ";
		cin >> id;
		checkConsoleInput();
		cout << "이름: ";
		cin >> name;
		cout << "비밀번호: ";
		cin >> password;
		cout << "e-mail: ";
		cin >> email;
		cout << "전화번호: ";
		cin >> phone;
		cout << "학과: ";
		cin >> major;

		if (CheckUser(id))
		{
			cout << "해당되는 직업을 선택해주세요." << endl;
			cout << "1. 교수" << endl;
			cout << "2. 학생" << endl;
			cout << "선택: ";
			cin >> select;

			// 이 경우 1과 2의 선택지에 따라 수행되는 문장이 다르므로
			// try-catch문보다 if 문을 통한 예외처리가 더 코드가 간단하다고 생각하였음
			if (select == 1) {
				userList[num++] = new professor(id, name, password, email, phone, major);
				cout << "성공적으로 저장되었습니다." << endl;
				cout << "------------------------------------------------" << endl;
			}
			else if (select == 2) {
				userList[num++] = new student(id, name, password, email, phone, major);
				cout << "성공적으로 저장되었습니다." << endl;
				cout << "------------------------------------------------" << endl;
			}
			else
			{
				cout << "잘못 입력하셨습니다. 다시 확인해주세요." << endl;
				cout << "------------------------------------------------" << endl;
			}
		}
		else
		{
			cout << "중복된 학번이 있습니다." << endl;
			cout << "다시 확인해주세요." << endl;
			cout << "------------------------------------------------" << endl;
		}
	}
	catch (consoleInputFailException& e)
	{
		e.clearBuffer();
		e.showExceptionMessage();
	}
}

bool UserHandler::CheckUser(int id)
{
	for (int i = 0; i < num; i++)
		if (userList[i]->get_ID() == id)		// id와 저장된 userList 중 일치하는 id (중복된 아이디) 가 있는지 확인 
			return false;
	return true;
}

void UserHandler::ChangeUser(user* curUser)
{
	int currentID;
	char currentPassword[LEN];
	user* currentUser;
	int select;
	char input[LEN];

	cout << "------------------------------------------------" << endl;
	/*
	cout << "현재 ID 입력: ";
	cin >> currentID;
	cout << "현재 비밀번호 입력: ";
	cin >> currentPassword;
	*/

	/* if문을 사용하여 예외처리를 하는 경우
	if (SearchUser(currentID, currentPassword) == NULL) {			// 해당 ID와 비밀번호가 일치하는 사용자가 없는 경우
		cout << "해당하는 사용자가 없습니다. 다시 입력해주세요." << endl;
		cout << "--------------------------" << endl;
		return;
	}
	*/

	currentUser = curUser;

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
		return;
	}

	cout << "------------------------------------------------" << endl;
	cout << "현재 정보" << endl;
	cout << "ID: " << currentUser->get_ID() << endl;
	cout << "비밀번호: " << currentUser->get_password() << endl;
	cout << "이메일: " << currentUser->get_mail() << endl;
	cout << "전화번호: " << currentUser->get_ph_num() << endl;
	cout << "전공: " << currentUser->get_major() << endl;

	cout << "------------------------------------------------" << endl;
	cout << "수정할 정보 선택" << endl;
	cout << "1. 비밀번호" << endl;
	cout << "2. 이메일" << endl;
	cout << "3. 전화번호" << endl;
	cout << "4. 전공" << endl;
	cout << "선택: ";
	cin >> select;
	cout << "변경할 정보 입력: ";
	cin >> input;

	// select에 저장된 값에 따라 다른 코드가 수행되기 때문에
	// try-catch문보다 switch문의 default를 통한 예외처리가 더 적합하다고 판단함 
	system("cls");
	switch (select)
	{
	case 1:
		currentUser->change_password(input);
		cout << "성공적으로 저장되었습니다." << endl;
		cout << "------------------------------------------------" << endl;
		break;
	case 2:
		currentUser->change_mail(input);
		cout << "성공적으로 저장되었습니다." << endl;
		cout << "------------------------------------------------" << endl;
		break;
	case 3:
		currentUser->change_ph_num(input);
		cout << "성공적으로 저장되었습니다." << endl;
		cout << "------------------------------------------------" << endl;
		break;
	case 4:
		currentUser->change_major(input);
		cout << "성공적으로 저장되었습니다." << endl;
		cout << "------------------------------------------------" << endl;
		break;
	default:
		cout << "잘못 입력하셨습니다. 다시 확인해주세요." << endl;
		cout << "------------------------------------------------" << endl;
	}
}

user* UserHandler::SearchUser(int id, char* password)
{
	for (int i = 0; i < num; i++)
		if ((userList[i]->get_ID() == id) && !(strcmp(userList[i]->get_password(), password)))		// 입력된 ID와 비밀번호가 일치하는 저장된 사용자가 있는지 확인 
			return userList[i];
	return NULL;
}

user* UserHandler::SearchUser(int id)
{
	for (int i = 0; i < num; i++)
		if (userList[i]->get_ID() == id)		// 입력된 ID가 일치하는 저장된 사용자가 있는지 확인 
			return userList[i];
	return NULL;
}

UserHandler::~UserHandler(void)
{
	for (int i = 0; i < num; i++)
	{
		delete userList[i];
	}
}

/* test
int main(void)
{
	int id = 123456789;
	char pw1[LEN] = "dkdk";
	char* pw = new char[strlen(pw1) + 1];
	strcpy(pw, pw1);
	UserHandler userhandler;
	userhandler.AddUser();
	userhandler.AddUser();				// 중복된 ID가 있는 경우 테스트
	userhandler.ChangeUser();
	userhandler.ChangeUser();			// 해당 사용자가 없는 경우 테스트
	return 0;
}
*/
