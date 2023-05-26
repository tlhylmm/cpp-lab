#include "Transform.h"
#include <cmath>
#include <iostream>
#include <Eigen/Dense>

//default constructor
Transform::Transform()
{
	for (int i = 0; i < 3; i++) {
		this->angles(i) = 0;
		this->trans(i) = 0;
	}
}

/*!
	\param angle_1 aci 1
	\param angle_2 aci 2
	\param angle_3 aci 3
*/
void Transform::setAngles(double angle_1, double angle_2, double angle_3)
{
	this->angles(0) = angle_1;
	this->angles(1) = angle_2;
	this->angles(2) = angle_3;

	//after changing the angles,
	//transMatrix also needs to be recalculated.
	//so we call setRotation() with updated angles:

	this->setRotationByAngle(this->angles);
}

/*!
	\param ang Acilari iceren 3x1 vektor
*/
void Transform::setRotationByAngle(Eigen::Vector3d ang) {
	this->angles(0) = ang(0);
	this->angles(1) = ang(1);
	this->angles(2) = ang(2);

	double c1 = cos(angles(0));
	double c2 = cos(angles(1));
	double c3 = cos(angles(2));
	double s1 = sin(angles(0));
	double s2 = sin(angles(1));
	double s3 = sin(angles(2));

	transMatrix(0, 0) = c2 * c3;
	transMatrix(0, 1) = -c2 * s3;
	transMatrix(0, 2) = s2;
	transMatrix(0, 3) = this->trans[0];
	transMatrix(1, 0) = c1 * s3 + c3 * s1 * s2;
	transMatrix(1, 1) = c1 * c3 - s1 * s2 * s3;
	transMatrix(1, 2) = -c2 * s1;
	transMatrix(1, 3) = this->trans[1];
	transMatrix(2, 0) = s1 * s3 - c1 * c3 * s2;
	transMatrix(2, 1) = c3 * s1 + c1 * s2 * s3;
	transMatrix(2, 2) = c1 * c2;
	transMatrix(2, 3) = this->trans[2];
	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;
	transMatrix(3, 3) = 1;

}

/*!
	\param ang 3x3 Rotasyon matrisi
*/
void Transform::setRotation(Eigen::Matrix3d ang) {
	this->transMatrix(0, 0) = ang(0, 0);
	this->transMatrix(0, 1) = ang(0, 1);
	this->transMatrix(0, 2) = ang(0, 2);
	this->transMatrix(1, 0) = ang(1, 0);
	this->transMatrix(1, 1) = ang(1, 1);
	this->transMatrix(1, 2) = ang(1, 2);
	this->transMatrix(2, 0) = ang(2, 0);
	this->transMatrix(2, 1) = ang(2, 1);
	this->transMatrix(2, 2) = ang(2, 2);

	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
}

/*!
	\param tr 3x1 Translasyon matrixi
*/
void Transform::setTranslation(Eigen::Vector3d tr) {
	this->trans(0) = tr(0);
	this->trans(1) = tr(1);
	this->trans(2) = tr(2);

	//after changing the translation matrix,
	//transMatrix also needs to be updated with
	//new values. so we also change the corresponding
	//elements:

	this->transMatrix(0, 3) = tr(0);
	this->transMatrix(1, 3) = tr(1);
	this->transMatrix(2, 3) = tr(2);

	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
}

/*!
	\param p Point
	\return Donusturulmus nokta
*/
Point Transform::doTransform(Point p) {
	Eigen::Vector4d v;
	v(0) = p.getX();
	v(1) = p.getY();
	v(2) = p.getZ();
	v(3) = 1;

	v = transMatrix * v;
	return Point(v(0), v(1), v(2), p.getR(), p.getG(), p.getB());
}

/*!
	\param pc PointCLoud
	\return Donusturulmus nokta bulutu
*/
PointCloud Transform::doTransform(PointCloud& pc) {
	PointCloud temp = pc;
	pc.emptyCloud();
	int pointNumber = temp.getPointNumber();
	for (int i = 0; i < pointNumber; i++) {
		pc.insertPoint(doTransform(temp.getPoints(i)));
	}
	return pc;
}