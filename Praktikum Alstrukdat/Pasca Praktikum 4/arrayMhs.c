/* Kamus Umum */
/* 
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek 
typedef int IdxType;
typedef struct {
    char *nama;
    char *nim;
    float nilai;
} ElType;

typedef struct {
    ElType TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
    /*int Neff; banyaknya elemen efektif } TabMhs;*/


/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabMhs, cara deklarasi dan akses: */
/* Deklarasi : T : TabMhs */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

#include "arrayMhs.h"
#include <stdio.h>
/* ********** KONSTRUKTOR ARRAY ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabMhs *T){
    (*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMhs T){
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Daya tampung container *** */
int MaxNbEl (TabMhs T){
    return IdxMax - IdxMin + 1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

IdxType GetFirstIdx (TabMhs T){
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

IdxType GetLastIdx (TabMhs T){
    return T.Neff;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

ElType GetElmt (TabMhs T, IdxType i){
    return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */


/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMhs Tin, TabMhs *Tout){
    (*Tout).Neff = Tin.Neff;
    for(int i = IdxMin; i <= Tin.Neff; i++){
        (*Tout).TI[i] = Tin.TI[i]; }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

void SetEl (TabMhs *T, IdxType i, ElType v){
    (*T).TI[i] = v;
    if ((*T).Neff < i){
    (*T).Neff = i;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

void SetNeff (TabMhs *T, IdxType N){
    (*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMhs T, IdxType i){
    if ((i >= IdxMin) && (i <= IdxMax)){
        return true;
    } else {
        return false;
    }
}
     
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

boolean IsIdxEff (TabMhs T, IdxType i){
    if ((i >= IdxMin) && (i <= T.Neff)){
        return true;
    } else {
        return false;
    }
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMhs T){
    if (T.Neff > 0){
        return false;
    } else {
        return true;
    }
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Test tabel penuh *** */
boolean IsFull (TabMhs T){
    if (T.Neff == IdxMax){
        return true;
    } else {
        return false;
    }

}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMhs T){
    IdxType i;
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    }
    else {
        for (i = GetFirstIdx(T) ; i <= NbElmt(T) ; i++){
            printf("%s | %s | %.2f\n", T.TI[i].nama , T.TI[i].nim , T.TI[i].nilai);
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh print tabel
Test | 12321123 | 3.61
Ini Juga Test | 12321124 | 3.21
Test Lagi | 12321125 | 3.11
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** KONSTRUKTOR MAHASISWA ********** */
ElType MakeMahasiswa (char* Nama, char* NIM, float Nilai){
    ElType M;
    M.nama = Nama;
    M.nim = NIM;
    M.nilai = Nilai;
    return M;
}
/* Membentuk sebuah Mahasiswa dari komponen-komponennya */
/* I.S. Nama, NIM, Nilai terdefinisi */
/* F.S. Mahasiswa M terbentuk dengan Nama, NIM, Nilai yang sesuai */

/* ********** OPERATOR STATISTIK MAHASISWA ********** */
float RataRata (TabMhs T){
    IdxType i;
    float sum = 0;
    int n = 0;
    for(i = GetFirstIdx(T) ; i <= NbElmt(T) ; i++){
        sum += T.TI[i].nilai;
        n ++;
    }
    float avg = sum / n;
    return avg;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai rata-rata dari elemen tabel */
float Max (TabMhs T){
    float Max;
    Max = T.TI[GetFirstIdx(T)].nilai;
    IdxType i;
    for (i = GetFirstIdx(T) ; i <= NbElmt(T) ; i++){
        if (T.TI[i].nilai > Max){
            Max = T.TI[i].nilai;
        }
    }
    return Max;

}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai maksimum dari elemen tabel */
float Min (TabMhs T){
    float Min;
    Min = Max(T);
    IdxType i;
    for (i = GetFirstIdx(T) ; i <= NbElmt(T) ; i++){
        if (T.TI[i].nilai < Min){
            Min = T.TI[i].nilai;
        }
    }
    return Min;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai minimum dari elemen tabel */
char *MaxNama (TabMhs T){
    boolean found = false;
	int idx = 1;
	float max;
	max = Max(T);
	while ((!found) && (idx <= NbElmt(T)))
	{
			if (T.TI[idx].nilai == max)
			{
				found = true;
			}
			
			else 
			{
				idx++;
			}	
	}
	return T.TI[idx].nama;
}

/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai tertinggi */
/* Jika ada lebih dari satu mahasiswa dengan nilai tertinggi, maka yang diambil yang nim lebih rendah */
char *MinNama (TabMhs T){
    boolean found = false;
	int idx = 1;
	float min;
	min = Min(T);
	while ((!found) && (idx <= NbElmt(T)))
	{
			if (T.TI[idx].nilai == min)
			{
				found = true;
			}
			
			else 
			{
				idx++;
			}	
	}
	return T.TI[idx].nama;
}

/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai terendah */
/* Jika ada lebih dari satu mahasiswa dengan nilai terendah, maka yang diambil yang nim lebih rendah */
int JumlahJurusan (TabMhs T, char* Jurusan){
    int jumlahjurusan = 0;
    IdxType i , j = 0;
    boolean found ;
    for (i = GetFirstIdx(T) ; i <= NbElmt(T) ; i++){
        found = true;
        for(j=0 ; j<3 ; j++){
            if (T.TI[i].nim[j] != *(Jurusan+j)){
                found = false;
            }
        }
        if (found){
            jumlahjurusan += 1;
        }
    }
    return jumlahjurusan ;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan jumlah mahasiswa yang berasal dari jurusan Jurusan, yang berbentuk 3 angka (contoh: 182) */
/* Jika tidak ada mahasiswa yang berasal dari jurusan Jurusan, maka menghasilkan 0 */




