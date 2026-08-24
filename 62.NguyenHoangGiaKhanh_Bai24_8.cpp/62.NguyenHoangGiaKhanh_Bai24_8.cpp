#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Thu vien de can le xuat theo cot

using namespace std;

// Khai bao lop NhanVien theo dung yeu cau
class NhanVien {
private:
    string manv;
    string hoten;
    string ngaysinh;
    string diachi;

public:
    // 1. Constructor khong doi (Mac dinh)
    NhanVien() {
        manv = "";
        hoten = "";
        ngaysinh = "";
        diachi = "";
    }

    // 2. Constructor co doi day du de dua nhan vien vao mang
    NhanVien(string ma, string ten, string ns, string dc) {
        manv = ma;
        hoten = ten;
        ngaysinh = ns;
        diachi = dc;
    }

    // Phuong thuc xuat du lieu theo tung o de tao thanh cot
    void xuatTheoCot() {
        // Can trai (left) va dat do rong (setw) cho tung cot
        cout << left << setw(15) << manv 
             << setw(25) << hoten 
             << setw(15) << ngaysinh 
             << setw(30) << diachi << endl;
    }
};

int main() {
    // NOTE STT CUA SV: STT 62 - NGUYEN HOANG GIA KHANH
    
    int n;
    cout << "Nhap so luong nhan vien n: ";
    cin >> n;
    cin.ignore(); // Xoa bo nho dem de khong bi troi lenh getline
    
    // LAY BAI TAP HOM 22/8 THEO CACH 3: DUNG STD::VECTOR
    vector<NhanVien> ds_nv;
    
    cout << "\n=== NHAP THONG TIN " << n << " NHAN VIEN ===" << endl;
    for (int i = 0; i < n; i++) {
        string ma, ten, ns, dc;
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        cout << "Nhap ma nhan vien: ";
        getline(cin, ma);
        cout << "Nhap ho ten: ";
        getline(cin, ten);
        cout << "Nhap ngay sinh: ";
        getline(cin, ns);
        cout << "Nhap dia chi: ";
        getline(cin, dc);
        
        // SU DUNG CONSTRUCTOR CO DOI DE KHOI TAO VA DUA VAO MANG (VECTOR)
        NhanVien nv_tam(ma, ten, ns, dc);
        ds_nv.push_back(nv_tam);
    }
    
    // XUAT DU LIEU NHAN VIEN THEO COT GON GANG
    cout << "\n=================================== DANH SACH NHAN VIEN ===================================\n" << endl;
    // In tieu de cac cot
    cout << left << setw(15) << "Ma NV" 
         << setw(25) << "Ho va Ten" 
         << setw(15) << "Ngay Sinh" 
         << setw(30) << "Dia Chi" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    
    // Vong lap in tung dong du lieu
    for (int i = 0; i < n; i++) {
        ds_nv[i].xuatTheoCot();
    }
    cout << "-------------------------------------------------------------------------------------------" << endl;
    
    return 0;
}
