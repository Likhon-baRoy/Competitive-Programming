void primeFactor(int n) {
  int divisor = 2;
  while (n > 1) {
    if (!(n % divisor)) {
      cout << divisor << " ";
      n /= divisor;
    } else
      divisor++;
  }
}
