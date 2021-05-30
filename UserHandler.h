#pragma once
#include <iostream>
#include <cstring>
#include "User.h"

class UserHandler
{
private:
	user* userList[200];						// 사용자 저장 배열 
	int num;									// 사용자 정보 저장 수

	bool CheckUser(int id);						// id의 저장된 사용자가 있는지 체크하여 반환, AddUser에서 사용됨 
public:
	UserHandler() : num(0) {};
	void AddUser(void);							// 회원가입 시 호출
	void ChangeUser(user* curUser);						// 사용자 정보 변경
	user* SearchUser(int id, char* password);	// 해당 ID와 비밀번호를 가진 사용자를 반환 
	user* SearchUser(int id);					// 해당 ID를 가진 사용자를 반환 
	~UserHandler();
};
