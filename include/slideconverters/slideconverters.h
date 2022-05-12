#pragma once

#include <string>

namespace SlideConverters {

  /**  Language codes to be used with the Converter class */
  enum class LanguageCode { EN, DE, ES, FR };

  /**
   * @brief A class for saying hello in multiple languages
   */
  class Converter {
    std::string name;

  public:
    /**
     * @brief Creates a new Converter
     * @param name the name to greet
     */
    Converter(std::string name);

    /**
     * @brief Creates a localized string containing the greeting
     * @param lang the language to greet in
     * @return a string containing the greeting
     */
    std::string convert(LanguageCode lang = LanguageCode::EN) const;
  };

}  // namespace SlideConverters
