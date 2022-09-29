#include <iostream>
#include "globalFile.h"
#include "identity.h"
#include <fstream>
#include <string>
#include "Student.cpp"
#include "Manager.cpp"
#include "Teacher.cpp"

using namespace std;


// 管理菜单
// Identity * 表示指针类型
// &manager 引用实参 可以直接操纵实参的值
void managerMenu(Identity *&manager)
{

    while (true)
    {
        //管理员菜单
        manager->operMenu();

        Manager *man = (Manager *)manager;
        int select = 0;

        cin >> select;

        if (select == 1) //添加账号
        {
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2) //查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3) //查看机房
        {
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if (select == 4) //清空预约
        {
            cout << "清空预约" << endl;
            man->cleanFile();
        }
        else
        {
            delete manager;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void LoginIn(string fileName, int type)
{
    // 指针类型 存储new的成员
    Identity *person = NULL;
    ifstream ifs;
    ifs.open(fileName, ios::in); // ios是读取方式  in是读取进来 out是写出去

    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)
    {
        // 学生登录
        std::cout << "/* id */" << std::endl;
        cin >> id;
    }
    else if (type == 2)
    {
        // 教师登录
        std::cout << "/* id */" << std::endl;
        cin >> id;
    }
    
    std::cout << "/* 姓名 */" << std::endl;
    cin >> name;

    std::cout << "/* 密码 */" << std::endl;
    cin >> pwd;

    if (type == 1)
    {
        //学生登录验证
        int fId;
        string fName;
        string fPwd;

        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                std::cout << "学生验证登录成功" << std::endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                return;
            }
        }
    }
    else if (type == 2)
    {
        //教师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "教师验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                return;
            }
        }
    }
    else if (type == 3)
    {
        //管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                cout << "验证登录成功!" << endl;
                //登录成功后，按任意键进入管理员界面
                system("pause");
                system("cls");
                //创建管理员对象
                person = new Manager(name, pwd);
                
                managerMenu(person);

                return;
            }
        }
    }

    cout << "验证登录失败!" << endl;
    system("pause");
    system("cls");
    return;
}



int main()
{

    int select = 0;

    while (true)
    {

        cout << "======================  欢迎来到传智播客机房预约系统  ====================="
             << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";
        cin >> select; //接受用户选择

        switch (select)
        {
        case 1: //学生身份
            // LoginIn();
            LoginIn(STUDENT_FILE,select);
            break;
        case 2: //老师身份
            LoginIn(TEACHER_FILE,select);
            break;
        case 3: //管理员身份
            LoginIn(ADMIN_FILE,select);
            break;
        case 0: //退出系统
            cout << "欢迎下一次使用" << endl;
            system("pause");
            break;
        default:
            cout << "输入有误，请重新选择！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");

    return 0;
}