#include "TUBES.h"

void CreateListParent(ListMataKuliah &LMK){

    firstMK(LMK) = NULL;
};

void CreateListChild(ListMahasiswa &LM){

    firstM(LM) = NULL;
};

adrMK createParent(infotypeMK xMK){

    adrMK pMK;

    pMK = new  ElmMK;
    infoMK(pMK) = xMK;
    nextMK(pMK) = NULL;
    Mhs(pMK) = NULL;

    return pMK;

};

adrM createChild(infotypeM xM){

    adrM pM;

    pM = new ElmMahasiswa;
    infoM(pM) = xM;
    nextM(pM) = NULL;

    return pM;

};

void insertDataParent(ListMataKuliah &LMK, adrMK pMK){

    if(firstMK(LMK)==NULL){
        firstMK(LMK) = pMK;
        nextMK(pMK) = firstMK(LMK);
    }else{
        adrMK qMK;

        qMK = nextMK(firstMK(LMK));
        while(nextMK(qMK)!=firstMK(LMK)){
            qMK = nextMK(qMK);
        }
        nextMK(qMK) = pMK;
        nextMK(pMK) = firstMK(LMK);
    }
};

void showAllDataParent(ListMataKuliah LMK){

    adrMK pMK;

    pMK = firstMK(LMK);
    cout<<infoMK(pMK).namaMK<<" "<<infoMK(pMK).Dosen<<" ("<<infoMK(pMK).KodeDOSEN<<")"<<endl;
    pMK = nextMK(pMK);
    while(pMK!=firstMK(LMK)){
        cout<<infoMK(pMK).namaMK<<" "<<infoMK(pMK).Dosen<<" ("<<infoMK(pMK).KodeDOSEN<<")"<<endl;
        pMK = nextMK(pMK);
    }
};

adrMK findParent(ListMataKuliah LMK, string namaMK){

    adrMK pMK;

    pMK = firstMK(LMK);
    while(pMK!=NULL){
        if(infoMK(pMK).namaMK == namaMK){
            return pMK;
            break;
        }
        pMK = nextMK(pMK);
    }if(pMK == NULL){
        return pMK;
        cout<<"Mata Kuliah Tidak Ditemukan"<<endl;
    }
};

void DeleteParentsAndChild(ListMataKuliah &LMK, string namaMK, adrMK &pMK){

    adrMK qMK;

    qMK = findParent(LMK, namaMK);

    if(firstMK(LMK)==NULL){
        cout<<"List Mata Kuliah Kosong"<<endl;
    }else if(qMK==firstMK(LMK)){
        firstMK(LMK) = nextMK(qMK);
        nextMK(qMK) = NULL;
    }else{
        //qMK = findParent(LMK, namaMK);
        pMK = firstMK(LMK);
        while(nextMK(pMK)!=qMK){
            pMK = nextMK(pMK);
        }
        if(nextMK(qMK)==firstMK(LMK)){
            nextMK(pMK) = firstMK(LMK);
            qMK = NULL;
        }else{
            nextMK(pMK) = nextMK(qMK);
            nextMK(qMK) = NULL;
            qMK = NULL;
        }
    }
};

void addChild(ListMataKuliah &LMK, string namaMK ,ListMahasiswa &LM, adrM M){

    adrMK pMK;
    adrM pM, qM;

    pMK = findParent(LMK, namaMK);

    if(Mhs(pMK)==NULL){
        Mhs(pMK) = M;
        if(firstM(LM)==NULL){
            firstM(LM) = M;
        }else{
            pM = firstM(LM);
            while(nextM(pM)!=NULL){
                pM = nextM(pM);
            }
            nextM(pM) = M;
        }
    }else{
        qM = Mhs(pMK);

        /*
        while(nextM(qM)!=NULL){
            qM = nextM(qM);
        }

        if(nextM(qM)==firstM(LM)){
            nextM(qM) = M;
            nextM(M) = firstM(LM);
        }else{
            nextM(M) = nextM(qM);
            nextM(qM) = M;
        }
        */
        nextM(M) = nextM(qM);
        nextM(qM) = M;


    }
};

