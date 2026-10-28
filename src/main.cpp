#include "ZooEnclosure.hpp"
#include <iostream>
#include <utility>

// Transmiterea prin valoare forteaza apelarea Copy Constructorului
void inspectEnclosure(ZooEnclosure tempEnclosure) {
    std::cout << "\n[Inspector ZOO] Analizez urmatorul tarc:\n";
    tempEnclosure.showHabitat();
    // La iesirea din functie, tempEnclosure va fi distrusa
}

int main() {
    std::cout << "--- 1. CREARE SI INCAPSULARE ---\n";
    ZooEnclosure savana("Savana Africana", 3);
    savana.addAnimal("Leu");
    savana.addAnimal("Zebra");
    savana.showHabitat();

    std::cout << "\n--- 2. DEMONSTRARE COPY CONSTRUCTOR ---\n";
    // Cand apelam functia, se creeaza o copie temporara a obiectului "savana"
    // Daca nu aveam Deep Copy, memoria s-ar fi corupt aici
    inspectEnclosure(savana); 

    std::cout << "\n[Main] Dupa inspectie, tarcul original ramane intact:\n";
    savana.showHabitat();

    std::cout << "\n--- 3. DEMONSTRARE MOVE CONSTRUCTOR ---\n";
    // Aici mutam tot continutul (inclusiv memoria de pe heap) catre o noua locatie,
    // fiind o operatie extrem de rapida pentru ca mutam doar niste pointeri (adrese)
    ZooEnclosure savanaNoua = std::move(savana);

    std::cout << "\nDupa relocare, starea tarcurilor este:\n";
    savana.showHabitat();     // Ar trebui sa fie un tarc abandonat, fara memorie
    savanaNoua.showHabitat(); // A preluat memoria cu Leul si Zebra

    std::cout << "\n--- SFARSIT (Intervin destructorii) ---\n";
    return 0;
}