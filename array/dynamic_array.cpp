#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int N;
  scanf("%d", &N);
  int **arr = new int *[N];

  for (int i = 0; i < N; ++i) {
    arr[i] = new int[N];
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }

  // Empty Array after end using. It's a good practice;
  for (int i = 0; i < N; ++i) {
    delete arr[i]; // one-by-one row and deleting pointer to that array
  }
  delete[] arr; // deleting the pointer to this array

  return 0;
}
