#include <iostream>
#include <cstring>
#include "User.h"

class UserHandler
{
private:
	user* userList[200];						// ����� ���� �迭 
	int num;									// ����� ���� ���� ��
	
	bool CheckUser(int id);						// id�� ����� ����ڰ� �ִ��� üũ�Ͽ� ��ȯ, AddUser���� ���� 
public:
	UserHandler() : num(0) {};
	void AddUser(void);							// ȸ������ �� ȣ��
	void ChangeUser(void);						// ����� ���� ����
	user* SearchUser(int id, char* password);	// �ش� ID�� ��й�ȣ�� ���� ����ڸ� ��ȯ 
	user* SearchUser(int id);					// �ش� ID�� ���� ����ڸ� ��ȯ 
	~UserHandler();
};
