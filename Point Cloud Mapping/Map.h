/**
* @file    Map.h
* @author  Ahmmet Albayrak (1521 2020 1076)
* @brief   Grid map icin temel fonksiyon taslaklarini iceren soyut sinif.
*
*/
#pragma once
#include "PointCloud.h"
#include <string>
using namespace std;
//! Map sinifi
class Map {
public:
	//! Default constructor
	Map() {};
	//! /param pc point cloudu haritaya yerlestirir.
	virtual void insertPointCloud(const PointCloud& pc) = 0;
	//! /param p noktayi haritaya yerlestirir.
	virtual void insertPoint(const Point& p) = 0;
	//! param fileName haritayi yukler.
	virtual bool loadMap(const string& fileName) = 0;
	//! param fileName haritayi kaydeder.
	virtual bool saveMap(const string& fileName) = 0;
};