#include <1_sonar_sweep.h>
#include <gtest/gtest.h>

std::ostream& OsAnswer() {
  std::cout << "[  ANSWER  ] ";
  return std::cout;
}

TEST(AdventOfCode2021, 1_SonarSweep_Part1) {
  SonarSweep ss{"../puzzles/1_sonar_sweep/input.txt"};
  EXPECT_EQ(ss.DataSamples(), 2000);
  auto answer = ss(1); // sliding window 1
  OsAnswer() << answer << std::endl;
  EXPECT_EQ(answer, 1298);
}

TEST(AdventOfCode2021, 1_SonarSweep_Part2) {
  SonarSweep ss{"../puzzles/1_sonar_sweep/input.txt"};
  EXPECT_EQ(ss.DataSamples(), 2000);
  auto answer = ss(3); // sliding window 3
  OsAnswer() << answer << std::endl;
  EXPECT_EQ(answer, 1248);
}