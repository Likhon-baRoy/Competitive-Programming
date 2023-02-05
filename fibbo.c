#include <stdio.h>

int fibbo (int, int, int);
int fibbo2 (int, int, int);

int main () {
  int a, b, c, d, n, num, sum = 0, total = 0, count = 0;
  float avg = 0, ans = 0;

  printf("Welcome!\nPlease Enter your values here : ");
  scanf("%d %d %d", &a, &b, &count);

  printf("\nYour Result is : %d", fibbo(a, b, count));

  printf("\n\n");
}
/*
	Hello Brother and Sister!!
 */
int fibbo3 (int fibIndex) {
  if (fibIndex < 2)
    return fibIndex;
  else // recursion if fibIndex >= 2
    return fibbo3(fibIndex - 1) + fibbo3(fibIndex - 2);
}

// Nah No Working !?! 🫠
int fibbo2 (int f, int l, int i) {
  i--;
  if (i <= 1) return l;

  return fibbo2(l, (f + l), i) + fibbo2((f + l), (f+ l) + l, i);
}

int fibbo (int first, int sec, int count) {

  printf("%d + %d = %d\n", first, sec, (first + sec));

  if (count < 2) return count;

  count--;

  if (count <= 1) return (first + sec);

  return  fibbo(sec, (first + sec), count);
}
