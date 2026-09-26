#include <stdio.h>
#include <string.h>

#define MAX 100
#define TEN_MAX 30
#define GIA_KHAM 200000
#define GIA_BHYT 40000

int so_thu_tu[MAX];
char ten_benh_nhan[MAX][TEN_MAX];
int tuoi[MAX];
int uu_tien[MAX];
int bhyt[MAX];
int phi_kham[MAX];

int so_luong = 0;
int so_thu_tu_tiep_theo = 1001;

void xoa_xuong_dong(char chuoi[]) {
    int i = 0;
    while (chuoi[i] != '\0') {
        if (chuoi[i] == '\n') {
            chuoi[i] = '\0';
            break;
        }
        i++;
    }
}

void xoa_bo_dem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int tim_theo_so_thu_tu(int stt) {
    for (int i = 0; i < so_luong; i++) {
        if (so_thu_tu[i] == stt) {
            return i;
        }
    }
    return -1;
}

void cap_nhat_thong_tin(int index) {
    if (tuoi[index] > 70) {
        uu_tien[index] = 1;
    } else {
        uu_tien[index] = 0;
    }
    if (bhyt[index] == 1) {
        phi_kham[index] = GIA_BHYT;
    } else {
        phi_kham[index] = GIA_KHAM;
    }
}

void hien_thi_benh_nhan(int index) {

    printf("\n----------------------------------------\n");
    printf("So thu tu: %d\n", so_thu_tu[index]);
    printf("Ho ten: %s\n", ten_benh_nhan[index]);
    printf("Tuoi: %d\n", tuoi[index]);

    if (uu_tien[index] == 1) {
        printf("Dien: UU TIEN\n");
    } else {
        printf("Dien: THUONG\n");
    }

    if (bhyt[index] == 1) {
        printf("BHYT: CO\n");
    } else {
        printf("BHYT: KHONG\n");
    }

    printf("Phi kham: %d VND\n", phi_kham[index]);
}

void them_benh_nhan() {
    if (so_luong >= MAX) {
        printf("\nHang doi da day! Khong the tiep nhan them.\n");
        return;
    }
    if (so_luong >= 5) {
        printf("\nKhung gio da du 5 benh nhan!\n");
        printf("Khong the dang ky them vao khung gio nay.\n");
        return;
    }

    int index = so_luong;

    so_thu_tu[index] = so_thu_tu_tiep_theo;

    xoa_bo_dem();

    printf("\nNhap ho ten benh nhan: ");
    fgets(ten_benh_nhan[index], TEN_MAX, stdin);
    xoa_xuong_dong(ten_benh_nhan[index]);

    do {
        printf("Nhap tuoi: ");
        scanf("%d", &tuoi[index]);

        if (tuoi[index] < 1 || tuoi[index] > 120) {
            printf("Tuoi khong hop le! Tuoi phai tu 1 den 120.\n");
        }

    } while (tuoi[index] < 1 || tuoi[index] > 120);

    do {
        printf("Co BHYT? (1: Co, 0: Khong): ");
        scanf("%d", &bhyt[index]);

        if (bhyt[index] != 0 && bhyt[index] != 1) {
            printf("BHYT chi duoc nhap 0 hoac 1.\n");
        }

    } while (bhyt[index] != 0 && bhyt[index] != 1);
    cap_nhat_thong_tin(index);
    so_luong++;
    so_thu_tu_tiep_theo++;

    printf("\nDang ky thanh cong!\n");
    printf("So thu tu cua benh nhan: %d\n", so_thu_tu[index]);
}

void hien_thi_danh_sach() {
    if (so_luong == 0) {
        printf("\nHang doi dang rong.\n");
        return;
    }

    printf("\n===============================================\n");
    printf("           DANH SACH HANG DOI\n");
    printf("===============================================\n");
    for (int i = 0; i < so_luong; i++) {
        printf("\nIndex: %d\n", i);
        printf("So thu tu: %d\n", so_thu_tu[i]);
        printf("Ho ten: %s\n", ten_benh_nhan[i]);
        printf("Tuoi: %d\n", tuoi[i]);

        if (uu_tien[i] == 1) {
            printf("Dien: UU TIEN\n");
        } else {
            printf("Dien: THUONG\n");
        }
        if (bhyt[i] == 1) {
            printf("BHYT: CO\n");
        } else {
            printf("BHYT: KHONG\n");
        }
        printf("Phi kham: %d VND\n", phi_kham[i]);
    }

    printf("\n===============================================\n");
    printf("Tong so benh nhan: %d\n", so_luong);
}

