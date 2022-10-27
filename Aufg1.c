/**
 * Ein Programm, das den größten gemeinsamen Teiler (ggT) zweier Zahlen sowohl iterativ als auch rekursiv berechnet.
 * @author Justin Kahle
 * @date 2022-10-27
*/

#include <stdio.h>

// Forward Declarations/Funktionsprototypen.
int iterativeGCD(int, int);
int recursiveGCD(int, int);

int main() {
    printf("Iterative GCD: %d\n", iterativeGCD(1071, 1029));
    printf("Iterative GCD: %d\n", iterativeGCD(19240, 82112));
    printf("Iterative GCD: %d\n", iterativeGCD(285, 9123));

    printf("\n");

    printf("Iterative GCD: %d\n", iterativeGCD(0, 0));
    printf("Iterative GCD: %d\n", iterativeGCD(12, 0));
    printf("Iterative GCD: %d\n", iterativeGCD(0, 15));

    printf("\n");

    printf("Recursive GCD: %d\n", recursiveGCD(1071, 1029));
    printf("Recursive GCD: %d\n", recursiveGCD(100055, 6500));
    printf("Recursive GCD: %d\n", recursiveGCD(1778, 126));

    printf("\n");

    printf("Recursive GCD: %d\n", iterativeGCD(0, 0));
    printf("Recursive GCD: %d\n", iterativeGCD(104, 0));
    printf("Recursive GCD: %d\n", iterativeGCD(0, 55));

    return 0;
}

// Iterative Funktion des ggTs.
int iterativeGCD(int firstNum, int secondNum) {
    // Wenn Zähler gleich 0, dann gebe Nenner zurück (der auch 0 sein kann!). Deckt also zwei Sonderfälle.
    if(firstNum == 0) return secondNum;

    int remainder = 0;

    // Vorgang des Euklidischen Algorithmus.
    // Da wir ständig dividieren, hören wir auf, wenn die Division aufgeht bzw. wenn der Rest 0 ist
    // da etwas durch 0 undefiniert ist.
    while(secondNum != 0) {
        remainder = firstNum % secondNum; // Berechne Rest aus a : b.

        firstNum = secondNum; // Setze a = b.
        secondNum = remainder; // Setze b = den ermittelten Rest
    }

    return firstNum; // Gebe den ggT, der ermittelt wurde, zurück.
}

// Rekursive Funktion des ggTs.
int recursiveGCD(int firstNum, int secondNum) {
    // Abbruchbedingung am Anfang; WICHTIG, sonst "unendliche" Schleife => Stack Overflow in dem Fall.
    if(firstNum == 0) return secondNum;
    if(secondNum == 0) return firstNum;

    // Rufe die Funktion erneut auf und setze b = Rest aus a und b und a = b.
    // Macht eine Zusatzvariable redundant.
    recursiveGCD(secondNum, firstNum % secondNum);
}

/*
int recursivePreCheck(int firstNum, int secondNum) {
    if(firstNum == 0) return secondNum;

    recursiveGCD(firstNum, secondNum);
}
*/
