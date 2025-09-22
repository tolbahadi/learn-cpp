#include "temperature-stats.h"

#include <iostream>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <string>

namespace tempstats {

namespace {
constexpr double absolute_zero_celsius{-273.15};
}

TempStats::TempStats() = default;

TempStats::~TempStats() = default;

void TempStats::read(std::istream& in) {
  std::string token;

  while (in >> token) {
    if (token == "q" || token == "quit") {
      break;
    }

    try {
      const double value = std::stod(token);
      if (value < absolute_zero_celsius) {
        std::cout << "Invalid temperature value. Value must be greater than absolute zero.\n";
      } else {
        temps.push_back(value);
      }
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "Invalid input. Please enter a valid double value.\n" << e.what() << "\n";
    }
    catch (const std::out_of_range& e) {
      std::cerr << "Invalid input. Please enter a valid double value.\n" << e.what() << "\n";
    }
  }
}

std::size_t TempStats::count() const {
  return temps.size();
}

double TempStats::mean() const {
  if (temps.size() == 0) throw std::invalid_argument("No data");

  double sum{0};
  for (double value : temps) {
    sum += value;
  }

  return sum / temps.size();
}

double TempStats::median() const {
  if (temps.size() == 0) throw std::invalid_argument("No data");
  auto temps_copy = temps;

  if (temps.size() % 2 == 0) {
    auto right_middle = temps_copy.begin() + temps_copy.size() / 2;
    std::nth_element(temps_copy.begin(), right_middle, temps_copy.end());

    double right_value = *right_middle;
    
    auto left_middle = std::max(right_middle - 1, temps_copy.begin());
    std::nth_element(temps_copy.begin(), left_middle, right_middle + 1);

    return (*left_middle + right_value) / 2.0;
  } else {
    auto middle = temps_copy.begin() + temps_copy.size() / 2;
    std::nth_element(temps_copy.begin(), middle, temps_copy.end());
  
    return *middle;
  }
}

std::pair<double, double> TempStats::minmax() const {
  if (temps.size() == 0) throw std::invalid_argument("No data to compute min/max for.");
  auto [min, max] = std::minmax_element(temps.begin(), temps.end());
  return {*min, *max};
}

} // end tempstats namespace
