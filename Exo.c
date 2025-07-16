#include <stdio.h>
#include <ctype.h>

#define NMAX 100

typedef char mot[NMAX];

// Fonction mirroir
void mirroir(mot dest, mot src) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0';
}

// Fonction majuscules
void majuscules(mot dest, mot src) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        dest[i] = toupper(src[i]);
    }
    dest[len] = '\0';
}

// Fonction est_facteur_gauche
int est_facteur_gauche(mot facteur_g, mot src) {
    int len_facteur = strlen(facteur_g);
    int len_src = strlen(src);
    if (len_facteur > len_src) return 0;
    for (int i = 0; i < len_facteur; i++) {
        if (facteur_g[i] != src[i]) return 0;
    }
    return 1;
}

// Fonction est_facteur
int est_facteur(mot facteur, mot src) {
    int len_facteur = strlen(facteur);
    int len_src = strlen(src);
    if (len_facteur > len_src) return 0;
    for (int i = 0; i <= len_src - len_facteur; i++) {
        int match = 1;
        for (int j = 0; j < len_facteur; j++) {
            if (src[i + j] != facteur[j]) {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

// Fonction est_sous_mot (récursive)
int est_sous_mot(mot sous_mot, mot src) {
    int len_sous_mot = strlen(sous_mot);
    int len_src = strlen(src);
    if (len_sous_mot == 0) return 1; // Cas de base : sous-mot vide
    if (len_src == 0) return 0;      // Sous-mot non trouvé
    if (sous_mot[0] == src[0]) {
        return est_sous_mot(sous_mot + 1, src + 1); // Correspondance trouvée, continuer récursivement
    } else {
        return est_sous_mot(sous_mot, src + 1); // Pas de correspondance, avancer dans src
    }
}

void main() {
    mot src = "polycopie";
    mot facteur_g = "poly";
    mot facteur = "copie";
    mot sous_mot = "co";

    mirroir(src, src);
    printf("Mirroir de 'polycopie' : %s\n", src);

    majuscules(src, "abcde");
    printf("Majuscules de 'abcde' : %s\n", src);

    printf("est_facteur_gauche('poly', 'polycopie') : %d\n", est_facteur_gauche(facteur_g, "polycopie"));
    printf("est_facteur('copi', 'polycopie') : %d\n", est_facteur(facteur, "polycopie"));
    printf("est_sous_mot('co', 'polycopie') : %d\n", est_sous_mot(sous_mot, "polycopie"));
}
