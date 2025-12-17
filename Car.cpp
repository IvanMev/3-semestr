#include "Car.h"
#include "Client.h"
#include <sstream>

namespace CarService {

    Car::Car(const std::string& licensePlate, const std::string& make, const std::string& model, int year)
        : licensePlate(licensePlate), make(make), model(model), year(year), owner(nullptr) {
    }

    std::string Car::getLicensePlate() const {
        return licensePlate;
    }

    std::string Car::getMake() const {
        return make;
    }

    std::string Car::getModel() const {
        return model;
    }

    int Car::getYear() const {
        return year;
    }

    void Car::addService(std::shared_ptr<Service> service) {
        services.push_back(service);
    }

    std::vector<std::shared_ptr<Service>> Car::getServices() const {
        return services;
    }

    void Car::addProblem(const std::string& problemDescription) {
        problems.push_back(problemDescription);
    }

    std::vector<std::string> Car::getProblems() const {
        return problems;
    }

    void Car::setOwner(std::shared_ptr<Client> owner) {
        this->owner = owner;
    }

    std::shared_ptr<Client> Car::getOwner() const {
        return owner;
    }

    std::string Car::getInfo() const {
        std::ostringstream oss;
        oss << "Авто: " << make << " " << model << " (" << year << "), Номер: " << licensePlate;
        if (owner) {
            oss << ", Владелец: " << owner->getName();
        }
        return oss.str();
    }

    std::vector<std::shared_ptr<Car>> Car::createTestCars(const std::vector<std::shared_ptr<Service>>& services) {
        std::vector<std::shared_ptr<Car>> testCars;
        
        auto car1 = std::make_shared<Car>("ABC123", "Toyota", "Camry", 2020);
        car1->addProblem("Перегрев двигателя");
        car1->addProblem("Изношены тормозные колодки");
        if (services.size() > 0) car1->addService(services[0]);
        if (services.size() > 1) car1->addService(services[1]);
        testCars.push_back(car1);
        
        auto car2 = std::make_shared<Car>("XYZ789", "Honda", "Civic", 2019);
        car2->addProblem("Царапины на покрытии");
        if (services.size() > 2) car2->addService(services[2]);
        testCars.push_back(car2);
        
        auto car3 = std::make_shared<Car>("DEF456", "Ford", "Focus", 2021);
        car3->addProblem("Требуется уборка салона");
        if (services.size() > 5) car3->addService(services[5]);
        testCars.push_back(car3);
        
        return testCars;
    }

}

