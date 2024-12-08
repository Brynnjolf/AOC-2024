#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

int main() {

  std::fstream fs{"input.txt"};
  std::vector<std::string> city;
  for(std::string line; std::getline(fs, line);) {
    city.push_back(line);
  }

  std::map<char, std::vector<std::pair<size_t, size_t>>> satellitePositions = {};
  std::set<std::pair<size_t,size_t>> antinodePositions = {};


  for(size_t i = 0; i < city.size(); ++i) {
    for(size_t j = 0; j < city[i].size(); ++j) {
      if(city[i][j] != '.') {
        satellitePositions[city[i][j]].push_back({ i, j });
      }
    }
  }

  for(const auto& [satellite, positions] : satellitePositions) {
    for(size_t i = 0; i < positions.size(); ++i) {
      for(size_t j = i + 1; j < positions.size(); ++j) {
        std::pair<size_t,size_t> a, b; // new Antinodes
        int dy = positions[j].first - positions[i].first;
        int dx = positions[j].second - positions[i].second;
        a = positions[i];
        b = positions[j];
        while(a.first < city.size() && a.second < city[i].size()) {
          antinodePositions.insert(a);
          a.first -= dy;
          a.second -= dx;
        }
        while(b.first < city.size() && b.second < city[i].size()) {
          antinodePositions.insert(b);
          b.first += dy;
          b.second += dx;
        }
      }
    }
  }

  for(auto& el : antinodePositions) {
    if (city[el.first][el.second] == '.') {
      city[el.first][el.second] = '#';
    }
  }

  std::cout << antinodePositions.size() << std::endl;

  return 0;
}
