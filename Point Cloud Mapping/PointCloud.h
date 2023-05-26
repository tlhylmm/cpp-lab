/*
* @file    PointCloud.h
* @author  Esma Kocak 152120211058
* @brief   Nokta bulutunu olusturulan noktalari bir vektorde tutar.
*
* Kameralardan elde edilen noktalari, bir vektorde tutarak nokta bulutu PointCloud olusturur.
*
*/

#pragma once
#include "Point.h"
#include <vector>

class PointCloud : public Point
{
private:
	//! noktalarin tutuldugu vektor
	std::vector<Point> points;
public:

	//! default constructor
	PointCloud();

	//! verilen nokta vektorunu atar
	void setPoints(std::vector<Point> newPoints);

	//! bir indexteki noktayi dondurur
	const Point getPoints(int index) const;
	//! buluttaki nokta sayisini dondurur
	int getPointNumber() const;
	//! noktalarin bulundugu vektoru dondurur
	std::vector<Point> getVector() const;

	//! insert point fonksiyonu, nokta bulutuna, nokta ekler
	void insertPoint(Point p);
	//! bulutun icerigini siler
	void emptyCloud();

	//! + operator overload
	PointCloud operator+(const PointCloud& pc);
	//! = operator overload
	const PointCloud& operator=(const PointCloud& pc);

};