#include "manager.h"




//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	initVector();
}

//选择菜单
void Manager::operMenu()
{
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
    
}

//添加账号  
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if(select == 1){
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
	}else{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
	}

	ofs.open(fileName,ios::out | ios::app);
	int id;
	string name;
	string pwd;
	
	std::cout << tip << std::endl;
	cin >> id;

	std::cout << "请输入姓名：" << std::endl;
	cin >> name;
	std::cout << "请输入密码：" << std::endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	std::cout << "添加成功" << std::endl;
	
	system("pause");
	system("cls");
	
	ofs.close();

}

//查看账号
void Manager::showPerson()
{
}

//查看机房信息
void Manager::showComputer()
{
}

//清空预约记录
void Manager::cleanFile()
{
}

void Manager::initVector()
{
	// 读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE,ios::in);
	if(!ifs.is_open())
	{
		std::cout << "文件读取失败" << std::endl;
		return;
	}
}