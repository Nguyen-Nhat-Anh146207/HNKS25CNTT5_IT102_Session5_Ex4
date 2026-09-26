# MedCare Clinic - Module Quản lý Hàng đợi Khám bệnh

## 1. Giới thiệu

Chương trình mô phỏng hệ thống Kiosk đăng ký khám bệnh tự động cho phòng khám MedCare.

Chương trình được xây dựng bằng ngôn ngữ C11 và sử dụng các kiến thức:

* Mảng một chiều.
* Mảng ký tự `char[]`.
* Mảng song song (Parallel Arrays).
* Vòng lặp `for`, `do...while`.
* Cấu trúc `if/else`, `switch/case`.
* Nhập chuỗi bằng `fgets()`.
* So sánh chuỗi bằng `strcmp()`.
* Thêm, sửa, xóa phần tử trong mảng.
* Dồn dịch mảng khi xóa.
* Biến đếm số lượng phần tử.

## 2. Cấu trúc thư mục

```text
clinic_appointment_module/
└── main.c
```

## 3. Thiết kế Parallel Arrays

Chương trình sử dụng các mảng song song:

| Mảng            | Kiểu dữ liệu | Ý nghĩa            |
| --------------- | ------------ | ------------------ |
| `so_thu_tu`     | `int`        | Mã số thứ tự khám  |
| `ten_benh_nhan` | `char[][30]` | Họ tên bệnh nhân   |
| `tuoi`          | `int`        | Tuổi bệnh nhân     |
| `uu_tien`       | `int`        | Trạng thái ưu tiên |
| `bhyt`          | `int`        | Trạng thái BHYT    |
| `phi_kham`      | `int`        | Chi phí khám       |

Các mảng sử dụng cùng một `index` để biểu diễn thông tin của cùng một bệnh nhân.

Ví dụ:

```text
index = 0

so_thu_tu[0]
ten_benh_nhan[0]
tuoi[0]
uu_tien[0]
bhyt[0]
phi_kham[0]
```

đều thuộc về bệnh nhân đầu tiên.

## 4. Quy tắc nghiệp vụ

### Giới hạn hàng đợi

Số lượng bệnh nhân tối đa:

```text
MAX = 100
```

### Giới hạn bác sĩ / khung giờ

Mỗi bác sĩ trong một khung giờ tiếp nhận tối đa:

```text
5 bệnh nhân
```

### Phân loại ưu tiên

Bệnh nhân trên 70 tuổi được đánh dấu:

```text
UU TIEN
```

Các trường hợp còn lại:

```text
THUONG
```

### Chính sách BHYT

Giá khám tiêu chuẩn:

```text
200.000 VNĐ
```

Có BHYT:

```text
40.000 VNĐ
```

Không có BHYT:

```text
200.000 VNĐ
```

## 5. Các chức năng

### 1. Tiếp nhận bệnh nhân

* Kiểm tra giới hạn hàng đợi.
* Kiểm tra giới hạn 5 bệnh nhân/khung giờ.
* Nhập họ tên.
* Nhập tuổi.
* Nhập BHYT.
* Tự động xác định diện ưu tiên.
* Tự động tính phí khám.
* Cấp số thứ tự.

### 2. Hiển thị danh sách

Hiển thị toàn bộ bệnh nhân đang có trong hàng đợi cùng:

* Số thứ tự.
* Họ tên.
* Tuổi.
* Diện ưu tiên.
* BHYT.
* Chi phí khám.

### 3. Cập nhật

Tìm bệnh nhân theo số thứ tự và cho phép thay đổi:

* Tên.
* Tuổi.
* BHYT.

Sau khi sửa, chương trình tính lại:

* Trạng thái ưu tiên.
* Chi phí khám.

### 4. Hủy số thứ tự

Khi xóa một bệnh nhân, chương trình sử dụng kỹ thuật dồn dịch mảng:

```c
for (int i = index; i < so_luong - 1; i++) {
    so_thu_tu[i] = so_thu_tu[i + 1];
    strcpy(ten_benh_nhan[i], ten_benh_nhan[i + 1]);
    tuoi[i] = tuoi[i + 1];
    uu_tien[i] = uu_tien[i + 1];
    bhyt[i] = bhyt[i + 1];
    phi_kham[i] = phi_kham[i + 1];
}
```

Sau đó giảm:

```c
so_luong--;
```

Cách này giúp dữ liệu trong hàng đợi được duy trì liên tục và không làm đứt thứ tự.

### 5. Tìm kiếm

Có hai cách tìm kiếm:

* Theo số thứ tự.
* Theo tên bệnh nhân.

Tìm kiếm tên sử dụng:

```c
strcmp()
```

## 6. Xử lý bộ đệm nhập liệu

Chương trình sử dụng `fgets()` để nhập chuỗi.

Sau khi sử dụng `scanf()`, chương trình gọi hàm:

```c
xoa_bo_dem();
```

để xử lý ký tự `\n` còn lại trong bộ đệm.

Khi nhập chuỗi bằng `fgets()`, chương trình sử dụng:

```c
xoa_xuong_dong();
```

để loại bỏ ký tự xuống dòng `\n`.

## 7. Luồng dữ liệu

```text
Đăng ký mới
    ↓
Kiểm tra giới hạn
    ↓
Nhập thông tin
    ↓
Phân loại ưu tiên
    ↓
Tính phí BHYT
    ↓
Lưu vào Parallel Arrays
    ↓
Hiển thị / Sửa / Xóa / Tìm kiếm
```

## 8. Kết luận

Chương trình sử dụng Parallel Arrays để quản lý thông tin bệnh nhân.

Kỹ thuật dồn dịch mảng được sử dụng khi xóa bệnh nhân nhằm duy trì dữ liệu liên tục và bảo toàn thứ tự của hàng đợi.

Chương trình phù hợp với phạm vi kiến thức C cơ bản và có thể biên dịch bằng GCC theo chuẩn C11.
