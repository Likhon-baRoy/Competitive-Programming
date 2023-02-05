// Sequence Containers - Array

// Static contiguous array

#include <array>
#include <iostream>

using namespace std;

int main() {
  array<int, 5> a;

  cout << "Enter the 5 numbers: ";
  for (int i(0); i < a.size(); ++i) {
    cin >> a[i];
  }

  int temp;
  for (int i(0); i < a.size() - 1; ++i)
    for (int j(i); j < a.size(); ++j)
      if (a[i] > a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }

  for (int i(0); i < a.size(); ++i) {
    cout << a[i] << ' ';
  }

  return 0;
}
