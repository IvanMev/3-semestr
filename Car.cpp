#include "Car.h"
#include <sstream>

namespace CarService {

    Car::Car(const std::string& licensePlate, const std::string& make, const std::string& model, int year)
        : licensePlate(licensePlate), make(make), model(model), year(year) {
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

    std::string Car::getInfo() const {
        std::ostringstream oss;
        oss << "Авто: " << make << " " << model << " (" << year << "), Номер: " << licensePlate;
        return oss.str();
    }

}

