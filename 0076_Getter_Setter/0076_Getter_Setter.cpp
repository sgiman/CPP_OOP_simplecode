﻿//**************************************************************************************************
// Методы класса. Что такое методы в программировании.Вызов метода класса.Функции. | Уроки C++ #76
// -------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// -------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
//
// 2019-2023 @ sgiman
//**************************************************************************************************
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*----------------------------------
 *	гетеры и сетеры
 *	инкапсуляция
 *
 *  данные отделены от методов
 *--------------------------------*/

 // --- Getters & Setters ---
class Point {

	//----------------------------------------- 
	//	Д А Н Н Ы Е: поля или свойства класса
	//----------------------------------------- 
private:
	int x = 0;
	int y = 0;

public:
	int px = 0;
	int py = 0;

	int GetX()					// GETTER !	для поля X	
	{
		return this->x;			// вернуть значене "x"
	}

	//------------------------------------- 
	//    С Е Т О Р Ы  и  Г Е Т О Р Ы
	//------------------------------------- 

		//void SetX(int valueX)		// SETTER ! параметер "valuaX" не должен быть "x" из области доступа private - для поля X 
	void SetX(int x)
	{
		this->x = x;			// уcтановить "x" (через указатель this)
	}

	int GetY()					// GETTER !	для поля Y	
	{
		return this->y;			// вернуть "y" (через указатель this)
	}

	// void SetY(int valueY)	// SETTER ! для поля Y
	void SetY(int y)
	{
		this->y = y * 2;		// уcтановить и модифицировать y
	}

	//-------------------- 
	//    М Е Т О Д Ы
	//-------------------- 
	void Print()				// публичный метод 	
	{
		cout << "\n Print(): \n" << " X = " << x << "\t Y =  " << this->y << endl;
		cout << " px = " << this->px << "\t py= " << py << endl << endl;
	}

};


/***********************
	  === MAIN ===
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	Point a;					// Объект "a" класса "Point"

	a.SetX(5);					// Установить переменную в объекте "a" класса "Point"
	a.SetY(11);
	a.Print();					// Вывод результата 

	cout << " a.GetY() = " << a.GetY() << endl;

	cout << "\n____________________________________________________________\n" << endl;

	a.px = 100;
	a.py = 200;
	a.Print();

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}
