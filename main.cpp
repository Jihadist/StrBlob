// StrBlob.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "StrBlob.h"
#include <iostream>
#include <memory>
#include "StrBlobPtr.h"

std::vector<int> *returner()
{
	std::vector<int> *p = new std::vector<int>;

	return p;
}

std::shared_ptr<std::vector<int>> returnerS()
{
	return std::make_shared<std::vector<int>>();
}

std::vector<int> *read(std::vector<int> *s)
{
	*s = { 1,2,3,4,5,6,7,8,9 };
	return s;
}

std::shared_ptr<std::vector<int>> read(std::shared_ptr<std::vector<int>> s)
{
	*s = { 1,2,3,4,5,6,7,8,9 };
	return s;
}

void write(std::vector<int> *p)
{
	std::for_each(p->cbegin(), p->cend(), [](const int &s) {std::cout << " " << s; });
	std::cout << std::endl;
}

void write(std::shared_ptr<std::vector<int>> p)
{
	std::for_each(p->cbegin(), p->cend(), [](const int &s) {std::cout << " " << s; });
	std::cout << std::endl;
}
// Напишите функцию, которая возвращает динамические созданный вектор чисел.
// Передайте этот вектор другой функции, которая читет значение его элементов 
// со стандартного устройства ввода. Передайте вектор другой функции,
// выводящей прочитанные ранее значения.
// Не забудьте удалить вектор в подходящий момент.
void Exp12_6()
{
	// первая версия использует new и delete
	auto vec = read(returner());
	write(vec);
	std::cout << std::endl;
	// вторая версия использует перегруженные версии функций и shared_ptr
	std::shared_ptr<std::vector<int>> vec2 = read(returnerS());
	write(vec2);
	delete vec;
}

void process(std::shared_ptr<int> ptr)
{
	(*ptr)++;
}

int test()
{
	std::vector<std::string> test;
	std::cout << "Counter =" << test.size();
	auto p1 = new auto(10);
	auto p2 = new auto(1.34567898765456787654);
	auto p3 = new auto("test");
	auto p4 = new auto('test');
	std::cout << std::endl << *p1 << " " << *p2 << " " << *p3 << " " << *p4;

	//Exp12_6();
	//std::shared_ptr<int> p(new int(42));
	//process(std::shared_ptr<int>(p));

	auto p = new int();
	auto sp = std::make_shared<int>();
	process(sp);
	//process(new int());
	//process(p);
	process(std::shared_ptr<int>(p));

	auto pp = sp.get();
	//delete pp;
	//std::unique_ptr<int> up1;
	//up1.release();
	//auto up2 = up1.release();
	//delete(up2);

	//up2.reset();

	// Упражнение 12.16 и 12.17
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef std::unique_ptr<int> IntP;
	//IntP up0(ix);
	//IntP up1=std::make_unique<int>(*p1); ошибка
	//IntP up2(pi2); ошибка
	//IntP up3(&ix);
	IntP up4(new int(2048));
	//IntP up5(up2.get());


	//

	auto sp1 = std::make_shared<int>(12);
	return 0;
}

void compare(const StrBlob& lhs, const StrBlob& rhs)
{
	if (lhs == rhs)
		std::cout << "Equality ";
	else
		if (lhs != rhs)
		{
			std::cout << "Not equality ";
			if (lhs < rhs)
				std::cout << "Lesser ";
			if (lhs > rhs)
				std::cout << "Greater ";
		}
}

void pointer()
{
	StrBlob test1;
	test1.push_back("hello");
	StrBlob test2;
	test2.push_back("hello");
	StrBlobPtr test11(test1);
	StrBlobPtr test12(test1);
	StrBlobPtr test21(test2);
	if (test11 == test12)
		std::cout << "a";
	if (test11 == test21)
		std::cout << "b\n";
	test11++;
	++test12;
}


int main()
{
	std::cout << "Hello World!\n";
	StrBlob test1;
	test1.push_back("hell");
	StrBlob test2;
	test2.push_back("hello");
	if (test1 == test2)
		std::cout << "test1 equal to test2";
	std::cout << test1.front();

	StrBlob LessTest1;
	LessTest1.push_back("hell");
	StrBlob LessTest2;
	LessTest2.push_back("hello");
	compare(LessTest1, LessTest2);
	std::cout << LessTest1[0];
	pointer();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
