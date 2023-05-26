/**
* @file    GridMap.h
* @author  Keremcan Seker (1521 2020 1074)
* @brief    3B izgara tabanli harita olusturan sinif
*
*  Nokta veya nokta bulutunu degerleri belirlenmis kupe yerlestiren
*  ve dosya olarak kaydedebilen sinif
*
*/

#include "PointCloud.h"
#include "Map.h"
#include <vector>
#include <string>

//! GridMap sinifi
class GridMap : public Map
{
private:
	//! Haritanin kuplerini tutan 3B dizi
	std::vector<std::vector<std::vector<bool>>> map;
	// !Kuplerin kenar uzunlugu
	float gridSize;
	//! X, Y ve Z eksenleri dogrultusunda kup sayisi
	int depth;

public:
	GridMap() {}
	//! Constructor fonksiyonu, kuplerin kenar uzunlugunu ve X, Y, Z eksenleri dogrultusunda kup sayisini alir
	//! Ve haritada tum kuplerin degerlerini false olarak atar
	GridMap(float gridSize, int depth);

	//! Verilen nokta bulutundaki tum noktalari haritaya ekleyen fonksiyon
	void insertPointCloud(const PointCloud& pc);

	//! Verilen noktayi haritaya ekleyen fonksiyon
	void insertPoint(const Point& p);

	//! Haritanin belirli bir kupunun degerini donduren fonksiyon
	bool getGrid(int x, int y, int z) const;

	//! Verilen dosyadan haritayi okuyan ve yukleyen fonksiyon
	bool loadMap(const std::string& fileName);

	//! Haritayi verilen dosyaya kaydeden fonksiyon
	bool saveMap(const std::string& fileName);
};
