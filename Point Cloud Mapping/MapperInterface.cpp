#include "MapperInterface.h"
/*!
\param dc DepthCamera
*/
void MapperInterface::addGenerator(PointCloudGenerator* dc)
{
	generators.push_back(dc);
}

/*!
\param pc PointCloudRecorder
*/
void MapperInterface::setRecorder(PointCloudRecorder* pcr)
{
	this->recorder = pcr;
}

/*!
\param map GridMap
*/
void MapperInterface::setMap(Map* map)
{
	this->map = map;
}

/*!
\return operation's succes
*/
bool MapperInterface::generate()
{
	int size = this->generators.size();
	for (int i = 0; i < size; i++) {
		PointCloud temp;
		this->generators[i]->captureFor(temp, this->generators[i]->getFile());
		this->pointCloud = this->pointCloud + temp;
	}
	return true;
}

/*!
\return operation's succes
*/
bool MapperInterface::recordPointCloud()
{
	this->recorder->setFileName("final.txt");
	this->recorder->save(pointCloud);

	return true;
}

/*!
\return operation's succes
*/
bool MapperInterface::recordMap()
{
	this->map->saveMap("map.txt");
	return true;
}

/*!
\return operation's succes
*/
bool MapperInterface::insertMap()
{
	this->map->insertPointCloud(pointCloud);

	return true;
}
