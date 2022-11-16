#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//struktur data yang dipakai
struct data_statis {
    string nama{};              //nama barang
    unsigned int stok{};        //stok barang yang tersisa
    unsigned long int harga{};  //harga barang
    string satuan{};            //unit satuan barang
};

struct data_dinamis {
    string nama{};              //nama barang
    unsigned int id{};          //id barang
    unsigned int stok{};        //stok barang yang tersisa
    unsigned long int harga{};  //harga barang
    string satuan{};            //unit satuan barang

    data_dinamis* ptr{};        //pointer yang menunjuk ke struct berikutnya
};

//deklarasi global di sini



//fungsi-fungsi di sini
//fungsi ini buat struct data_dinamis baru habis itu dikembalikan alamat structnya
data_dinamis* newStruct() {
    data_dinamis* data = new data_dinamis;
    return data;
}

void statis() {

}

void dinamis() {

}

//jangan disentuh, ini buat testing algo sorting dinamis


int main()
{
    while (true) {
            cout << "Selamat datang di Microhard Binbows Excelsior!\n"
                << "1. Data Statis\n"
                << "2. Data Dinamis\n"
                << "3. Exit\n>> ";
            int x;
            cin >> x;

            switch (x) {
            case 1: {
                statis();
                break;
            }

            case 2: {
                dinamis();
                break;
            }

            case 3: {
                exit(0);
                break;
            }

            default: {
                cout << "Opsi tidak ada! ";
                system("pause");
                break;
            }
        }
        system("CLS");
    }
}

