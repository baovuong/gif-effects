#include <iostream>
#include <vector>

#include "image_effects.h"

using namespace Magick;
using namespace std;


struct point {
    int x;
    int y;
};

point createPoint(double radius, double angle) {
    point result = {
        (int)(radius * cos(angle)),
        (int)(radius * sin(angle))
    };

    return result;
}

vector<Image> shake(Image* image, int interval, int points, double radius) {
    vector<Image> frames;

    Blob blob;
    //image->magick("GIF");
    image->write(&blob);
    int newWidth = image->size().width() - 2*radius;
    int newHeight = image->size().height() - 2*radius;


    for (int i=0; i<points; i++) {
        point p = createPoint(radius, i*2*M_PI/points);
        cout << p.x << ", " << p.y << endl;
        Image frame(blob);
        frame.magick("GIF");

        cout << "cropping" << endl;
        frame.crop(Geometry(
            newWidth,
            newHeight, 
            3*newWidth/8 + 2*p.x, 
            3*newHeight/8 + 2*p.y));
        cout << "done cropping" << endl;

        cout << "paging" << endl;
        frame.page(Geometry(
            newWidth, 
            newHeight, 
            2*p.x, 
            2*p.y));
        cout << "done paging" << endl;

        frame.animationDelay(interval);
        frames.push_back(frame);
        cout << "done" << endl;
    }

    //srand ( unsigned ( time(0) ) );
    //random_shuffle(frames.begin(), frames.end());

    return frames;
}