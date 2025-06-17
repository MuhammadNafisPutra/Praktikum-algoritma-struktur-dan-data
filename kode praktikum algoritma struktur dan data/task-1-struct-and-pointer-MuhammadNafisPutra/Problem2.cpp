    #include<iostream>

    using namespace std;

    struct kendaraan {
        char plat [10]  = "DA1234MK";
        char jenis_kendaraan[10] = "RUSH";
        char nama_pemilik[20] = "Andika Hartanto";
        char alamat[20] = "Jl. Kayu Tangi 1";
        char kota[15] = "Banjarmasin";
        
    };

    int main(){
        kendaraan mobil;

        cout << "\n----------------------------------------\n";
        cout << "Plat Nomor Kendaraan        = "<< mobil.plat << endl;
        cout << "Jenis Kendaraa              = " << mobil.jenis_kendaraan << endl;
        cout << "Nama Pemilik                = " << mobil.nama_pemilik << endl;
        cout << "Alamat                      = " << mobil.alamat << endl;
        cout << "Kota                        = " << mobil.kota << endl;

        

        return 0;
    }