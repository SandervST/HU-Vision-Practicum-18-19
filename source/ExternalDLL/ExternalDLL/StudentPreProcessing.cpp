#include "StudentPreProcessing.h"
#include "ImageFactory.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	auto intesityImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	for (int w = 0; w < image.getWidth(); w++) {
		for (int h = 0; h < image.getHeight(); h++) {
			auto ColorPixel = image.getPixel(w, h);
			Intensity i = (ColorPixel.r + ColorPixel.g + ColorPixel.b) / 3;
			intesityImage->setPixel(w, h, i);
		}
	}
	return intesityImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}