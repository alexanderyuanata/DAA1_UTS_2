#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//struktur data yang dipakai
struct data_statis {
    string nama{};              //nama barang
    unsigned int id{};          //id barang
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
const unsigned int nmax = 20;


//fungsi-fungsi di sini
//fungsi ini buat struct data_dinamis kosong habis itu dikembalikan alamat structnya
data_dinamis* newNode() {
    data_dinamis* data = new data_dinamis;
    return data;
}

//buat copy dari elemen linked list yang dipass alamatnya
data_dinamis* createNodeCopy(data_dinamis* source) {
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
    data_dinamis* lastcopy = createNodeCopy(head);
    //data yg dicopy selanjutnya itu ditunjuk kepala
    data_dinamis* nextcopy = head->ptr;
    //kepala dari copy linked list itu copy kepala
    data_dinamis* origin = lastcopy;

    //selagi ada elemen dalam linked list
    while (nextcopy != nullptr) {
        //buat copy baru dari elemen selanjutnya
        data_dinamis* newcopy = createNodeCopy(nextcopy);
        //elemen sebelumnya menunjuk ke elemen baru
        lastcopy->ptr = newcopy;
        //elemen yang akan dicopy adalah elemen berikutnya
        nextcopy = nextcopy->ptr;
        //copy terakhir adalah hasil copy yang baru ini
        lastcopy = newcopy;
    }

    return origin;
}

//traverse the list until reaching the tail
data_dinamis* traversetoTail(data_dinamis* head) {
    //while node isn't the tail, keep traversing the list
    data_dinamis* current = head;
    while (current->ptr != nullptr) {
        current = current->ptr;
    }
    return current;
}

//count the number of nodes inside the list
int getlen_ofList(data_dinamis** head) {
    int count{ 0 };
    if (*head == nullptr) {
        return count;
    }
    //while node isn't the tail, keep traversing the list
    data_dinamis* data_todisplay = *head;
    while (data_todisplay != nullptr) {
        //iterate count by one, and move it forward
        count++;
        data_todisplay = (*data_todisplay).ptr;
    }

    return count;
}

//Input data dinamis
void inputDinamis(data_dinamis** head) {
    //if the list is empty, create a head
    if (*head == nullptr) {
        *head = newNode();
        cin.ignore();
        cout << "Nama barang  : "; getline(cin, (**head).nama);
        cout << "ID barang    : "; cin >> (**head).id;
        cout << "Stok barang  : "; cin >> (**head).stok;
        cout << "Harga barang : "; cin >> (**head).harga;
        cout << "Unit satuan  : "; cin >> (**head).satuan;
    }
    //if not, then traverse the list until the head and append a new node
    else {
        data_dinamis* current{};
        //traverse the list to its tail, append a new struct to the list and move the current pointer forward
        current = traversetoTail(*head);
        current->ptr = newNode();
        current = current->ptr;

        cin.ignore();
        cout << "Nama barang  : "; getline(cin, (*current).nama);
        cout << "ID barang    : "; cin >> (*current).id;
        cout << "Stok barang  : "; cin >> (*current).stok;
        cout << "Harga barang : "; cin >> (*current).harga;
        cout << "Unit satuan  : "; cin >> (*current).satuan;
        (*current).ptr = nullptr;
    }
}

//display node contents
void displayNode(data_dinamis node) {
    cout << "Nama barang  : " << node.nama << '\n'
        << "ID barang    : " << node.id << '\n'
        << "Stok barang  : " << node.stok << '\n'
        << "Harga barang : " << node.harga << '\n'
        << "Unit satuan  : " << node.satuan << "\n\n";
}


//update linked list
void updateList(data_dinamis** head) {
    if (*head == nullptr) {
        cout << "Tidak ada data yang terdeteksi dalam linked list! ";
    }
    else {
        cout << "Barang keberapa yang akan diupdate? ";
        int index{};
        cin >> index;

        if (index > getlen_ofList(head) || index < 1) {
            cout << "Index tidak terdapat dalam linked list! ";
            return;
        }

        int i{ 0 };
        data_dinamis* data_toupdate = *head;
        while (data_toupdate != nullptr) {
            i++;
            if (i == index) {
                cin.ignore();
                cout << "Nama barang  : "; getline(cin, (*data_toupdate).nama);
                cout << "ID barang    : "; cin >> (*data_toupdate).id;
                cout << "Stok barang  : "; cin >> (*data_toupdate).stok;
                cout << "Harga barang : "; cin >> (*data_toupdate).harga;
                cout << "Unit satuan  : "; cin >> (*data_toupdate).satuan;
                return;
            }
            data_toupdate = (*data_toupdate).ptr;
        }
    }

}

//menghapus node
void deleteNode(data_dinamis** head) {
    //if linked list is empty
    if (*head == nullptr) {
        cout << "Tidak ada data yang terdeteksi dalam linked list! ";
    }
    //if not then
    else {
        cout << "Barang keberapa yang akan dihapus? ";
        int index{};
        cin >> index;
        //check if index is within linked list range
        if (index > getlen_ofList(head) || index < 1) {
            cout << "Index tidak terdapat dalam linked list! ";
            return;
        }

        int i{ 0 };
        data_dinamis* data_todelete = *head;
        //if the data to be deleted is the head, delete it and make the next node the head
        if (index == 1) {
            *head = data_todelete->ptr;
            delete data_todelete;
            return;
        }
        //traverse the list until the node before the index
        while (data_todelete != nullptr) {
            i++;
            if (i == (index - 1)) {
                //determine the data to delete, previous data and upcoming data
                data_dinamis* data_prev = data_todelete;
                data_todelete = (*data_prev).ptr;
                data_dinamis* data_next = (*data_todelete).ptr;

                //delete the data and stitch the gap together
                delete data_todelete;
                (*data_prev).ptr = data_next;
                return;
            }
            data_todelete = (*data_todelete).ptr;
        }
    }
}

//mengembalikan alamat node pada index tertentu
data_dinamis* getnodeAt(data_dinamis** head, int index) {
    int i{ 0 };
    data_dinamis* current = *head;
    while (current != nullptr) {
        if (i == index) {
            return current;
        }
        i++;
        current = (*current).ptr;
    }
    return nullptr;
}

//copy node from copy to paste
void copyNode(data_dinamis* copy, data_dinamis* paste) {
    (*paste).nama = (*copy).nama;
    (*paste).id = (*copy).id;
    (*paste).stok = (*copy).stok;
    (*paste).harga = (*copy).harga;
    (*paste).satuan = (*copy).satuan;
}

//swap node
void swapNode(data_dinamis* m, data_dinamis* n) {
    data_dinamis* temp = createNodeCopy(m);
    copyNode(n, m);
    copyNode(temp, n);

    delete temp;
}

//sorting linked list
void selectionSort(data_dinamis** head) {
    //selection sort by price
    for (int i = 0; i < (getlen_ofList(head) - 1); i++) {
        int i_max = i;
        for (int j = i + 1; j < (getlen_ofList(head)); j++) {
            if (getnodeAt(head, j)->harga
                >
                getnodeAt(head, i_max)->harga) {
                i_max = j;
            }
        }
        if (i_max != i) {
            swapNode(getnodeAt(head, i), getnodeAt(head, i_max));
        }
    }
}


//display linked list content
void displayList(data_dinamis** head) {
    selectionSort(head);
    //if list is empty
    if (*head == nullptr) {
        cout << "Tidak ada data yang tersedia! ";
    }
    //if not
    else {
        //start from head
        data_dinamis* data_todisplay = *head;
        int i{ 0 };
        while (data_todisplay != nullptr) {
            //iterate count by one, display current data and move it forward
            cout << "Data #" << ++i << '\n';
            displayNode(*data_todisplay);
            data_todisplay = (*data_todisplay).ptr;
        }
    }
}

//copy array 1 to other
void copyArrayElement(data_statis* m, data_statis* n)
{
    n->nama = m->nama;
    n->id = m->id;
    n->stok = m->stok;
    n->harga = m->harga;
    n->satuan = m->satuan;
}

//bubble sort statis
void bubbleSort(data_statis sort[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (sort[j].harga < sort[j + 1].harga)
            {
                data_statis temp;
                copyArrayElement(&sort[j + 1], &temp);
                copyArrayElement(&sort[j], &sort[j + 1]);
                copyArrayElement(&temp, &sort[j]);
            }
        }
    }
}

