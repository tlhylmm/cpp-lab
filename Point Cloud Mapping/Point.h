/**
* @file    Point.h
* @author  Ahmet Albayrak (1521 2020 1076)
* @brief   Noktalarin koordinatlarini ve R G B degerlerini iceren nokta sinifi.
*
*/
#pragma once


//! Point Sinifi
//! Noktalari set eden ve get eden fonksiyon parametrelerinin bulundugu sinif.
class Point
{
private:
	//! Nokta ekseni
	double x, y, z;//point axis
	int r, g, b;

public:
	//! Default constructor
	Point();
	//! Point(double x, double y, double z);
	Point(double x, double y, double z, int r, int g, int b);
	//! Copy consturctor
	Point(const Point& p1);

	//! setters
	void setPoint(double x, double y, double z);
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	//! R G B degerlerini set eden fonksiyonlar.
	void setR(int r);
	void setG(int g);
	void setB(int b);

	//! getters
	Point* getPoint();
	double getX() const;
	double getY() const;
	double getZ() const;
	//! R G B degerlerini get eden fonksiyonlar.
	int getR() const;
	int getG() const;
	int getB() const;

	//! \param point iki noktanin birbirine esit olup olmadigini kontrol eder.
	bool operator==(Point point);
	//! \param constPoint iki nokta arasindaki uzakligi hesaplar.
	double distance(const Point&)const;
};

