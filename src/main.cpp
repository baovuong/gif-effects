#include <chrono>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>

#include <cmath>
#include <cstdlib>
#include <cstring>

#include <unistd.h>

#include <Magick++.h>

#include "image_effects.h"

using namespace std;
using namespace Magick;

vector<int> randomNumbers(int num) {
    vector<int> output(num);
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, 100);

    for (int i=0; i<num; i++) {
        output[i] = distribution(generator);
    }
    return output;
}


int main(int argc, char **argv) {
    char* inputPath = NULL;
    char* outputPath = NULL;
    int interval = 1000;
    int points = 5;
    int radius = 20;
    int c;

    int requirementCount = 0;

    opterr = 0;

    while ((c = getopt(argc, argv, "t:n:r:i:o:")) != -1) {
        switch (c) {
            case 't':
                interval = atoi(optarg);
                break;
            case 'n':
                points = atoi(optarg);
                break;
            case 'r':
                radius = atoi(optarg);
                break;
            case 'i':
                inputPath = optarg;
                requirementCount++;
                break;
            case 'o':
                outputPath = optarg;
                requirementCount++;
                break;
            case '?':
                if (optopt != 0 && strchr("tnrio", optopt) != NULL) {
                    cerr << "Option -" << (int)optopt << " requires an argument" << endl;
                    return 1;
                }
                break;
            case ':':
                break;
            default:
                abort ();
        }
    }

    if (requirementCount < 2) {
        cerr << "insufficient arguments" << endl;
        return 1;
    }

    Image image(inputPath);
    vector<Image> frames = shake(&image, interval, points, radius);
    writeImages(frames.begin(), frames.end(), outputPath);
    return 0;
}