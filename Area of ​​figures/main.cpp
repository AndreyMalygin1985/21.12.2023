#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <vector>

using namespace std;

// Создать абстрактный базовый класс с виртуальной функцией — площадь.
// Создать производные классы: прямоугольник, круг, прямоугольный треугольник,
// трапеция со своими функциями площади Для проверки определить массив ссылок
// на абстрактный класс, которым присваиваются адреса различных объектов.
// Площадь трапеции : S = (a + b)h / 2

class Figure {
public:
	virtual double square() const = 0;
};

class Rectanglle : public Figure {
	double width;
	double height;

public:
	Rectanglle(double w, double h) : width(w), height(h) {}

	double square() const override {
		return width * height;
	}
};

class Circle : public Figure {
	double radius;

public:
	Circle(double r) : radius(r) {}

	double square() const override {
		return M_PI * radius * radius;
	}
};

class RightTriangle : public Figure {
	double base;
	double height;

public:
	RightTriangle(double b, double h) : base(b), height(h) {}

	double square() const override {
		return 0.5 * base * height;
	}
};

class Trapezoid : public Figure {
	double a;
	double b;
	double height;

public:
	Trapezoid(double a, double b, double h) : a(a), b(b), height(h) {}

	double square() const override {
		return 0.5 * (a + b) * height;
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	Rectanglle rect(13, 5);
	Circle circle(10);
	RightTriangle triangle(7, 4);
	Trapezoid trapezoid(5, 4, 3);

	vector<Figure*> figures = { &rect, &circle, &triangle, &trapezoid };

	for (const auto& figure : figures) {
		if (dynamic_cast<Rectanglle*>(figure)) {
			cout << "Площадь прямоугольника = " << figure->square() << endl;
		}
		else if (dynamic_cast<Circle*>(figure)) {
			cout << "Площадь круга = " << figure->square() << endl;
		}
		else if (dynamic_cast<RightTriangle*>(figure)) {
			cout << "Площадь прямоугольного треугольника = " << figure->square() << endl;
		}
		else if (dynamic_cast<Trapezoid*>(figure)) {
			cout << "Площадь трапеции = " << figure->square() << endl;
		}
	}

	return 0;
}