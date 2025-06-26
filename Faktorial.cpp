#include <iostream>
#include <chrono> // Untuk delay
#include <thread> // Untuk sleep_for
using namespace std;

void menuFaktorial();
void menuDeretMatematika();
void showMenu();

// Fungsi rekursif untuk menghitung dan mencetak faktorial
unsigned long long faktorialRekursif(int n) {
    if (n == 0 || n == 1) { // Base case: 0! = 1! = 1
        cout << "1"; // Cetak angka terakhir
        return 1;
    }
    else {
        unsigned long long hasil = n * faktorialRekursif(n - 1); // Recursive case
        cout << " x " << n; // Cetak angka saat ini
        return hasil;
    }
}

// Fungsi rekursif untuk menghitung dan mencetak deret matematika
int deretRekursif(int n, int i = 1) {
    if (i > n) { // Base case: Jika sudah melewati n
        return 0;
    }
    else {
        if (i < n) {
            cout << i << " + "; // Cetak angka saat ini dengan "+"
        }
        else {
            cout << i; // Cetak angka terakhir tanpa "+"
        }
        return i + deretRekursif(n, i + 1); // Recursive case
    }
}

// Implementasi fungsi showMenu
void showMenu() {
    int pilihan = 0;
    while (true) {
        // Clear console
        system("CLS");
        // UI console
        cout << "===============================================" << endl;
        cout << "==  Kalkulator Faktorial & Deret Matematika  ==" << endl;
        cout << "===============================================" << endl << endl;
        cout << "1. Kalkulator Faktorial" << endl;
        cout << "2. Kalkulator Deret Matematika" << endl;
        cout << "3. Keluar" << endl << endl;
        cout << "Input : ";
        cin >> pilihan;
        if (pilihan == 1) {
            // Pilihan untuk menghitung faktorial
            menuFaktorial();
        }
        else if (pilihan == 2) {
            // Pilihan untuk menghitung deret matematika
            menuDeretMatematika();
        }
        else if (pilihan == 3) {
            // Pilihan untuk keluar dari aplikasi
            cout << "See you next time!" << endl;
            break; // Keluar dari program
        }
        else {
            // Handle input yang tidak valid
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            this_thread::sleep_for(chrono::seconds(2)); // Delay 2 detik
        }
    }
}

// Fungsi untuk menampilkan menu faktorial
void menuFaktorial() {
    // Clear console
    system("CLS");
    int n;
    cout << "==============================================" << endl;
    cout << "==  Selamat datang di Kalkulator Faktorial  ==" << endl;
    cout << "==============================================" << endl << endl;
    cout << "Masukkan Angka (HARUS POSITIF) : ";
    cin >> n;
    if (n < 0) {
        cout << "Error, Angka Harus Positif!" << endl;
    }
    else {
        cout << n << "! = "; // Menampilkan soal sebelum hasilnya
        unsigned long long hasil = faktorialRekursif(n); // Menggunakan fungsi rekursif
        cout << " = " << hasil << endl; // Menampilkan hasil faktorial
    }
    // Tunggu sebelum kembali ke menu utama
    cout << endl << "Tekan Enter untuk melanjutkan...";
    cin.ignore(); // Agar bisa berhenti sebelum user klik enter
    cin.get();    // Untuk Enter
}

// Fungsi untuk menampilkan menu deret matematika
void menuDeretMatematika() {
    // Clear console
    system("CLS");
    int n;
    cout << "=====================================================" << endl;
    cout << "==  Selamat datang di Kalkulator Deret Matematika  ==" << endl;
    cout << "=====================================================" << endl << endl;
    cout << "Masukkan Angka (HARUS POSITIF) : ";
    cin >> n;
    if (n < 0) {
        cout << "Error, Angka Harus Positif!" << endl;
    }
    else {
        cout << n << "+ = "; // Menampilkan n dan + = sebelum hasil akhir
        int jumlah = deretRekursif(n); // Menggunakan fungsi rekursif
        cout << " = " << jumlah << endl; // Menampilkan hasil akhir
    }
    // Tunggu sebelum kembali ke menu utama
    cout << endl << "Tekan Enter untuk melanjutkan...";
    cin.ignore(); // Agar bisa berhenti sebelum user klik enter
    cin.get();    // Untuk Enter
}

// Fungsi utama
int main() {
    // Tampilkan UI Menu
    showMenu();
    return 0;
}