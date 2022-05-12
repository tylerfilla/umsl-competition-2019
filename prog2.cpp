/*
 * Tyler Filla
 * OPC19 - Program 2
 */

// Bunch o' headers
// These were prepared before the competition, so many may be unneeded
#include <algorithm>
#include <climits>
#include <cmath>
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

struct point {
  double x;
  double y;
  double z;
};

static double distance(const point& p1, const point& p2) {
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2) + std::pow(p1.z - p2.z, 2));
}

static point read_point(std::string line) {
  point p = {};

  std::stringstream ss;
  ss << line;
  ss >> p.x;
  ss >> p.y;
  ss >> p.z;

  return p;
}

int main(int argc, char* argv[]) {
  std::fstream f(argv[1]);

  std::vector<point> points;

  std::string line;
  while (std::getline(f, line)) {
    points.push_back(read_point(line));
  }

  for (int i = 0; i < points.size(); ++i) {
    for (int j = 0; j < points.size(); ++j) {
      double dist = distance(points[i], points[j]);

      std::stringstream ss;
      ss << std::fixed << std::setprecision(1000) << dist;

      std::string s = ss.str();

      std::cout << s.substr(0, s.find('.')) << "." << s.substr(s.find('.') + 1, 1);

      if (j + 1 < points.size()) {
        std::cout << " ";
      }
    }

    if (i + 1 < points.size()) {
      std::cout << "\n";
    }
  }

  std::cout << "\n";
}
