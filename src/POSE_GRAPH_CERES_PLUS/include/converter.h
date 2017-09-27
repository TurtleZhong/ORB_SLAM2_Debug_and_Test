/**
* This file is part of ORB-SLAM2.
*
* Copyright (C) 2014-2016 Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
* For more information see <https://github.com/raulmur/ORB_SLAM2>
*
* ORB-SLAM2 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ORB-SLAM2 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with ORB-SLAM2. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include<opencv2/core/core.hpp>
#include<png++/png.hpp>
#include<Eigen/Dense>
//#include<sophus/so3.h>
//#include<sophus/se3.h>
#include"types.h" /*to use the Pos3d*/

namespace POSE_GRAPH
{
class Converter
{
public:
    static std::vector<cv::Mat> toDescriptorVector(const cv::Mat &Descriptors);

    static cv::Mat toCvMat(const Eigen::Matrix<double,4,4> &m);
    static cv::Mat toCvMat(const Eigen::Matrix3d &m);
    static cv::Mat toCvMat(const Eigen::Matrix<double,3,1> &m);
    static cv::Mat toCvMat(const Eigen::Quaterniond &q);
    static cv::Mat toCvMat(const Pose3d &pose);
    static cv::Mat toCvSE3(const Eigen::Matrix<double,3,3> &R, const Eigen::Matrix<double,3,1> &t);

    static Eigen::Matrix<double,3,1> toVector3d(const cv::Mat &cvVector);
    static Eigen::Matrix<double,3,1> toVector3d(const cv::Point3f &cvPoint);
    static Eigen::Matrix<double,3,3> toMatrix3d(const cv::Mat &cvMat3);

    //static std::vector<float> toQuaternion(const cv::Mat &M);
    static Eigen::Quaterniond toQuaternion(const cv::Mat &M);
    static uint8_t* toPng(cv::Mat image);

    //static Sophus::SE3 toSE3(const cv::Mat &cvT);
    static cv::Mat toCvMat(const Eigen::Vector3d &m, int flag);
    static Eigen::Isometry3d toIsometry3d(const cv::Mat &M);
    static Pose3d toPose3d(const cv::Mat &Twc);

};


}


// namespace myslam

#endif // CONVERTER_H
