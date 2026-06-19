<div align="center">
  <h1 align="center">🏸 HỆ THỐNG QUẢN LÝ SÂN CẦU LÔNG (BADMINTON COURT POS)</h1>
  <p align="center">
    <strong>Đồ án PBL01: Dự án lập trình (Project Based Learning 1)</strong>
    <br />
    <i>Chuyên ngành: Kỹ thuật Máy tính - Trường Đại học Bách Khoa (DUT)</i>
  </p>
</div>

## 📑 1. Tổng quan dự án (Project Overview)

Trong bối cảnh chuyển đổi số đang diễn ra mạnh mẽ, việc vận hành các cơ sở thể thao bằng sổ sách thủ công bộc lộ nhiều điểm yếu như: dễ sai sót trong tính toán, khó kiểm soát lịch đặt sân dẫn đến trùng giờ, và thất thoát doanh thu/hàng hóa. 

Nhằm giải quyết triệt để bài toán này, **Hệ thống Quản lý Sân Cầu Lông (Badminton Court POS)** ra đời. Đây là một ứng dụng Console được xây dựng hoàn toàn bằng ngôn ngữ **C++**, ứng dụng chặt chẽ các nguyên lý của **Lập trình Hướng đối tượng (OOP)**. Hệ thống không chỉ cung cấp giao diện tương tác trực quan cho nhân viên (Staff) mà còn tích hợp bộ công cụ phân tích doanh thu chuyên sâu cho quản lý (Admin), đảm bảo quy trình vận hành khép kín từ lúc khách hàng đặt lịch cho đến khi xuất hóa đơn thanh toán.

## 🚀 2. Phân tích Tính năng Nổi bật (Core Features)

Hệ thống được module hóa thành các phân hệ chức năng riêng biệt, bao gồm:

### 🛡️ Phân hệ Quản trị (Dành cho Admin)
- **Quản lý Nhân sự:** Tạo lập, cấp phát và thu hồi tài khoản nhân viên (Staff). Tự động sinh ID tài khoản theo định dạng chuẩn để dễ dàng kiểm soát.
- **Thiết lập Ma trận Giá linh hoạt:** Cho phép Admin cấu hình lại bảng giá theo thời gian thực (Real-time pricing). Hệ thống tự động phân loại giá theo 3 mức: Giờ thường, Giờ cao điểm (sau 16h00) và Giá cuối tuần.
- **Báo cáo Thống kê & Phân tích Dữ liệu:** - Khai thác dữ liệu lịch sử để kết xuất báo cáo doanh thu tổng quan.
  - Tích hợp bộ lọc truy vấn doanh thu theo từng **Tháng/Năm** cụ thể.
  - Phân tích và trích xuất danh sách "Top Dịch Vụ Bán Chạy" nhằm hỗ trợ chủ sân đưa ra quyết định nhập kho hàng hóa.

### 💼 Phân hệ Vận hành (Dành cho Staff)
- **Thuật toán Đặt sân (Booking System) thông minh:** - Chặn đứng các thao tác lỗi: Không cho phép đặt lịch vào các ngày/giờ trong quá khứ so với đồng hồ hệ thống.
  - Chặn xung đột (Conflict Resolution): Kiểm tra và từ chối các yêu cầu đặt sân có khung giờ giao cắt với các đơn đã tồn tại.
- **Quản lý Trạng thái Real-time:** Cập nhật liên tục trạng thái của sân (Trống -> Đã đặt -> Đang chơi). Ghi nhận chính xác tới từng phút thời điểm Check-in và Check-out.
- **Hệ thống Quản lý Khách hàng (CRM) & Tích điểm:** - Tự động nhận diện khách hàng cũ qua Số điện thoại.
  - Tích lũy điểm sau mỗi lần thanh toán và phân hạng tự động (Normal, Silver, Gold, VIP) để tính toán chiết khấu giảm giá.
