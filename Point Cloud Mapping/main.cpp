#include <iostream>
#include <string>
#include "DepthCamera.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "Transform.h"
#include "MapperInterface.h"
#include "GridMap.h"
#include <Eigen/Dense>

using namespace std;

int main(){
    PointCloudRecorder* recorder = new PointCloudRecorder("final.txt");

    Eigen::Vector3d translation;
    translation << 1.95704, 1.93000, 1.05707;
    Eigen::Matrix3d rotation;
    rotation << -0.7076050, 0.0065031, -0.7065783,
        0.7066082, 0.0065134, -0.7075750,
        0.0000008, -0.9999576, -0.0092041;
    DepthCamera* dc = new DepthCamera(rotation, translation, "cam.txt");

    Eigen::Vector3d translation1;
    translation1 << -1.91288, 1.94412, 1.05465;
    Eigen::Matrix3d rotation1;
    rotation1 << -0.6638364, -0.0068830, 0.7478462,
        -0.7478778, 0.0061099, -0.6638082,
        -0.0000002, -0.9999576, -0.0092036;
    DepthCamera* dc1 = new DepthCamera(rotation1, translation1, "cam1.txt");

    Eigen::Vector3d translation2;
    translation2 << 1.96978, -1.94622, 1.05264;
    Eigen::Matrix3d rotation2;
    rotation2 << 0.8762180, 0.0044351, -0.4818945,
        0.4819149, -0.0080638, 0.8761809,
        0.0000001, -0.9999577, -0.0092030;
    DepthCamera* dc2 = new DepthCamera(rotation2, translation2, "cam2.txt");

    Eigen::Vector3d translation3;
    translation3 << -1.87445, -1.95027, 1.06432;
    Eigen::Matrix3d rotation3;
    rotation3 << 0.3597052, -0.0085871, 0.9330265,
        -0.9330660, -0.0033108, 0.3596900,
        0.0000003, -0.9999576, -0.0092033;
    DepthCamera* dc3 = new DepthCamera(rotation3, translation3, "cam3.txt");

    GridMap* gridMap = new GridMap(0.01, 300);


    MapperInterface interface;
    interface.addGenerator(dc);
    interface.addGenerator(dc1);
    interface.addGenerator(dc2);
    interface.addGenerator(dc3);
    interface.generate();

    interface.setRecorder(recorder);


    interface.setMap(gridMap);
    interface.insertMap();


    interface.recordPointCloud();
    interface.recordMap();

    return 0;
}