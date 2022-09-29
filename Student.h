#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
class Student : public Identity
{
private:
    /* data */
public:
    Student(/* args */);
    //有参构造(学号、姓名、密码)
    Student(int id, string name, string pwd);
    //菜单界面
    virtual void operMenu();
    //申请预约
    void applyOrder();
    //查看我的预约
    void showMyOrder();
    //查看所有预约
    void showAllOrder();
    //取消预约
    void cancelOrder();
    //学生学号
	int m_Id;
    ~Student();
};


