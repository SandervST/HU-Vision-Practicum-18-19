#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	picturebuffer = new Intensity[1];
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImageStudent(other.getWidth(), other.getHeight()) {
	//Create a copy from the other object
	for (int x = 0; x < getWidth(); x++) {
		for (int y = 0; y < getWidth(); y++) {
			setPixel(x, y, other.getPixel(x, y));
		}
	}
	
}


IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	//Initialize pixel storage
	picturebuffer = new Intensity[width*height];
}

IntensityImageStudent::~IntensityImageStudent() {
	//delete allocated objects
	delete[] picturebuffer;
}

void IntensityImageStudent::set(const int width, const int height) {
	//resize or create a new pixel storage
	IntensityImage::set(width, height);
	delete[] picturebuffer;
	picturebuffer = new Intensity[width*height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	//resize or create a new pixel storage and copy the object
	set(other.getWidth(), other.getHeight());

	for (int x = 0; x < getWidth(); x++) {
		for (int y = 0; y < getWidth(); y++) {
			setPixel(x, y, other.getPixel(x, y));
		}
	}
}


void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int i = getWidth() * y + x;
	setPixel(i, pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	//set pixel i in "Row-Major Order"
	picturebuffer[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int i = getWidth() * y + x;
	return getPixel(i);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return picturebuffer[i];
}