#include <bits/stdc++.h>
using namespace std;

struct Time {
  int Gio;
  int Phut;
  long long TongPhut() { return Gio * 60 + Phut; }
  bool operator>(Time const &khac) {
    int TongPhutBatDau = Gio * 60 + Phut;
    int TongPhutKetThuc = khac.Gio * 60 + khac.Phut;
    return TongPhutBatDau > TongPhutKetThuc;
  }
  bool operator<(Time const &Khac) {
    int TongPhutBatDau = Gio * 60 + Phut;
    int TongPhutKetThuc = Khac.Gio * 60 + Khac.Phut;
    return TongPhutBatDau < TongPhutKetThuc;
  }
};
struct Date {
  int Ngay;
  int Thang;
  int Nam;
  bool operator==(Date const &Khac) {
    return (Ngay == Khac.Ngay && Thang == Khac.Thang && Nam == Khac.Nam);
  }

  string LayThu() {
    int t = Thang;
    int n = Nam;

    if (t < 3) {
      n--;
    }

    int MangBuSo[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int KetQua = (n + n / 4 - n / 100 + n / 400 + MangBuSo[t - 1] + Ngay) % 7;

    string DanhSachThu[] = {"Chu Nhat", "Thu 2", "Thu 3", "Thu 4",
                            "Thu 5",    "Thu 6", "Thu 7"};
    return DanhSachThu[KetQua];
  }
};
class Nguoi {
protected:
  string HoTen;
  string SDT;

public:
  Nguoi() {}
  Nguoi(string ten, string sdt) {
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
  string GetHoTen() { return HoTen; }
  string GetSDT() { return SDT; }
};
class KhachHang : public Nguoi {
private:
  int DiemTichLuy;

public:
  KhachHang() : Nguoi() { DiemTichLuy = 0; }
  static int SoLuongHoiVien;
  KhachHang(string ten, string sdt, int diem) : Nguoi(ten, sdt) {
    SoLuongHoiVien++;
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
  void CongDiem(int TienThanhToan) { DiemTichLuy += (TienThanhToan / 10000); }
  int GetDienTichLuy() { return DiemTichLuy; }
};
int KhachHang::SoLuongHoiVien = 0;
class NguoiDung : public Nguoi {
private:
  string Taikhoan;
  string MatKhau;
  string VaiTro;

public:
  static int SoLuongUser;
  NguoiDung() : Nguoi() {}
  NguoiDung(string ten, string sdt, string tk, string mk, string vitri)
      : Nguoi(ten, sdt) {
    Taikhoan = tk;
    MatKhau = mk;
    VaiTro = vitri;
    SoLuongUser++;
  }
  string GetTK() { return Taikhoan; }
  string GetMK() { return MatKhau; }
  string GetVaiTro() { return VaiTro; }
};
int NguoiDung::SoLuongUser = 0;
class CauLong {
private:
  string IDsan;
  string TenSan;
  string TrangThai;

public:
  static int SoLuongSan;
  CauLong() {}
  CauLong(string ID, string tensan, string trangthai) {
    IDsan = ID;
    TenSan = tensan;
    TrangThai = trangthai;
    SoLuongSan++;
  }
  string GetID() { return IDsan; }
  string GetTenSan() { return TenSan; }
  string GetTrangThai() { return TrangThai; }
  void SetTrangThai(string tt) { TrangThai = tt; }
};
int CauLong::SoLuongSan = 0;
class DichVu {
private:
  string IDSP;
  string TenSp;
  long long DonGia;
  int SoLuongTonKho;
  int SoLuongMua;

public:
  static int SoLuongDV;
  DichVu() {}
  DichVu(string ID, string ten, long long gia, int soluong) {
    IDSP = ID;
    TenSp = ten;
    DonGia = gia;
    SoLuongTonKho = soluong;
    SoLuongDV++;
  }
  void SetSoLuongDaBan(int sl) { SoLuongMua = sl; }
  void NhapThamHang(int SoLuongNhap) {
    SoLuongTonKho = SoLuongTonKho + SoLuongNhap;
  }
  string GetIDSP() { return IDSP; }
  string GetTenSP() { return TenSp; }
  long long GetDonGia() { return DonGia; }
  int GetSoLuongTonKho() { return SoLuongTonKho; }
  void TonKhoSauKhiBan(int SoLuongMua) {
    this->SoLuongMua += SoLuongMua;
    SoLuongTonKho = SoLuongTonKho - SoLuongMua;
  }
  int GetSoLuongDaBan() { return SoLuongMua; }
};
int DichVu::SoLuongDV = 0;
class DatVatDung {
private:
  string IDKhachHang;
  string SDTKhach;
  string IDSan;
  string TrangThai;
  Date NgayDat;
  Time GioBatDau;
  Time GioKetThuc;
  Time GioThucTe;
  Time GioThucTeLucVe;
  string IDDichVuDaDat[20];
  int SoLuongDichVuDaDat[20];
  int DemSoLuongDat;
  long long TongTienBill = 0;

public:
  static int SoLuongSanDaDat;
  DatVatDung() {}
  DatVatDung(string ten, string sdt, string MaSan, string tt, Date ngay,
             Time batdau, Time ketthuc) {
    IDKhachHang = ten;
    SDTKhach = sdt;
    IDSan = MaSan;
    TrangThai = tt;
    NgayDat = ngay;
    GioBatDau = batdau;
    GioKetThuc = ketthuc;
    DemSoLuongDat = 0;
    SoLuongSanDaDat++;
  }
  void SetTongTienBill(long long Tien) { TongTienBill = Tien; }
  long long GetTongTienBill() { return TongTienBill; }
  void SetGioThucTeLucVe(Time GioKhacLucVe) { GioThucTeLucVe = GioKhacLucVe; }
  void SetGioThucTe(Time GioKhac) { GioThucTe = GioKhac; }
  string GetIDDatHang() { return IDKhachHang; }
  string GetSDTKhach() { return SDTKhach; }
  string GetIDSan() { return IDSan; }
  string GetTrangThai() { return TrangThai; }
  Date GetNgayDat() { return NgayDat; }
  Time GetGioBatDau() { return GioBatDau; }
  Time GetGioKetThuc() { return GioKetThuc; }
  Time GetGioThucTe() { return GioThucTe; }
  void SetTrangThai(string tt) { TrangThai = tt; }
  void ThemDichVu(string IDDichVu, int SoLuong) {
    IDDichVuDaDat[DemSoLuongDat] = IDDichVu;
    SoLuongDichVuDaDat[DemSoLuongDat] = SoLuong;
    DemSoLuongDat++;
  }
  int GetDemSoLuongDat() { return DemSoLuongDat; }
  string GetIDDichVuDaDat(int ViTri) { return IDDichVuDaDat[ViTri]; }
  int GetSoLuongDichVuDaDat(int ViTri) { return SoLuongDichVuDaDat[ViTri]; }
};
int DatVatDung::SoLuongSanDaDat = 0;
DatVatDung *DSSanDaDat;
KhachHang *DSKhachHang;
CauLong *DSSan;
DichVu *DSDichVu;
NguoiDung *DSNguoiDung;
void KhoiTaoGiaTri() {
  DSSanDaDat = new DatVatDung[20];
  DSKhachHang = new KhachHang[50];
  DSSan = new CauLong[20];
  DSDichVu = new DichVu[50];
  DSNguoiDung = new NguoiDung[20];
  DSKhachHang[0] = KhachHang("Huy", "0868880087", 0);
  DSSan[0] = CauLong("SNT01", "SAN THUONG 1", "Trong");
  DSSan[1] = CauLong("SNT02", "SAN THUONG 2", "Trong");
  DSSan[2] = CauLong("SNT03", "SAN THUONG 3", "Trong");
  DSSan[3] = CauLong("SNT04", "SAN THUONG 4", "Trong");
  DSDichVu[0] = DichVu("DV01", "Nuoc loc", 10000, 100);
  DSDichVu[1] = DichVu("DV02", "Quan can vot", 15000, 100);
  DSDichVu[2] = DichVu("DV03", "Cau le", 30000, 100);
  DSDichVu[3] = DichVu("DV04", "Hop cau", 300000, 100);
  DSNguoiDung[0] = NguoiDung("H.Huy", "0868880087", "1", "1", "admin");
}

string XuLiDangNhap() {
  int Chon;
  string VaiTroCanTim;
  cout << "Vui long chon vai tro de he thong khoi dong (1.Admin | 2.Staff) : ";
  cin >> Chon;
  if (Chon == 1)
    VaiTroCanTim = "admin";
  if (Chon == 2)
    VaiTroCanTim = "staff";
  string UserName, Pass;
  cin.ignore();
  cout << "Vui long nhap tai khoan : ";
  getline(cin, UserName);
  cout << "Mat Khau : ";
  getline(cin, Pass);
  for (int i = 0; i < NguoiDung::SoLuongUser; i++) {
    if (DSNguoiDung[i].GetTK() == UserName && DSNguoiDung[i].GetMK() == Pass &&
        DSNguoiDung[i].GetVaiTro() == VaiTroCanTim)
      return DSNguoiDung[i].GetVaiTro();
  }
  return "";
}
void VeDuongNgang(string GocTrai, string GocPhai, int DoRong) {
  cout << GocTrai;
  for (int i = 0; i < DoRong; i++) {
    cout << "─";
  }
  cout << GocPhai << "\n";
}
int DoRong = 55;
int GioThuong = 30000;
int GioCaoDiem = 40000;
int GioCuoiTuan = 30000;
void ThietLapGiaThue() {
  int Chon;
  while (true) {
    VeDuongNgang("┌", "┐", DoRong);
    cout << "│" << left << setw(DoRong) << "                THIET LAP BANG GIA"
         << "│\n";
    VeDuongNgang("├", "┤", DoRong);
    cout << "│" << left << setw(DoRong) << "[1] Xem bang gia hien tai"
         << "│\n";
    cout << "│" << left << setw(DoRong)
         << "[2] Thiet lap gia thuong (0h -> 16h)"
         << "│\n";
    cout << "│" << left << setw(DoRong)
         << "[3] Thiet lap gia gio cao diem (16h -> 22h)" << "│\n";
    cout << "│" << left << setw(DoRong) << "[4] Thiet lap gia gio cuoi tuan"
         << "│\n";
    cout << "│" << left << setw(DoRong) << "[0] Luu du lieu va quay lai"
         << "│\n";
    VeDuongNgang("└", "┘", DoRong);
    cout << " -> Lua chon cua ban: ";
    cin >> Chon;
    if (Chon == 0) {
      return;
    }
    switch (Chon) {
    case 1: {
      while (true) {
        string d1 = "[1] Gia hien tai gio thuong la : " + to_string(GioThuong);
        string d2 =
            "[2] Gia hien tai gio cao diem la : " + to_string(GioCaoDiem);
        string d3 =
            "[3] Gia hien tai gio cuoi tuan la : " + to_string(GioCuoiTuan);
        string d0 = "[0] Quay lai";
        VeDuongNgang("┌", "┐", DoRong);
        cout << "│" << left << setw(DoRong)
             << "             BANG GIA SAN CAU LONG HIEN TAI"
             << "│\n";
        VeDuongNgang("├", "┤", DoRong);
        cout << "│" << left << setw(DoRong) << d1 << "│\n";
        cout << "│" << left << setw(DoRong) << d2 << "│\n";
        cout << "│" << left << setw(DoRong) << d3 << "│\n";
        cout << "│" << left << setw(DoRong) << d0 << "│\n";
        VeDuongNgang("└", "┘", DoRong);
        cout << "Nhan phim 0 de quay lai : ";
        int QuayLai;
        cin >> QuayLai;
        if (QuayLai == 0) {
          break;
        }
      }
      break;
    }
    case 2: {
      {
        do {
          cout << "Vui long nhap gia thuong muon thay doi: ";
          cin >> GioThuong;
        } while (GioThuong < 0);
        cout << "\033[31m -> Da cap nhap hoan tat!\033[0m\n";
      }
      break;
    }
    case 3: {
      {
        do {
          cout << "Vui long nhap gia gio cao diem muon thay doi: ";
          cin >> GioCaoDiem;
        } while (GioCaoDiem < 0);
        cout << "\033[31m -> Da cap nhap hoan tat!\033[0m\n";
      }
      break;
    }
    case 4: {
      {
        do {
          cout << "Vui long nhap gia cuoi tuan muon thay doi: ";
          cin >> GioCuoiTuan;
        } while (GioCuoiTuan < 0);
        cout << "\033[31m -> Da cap nhap hoan tat!\033[0m\n";
      }
      break;
    }
    }
  }
}
void HienThiTrangThaiSan() {
  VeDuongNgang("┌", "┐", DoRong);
  cout << "│" << left << setw(DoRong) << "             DANH SACH SAN CAU LONG"
       << "│\n";
  VeDuongNgang("├", "┤", DoRong);
  cout << "│ " << left << setw(12) << "  MA SAN"
       << "│ " << left << setw(22) << "      TEN SAN"
       << "│ " << left << setw(DoRong - 39) << "   TRANG THAI" << "│\n";
  VeDuongNgang("├", "┤", DoRong);
  for (int i = 0; i < CauLong::SoLuongSan; i++) {
    cout << "│ " << left << setw(12) << ("  " + DSSan[i].GetID()) << "│ "
         << left << setw(22) << ("   " + DSSan[i].GetTenSan()) << "│ " << left
         << setw(DoRong - 39) << ("      " + DSSan[i].GetTrangThai()) << "│\n";
  }
  VeDuongNgang("└", "┘", DoRong);
}
void QuanLiDSSan() {
  int Chon;
  while (true) {
    VeDuongNgang("┌", "┐", DoRong);
    cout << "│" << left << setw(DoRong) << "             QUAN LY DANH SACH SAN"
         << "│\n";
    VeDuongNgang("├", "┤", DoRong);
    cout << "│" << left << setw(DoRong) << "[1] Xem danh sach san hien tai"
         << "│\n";
    cout << "│" << left << setw(DoRong) << "[2] Them san"
         << "│\n";
    cout << "│" << left << setw(DoRong) << "[3] Xoa san" << "│\n";
    cout << "│" << left << setw(DoRong) << "[0] Luu du lieu va quay lai"
         << "│\n";
    VeDuongNgang("└", "┘", DoRong);
    cout << " -> Lua chon cua ban: ";
    cin >> Chon;
    if (Chon == 0) {
      break;
    }
    switch (Chon) {
    case 1: {
      while (true) {
        HienThiTrangThaiSan();
        cout << "-> Nhan phim 0 de quay lai : ";
        int QuayLai;
        cin >> QuayLai;
        if (QuayLai == 0) {
          break;
        }
      }
      break;
    }
    case 2: {
      int SoSan;
      cout << "-> Vui long nhap so luong san muon them : ";
      cin >> SoSan;

      for (int i = 0; i < SoSan; i++) {
        int ViTri = CauLong::SoLuongSan;

        string IDMoi = "SNT0" + to_string(ViTri + 1);
        string TenMoi = "SAN THUONG " + to_string(ViTri + 1);

        DSSan[ViTri] = CauLong(IDMoi, TenMoi, "Trong");
      }
      cout << "\033[32m -> Da them san thanh cong " << SoSan
           << " san thanh cong!\033[0m\n";
      break;
    }
    case 3: {
      int SoSan;
      cout << "-> Vui long nhap so luong san muon xoa : ";
      cin >> SoSan;

      if (SoSan <= 0 || SoSan > CauLong::SoLuongSan) {
        cout << "\033[31m -> Loi: So luong xoa khong hop le!\033[0m\n";
        break;
      }

      for (int i = 0; i < SoSan; i++) {
        CauLong::SoLuongSan--;
      }
      cout << "\033[32m -> Da xoa san thanh cong " << SoSan << " san!\033[0m\n";
      break;
    }
    case 0: {
      break;
    }
    }
  }
}
void QuanLiKhoHang() {
  int Chon;
  while (true) {
    VeDuongNgang("┌", "┐", DoRong);
    cout << "│" << left << setw(DoRong)
         << "         MENU QUAN LI SAN PHAM KHO HANG"
         << "│\n";
    VeDuongNgang("├", "┤", DoRong);
    cout << "│" << left << setw(DoRong)
         << "[1] Xem danh sach san pham  hien tai"
         << "│\n";
    cout << "│" << left << setw(DoRong) << "[2] Them san phan ton kho"
         << "│\n";
    cout << "│" << left << setw(DoRong) << "[3] Them hoac xoa san pham"
         << "│\n";
    cout << "│" << left << setw(DoRong) << "[0] Luu du lieu va quay lai"
         << "│\n";
    VeDuongNgang("└", "┘", DoRong);
    cout << " -> Lua chon cua ban: ";
    cin >> Chon;
    if (Chon == 0) {
      break;
    }
    switch (Chon) {

    case 1: {
      while (true) {
        int DoRong = 69;
        VeDuongNgang("┌", "┐", DoRong);
        cout << "│" << left << setw(DoRong)
             << "                DANH SACH SAN PHAM KHO HANG"
             << "│\n";
        VeDuongNgang("├", "┤", DoRong);
        cout << "│" << left << setw(12) << "  MA SP"
             << "│" << left << setw(22) << "  TEN SP"
             << "│" << left << setw(15) << "  GIA BAN SP"
             << "│" << left << setw(DoRong - 53) << "  SO LUONG SP" << " │\n";
        VeDuongNgang("├", "┤", DoRong);

        for (int i = 0; i < DichVu::SoLuongDV; i++) {
          cout << "│" << left << setw(12) << ("  " + DSDichVu[i].GetIDSP())
               << "│" << left << setw(22) << ("  " + DSDichVu[i].GetTenSP())
               << "│" << left << setw(15)
               << ("  " + to_string(DSDichVu[i].GetDonGia())) << "│" << left
               << setw(DoRong - 53)
               << ("  " + to_string(DSDichVu[i].GetSoLuongTonKho())) << " │\n";
        }
        VeDuongNgang("└", "┘", DoRong);
        cout << "-> Nhan phim 0 de quay lai : ";
        int QuayLai;
        cin >> QuayLai;
        if (QuayLai == 0) {
          break;
        }
      }
      break;
    }
    case 2: {
      while (true) {
        string NhapKho;
        bool TC;
        cout << "-> Nhap mat hang muon nhap kho: ";
        cin.ignore();
        getline(cin, NhapKho);
        cout << "\n";
        cout << "-> Nhap so luong : ";
        long long SoLuong;
        cin >> SoLuong;
        while (SoLuong <= 0) {
          cout << "So luong phai lon hon 0. Nhap lai : ";
          cin >> SoLuong;
        }
        for (int i = 0; i < DichVu::SoLuongDV; i++) {
          if (NhapKho == DSDichVu[i].GetTenSP()) {
            DSDichVu[i].NhapThamHang(SoLuong);
            TC = true;
          }
        }
        if (TC == true) {
          cout << "\033[32m -> Da them san pham thanh cong!\033[0m\n";
        } else {
          cout << "\033[31m -> Loi: Khong tim thay mat hang nay trong "
                  "kho!\033[0m\n";
        }

        break;
      }
      break;
    }
    case 3: {
      int LuaChonPhu;
      cout << "\n -> Chon [1] Them SP moi | [2] Xoa SP | [0] Huy : ";
      cin >> LuaChonPhu;

      if (LuaChonPhu == 1) {
        int SoLuongThem;
        cout << "-> Nhap so luong mat hang muon them: ";
        cin >> SoLuongThem;
        for (int i = 0; i < SoLuongThem; i++) {
          string IDMoi, TenMoi;
          long long GiaMoi;
          int SLMoi;
          cout << "\n--- Nhap thong tin mon thu " << i + 1 << " ---\n";

          bool TrungID;
          do {
            TrungID = false;
            cout << "Nhap ID: ";
            cin >> IDMoi;

            for (int k = 0; k < DichVu::SoLuongDV; k++) {
              if (DSDichVu[k].GetIDSP() == IDMoi) {
                TrungID = true;
                cout << "\033[1;31m   => Loi: ID nay da co trong kho! Vui long "
                        "nhap ma khac.\033[0m\n";
                break;
              }
            }
          } while (TrungID == true);

          cin.ignore();

          bool TrungTen;
          do {
            TrungTen = false;
            cout << "Nhap Ten mat hang: ";
            getline(cin, TenMoi);

            for (int k = 0; k < DichVu::SoLuongDV; k++) {
              if (DSDichVu[k].GetTenSP() == TenMoi) {
                TrungTen = true;
                cout << "\033[1;31m   => Loi: Mat hang nay da ton tai! Vui "
                        "long nhap ten khac.\033[0m\n";
                break;
              }
            }
          } while (TrungTen == true);

          cout << "Nhap Gia ban: ";
          cin >> GiaMoi;
          cout << "Nhap So luong ton kho: ";
          cin >> SLMoi;

          int ViTriMoi = DichVu::SoLuongDV;
          DSDichVu[ViTriMoi] = DichVu(IDMoi, TenMoi, GiaMoi, SLMoi);
        }
        cout << "\033[32m -> Da them " << SoLuongThem
             << " mat hang thanh cong!\033[0m\n";
      } else if (LuaChonPhu == 2) {
        string IDXoa;
        cout << "-> Nhap Ma SP muon xoa: ";
        cin >> IDXoa;
        int ViTri = -1;
        for (int i = 0; i < DichVu::SoLuongDV; i++) {
          if (DSDichVu[i].GetIDSP() == IDXoa) {
            ViTri = i;
            break;
          }
        }
        if (ViTri == -1) {
          cout << "\033[31m -> Loi: Khong tim thay Ma SP nay trong "
                  "kho!\033[0m\n";
        } else {
          for (int i = ViTri; i < DichVu::SoLuongDV - 1; i++) {
            DSDichVu[i] = DSDichVu[i + 1];
          }
          DichVu::SoLuongDV--;
          cout << "\033[32m -> Da xoa san pham " << IDXoa
               << " thanh cong!\033[0m\n";
        }
      }
      break;
    }
    }
  }
}
void TKStaff() {
  int Chon;
  while (true) {
    VeDuongNgang("┌", "┐", DoRong);
    cout << "│" << left << setw(DoRong)
         << "         QUAN LY TAI KHOAN NHAN VIEN" << "│\n";
    VeDuongNgang("├", "┤", DoRong);
    cout << "│" << left << setw(DoRong) << " [1] Xem danh sach nhan vien"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [2] Them nhan vien moi" << "│\n";
    cout << "│" << left << setw(DoRong) << " [3] Xoa tai khoan nhan vien"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [0] Quay lai" << "│\n";
    VeDuongNgang("└", "┘", DoRong);
    cout << " -> Lua chon cua ban: ";
    cin >> Chon;

    if (Chon == 0)
      break;

    switch (Chon) {
    case 1: {
      VeDuongNgang("┌", "┐", DoRong);
      cout << "│ " << left << setw(15) << "Ho Ten"
           << "│ " << left << setw(12) << "SDT"
           << "│ " << left << setw(9) << "Tai khoan "
           << "│ " << left << setw(11) << "Mat khau" << "│\n";
      VeDuongNgang("├", "┤", DoRong);
      for (int i = 0; i < NguoiDung::SoLuongUser; i++) {
        if (DSNguoiDung[i].GetVaiTro() == "staff") {
          cout << "│ " << left << setw(15) << DSNguoiDung[i].GetHoTen() << "│ "
               << left << setw(12) << DSNguoiDung[i].GetSDT() << "│ " << left
               << setw(9) << DSNguoiDung[i].GetTK() << "│ " << left << setw(11)
               << DSNguoiDung[i].GetMK() << "│\n";
        }
      }
      VeDuongNgang("└", "┘", DoRong);

      int QuayLai;
      do {
        cout << "-> Chon 0 de quay lai: ";
        cin >> QuayLai;
      } while (QuayLai != 0);

      break;
    }
    case 2: {
      string Ten, SDT;
      cin.ignore();
      cout << "-> Nhap Ho Ten nhan vien: ";
      getline(cin, Ten);

      bool TrungSDT;
      do {
        TrungSDT = false;
        cout << "-> Nhap So dien thoai: ";
        getline(cin, SDT);

        for (int i = 0; i < NguoiDung::SoLuongUser; i++) {
          if (DSNguoiDung[i].GetSDT() == SDT) {
            TrungSDT = true;
            cout << "\033[1;31m=> Loi: So dien thoai nay da duoc dang ky! Vui "
                    "long nhap SDT khac.\033[0m\n";
            break;
          }
        }
      } while (TrungSDT == true);

      string TKMoi = SDT;
      string MkMoi = "123456";

      int ViTriMoi = NguoiDung::SoLuongUser;
      DSNguoiDung[ViTriMoi] = NguoiDung(Ten, SDT, TKMoi, MkMoi, "staff");

      cout << "\033[1;32m\n=> Them nhan vien thanh cong!\033[0m\n";
      cout << "   Tai khoan duoc cap : \033[1;33m" << TKMoi << "\033[0m\n";
      cout << "   Mat khau mac dinh  : \033[1;33m" << MkMoi << "\033[0m\n\n";
      break;
    }
    case 3: {
      string TKXoa;
      cout << "-> Nhap Tai khoan nhan vien can xoa: ";
      cin >> TKXoa;
      int ViTri = -1;
      for (int i = 0; i < NguoiDung::SoLuongUser; i++) {
        if (DSNguoiDung[i].GetTK() == TKXoa &&
            DSNguoiDung[i].GetVaiTro() == "staff") {
          ViTri = i;
          break;
        }
      }
      if (ViTri != -1) {
        for (int i = ViTri; i < NguoiDung::SoLuongUser - 1; i++) {
          DSNguoiDung[i] = DSNguoiDung[i + 1];
        }
        NguoiDung::SoLuongUser--;
        cout << "\033[1;32m=> Da xoa tai khoan " << TKXoa
             << " khoi he thong!\033[0m\n";
      } else {
        cout << "\033[1;31m=> Khong tim thay tai khoan nay!\033[0m\n";
      }
      break;
    }
    }
  }
}
void BaoCaoDoanhThu() {
  int Chon;
  while (true) {
    VeDuongNgang("┌", "┐", DoRong);
    cout << "│" << left << setw(DoRong) << "               BAO CAO DOANH THU"
         << "│\n";
    VeDuongNgang("├", "┤", DoRong);
    cout << "│" << left << setw(DoRong) << " [1] Doanh thu tong"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [2] Doanh thu theo thang va nam"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [3] Xem lich su giao dich"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [0] Quay lai" << "│\n";
    VeDuongNgang("└", "┘", DoRong);
    cout << " -> Lua chon cua ban: ";
    cin >> Chon;

    if (Chon == 0) {
      break;
    }

    switch (Chon) {
    case 1: {
      long long TongDoanhThu = 0;
      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        TongDoanhThu += DSSanDaDat[i].GetTongTienBill();
      }
      cout << "\n\033[1;32m=> TONG DOANH THU TAT CA CAC THOI DIEM: "
           << TongDoanhThu << " VND\033[0m\n\n";
      break;
    }
    case 2: {
      int ThangCanTim, NanCanTim;
      cout << "Nhap thang can xem: ";
      cin >> ThangCanTim;
      cout << "Nhap nam can xem: ";
      cin >> NanCanTim;

      long long DoanhThuThang = 0;
      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        Date ngay = DSSanDaDat[i].GetNgayDat();
        if (ngay.Thang == ThangCanTim && ngay.Nam == NanCanTim) {
          DoanhThuThang += DSSanDaDat[i].GetTongTienBill();
        }
      }
      cout << "\n\033[1;32m=> TONG DOANH THU THANG " << ThangCanTim << "/"
           << NanCanTim << ": " << DoanhThuThang << " VND\033[0m\n\n";
      break;
    }
    case 3: {
      int DoRong = 70;
      VeDuongNgang("┌", "┐", DoRong);
      cout << "│" << left << setw(DoRong)
           << "                 LICH SU GIAO DICH (DA THANH TOAN)" << "│\n";
      VeDuongNgang("├", "┤", DoRong);
      cout << "│ " << left << setw(13) << "    SDT"
           << "│ " << left << setw(9) << "  San"
           << "│ " << left << setw(13) << "   Ngay"
           << "│ " << left << setw(13) << "   Gio"
           << "│ " << left << setw(DoRong - 57) << " Tong Tien" << "│\n";
      VeDuongNgang("├", "┤", DoRong);

      bool CoGiaoDich = false;
      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        if (DSSanDaDat[i].GetTongTienBill() > 0) {
          CoGiaoDich = true;
          Date D = DSSanDaDat[i].GetNgayDat();
          string NgaySTR = to_string(D.Ngay) + "/" + to_string(D.Thang) + "/" +
                           to_string(D.Nam);

          Time Start = DSSanDaDat[i].GetGioBatDau();
          Time End = DSSanDaDat[i].GetGioKetThuc();
          string GioSTR = to_string(Start.Gio) + ":" +
                          (Start.Phut < 10 ? "0" : "") + to_string(Start.Phut) +
                          "-" + to_string(End.Gio) + ":" +
                          (End.Phut < 10 ? "0" : "") + to_string(End.Phut);

          cout << "│ " << left << setw(13) << DSSanDaDat[i].GetSDTKhach()
               << "│ " << left << setw(9) << DSSanDaDat[i].GetIDSan() << "│ "
               << left << setw(13) << NgaySTR << "│ " << left << setw(13)
               << GioSTR << "│ " << left << setw(DoRong - 57)
               << DSSanDaDat[i].GetTongTienBill() << "│\n";
        }
      }

      if (!CoGiaoDich) {
        cout << "│" << left << setw(DoRong)
             << " Khong co giao dich nao da hoan thanh!" << "│\n";
      }

      VeDuongNgang("└", "┘", DoRong);

      int QuayLai;
      do {
        cout << "-> Nhan phim 0 de quay lai: ";
        cin >> QuayLai;
      } while (QuayLai != 0);
      break;
    }
    default:
      cout
          << "\n\033[1;31mLua chon khong hop le, vui long nhap lai!\033[0m\n\n";
      break;
    }
  }
}
void MenuStaff(bool Admin = false) {
  int Chon;
  while (true) {
    VeDuongNgang("┌", "┐", DoRong);
    cout << "│" << left << setw(DoRong) << "               MENU QUAN LY (STAFF)"
         << "│\n";
    VeDuongNgang("├", "┤", DoRong);
    cout << "│" << left << setw(DoRong)
         << " [1] Xem danh sach va trang thai san" << "│\n";
    cout << "│" << left << setw(DoRong) << " [2] Dat san cho khach hang"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [3] Check-in khach den choi"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [4] Goi dich vu" << "│\n";
    cout << "│" << left << setw(DoRong)
         << " [5] Check-out va Thanh toan hoa don" << "│\n";
    cout << "│" << left << setw(DoRong)
         << " [6] Quan ly thong tin khach hang thanh vien" << "│\n";

    cout << "│" << left << setw(DoRong) << " [0] Dang xuat khoi he thong"
         << "│\n";
    VeDuongNgang("└", "┘", DoRong);
    cout << " -> Lua chon cua ban: ";
    cin >> Chon;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
      Chon = -1;
    }
    switch (Chon) {
    case 1: {
      while (true) {
        HienThiTrangThaiSan();
        int quaylai;
        cout << "-> Nhan phim 0 de quay lai : ";
        cin >> quaylai;
        if (quaylai == 0) {
          break;
        }
      }
      break;
    }
    case 2: {
      string SDT;
      string Ten;
      Date NgayChoi;
      string NgayChoiNhap;
      Time Start, End;
      string StartImport, EndImport;
      string IDSan;

      time_t HienTai = time(0);
      tm *ltm_ht = localtime(&HienTai);
      int NamHT = 1900 + ltm_ht->tm_year;
      int ThangHT = 1 + ltm_ht->tm_mon;
      int NgayHT = ltm_ht->tm_mday;
      int GioHT = ltm_ht->tm_hour;
      int PhutHT = ltm_ht->tm_min;

      cout << "Vui long nhap sdt : ";
      cin >> SDT;
      bool SanHopLe = false;
      cin.ignore();
      while (!SanHopLe) {
        cout << "Vui long nhap ma san muon dat : ";
        getline(cin, IDSan);

        for (int i = 0; i < CauLong::SoLuongSan; i++) {
          if (IDSan == DSSan[i].GetID()) {
            SanHopLe = true;
            break;
          }
        }

        if (!SanHopLe) {
          cout << "\033[1;31m=> Ma san khong ton tai! Vui long nhap lai  "
                  "\033[0m\n";
        }
      }

      bool TimThayKhach = false;
      for (int i = 0; i < KhachHang::SoLuongHoiVien; i++) {
        if (SDT == DSKhachHang[i].GetSDT()) {
          cout << "\033[1;36m=> Xin chao khach quen: "
               << DSKhachHang[i].GetHoTen() << "\033[0m\n";
          TimThayKhach = true;
          break;
        }
      }

      if (!TimThayKhach) {
        cout << "Vui long nhap ten thanh vien moi : ";
        getline(cin, Ten);
        int ViTriKhach = KhachHang::SoLuongHoiVien;
        DSKhachHang[ViTriKhach] = KhachHang(Ten, SDT, 0);
        cout << "\033[1;32mCap nhat thanh cong thanh vien moi!\033[0m\n";
      }

      cout << "Vui long chon ngay choi (YYYY-MM-DD) : ";
      getline(cin, NgayChoiNhap);

      bool NgayHopLe = false;
      while (!NgayHopLe) {
        if (NgayChoiNhap.length() != 10 || NgayChoiNhap[4] != '-' ||
            NgayChoiNhap[7] != '-') {
          cout << "\033[1;31mSai dinh dang! Vui long nhap dung (YYYY-MM-DD) : "
                  "\033[0m";
          getline(cin, NgayChoiNhap);
          continue;
        }

        int Nam = stoi(NgayChoiNhap.substr(0, 4));
        int Thang = stoi(NgayChoiNhap.substr(5, 2));
        int Ngay = stoi(NgayChoiNhap.substr(8, 2));

        int NgayToiDa = 31;
        if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11) {
          NgayToiDa = 30;
        } else if (Thang == 2) {
          if ((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0)) {
            NgayToiDa = 29;
          } else {
            NgayToiDa = 28;
          }
        }

        if (Nam < NamHT || (Nam == NamHT && Thang < ThangHT) ||
            (Nam == NamHT && Thang == ThangHT && Ngay < NgayHT) || Thang < 1 ||
            Thang > 12 || Ngay < 1 || Ngay > NgayToiDa) {
          cout << "\033[1;31mNgay khong hop le hoac o trong qua khu! Nhap lai "
                  ": \033[0m";
          getline(cin, NgayChoiNhap);
        } else {
          NgayHopLe = true;
          NgayChoi.Nam = Nam;
          NgayChoi.Thang = Thang;
          NgayChoi.Ngay = Ngay;
        }
      }

      cout << "Vui long nhap thoi gian bat dau choi (HH:MM) : ";
      getline(cin, StartImport);
      Start.Gio = stoi(StartImport.substr(0, 2));
      Start.Phut = stoi(StartImport.substr(3, 2));

      while (Start.Gio < 0 || Start.Gio > 23 || Start.Phut < 0 ||
             Start.Phut > 59 ||
             (NgayChoi.Nam == NamHT && NgayChoi.Thang == ThangHT &&
              NgayChoi.Ngay == NgayHT &&
              (Start.Gio < GioHT ||
               (Start.Gio == GioHT && Start.Phut <= PhutHT)))) {
        cout << "\033[1;31mThoi gian khong hop le hoac o trong qua khu! Vui "
                "long nhap lai (HH:MM) : \033[0m";
        getline(cin, StartImport);
        Start.Gio = stoi(StartImport.substr(0, 2));
        Start.Phut = stoi(StartImport.substr(3, 2));
      }

      cout << "Vui long nhap thoi gian ket thuc (HH:MM) : ";
      getline(cin, EndImport);
      End.Gio = stoi(EndImport.substr(0, 2));
      End.Phut = stoi(EndImport.substr(3, 2));

      while (End.Gio < 0 || End.Gio > 23 || End.Phut < 0 || End.Phut > 59 ||
             (End.Gio < Start.Gio ||
              (End.Gio == Start.Gio && End.Phut <= Start.Phut))) {
        cout << "\033[1;31mThoi gian khong hop le (phai sau gio bat dau)! Nhap "
                "lai (HH:MM) : \033[0m";
        getline(cin, EndImport);
        End.Gio = stoi(EndImport.substr(0, 2));
        End.Phut = stoi(EndImport.substr(3, 2));
      }

      bool TrungLich = false;
      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        if (IDSan == DSSanDaDat[i].GetIDSan() &&
            NgayChoi == DSSanDaDat[i].GetNgayDat() &&
            (Start < DSSanDaDat[i].GetGioKetThuc() &&
             End > DSSanDaDat[i].GetGioBatDau())) {
          cout << "\033[1;31m=> San nay gio nay ngay nay da co nguoi "
                  "dat!\033[0m\n";
          TrungLich = true;
          break;
        }
      }

      if (!TrungLich) {
        cout
            << "\033[1;32m=> Lich trong! Hop le! Tien hanh luu don...\033[0m\n";
        int ViTriMoi = DatVatDung::SoLuongSanDaDat;
        DSSanDaDat[ViTriMoi] =
            DatVatDung(Ten, SDT, IDSan, "Booked", NgayChoi, Start, End);
        for (int i = 0; i < CauLong::SoLuongSan; i++) {
          if (DSSan[i].GetID() == IDSan) {
            DSSan[i].SetTrangThai("Booked");
            break;
          }
        }
      }
      break;
    }
    case 3: {
      string SDT;
      cout << "Vui long nhap so dien thoai : ";
      cin >> SDT;
      bool TimThay = false;
      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        if (SDT == DSSanDaDat[i].GetSDTKhach() &&
            DSSanDaDat[i].GetTrangThai() == "Booked") {
          DSSanDaDat[i].SetTrangThai("Playing");
          for (int j = 0; j < CauLong::SoLuongSan; j++) {
            if (DSSan[j].GetID() == DSSanDaDat[i].GetIDSan()) {
              DSSan[j].SetTrangThai("Playing");
              break;
            }
          }
          time_t Now = time(0);
          tm *ltm = localtime(&Now);
          Time GioThucTe;
          GioThucTe.Gio = ltm->tm_hour;
          GioThucTe.Phut = ltm->tm_min;
          cout << "\033[1;32m\n=> CHECK-IN THANH CONG!\033[0m\n";
          cout << "\033[1;36mTrang thai don: Dang Choi (Playing)\033[0m\n";
          cout << "\033[1;36mGio vao san thuc te: " << GioThucTe.Gio << ":"
               << GioThucTe.Phut << "\033[0m\n";
          TimThay = true;
          DSSanDaDat[i].SetGioThucTe(GioThucTe);
          break;
        }
      }
      if (TimThay == false) {
        cout << "\033[1;31m=> Khong tim thay don dat san nao khop voi thong "
                "tin vua nhap!\033[0m\n";
      }
      break;
    }
    case 4: {

      VeDuongNgang("┌", "┐", DoRong);
      cout << "│" << left << setw(DoRong)
           << "               DANH SACH SAN DANG CHOI" << "│\n";
      VeDuongNgang("├", "┤", DoRong);

      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        if (DSSanDaDat[i].GetTrangThai() == "Playing") {
          cout << "│" << left << setw(DoRong - 35) << DSSanDaDat[i].GetIDSan()
               << left << setw(DoRong - 35) << DSSanDaDat[i].GetSDTKhach()
               << left << setw(15) << DSSanDaDat[i].GetIDDatHang() << "│\n";
        }
      }
      VeDuongNgang("└", "┘", DoRong);
      cout << "-> Chon ID San de goi them dich vu: ";
      string IDSan;
      int DoRong = 69;
      cin.ignore();
      getline(cin, IDSan);
      int ViTriDonHang = -1;
      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        if (IDSan == DSSanDaDat[i].GetIDSan() &&
            DSSanDaDat[i].GetTrangThai() == "Playing") {
          ViTriDonHang = i;
          VeDuongNgang("┌", "┐", DoRong);
          cout << "│" << left << setw(DoRong)
               << "                   DANH SACH KHO HANG" << "│\n";
          VeDuongNgang("├", "┤", DoRong);
          cout << "│" << left << setw(12) << "  MA SP"
               << "│" << left << setw(22) << "  TEN SP"
               << "│" << left << setw(15) << "  GIA BAN SP"
               << "│" << left << setw(DoRong - 53) << "  SO LUONG SP"
               << " │\n";

          VeDuongNgang("├", "┤", DoRong);
          for (int i = 0; i < DichVu::SoLuongDV; i++) {
            cout << "│" << left << setw(12) << ("  " + DSDichVu[i].GetIDSP())
                 << "│" << left << setw(22) << ("  " + DSDichVu[i].GetTenSP())
                 << "│" << left << setw(15)
                 << ("  " + to_string(DSDichVu[i].GetDonGia())) << "│" << left
                 << setw(DoRong - 53)
                 << ("  " + to_string(DSDichVu[i].GetSoLuongTonKho()))
                 << " │\n";
          }
          VeDuongNgang("└", "┘", DoRong);
        }
      }
      string IDMuaHang;
      int SoLuong;
      cout << "-> Chon ID san pham muon mua: ";
      getline(cin, IDMuaHang);
      for (int j = 0; j < DichVu::SoLuongDV; j++) {
        if (IDMuaHang == DSDichVu[j].GetIDSP()) {
          cout << "-> Nhap so luong: ";
          cin >> SoLuong;
          while (SoLuong > DSDichVu[j].GetSoLuongTonKho()) {
            cout << "\033[1;31m-> So luong ton kho hien tai khong du! Vui long "
                    "nhap lai: \033[0m";
            cin >> SoLuong;
            break;
          }
          cout << "\033[1;32m-> Da dat hang thanh cong\033[0m\n";
          DSDichVu[j].TonKhoSauKhiBan(SoLuong);
          DSSanDaDat[ViTriDonHang].ThemDichVu(IDMuaHang, SoLuong);
        }
      }
      break;
    }
    case 5: {
      string SDT;
      cout << "Vui long nhap sdt: ";
      cin >> SDT;
      bool TimThay = false;
      for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
        if (SDT == DSSanDaDat[i].GetSDTKhach() &&
            DSSanDaDat[i].GetTrangThai() == "Playing") {
          DSSanDaDat[i].SetTrangThai("Trong");
          for (int j = 0; j < CauLong::SoLuongSan; j++) {
            if (DSSan[j].GetID() == DSSanDaDat[i].GetIDSan()) {
              DSSan[j].SetTrangThai("Trong");
              break;
            }
          }
          time_t Now = time(0);
          tm *ltm = localtime(&Now);
          Time GioVe;
          GioVe.Gio = ltm->tm_hour;
          GioVe.Phut = ltm->tm_min;
          TimThay = true;

          cout << "\033[1;32m\n=> CHECK-OUT THANH CONG!\033[0m\n";
          cout << "\033[1;36mTrang thai don: Dang Trong (Relax)\033[0m\n";
          cout << "\033[1;36mGio ra san thuc te: " << right << setfill('0')
               << setw(2) << GioVe.Gio << ":" << setw(2) << GioVe.Phut
               << setfill(' ') << "\033[0m\n";

          DSSanDaDat[i].SetGioThucTeLucVe(GioVe);

          Time GioVaoDat = DSSanDaDat[i].GetGioBatDau();
          Time GioRaDat = DSSanDaDat[i].GetGioKetThuc();

          long long TongPhut = GioRaDat.TongPhut() - GioVaoDat.TongPhut();
          double SoGio = (double)TongPhut / 60.0;

          string Thu = DSSanDaDat[i].GetNgayDat().LayThu();
          long long TienSan = 0;
          if (Thu == "Thu 7" || Thu == "Chu Nhat") {
            TienSan = (long long)(SoGio * GioCuoiTuan);
          } else {
            TienSan = (GioVaoDat.Gio >= 16) ? (long long)(SoGio * GioCaoDiem)
                                            : (long long)(SoGio * GioThuong);
          }

          string Hang = "Normal";
          for (int h = 0; h < KhachHang::SoLuongHoiVien; h++) {
            if (SDT == DSKhachHang[h].GetSDT()) {
              Hang = DSKhachHang[h].HangThanhVien();
              break;
            }
          }
          double GiamGia = (Hang == "VIP") ? 0.2 : ((Hang == "Gold") ? 0.1 : 0);
          long long TongDichVu = 0;

          cout << "\n================================\n";
          cout << "           SAN CAU LONG \n";
          cout << "       HOA DON THANH TOAN\n";
          cout << "================================\n";

          cout << "Ngay: " << right << setfill('0') << setw(2) << ltm->tm_mday
               << "/" << setw(2) << 1 + ltm->tm_mon << "/"
               << 1900 + ltm->tm_year << "   Gio: " << setw(2) << ltm->tm_hour
               << ":" << setw(2) << ltm->tm_min << "\n";
          cout << setfill(' ');

          cout << left << "Khach: " << SDT << " (" << Hang << ")\n";
          cout << "--------------------------------\n";

          cout << "San: " << DSSanDaDat[i].GetIDSan() << "\n";
          cout << "Gio dat: " << right << setfill('0') << setw(2)
               << GioVaoDat.Gio << ":" << setw(2) << GioVaoDat.Phut << " - "
               << setw(2) << GioRaDat.Gio << ":" << setw(2) << GioRaDat.Phut
               << "\n";
          cout << setfill(' ');

          cout << left << "Tien san (" << SoGio << "h):" << right << setw(18)
               << TienSan << "\n\n";

          int SoLuongMon = DSSanDaDat[i].GetDemSoLuongDat();
          if (SoLuongMon > 0) {
            cout << left << "Dich vu:\n";
            for (int k = 0; k < SoLuongMon; k++) {
              string IDMon = DSSanDaDat[i].GetIDDichVuDaDat(k);
              int SLMon = DSSanDaDat[i].GetSoLuongDichVuDaDat(k);
              for (int m = 0; m < DichVu::SoLuongDV; m++) {
                if (DSDichVu[m].GetIDSP() == IDMon) {
                  long long ThanhTien = SLMon * DSDichVu[m].GetDonGia();
                  TongDichVu += ThanhTien;

                  string TenVaSL =
                      "- " + DSDichVu[m].GetTenSP() + " x" + to_string(SLMon);
                  cout << left << setw(22) << TenVaSL << right << setw(10)
                       << ThanhTien << "\n";
                  break;
                }
              }
            }
          }
          cout << "--------------------------------\n";

          long long TongCong = TienSan + TongDichVu;
          long long TienGiam = TongCong * GiamGia;
          long long TongSauGiam = TongCong - TienGiam;

          cout << left << setw(22) << "Tong cong:" << right << setw(10)
               << TongCong << "\n";
          if (TienGiam > 0) {
            string GiamSTR =
                "Giam (" + Hang + " " + to_string((int)(GiamGia * 100)) + "%):";
            cout << left << setw(22) << GiamSTR << right << setw(10)
                 << "-" + to_string(TienGiam) << "\n";
          }
          cout << "================================\n";
          cout << "\033[1;32m" << left << setw(22) << "THANH TOAN:" << right
               << setw(10) << TongSauGiam << "\033[0m\n";
          cout << "================================\n";
          DSSanDaDat[i].SetTongTienBill(TongSauGiam);
          for (int h = 0; h < KhachHang::SoLuongHoiVien; h++) {
            if (SDT == DSKhachHang[h].GetSDT()) {
              DSKhachHang[h].CongDiem(TongSauGiam);
              break;
            }
          }

          break;
        }
      }
      if (!TimThay)
        cout << "\033[1;31m=> Khong tim thay don dat san nao dang "
                "choi!\033[0m\n";
      break;
    }
    case 6: {
      VeDuongNgang("┌", "┐", DoRong);
      cout << "│" << left << setw(DoRong)
           << "        DANH SACH KHACH HANG THANH VIEN" << "│\n";
      VeDuongNgang("├", "┤", DoRong);
      cout << "│ " << left << setw(16) << "    Ho Ten"
           << "│ " << left << setw(12) << "   SDT"
           << "│ " << left << setw(7) << " Diem"
           << "│ " << left << setw(13) << " Hang TV" << "│\n";
      VeDuongNgang("├", "┤", DoRong);

      for (int i = 0; i < KhachHang::SoLuongHoiVien; i++) {
        cout << "│ " << left << setw(16) << DSKhachHang[i].GetHoTen() << "│ "
             << left << setw(12) << DSKhachHang[i].GetSDT() << "│ " << left
             << setw(7) << DSKhachHang[i].GetDienTichLuy() << "│ " << left
             << setw(13) << DSKhachHang[i].HangThanhVien() << "│\n";
      }
      VeDuongNgang("└", "┘", DoRong);

      int QuayLai;
      do {
        cout << "-> Nhan phim 0 de quay lai: ";
        cin >> QuayLai;
      } while (QuayLai != 0);

      break;
    }
    case 0: {
      if (Admin) {
        cout << "\033[1;33m\n=> Da thoat quyen Staff, tro ve Menu "
                "Admin!\033[0m\n";
      } else {
        cout << "\033[1;32m\n=> DANG XUAT THANH CONG! He thong tro ve man hinh "
                "chinh.\033[0m\n";
      }
      return;
    }
    }
  }
}
void MenuAdmin() {
  int Chon;
  while (true) {
    VeDuongNgang("┌", "┐", DoRong);
    cout << "│" << left << setw(DoRong) << "               MENU QUAN LY (ADMIN)"
         << "│\n";
    VeDuongNgang("├", "┤", DoRong);
    cout << "│" << left << setw(DoRong)
         << " [1] Tat ca cac chuc nang cua Nhan vien" << "│\n";
    cout << "│" << left << setw(DoRong)
         << " [2] Thiet lap gia thue san va khung gio" << "│\n";
    cout << "│" << left << setw(DoRong) << " [3] Quan ly danh sach san "
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [4] Quan ly kho hang & Gia"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [5] Quan ly tai khoan Nhan vien"
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [6] Xem bao cao doanh thu "
         << "│\n";
    cout << "│" << left << setw(DoRong) << " [0] Dang xuat khoi he thong"
         << "│\n";
    VeDuongNgang("└", "┘", DoRong);

    cout << " -> Lua chon cua ban: ";
    cin >> Chon;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
      Chon = -1;
    }
    switch (Chon) {
    case 1:
      MenuStaff(true);
      break;
    case 2:
      ThietLapGiaThue();
      break;
    case 3:
      QuanLiDSSan();
      break;
    case 4:
      QuanLiKhoHang();
      break;
    case 5:
      TKStaff();

      break;
    case 6:
      BaoCaoDoanhThu();
      break;
    case 0:
      return;
    default:
      cout << "Nhap sai, vui long nhap lai!\n";
    }
  }
}
void GhiFileDuLieu() {
  ofstream FileGia("cai_dat_gia.txt");
  if (FileGia.is_open()) {
    FileGia << GioThuong << "\n" << GioCaoDiem << "\n" << GioCuoiTuan << "\n";
    FileGia.close();
  }

  ofstream FileKH("khachhang.txt");
  if (FileKH.is_open()) {
    FileKH << KhachHang::SoLuongHoiVien << "\n";
    for (int i = 0; i < KhachHang::SoLuongHoiVien; i++) {
      FileKH << DSKhachHang[i].GetHoTen() << "\n";
      FileKH << DSKhachHang[i].GetSDT() << "\n";
      FileKH << DSKhachHang[i].GetDienTichLuy() << "\n";
    }
    FileKH.close();
  }

  ofstream FileND("nguoidung.txt");
  if (FileND.is_open()) {
    FileND << NguoiDung::SoLuongUser << "\n";
    for (int i = 0; i < NguoiDung::SoLuongUser; i++) {
      FileND << DSNguoiDung[i].GetHoTen() << "\n";
      FileND << DSNguoiDung[i].GetSDT() << "\n";
      FileND << DSNguoiDung[i].GetTK() << "\n";
      FileND << DSNguoiDung[i].GetMK() << "\n";
      FileND << DSNguoiDung[i].GetVaiTro() << "\n";
    }
    FileND.close();
  }

  ofstream FileSan("san.txt");
  if (FileSan.is_open()) {
    FileSan << CauLong::SoLuongSan << "\n";
    for (int i = 0; i < CauLong::SoLuongSan; i++) {
      FileSan << DSSan[i].GetID() << "\n";
      FileSan << DSSan[i].GetTenSan() << "\n";
      FileSan << DSSan[i].GetTrangThai() << "\n";
    }
    FileSan.close();
  }

  ofstream FileDV("dichvu.txt");
  if (FileDV.is_open()) {
    FileDV << DichVu::SoLuongDV << "\n";
    for (int i = 0; i < DichVu::SoLuongDV; i++) {
      FileDV << DSDichVu[i].GetIDSP() << "\n";
      FileDV << DSDichVu[i].GetTenSP() << "\n";
      FileDV << DSDichVu[i].GetDonGia() << "\n";
      FileDV << DSDichVu[i].GetSoLuongTonKho() << "\n";
      FileDV << DSDichVu[i].GetSoLuongDaBan() << "\n";
    }
    FileDV.close();
  }

  ofstream FileDatVatDung("datvatdung.txt");
  if (FileDatVatDung.is_open()) {
    FileDatVatDung << DatVatDung::SoLuongSanDaDat << "\n";
    for (int i = 0; i < DatVatDung::SoLuongSanDaDat; i++) {
      FileDatVatDung << DSSanDaDat[i].GetIDDatHang() << "\n";
      FileDatVatDung << DSSanDaDat[i].GetSDTKhach() << "\n";
      FileDatVatDung << DSSanDaDat[i].GetIDSan() << "\n";
      FileDatVatDung << DSSanDaDat[i].GetTrangThai() << "\n";

      Date Ngay = DSSanDaDat[i].GetNgayDat();
      FileDatVatDung << Ngay.Ngay << " " << Ngay.Thang << " " << Ngay.Nam
                     << "\n";

      Time Vao = DSSanDaDat[i].GetGioBatDau();
      FileDatVatDung << Vao.Gio << " " << Vao.Phut << "\n";

      Time Ra = DSSanDaDat[i].GetGioKetThuc();
      FileDatVatDung << Ra.Gio << " " << Ra.Phut << "\n";

      FileDatVatDung << DSSanDaDat[i].GetTongTienBill() << "\n";

      int SoLuongDVDaDat = DSSanDaDat[i].GetDemSoLuongDat();
      FileDatVatDung << SoLuongDVDaDat << "\n";
      for (int j = 0; j < SoLuongDVDaDat; j++) {
        FileDatVatDung << DSSanDaDat[i].GetIDDichVuDaDat(j) << "\n";
        FileDatVatDung << DSSanDaDat[i].GetSoLuongDichVuDaDat(j) << "\n";
      }
    }
    FileDatVatDung.close();
  }

  cout << "\033[1;32mTAM BIET VA HEN GAP LAI!\033[0m\n";
}

