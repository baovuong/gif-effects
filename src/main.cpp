#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <Magick++.h>


using namespace std;
using namespace Magick;


/**
 * @brief 
 * 
 * @param image 
 * @param interval 
 * @param frames 
 */
vector<Image> shake(Image* image, int interval, int numFrames) {
    image->pixelColor(50, 50, Color("blue"));
    vector<Image> images;

    return images;
}

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
    
    Image image("640x480", "red");
    shake(&image, 100, 20);
    image.magick("png");                   
    image.write("thing.png");

    vector<int> numbers = randomNumbers(5);
    for (auto &number : numbers) {
        cout << number << endl;
    }

    return 0;
}