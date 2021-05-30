#include <iostream>
#include <cstring>
#include "UserHandler.h"
//#define LEN 50							User.h�� LEN ���

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
	
	cout << "------------------------------------------------" << endl;
	cout << "���� �Է�" << endl;
	cout << "ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "��й�ȣ: ";
	cin >> password;
	cout << "e-mail: ";
	cin >> email;
	cout << "��ȭ��ȣ: ";
	cin >> phone;
	cout << "�а�: ";
	cin >> major;
	
	if (CheckUser(id))
	{
		cout << "�ش�Ǵ� ������ �������ּ���." << endl;
		cout << "1. ����" << endl;
		cout << "2. �л�" << endl;
		cout << "����: ";
		cin >> select;
		
		// �� ��� 1�� 2�� �������� ���� ����Ǵ� ������ �ٸ��Ƿ�
		// try-catch������ if ���� ���� ����ó���� �� �ڵ尡 �����ϴٰ� �����Ͽ���
		if (select == 1) {
			userList[num++] = new professor(id, name, password, email, phone, major);
			cout << "���������� ����Ǿ����ϴ�." << endl; 
			cout << "------------------------------------------------" << endl;
		}
		else if (select == 2) {
			userList[num++] = new student(id, name, password, email, phone, major);
			cout << "���������� ����Ǿ����ϴ�." << endl; 
			cout << "------------------------------------------------" << endl;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� Ȯ�����ּ���." << endl;
			cout << "------------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "�ߺ��� �й��� �ֽ��ϴ�." << endl;
		cout << "�ٽ� Ȯ�����ּ���." << endl;
		cout << "------------------------------------------------" << endl;
	}
}

bool UserHandler::CheckUser(int id)
{
	for (int i = 0; i < num; i++)
		if (userList[i]->get_ID() == id)		// id�� ����� userList �� ��ġ�ϴ� id (�ߺ��� ���̵�) �� �ִ��� Ȯ�� 
			return false;
	return true;
}

void UserHandler::ChangeUser(void)
{
	int currentID;
	char currentPassword[LEN];
	user* currentUser;
	int select;
	char input[LEN];
	
	cout << "------------------------------------------------" << endl;
	cout << "���� ID �Է�: ";
	cin >> currentID;
	cout << "���� ��й�ȣ �Է�: ";
	cin >> currentPassword;

	/* if���� ����Ͽ� ����ó���� �ϴ� ��� 
	if (SearchUser(currentID, currentPassword) == NULL) {			// �ش� ID�� ��й�ȣ�� ��ġ�ϴ� ����ڰ� ���� ���
		cout << "�ش��ϴ� ����ڰ� �����ϴ�. �ٽ� �Է����ּ���." << endl;
		cout << "--------------------------" << endl;
		return;
	}
	*/

	currentUser = SearchUser(currentID, currentPassword);
	
	// ����ó�� :  �ش� ID�� ��й�ȣ�� ��ġ�ϴ� ����ڰ� ���� ���
	try
	{
		if (currentUser == NULL)
			throw currentUser;
	}
	catch(user* expn)
	{
		cout << "�ش��ϴ� ����ڰ� �����ϴ�. �ٽ� �Է����ּ���." << endl;
		cout << "------------------------------------------------" << endl;
		return;
	}
	
	cout << "------------------------------------------------" << endl;
	cout << "���� ����" << endl;
	cout << "ID: " << currentUser->get_ID() << endl;
	cout << "��й�ȣ: " << currentUser->get_password() << endl;
	cout << "�̸���: " << currentUser->get_mail() << endl;
	cout << "��ȭ��ȣ: " << currentUser->get_ph_num() << endl;
	cout << "����: " << currentUser->get_major() << endl;
	
	cout << "------------------------------------------------" << endl;
	cout << "������ ���� ����" << endl;
	cout << "1. ��й�ȣ" << endl;
	cout << "2. �̸���" << endl;
	cout << "3. ��ȭ��ȣ" << endl;
	cout << "4. ����" << endl;
	cout << "����: ";
	cin >> select;
	cout << "������ ���� �Է�: ";
	cin >> input;
	
	// select�� ����� ���� ���� �ٸ� �ڵ尡 ����Ǳ� ������
	// try-catch������ switch���� default�� ���� ����ó���� �� �����ϴٰ� �Ǵ��� 
	switch(select)
	{
		case 1:
			currentUser->change_password(input);
			cout << "���������� ����Ǿ����ϴ�." << endl;
			cout << "------------------------------------------------" << endl;
			break;
		case 2:
			currentUser->change_mail(input);
			cout << "���������� ����Ǿ����ϴ�." << endl;
			cout << "------------------------------------------------" << endl;
			break;
		case 3:
			currentUser->change_ph_num(input);
			cout << "���������� ����Ǿ����ϴ�." << endl;
			cout << "------------------------------------------------" << endl;
			break;
		case 4:
			currentUser->change_major(input);
			cout << "���������� ����Ǿ����ϴ�." << endl;
			cout << "------------------------------------------------" << endl;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� Ȯ�����ּ���." << endl;
			cout << "------------------------------------------------" << endl;
	}
}

user* UserHandler::SearchUser(int id, char* password)
{
	for (int i = 0; i < num; i++)
		if ((userList[i]->get_ID() == id) && !(strcmp(userList[i]->get_password(), password)))		// �Էµ� ID�� ��й�ȣ�� ��ġ�ϴ� ����� ����ڰ� �ִ��� Ȯ�� 
			return userList[i];
	return NULL;
}

user* UserHandler::SearchUser(int id)
{
	for (int i = 0; i < num; i++)
		if (userList[i]->get_ID() == id)		// �Էµ� ID�� ��ġ�ϴ� ����� ����ڰ� �ִ��� Ȯ�� 
			return userList[i];
	return NULL;
}

UserHandler::~UserHandler(void)
{
	for (int i = 0; i < num; i++)
		delete userList[i];
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
	userhandler.AddUser();				// �ߺ��� ID�� �ִ� ��� �׽�Ʈ
	userhandler.ChangeUser();
	userhandler.ChangeUser();			// �ش� ����ڰ� ���� ��� �׽�Ʈ 
	return 0;
}
*/
