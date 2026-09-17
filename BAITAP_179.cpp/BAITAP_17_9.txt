#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Thu vien de dung ham sap xep sort

using namespace std;

// === CAU 1: KHAI BAO LOP NGUOI ===
class Nguoi {
protected:
    string hoTen;
    int namSinh;

public:
    // Cau 2: Ham tao khong doi cua lop Nguoi
    Nguoi() {
        hoTen = "";
        namSinh = 0;
    }

    // Cau 2: Ham tao co doi cua lop Nguoi
    Nguoi(string ten, int ns) {
        hoTen = ten;
        namSinh = ns;
    }

    // Phuong thuc nhap cho lop Nguoi
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore(); // Xoa bo nho dem
    }

    // Phuong thuc xuat cho lop Nguoi
    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh;
    }
};

// === CAU 1: KHAI BAO LOP SINH VIEN KE THUA TU LOP NGUOI ===
class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:
    // Cau 2: Ham tao khong doi cua lop SinhVien
    SinhVien() : Nguoi() {
        maSV = "";
        diemTB = 0.0;
    }

    // Cau 2: Ham tao co doi cua lop SinhVien (Goi lai ham tao co doi cua lop cha Nguoi)
    SinhVien(string ten, int ns, string ma, float dtb) : Nguoi(ten, ns) {
        maSV = ma;
        diemTB = dtb;
    }

    // Phuong thuc nhap cua lop SinhVien
    void nhap() {
        Nguoi::nhap(); // Goi lai ham nhap cua lop cha
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
        cin.ignore(); // Xoa bo nho dem
    }

    // Phuong thuc xuat cua lop SinhVien
    void xuat() {
        Nguoi::xuat(); // Goi lai ham xuat cua lop cha
        cout << " | Ma SV: " << maSV << " | Diem TB: " << diemTB << endl;
    }

    // Ham bo tro lay diem trung binh de phuc vu sap xep
    float getDiemTB() {
        return diemTB;
    }
};

// Ham so sanh de sap xep giam dan theo diem trung binh (Cau 3)
bool soSanhDiemGiamDan(SinhVien a, SinhVien b) {
    return a.getDiemTB() > b.getDiemTB();
}

// === HAM MAIN CHINH ===
int main() {
    // NOTE STT CUA SV LOP C++: STT 62 - NGUYEN HOANG GIA KHANH

    cout << "=================== CAU 2: CHAY THU HAM TAO CO DOI ===================" << endl;
    // Chay thu ham tao co doi cho lop Nguoi
    Nguoi nguoiMau("Nguyen Van A", 2000);
    cout << "Doi tuong Nguoi (khoi tao co doi): ";
    nguoiMau.xuat();
    cout << "\n" << endl;

    // Chay thu ham tao co doi cho lop SinhVien
    SinhVien svMau("Le Thi B", 2005, "UTT62001", 8.5);
    cout << "Doi tuong SinhVien (khoi tao co doi): ";
    svMau.xuat();
    cout << "======================================================================\n" << endl;


    cout << "=================== CAU 3: QUAN LY DANH SACH SINH VIEN ===================" << endl;
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;
    cin.ignore();

    vector<SinhVien> ds_sv(n);

    // Nhap danh sach n sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho sinh vien thu " << i + 1 << ":" << endl;
        ds_sv[i].nhap();
    }

    // Sap xep lai danh sach sinh vien theo thu tu giam dan cua diem trung binh
    sort(ds_sv.begin(), ds_sv.end(), soSanhDiemGiamDan);

    // In ra man hinh danh sach sau khi sap xep
    cout << "\n--- DANH SACH SINH VIEN SAU KHI SAP XEP GIAM DAN THEO DIEM TB ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "] ";
        ds_sv[i].xuat();
    }
    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}
