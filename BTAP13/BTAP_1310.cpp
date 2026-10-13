#include <iostream>
using namespace std;

//cau 1
class sophuc{
    private:
        float thuc, ao;
    public:
        sophuc(){
            thuc = ao = 0;
        }
        sophuc(float thuc, float ao){
            this->thuc = thuc;
            this->ao = ao;
        }
        ~sophuc(){}
        
        //cau 2
        friend istream& operator>> (istream &is, sophuc &p);
        friend ostream& operator<< (ostream &os, sophuc p);
        
        //cau 3: xay dung la method nap chồng toán tử
        sophuc operator+ (sophuc a){ //this+a
            sophuc kq;
            kq.thuc = thuc + a.thuc;
            kq.ao = ao + a.ao;
            return kq;
        }

        sophuc operator- (sophuc a){
            sophuc kq;
            kq.thuc = thuc - a.thuc; 
            kq.ao = ao - a.ao;
            return kq;
        }
        
        sophuc operator* (sophuc a){ //this*a=(thuc +ao*i)*(a.thuc+a.ao*i)=...
            sophuc kq;
            kq.thuc = thuc * a.thuc - ao * a.ao; 
            kq.ao = thuc * a.ao + ao * a.thuc;
            return kq;
        }
        
        sophuc operator/ (sophuc a){ //this/a...
            sophuc kq;
            float mau;
            mau = a.thuc * a.thuc + a.ao * a.ao;
            if (mau == 0){ 
                cout << "khong co so phuc: "; 
            }
            else {
                 kq.thuc = (thuc * a.thuc + ao * a.ao) / mau;
                 kq.ao = (ao * a.thuc - thuc * a.ao) / mau;
            }
            return kq;
        }
}; 

istream& operator>> (istream &is, sophuc &p) {
    cout << "Nhap phan thuc: "; is >> p.thuc;
    cout << "Nhap phan ao: "; is >> p.ao;
    return is;
}

ostream& operator<< (ostream &os, sophuc p) {
    if (p.ao < 0) os << p.thuc << p.ao << "i" << endl;
    else os << p.thuc << "+" << p.ao << "i" << endl;
    return os;
}

// ==========================================
// PHẦN ĐUÔI BỔ SUNG ĐỂ HOÀN THIỆN CHƯƠNG TRÌNH
// ==========================================
int main() {
    sophuc p1, p2;
    
    cout << "--- NHAP THONG TIN HAI SO PHUC ---\n";
    cout << "Nhap so phuc thu 1:\n";
    cin >> p1;
    cout << "\nNhap so phuc thu 2:\n";
    cin >> p2;

    cout << "\n--- KET QUA HIỂN THỊ ---\n";
    cout << "So phuc 1: " << p1;
    cout << "So phuc 2: " << p2;

    sophuc tong = p1 + p2;
    sophuc hieu = p1 - p2;
    sophuc tich = p1 * p2;
    sophuc thuong = p1 / p2;

    cout << "\nTong (p1 + p2) = " << tong;
    cout << "Hieu (p1 - p2) = " << hieu;
    cout << "Tich (p1 * p2) = " << tich;
    cout << "Thuong (p1 / p2) = " << thuong;

    return 0;
}

```
