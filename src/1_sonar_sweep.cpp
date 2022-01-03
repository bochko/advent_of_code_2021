#include <1_sonar_sweep.h>

#include <fstream>

SonarSweep::SonarSweep(const std::filesystem::path &input) {
  std::ifstream ifs{input};
  std::string line{};
  while (std::getline(ifs, line)) {
    data_.emplace_back(std::stoi(line));
  }
}

[[nodiscard]] int SonarSweep::operator()(int window_size) const noexcept {
  int depth_increases = 0;
  for (std::size_t idx = window_size; idx < DataSamples(); ++idx) {
    if (SampleWindow(idx, window_size) > SampleWindow(idx - 1, window_size)) {
      ++depth_increases;
    }
  }
  return depth_increases;
}

[[nodiscard]] int SonarSweep::SampleWindow(std::size_t idx,
                                           int window_size) const noexcept {
  int sample_sum = 0;
  for (std::size_t offset = 0; offset < window_size; ++offset) {
    sample_sum += data_[idx - offset];
    if (idx - offset == 0) break;  // reached start of memory
  }
  return sample_sum;
}
