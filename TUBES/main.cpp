#include <iostream>
#include "TUBES.h""

using namespace std;

int main()
{
    ListMahasiswa LM;
    ListMataKuliah LMK;
    infotypeM xM;
    infotypeMK xMK;
    adrMK pMK;
    adrM pM;
    int pilihan, k, Jumdata;
    string namaMK, NIM;
    char subMenu;

    CreateListChild(LM);
    CreateListParent(LMK);

    pilihan = Select_Menu();
    while (pilihan!=0){
        switch(pilihan){
        case 1:
            cout<<"Berapa Mata Kuliah yang akan Ditambahkan : ";
            cin>>Jumdata;
            for(k=1;k<=Jumdata;k++){
                cout<<"Masukkan Nama Mata Kuliah : ";
                cin>>xMK.namaMK;
                cout<<"Masukkan Dosen Mata Kuliah : ";
                cin>>xMK.Dosen;
                cout<<"Masukkan Kode Dosen Mata Kuliah : ";
                cin>>xMK.KodeDOSEN;
                pMK = createParent(xMK);
                insertDataParent(LMK, pMK);
            }
            break;
        case 2:
            cout<<"Berapa Mahasiswa yang akan Ditambahkan : ";
            cin>>Jumdata;
            for(k=1;k<=Jumdata;k++){
                cout<<"Masukkan Nama Mahasiswa : ";
                cin>>xM.nama;
                cout<<"Masukkan NIM Mahasiswa : ";
                cin>>xM.nim;
                cout<<"Masukkan Kelas Mahasiswa : ";
                cin>>xM.kelas;
                cout<<"Masukkan Kode Dosen Mata Kuliah yang diambil Mahasiswa : ";
                cin>>xM.KodeDosen;
                cout<<"Masukkan Nilai Mahasiswa : ";
                cin>>xM.nilai;
                pM = createChild(xM);
                cout<<"Mata Kuliah yang Diambil : ";
                cin>>namaMK;
                addChild(LMK, namaMK, LM, pM);
            }
            break;
        case 3:
            cout<<"Masukkan Nama Mata Kuliah yang ingin dihapus : ";
            cin>>namaMK;
            DeleteParentsAndChild(LMK, namaMK, pMK);
            break;
        case 4:
            showAllDataParent(LMK);
            break;
        case 5:
            showAllData(LMK);
            break;
        case 6:
            cout<<"Masukkan Nama Mata Kuliah : ";
            cin>>namaMK;
            pMK = findParent(LMK, namaMK);
            cout<<infoMK(pMK).namaMK<<" "<<infoMK(pMK).Dosen<<" ("<<infoMK(pMK).KodeDOSEN<<")"<<endl;
            break;
        case 7:
            cout<<"Masukkan NIM Mahasiswa : ";
            cin>>NIM;
            cout<<"Masukkan Nama Mata Kuliah Mahasiswa : ";
            cin>>namaMK;
            pM = findChild(LMK, namaMK, NIM);
            cout<<infoM(pM).nilai<<" "<<infoM(pM).nama<<" "<<infoM(pM).nim<<" "<<infoM(pM).kelas<<endl;
            break;
        case 8:
            cout<<"Masukkan Nama Mata Kuliah : ";
            cin>>namaMK;
            cout<<"Jumlah mahasiswa : "<<CountChild(LMK, namaMK)<<endl;
            break;
        case 9:
            cout<<"Masukkan NIM Mahasiswa : ";
            cin>>NIM;
            cout<<"Masukkan Nama Mata Kuliah : ";
            cin>>namaMK;
            deleteChild(LMK, namaMK, LM, NIM, pM);
            break;
        }
        cout<<"Kembali ke menu utama?(Y/N)";
        cin>>subMenu;
        if(subMenu=='Y'){
            pilihan = Select_Menu();
        }else{
            pilihan = 0;
        }
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
