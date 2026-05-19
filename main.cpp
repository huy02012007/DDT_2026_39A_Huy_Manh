#include <bits/stdc++.h>
using namespace std;

struct Time {
  int gio;
  int phut;
  long long TongPhut() { return gio * 60 + phut; }
};
struct Date {
  int ngay;
  int thang;
  int nam;
  void cong7ngay() {
    ngay += 7;
    if (ngay > 28) {
      ngay -= 28;
      thang += 1;
    } else if (ngay > 30) {
      ngay -= 30;
      thang += 1;
    } else if (ngay > 31) {
      ngay -= 31;
      thang += 1;
    } else if (thang > 12) {
      nam += 1;
    }
  }
  string layThu() {
    int t = thang;
    int n = nam;

    if (t < 3) {
      n--;
    }

    int mangBuSo[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int ketQua = (n + n / 4 - n / 100 + n / 400 + mangBuSo[t - 1] + ngay) % 7;

    string danhSachThu[] = {"Chu Nhat", "Thu 2", "Thu 3", "Thu 4",
                            "Thu 5",    "Thu 6", "Thu 7"};
    return danhSachThu[ketQua];
  }
};
