#include <iostream>
#include <cmath>

using namespace std;

// Cau 1: Khai bao lop PhanSo
class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Ham tao khong doi
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

    // Ham huy
    ~PhanSo() {}

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
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Cau 2: Nap chong toan tu nhap >> va xuat <<
    friend istream& operator>>(istream& in, PhanSo& ps) {
        cout << "Nhap tu so: ";
        in >> ps.tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            in >> ps.mauSo;
            if (ps.mauSo == 0) {
                cout << "Mau so khong hop le! Vui long nhap lai.\n";
            }
        } while (ps.mauSo == 0);
        return in;
    }

    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        if (ps.mauSo == 1) {
            out << ps.tuSo;
        } else {
            out << ps.tuSo << "/" << ps.mauSo;
        }
        return out;
    }

    // Cau 3: Dinh nghia cac toan tu +, -, *, /
    PhanSo operator+(const PhanSo& ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.mauSo + ps2.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo operator-(const PhanSo& ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.mauSo - ps2.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo operator*(const PhanSo& ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.tuSo;
        kq.mauSo = this->mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo operator/(const PhanSo& ps2) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps2.mauSo;
        kq.mauSo = this->mauSo * ps2.tuSo;
        kq.rutGon();
        return kq;
    }
};

int main() {
    // NOTE STT CUA SV: STT 62 - NGUYEN HOANG GIA KHANH
    cout << "===== BAI 2: NAP CHONG TOAN TU (OPERATOR OVERLOADING) =====" << endl;
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1; // Dung nap chong >>
    cout << "Nhap phan so thu hai:\n";
    cin >> ps2; // Dung nap chong >>

    ps1.rutGon();
    ps2.rutGon();
    cout << "\nPhan so 1 toi gian: " << ps1 << endl; // Dung nap chong <<
    cout << "Phan so 2 toi gian: " << ps2 << endl;

    // Thuc hien phep toan va in ket qua toi gian bang toan tu
    cout << "\n--- KET QUA CAC PHEP TOAN NAP CHONG ---" << endl;
    cout << ps1 << " + " << ps2 << " = " << (ps1 + ps2) << endl;
    cout << ps1 << " - " << ps2 << " = " << (ps1 - ps2) << endl;
    cout << ps1 << " * " << ps2 << " = " << (ps1 * ps2) << endl;
    cout << ps1 << " / " << ps2 << " = " << (ps1 / ps2) << endl;

    return 0;
}
