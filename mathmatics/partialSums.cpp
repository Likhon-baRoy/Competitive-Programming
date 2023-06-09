// Partial Sums Implementation
/*
  খুবই সহজ ব্যাপার যখন বলা হয়, নির্দিষ্ট রেঞ্জের মধ্যে অ্যারের(Array) এলিমেন্টস গুলোর
  যোগফল(sum) বের করার জন্য। একটি লোপ চালিয়ে দিলেই খেল ক্ষতম! যার কমপ্লেক্সিটি হবে
  O(n), এটা একদমই সঠিক পদ্ধতি। কিন্তু কেমন হবে যদি আমরা এটিকে আরো এফিশিয়েন্ট করে
  O(1) এ নিয়ে আসতে পারি??
  হ্যাঁ ঠিক তাই, এখানে আমরা সেটাই দেখবো!
  প্রথমে আমরা অ্যারের প্রতিটি এলিমেন্টকে যোগ করে করে, আরেকটি sum[] নামক অ্যারেতে
  রেখেছি। তারপর খুবই সহজ, শুধু রেইঞ্জ বলা যে, X to Y তমর সাম বের করতে হবে। আমরা
  শুধু বড় ইনডেক্সটি থেকে ছোট ইনডেক্সটির পরবর্তী ইনডেক্স এর সাম বাদ দিলেই উত্তর পেয়ে
  যাব।
we know,
    sum[i] = sum of first i elements
    sum(left, right) = sum[right] - sum[left-1];
*/

/*
  আমি এখানে মেইন ফাংকশনের ভিতরে একভাবে করেছি ও ফাংকশন ডিক্লারেশনের মাধ্যমে
  আরেকভাবে দেখিয়েছি। টেষ্টকেস দিয়ে পরীক্ষা করলেই বুঝতে পারবে।
*/

#include <bits/stdc++.h>
using namespace std;

int s[INT_MAX];
void buildPartialSum(int a[], int N);
long long query(int x, int y);

int main() {
  int n;
  cin >> n;

  int arr[n];
  long long sum[n];
  /*
    Let's assume the Array is, arr = {7, -2, 3, 9, -11, 5, 1, -3};
    Now, sum of the Array is, sum = {7, 5, 8, 17, 6, 11, 12, 9};
  */
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0)
      sum[i] = arr[i];
    else {
      sum[i] = sum[i - 1] + arr[i];
    }
  }
  int x, y;
  cin >> x >> y;

  for (auto &i : sum)
    cout << i << " ";
  cout << "\n";

  cout << (sum[y] - sum[x - 1]) << "\n";

  return 0;
}

void buildPartialSum(int a[], int N) {
  // খেয়ার কোরো এখানে গণনা কিন্তু জিরো ইনডেক্স থেকে শুরু।
  s[0] = a[0];
  for (int i = 0; i < N; ++i) {
    s[i] = s[i - 1] + a[i];
  }
}

long long query(int x, int y) { return (s[y] - s[x - 1]); }
