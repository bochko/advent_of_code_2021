#pragma once

#include <filesystem>
#include <vector>

class SonarSweep {
 public:
  explicit SonarSweep(const std::filesystem::path &input);
  [[nodiscard]] int operator()(int window_size) const noexcept;
  [[nodiscard]] std::size_t DataSamples() const noexcept {
    return data_.size();
  }

 private:
  [[nodiscard]] int SampleWindow(std::size_t idx_offset,
                                 int window_size) const noexcept;
  std::vector<int> data_;
};