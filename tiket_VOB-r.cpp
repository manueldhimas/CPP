#include <iostream>
#include <string>

using namespace std;

//Mendeklarasikan variabel global HARGA_TIKET dan DISKON_PELAJAR yang digunakan untuk menyimpan harga tiket dan persentase diskon untuk pelajar.
int HARGA_TIKET[4] = {500000, 1000000, 1500000, 2000000};
double DISKON_PELAJAR = 0.2;

//Digunakan untuk menampilkan pilihan kategori tiket kepada pengguna.
void kategoriTiket()
{
    cout << "Silakan pilih kategori tiket:\n";
    cout << "1. Reguler \tRp.500.000\n";
    cout << "2. Festival \tRp.1.000.000\n";
    cout << "3. VIP \t\tRp.1.500.000\n";
    cout << "4. VVIP \tRp.2.000.000\n";
    cout << "Masukkan pilihan Anda (0 untuk selesai): ";
}

// Digunakan untuk menghitung total biaya berdasarkan pilihan kategori tiket dan jumlah tiket yang dimasukkan oleh pengguna.
int totalHarga(int pilihan, int jumlahTiket)
{
    int hargaTiket = HARGA_TIKET[pilihan - 1];
    return jumlahTiket * hargaTiket;
}

//Digunakan untuk menampilkan pilihan metode pembayaran kepada pengguna.
void metodeBayar()
{
    cout << "\nSilakan pilih metode pembayaran:\n";
    cout << "1. Kartu Kredit\n";
    cout << "2. Kartu Debit\n";
    cout << "3. E-Wallet\n";
    cout << "Masukkan pilihan Anda (0 untuk keluar): ";
}

//Titik masuk utama program. Pengguna diminta untuk memasukkan data pribadi, memilih kategori tiket, dan jumlah tiket yang ingin dibeli.
int main()
{
    int totalBiaya = 0;
    string nama,email,nomor_telp,metodePembayaran;
    bool pelajar = false;
    
    cout << "Tiket Konser Voice of Baceprot!\n\n";
    cout << "Masukan data anda"<<endl;
    cout << "Nama : ";getline(cin,nama);cout;
    cout << "Nomor Telepon : ";getline(cin,nomor_telp);cout;
    cout << "Email : ";getline(cin,email);cout<<endl;

    while (true)
    {
        kategoriTiket();
        int pilihan;
        cin >> pilihan;

        if (pilihan == 0)
        {
            if (totalBiaya == 0)
            {
                cout << "Tidak ada kategori tiket yang dipilih. Program berakhir.\n";
                return 0;
            }
            else
            {
                break;
            }
        }

        if (pilihan < 1 || pilihan > 4)
        {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            continue;
        }

        int jumlahTiket;

        cout << "Anda memilih kategori tiket " << pilihan << ".\n";
        cout << "Masukkan jumlah tiket yang ingin dibeli: ";
        cin >> jumlahTiket;

        if (jumlahTiket <= 0)
        {
            cout << "Jumlah tiket tidak valid. Silakan coba lagi.\n";
            continue;
        }

        totalBiaya += totalHarga(pilihan, jumlahTiket);

        cout << "Kategori tiket: " << pilihan << "\n";
        cout << "Jumlah tiket: " << jumlahTiket << "\n";
        cout << "Total biaya untuk kategori ini: " << totalBiaya << "\n\n";
    }
    
    //Pengguna memilih apakah mereka seorang pelajar atau bukan. Jika pengguna adalah seorang pelajar, total biaya akan dikenai diskon sebesar DISKON_PELAJAR. 
    while (true)
    {
        cout << "Apakah Anda seorang pelajar? (y/n, 0 untuk keluar): ";
        char pilihanPelajar;
        cin >> pilihanPelajar;

        if (pilihanPelajar == 'y' || pilihanPelajar == 'Y')
        {
            pelajar = true;
            break;
        }
        else if (pilihanPelajar == 'n' || pilihanPelajar == 'N')
        {
            pelajar = false;
            break;
        }
        else if (pilihanPelajar == '0')
        {
            cout << "Program berakhir. Tidak ada diskon pelajar yang diterapkan.\n";
            return 0;
        }
        else
        {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }

    if (pelajar)
    {
        totalBiaya -= totalBiaya * DISKON_PELAJAR / 100;
    }

    cout << "\nTotal biaya: " << totalBiaya << "\n";
    
    //Pengguna diminta untuk memilih metode pembayaran.
    while (true)
    {
        metodeBayar();
        int pilihan;
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            metodePembayaran = "Kartu Kredit";
            break;
        case 2:
            metodePembayaran = "Kartu Debit";
            break;
        case 3:
            metodePembayaran = "E-Wallet";
            break;
        case 0:
            cout << "Program berakhir. Tidak ada metode pembayaran yang dipilih.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            continue;
        }
        break;
    }
    
    //Program akan mencetak struk pembayaran yang berisi informasi seperti nama, nomor telepon, email, total biaya, dan metode pembayaran yang dipilih.
	cout << "-------------------------------------------------\n";
	cout << "		Struk Pembayaran		\n";
	cout << "-------------------------------------------------\n";
	cout << "Nama :" <<nama<<"					\n";
	cout << "Nomor Telepon \t\t:" <<nomor_telp<<"				\n";
	cout << "Nomor Email \t\t:" <<email<<"				\n";
    cout << "Total biaya \t\t: " << totalBiaya << "        			\n";
    cout << "Metode pembayaran \t: " << metodePembayaran << "		\n";
    cout << "-------Terima kasih atas pembelian Anda :D-------\n\n";

    return 0;
}