void sua_benh_nhan() {
    if (so_luong == 0) {
        printf("\nHang doi dang rong.\n");
        return;
    }
    int stt;
    int index;

    printf("\nNhap so thu tu can sua: ");
    scanf("%d", &stt);
    index = tim_theo_so_thu_tu(stt);
    if (index == -1) {
        printf("Khong tim thay benh nhan!\n");
        return;
    }
    printf("\nThong tin hien tai:");
    hien_thi_benh_nhan(index);

    xoa_bo_dem();

    printf("\nNhap ten moi: ");
    fgets(ten_benh_nhan[index], TEN_MAX, stdin);
    xoa_xuong_dong(ten_benh_nhan[index]);

    do {
        printf("Nhap tuoi moi: ");
        scanf("%d", &tuoi[index]);

        if (tuoi[index] < 1 || tuoi[index] > 120) {
            printf("Tuoi khong hop le!\n");
        }

    } while (tuoi[index] < 1 || tuoi[index] > 120);

    do {
        printf("Nhap BHYT moi (1: Co, 0: Khong): ");
        scanf("%d", &bhyt[index]);

        if (bhyt[index] != 0 && bhyt[index] != 1) {
            printf("BHYT chi duoc nhap 0 hoac 1.\n");
        }

    } while (bhyt[index] != 0 && bhyt[index] != 1);

    cap_nhat_thong_tin(index);

    printf("\nCap nhat thanh cong!\n");
}

void xoa_benh_nhan() {
    if (so_luong == 0) {
        printf("\nHang doi dang rong. Khong co gi de xoa.\n");
        return;
    }
    int stt;
    int index;

    printf("\nNhap so thu tu can huy: ");
    scanf("%d", &stt);

    index = tim_theo_so_thu_tu(stt);
    if (index == -1) {
        printf("Khong tim thay benh nhan!\n");
        return;
    }

    for (int i = index; i < so_luong - 1; i++) {
        so_thu_tu[i] = so_thu_tu[i + 1];
        strcpy(ten_benh_nhan[i], ten_benh_nhan[i + 1]);
        tuoi[i] = tuoi[i + 1];
        uu_tien[i] = uu_tien[i + 1];
        bhyt[i] = bhyt[i + 1];
        phi_kham[i] = phi_kham[i + 1];
    }
    so_luong--;
    printf("\nHuy lich thanh cong!\n");
}

void tim_theo_stt() {
    int stt;
    int index;
    printf("\nNhap so thu tu can tim: ");
    scanf("%d", &stt);
    index = tim_theo_so_thu_tu(stt);

    if (index == -1) {
        printf("Khong tim thay benh nhan!\n");
    } else {
        printf("\nTim thay benh nhan:\n");
        hien_thi_benh_nhan(index);
    }
}

void tim_theo_ten() {
    char ten_can_tim[TEN_MAX];
    int tim_thay = 0;
    xoa_bo_dem();

    printf("\nNhap ten can tim: ");
    fgets(ten_can_tim, TEN_MAX, stdin);
    xoa_xuong_dong(ten_can_tim);
    for (int i = 0; i < so_luong; i++) {
        if (strcmp(ten_benh_nhan[i], ten_can_tim) == 0) {
            printf("\nTim thay benh nhan:");
            hien_thi_benh_nhan(i);

            tim_thay = 1;
        }
    }
    if (tim_thay == 0) {
        printf("\nKhong tim thay benh nhan co ten \"%s\".\n",
               ten_can_tim);
    }
}

void hien_thi_menu() {

    printf("\n\n========================================\n");
    printf("     MEDCARE - QUAN LY HANG DOI\n");
    printf("========================================\n");
    printf("1. Tiep nhan benh nhan\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Cap nhat thong tin\n");
    printf("4. Huy so thu tu\n");
    printf("5. Tim kiem theo so thu tu\n");
    printf("6. Tim kiem theo ten\n");
    printf("0. Thoat\n");
    printf("========================================\n");
    printf("Chon chuc nang: ");
}
int main() {
    int lua_chon;
    do {
        hien_thi_menu();
        scanf("%d", &lua_chon);
        switch (lua_chon) {
            case 1:
                them_benh_nhan();
                break;
            case 2:
                hien_thi_danh_sach();
                break;
            case 3:
                sua_benh_nhan();
                break;
            case 4:
                xoa_benh_nhan();
                break;
            case 5:
                tim_theo_stt();
                break;
            case 6:
                tim_theo_ten();
                break;
            case 0:
                printf("\nDa thoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (lua_chon != 0);

    return 0;
}