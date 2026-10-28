#include "ZooEnclosure.hpp"

// 3. Constructor: Initializam membrii si devenim proprietarii unei zone de memorie de pe heap
ZooEnclosure::ZooEnclosure(const std::string& name, int capacity) 
    : habitatName(name), maxCapacity(capacity), currentCount(0) {
    
    animals = new std::string[maxCapacity]; // Alocare dinamică
    std::cout << "[Constructor] S-a construit tarcul '" << habitatName 
              << "' (Capacitate: " << maxCapacity << "). Memorie alocata.\n";
}

// 4. Destructor: Curatam dupa noi. 
// Daca nu am face asta, la terminarea programului, memoria ocupata de array-ul "animals" 
// ar ramane blocata, cauzand un Memory Leak
ZooEnclosure::~ZooEnclosure() {
    std::cout << "[Destructor] Se demoleaza tarcul '" << habitatName << "'. Dealocam memoria.\n";
    delete[] animals; 
}

// 5. Copy Constructor (Deep Copy)
// Daca lasam compilatorul sa faca o copie "Shallow" (adresa pointerului), 
// doua obiecte vor crede ca sunt proprietare pe aceeasi zona de memorie. Cand primul obiect 
// este distrus, da "delete[]". Al doilea obiect ramane cu un "Dangling Pointer" (un pointer 
// catre o memorie deja stearsa). Cand se distruge si al doilea, programul crapa (Double Free)
ZooEnclosure::ZooEnclosure(const ZooEnclosure& other) 
    : habitatName(other.habitatName + " (Clona)"), maxCapacity(other.maxCapacity), currentCount(other.currentCount) {
    
    std::cout << "[Copy Constructor] Clonam datele din '" << other.habitatName << "' intr-o memorie separata.\n";
    
    // Alocam propria noastra memorie pentru a fi independenti
    animals = new std::string[maxCapacity];
    for (int i = 0; i < currentCount; ++i) {
        animals[i] = other.animals[i];
    }
}

// 6. Move Constructor (Transfer de proprietate)
// Nu are sens sa "clonam" animalele intr-un loc nou (Deep Copy) si sa le stergem pe cele vechi, pentru ca e lent si ineficient
// Move constructorul doar da "cheile" memoriei noului obiect, lasand obiectul vechi gol
ZooEnclosure::ZooEnclosure(ZooEnclosure&& other) noexcept 
    : habitatName(other.habitatName + " (Relocat)"), 
      maxCapacity(other.maxCapacity), 
      currentCount(other.currentCount), 
      animals(other.animals) // Preluam pointerul direct
{
    std::cout << "[Move Constructor] Transferam proprietatea memoriei de la '" << other.habitatName << "'.\n";
    
    // Deconectam sursa de la memorie ca sa nu o stearga in destructorul ei
    other.animals = nullptr;
    other.currentCount = 0;
    other.maxCapacity = 0;
    other.habitatName = "Tarc Abandonat";
}

// Implementarea metodelor publice
void ZooEnclosure::addAnimal(const std::string& animalName) {
    if (currentCount < maxCapacity && animals != nullptr) {
        animals[currentCount++] = animalName;
    } else {
        std::cout << " [!] Eroare: Tarcul este plin sau invalid!\n";
    }
}

void ZooEnclosure::showHabitat() const {
    std::cout << "=== Tarc: " << habitatName << " ===\n";
    if (animals == nullptr) {
        std::cout << "  (Tarcul nu are nicio alocare de memorie)\n";
        return;
    }
    for (int i = 0; i < currentCount; ++i) {
        std::cout << "  - " << animals[i] << "\n";
    }
}