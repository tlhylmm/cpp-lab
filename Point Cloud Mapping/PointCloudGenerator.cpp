#include "PointCloudGenerator.h"

/*!
	\param rotation 3x3 rotasyon matrixi
	\param translation 3x1 translasyon vektoru
*/
PointCloudGenerator::PointCloudGenerator(Eigen::Matrix3d rotation, Eigen::Vector3d translation) {
	this->transform.setRotation(rotation);
	this->transform.setTranslation(translation);
}

/*!
	\return transform objesi
*/
Transform PointCloudGenerator::getTransform() {
	return this->transform;
}