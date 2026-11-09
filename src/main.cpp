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


    // =====================================================================
    // ============ SECTIUNEA NOUA PENTRU LUCRARILE 4 SI 5 =================
    // =====================================================================

    std::cout << "\n--- 4. DEMONSTRARE ITEM 6 (Lucrarea 4) ---\n";
    std::cout << "Compilatorul nu ne lasa sa cream un tarc fara parametri, deoarece am sters explicit default constructor-ul (= delete).\n";
    // ZooEnclosure tarcGresit; // Daca decomentezi aceasta linie, programul nu va compila!

    std::cout << "\n--- 5. DEMONSTRARE ITEM 11 (Self-Assignment) ---\n";
    ZooEnclosure ursi("Habitat Ursi", 2);
    ursi.addAnimal("Baloo");
    ursi.showHabitat();
    
    std::cout << "[Test] Fortam atribuirea obiectului catre el insusi (ursi = ursi):\n";
    ursi = ursi; 
    ursi.showHabitat(); // Datele raman intacte, nu au fost sterse accidental.

    std::cout << "\n--- 6. DEMONSTRARE ITEM 10 & 12 (Chained Assignment & Copy all parts) ---\n";
    ZooEnclosure maimute("Habitat Maimute", 4);
    maimute.addAnimal("Cimpanzeu");
    
    ZooEnclosure tarcTemporar("Tarc Nou", 5);
    
    std::cout << "[Test] Lant de atribuiri: tarcTemporar = maimute = ursi;\n";
    // Compilatorul evalueaza de la dreapta la stanga:
    // 1. "ursi" se copiaza in "maimute"
    // 2. noul obiect "maimute" (care acum contine datele ursilor) se copiaza in "tarcTemporar"
    tarcTemporar = maimute = ursi;

    std::cout << "\nStarea finala dupa chained assignment:\n";
    ursi.showHabitat();         // Originalul (Habitat Ursi)
    maimute.showHabitat();      // Copie completa (Inclusiv numele s-a suprascris - Item 12)
    tarcTemporar.showHabitat(); // A preluat totul la randul sau prin inlantuire (Item 10)

    std::cout << "\n--- SFARSIT (Intervin destructorii) ---\n";
    return 0;
}