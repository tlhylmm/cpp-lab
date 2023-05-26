#include "Point.h"
#include <math.h>

//! Constructor fonksiyonu x,y,z,r,g,b parametrelerinin ilk degerlerini 0 olarak ayarlar.
Point::Point()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

/*Point::Point(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->r = 0;
	this->g = 0;
	this->b = 0;
}*/

/*!
* \param x
* \param y
* \param z
* \param r
* \param g
* \param b
*  noktaya ait butun degerleri parametre olarak alip atayan consturctor.
*/
Point::Point(double x, double y, double z, int r, int g, int b) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->r = r;
	this->g = g;
	this->b = b;
}

//! \param p1 verilmis bi noktadan ayni degerlere sahip baska nokta olusturur.
Point::Point(const Point& p1) {
	this->x = p1.getX();
	this->y = p1.getY();
	this->z = p1.getZ();
	this->r = p1.getR();
	this->g = p1.getG();
	this->b = p1.getB();
}

/*!
* \param _x
* \param _y
* \param _z
*
*/
void Point::setPoint(double _x = 0, double _y = 0, double _z = 0)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

//! \param x x koordinati
void Point::setX(double x)
{
	this->x = x;
}

//! \param y y koordinati
void Point::setY(double y)
{
	this->y = y;
}

//! \param z z koordinati
void Point::setZ(double z)
{
	this->z = z;
}

//! \param r kirmizi
void Point::setR(int r) {
	this->r = r;
}

//! \param g yesil
void Point::setG(int g) {
	this->g = g;
}

//! \param b mavi
void Point::setB(int b) {
	this->b = b;
}

/*!
* \return getPoint getpointi return eder.
*/
Point* Point::getPoint()
{
	return this;
}

//! \return getX x'i return eder.
double Point::getX() const
{
	return this->x;
}

//! \return getY y'yi return eder.
double Point::getY() const
{
	return this->y;
}

//!  \return getZ z'yi return eder.
double Point::getZ() const
{
	return this->z;
}

//! \getR r'yi return eder.
int Point::getR() const {
	return this->r;
}

//! \return getG g'yi return eder.
int Point::getG() const {
	return this->g;
}

//! \return getB b'yi return eder.
int Point::getB() const {
	return this->b;
}

//! \return bool true yada false return eder.
bool Point::operator==(Point point)
{
	if (this->x == point.x && this->y == point.y && this->z == point.z) {
		return true;
	}return false;
}

//! \return distance noktalar arasi mesafeyi return eder.
double Point::distance(const Point& inp)const
{
	double distance;
	distance = sqrt(pow((this->x - inp.x), 2) + pow((this->y - inp.y), 2) + pow((this->z - inp.z), 2));
	return distance;
}
