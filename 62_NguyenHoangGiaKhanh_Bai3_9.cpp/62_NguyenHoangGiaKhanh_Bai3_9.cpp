#include <iostream>

using namespace std;

int main() {
    
    /*
    - Bai toan lap o viec lien tuc cong/tru cac so hang co dang 10 * i (i chay tu 1 den n).
    - Lua chon vong lap FOR la hop ly nhat vi da biet truoc so lan lap co dinh la n lan.
    - Quy luat: i le thi TRU (-), i chan thi CONG (+)
    */

    int n;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;

    // Khoi tao tong T ban dau bang 100 theo de bai
    long long T = 100; 

    // Vong lap for chay tu 1 den n de tinh bieu thuc
    for (int i = 1; i <= n; i++) {
        int so_hang = 10 * (i + 1); // i=1 -> 20, i=2 -> 30, i=3 -> 40...
        
        if (i % 2 != 0) {
            // Neu i le: thuc hien phep TRU
            T -= so_hang;
        } else {
            // Neu i chan: thuc hien phep CONG
            T += so_hang;
        }
    }

    // In ket qua ra man hinh
    cout << "Ket qua bieu thuc T = " << T << endl;

    return 0;
}
