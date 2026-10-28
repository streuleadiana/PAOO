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
    // 3. Initializarea membrilor (Constructor)
    ZooEnclosure(const std::string& name, int capacity);

    // 4. Eliberarea heap-ului (Destructor)
    ~ZooEnclosure();

    // 5. Suprascrierea copy constructor-ului
    ZooEnclosure(const ZooEnclosure& other);

    // 6. Crearea unui move constructor
    ZooEnclosure(ZooEnclosure&& other) noexcept;

    // Metode publice pentru manipularea datelor private
    void addAnimal(const std::string& animalName);
    void showHabitat() const;
};