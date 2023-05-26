
#include "GridMap.h"
#include <fstream>

/*!
* \param gridSize kuplerin kenar uzunlugu
* \param depth xyz ekseni dogrultusundaki kup sayisi
* \return Gridmap
*/

// Constructor fonksiyonu, kuplerin kenar uzunlugunu ve X, Y, Z eksenleri dogrultusunda kup sayisini alir
// Ve haritada tum kuplerin degerlerini false olarak atar
GridMap::GridMap(float gridSize, int depth) : gridSize(gridSize), depth(depth)
{
	// 3B dizi olusturulur ve tum kuplerin degerleri false atanir
	map.resize(depth);
	for (int i = 0; i < depth; i++)
	{
		map[i].resize(depth);
		for (int j = 0; j < depth; j++)
			map[i][j].resize(depth, false);
	}
}

/*!
* \param pc PointCloud
*/

// Verilen nokta bulutundaki tum noktalari haritaya ekleyen fonksiyon
void GridMap::insertPointCloud(const PointCloud& pc)
{
	// Nokta bulutundaki tum noktalar gezilir ve haritaya eklenir
	for (int i = 0; i < pc.getPointNumber(); i++)
		insertPoint(pc.getPoints(i));
}

/*!
* \param p Point
*/
void GridMap::insertPoint(const Point& p)
{
	// Noktanin haritadaki koordinatlari hesaplanir
	int x = static_cast<int>(p.getX() / gridSize);
	int y = static_cast<int>(p.getY() / gridSize);
	int z = static_cast<int>(p.getZ() / gridSize);
	// Eger koordinatlar haritanin sinirlari icinde ise, o koordinatin kupunun degeri true yapilir
	if (x >= 0 && x < depth && y >= 0 && y < depth && z >= 0 && z < depth)
		map[x][y][z] = true;
}

/*!
* \param x  x noktasi
* \param y  y noktasi
* \param z  z noktasi
* \return bool
*/
// Haritanin belirli bir kupunun degerini donduren fonksiyon
bool GridMap::getGrid(int x, int y, int z) const
{
	// Koordinatlar haritanin sinirlari icinde ise, o koordinatin kupunun degeri dondurulur
	if (x >= 0 && x < depth && y >= 0 && y < depth && z >= 0 && z < depth)
		return map[x][y][z];
	// Koordinatlar haritanin sinirlari disinda ise false dondurulur
	return false;
}

/*!
* \param fileName dosyanin adi
\return bool
*/
// Verilen dosyadan haritayi okuyan ve yukleyen fonksiyon
bool GridMap::loadMap(const std::string& fileName)
{
	// Dosya acilir
	std::ifstream in(fileName);
	// Eger dosya acilamazsa false dondurulur
	if (!in)
		return false;

	// Kuplerin kenar uzunlugu ve X, Y, Z eksenleri dogrultusunda kup sayisi dosyadan okunur
	in >> gridSize >> depth;

	// 3B dizi olusturulur ve tum kuplerin degerleri false atanir
	map.resize(depth);
	for (int i = 0; i < depth; i++)
	{
		map[i].resize(depth);
		for (int j = 0; j < depth; j++)
			map[i][j].resize(depth, false);
	}

	// Dosyadaki tum satirlar gezilir ve haritaya eklenir
	int x, y, z;
	while (in >> x >> y >> z)
		map[x][y][z] = true;

	// Dosya kapatilir
	in.close();

	// Islem basarili oldugu icin true dondurulur
	return true;
}

/*!
* \param fileName dosya adi
* \return bool
*/

bool GridMap::saveMap(const std::string& fileName)
{
	// Dosya acilir
	std::ofstream out(fileName);
	// Eger dosya acilamazsa false dondurulur
	if (!out)
		return false;

	// Kuplerin kenar uzunlugu ve X, Y, Z eksenleri dogrultusunda kup sayisi dosyaya yazilir
	out << gridSize << " " << depth << std::endl;

	// Haritadaki tum kupler gezilir ve true olanlar dosyaya yazilir
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < depth; j++)
			for (int k = 0; k < depth; k++)
				if (map[i][j][k])
					out << i << " " << j << " " << k << std::endl;

	// Dosya kapatilir
	out.close();

	// Islem basarili oldugu icin true dondurulur
	return true;
}