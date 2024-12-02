#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool test_report(std::vector<int>& levels);

int main() {
  std::fstream fs("input.txt");
  std::string line;

  int result = 0;

  while(std::getline(fs, line)) {
    std::vector<int> levels;

    std::stringstream ss(line);
    std::string tok;
    while(ss >> tok) {
      levels.push_back(std::stoi(tok));
    }

    bool safe = test_report(levels);
    if(!safe) {
      for(int i = 0; i < levels.size(); ++i) {
        std::vector copy(levels);
        copy.erase(copy.begin() + i);
        if(test_report(copy)) {
          safe = true;
          break;
        }
      }
    }
    if(safe) {
      result++;
    }
  }

  std::cout << result << std::endl;
  return 0;
}

bool test_report(std::vector<int>& levels) {
  if(!std::is_sorted(levels.begin(), levels.end(), std::less<int>{}) && !std::is_sorted(levels.begin(), levels.end(), std::greater<int>{})) {
    return false;
  } else {
    for(int j = 0; j < levels.size()-1; ++j) {
      if(int diff = std::abs(levels[j] - levels[j+1]); diff < 1 || diff > 3) {
        return false;
      }
    }
  }
  return true;
}

