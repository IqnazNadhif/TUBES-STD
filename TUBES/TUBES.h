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
    string nama, nim, kelas;
};
struct MataKuliah{
    string namaMK, Dosen;
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

void createParent(infotypeM x);
void createChild(infotypeMK x);
void insertDataParent(ListMataKuliah &LMK, adrMK MK);
void showAllDataParent(ListMataKuliah LMK);
void DeleteParentsAndChild(ListMataKuliah &LMK, adrMK &MK);
adrMK findParent(ListMataKuliah &LMK, string namaMK);
void addChild(ListMataKuliah &LMK,ListMahasiswa &LM, adrM M);
void showAllData(ListMataKuliah LMK);
adrM findChild(ListMataKuliah LMK, string namaMK, string nim);
void deleteChild(ListMataKuliah LMK, string namaMK, ListMahasiswa &LM);
void CountChild(ListMataKuliah LMK, string namaMK);


#endif // TUBES_H_INCLUDED
