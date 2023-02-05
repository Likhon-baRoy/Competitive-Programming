#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[6][6];

    for (int x = 0; x < 6; x++) {
        for (int z = 0; z < 6; z++) {
            cin >> arr[x][z];
        }
    }
    int sum, max = -99999;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (max < sum) max = sum;
        }
    }
    cout <<  max << '\n';
    return 0;
}
