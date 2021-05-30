#include <iostream>
#include "UserHandler.h"

using namespace std;

UserHandler userManager;

user* login();
user* loginOrJoin();

int main(void)
{
	user* currentUser = NULL;
	
	while(currentUser == NULL)
		currentUser = loginOrJoin();
	
	/* �α��� �� ���α׷� ���� */ 
	
	return 0;
}

user* loginOrJoin(void)
{
	int select;
	user* currentUser;
	
	cout << "------------------------------------------------" << endl;
	cout << "�л� ���� �ý��ۿ� ���� ���� ȯ���մϴ�." << endl;
	cout << "������ ���͵帱���?" << endl;
	cout << "1. �α���" << endl;
	cout << "2. ȸ������" << endl;
	cout << "3. ���α׷� ����" << endl;
	cout << "����: ";
	cin >> select;
	
	switch(select)
	{
		case 1:
		{
			currentUser = login();
			
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
				return NULL;
			}
			cout << currentUser->get_name() << "��, ȯ���մϴ�." << endl;
			return currentUser;
		}
		case 2:
			userManager.AddUser();
			return NULL;
		case 3:
			exit(0);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� Ȯ�����ּ���." << endl;
			cout << "------------------------------------------------" << endl;
	}
	return NULL;
}

user* login(void)
{
	int id;
	char password[LEN];
	user* currentUser;
	
	cout << "------------------------------------------------" << endl;
	cout << "ID: ";
	cin >> id;
	cout << "��й�ȣ: ";
	cin >> password;
	
	currentUser = userManager.SearchUser(id, password);
	
	return currentUser;
}
