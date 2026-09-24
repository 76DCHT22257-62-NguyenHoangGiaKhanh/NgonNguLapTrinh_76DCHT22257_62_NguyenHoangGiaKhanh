#include <iostream>
#include <cmath>
using namespace std;

// =======================================================
// CÂU 1
// =======================================================
class PS1 {
protected:
    int tu, mau;

public:
    PS1() {
        tu = 0;
        mau = 1;
    }

    void nhap() {
        cout << "  - Nhap tu so: ";
        cin >> tu;
        do {
            cout << "  - Nhap mau so (khac 0): ";
            cin >> mau;
        } while (mau == 0);
    }

    int USCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void toiGian() {
        int uoc = USCLN(tu, mau);
        tu = tu / uoc;
        mau = mau / uoc;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void in() {
        toiGian();
        if (mau == 1) {
            cout << tu;
        } else {
            cout << tu << "/" << mau;
        }
    }
};

// =======================================================
// CÂU 2
// =======================================================
class PS2 : public PS1 {
public:
    PS2& operator=(const PS2& psKhac) {
        if (this != &psKhac) {
            this->tu = psKhac.tu;
            this->mau = psKhac.mau;
        }
        return *this;
    }

    bool operator>(PS2 psKhac) {
        return (this->tu * psKhac.mau) > (psKhac.tu * this->mau);
    }
};

// =======================================================
// CÂU 3
// =======================================================
int main() {
    PS2 ds[10];
    int n;

    do {
        cout << "Nhap so luong phan so (1 den 10): ";
        cin >> n;
    } while (n <= 0 || n > 10);

    cout << "\n=== NHAP DANH SACH PHAN SO ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sap xep giam dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) {
                PS2 temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\n=== DANH SACH SAU KHI SAP XEP GIAM DAN ===\n";
    for (int i = 0; i < n; i++) {
        cout << "  Phan so " << i + 1 << ": ";
        ds[i].in();
        cout << endl;
    }

    return 0;
}
