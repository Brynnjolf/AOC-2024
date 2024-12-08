#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>


long concatenate(long left, long right) {
  try {
    std::string str = std::to_string(left);
    str += std::to_string(right);
    return std::stol(str);
  } catch (std::out_of_range& e) {
    return -1; // if it's too long, it can't be right. return junk.
  }
}

bool calculate(long target, long result, size_t pos, std::vector<long>& expr) {
  if(target == result && pos == expr.size()-1) {
    return true;
  }

  if(pos >= expr.size()) {
    return false;
  }

  if(calculate(target, result + expr[pos+1], pos+1, expr) || calculate(target, result * expr[pos+1], pos+1, expr) || calculate(target, concatenate(result, expr[pos+1]), pos+1, expr)) {
    return true;
  }

  return false;
}

int main() {

  size_t count = 0;

  std::fstream fs{"input.txt"};
  for(std::string line; std::getline(fs, line);) {
    line.erase(std::remove(line.begin(), line.end(), ':'), line.end());

    std::vector<long> expr;
    std::stringstream ss{line};
    for(std::string tok; std::getline(ss, tok, ' ');) {
      expr.push_back(std::stol(tok));
    }

    if(calculate(expr[0], expr[1], 1, expr)) {
      count += expr[0];
    }
  }

  std::cout << count << std::endl;

  return 0;
}
