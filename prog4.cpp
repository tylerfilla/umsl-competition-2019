/*
 * Tyler Filla
 * OPC19 - Program 4
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

static bool has_star_in_it(std::string haystack) {
  return haystack.find("STAR") != std::string::npos;
}

static std::string decipher(std::string ciphertext, int key) {
  for (int i = 0; i < ciphertext.size(); ++i) {
    ciphertext[i] = 'A' + (ciphertext[i] + key - 'A') % 26;
  }

  return ciphertext;
}

static std::string decipher_no_key(std::string ciphertext) {
  for (int c = 0; c <= 26; ++c) {
    std::string plaintext = decipher(ciphertext, c);
    if (has_star_in_it(plaintext)) {
      return plaintext;
    }
  }

  return "???";
}

int main(int argc, char* argv[]) {
  std::cout << decipher_no_key(argv[1]) << "\n";
}
