#include <doctest/doctest.h>
#include <slideconverters/version.h>

#include <fstream>
#include <iostream>
#include <string>

#include "SlideConverters/IntermediateSlide.h"
#include "SlideConverters/IntermediateSlideGenerator.h"
#include "SlideConverters/SlideFileType.h"

using namespace SlideConverters;

class MockSlideConverterStrategy: public SlideGeneratorStrategy {
  std::vector<IntermediateSlide> slidesForDataStream(std::string&);
  std::string dataStreamForSlides(std::vector<IntermediateSlide>);
};

std::vector<IntermediateSlide> MockSlideConverterStrategy::slidesForDataStream(std::string&) {
    std::vector<IntermediateSlide> collection;
    IntermediateSlide mockSlide = IntermediateSlide();
    collection.push_back(mockSlide);
    return collection;
}

std::string MockSlideConverterStrategy::dataStreamForSlides(std::vector<IntermediateSlide>) {
  return std::string("Test String");
}

TEST_CASE("SlideConverters::IntermediateSlideGenerator should call expected methods") {
  using namespace SlideConverters;

  MockSlideConverterStrategy mockStrategy = MockSlideConverterStrategy();
  std::map<SlideFileType, SlideGeneratorStrategy *> strategies;
  strategies[SlideFileType::PP7] = &mockStrategy;
  IntermediateSlideGenerator generator = IntermediateSlideGenerator(strategies);

  std::string input = std::string("Testing string");
  CHECK(generator.convert(input, SlideFileType::PP7, SlideFileType::PP7).compare(input) == 0);
//  std::vector<SlideGeneratorStrategy> strategies;
//  MockSlideConverterStrategy newMockStrategy = MockSlideConverterStrategy();
//  strategies.push_back(newMockStrategy);
//   SlideConverters::SlideConverters converter(strategies);

//   CHECK(converter.convert(LanguageCode::EN) == "Hello, Tests!");
//   CHECK(converter.convert(LanguageCode::DE) == "Hallo Tests!");
//   CHECK(converter.convert(LanguageCode::ES) == "¡Hola Tests!");
//   CHECK(converter.convert(LanguageCode::FR) == "Bonjour Tests!");
    
}

TEST_CASE("SlideConverters version") {
  static_assert(std::string_view(SLIDECONVERTERS_VERSION) == std::string_view("1.0"));
  CHECK(std::string(SLIDECONVERTERS_VERSION) == std::string("1.0"));
}
