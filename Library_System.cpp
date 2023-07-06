#include <iostream>
#include <string>
#define MAX 10

using namespace std;

// Struct Untuk menyimpan data yang diinpuntkan mahasiswa
struct
{
    string inputStudentName[MAX];
    int inputBookTitle[MAX];
    string inputStudentAdress[MAX];
    int inputStudentNumber[MAX];
    int inputStudentOption;
    // variable untuk menyimpan durasi peminjaman buku
    int bookBorrowingDuration[MAX];
} InputStudentsData;

int arrayIndeks = 0;

// Array untuk menampilkan daftar judul - judul buku
string booksTitle[5] =
    {
        "Pemograman web",
        "Basis data",
        "Bahasa pemograman javascript",
        "Struktur data dan algorithma",
        "Membuat game dengan unreal engine"};

// Function untuk menampilkan seluruh judul buku
void ShowBooksTitle()
{
    // Variable untuk pengulangan
    int indeks = 1;
    cout << "" << endl;
    cout << " === Judul buku yang bisa dipinjam === " << endl;
    for (indeks; indeks < 5; indeks++)
    {
        cout << indeks << ". " << booksTitle[indeks] << endl;
    }
    cout << " ===================================== " << endl;
}

// Function untuk menampilkan pilihan meminjam atau mengembalikan buku
static bool StudentOptions()
{
    // Array untuk menampilkan pilihan meminjam atau mengembalikan buku
    string listOptions[2] = {" Meminjam buku? ", " Mengembalikan buku? "};

    // Variable untuk pengulangan
    int indeksOption = 0;
    for (indeksOption; indeksOption < 2; indeksOption++)
    {
        cout << indeksOption << ". " << listOptions[indeksOption] << endl;
    }

    cout << " Masukkan pilihan anda : ";
    cin >> InputStudentsData.inputStudentOption;

    // Jika pengguna sudah memasukkan pilihan jalankan function untuk menampilkan judul buku
    if (InputStudentsData.inputStudentOption == 0 || InputStudentsData.inputStudentOption == 1)
    {
        // Jalankan function untuk menampilkan judul buku
        ShowBooksTitle();
        return true;
    }
    else if (!InputStudentsData.inputStudentOption == 0 || InputStudentsData.inputStudentOption == 1)
    {
        cout << " Data salah" << endl;
        cout << " Masukkan pilihan anda : ";
        cin >> InputStudentsData.inputStudentOption;
        ShowBooksTitle();
        return true;
    }
    return NULL;
}

// Funciton untuk menampilkan data yang harus diinputkan pengguna
void InputDataStudent()
{
    cout << "" << endl;
    cout << " === Silahkan isi data berikut untuk meminjam / mengembalikanbuku === " << endl;

    // Jika antrian kosong pengguna bisa memasukkan data dan melakukan peminjaman
    if (MAX == 10)
    {
        for (int i = 1; i < 10; i++)
        {
        CompleteInput:
            cout << "Masukkan nama Mahasiswa : \n";
            cin >> InputStudentsData.inputStudentName[i];

            cout << "Masukkan nim Mahasiswa : \n";
            cin >> InputStudentsData.inputStudentNumber[i];

            cout << "Masukkan alamat Mahasiswa : \n";
            cin >> InputStudentsData.inputStudentAdress[i];

            cout << "Masukkan judul buku : \n";
            cin >> InputStudentsData.inputBookTitle[i];

            cout << "Masukkan waktu peminjaman buku : \n";
            cin >> InputStudentsData.bookBorrowingDuration[i];

            // Jika data sudah lengkap akan beralih ke pengguna lainnya menginputkan data
            if (InputStudentsData.inputStudentName[i] != "" && InputStudentsData.inputStudentAdress[i] != "" && InputStudentsData.inputBookTitle[i] > 0)
            {
                if (InputStudentsData.inputStudentNumber[i] > 0 && InputStudentsData.bookBorrowingDuration[i] > 0)
                {
                    cout << " === Terimakasih sudah berkunjung di perpustakaan === " << endl;
                    for (int j = 1; j < MAX; j++)
                    {
                        cout << "Nama : " << InputStudentsData.inputStudentName[j] << endl;
                        cout << "Nim : " << InputStudentsData.inputStudentNumber[j] << endl;
                        cout << "Alamat : " << InputStudentsData.inputStudentAdress[j] << endl;
                        cout << "Judul buku : " << booksTitle[InputStudentsData.inputBookTitle[j]] << endl;
                        cout << "Durasi peminjalam : " << InputStudentsData.bookBorrowingDuration[j] << " Hari " << endl;
                        cout << "" << endl;
                        // break;

                        // Hapus data pada atrean pertama
                        InputStudentsData.inputStudentName[-1]; 
                        InputStudentsData.inputStudentNumber[-1]; 
                        InputStudentsData.inputStudentAdress[-1]; 
                        booksTitle[InputStudentsData.inputBookTitle[-1]]; 
                        InputStudentsData.bookBorrowingDuration[-1];
                        cout << "" << endl;

                        // Tampilkan data yang kosong 
                        cout << "Nama : " << InputStudentsData.inputStudentName[j] << " Sudah dihapus " << endl;
                        cout << "Nim : " << InputStudentsData.inputStudentNumber[j] << " Sudah dihapus " << endl;
                        cout << "Alamat : " << InputStudentsData.inputStudentAdress[j] << " Sudah dihapus " << endl;
                        cout << "Judul buku : " << booksTitle[InputStudentsData.inputBookTitle[j]] << " Sudah dihapus " << endl;
                        cout << "Durasi peminjalam : " << InputStudentsData.bookBorrowingDuration[j] << " Hari " << " Sudah dihapus " << endl;
                        cout << "" << endl;
                        break;
                    }
                    // Jika antran pertama selesai berlanjut ke antrean berikutnya
                    goto CompleteInput;
                }
            }
        }
               
    }
}

int main()
{
    // Deklarasi variable
    // struct InputStudentsData InputData;

    // struct InputStudentsData* InputDataStudents = &InputData;

    // Jalankan function untuk menampilkan pilihan pengguna
    if (StudentOptions() == true)
    {
        // Jalankan function untuk menampilkan input data
        InputDataStudent();
    }
    return 0;
}