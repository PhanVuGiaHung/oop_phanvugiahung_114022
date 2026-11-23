#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Lop quan ly san pham
class SanPham {
private:
    string tenSanPham;
    string donViTinh;
    int soLuong;
    double donGia;

public:
    // Ham nhap thong tin san pham
    void nhap() {
        cout << "Nhap ten san pham: ";
        getline(cin >> ws, tenSanPham);

        cout << "Nhap don vi tinh: ";
        getline(cin >> ws, donViTinh);

        cout << "Nhap so luong: ";
        cin >> soLuong;

        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    // Ham tinh thanh tien
    double tinhThanhTien() {
        return soLuong * donGia;
    }

    // Ham hien thi san pham
    void xuat(int soThuTu) {
        cout << left
             << setw(5) << soThuTu
             << setw(25) << tenSanPham
             << setw(12) << donViTinh
             << setw(10) << soLuong
             << setw(15) << fixed << setprecision(0)
             << donGia
             << setw(15) << tinhThanhTien()
             << endl;
    }
};

// Lop quan ly hoa don
class HoaDon {
private:
    string soHoaDon;
    string ngayLap;
    string tenKhachHang;
    string diaChi;
    SanPham danhSach[100];
    int soSanPham;
    double thueSuat;

public:
    // Ham khoi tao
    HoaDon() {
        soSanPham = 0;
        thueSuat = 0;
    }

    // Ham nhap hoa don
    void nhapHoaDon() {
        cout << "\n===== NHAP HOA DON =====\n";

        cout << "Nhap so hoa don: ";
        getline(cin >> ws, soHoaDon);

        cout << "Nhap ngay lap: ";
        getline(cin >> ws, ngayLap);

        cout << "Nhap ten khach hang: ";
        getline(cin >> ws, tenKhachHang);

        cout << "Nhap dia chi: ";
        getline(cin >> ws, diaChi);

        cout << "Nhap so san pham: ";
        cin >> soSanPham;

        if (soSanPham < 0 || soSanPham > 100) {
            cout << "So san pham khong hop le!\n";
            soSanPham = 0;
            return;
        }

        for (int i = 0; i < soSanPham; i++) {
            cout << "\n--- San pham " << i + 1 << " ---\n";
            danhSach[i].nhap();
        }

        cout << "Nhap thue GTGT (%): ";
        cin >> thueSuat;

        cout << "\nNhap hoa don thanh cong!\n";
    }

    // Ham tinh tong tien hang
    double tinhTongTien() {
        double tong = 0;

        for (int i = 0; i < soSanPham; i++) {
            tong += danhSach[i].tinhThanhTien();
        }

        return tong;
    }

    // Ham tinh tien thue
    double tinhTienThue() {
        return tinhTongTien() * thueSuat / 100;
    }

    // Ham tinh tong thanh toan
    double tinhThanhToan() {
        return tinhTongTien() + tinhTienThue();
    }

    // Ham xuat hoa don
    void xuatHoaDon() {
        cout << "\n";
        cout << "====================================================\n";
        cout << " HOA DON BAN HANG \n";
        cout << "====================================================\n";

        cout << "So hoa don: " << soHoaDon << endl;
        cout << "Ngay lap: " << ngayLap << endl;
        cout << "Khach hang: " << tenKhachHang << endl;
        cout << "Dia chi: " << diaChi << endl;

        cout << "----------------------------------------------------\n";

        cout << left
             << setw(5) << "STT"
             << setw(25) << "Ten san pham"
             << setw(12) << "Don vi"
             << setw(10) << "So luong"
             << setw(15) << "Don gia"
             << setw(15) << "Thanh tien"
             << endl;

        cout << "----------------------------------------------------\n";

        for (int i = 0; i < soSanPham; i++) {
            danhSach[i].xuat(i + 1);
        }

        cout << "----------------------------------------------------\n";

        cout << fixed << setprecision(0);
        cout << "Tong tien hang: " << tinhTongTien() << " VND\n";
        cout << "Thue GTGT (" << thueSuat << "%): "
             << tinhTienThue() << " VND\n";
        cout << "Tong thanh toan: "
             << tinhThanhToan() << " VND\n";

        cout << "====================================================\n";
    }
};

// Ham main
int main() {
    HoaDon hoaDon;
    int luaChon;
    bool daNhap = false;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Nhap hoa don\n";
        cout << "2. Xuat hoa don\n";
        cout << "3. Xem tong tien hang\n";
        cout << "4. Xem tien thue GTGT\n";
        cout << "5. Xem tong thanh toan\n";
        cout << "0. Thoat\n";
        cout << "==========================\n";

        cout << "Nhap lua chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            hoaDon.nhapHoaDon();
            daNhap = true;
        }
        else if (luaChon == 0) {
            cout << "Tam biet!\n";
        }
        else if (!daNhap) {
            cout << "Ban chua nhap hoa don!\n";
        }
        else if (luaChon == 2) {
            hoaDon.xuatHoaDon();
        }
        else if (luaChon == 3) {
            cout << "Tong tien hang: "
                 << hoaDon.tinhTongTien() << " VND\n";
        }
        else if (luaChon == 4) {
            cout << "Tien thue GTGT: "
                 << hoaDon.tinhTienThue() << " VND\n";
        }
        else if (luaChon == 5) {
            cout << "Tong thanh toan: "
                 << hoaDon.tinhThanhToan() << " VND\n";
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }

    } while (luaChon != 0);

    return 0;
}

