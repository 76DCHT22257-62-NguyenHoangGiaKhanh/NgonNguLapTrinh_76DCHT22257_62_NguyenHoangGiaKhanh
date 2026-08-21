#include <iostream>
#include <string>

using namespace std;

// Khai bao lop NhanVien theo dung Slide giang day
class NhanVien {
public:
    // Cac thuoc tinh kieu chuoi (string) de public de truy xuat truc tiep
    string hoten;
    string manv;
    string ngaysinh;
    string diachi;
};

int main() {
    // Khai bao 1 doi tuong la Minh thuoc lop NhanVien
    NhanVien Minh;
    
    // Nhap thong tin cho Minh (Truy xuat thanh phan qua dau cham '.')
    cout << "Nhap ho ten: ";
    getline(cin, Minh.hoten);
    
    cout << "Nhap ma nhan vien: ";
    getline(cin, Minh.manv);
    
    cout << "Nhap ngay sinh: ";
    getline(cin, Minh.ngaysinh);
    
    cout << "Nhap dia chi: ";
    getline(cin, Minh.diachi);
    
    // Xuat thong tin cua Minh (Truy xuat thanh phan qua dau cham '.')
    cout << "\n--- THONG TIN NHAN VIEN MINH ---" << endl;
    cout << "Ho ten: " << Minh.hoten << endl;
    cout << "Ma NV: " << Minh.manv << endl;
    cout << "Ngay sinh: " << Minh.ngaysinh << endl;
    cout << "Dia chi: " << Minh.diachi << endl;
    
    return 0;
}
