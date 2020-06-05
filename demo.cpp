#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  float A[100][100];
  float B[100];
  int n = 3, m = 4;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> A[i][j];
    }
  }
  for(int i = 1; i <= n; i++){
    cout << endl;
    for(int j = 1; j <= m; j++){
      cout << A[i][j] << " ";
    }
  }
  float sum = 0;
  cout << endl;
  // cau 6 - tong cua tung hang
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      sum = A[i][j] + sum;
    }
    B[i] = sum;
    sum = 0;
  }
  for (int i = 1; i <=n ; i++){
    cout << B[i] << endl;
  }
  cout << sum;
  // cau 6 - tong cua tung cot
  for(int j = 1; j <=m ; j++){
    for(int i = 1; i <=n; i++){
      sum = A[i][j]  + sum;
    }
    B[j] = sum;
    sum = 0;
  }
  cout << endl;
  for(int j = 1; j <=m ; j++){
    cout << B[j] << endl;
  }
  return 0;
}
