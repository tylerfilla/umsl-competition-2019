/*
 * Tyler Filla
 * OPC19 - Program 5
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

static bool generate(std::string& name) {
  for (int i = 0; i < name.size(); ++i) {
    char c = name[i];

    c = std::toupper(c);

    // character replacements
    switch (c) {
      case 'A':
        c = 'E';
        break;
      case 'E':
        c = 'I';
        break;
      case 'I':
        c = 'O';
        break;
      case 'O':
        c = 'U';
        break;
      case 'U':
        c = 'A';
        break;



      case 'B':
        c = 'C';
        break;
      case 'C':
        c = 'D';
        break;
      case 'D':
        c = 'F';
        break;
      case 'F':
        c = 'G';
        break;
      case 'G':
        c = 'H';
        break;
      case 'H':
        c = 'J';
        break;
      case 'J':
        c = 'K';
        break;
      case 'K':
        c = 'L';
        break;
      case 'L':
        c = 'M';
        break;
      case 'M':
        c = 'N';
        break;
      case 'N':
        c = 'P';
        break;
      case 'P':
        c = 'Q';
        break;
      case 'Q':
        c = 'R';
        break;
      case 'R':
        c = 'S';
        break;
      case 'S':
        c = 'T';
        break;
      case 'T':
        c = 'V';
        break;
      case 'V':
        c = 'W';
        break;
      case 'W':
        c = 'X';
        break;
      case 'X':
        c = 'Y';
        break;
      case 'Y':
        c = 'Z';
        break;
      case 'Z':
        c = 'B';
        break;
    }

    if (!std::isalpha(c)) {
      return false;
    }

    if (c >= '0' && c <= '9') {
      return false;
    }

    // casing
    c = std::toupper(c);

    // putback
    name[i] = c;
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::string s = argv[1];

  if (generate(s)) {
    std::cout << s << "\n";
  } else {
    std::cout << "ERROR\n";
  }
}
