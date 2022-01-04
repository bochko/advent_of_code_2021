#pragma once

#include <cassert>
#include <filesystem>
#include <fstream>
#include <functional>

struct SubmarineCoordinates {
  int64_t horizontal{};
  int64_t depth{};
  int64_t aim{};
};

enum class SubmarineNavModel {
    Primitive, // simple
    IronSights, // aiming
};

template <SubmarineNavModel Aiming_>
struct SubmarineNav {
  using Action = std::function<void(SubmarineCoordinates &)>;
  explicit SubmarineNav(const std::filesystem::path &input) {
    std::ifstream ifs{input};
    std::string line{};
    while (std::getline(ifs, line)) {
      auto split = line.find_first_of(' ');
      std::string op = line.substr(0, split);
      int64_t magnitude = std::stoll(line.substr(split));
      Action action;

      if (op == "forward") {
        action = [magnitude](SubmarineCoordinates &coords) {
          coords.horizontal += magnitude;
          if constexpr (Aiming_ == SubmarineNavModel::IronSights) {
            coords.depth += magnitude * coords.aim;
          }
        };
      } else if (op == "down") {
        action = [magnitude](SubmarineCoordinates &coords) {
          if constexpr (Aiming_ == SubmarineNavModel::IronSights) {
            coords.aim += magnitude;
          } else {
            coords.depth += magnitude;
          }
        };
      } else if (op == "up") {
        action = [magnitude](SubmarineCoordinates &coords) {
          if constexpr (Aiming_ == SubmarineNavModel::IronSights) {
            coords.aim -= magnitude;
          } else {
            coords.depth -= magnitude;
          }
        };
      } else {
        assert(false);
      }
      lazy_eval_actions_.emplace_back(action);
    }
  }
  void operator()(SubmarineCoordinates &coords) const noexcept {
    for (const auto &action : lazy_eval_actions_) {
      action(coords);
    }
  }

 private:
  std::vector<Action> lazy_eval_actions_;
};
