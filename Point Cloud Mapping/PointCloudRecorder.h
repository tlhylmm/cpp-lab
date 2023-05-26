/**
* @file    PointCloudRecorder.h
* @author  Baris Yirtinci (1521 2020 1025)
* @brief   PointCloud X,Y,Z,R,G,B noktalarini kaydeder.
*
* Almis oldugu PointCloud icerisinde bulunan X,Y,Z, R,G,B
* degerlerini fileName.txt icerisine kaydeder.
*/

#pragma once
#include <string>
#include "PointCloud.h"
using namespace std;

class PointCloudRecorder {
private:
	//! PointCloud X,Y,Z, R,G,B degerlerinin kaydedilecegi dosya adi.
	string fileName;
public:
	//! Varsayilan olusturucu.
	PointCloudRecorder() {};
	//! fileName' e direkt deger atamasi yapan olusturucu.
	PointCloudRecorder(string fileName);
	//! fileName' e deger atamasi yapar.
	void setFileName(string fileName);
	//! fileName degerini dondurur.
	string getFileName();
	//! PointCloud X,Y,Z,R,G,B noktalarini fileName.txt icerisine kaydeder.
	bool save(const PointCloud& pc);
};