#include <doctest/doctest.h>
#include <slideconverters/slideconverters.h>
#include <slideconverters/version.h>

#include <string>

TEST_CASE("SlideConverters") {
  using namespace SlideConverters;

  Converter converter("Tests");

  CHECK(converter.convert(LanguageCode::EN) == "Hello, Tests!");
  CHECK(converter.convert(LanguageCode::DE) == "Hallo Tests!");
  CHECK(converter.convert(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(converter.convert(LanguageCode::FR) == "Bonjour Tests!");
}

TEST_CASE("SlideConverters version") {
  static_assert(std::string_view(SlideConverters_VERSION) == std::string_view("1.0"));
  CHECK(std::string(SlideConverters_VERSION) == std::string("1.0"));
}