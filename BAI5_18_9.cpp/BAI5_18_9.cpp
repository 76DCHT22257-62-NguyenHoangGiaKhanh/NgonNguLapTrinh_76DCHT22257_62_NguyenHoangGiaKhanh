#include <iostream>
#include <string>

using namespace std;

// CÂU 1: Khai báo lớp Nguoi và lớp SinhVien kế thừa
class Nguoi {
protected:
    string hoTen;
    int namSinh;
};

class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:
    // CÂU 2: Xây dựng phương thức nhập, xuất
    void nhap() {
        cout << "Nhap ho ten: ";
        cin >> hoTen;
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh 
             << " | Ma SV: " << maSV << " | Diem TB: " << diemTB << endl;
    }

    // Các hàm trả về dữ liệu để dùng cho Câu 3
    string getMaSV() {
        return maSV;
    }

    string getHoTen() {
        return hoTen;
    }
};

// CÂU 3: Nhập n sinh viên và tìm kiếm theo mã hoặc họ tên
int main() {
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;

    SinhVien ds[100]; // Mảng đối tượng sinh viên

    // Nhập danh sách
    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }

    // Nhập thông tin tìm kiếm
    string tuKhoa;
    cout << "\nNhap ma sinh vien hoac ho ten can tim: ";
    cin >> tuKhoa;

    // Tìm kiếm và in kết quả
    bool timThay = false;
    cout << "\n--- KET QUA TIM KIEM ---" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].getMaSV() == tuKhoa || ds[i].getHoTen() == tuKhoa) {
            ds[i].xuat();
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sinh vien nao!" << endl;
    }

    return 0;
}

```