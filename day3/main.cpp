#include <fstream>
#include <iostream>
#include <regex>
int main() {
  std::fstream fs("input.txt");
  std::stringstream in;
  in << fs.rdbuf();
  std::string input = in.str();


  std::regex reg{"(mul)\\((\\d+),(\\d+)\\)|(do\\(\\))|(don't\\(\\))"};
  std::sregex_iterator regit(input.begin(), input.end(), reg);

  int total = 0;
  bool enabled = true;
  for(auto it = regit; it != std::sregex_iterator(); ++it) {
    std::smatch m = *it;
    if(m[1] == "mul" && enabled) {
      std::cout << "match found: " << m[2] << " * " << m[3] << std::endl;
      total += (std::stoi(m[2]) * std::stoi(m[3]));
    } else if(m[0] == "do()") {
      enabled = true;
    } else {
      enabled = false;
    }
  }

  std::cout << "TOTAL: " << total << std::endl;


  return 0;
}
