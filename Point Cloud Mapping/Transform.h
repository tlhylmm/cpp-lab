/**
* @file    Transform.h
* @author  Talha Yilmam (1521 2021 1114)
* @brief   Donusumleri uygulayan sinif
*
* Rotasyon matrixi, Translasyon matrixi veya aci degerleri gibi
* parametreleri kullanarak 4x4'luk donusum matrixini uretir ve
* bu matrixi kullanarak donusturulmus yeni PointCloud yaratir.
*/

#pragma once
#include "PointCloud.h"
#include <iostream>
#include <Eigen/Dense>

//! Donusturucu sinifi
/*! PointCloud'dan cesitli fonksiyonlari miras alan Donusturucu sinifi*/
class Transform : public PointCloud
{
private:
	//! Acilari tutan 3x1 vektor
	Eigen::Vector3d angles;
	//! Translasyon degerlerini tutan 3x1 vektor
	Eigen::Vector3d trans;
public:
	//! 4x4 donusum matrixi
	Eigen::Matrix4d transMatrix;
	//! Default constructor
	Transform();
	//! Acilari ayarlar
	void setAngles(double angle_1, double angle_2, double angle_3);
	//! Acilardan rotasyon matrisini olusturur
	void setRotationByAngle(Eigen::Vector3d ang);
	//! Rotasyon matrisini olusturur
	void setRotation(Eigen::Matrix3d ang);
	//! Translasyon matrisini olusturur
	void setTranslation(Eigen::Vector3d tr);
	//! Noktaya donusum uygular
	Point doTransform(Point p);
	//! PointCloud'a donusum uygular
	PointCloud doTransform(PointCloud& pc);
};
