#include "temperature-stats.h"

#include <iostream>
#include <string>

int main() {
  tempstats::TempStats temp_stats;

  try {

    temp_stats.read(std::cin);
  
    std::cout << "Count: " << temp_stats.count() << "\n";
    std::cout << "Mean: " << temp_stats.mean() << "\n";
    std::cout << "Median: " << temp_stats.median() << "\n";
    auto [min, max] = temp_stats.minmax();
    std::cout << "Min: " << min << "\n";
    std::cout << "Max: " << max << "\n";
  } catch (std::invalid_argument& error) {
    std::cerr << error.what();
    return 1;
  }

  return 0;
}
