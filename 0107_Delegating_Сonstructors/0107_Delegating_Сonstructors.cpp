﻿// ****************************************************************************************************************
// Делегирующие конструкторы c++. Вызов конструктора из конструктора. ООП. С++ | Для начинающих. | Уроки C++ #107  
// ----------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ----------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// ****************************************************************************************************************

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*-----------------------------
*  Делегирующий конструктор
*-----------------------------*/

class Human
{
public:

	Human(string Name)												// Конструктор 1
	{
		this->Name = Name + "!";
		this->Age = 0;
		this->Weight = 0;
	}

	Human(string Name, int Age) : Human(Name)						// Конструктор 2 (делегирующий)
	{
		this->Age = Age;
	}

	Human(string Name, int Age, int Weight) : Human(Name, Age)		// Конструктор 3 (делегирующий)
	{
		this->Weight = Weight;
	}

	// С В О Й С Т В А

	string Name;
	int Age;
	int Weight;

};


/***********************
		  MAIN
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "____________________________________________________________\n" << endl;
	Human h("Аристарх", 30, 70);
	cout << "\tAGE = " << h.Age << endl;
	cout << "\tWEIGTH = " << h.Weight << endl;
	cout << "____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;

}