#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * BURSA TEKNIK UNIVERSITESI - BILGISAYAR MUHENDISLIGI
 * ALGORITMALAR VE PROGRAMLAMA DERSI DONEM PROJESI
 */

#define PI 3.14159265358979323846
#define GEZEGEN_SAYISI 8

/* 1. ZORUNLULUK: Gezegen ivmeleri dizi icerisinde gunese yakinlik sirasina gore tutulur [cite: 83] */
double gezegen_ivmeleri[GEZEGEN_SAYISI] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};

/**
 * 2. ZORUNLULUK: Negatif metrikleri ternary operator ile mutlak degere cevirir [cite: 86]
 * Bu islem icin 'if' kullanimi yasaktir.
 */
double mutlak_yap(double *deger) {
    return (*deger < 0) ? -(*deger) : *deger;
}

const char *gezegen_adi_bul(int indis) {
    const char *isimler[GEZEGEN_SAYISI] = {
        "Merkur", "Venus", "Dunya", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptun"
    };
    return isimler[indis];
}

void dekoratif_ayrac() {
    printf("**********************************************************************\n");
}

void deney_on_bilgi(const char *deney, const char *bilim_insani) {
    printf("\n");
    dekoratif_ayrac();
    printf(" >> SIMULASYON: %s\n", deney);
    printf(" >> YURUTEN BILIM INSANI: %s\n", bilim_insani);
    dekoratif_ayrac();
}

/* ----------------------------------------------------------------------------------
 * DENEY FONKSIYONLARI
 * 3. ZORUNLULUK: Her deney ayri fonksiyonda, tum parametreler pointer olarak
 * 4. ZORUNLULUK: Dizi erisimleri pointer aritmetigi (*(g+i)) ile
 * ---------------------------------------------------------------------------------- */

void calistir_serbest_dusme(double *g_ptr, double *t_ptr, char *ad) {
    double t = mutlak_yap(t_ptr);
    deney_on_bilgi("Serbest Dusme Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double h = 0.5 * (*(g_ptr + i)) * pow(t, 2); /* h = 1/2 * g * t^2 [cite: 36] */
        printf("[%s] -> Dusme Mesafesi (h): %.3f m\n", gezegen_adi_bul(i), h);
    }
}

void calistir_yukari_atis(double *g_ptr, double *v_ptr, char *ad) {
    double v0 = mutlak_yap(v_ptr);
    deney_on_bilgi("Yukari Atis Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double h_max = (v0 * v0) / (2 * (*(g_ptr + i))); /* h_max = v0^2 / 2g  */
        printf("[%s] -> Maksimum Yukseklik (h_max): %.3f m\n", gezegen_adi_bul(i), h_max);
    }
}

void calistir_agirlik(double *g_ptr, double *m_ptr, char *ad) {
    double m = mutlak_yap(m_ptr);
    deney_on_bilgi("Agirlik Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double G = m * (*(g_ptr + i)); /* G = m * g  */
        printf("[%s] -> Agirlik (G): %.3f Newton\n", gezegen_adi_bul(i), G);
    }
}

void calistir_potansiyel_enerji(double *g_ptr, double *m_ptr, double *h_ptr, char *ad) {
    double m = mutlak_yap(m_ptr);
    double h = mutlak_yap(h_ptr);
    deney_on_bilgi("Kutlecekimsel Potansiyel Enerji Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double Ep = m * (*(g_ptr + i)) * h; /* Ep = m * g * h [cite: 49] */
        printf("[%s] -> Potansiyel Enerji (Ep): %.3f Joule\n", gezegen_adi_bul(i), Ep);
    }
}

void calistir_hidrostatik_basinc(double *g_ptr, double *rho_ptr, double *h_ptr, char *ad) {
    double rho = mutlak_yap(rho_ptr);
    double h = mutlak_yap(h_ptr);
    deney_on_bilgi("Hidrostatik Basinc Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double P = rho * (*(g_ptr + i)) * h; /* P = rho * g * h [cite: 54] */
        printf("[%s] -> Hidrostatik Basinc (P): %.3f Pascal\n", gezegen_adi_bul(i), P);
    }
}

void calistir_arsimet(double *g_ptr, double *rho_ptr, double *V_ptr, char *ad) {
    double rho = mutlak_yap(rho_ptr);
    double V = mutlak_yap(V_ptr);
    deney_on_bilgi("Arsimet Kaldirma Kuvveti Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double Fk = rho * (*(g_ptr + i)) * V; /* Fk = rho * g * V [cite: 59] */
        printf("[%s] -> Kaldirma Kuvveti (Fk): %.3f Newton\n", gezegen_adi_bul(i), Fk);
    }
}

void calistir_sarkac(double *g_ptr, double *L_ptr, char *ad) {
    double L = mutlak_yap(L_ptr);
    deney_on_bilgi("Basit Sarkac Periyodu Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double T_per = 2 * PI * sqrt(L / (*(g_ptr + i))); /* T = 2*PI*sqrt(L/g) */
        printf("[%s] -> Periyot (T): %.3f saniye\n", gezegen_adi_bul(i), T_per);
    }
}

void calistir_ip_gerilmesi(double *g_ptr, double *m_ptr, char *ad) {
    double m = mutlak_yap(m_ptr);
    deney_on_bilgi("Sabit Ip Gerilmesi Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double T_ger = m * (*(g_ptr + i)); /* T = m * g */
        printf("[%s] -> Ip Gerilmesi (T): %.3f Newton\n", gezegen_adi_bul(i), T_ger);
    }
}

