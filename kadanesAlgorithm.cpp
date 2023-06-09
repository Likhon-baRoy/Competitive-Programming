int kadanesAlgo(vi a) {
  int curr_max = a[0], max_so_far = a[0];
  rep(i, 1, sz(a)) {
    curr_max = max(a[i], curr_max + a[i]);
    max_so_far = max(curr_max, max_so_far);
  }
  return max_so_far;
}
