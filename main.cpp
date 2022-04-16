#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

// Mochammad Vaif Dwi Alifkhan
// 202102011014
// Sarjana Teknik Informatika
// Mata Kuliah Praktika Struktur Data Pemrograman C++


struct datapembaca {
	string nama_pembaca;
	string umur_pembaca;
	string gender_pembaca;
	string status_pembaca;
	string regristrasi;
};

datapembaca data;


void CreateData ()
{
    fstream xdata;
    xdata.open("data.txt", ios::app);

    xdata << data.nama_pembaca   << endl;
    xdata << data.umur_pembaca   << endl;
    xdata << data.gender_pembaca << endl;
    xdata << data.status_pembaca << endl;
    xdata << data.regristrasi    << endl << endl;

    xdata.close ();
}

void ReadData ()
{
    ifstream ydata;
    ydata.open("data.txt");


    while (!ydata.eof ())
    {
        string tampildata;

        getline(ydata,tampildata);
        if(tampildata ==""){
            getline(ydata,tampildata);
            if(tampildata ==""){
            break;
        }
        }
        cout << "=========================================" << endl;
        cout << "Nama Pembaca      :"  << tampildata << endl;
        getline(ydata,tampildata);
        cout << "Umur Pembaca      :"  << tampildata << endl;
        getline(ydata,tampildata);
        cout << "Jenis Kelamin     :"  << tampildata << endl;
        getline(ydata,tampildata);
        cout << "Status Pembaca    :"  << tampildata << endl;
        getline(ydata,tampildata);
        cout << "Regristrasi Pada  :"  << tampildata << endl;
        getline(ydata,tampildata);

        cout << "=========================================" << endl;


    }

    ydata.close ();
}

struct lapbaca {
	string  surah;
	string  juz;
	string  jumlah_hal;
	string  nomor_hal;
	string  waktu_baca;
	string  tanggal_baca;
};

lapbaca form;

void CreateLaporan ()
{
    fstream aform;
    aform.open("laporan.txt", ios::app);

    aform << form.surah        << endl;
    aform << form.juz          << endl;
    aform << form.jumlah_hal   << endl;
    aform << form.nomor_hal    << endl;
    aform << form.waktu_baca   << endl;
    aform << form.tanggal_baca << endl << endl;

    aform.close ();
}

void ReadLaporan ()
{
    ifstream bform;
    bform.open("laporan.txt");


    while (!bform.eof ())
    {
        string tampildata;

        getline(bform,tampildata);
        if(tampildata ==""){
            getline(bform,tampildata);
            if(tampildata ==""){
            break;
        }
        }
        cout << "=========================================" << endl;

        cout << "Surah yang Dibaca    :" << tampildata << endl;
        getline(bform,tampildata);
        cout << "Juz ke               :" << tampildata << endl;
        getline(bform,tampildata);
        cout << "Jumlah Halaman Baca  :" << tampildata << endl;
        getline(bform,tampildata);
        cout << "Nomor Halaman        :" << tampildata << endl;
        getline(bform,tampildata);
        cout << "Waktu Membaca        :" << tampildata << endl;
        getline(bform,tampildata);
        cout << "Tanggal Membaca      :" << tampildata << endl;
        getline(bform,tampildata);

        cout << "=========================================" << endl;

    }

    bform.close ();
}


