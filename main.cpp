#include <bits/stdc++.h>
#include <iomanip>
#include <string>
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
  static int so_luong_user;
  NguoiDung() : nguoi() {}
  NguoiDung(string ten, string sdt, string tk, string mk, string vitri)
      : nguoi(ten, sdt) {
    Taikhoan = tk;
    MatKhau = mk;
    VaiTro = vitri;
    so_luong_user++;
  }
  string gettk() { return Taikhoan; }
  string getmk() { return MatKhau; }
  string getvaitro() { return VaiTro; }
};
int NguoiDung::so_luong_user = 0;
class CauLong {
private:
  string IDsan;
  string TenSan;
  string TrangThai;

public:
  static int so_luong_san;
  CauLong() {}
  CauLong(string ID, string tensan, string trangthai) {
    IDsan = ID;
    TenSan = tensan;
    TrangThai = trangthai;
    so_luong_san++;
  }
  string getID() { return IDsan; }
  string getTenSan() { return TenSan; }
  string getTrangThai() { return TrangThai; }
  void setTrangThai(string tt) { TrangThai = tt; }
};
int CauLong::so_luong_san = 0;
class DichVu {
private:
  string IDsp;
  string tensp;
  long long DonGia;
  int SoLuongTonKho;

public:
  static int so_luong_dv;
  DichVu() {}
  DichVu(string ID, string ten, long long gia, int soluong) {
    IDsp = ID;
    tensp = ten;
    DonGia = gia;
    SoLuongTonKho = soluong;
    so_luong_dv++;
  }
  string getIDsp() { return IDsp; }
  string gettensp() { return tensp; }
  long long getdongia() { return DonGia; }
  int getsoluongtonkho() { return SoLuongTonKho; }
  void ton_kho_sau_khi_ban(int so_luong_mua) {
    SoLuongTonKho = SoLuongTonKho - so_luong_mua;
  }
};
int DichVu::so_luong_dv = 0;
class DatVatDung {
private:
  string ID_dat_hang;
  string SDT_khach;
  string IDsan;
  string TrangThai;
  Date NgayDat;
  Time GioBatDau;
  Time GioKetThuc;
  string IDdich_vu_da_dat[20];
  int so_luong_dich_vu_da_dat[20];
  int dem_so_luong_dat;

public:
  DatVatDung() {}
  DatVatDung(string ID, string sdt, string IDSan, string tt, Date ngay,
             Time batdau, Time ketthuc) {
    ID_dat_hang = ID;
    SDT_khach = sdt;
    IDsan = IDSan;
    TrangThai = tt;
    NgayDat = ngay;
    GioBatDau = batdau;
    GioKetThuc = ketthuc;
    dem_so_luong_dat = 0;
  }
  string getID_dat_hang() { return ID_dat_hang; }
  string getSDT_khach() { return SDT_khach; }
  string getIDsan() { return IDsan; }
  string getTrangThai() { return TrangThai; }
  Date getNgayDat() { return NgayDat; }
  Time getGioBatDau() { return GioBatDau; }
  Time getGioKetThuc() { return GioKetThuc; }
  void setTrangThai(string tt) { TrangThai = tt; }
  void them_dich_vu(string id_dich_vu, int so_luong) {
    IDdich_vu_da_dat[dem_so_luong_dat] = id_dich_vu;
    so_luong_dich_vu_da_dat[dem_so_luong_dat] = so_luong;
    dem_so_luong_dat++;
  }
  int getDemSoLuongDat() { return dem_so_luong_dat; }
  string getIDDichVuDaDat(int vitri) { return IDdich_vu_da_dat[vitri]; }
  int getsoluongdichvudadat(int vitri) {
    return so_luong_dich_vu_da_dat[vitri];
  }
};
CauLong *ds_san;
DichVu *ds_dichvu;
NguoiDung *ds_nguoi_dung;
void khoi_tao_gia_tri() {
  ds_san = new CauLong[20];
  ds_dichvu = new DichVu[50];
  ds_nguoi_dung = new NguoiDung[20];
  ds_san[0] = CauLong("SNT01", "SAN THUONG 1", "Trong");
  ds_san[1] = CauLong("SNT02", "SAN THUONG 2", "Trong");
  ds_san[2] = CauLong("SNT03", "SAN THUONG 3", "Trong");
  ds_san[3] = CauLong("SNT04", "SAN THUONG 4", "Trong");
  ds_dichvu[0] = DichVu("DV01", "Nuoc loc", 10000, 100);
  ds_dichvu[1] = DichVu("DV02", "Quan can vot", 15000, 100);
  ds_dichvu[2] = DichVu("DV03", "Cau le", 30000, 100);
  ds_dichvu[3] = DichVu("DV04", "Hop cau", 300000, 100);
  ds_nguoi_dung[0] = NguoiDung("H.Huy", "0868880087", "1", "1", "admin");
}
string xu_li_dang_nhap() {
  int chon1;
  string vai_tro_can_tim;
  cout << "Vui long chon vai tro de he thong khoi dong (1.Admin | 2.Staff) : ";
  cin >> chon1;
  if (chon1 == 1)
    vai_tro_can_tim = "admin";
  if (chon1 == 2)
    vai_tro_can_tim = "staff";
  string username, pass;
  cin.ignore();
  cout << "Vui long nhap tai khoan : ";
  getline(cin, username);
  cout << "Mat Khau : ";
  getline(cin, pass);
  for (int i = 0; i < NguoiDung::so_luong_user; i++) {
    if (ds_nguoi_dung[i].gettk() == username &&
        ds_nguoi_dung[i].getmk() == pass &&
        ds_nguoi_dung[i].getvaitro() == vai_tro_can_tim)
      return ds_nguoi_dung[i].getvaitro();
  }
  return "";
}
void ve_duong_ngang(string goctrai, string gocphai, int dorong) {
  cout << goctrai;
  for (int i = 0; i < dorong; i++) {
    cout << "─";
  }
  cout << gocphai << "\n";
}
int do_rong = 55;
void thiet_lap_gia_thue() {
  int chon;
  long long gio_thuong = 30000;
  long long gio_cao_diem = 40000;
  long long gio_cuoi_tuan = 50000;
  while (true) {
    ve_duong_ngang("┌", "┐", do_rong);
    cout << "│" << left << setw(do_rong) << "                THIET LAP BANG GIA"
         << "│\n";
    ve_duong_ngang("├", "┤", do_rong);
    cout << "│" << left << setw(do_rong) << "[1] Xem bang gia hien tai"
         << "│\n";
    cout << "│" << left << setw(do_rong)
         << "[2] Thiet lap gia thuong (0h -> 16h)"
         << "│\n";
    cout << "│" << left << setw(do_rong)
         << "[3] Thiet lap gia gio cao diem (16h -> 22h)" << "│\n";
    cout << "│" << left << setw(do_rong) << "[4] Thiet lap gia gio cuoi tuan"
         << "│\n";
    cout << "│" << left << setw(do_rong) << "[0] Luu du lieu va quay lai"
         << "│\n";
    ve_duong_ngang("└", "┘", do_rong);
    cout << " -> Lua chon cua ban: ";
    cin >> chon;
    if (chon == 0) {
      return;
    }
    switch (chon) {
    case 1: {
      while (true) {
        string d1 = "[1] Gia hien tai gio thuong la : " + to_string(gio_thuong);
        string d2 =
            "[2] Gia hien tai gio cao diem la : " + to_string(gio_cao_diem);
        string d3 =
            "[3] Gia hien tai gio cuoi tuan la : " + to_string(gio_cuoi_tuan);
        string d0 = "[0] Quay lai";
        ve_duong_ngang("┌", "┐", do_rong);
        cout << "│" << left << setw(do_rong)
             << "             BANG GIA SAN CAU LONG HIEN TAI"
             << "│\n";
        ve_duong_ngang("├", "┤", do_rong);
        cout << "│" << left << setw(do_rong) << d1 << "│\n";
        cout << "│" << left << setw(do_rong) << d2 << "│\n";
        cout << "│" << left << setw(do_rong) << d3 << "│\n";
        cout << "│" << left << setw(do_rong) << d0 << "│\n";
        ve_duong_ngang("└", "┘", do_rong);
        cout << "Nhan phim 0 de quay lai : ";
        int quaylai;
        cin >> quaylai;
        if (quaylai == 0) {
          break;
        }
      }
      break;
    }
    case 2: {
      {
        cout << "Vui long nhap gia thuong muon thay doi : ";
        cin >> gio_thuong;
        cout << "\033[31m -> Da cap nhap hoan tat!\033[0m\n";
      }
      break;
    }
    case 3: {
      {
        cout << "Vui long nhap gia gio cao diem muon thay doi : ";
        cin >> gio_cao_diem;
        cout << "\033[31m -> Da cap nhap hoan tat!\033[0m\n";
      }
      break;
    }
    case 4: {
      {
        cout << "Vui long nhap gia cuoi tuan muon thay doi : ";
        cin >> gio_cuoi_tuan;
        cout << "\033[31m -> Da cap nhap hoan tat!\033[0m\n";
      }
      break;
    }
    }
  }
}
void quan_li_ds_san() {
  int chon;
  while (true) {
    ve_duong_ngang("┌", "┐", do_rong);
    cout << "│" << left << setw(do_rong) << "             QUAN LY DANH SACH SAN"
         << "│\n";
    ve_duong_ngang("├", "┤", do_rong);
    cout << "│" << left << setw(do_rong) << "[1] Xem danh sach san hien tai"
         << "│\n";
    cout << "│" << left << setw(do_rong) << "[2] Them san"
         << "│\n";
    cout << "│" << left << setw(do_rong) << "[3] Xoa san" << "│\n";
    cout << "│" << left << setw(do_rong) << "[0] Luu du lieu va quay lai"
         << "│\n";
    ve_duong_ngang("└", "┘", do_rong);
    cout << " -> Lua chon cua ban: ";
    cin >> chon;
    switch (chon) {
    case 1: {
      while (true) {
        ve_duong_ngang("┌", "┐", do_rong);
        cout << "│" << left << setw(do_rong)
             << "             DANH SACH SAN CAU LONG"
             << "│\n";
        ve_duong_ngang("├", "┤", do_rong);
        cout << "│ " << left << setw(12) << "  MA SAN"
             << "│ " << left << setw(22) << "      TEN SAN"
             << "│ " << left << setw(do_rong - 39) << "   TRANG THAI" << "│\n";
        ve_duong_ngang("├", "┤", do_rong);
        for (int i = 0; i < CauLong::so_luong_san; i++) {
          cout << "│ " << left << setw(12) << ("  " + ds_san[i].getID()) << "│ "
               << left << setw(22) << ("   " + ds_san[i].getTenSan()) << "│ "
               << left << setw(do_rong - 39)
               << ("      " + ds_san[i].getTrangThai()) << "│\n";
        }
        ve_duong_ngang("└", "┘", do_rong);
        cout << "-> Nhan phim 0 de quay lai : ";
        int quaylai;
        cin >> quaylai;
        if (quaylai == 0) {
          break;
        }
      }
      break;
    }
    case 2: {
      int so_san;
      cout << "-> Vui long nhap so luong san muon them : ";
      cin >> so_san;

      for (int i = 0; i < so_san; i++) {
        int vitri = CauLong::so_luong_san;

        string id_moi = "SNT0" + to_string(vitri + 1);
        string ten_moi = "SAN THUONG " + to_string(vitri + 1);

        ds_san[vitri] = CauLong(id_moi, ten_moi, "Trong");
      }
      cout << "\033[32m -> Da them san thanh cong " << so_san
           << " san thanh cong!\033[0m\n";
      break;
    }
    case 3: {
      int so_san;
      cout << "-> Vui long nhap so luong san muon xoa : ";
      cin >> so_san;
      for (int i = 0; i < so_san; i++) {
        CauLong::so_luong_san--;
      }
      cout << "\033[32m -> Da xoa san thanh cong " << so_san
           << " san thanh cong!\033[0m\n";
      break;
    }
    case 0: {
      break;
    }
    }
    break;
  }
}
void menu_admin() {
  int chon;
  while (true) {
    ve_duong_ngang("┌", "┐", do_rong);
    cout << "│" << left << setw(do_rong)
         << "               MENU QUAN LY (ADMIN)" << "│\n";
    ve_duong_ngang("├", "┤", do_rong);
    cout << "│" << left << setw(do_rong)
         << " [1] Tat ca cac chuc nang cua Nhan vien" << "│\n";
    cout << "│" << left << setw(do_rong)
         << " [2] Thiet lap gia thue san va khung gio" << "│\n";
    cout << "│" << left << setw(do_rong)
         << " [3] Quan ly danh sach san (Them/Xoa)" << "│\n";
    cout << "│" << left << setw(do_rong)
         << " [4] Quan ly kho hang & Gia nuoc/cau/cuon can" << "│\n";
    cout << "│" << left << setw(do_rong)
         << " [5] Quan ly tai khoan Nhan vien (Them/Xoa)" << "│\n";
    cout << "│" << left << setw(do_rong)
         << " [6] Xem bao cao doanh thu va hieu suat san" << "│\n";
    cout << "│" << left << setw(do_rong) << " [0] Dang xuat khoi he thong"
         << "│\n";
    ve_duong_ngang("└", "┘", do_rong);

    cout << " -> Lua chon cua ban: ";
    cin >> chon;
    switch (chon) {
    case 1:
      break;
    case 2:
      thiet_lap_gia_thue();
      break;
    case 3:
      quan_li_ds_san();
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 0:
      return;
    default:
      cout << "Nhap sai, vui long nhap lai!\n";
    }
  }
}
int main() {
  khoi_tao_gia_tri();

  int chon;
  while (true) {
    cout << "\n--- HE THONG QUAN LY SAN CAU LONG ---\n";
    cout << "[1] Dang nhap\n";
    cout << "[0] Thoat\n";
    cout << "Nhap lua chon cua ban (0-1) : ";
    cin >> chon;

    if (chon == 0) {
      break;
    }
    switch (chon) {
    case 1: {
      string role = xu_li_dang_nhap();
      if (role == "admin")
        menu_admin();
      else if (role == "staff")
        cout << "Bang dieu khien staff";
      else if (role == "")
        cout << "Dang nhap that bai!";
    }

    break;
    case 2:

      break;
    case 3:

      break;
    default:
      cout << "Vui long nhap lai!\n";
    }
  }

  delete[] ds_san;
  delete[] ds_dichvu;
  delete[] ds_nguoi_dung;

  return 0;
}