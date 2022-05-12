/*
 * Tyler Filla
 * OPC19 - Program 8
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

struct node {
  struct node* child_a;
  struct node* child_b;

  int value;

  void preorder();
};

void node::preorder() {
  std::cout << value;

  if (child_a) {
    std::cout << " "; // space before next element
    child_a->preorder();
  }
  if (child_b) {
    std::cout << " "; // space before next element
    child_b->preorder();
  }
}

static int which_way(node* sub, int num) {
  if (num < sub->value) {
    return -1; // go left
  }

  if (num > sub->value) {
    return 1; // go right
  }

  return 0; // nowhere to go
}

static void insert(node* child, node* parent) {
  if (child->value < parent->value) {
    if (parent->child_a) {
      insert(child, parent->child_a);
    } else {
      parent->child_a = child;
    }
  } else if (child->value >= parent->value) { // default equals
    if (parent->child_b) {
      insert(child, parent->child_b);
    } else {
      parent->child_b = child;
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums;

  for (int i = 1; i < argc; ++i) {
    nums.push_back(std::atoi(argv[i]));
  }

  // first one
  node* tree = new node;
  tree->value = nums[0];
  tree->child_a = NULL;
  tree->child_b = NULL;

  for (int i = 1; i < nums.size(); ++i) {
    int num = nums[i];

    node* new_node = new node;
    new_node->value = num;
    new_node->child_a = NULL;
    new_node->child_b = NULL;

    insert(new_node, tree);
  }

  tree->preorder(); // traverse it
  std::cout << "\n";
}
