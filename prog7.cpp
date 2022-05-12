/*
 * Tyler Filla
 * OPC19 - Program 7
 */

// Bunch o' headers
// These were prepared before the competition, so many may be unneeded
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

static int detect_base(std::string str) {
  std::set<char> digits;

  for (int i = 0; i < str.size(); ++i) {
    digits.insert(str[i]);
  }

  // hex
  if (digits.find('A') != digits.end()) {
    return 16;
  }
  if (digits.find('B') != digits.end()) {
    return 16;
  }
  if (digits.find('C') != digits.end()) {
    return 16;
  }
  if (digits.find('D') != digits.end()) {
    return 16;
  }
  if (digits.find('E') != digits.end()) {
    return 16;
  }
  if (digits.find('F') != digits.end()) {
    return 16;
  }

  // dec
  if (digits.find('9') != digits.end()) {
    return 10;
  }
  if (digits.find('8') != digits.end()) {
    return 10;
  }

  // oct
  if (digits.find('7') != digits.end()) {
    return 8;
  }
  if (digits.find('6') != digits.end()) {
    return 8;
  }
  if (digits.find('5') != digits.end()) {
    return 8;
  }
  if (digits.find('4') != digits.end()) {
    return 8;
  }
  if (digits.find('3') != digits.end()) {
    return 8;
  }
  if (digits.find('2') != digits.end()) {
    return 8;
  }
  if (digits.find('1') != digits.end()) {
    return 8;
  }
  if (digits.find('0') != digits.end()) {
    return 8;
  }
  return -1;
}


static long read_number(std::string s) {
  char* endp;
  return std::strtol(s.data(), &endp, detect_base(s));
}

int main(int argc, char* argv[]) {
  std::fstream f(argv[1]);

  if (!f) {
    std::cout << "FILE ERROR\n";
    return 0; // error code?
  }

  long max_num = -1234567890;

  std::string line;
  while (std::getline(f, line)) {
    long num = read_number(line);

    if (num > max_num) {
      max_num = num;
    }
  }

  std::cout << max_num << "\n";
}
