#pragma once
#include <string>
#include <iostream>

class ZooEnclosure {
private:
    std::string habitatName;
    int maxCapacity;
    int currentCount;
    std::string* animals; // Pointer catre memoria alocata dinamic pe heap

public:

    // Item 6: Explicitly disallow the use of compiler-generated functions you do not want:
    // Nu are sens sa cream un tarc "gol" (fara nume si capacitate). 
    // Compilatorul ar fi generat un Default Constructor automat daca nu scriam noi unul cu parametri.
    // Ca sa fim explicit si siguri ca nimeni nu face un tarc fara parametri, stergem acest constructor.
    ZooEnclosure() = delete;

    // 3. Initializarea membrilor (Constructor)
    ZooEnclosure(const std::string& name, int capacity);

    // 4. Eliberarea heap-ului (Destructor)
    ~ZooEnclosure();

    // 5. Suprascrierea copy constructor-ului
    ZooEnclosure(const ZooEnclosure& other);

    // Item 10: Have assignment operators return a reference to *this.
    // Item 11: Handle assignment to self in operator=.
    // Item 12: Copy all parts of an object.
    ZooEnclosure& operator=(const ZooEnclosure& rhs);

    // 6. Crearea unui move constructor
    ZooEnclosure(ZooEnclosure&& other) noexcept;

    // Metode publice pentru manipularea datelor private
    void addAnimal(const std::string& animalName);
    void showHabitat() const;
};