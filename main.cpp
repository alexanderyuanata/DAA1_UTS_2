#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

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
//fungsi ini buat struct data_dinamis kosong habis itu dikembalikan alamat structnya
data_dinamis* newStruct() {
    data_dinamis* data = new data_dinamis;
    return data;
}

//buat copy dari elemen linked list yang dipass alamatnya
data_dinamis* createStructCopy(data_dinamis* source) {
    data_dinamis* copy = new data_dinamis;

    //isi dari copy sama dengan data yang dicopy
    copy->harga = source->harga;
    copy->id = source->id;
    copy->nama = source->nama;
    copy->satuan = source->satuan;
    copy->stok = source->stok;
    //ptr tidak dicopy karena tidak boleh menunjuk ke alamat linked list asal
    copy->ptr = nullptr;

    //mengembalikan alamat copy
    return copy;
}

//buat copy linked list, yg dipass alamat kepala linked list
data_dinamis* createLinkedListCopy(data_dinamis* head) {
    //copy terakhir itu copy dari kepala
    data_dinamis* lastcopy = createStructCopy(head);
    //data yg dicopy selanjutnya itu ditunjuk kepala
    data_dinamis* nextcopy = head->ptr;
    //kepala dari copy linked list itu copy kepala
    data_dinamis* origin = lastcopy;

    //selagi ada elemen dalam linked list
    while (nextcopy != nullptr) {
        //buat copy baru dari elemen selanjutnya
        data_dinamis* newcopy = createStructCopy(nextcopy);
        //elemen sebelumnya menunjuk ke elemen baru
        lastcopy->ptr = newcopy;
        //elemen yang akan dicopy adalah elemen berikutnya
        nextcopy = nextcopy->ptr;
        //copy terakhir adalah hasil copy yang baru ini
        lastcopy = newcopy;
    }

    return origin;
}


void statis() {
    int opsiStatis, jumlah, n;
    vector<data_statis>barang(20);

    menu:
    system("cls");
    cout<<"Menu Data Statis :";
    cout<<"\n1. Input Data";
    cout<<"\n2. Tampilkan Data";
    cout<<"\n3. Update Data";
    cout<<"\n4. Delete Data";
    cout<<"\n5. Back\n>> ";
    cin>>opsiStatis;

    switch (opsiStatis) {
                case 1: {
                    cout<<"\nMasukkan jumlah data yang akan di-input : ";cin>>jumlah;

                    for (int i=0;i<jumlah;i++)
                    {
                        cout<<"\nBARANG "<<i+1;
                        cout<<"\nNama barang : ";cin>>barang[i].nama;
                        cout<<"Stok barang : ";cin>>barang[i].stok;
                        cout<<"Harga barang : ";cin>>barang[i].harga;
                        cout<<"Unit satuan : ";cin>>barang[i].satuan;
                    }
                    system("pause");
                    goto menu;
                }

                case 2: {
                    for (int i=0;i<jumlah;i++)
                    {
                        cout<<"\nBARANG "<<i+1;
                        cout<<"\nNama barang : "<<barang[i].nama;
                        cout<<"\nStok barang : "<<barang[i].stok;
                        cout<<"\nHarga barang : "<<barang[i].harga;
                        cout<<"\nUnit satuan : "<<barang[i].satuan;
                        cout<<endl;
                    }
                    system("pause");
                    goto menu;
                }

                case 3: {
                    system("pause");
                    goto menu;
                }

                case 4: {
                    cout<<"Pilih data keberapa yang akan di-delete : ";cin>>n;
                    barang.erase(barang.begin()+(n-1));
                    system("pause");
                    goto menu;
                }

                case 5: {
                    break;
                }

                default: {
                    cout << "Opsi tidak ada! ";
                    system("pause");
                    goto menu;
                }
        }
    system("cls");
}

void dinamis() {

}

//jangan disentuh, ini buat testing linked list aja, nanti dihapus
data_dinamis ekor{
    "Susu Beruang",
    3,
    30,
    11000,
    "Kaleng",
    nullptr
};

data_dinamis badan{
    "Sprite",
    2,
    20,
    4000,
    "Botol",
    &ekor
};

data_dinamis kepala{
    "Coca Cola",
    1,
    45,
    5000,
    "Botol",
    &badan
};

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

