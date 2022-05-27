#pragma once

#include <string>
#include <stdio.h>
#include <map>
#include <fstream>
#include <vector>
#include "IntermediateSlide.h"
#include "SlideFileType.h"
#include "SlideGeneratorStrategy.h"

namespace SlideConverters {
  /**
   * @brief A class for converting one slide file to another, guided by available strategies.
   */
  class IntermediateSlideGenerator {
    std::map<SlideFileType, SlideGeneratorStrategy *> strategies;

  public:

    IntermediateSlideGenerator(std::map<SlideFileType, SlideGeneratorStrategy *>);
    ~IntermediateSlideGenerator();

    std::string convert(std::string, SlideFileType, SlideFileType);
    void registerStrategy(SlideGeneratorStrategy *, SlideFileType);
  };

}  // namespace SlideConverters
