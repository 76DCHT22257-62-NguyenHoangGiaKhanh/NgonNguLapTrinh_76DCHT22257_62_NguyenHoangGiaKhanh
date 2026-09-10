#include <iostream>
#include <cmath>

using namespace std;

// Cau 1: Khai bao lop PhanSo
class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Ham tao khong doi (Mac dinh)
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    // Ham tao co doi
    PhanSo(int tu, int mau) {
        tuSo = tu;
        if (mau != 0) {
            mauSo = mau;
        } else {
            mauSo = 1;
        }
    }

    // Ham huy mot doi tuong phan so
    ~PhanSo() {
        // Ham huy mac dinh
    }

    // Tim uoc chung lon nhat de rut gon
    int USCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return (a == 0) ? 1 : a;
    }

    // Cau 2: Phuong thuc rut gon phan so
    void rutGon() {
        int uoc = USCLN(tuSo, mauSo);
        tuSo /= uoc;
        mauSo /= uoc;
        if (mauSo < 0) { // Dua dau tru len tu so
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Phuong thuc nhap
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
            if (mauSo == 0) {
                cout << "Mau so khong hop le! Vui long nhap lai.\n";
            }
        } while (mauSo == 0);
    }

    // Phuong thuc xuat
    void xuat() {
        if (mauSo == 1) {
            cout << tuSo;
        } else {
            cout << tuSo << "/" << mauSo;
        }
    }

    // Phuong thuc cong hai phan so
    PhanSo cong(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.mauSo + ps2.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    // Phuong thuc tru hai phan so
    PhanSo tru(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.mauSo - ps2.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    // Phuong thuc nhan hai phan so
    PhanSo nhan(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.tuSo;
        kq.mauSo = this->mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    // Phuong thuc chia hai phan so
    PhanSo chia(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.mauSo;
        kq.mauSo = this->mauSo * ps2.tuSo;
        kq.rutGon();
        return kq;
    }
};

int main() {
    // NOTE STT CUA SV: STT 62 - NGUYEN HOANG GIA KHANH
    cout << "===== BAI 1: PHUONG THUC THONG THUONG =====" << endl;
    PhanSo ps1, ps2, kq;

    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();
    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();

    cout << "\nPhan so 1 toi gian: "; ps1.rutGon(); ps1.xuat(); cout << endl;
    cout << "Phan so 2 toi gian: "; ps2.rutGon(); ps2.xuat(); cout << endl;

    // Cau 3: Thuc hien cac phep toan va in ket qua toi gian
    cout << "\n--- KET QUA CAC PHEP TOAN ---" << endl;
    
    kq = ps1.cong(ps2);
    ps1.xuat(); cout << " + "; ps2.xuat(); cout << " = "; kq.xuat(); cout << endl;

    kq = ps1.tru(ps2);
    ps1.xuat(); cout << " - "; ps2.xuat(); cout << " = "; kq.xuat(); cout << endl;

    kq = ps1.nhan(ps2);
    ps1.xuat(); cout << " * "; ps2.xuat(); cout << " = "; kq.xuat(); cout << endl;

    kq = ps1.chia(ps2);
    ps1.xuat(); cout << " / "; ps2.xuat(); cout << " = "; kq.xuat(); cout << endl;

    return 0;
}
