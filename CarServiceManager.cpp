#include "CarServiceManager.h"
#include <sstream>
#include <algorithm>

namespace CarService {

    CarServiceManager::CarServiceManager() {
    }

    void CarServiceManager::addService(std::shared_ptr<Service> service) {
        services.push_back(service);
    }

    std::vector<std::shared_ptr<Service>> CarServiceManager::getAllServices() const {
        return services;
    }

    std::string CarServiceManager::getServicesList() const {
        std::ostringstream oss;
        oss << "Services offered by the car service:\n";
        for (size_t i = 0; i < services.size(); ++i) {
            oss << (i + 1) << ". " << services[i]->getDescription() << "\n";
        }
        return oss.str();
    }

    void CarServiceManager::addCar(std::shared_ptr<Car> car) {
        cars.push_back(car);
    }

    std::vector<std::shared_ptr<Car>> CarServiceManager::getAllCars() const {
        return cars;
    }

    std::string CarServiceManager::getCarsList() const {
        std::ostringstream oss;
        oss << "Cars in the car service:\n";
        for (size_t i = 0; i < cars.size(); ++i) {
            oss << (i + 1) << ". " << cars[i]->getInfo() << "\n";
        }
        return oss.str();
    }

    void CarServiceManager::addClient(std::shared_ptr<Client> client) {
        clients.push_back(client);
    }

    std::vector<std::shared_ptr<Client>> CarServiceManager::getAllClients() const {
        return clients;
    }

    void CarServiceManager::addEmployee(std::shared_ptr<Employee> employee) {
        employees.push_back(employee);
    }

    std::vector<std::shared_ptr<Employee>> CarServiceManager::getAllEmployees() const {
        return employees;
    }

    std::string CarServiceManager::getCarInfo(const std::string& licensePlate) const {
        for (const auto& car : cars) {
            if (car->getLicensePlate() == licensePlate) {
                std::ostringstream oss;
                oss << "Car Information:\n";
                oss << car->getInfo() << "\n";
                oss << "Problems:\n";
                auto problems = car->getProblems();
                for (size_t i = 0; i < problems.size(); ++i) {
                    oss << "  " << (i + 1) << ". " << problems[i] << "\n";
                }
                oss << "Services provided:\n";
                auto services = car->getServices();
                for (size_t i = 0; i < services.size(); ++i) {
                    oss << "  " << (i + 1) << ". " << services[i]->getDescription() << "\n";
                }
                return oss.str();
            }
        }
        return "Car not found.";
    }

    std::string CarServiceManager::getEmployeeWorkReport(const std::string& employeeName, std::time_t startDate, std::time_t endDate) const {
        for (const auto& employee : employees) {
            if (employee->getName() == employeeName) {
                return employee->getWorkReport(startDate, endDate);
            }
        }
        return "Employee not found.";
    }

    double CarServiceManager::calculateClientCost(const std::string& clientName) const {
        for (const auto& client : clients) {
            if (client->getName() == clientName) {
                double totalCost = 0.0;
                auto clientCars = client->getCars();
                for (const auto& car : clientCars) {
                    auto carServices = car->getServices();
                    for (const auto& service : carServices) {
                        totalCost += service->getPrice();
                    }
                }
                double discount = client->getDiscountPercent();
                return totalCost * (1.0 - discount / 100.0);
            }
        }
        return 0.0;
    }

}

