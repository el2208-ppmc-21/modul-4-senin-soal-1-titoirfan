#include <stdio.h>
#include <stdlib.h>

char Con, ganti;
char *BN,*BNmutasi;
int jumlah,i, urut,jumlahcek, bagi, modu,sum, mutasiTA;

int cekKodonStart (char *BN);
int cekKodonStop(int jum, char *BN);

typedef struct dataAsMin {
char BN1, BN2, BN3, kodon;
} dataAsMin;

dataAsMin *libAsMin;
int k, jumlahlib, jmlh;

void cekKodonData (dataAsMin *libAsMin, char *BN, int jumlib, int jum);

int main(){

    libAsMin = (dataAsMin*)calloc(0, sizeof(dataAsMin));
do{
   jmlh ++;
   libAsMin = realloc(libAsMin,jmlh * sizeof(dataAsMin));
   printf("Masukkan 3 basa nitrogen : ");
   scanf(" %c",&libAsMin[jmlh-1].BN1);
   scanf(" %c",&libAsMin[jmlh-1].BN2);
   scanf(" %c",&libAsMin[jmlh-1].BN3);
   printf("Masukkan singkatan asam amino : ");
   scanf(" %c",&libAsMin[jmlh-1].kodon);
   printf("Apakah ingin lanjut? (Y/N) : ");
   scanf(" %c", &Con);
} while (Con != 'N');

    Con = 'Y';
    BN = (char*)calloc(0, sizeof(char));

do{
    jumlah += 3;
    BN = (char*)realloc(BN, jumlah);
    printf("Masukkan 3 basa nitrogen untuk dicek : ");
    for(i=(jumlah-3) ; i < (jumlah) ; i++){
        scanf(" %c",&BN[i]);
        //printf("ini %c\n",BN[i]);
    }
    printf("Masukkan basa nitrogen lagi? (Y/N) : ");
    scanf(" %c", &Con);
} while (Con != 'N');

    printf("Urutan basa input : ");
    for(i=0;i<jumlah;i++){
        printf("%c",BN[i]);
    }
    if ((cekKodonStart(BN)==1)&&(cekKodonStop(jumlah,BN)==1)){
    //dimulai dari 1
    printf("\nUrutan yang ingin diganti ? ");
    scanf (" %d", &urut);
    printf("Basa nitrogen pengganti ? ");
    scanf (" %c", &ganti);

    BNmutasi = (char*)calloc(jumlah, sizeof(char));
    for (int m=0; m<jumlah;m++){
        if (m != urut-1){
            BNmutasi[m] = BN[m];
        } else {
            BNmutasi[m] = ganti;
        }
    }

    printf("Urutan basa output : ");
    for(i=0;i<jumlah;i++){
        printf("%c",BNmutasi[i]);
    }

    if((cekKodonStart(BNmutasi) == 1)&&(cekKodonStop(jumlah, BNmutasi))){
    //untuk ngecek urutan kodon mutasi
    modu = urut%3;
    bagi = urut/3;
    if(modu != 0){
        sum = (bagi + 1)*3;
    } else {
        sum = bagi*3;
    }

    if(sum != jumlah){
    if ((cekKodonStop(sum, BNmutasi))==1){
        printf("\nTerjadi mutasi tanpa arti");
    } else {
        printf("\nTidak terjadi mutasi tanpa arti");
    }
        cekKodonData(libAsMin,BNmutasi,jmlh,jumlah);
    }else {
        printf("\nTidak terjadi mutasi tanpa arti");
        cekKodonData(libAsMin,BNmutasi,jmlh,jumlah);
    }

    } else {
    printf ("\nMutasi harus dimulai dengan kodon start dan diakhiri dengan kodon stop!");
    }
    } else {
    printf ("\nHarus dimulai dengan kodon start dan diakhiri dengan kodon stop!");
    }
}

int cekKodonStart (char *BN){
    if (BN[0] == 'A'){
        if (BN[1] == 'U'){
            if (BN[2] == 'G'){
                return (1);
            }
        }
    } else {
        return (0);
    }
}

int cekKodonStop (int jum, char *BN){
    if (BN[jum-3]== 'U'){
        if (BN[jum-2]=='A'){
            if ((BN[jum-1] == 'A')||(BN[jum-1] == 'G')){
                return (1);
            } else {
                return (0);
            }
        } else if (BN[jum-2]=='G'){
            if (BN[jum-1]=='A'){
                return (1);
            } else {
                return (0);
            }
        }
    } else {
        return (0);
    }
}

void cekKodonData (dataAsMin *libAsMin, char *BNmutasi, int jumlib, int jum){
    int itung = 0;
    for (int j = 0; j<jumlib; j++){
        for(int k=1; k<jum; k+=3){
         if (libAsMin[j].BN1 == BNmutasi[k-1]){
            if(libAsMin[j].BN2 == BNmutasi[k]){
                if(libAsMin[j].BN3 == BNmutasi[k+1]){
                    itung += 1;
                }
            }
         }
        }
    printf ("\nAsMin %c pada untaian ada %d",libAsMin[j].kodon, itung);
    itung = 0;
    }
}
