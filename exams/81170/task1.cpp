#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  vector<Node*> children;

  Node(int data) : data(data) {}
};

bool member(Node* root, int x) {
  if (root->data == x) {
    return true;
  }

  for (vector<Node*>::iterator it = root->children.begin();
       it != root->children.end(); ++it) {
    if (member(*it, x)) {
      return true;
    }
  }

  return false;
}

void eraseNode(Node* node) {
  for (vector<Node*>::iterator it = node->children.begin();
       it != node->children.end(); ++it) {
    eraseNode(*it);
    node->children.erase(it);
    --it;
  }
  delete node;
}

void filterOdd(Node* root) {
  if (root->data % 2 != 0) {
    eraseNode(root);
    return;
  }

  for (vector<Node*>::iterator it = root->children.begin();
       it != root->children.end(); ++it) {
    if ((*it)->data % 2 != 0) {
      eraseNode(*it);

      root->children.erase(it);
      --it;
    } else {
      filterOdd(*it);
    }
  }
}

void printTree(Node* root) {
  if (root == nullptr) {
    return;
  }

  cout << root->data << ' ';
  for (vector<Node*>::iterator it = root->children.begin();
       it != root->children.end(); ++it) {
    printTree(*it);
  }
}

int main() {
  Node* root = new Node(10);
  Node* t1 = new Node(4);
  t1->children = {new Node(5), new Node(6)};
  root->children = {new Node(2), t1, new Node(7)};

  cout << boolalpha << member(root, 5) << '\n';

  printTree(root);
  cout << '\n';

  filterOdd(root);

  printTree(root);
  cout << '\n';

  return 0;
}