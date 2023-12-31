﻿//*******************************************************************************************************
// Ключевое слово this в ООП. Что означает. Что это такое. Для чего нужен this указатель | Уроки C++ #81
// ------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//*******************************************************************************************************
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*-------------------------
 * Ключевое слово this
 *------------------------*/

 // --- CLASS POINT --- 

class Point {
private:			// ....шаблон сингл-тон (конструктор) - необязательное ключевое слово  
	int x;
	int y;

public:

	// Конcтруктор по умолчанию 
	Point()
	{
		cout << this << " constructor 1" << endl;
	}

	// --- Constructor ---
	// Конcтруктор вызывается сам, когда создаётся объект класса
	// (функция которая не вызывается и ничего не вовзращает)
	Point(int x, int y)	// перегрузка констркутора 
	{
		this->x = x;
		this->y = y;
		cout << this << " constructor 2" << endl;	// this - указтель (адрес) для каждого объекта класса
	}

	// --- Getters-Stters ---
	int GetX()			// GET X	
	{
		return this->x;
	}
	int GetY()			// GEY Y
	{
		return this->y;
	}
	void SetX(int x)		// SET X
	{
		this->x = x;
	}
	void SetY(int y)		// SET Y
	{
		this->y = y;
	}

	// --- Method ---
	void Print()			// публичный метод 	
	{
		cout << " X = " << x << "\t Y =  " << y << endl << endl;
	}

};


/***********************
	  === MAIN ===
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	Point p1;
	Point p2(11, 22);

	cout << "\n____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}
