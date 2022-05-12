/*
 * Tyler Filla
 * OPC19 - Program 3
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

static std::string trunc_string(double d) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(1000) << d;

  std::string s = ss.str();

  std::stringstream ss2;
  ss2 << s.substr(0, s.find('.')) << "." << s.substr(s.find('.') + 1, 2);
  return ss2.str();
}

int main(int argc, char* argv[]) {
  char* endp;

  double todays_charge = std::strtod(argv[1], &endp);
  std::string local_state = argv[2];
  std::string friendly_state = argv[3];
  int age = std::strtol(argv[4], &endp, 10);
  bool aaa = std::string("YES") == argv[5];
  bool veteran = std::string("YES") == argv[6];
  std::string resident_state = argv[7];
  bool credit_card = std::string("YES") == argv[8];

  double discount = 0;

  if (veteran) {
    //charge *= 0.9; // 10% off
    discount += 0.1;
  }
   else if (aaa) {
    if (age < 19) {
      //charge *= 0.95; // 5% discount
      discount += 0.05;
    } else if (age > 65) {
      //charge *= 0.85; // 15% discount
      discount += 0.15;
    } else {
      //charge *= 0.9; // 10% discount
      discount += 0.1;
    }
  }

  if (age >= 60) {
    if (resident_state == local_state) {
      //charge *= 0.9; // 10% off
      discount += 0.1;
    } else if (resident_state == friendly_state) {
      //charge *= 0.95; // 5% off
      discount += 0.05;
    }
  }

  if (credit_card && resident_state == friendly_state) {
    //charge *= 0.9; // 10% off
    discount += 0.1;
  }

  double subtotal = todays_charge * (1 - discount);

  std::cout << trunc_string(subtotal) << "\n";
}
