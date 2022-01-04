#include <1_sonar_sweep.h>
#include <2_dive.h>
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
  EXPECT_EQ(answer, 1298); // verified answer
}

TEST(AdventOfCode2021, 1_SonarSweep_Part2) {
  SonarSweep ss{"../puzzles/1_sonar_sweep/input.txt"};
  EXPECT_EQ(ss.DataSamples(), 2000);
  auto answer = ss(3); // sliding window 3
  OsAnswer() << answer << std::endl;
  EXPECT_EQ(answer, 1248); // verified answer
}

TEST(AdventOfCode2021, 2_Dive_Part1) {
  SubmarineCoordinates coords;
  SubmarineNav<SubmarineNavModel::Primitive> nav{"../puzzles/2_dive/input.txt"};
  nav(coords);
  auto arbitrary_multiply = coords.depth * coords.horizontal;
  OsAnswer() << arbitrary_multiply << std::endl;
  EXPECT_EQ(arbitrary_multiply, 1990000); // verified answer
}

TEST(AdventOfCode2021, 2_Dive_Part2) {
  SubmarineCoordinates coords;
  SubmarineNav<SubmarineNavModel::IronSights> nav{"../puzzles/2_dive/input.txt"};
  nav(coords);
  auto arbitrary_multiply = coords.depth * coords.horizontal;
  OsAnswer() << arbitrary_multiply << std::endl;
  EXPECT_EQ(arbitrary_multiply, 1975421260); // verified answer
}