#include <iostream>
#include <string>

using namespace std;

//struktur data yang dipakai
struct data_statis{
    string nama{};              //nama barang
    unsigned int stok{};        //stok barang yang tersisa
    unsigned long int harga{};  //harga barang
    string satuan{};            //unit satuan barang
};

struct data_dinamis{
    string nama{};              //nama barang
    unsigned int stok{};        //stok barang yang tersisa
    unsigned long int harga{};  //harga barang
    string satuan{};            //unit satuan barang

    data_dinamis* ptr{};
};

//deklarasi global di sini



//fungsi-fungsi di sini



int main()
{
    while (true){
        cout    << "Selamat datang di Microhard Binbows Excelsior!\n"
                << "1. Data Statis\n"
                << "2. Data Dinamis\n"
                << "3. Exit\n>> ";
        int x;
        cin >> x;

        switch(x){
            case 1 : {
                //masuk fungsi statis
                break;
            }

            case 2 : {
                //masuk fungsi dinamis
                break;
            }

            case 3 : {
                exit(0);
                break;
            }

            default : {
                cout << "Opsi tidak ada!";
            }
        }
        system("CLS");
    }
}

