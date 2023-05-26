/**
* @file    DepthCamera.h
* @author  Talha Yilmam (1521 2021 1114)
* @brief   Text dosyalarindan PointCloud yaratir
*
* Farkli noktalara koyulmus kameralarin bakis acisindan elde edilmis koordinatlari
* uzerinde islemler yaparak veya islem yapmadan PointCloud nesnesine donusturur
*/

#pragma once
#include <string>
#include "PointCloud.h"
#include "PointCloudGenerator.h"

using namespace std;

//! Derinlik Kamerasi Sinifi
/*! PointCloudGenerator'den cesitli fonksiyonlari miras alan Derinlik Kamerasi sinifi*/
class DepthCamera : public PointCloudGenerator
{
private:
	//! Dosya adini tutan string
	string fileName;
public:
	//! Default constructor
	DepthCamera() {}
	//! 4x4'luk donusum matrisini ve dosya adini ayarlayan constructor
	DepthCamera(Eigen::Matrix3d rotation, Eigen::Vector3d translation, string fileName);
	//! Dosya adini degistirir
	void setFile(string fileName);
	//! Dosyanin adini dondurur
	string getFile();
	//! Verilen addaki dosyadan PointCloud uretir
	PointCloud capture(PointCloud& pc, string fileName);
	//! Verilen addaki dosyadan noktalari alir ve donusum uygulayarak PointCloud uretir
	PointCloud captureFor(PointCloud& pc, string fileName);
};