//input data statis
void inputStatis(data_statis barang[], int *jumlah, int *data, bool *input) {
    cout << "\nMasukkan jumlah data yang akan di-input : ";
    int a; cin >> a;
    if (*jumlah + a > 20) {
        cout << "Maksimum data sebanyak 20!\n";
        system("pause");
        return;
    }
    else {
        *jumlah += a;
    }

    if (*input == true) {
        for (int i = *data; i < *jumlah; i++)
        {
            cin.ignore();
            cout << "\nBarang " << i + 1 << '\n';
            cout << "Nama barang  : "; getline(cin, barang[i].nama);
            cout << "ID barang    : "; cin >> barang[i].id;
            cout << "Stok barang  : "; cin >> barang[i].stok;
            cout << "Harga barang : "; cin >> barang[i].harga;
            cout << "Unit satuan  : "; cin >> barang[i].satuan;
            *data += 1;
        }
    }

    else {
        for (int i = 0; i < *jumlah; i++)
        {
            cin.ignore();
            cout << "\nBarang #" << i + 1 << '\n';
            cout << "Nama barang  : "; getline(cin, barang[i].nama);
            cout << "ID barang    : "; cin >> barang[i].id;
            cout << "Stok barang  : "; cin >> barang[i].stok;
            cout << "Harga barang : "; cin >> barang[i].harga;
            cout << "Unit satuan  : "; cin >> barang[i].satuan;
            if (i > 0) {
                *data += 1;
            }
        }
        *input = true;
    }
}

