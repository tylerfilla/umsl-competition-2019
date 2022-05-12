/*
 * Tyler Filla
 * OPC19 - Program 1
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

int main(int argc, char* argv[]) {
  int req = std::atoi(argv[1]);

  int num = 1;

  for (int i = 0; i < req; ++i) {

    for (int j = 0; j < req - i; ++j) {
      std::cout << num;
    }
    std::cout << "\n";

    num++;
  }
}
