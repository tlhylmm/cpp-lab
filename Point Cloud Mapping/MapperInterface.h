/**
* @file    PointCloud.h
* @author  Esma Kocak 152120211058
* @brief   Cesitli nesnelere erisimi kolaylastiran sinif
*
* Cesitli siniflardan olusturulmus nesneleri tutan ve bunlarin birbiriyle etkilesimini
* kullanici icin kolaylastiran arayuz sinifi
*
*/

#pragma once

#include "PointCloudRecorder.h"
#include "PointCloudGenerator.h"
#include "Map.h"
#include <vector>


//! Erisimi kolaylastirici arayuz sinifi
class MapperInterface {
private:
	//! Tum noktalarin tutuldugu nokta bulutu
	PointCloud pointCloud;
	PointCloud patch;
	//! Ust sinifi PointCloudGenerator olan DepthCamera'larin tutuldugu vektor
	std::vector<PointCloudGenerator*> generators;
	//! Kaydedici nesne
	PointCloudRecorder* recorder;
	//! GridMap ust sinifi
	Map* map;
public:
	//! default constructor
	MapperInterface() {};
	//! Vektore PointCloudGenerator'un alt siniflarindan birini ekler
	void addGenerator(PointCloudGenerator*);
	//! Recorder nesnesini ayarlar
	void setRecorder(PointCloudRecorder*);
	//! Ust sinifi Map olan GridMap'i ayarlar
	void setMap(Map*);
	//! Tum PointCloudGenerator'lardan tek bir nokta bulutu yaratir
	bool generate();
	//! Nokta bulutunu dosyaya kaydeder
	bool recordPointCloud();
	//! GridMap'i dosyaya kaydeder
	bool recordMap();
	//! Nokta bulutunu haritaya yerlestirir
	bool insertMap();
};