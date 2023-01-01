#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;

#define infoM(p) p->infoM
#define nextM(p) p->nextM
#define firstM(M) (M.firstM)
#define infoMK(d) d->infoMK
#define nextMK(d) d->nextMK
#define Mhs(d) d->Mhs
#define firstMK(MK) (MK.firstMK)

struct mahasiswa{
    int nilai;
    string nama, nim, kelas, KodeDosen;
};
struct MataKuliah{
    string namaMK, Dosen, KodeDOSEN;
};

typedef mahasiswa infotypeM;
typedef struct ElmMahasiswa *adrM;
typedef MataKuliah infotypeMK;
typedef struct ElmMK *adrMK;

struct ElmMahasiswa{
    infotypeM infoM;
    adrM nextM;
};

struct ElmMK{
    infotypeMK infoMK;
    adrM Mhs;
    adrMK nextMK;
};

struct ListMahasiswa{
    adrM firstM;
};

struct ListMataKuliah{
    adrMK firstMK;
};

adrMK createParent(infotypeMK xMK);
adrM createChild(infotypeM xM);
void CreateListParent(ListMataKuliah &LMK);
void CreateListChild(ListMahasiswa &LM);
void insertDataParent(ListMataKuliah &LMK, adrMK pMK);
void showAllDataParent(ListMataKuliah LMK);
void DeleteParentsAndChild(ListMataKuliah &LMK, string namaMK, adrMK &pMK);
adrMK findParent(ListMataKuliah LMK, string namaMK);
void addChild(ListMataKuliah &LMK, string namaMK, ListMahasiswa &LM, adrM M);
void showAllData(ListMataKuliah LMK);
adrM findChild(ListMataKuliah LMK, string namaMK, string nim);
void deleteChild(ListMataKuliah &LMK, string namaMK, ListMahasiswa &LM, string nim, adrM &M);
int CountChild(ListMataKuliah LMK, string namaMK);
int Select_Menu();

#endif // TUBES_H_INCLUDED
