﻿//***************************************************************************************************************
// Перегрузка оператора равенства == и не равно !=. Перегрузка логических операторов сравнения.| Уроки C++ #84  
// --------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// --------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//***************************************************************************************************************
#include <iostream>
#include "utils.h"

using namespace std;

/*--------------------------------------
 *	 перегрузка операторов  == и !=
 *-------------------------------------*/

class Point {

private:
	int x;
	int y;

public:

	// --- КОНСТРУКТОРЫ ---

	Point() // Конcтруктор по умолчанию (инициализация данных)
	{
		x = 0;
		y = 0;
	}

	Point(int x, int y)	// Второй конcтруктор c парметрами (не вызывается извне) для перезагрузки 
	{
		this->x = x;	// Для VS2017  - this.x (в случае одинаковых имен)
		this->y = y;	// Для VS2017  - this.y (в случае одинаковых имен)
	}

	Point(int valueX, bool boolean) // Третий конструктор (bool)
	{
		x = valueX;

		if (boolean)
		{
			y = 1;
		}
		else
		{
			y = -1;
		}
	}

	// --- СЕТЕРЫ-ГЕТЕРЫ ---

	int GetX()						// GETTER !	для поля X 	
	{
		return x;					// вернуть значене "x"
	}

	void SetX(int valueX)			// SETTER ! параметер "valuaX" не должен быть "x" из области доступа private - для поля X 
	{
		x = valueX;					// уcтановить "x"
	}

	int GetY()						// GETTER !	для поля Y	
	{
		return y;
	}

	void SetY(int valueY)			// SETTER ! для поля Y
	{
		y = valueY;
	}

	// --- МЕТОДЫ ---

	void Print()					// публичный метод 	
	{
		cout << " X = " << x << "\t Y =  " << y << endl << endl;
	}

	/*-----------------------------------------------
	  Перегрузка операторов сравнения ("==" и "!=")
	------------------------------------------------*/

	// --- Перегрузка (==) ---
	bool operator == (const Point& other)
	{
		/*
		if (this->x == other.x && this->y == other.y)
		{
			return true;
		}
		else
		{
			return false;
		}
		*/
		return (this->x == other.x) && (this->y == other.y);
	}

	// --- Перегрузка (!=) --- 
	bool operator != (const Point& other)
	{
		return !((this->x == other.x) && (this->y == other.y));
	}

};


/***********************
	  === MAIN ===
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	cout << "\n____________________________________________________________\n" << endl;

	Point a(5, 1);
	Point b(9, 4);

	/*--------------------------------------
	// излишний и не оптимальный код !!!
	if (a == b)
	{
	result = true;
	}
	else
	{
	result = false;
	}
	----------------------------------------*/

	// оптимальный код
	bool result1 = (a == b);					// "равно"
	cout << " RESULT1 (a == b): " << result1 << endl;

	bool result2 = (a != b);					// "не равно"
	cout << " RESULT2 (a != b): " << result2 << endl;


	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;									// Деструктор запукается, когда поиcходит выход из области видимости функции 

}