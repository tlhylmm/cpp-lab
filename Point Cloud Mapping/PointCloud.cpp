#include "PointCloud.h"
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

PointCloud::PointCloud()
{
}

/*!
*  \param newPoints nokta bulutu
*/
void PointCloud::setPoints(std::vector<Point> newPoints)
{
	this->points.clear();
	this->points = newPoints;
}

/*!
*  \param index index
*	\return verilen indexteki nokta
*/
const Point PointCloud::getPoints(int index) const
{
	return this->points[index];
}

/*!
*  \return nokta bulutu
*/
std::vector<Point> PointCloud::getVector() const
{
	return points;
}

/*!
*  \return nokta bulutunun boyutu
*/
int PointCloud::getPointNumber() const
{
	return this->points.size();
}

/*!
*  \param p nokta
*/
void PointCloud::insertPoint(Point p)
{
	this->points.push_back(p);
}

void PointCloud::emptyCloud() {
	this->points.clear();
}

/*!
*  \param pc
*  \return sum of Point clouds
*/
PointCloud PointCloud::operator+(const PointCloud& pc)
{
	PointCloud sumPC;
	sumPC = *this;

	std::vector<Point> temp = pc.getVector();
	int size = pc.getPointNumber();
	for (int i = 0; i < size; i++)
	{
		sumPC.insertPoint(temp[i]);
	}

	return sumPC;
}

/*!
*  \param pc
*  \return copy of pc
*/
const PointCloud& PointCloud::operator=(const PointCloud& pc)
{
	std::vector<Point> temp = pc.getVector();

	if (&pc != this)
	{
		points.clear();
		int size = pc.getPointNumber();
		for (int i = 0; i < size; i++)
		{
			this->insertPoint(temp[i]);
		}
	}

	return *this;
}
