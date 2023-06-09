// This Recursion function check if given Array is sorted or not.
bool isSoreted(int a[], int sz) {
  if (sz == 0 || sz == 1) {
    return true;
  }
  if (a[0] > a[1]) {
    return false;
  }
  return isSoreted(a + 1, sz - 1);
}
