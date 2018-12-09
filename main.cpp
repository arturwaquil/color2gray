#include <iostream>
#include <opencv2/opencv.hpp>
#include "color2gray.h"
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    string fileName, saveName;
    double theta, alpha;
    
    if (argc > 1)
    {
        fileName = argv[1];
    
        theta = PI/4.0;
        alpha = 10.0;

        for (int i = 2; i < argc; i++)
        {
            if (!strcmp(argv[i], "-t") || !strcmp(argv[i], "--theta"))
            {
                i++;
                sscanf(argv[i], "%lf", &theta);
                theta *= PI/180;        // convert to radians
            }
            else if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--alpha"))
            {
                i++;
                sscanf(argv[i], "%lf", &alpha);
            }
            else if (!strcmp(argv[i], "-s") || !strcmp(argv[i], "--savename"))
            {
                i++;
                saveName = argv[i];
            }
            else
            {
                cout << argv[i] << "is not a valid option.\n";
                return 1;
            }
        }
    }

    Mat image = imread(fileName);

    if (image.empty())
    {
        cout << "This file does not exist.\n";
        return 1;
    }

    image = color2gray(image, theta, alpha, 0);

    if (saveName.empty())
    {
        cout << "Save as (include extension): ";
        cin >> saveName;
    }

    imwrite(saveName, image);

    return 0;
}
