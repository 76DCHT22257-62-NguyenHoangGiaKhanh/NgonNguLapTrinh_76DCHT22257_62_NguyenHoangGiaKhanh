#include <iostream>
#include <cmath> // Dùng hàm sqrt() để tính module số phức

using namespace std;

// ==========================================
// CÂU 1: KHAI BÁO LỚP SP1 VÀ CÁC PHƯƠNG THỨC
// ==========================================

class SP1 {
protected:
    float thuc; // Phần thực
    float ao;   // Phần ảo

public:
    // Hàm tạo (Constructor) không tham số và có tham số
    SP1() {
        thuc = 0;
        ao = 0;
    }

    SP1(float t, float a) {
        thuc = t;
        ao = a;
    }

    // Phương thức nhập số phức
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    // Phương thức in số phức (Dạng: a + bi)
    void xuat() {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << abs(ao) << "i";
    }

    // Phương thức tính Module số phức: |z| = sqrt(thuc^2 + ao^2)
    float tinhModule() {
        return sqrt(thuc * thuc + ao * ao);
    }
};

// ==========================================
// CÂU 2: XÂY DỰNG LỚP SP2 KẾ THỪA SP1
// & NẠP CHỒNG TOÁN TỬ = , >
// ==========================================

class SP2 : public SP1 {
public:
    // Hàm tạo kế thừa
    SP2() : SP1() {}
    SP2(float t, float a) : SP1(t, a) {}

    // Nạp chồng toán tử gán (=)
    SP2& operator=(const SP2 &sp) {
        if (this != &sp) {
            thuc = sp.thuc;
            ao = sp.ao;
        }
        return *this;
    }

    // Nạp chồng toán tử so sánh lớn hơn (>) theo Module
    bool operator>(SP2 sp) {
        return this->tinhModule() > sp.tinhModule();
    }
};

// ==========================================
// CÂU 3: CHƯƠNG TRÌNH CHÍNH & SẮP XẾP GIẢM DẦN
// ==========================================

int main() {
    int n;
    cout << "Nhap so luong so phuc (n <= 10): ";
    cin >> n;

    // Giới hạn n tối đa 10 theo yêu cầu đề bài
    if (n > 10) n = 10;

    SP2 ds[10]; // Mảng chứa tối đa 10 số phức

    // Nhập danh sách số phức
    for (int i = 0; i < n; i++) {
        cout << "\nNhap so phuc thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }

    // Sắp xếp danh sách giảm dần theo Module (dùng toán tử > đã nạp chồng)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!(ds[i] > ds[j])) { // Nếu ds[i] không lớn hơn ds[j] thì đổi chỗ
                SP2 temp = ds[i];   // Sử dụng toán tử gán =
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // In danh sách sau khi sắp xếp
    cout << "\n=== DANH SACH SO PHUC GIAM DAN THEO MODULE ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "So phuc " << i + 1 << ": ";
        ds[i].xuat();
        cout << " | Module = " << ds[i].tinhModule() << endl;
    }

    return 0;
}