//tampilkan data statis
void displayStatis(data_statis barang[], int jumlah) {
    for (int i = 0; i < jumlah; i++)
    {
        cout << "\nBarang #" << i + 1;
        cout << "\nNama barang  : " << barang[i].nama;
        cout << "\nID barang    : " << barang[i].id;
        cout << "\nStok barang  : " << barang[i].stok;
        cout << "\nHarga barang : " << barang[i].harga;
        cout << "\nUnit satuan  : " << barang[i].satuan;
        cout << endl;
    }
}

//update data statis
void updateStatis(data_statis barang[]) {
    int n{};
    cout << "\nPilih data keberapa yang akan di-update : "; cin >> n; cout << '\n';
    if (n < 1 || n > nmax) {
        cout << "Data tidak terdapat dalam data statis! ";
        system("pause");
        return;
    }
    cin.ignore();
    cout << "Update barang #" << n << '\n';
    cout << "Nama barang  : "; getline(cin, barang[n - 1].nama);
    cout << "ID barang    : "; cin >> barang[n - 1].id;
    cout << "Stok barang  : "; cin >> barang[n - 1].stok;
    cout << "Harga barang : "; cin >> barang[n - 1].harga;
    cout << "Unit satuan  : "; cin >> barang[n - 1].satuan;
}

//delete data
void deleteStatis(data_statis barang[], int* jumlah, int* data) {
    int n;
    cout << "\nPilih data keberapa yang akan di-delete : "; cin >> n;
    for (int i = n - 1; i < *jumlah; i++)
    {
        barang[i] = barang[i + 1];
    }
    *data -= 1;
    *jumlah -= 1;
    system("pause");
}

//data statis
void statis() {
    int opsiStatis, jumlah = 0, data = 1;
    bool input{};
    data_statis barang[20];

    while (true) {
        system("cls");
        cout << "Menu Data Statis :";
        cout << "\n1. Input Data";
        cout << "\n2. Tampilkan Data";
        cout << "\n3. Update Data";
        cout << "\n4. Delete Data";
        cout << "\n5. Back\n>> ";
        cin >> opsiStatis;

        switch (opsiStatis) {
        case 1: {
            inputStatis(barang, &jumlah, &data, &input);
            system("pause");
            break;
        }

        case 2: {
            bubbleSort(barang, jumlah);
            displayStatis(barang, jumlah);
            system("pause");
            break;
        }

        case 3: {
            updateStatis(barang);
            system("pause");
            break;
        }

        case 4: {
            deleteStatis(barang, &jumlah, &data);
            break;
        }

        case 5: {
            goto restart_static;
            break;
        }

        default: {
            cout << "Opsi tidak ada! ";
            system("pause");
            break;
        }
        }
    }
restart_static:
    system("cls");
}

//data dinamis
void dinamis() {
    data_dinamis* head = nullptr;
    bool flag = true;

    while (flag) {
        system("cls");
        cout << "Panjang linked list sekarang: " << getlen_ofList(&head) << '\n'
            << "1. Input data\n"
            << "2. Tampilkan data\n"
            << "3. Update data\n"
            << "4. Delete data\n"
            << "5. Back\n"
            << ">> ";
        int select{};
        cin >> select;

        switch (select) {
        case 1: {
            cout << "Berapa banyak data yang ingin dimasukkan? "; int data_count{}; cin >> data_count;
            for (int i = 0; i < data_count; i++) {
                cout << "\nData #" << i + 1 << endl;
                inputDinamis(&head);
                cout << "\n\n";
            }
            break;
        }

        case 2: {
            displayList(&head);
            break;
        }

        case 3: {
            displayList(&head);
            updateList(&head);
            break;
        }

        case 4: {
            displayList(&head);
            deleteNode(&head);
            break;
        }

        case 5: {
            flag = false;
            break;
        }

        default: {
            cout << "Opsi tidak ada! ";
            break;
        }

        }
        system("pause");
    }
}

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

