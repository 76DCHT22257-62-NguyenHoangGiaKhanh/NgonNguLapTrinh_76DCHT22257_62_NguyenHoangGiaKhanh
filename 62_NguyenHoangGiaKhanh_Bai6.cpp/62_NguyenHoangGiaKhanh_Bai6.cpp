#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Cau 1: Khai bao lop SinhVien
class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5]; // Diem 5 mon hoc

public:
    // Cau 2: Xay dung cac phuong thuc nhap, xuat, tinh diem trung binh
    void nhap() {
        cout << "Nhap ho ten sinh vien: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem cua 5 mon hoc: " << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  Mon " << i + 1 << ": ";
            cin >> diem[i];
        }
        cin.ignore(); // Xoa bo nho dem sau khi dung cin >>
    }

    float tinhDiemTB() {
        float tong = 0;
        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }
        return tong / 5;
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDiemTB() << endl;
    }

    // Phuong thuc phuc vu cho Cau 3: Kiem tra mon thi lai
    void checkThiLai() {
        bool coThiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                if (!coThiLai) {
                    cout << "Sinh vien: " << hoTen << " phai thi lai cac mon: " << endl;
                    coThiLai = true;
                }
                cout << "  - Mon " << i + 1 << " (Diem: " << diem[i] << ")" << endl;
            }
        }
    }
};

int main() {
    // NOTE STT CUA SV: STT 62 - NGUYEN HOANG GIA KHANH
    
    // Cau 3: Nhap vao n sinh vien
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;
    cin.ignore();

    vector<SinhVien> ds_sv(n);
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---" << endl;
        ds_sv[i].nhap();
    }

    cout << "\n================ DANH SACH SINH VIEN ================" << endl;
    for (int i = 0; i < n; i++) {
        ds_sv[i].xuat();
    }

    cout << "\n================ THONG TIN THI LAI ================" << endl;
    for (int i = 0; i < n; i++) {
        ds_sv[i].checkThiLai();
    }

    return 0;
}
