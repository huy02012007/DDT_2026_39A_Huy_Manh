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
class nguoi {
protected:
  string HoTen;
  string SDT;

public:
  nguoi() {}
  nguoi(string ten, string sdt) {
    HoTen = ten;
    SDT = sdt;
  }
  void NhapThongTin() {
    cout << "Nhap ho ten : ";
    getline(cin, HoTen);
    cout << "Nhap so dien thoai : ";
    getline(cin, SDT);
  }
  void InThongTin() {
    cout << "Nguoi dung : " << HoTen << "| So dien thoai : " << SDT << endl;
  }
  string getHoTen() { return HoTen; }
  string getSDT() { return SDT; }
};
class KhachHang : public nguoi {
private:
  int DiemTichLuy;

public:
  KhachHang() : nguoi() { DiemTichLuy = 0; }
  KhachHang(string ten, string sdt, int diem) : nguoi(ten, sdt) {
    DiemTichLuy = diem;
  }
  string HangThanhVien() {
    if (DiemTichLuy >= 300)
      return "VIP";
    if (DiemTichLuy >= 150)
      return "Gold";
    if (DiemTichLuy >= 50)
      return "Silver";
    return "Normal";
  }
};
class NguoiDung : public nguoi {
private:
  string Taikhoan;
  string MatKhau;
  string VaiTro;

public:
  NguoiDung() : nguoi() {}
  NguoiDung(string ten, string sdt, string tk, string mk, string vitri)
      : nguoi(ten, sdt) {
    Taikhoan = tk;
    MatKhau = mk;
    VaiTro = vitri;
  }
};
