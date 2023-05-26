#include "DepthCamera.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/*!
*  \param rotation 3x3 Rotasyon Matrixi
*  \param translation 3x1 Translasyon Vektoru
*  \param fileName Noktalarin tutuldugu dosyanin adi
*/
DepthCamera::DepthCamera(Eigen::Matrix3d rotation, Eigen::Vector3d translation, string fileName)
	: PointCloudGenerator(rotation, translation) {
	this->fileName = fileName;
}

/*!
*  \param finalFileName Finaldeki dosya adi
*/
void DepthCamera::setFile(string finalFileName) {
	this->fileName = finalFileName;
}

/*!
*  \return Dosya adi
*/
string DepthCamera::getFile() {
	return this->fileName;
}

/*!
*  \param pc Doldurulacak PointCloud
*  \param fileName Okunacak dosyanin adi
*  \return Doldurulan PointCloud
*/
PointCloud DepthCamera::capture(PointCloud& pc, string fileName) {
	string lineData, _lines;
	stringstream dataStream;
	int lines;
	string _x, _y, _z;
	string _r, _g, _b;
	double x, y, z;
	int r, g, b;

	ifstream readFile;
	readFile.open(fileName);
	getline(readFile, lineData); //skip the first line
	getline(readFile, _lines); //get the number of lines
	lines = stoi(_lines);


	//create new point
	Point newPoint = Point();


	for (int i = 0; i < lines; i++) {
		dataStream = stringstream(); //clear the stream

		getline(readFile, lineData);
		dataStream = stringstream(lineData);
		dataStream >> _x >> _y >> _z >> _r >> _g >> _b; //get coordinates as string
		x = stod(_x);
		y = stod(_y);
		z = stod(_z);
		r = stoi(_r);
		g = stoi(_g);
		b = stoi(_b);

		//set the temp point's values:
		newPoint.setPoint(x, y, z);
		newPoint.setR(r);
		newPoint.setG(g);
		newPoint.setB(b);

		//send the point to the cloud:
		pc.insertPoint(newPoint);
	}

	readFile.close();

	return pc;
}

/*!
*  \param pc Doldurulacak PointCloud
*  \param fileName Okunacak dosyanin adi
*  \return Doldurulan PointCloud
*/
PointCloud DepthCamera::captureFor(PointCloud& pc, string fileName) {
	this->capture(pc, fileName);
	this->getTransform().doTransform(pc);

	return pc;
}