void calistir_asansor(double *g_ptr, double *m_ptr, double *a_ptr, int *tip_ptr, char *ad) {
    double m = mutlak_yap(m_ptr);
    double a = mutlak_yap(a_ptr);
    deney_on_bilgi("Asansor Deneyi", ad);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g_yer = *(g_ptr + i);
        /* Asansor durumu secimi ve Newton birimi  */
        double N_etkin = (*tip_ptr == 1) ? m * (g_yer + a) : m * (g_yer - a);
        N_etkin = (N_etkin < 0) ? -N_etkin : N_etkin;
        printf("[%s] -> Hissedilen Agirlik (N): %.3f Newton\n", gezegen_adi_bul(i), N_etkin);
    }
}

int main() {
    char bilim_ad[100];
    int secim = 0;

    /* 5. ZORUNLULUK: Bilim insani adinin istenmesi [cite: 17] */
    printf("Lutfen Bilim Insani Adinizi Giriniz: ");
    scanf(" %[^\n]", bilim_ad);

    /* 5. ZORUNLULUK: Kullanici -1 girene kadar tekrar secim yapabilmelidir [cite: 87, 88] */
    while (secim != -1) {
        printf("\n--- DENEY MENUSU ---\n");
        printf("1. Serbest Dusme\n2. Yukari Atis\n3. Agirlik\n4. Potansiyel Enerji\n");
        printf("5. Hidrostatik Basinc\n6. Arsimet\n7. Basit Sarkac\n8. Ip Gerilmesi\n9. Asansor\n-1. CIKIS\n");
        printf("Seciminiz: ");

        if (scanf("%d", &secim) != 1) {
            printf("\nHATA: Gecersiz giris! Sayisal bir deger giriniz.\n");
            while (getchar() != '\n');
            continue;
        }

        if (secim == -1) break;

        double m_val, h_val, t_val, v_val, rho_val, V_bat_val, L_val, a_iv_val;
        int tip_val;

        switch (secim) {
            case 1:
                printf("Sure (t) saniye: "); scanf("%lf", &t_val);
                calistir_serbest_dusme(gezegen_ivmeleri, &t_val, bilim_ad); break;
            case 2:
                printf("Hiz (v0) m/s: "); scanf("%lf", &v_val);
                calistir_yukari_atis(gezegen_ivmeleri, &v_val, bilim_ad); break;
            case 3:
                printf("Kutle (m) kg: "); scanf("%lf", &m_val);
                calistir_agirlik(gezegen_ivmeleri, &m_val, bilim_ad); break;
            case 4:
                printf("Kutle (m) kg: "); scanf("%lf", &m_val);
                printf("Yukseklik (h) m: "); scanf("%lf", &h_val);
                calistir_potansiyel_enerji(gezegen_ivmeleri, &m_val, &h_val, bilim_ad); break;
            case 5:
                printf("Yogunluk (rho) kg/m^3: "); scanf("%lf", &rho_val);
                printf("Derinlik (h) m: "); scanf("%lf", &h_val);
                calistir_hidrostatik_basinc(gezegen_ivmeleri, &rho_val, &h_val, bilim_ad); break;

            case 6: /* ARSIMET - AYRI AYRI GIRIS VE HARF KONTROLU */
                printf("Sivinin yogunlugunu (rho) kg/m^3 cinsinden giriniz: ");
                while (scanf("%lf", &rho_val) != 1) {
                    printf("HATA: Sayisal bir deger giriniz: ");
                    while(getchar() != '\n');
                }
                printf("Cismin batan hacmini (V) m^3 cinsinden giriniz: ");
                while (scanf("%lf", &V_bat_val) != 1) {
                    printf("HATA: Sayisal bir deger giriniz: ");
                    while(getchar() != '\n');
                }
                calistir_arsimet(gezegen_ivmeleri, &rho_val, &V_bat_val, bilim_ad);
                break;

            case 7:
                printf("Ip uzunlugu (L) metre: "); scanf("%lf", &L_val);
                calistir_sarkac(gezegen_ivmeleri, &L_val, bilim_ad); break;
            case 8:
                printf("Kutle (m) kg: "); scanf("%lf", &m_val);
                calistir_ip_gerilmesi(gezegen_ivmeleri, &m_val, bilim_ad); break;

            case 9: /* ASANSOR - AYRI AYRI GIRIS VE HARF KONTROLU */
                printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
                while (scanf("%lf", &m_val) != 1) {
                    printf("HATA: Sayisal bir deger giriniz: ");
                    while(getchar() != '\n');
                }
                printf("Asansorun ivmesini (a) m/s^2 cinsinden giriniz: ");
                while (scanf("%lf", &a_iv_val) != 1) {
                    printf("HATA: Sayisal bir deger giriniz: ");
                    while(getchar() != '\n');
                }
                do {
                    printf("Hareket Tipi (1: Yukari Hizlanma/Asagi Yavaslama, 2: Diger): ");
                    if (scanf("%d", &tip_val) != 1) {
                        while(getchar() != '\n');
                        tip_val = 0;
                    }
                } while (tip_val != 1 && tip_val != 2);
                calistir_asansor(gezegen_ivmeleri, &m_val, &a_iv_val, &tip_val, bilim_ad);
                break;

            default: printf("Gecersiz secim! Lutfen listeden bir numara giriniz.\n");
        }
    }

    printf("\nSimulasyon sonlandirildi. Gule gule %s!\n", bilim_ad);
    return 0;
}