- **Point of Sale (POS) - Xử lý hóa đơn:** Gọi thêm dịch vụ (Nước uống, thuê vợt, mua cầu) trực tiếp khi khách đang ở trên sân. Tự động trừ số lượng hàng tồn kho và gộp thẳng vào hóa đơn tính tiền cuối cùng.

## 🧠 3. Nền tảng Kỹ thuật & Cấu trúc Dữ liệu

Dự án là minh chứng cho việc vận dụng kiến thức lý thuyết vào giải quyết bài toán thực tế:
1. **Object-Oriented Programming (OOP):** Xây dựng hệ thống Class phức tạp (`KhachHang`, `NguoiDung`, `CauLong`, `DichVu`, `DatVatDung`). Vận dụng tính Đóng gói (Encapsulation) để bảo vệ dữ liệu nhạy cảm và tính Kế thừa (Inheritance) để tối ưu hóa mã nguồn.
2. **Nạp chồng toán tử (Operator Overloading):** Tự định nghĩa lại các toán tử `>`, `<`, `==` cho Struct `Time` và `Date` để đơn giản hóa các phép toán so sánh thời gian.
3. **Quản lý Bộ nhớ (Memory Management):** Sử dụng các mảng động và con trỏ (Pointers) để cấp phát không gian lưu trữ cho danh sách khách hàng, danh sách sân và hóa đơn một cách linh hoạt.
4. **Time & System Libraries:** Tích hợp sâu thư viện `<ctime>` để trích xuất và đồng bộ dữ liệu thời gian trực tiếp từ hệ điều hành, phục vụ cho logic tính tiền và kiểm tra lịch.

## 🛠️ 4. Hướng dẫn Cài đặt & Sử dụng (Installation & Usage)

Để chạy thử hệ thống trên máy cá nhân, vui lòng đảm bảo máy tính đã cài đặt trình biên dịch C++ (ví dụ: GCC/MinGW) và thực hiện các bước sau:

**Bước 1: Tải mã nguồn về máy**
Mở Terminal/Command Prompt và chạy lệnh:
```bash
git clone https://github.com/huy02012007/DDTuan-PBL01-NHP39A-Nhom03.git
cd DDTuan-PBL01-NHP39A-Nhom03
```

**Bước 2: Biên dịch chương trình (Compile)**
Chạy lệnh g++ để biên dịch file `main.cpp`:
```bash
g++ main.cpp -o quanlysan
```

**Bước 3: Khởi chạy (Run)**
- Trên môi trường Windows:
```bash
quanlysan.exe
```
- Trên môi trường Linux/MacOS:
```bash
./quanlysan
```

### 🔑 Thông tin Đăng nhập Mặc định (Default Credentials)
Hệ thống đã được khởi tạo sẵn một số dữ liệu mẫu và tài khoản quản trị cao nhất để thuận tiện cho việc kiểm thử (Testing):
- **Vai trò:** `Admin` (Chọn 1 khi khởi động)
- **Tài khoản:** `1`
- **Mật khẩu:** `1`

*(Từ tài khoản Admin này, giảng viên có thể tự do cấp phát thêm tài khoản cho Staff để test các phân hệ chức năng khác).*

## 👥 5. Thành viên Nhóm Phát triển (Nhóm 03)

| STT | Họ và Tên | Mã Sinh Viên (MSV) | Vai trò & Nhiệm vụ trong dự án |
| :---: | :--- | :---: | :--- |
| 1 | **Nguyễn Hữu Huy** | `106250074` | **Trưởng nhóm.** Thiết kế kiến trúc OOP cốt lõi; Xử lý thuật toán Đặt sân, Check-in/Check-out thời gian thực; Cấu hình module Tính tiền và Báo cáo doanh thu. |
| 2 | **Nguyễn Hữu Mạnh** | `106250192` | **Thành viên.** Xử lý logic phân quyền Admin/Staff; Quản lý kho hàng dịch vụ; Xây dựng hệ thống Khách hàng (tích điểm/phân hạng) & Thực hiện kiểm thử (Testing). |

---
*Dự án được thực hiện dưới sự hướng dẫn của **Thầy D.Tuấn** (Mã HP: NH.39A).*