int main ()
{
    int pilmenu,input_ulang;

	loop:
    menu:
	cout << "BUKU LAPORAN BACA AL-QUR'AN DI BULAN RAMADHAN" << endl;
	cout << "=============================================" << endl;

	cout << "[1]. Input Data Pembaca" << endl;
	cout << "[2]. Lihat Data Pembaca" << endl;
	cout << "[3]. Input Laporan Baca Al-Qur'an" << endl;
	cout << "[4]. Lihat Laporan Baca Al-Qur'an" << endl;

	cout << "=============================================" << endl;

	cout << "Pilih Menu : ";
	cin  >> pilmenu;

    cout << "=============================================" << endl;

	switch (pilmenu)
	{
		case 1	:
		{
		    int input_lagi= 1;

		    while (input_lagi !=0)
            {
                system ("cls");
                cout << "====================== INPUT DATA PEMBACA =======================" << endl;
                cin.ignore(1,'\n');
                cout << "Masukkan Nama Lengkap : ";
                getline(cin, data.nama_pembaca);
                cout << "Masukkan Umur Anda    : ";
                getline(cin, data.umur_pembaca);
                cout << "Jenis Kelamin         : ";
                getline(cin, data.gender_pembaca);
                cout << "Status Anda           : ";
                getline(cin, data.status_pembaca);
                cout << "Tanggal Regristrasi   : ";
                getline(cin, data.regristrasi);

                CreateData();

                cout << "=================================================================" << endl;
                cout << "Apakah Anda ingin input laporan lagi? [0] Tidak || [1] Ya : ";
                cin  >> input_lagi;

            }

            system ("cls");

            goto loop;

			break;
		}


        case 2  :
        {
            system ("cls");
            int kembali = 1;

            while (kembali !=0)
            {
                cout << "=============== DATA PEMBACA ===============" << endl;
                ReadData();

                cout << " [0] Untuk kembali ke menu utama : ";
                cin  >> kembali;

                if (kembali !=0)
                {
                    system ("cls");
                    goto loop;
                }
            }

            system ("cls");
            goto loop;
			break;
        }


        case 3  :
        {
		    int input_lagi= 1;

		    while (input_lagi !=0)
            {
                system ("cls");
                cout << "================ INPUT LAPORAN BACA AL-QUR'AN ================" << endl;
                cin.ignore(1,'\n');
                cout << "Masuk Ke Dalam Surah [Ex: Al-Mulk]             : ";
                getline(cin, form.surah);
                cout << "Masuk Juz Ke Berapa  [Ex: Juz 1-30]            : ";
                getline(cin, form.juz);
                cout << "Jumlah Halaman Yang Dibaca   [Ex: 3 halaman]   : ";
                getline(cin, form.jumlah_hal);
                cout << "Nomor Halaman Yang Dibaca    [Ex: 117-118]     : ";
                getline(cin, form.nomor_hal);
                cout << "Waktu Baca [Shubuh|Dhuhur|Ashar|Maghrib|Isya'] : ";
                getline(cin, form.waktu_baca);
                cout << "Tanggal Membaca      [Ex: 20 Maret 2022]       : ";
                getline(cin, form.tanggal_baca);

                CreateLaporan();

                cout << "=================================================================" << endl;
                cout << "Apakah Anda ingin input laporan lagi? [0] Tidak || [1] Ya : ";
                cin  >> input_lagi;

            }

            system ("cls");

            goto loop;

			break;
		}


        case 4  :
        {
            system ("cls");
            int kembali = 1;

            while (kembali !=0)
            {
                cout << "=============== LAPORAN BACA AL-QUR'AN ===============" << endl;
                ReadLaporan();

                cout << " [0] Untuk kembali ke menu utama : ";
                cin  >> kembali;

                if (kembali !=0)
                {
                    system ("cls");
                    goto loop;
                }
            }

            system ("cls");
            goto loop;
			break;
        }

        default:
            cout << "Maaf menu yang Anda pilih tidak tersedia" << endl;
	}
        cout << "\nApakah Anda ingin input pilihan kembali? [0] Tidak [1] Ya : ";
        cin  >> input_ulang;

        if (input_ulang == 1)
        {
            system ("cls");
            goto menu;
        }
        else if (input_ulang == 0)
        {
            cout << "\nTerima Kasih Telah Menggunakan Program Laporan Baca Al-Qur'an di Bulan Ramadhan" << endl;
            cout << "Semoga Selalu Istiqomah dan Menjadi Amal Kebaikan di Bulan Ramadhan..AAmiin!!!!" << endl;
            return 0;
        }

}
