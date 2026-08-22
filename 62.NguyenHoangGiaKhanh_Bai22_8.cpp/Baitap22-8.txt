#include iostream
#include string

using namespace std;

// Khai bao lop NhanVien 
class NhanVien {
private
    string manv;
    string hoten;
    string ngaysinh;
    string diachi;

public
// Phuong thuc nhap thong tin cho 1 nhan vien
    void nhap() {
        cout  Nhap ma nhan vien ;
        getline(cin, manv);
        cout  Nhap ho ten ;
        getline(cin, hoten);
        cout  Nhap ngay sinh ;
        getline(cin, ngaysinh);
        cout  Nhap dia chi ;
        getline(cin, diachi);
    }

// Phuong thuc xuat thong tin
    void xuat() {
        cout  Ma NV   manv    Ho ten   hoten 
                Ngay sinh   ngaysinh    Dia chi   diachi  endl;
    }
};

int main() {
    
// Khai bao mang tinh gom 10 phan tu doi tuong nhan vien
    NhanVien ds_nv[10];
    
// Vong lap nhap thong tin cho 10 nhan vien
    cout  === NHAP THONG TIN 10 NHAN VIEN ===  endl;
    for (int i = 0; i  10; i++) {
        cout  nNhap thong tin nhan vien thu   i + 1    endl;
        ds_nv[i].nhap();
    }
    
// Vong lap xuat thong tin de kiem tra
    cout  n=== DANH SACH THONG TIN 10 NHAN VIEN ===  endl;
    for (int i = 0; i  10; i++) {
        cout  Nhan vien thu   i + 1   - ;
        ds_nv[i].xuat();
    }
    
    return 0;
}
