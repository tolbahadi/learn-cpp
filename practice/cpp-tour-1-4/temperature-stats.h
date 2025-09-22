#ifndef PRACTICE_2025_09_20_CH1_4_TEMPERATURE_STATS_H
#define PRACTICE_2025_09_20_CH1_4_TEMPERATURE_STATS_H

#include <istream>
#include <vector>
#include <utility>

namespace tempstats {

class TempStats {
public:
  TempStats();

  ~TempStats();

  TempStats(const TempStats&) = delete;
  TempStats& operator=(const TempStats&) = delete;

  TempStats(TempStats&&) = delete;
  TempStats& operator=(TempStats&&) = delete;

  void read(std::istream& in);

  std::size_t count() const;

  double mean() const;
  
  double median() const;

  std::pair<double, double> minmax() const;

private:
  std::vector<double> temps;
};

} // end tempstats namespace

#endif
