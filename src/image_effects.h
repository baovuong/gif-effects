#include <Magick++.h>
#include <vector>

std::vector<Magick::Image> shake(Magick::Image* image, int interval, int points, double radius);