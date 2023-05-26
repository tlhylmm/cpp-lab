#include "PointCloudRecorder.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*!
*  \param fileName Noktalarin kaydedilecegi dosya adi.
*/
PointCloudRecorder::PointCloudRecorder(string fileName) {
	this->fileName = fileName;
}

/*!
*  \param fileName Noktalarin kaydedilecegi dosya adi.
*/
void PointCloudRecorder::setFileName(string fileName) {
	this->fileName = fileName;
}

/*!
*  \return Kayit dosyasi adi, fileName
*/
string PointCloudRecorder::getFileName() {
	return this->fileName;
}

/*!
*  \param pc Noktalarin alinacagi PointCloud.
*  \return boolean, islem basarisi.
*/
bool PointCloudRecorder::save(const PointCloud& pc) {
	ofstream writeFile;
	writeFile.open(this->fileName);

	if (!writeFile.is_open()) {
		cout << "Error while opening file: " << this->fileName << endl;
		return false;
	}
	else {
		int lines = pc.getPointNumber();

		for (int i = 0; i < lines; i++) {
			Point temp = pc.getPoints(i);
			writeFile << setprecision(9)
				<< temp.getX() << " "
				<< temp.getY() << " "
				<< temp.getZ() << " "
				<< temp.getR() << " "
				<< temp.getG() << " "
				<< temp.getB() << "\n";
		}
	}

	writeFile.close();

	return true;
}