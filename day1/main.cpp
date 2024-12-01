#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int part1(std::vector<int>& first, std::vector<int>& second) {
  unsigned int difference = 0;
  for(int i = 0; i < first.size(); ++i) {
    difference += std::abs(first[i] - second[i]);
  }
  return difference;
}

int part2(std::vector<int>& first, std::vector<int>& second) {
  int similarity = 0;
  for(int i = 0; i < first.size(); ++i) {
    if(auto it = std::ranges::find(second, first[i]); it != second.end()) {
      int factor = 0;
      while(*it == first[i]) {
        factor++;
        it++;
      }
      similarity += (first[i] * factor);
    }
  }
  return similarity;
}

int main() {
  std::fstream fs("input.txt");
  std::string line;

  std::vector<int> first;
  std::vector<int> second;
  while(std::getline(fs, line)) {
    first.push_back(std::stoi(line));
    second.push_back(std::stoi(line.substr(8)));
  }

  assert(first.size() == second.size());

  std::ranges::sort(first);
  std::ranges::sort(second);

  std::cout << "part 1: " << part1(first, second) << std::endl;
  std::cout << "part 2: " << part2(first, second) << std::endl;

  return 0;
}