void DocFileDuLieu() {
  ifstream FileGia("cai_dat_gia.txt");
  if (FileGia.is_open()) {
    if (!(FileGia >> GioThuong >> GioCaoDiem >> GioCuoiTuan)) {
      GioThuong = 30000;
      GioCaoDiem = 40000;
      GioCuoiTuan = 30000;
    }
    FileGia.close();
  }

  ifstream FileKH("khachhang.txt");
  if (FileKH.is_open()) {
    int SL = 0;
    if (FileKH >> SL) {
      FileKH.ignore();
      KhachHang::SoLuongHoiVien = 0;
      for (int i = 0; i < SL; i++) {
        string Ten, SDT;
        int Diem;
        getline(FileKH, Ten);
        getline(FileKH, SDT);
        FileKH >> Diem;
        FileKH.ignore();
        DSKhachHang[i] = KhachHang(Ten, SDT, Diem);
      }
    }
    FileKH.close();
  }

  ifstream FileND("nguoidung.txt");
  if (FileND.is_open()) {
    int SL = 0;
    if (FileND >> SL) {
      FileND.ignore();
      NguoiDung::SoLuongUser = 0;
      for (int i = 0; i < SL; i++) {
        string Ten, SDT, TK, MK, VaiTro;
        getline(FileND, Ten);
        getline(FileND, SDT);
        getline(FileND, TK);
        getline(FileND, MK);
        getline(FileND, VaiTro);
        DSNguoiDung[i] = NguoiDung(Ten, SDT, TK, MK, VaiTro);
      }
    }
    FileND.close();
  }

  ifstream FileSan("san.txt");
  if (FileSan.is_open()) {
    int SL = 0;
    if (FileSan >> SL) {
      FileSan.ignore();
      CauLong::SoLuongSan = 0;
      for (int i = 0; i < SL; i++) {
        string ID, Ten, TrangThai;
        getline(FileSan, ID);
        getline(FileSan, Ten);
        getline(FileSan, TrangThai);
        DSSan[i] = CauLong(ID, Ten, TrangThai);
      }
    }
    FileSan.close();
  }

  ifstream FileDV("dichvu.txt");
  if (FileDV.is_open()) {
    int SL = 0;
    if (FileDV >> SL) {
      FileDV.ignore();
      DichVu::SoLuongDV = 0;
      for (int i = 0; i < SL; i++) {
        string ID, Ten;
        long long Gia;
        int TonKho, DaBan;
        getline(FileDV, ID);
        getline(FileDV, Ten);
        FileDV >> Gia >> TonKho >> DaBan;
        FileDV.ignore();
        DSDichVu[i] = DichVu(ID, Ten, Gia, TonKho);
        DSDichVu[i].SetSoLuongDaBan(DaBan);
      }
    }
    FileDV.close();
  }

  ifstream FileDatVatDung("datvatdung.txt");
  if (FileDatVatDung.is_open()) {
    int SL = 0;
    if (FileDatVatDung >> SL) {
      FileDatVatDung.ignore();
      DatVatDung::SoLuongSanDaDat = 0;
      for (int i = 0; i < SL; i++) {
        string IDDat, SDT, IDSan, TrangThai;
        getline(FileDatVatDung, IDDat);
        getline(FileDatVatDung, SDT);
        getline(FileDatVatDung, IDSan);
        getline(FileDatVatDung, TrangThai);

        Date Ngay;
        FileDatVatDung >> Ngay.Ngay >> Ngay.Thang >> Ngay.Nam;

        Time Vao, Ra;
        FileDatVatDung >> Vao.Gio >> Vao.Phut;
        FileDatVatDung >> Ra.Gio >> Ra.Phut;

        long long TongTien;
        FileDatVatDung >> TongTien;
        FileDatVatDung.ignore();

        DSSanDaDat[i] = DatVatDung(IDDat, SDT, IDSan, TrangThai, Ngay, Vao, Ra);
        DSSanDaDat[i].SetTongTienBill(TongTien);

        int SLMon = 0;
        FileDatVatDung >> SLMon;
        FileDatVatDung.ignore();
        for (int j = 0; j < SLMon; j++) {
          string IDDichVu;
          int SLMua;
          getline(FileDatVatDung, IDDichVu);
          FileDatVatDung >> SLMua;
          FileDatVatDung.ignore();
          DSSanDaDat[i].ThemDichVu(IDDichVu, SLMua);
        }
      }
    }
    FileDatVatDung.close();
  }
}
int main() {

  KhoiTaoGiaTri();
  DocFileDuLieu();
  int Chon;
  while (true) {
    cout << "\n--- HE THONG QUAN LY SAN CAU LONG ---\n";
    cout << "[1] Dang nhap\n";
    cout << "[0] Thoat\n";
    cout << "Nhap lua chon cua ban (0-1) : ";
    cin >> Chon;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
      Chon = -1;
    }
    if (Chon == 0) {
      GhiFileDuLieu();
      break;
    }
    switch (Chon) {
    case 1: {
      string Role = XuLiDangNhap();
      if (Role == "admin")
        MenuAdmin();
      else if (Role == "staff")
        MenuStaff();
      else if (Role == "")
        cout << "Dang nhap that bai!";
    }

    break;
    default:
      cout << "Vui long nhap lai!\n";
    }
  }

  delete[] DSSan;
  delete[] DSDichVu;
  delete[] DSNguoiDung;
  delete[] DSKhachHang;
  delete[] DSSanDaDat;
  return 0;
}
