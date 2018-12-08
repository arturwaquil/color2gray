#ifndef COLOR2GRAY_H
#define COLOR2GRAY_H

#include <iostream>
#include <math.h>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

const double PI = 3.14159265359;
const int LUMINANCE = 0;
const int CHANNEL_A = 1;
const int CHANNEL_B = 2;

Mat rgb2cielab(Mat original);

double crunch(double value, double alpha);

double dotProduct2(Vec2b v, Vec2b u);

double findDelta(double deltaL, double deltaA, double deltaB, double theta, double alpha);

Mat color2gray(Mat original, double theta, double alpha, double mu);

#endif // COLOR2GRAY_H