void showAllData(ListMataKuliah LMK){
    adrMK pMK;
    adrM pM;

    pMK = firstMK(LMK);
    cout<<infoMK(pMK).namaMK<<" "<<infoMK(pMK).Dosen<<" ("<<infoMK(pMK).KodeDOSEN<<")"<<endl;
    if(Mhs(pMK)!=NULL){
        pM = Mhs(pMK);
        cout<<"======Mahasiswa======"<<endl;
        while(pM!=NULL){
            if(infoM(pM).KodeDosen == infoMK(pMK).KodeDOSEN){
                cout<<infoM(pM).nilai<<" "<<infoM(pM).nama<<" "<<infoM(pM).nim<<" "<<infoM(pM).kelas<<endl;
            }
            pM = nextM(pM);
        }
    }
    pMK = nextMK(pMK);
    while(pMK!=firstMK(LMK)){
        cout<<infoMK(pMK).namaMK<<" "<<infoMK(pMK).Dosen<<" "<<infoMK(pMK).KodeDOSEN<<endl;
        if(Mhs(pMK)!=NULL){
            pM = Mhs(pMK);
            cout<<"======Mahasiswa======"<<endl;
            while(pM!=NULL){
                    if(infoM(pM).KodeDosen == infoMK(pMK).KodeDOSEN){
                        cout<<infoM(pM).nilai<<" "<<infoM(pM).nama<<" "<<infoM(pM).nim<<" "<<infoM(pM).kelas<<endl;
                    }
                pM = nextM(pM);
            }
        }
        pMK = nextMK(pMK);
    }
};

adrM findChild(ListMataKuliah LMK, string namaMK, string nim){

    adrM M;
    adrMK pMK;

    pMK = findParent(LMK, namaMK);
    M = Mhs(pMK);
    while(M!=NULL){
        if(infoM(M).nim == nim && infoMK(pMK).KodeDOSEN == infoM(M).KodeDosen){
            return M;
            break;
        }
        M = nextM(M);
    }
    if(M==NULL){
        return M;
    }
};

void deleteChild(ListMataKuliah &LMK, string namaMK, ListMahasiswa &LM, string nim, adrM &M){

    adrMK pMK;
    adrM pM;

    pMK = findParent(LMK, namaMK);
    M = findChild(LMK, namaMK, nim);

    pM = Mhs(pMK);
    if(pM==M){
        if(nextM(M)==NULL){
            Mhs(pMK) = NULL;
        }else{
            Mhs(pMK) = nextM(Mhs(pMK));
        }
    }
    else{
        while(pM!=NULL){
            if(infoM(nextM(pM)).KodeDosen == infoM(M).KodeDosen){
                if(nextM(M)==NULL){
                    nextM(pM) = NULL;
                    break;
                }else{
                    Mhs(pMK) = pM;
                    break;
                }
            }
            pM = nextM(pM);
        }
    }
};

int CountChild(ListMataKuliah LMK, string namaMK){

    adrMK pMK;
    adrM pM;
    int i = 0;

    pMK = findParent(LMK, namaMK);
    if(Mhs(pMK)!=NULL){
        pM = Mhs(pMK);
        while(pM!=NULL){
            if(infoM(pM).KodeDosen == infoMK(pMK).KodeDOSEN){
                i++;
            }
            pM = nextM(pM);
        }
    }
    return i;
};

int Select_Menu(){

    int pilihan;

    cout<<"=====MENU====="<<endl;
    cout<<"1. Menambah N Mata Kuliah"<<endl;
    cout<<"2. Menambah N Mahasiswa dan Menghubungkan ke Mata Kuliah"<<endl;
    cout<<"3. Menghapus Mata Kuliah dan Mahasiswa"<<endl;
    cout<<"4. Menampilkan Semua Mata Kuliah"<<endl;
    cout<<"5. Menampilkan Semua Mata Kuliah dan Mahasiswa"<<endl;
    cout<<"6. Mencari Mata Kuliah N"<<endl;
    cout<<"7. Mencari Mahasiswa N"<<endl;
    cout<<"8. Menghitung Jumlah Mahasiswa yang Mengambil Mata Kuliah N"<<endl;
    cout<<"9. Hapus Mahasiswa N pada Mata Kuliah M"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilihan;
    return pilihan;
}





