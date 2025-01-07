#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct {
    char dn[30];
    char fn[10][30];
    int fqty;
} dir[10];
int main() {
    int opt, i, j, dirCnt = 0;
    char file[30], dirName[30];
    while (1) {
        printf("\n\n1. Buat Direktori\t2. Buat File di Direktori\t3. Hapus File");
        printf("\n4. Cari File di Direktori\t5. Tampilkan Direktori dan File\t6. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nMasukkan nama direktori: ");
                scanf("%s", dir[dirCnt].dn);
                dir[dirCnt].fqty = 0;
                dirCnt++;
                printf("Direktori %s berhasil dibuat.\n", dir[dirCnt - 1].dn);
                break;
            case 2:
                printf("\nMasukkan nama direktori tempat menambahkan file: ");
                scanf("%s", dirName);
                for (i = 0; i < dirCnt; i++) {
                    if (strcmp(dirName, dir[i].dn) == 0) {
                        printf("Masukkan nama file yang ingin dibuat: ");
                        scanf("%s", dir[i].fn[dir[i].fqty]);
                        dir[i].fqty++;
                        printf("File %s berhasil dibuat di direktori %s.\n", dir[i].fn[dir[i].fqty - 1], dir[i].dn);
                        break;
                    }
                }
                if (i == dirCnt) {
                    printf("Direktori %s tidak ditemukan.\n", dirName);
                }
                break;
            case 3:
                printf("\nMasukkan nama direktori: ");
                scanf("%s", dirName);
                for (i = 0; i < dirCnt; i++) {
                    if (strcmp(dirName, dir[i].dn) == 0) {
                        printf("Masukkan nama file yang ingin dihapus: ");
                        scanf("%s", file);
                        for (j = 0; j < dir[i].fqty; j++) {
                            if (strcmp(file, dir[i].fn[j]) == 0) {
                                for (int k = j; k < dir[i].fqty - 1; k++) {
                                    strcpy(dir[i].fn[k], dir[i].fn[k + 1]);
                                }
                                dir[i].fqty--;
                                printf("File %s berhasil dihapus dari direktori %s.\n", file, dir[i].dn);
                                break;
                            }
                        }
                        if (j == dir[i].fqty) {
                            printf("File %s tidak ditemukan di direktori %s.\n", file, dir[i].dn);
                        }
                        break;
                    }
                }
                if (i == dirCnt) {
                    printf("Direktori %s tidak ditemukan.\n", dirName);
                }
                break;
            case 4:
                printf("\nMasukkan nama direktori: ");
                scanf("%s", dirName);
                for (i = 0; i < dirCnt; i++) {
                    if (strcmp(dirName, dir[i].dn) == 0) {
                        printf("Masukkan nama file yang ingin dicari: ");
                        scanf("%s", file);
                        for (j = 0; j < dir[i].fqty; j++) {
                            if (strcmp(file, dir[i].fn[j]) == 0) {
                                printf("File %s ditemukan di direktori %s.\n", file, dir[i].dn);
                                break;
                            }
                        }
                        if (j == dir[i].fqty) {
                            printf("File %s tidak ditemukan di direktori %s.\n", file, dir[i].dn);
                        }
                        break;
                    }
                }
                if (i == dirCnt) {
                    printf("Direktori %s tidak ditemukan.\n", dirName);
                }
                break;
            case 5:
                if (dirCnt == 0) {
                    printf("Belum ada direktori yang dibuat.\n");
                    break;
                }
                printf("\nDirektori dan File:\n");
                for (i = 0; i < dirCnt; i++) {
                    printf("Direktori: %s\n", dir[i].dn);
                    for (j = 0; j < dir[i].fqty; j++) {
                        printf("\tFile: %s\n", dir[i].fn[j]);
                    }
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    }
    return 0;
}
