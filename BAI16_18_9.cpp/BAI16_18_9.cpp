#include <iostream>
#include <string>

using namespace std;

// CÂU 1: Khai báo lớp MonHoc và lớp SinhVien kế thừa
class MonHoc {
protected:
    string tenMonHoc;
    float diemCC;
    float diemKT;
    float diemDT;
};

class SinhVien : public MonHoc {
private:
    string hoTen;
    string lop;
    string maSV;

public:
    // CÂU 2: Xây dựng phương thức nhập, xuất và tính điểm học phần
    void nhap() {
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap lop: ";
        cin >> lop;
        cout << "Nhap ten mon hoc: ";
        getline(cin, tenMonHoc);
        cout << "Nhap diem chuyen can (CC): ";
        cin >> diemCC;
        cout << "Nhap diem kiem tra (KT): ";
        cin >> diemKT;
        cout << "Nhap diem thi (DT): ";
        cin >> diemDT;
    }

    void xuat() {
        cout << "Ma SV: " << maSV << " | Ho ten: " << hoTen 
             << " | Lop: " << lop << " | Mon: " << tenMonHoc 
             << " | Diem HP: " << tinhDiemHP() << endl;
    }

    // Phương thức tính điểm học phần (Ví dụ tính trọng số: CC 10%, KT 30%, Thi 60%)
    float tinhDiemHP() {
        return diemCC * 0.1f + diemKT * 0.3f + diemDT * 0.6f;
    }

    // Phương thức kiểm tra điều kiện cấm thi theo yêu cầu Câu 3
    bool laBiCamThi() {
        if (diemCC < 5.0f || diemKT == 0.0f) {
            return true; // Bị cấm thi
        }
        return false;
    }
};

// CÂU 3: Nhập n sinh viên và in ra danh sách sinh viên bị cấm thi
int main() {
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;

    SinhVien ds[100]; // Mảng đối tượng sinh viên tối đa 100

    // Nhập danh sách sinh viên
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }

    // In danh sách sinh viên bị cấm thi
    cout << "\n=== DANH SACH SINH VIEN BI CAM THI ===" << endl;
    bool coNguoiCamThi = false;

    for (int i = 0; i < n; i++) {
        if (ds[i].laBiCamThi()) {
            ds[i].xuat();
            coNguoiCamThi = true;
        }
    }

    if (!coNguoiCamThi) {
        cout << "Khong co sinh vien nào bi cam thi." << endl;
    }

    return 0;
}

```