/**
 * Ein Program zur Berechnung der Fakultät einer natürlichen Zahl, des Binominalkoeffizienten zweier Zahlen und
 * zur Erstellung des Pascal'schen Dreiecks basierend auf diesen.
 * @author Justin Kahle
 * @date 2022-10-21
*/

#include <stdio.h>

// Forward Declarations/Funktionsprototypen.
int factorial(int);
int binomialCoefficient(int, int);
void pascalsTriangle(int);

int main() {
    printf("%d\n", factorial(5));
    printf("%d\n", factorial(0));
    printf("%d\n", factorial(10));

    printf("\n");

    pascalsTriangle(6); // Sechs Zeilen.

    printf("\n");

    pascalsTriangle(10); // Zehn Zeilen.

    printf("\n");

    pascalsTriangle(16); // 35 Zeilen.
}

// Fakultätsfunktion.
int factorial(int num) {
    if(num < 0) return 0; // Fehler. Fakultät geht nur mit natürlichen Zahlen.
    if(num == 0) return 1; // 0! = 1.

    // Aufgrund der Bedingung fallen 1! und 0! raus, da diese das Ergebnis eh nicht beeinflussen.
    for(int i = num; i > 1;) {
        num *= --i; // Reinitialisierungskomponente fällt raus, da hier bereits dekrementiert wird.
    }

    return num;
}

// Funktion zur Berechnung des Binomialkoeffizientens.
int binomialCoefficient(int n, int k) {
    if(k < 0 || n < k) return 0;

    return (factorial(n)) / (factorial(k) * factorial(n - k));
}

// Funktion, die das Pascal'sche Dreieck ausgibt.
void pascalsTriangle(int n) { // n steht für die Zeilen.
    // Schleife für die Zeilen.
    for(int i = 0; i < n; i++) {
        // Diese innere Schleife setzt den Zeilenabstand pro Zeile (=> Formattierung).
        for(int k = 0; k < (n - i) * 4; k++) {
            printf(" ");
        }
        // Diese innere Schleife geht die Spalten durch.
        for(int j = 0; j <= i; j++) { // Anzahl an Spalten ist abhängig von der aktuellen Zeile.
            // Ausgabe des Binomialkoeffizientens; n - (n - i) gibt die aktuelle Zeile an.
            printf("%8d", binomialCoefficient(n - (n - i), j));
        }

        printf("\n");
    }
}
