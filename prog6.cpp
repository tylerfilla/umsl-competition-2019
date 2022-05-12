/*
 * Tyler Filla
 * OPC19 - Program 6
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

static int to_digit(char c) {
  switch (c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    default:
      return -1;
  }
}

static std::string file_data;
static int num_steps = 0;

static void next(std::string s) {
  num_steps++;

  double product = 1;

  for (int i = 0; i < s.size(); ++i) {
    int digit = to_digit(s[i]);

    if (digit == -1) {
      std::cout << "The input file has inappropriate data.\n" << file_data << "\n";
      std::exit(0);
    }

    product *= digit;
  }

  std::stringstream ss;
  ss << product;

  if (ss.str().size() == 1) {
    //std::cout << "base\n";
  } else {
    next(ss.str());
  }
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "DATA MISSING\n";
    return 0;
  }

  std::fstream f(argv[1]);

  if (!f) {
    std::cout << "FILE ERROR\n";
    return 0;
  }

  std::string line;
  std::getline(f, line);

  if (line.empty()) {
    std::cout << "FILE ERROR\n";
    return 0;
  }

  if (std::atoi(line.c_str()) <= 9) {
    std::cout << "The input file has inappropriate data.\n" << line << "\n";
    std::exit(0);
  }

  file_data = line;

  next(line);

  std::cout << num_steps << "\n";
}
