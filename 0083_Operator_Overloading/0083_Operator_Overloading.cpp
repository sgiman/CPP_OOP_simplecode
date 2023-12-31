﻿//************************************************************************************************************
// Перегрузка операторов пример. ООП. Перегрузка оператора присваивания.  C++ Для начинающих.| Уроки C++ #83
// -----------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022
// -----------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//************************************************************************************************************
#include <iostream>
#include "utils.h"

using namespace std;

/*------------------------------
*	 перегрузка операторов
*------------------------------*/

class MyClass
{

private:
	int size;

public:
	int* data;

	/*---------------------
		  Constructor
	----------------------*/
	MyClass(int size)
	{
		this->size = size;				// размер
		this->data = new int[size];		// дин. массив

		for (int i = 0; i < size; i++)	// заполнить
		{
			data[i] = i;
		}
		cout << " Объект: " << data << " Вызвался конструктор" << " THIS: " << this << endl;
	}

	/*--------------------------------------
	   !!! (I) Конструктор копирования !!!
	 --------------------------------------*/
	 // this - указатель на текущий объект
	MyClass(const MyClass& other)				// параметер: константная ссылка на объект класса
	{
		this->size = other.size;				// копировать размер
		this->data = new int[other.size];		// копировать дин. массив
		for (int i = 0; i < other.size; i++)	// скопировать новый дин. массив
		{
			this->data[i] = other.data[i];
		}
		cout << " Вызвался конструктор копирования!!!" << " THIS: " << this << endl;
	}

	/*------------------------------------------------------------------------
	  !!! (II) Перегрузка оператора (возвращает ссылку на текущий объект) !!!
	-------------------------------------------------------------------------*/
	MyClass& operator = (const MyClass& other) // параметер: константная ссылка на объект класса
	{
		cout << " Вызвался оператор \"=\" " << this << endl;

		this->size = other.size;		// размер
		if (this->data != nullptr)		// если не пустой дин.массив - удалить
		{
			delete[] this->data;		// очистка дин.памяти (удаление ука )
		}

		// новый дин. массив
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		return *this;	// вернуть ссылку на текущий объект
	}

	/*------------------------------------------------------
						   Destructor
	  (не может принимать параметры и вызываться отдельно)
	-------------------------------------------------------*/
	~MyClass()
	{
		cout << " Объект: " << data << " Вызвался деструктор" << " THIS: " << this << endl;
		cout << endl;
		delete[] data; // очистить память от дин. массива
	}

};


/***********************
		  MAIN
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	cout << "\n____________________________________________________________\n" << endl;

	MyClass a(10);			// Новый дин. массив
	MyClass b(2);

	a.operator = (b);		// Перегрузка оператора присваивания 
	a = b;					// или сокращенно (для вызова метода "operаtor"), аналогично "a.присваивание(b)"	

	MyClass c(5);

	// c = a = b;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;				// Деструктор запукается, когда поиcходит выход из области видимости функции 

}
