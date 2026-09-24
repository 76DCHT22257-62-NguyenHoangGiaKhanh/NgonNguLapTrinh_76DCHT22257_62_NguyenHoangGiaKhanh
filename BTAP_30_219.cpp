#include <iostream>
#include <cmath>
using namespace std;

// =======================================================
// CÂU 1
// =======================================================
class SP1 {
protected:
    float thuc, ao;

public:
    // Hàm tạo (Constructor)
    SP1(float t = 0, float a = 0) {
        thuc = t;
        ao = a;
    }

    void nhap() {
        cout << "  - Nhap phan thuc: ";
        cin >> thuc;
        cout << "  - Nhap phan ao: ";
        cin >> ao;
    }

    void in() {
        if (ao >= 0) {
            cout << thuc << " + " << ao << "i";
        } else {
            cout << thuc << " - " << abs(ao) << "i";
        }
    }

    // Module so phuc = sqrt(thuc^2 + ao^2)
    float tinhModule() {
        return sqrt(thuc * thuc + ao * ao);
    }
};

// =======================================================
// CÂU 2
// =======================================================
class SP2 : public SP1 {
public:
    SP2(float t = 0, float a = 0) : SP1(t, a) {}

    // Nap chong toan tu gan (=)
    SP2& operator=(const SP2& spKhac) {
        if (this != &spKhac) {
            this->thuc = spKhac.thuc;
            this->ao = spKhac.ao;
        }
        return *this;
    }

    // Nap chong toan tu so sanh lon hon (>) theo module
    bool operator>(SP2 spKhac) {
        return this->tinhModule() > spKhac.tinhModule();
    }
};

// =======================================================
// CÂU 3
// =======================================================
int main() {
    SP2 ds[10];
    int n;

    do {
        cout << "Nhap so luong so phuc (1 den 10): ";
        cin >> n;
    } while (n <= 0 || n > 10);

    cout << "\n=== NHAP DANH SACH SO PHUC ===\n";
    for (int i = 0; i < n; i++) {
        cout << "So phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sap xep giam dan theo module
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) {
                SP2 temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\n=== DANH SACH SAU KHI SAP XEP GIAM DAN THEO MODULE ===\n";
    for (int i = 0; i < n; i++) {
        cout << "  So phuc " << i + 1 << ": ";
        ds[i].in();
        cout << " (Module = " << ds[i].tinhModule() << ")\n";
    }

    return 0;
}
