//
// Created by Jason Terhorst on 5/18/22.
//

#ifndef SLIDECONVERTERS_SLIDEGENERATORSTRATEGY_H
#define SLIDECONVERTERS_SLIDEGENERATORSTRATEGY_H

#include <fstream>
#include <vector>
#include "IntermediateSlide.h"
#include "SlideFileType.h"

namespace SlideConverters {

  class SlideGeneratorStrategy {
  public:
    virtual ~SlideGeneratorStrategy() {}

    virtual std::vector<IntermediateSlide> slidesForDataStream(std::string&) = 0;
    virtual std::string dataStreamForSlides(std::vector<IntermediateSlide>) = 0;
  };

}  // namespace SlideConverters

#endif  // SLIDECONVERTERS_SLIDEGENERATORSTRATEGY_H
