/*
* @file    GridMap.h
* @author  Keremcan Seker (1521 2020 1074)
* @brief   PointCloud uretilmesi icin soyut sinif
*
*  Dosyadan PointCloud olusturan veya donusum uygulayarak PointCloud olusturan
*	soyut sinif
*
*/

#pragma once
#include "Transform.h"
#include <string>
using namespace std;

//! PointCloud ureten soyut sinif
class PointCloudGenerator {
private:
	//! Donusturucu nesne
	Transform transform;
public:
	//! Default constructor
	PointCloudGenerator() {};
	//! Rotasyon ve Translasyon matrixleriyle 4x4 donusum matrixi ureten constructor
	PointCloudGenerator(Eigen::Matrix3d rotation, Eigen::Vector3d translation);
	//! Transform nesnesini dondurur
	Transform getTransform();
	//! (Soyut Fonksiyon) Verilen isimdeki dosyadan PointCloud yaratir
	virtual PointCloud capture(PointCloud& pc, string fileName) = 0;
	//! (Soyut Fonksiyon) Verilen isimdeki dosyadan donusturulmus PointCloud yaratir
	virtual PointCloud captureFor(PointCloud& pc, string fileName) = 0;
	//!	(Soyut Fonksiyon) Dosya adini dondurur
	virtual string getFile() = 0;
};