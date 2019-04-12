#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	picturebuffer = new RGB[1];
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImageStudent(other.getWidth(), other.getHeight()) {
	//Create a copy from the other object
	for (int x = 0; x < getWidth(); x++) {
		for (int y = 0; y < getWidth(); y++) {
			setPixel(x, y, other.getPixel(x, y));
		}
	}
	
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	//Initialize pixel storage
	picturebuffer = new RGB[width*height];
}

RGBImageStudent::~RGBImageStudent() {
	//delete allocated objects
	delete[] picturebuffer;
}

void RGBImageStudent::set(const int width, const int height) {
	//resize or create a new pixel storage
	RGBImage::set(width, height);
	delete[] picturebuffer;
	picturebuffer = new RGB[width*height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	//resize or create a new pixel storage and copy the object
	set(other.getWidth(), other.getHeight());

	for (int x = 0; x < getWidth(); x++) {
		for (int y = 0; y < getWidth(); y++) {
			setPixel(x, y, other.getPixel(x, y));
		}
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int i = getWidth() * y + x;
	setPixel(i, pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	//set pixel i in "Row-Major Order"
	picturebuffer[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int i = getWidth() * y + x;
	return getPixel(i);
}

RGB RGBImageStudent::getPixel(int i) const {
	return picturebuffer[i];
}