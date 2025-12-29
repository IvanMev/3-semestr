#include "Client.h"

namespace CarService {

    const double Client::REGULAR_CLIENT_DISCOUNT = 10.0;

    Client::Client(const std::string& name, const std::string& phone, bool isRegular)
        : name(name), phone(phone), regular(isRegular) {
    }

    std::string Client::getName() const {
        return name;
    }

    std::string Client::getPhone() const {
        return phone;
    }

    bool Client::isRegularClient() const {
        return regular;
    }

    void Client::addCar(std::shared_ptr<Car> car) {
        cars.push_back(car);
    }

    std::vector<std::shared_ptr<Car>> Client::getCars() const {
        return cars;
    }

    double Client::getDiscountPercent() const {
        return regular ? REGULAR_CLIENT_DISCOUNT : 0.0;
    }

    void Client::setRegularStatus(bool isRegular) {
        regular = isRegular;
    }

    std::vector<std::shared_ptr<Client>> Client::createTestClients(const std::vector<std::shared_ptr<Car>>& cars) {
        std::vector<std::shared_ptr<Client>> testClients;
        
        auto client1 = std::make_shared<Client>("Иван Петров", "555-0101", true);
        if (cars.size() > 0) {
            client1->addCar(cars[0]);
            cars[0]->setOwner(client1);
        }
        if (cars.size() > 1) {
            client1->addCar(cars[1]);
            cars[1]->setOwner(client1);
        }
        testClients.push_back(client1);
        
        auto client2 = std::make_shared<Client>("Мария Смирнова", "555-0102", false);
        if (cars.size() > 2) {
            client2->addCar(cars[2]);
            cars[2]->setOwner(client2);
        }
        testClients.push_back(client2);
        
        return testClients;
    }

}

