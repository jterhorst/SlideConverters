#include <fmt/format.h>

#include "SlideConverters/IntermediateSlideGenerator.h"

using namespace SlideConverters;

//IntermediateSlideGenerator::IntermediateSlideGenerator() {}

IntermediateSlideGenerator::IntermediateSlideGenerator(std::map<SlideFileType, SlideGeneratorStrategy *> x) : strategies{x} {}

IntermediateSlideGenerator::~IntermediateSlideGenerator() {}

std::string IntermediateSlideGenerator::convert(std::string inputData, SlideFileType inputType, SlideFileType expectedOutputType) {

    std::vector<IntermediateSlide> slides = strategies[inputType]->slidesForDataStream(inputData);
    std::string result = strategies[expectedOutputType]->dataStreamForSlides(slides);
    printf("%s", result.c_str());
  return inputData;
}

void IntermediateSlideGenerator::registerStrategy(SlideGeneratorStrategy * strategy, SlideFileType type) {
    strategies[type] = strategy;
}
