#include "CarServiceManager.h"
#include "RepairService.h"
#include "PaintingService.h"
#include "WashingService.h"
#include "TuningService.h"
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
        oss << "Услуги автосервиса:\n";
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
        oss << "Автомобили в автосервисе:\n";
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
                oss << "Информация об автомобиле:\n";
                oss << car->getInfo() << "\n";
                oss << "Проблемы:\n";
                auto problems = car->getProblems();
                for (size_t i = 0; i < problems.size(); ++i) {
                    oss << "  " << (i + 1) << ". " << problems[i] << "\n";
                }
                oss << "Выполненные услуги:\n";
                auto services = car->getServices();
                for (size_t i = 0; i < services.size(); ++i) {
                    oss << "  " << (i + 1) << ". " << services[i]->getDescription() << "\n";
                }
                return oss.str();
            }
        }
        return "Автомобиль не найден.";
    }

    std::string CarServiceManager::getEmployeeWorkReport(const std::string& employeeName, std::time_t startDate, std::time_t endDate) const {
        for (const auto& employee : employees) {
            if (employee->getName() == employeeName) {
                return employee->getWorkReport(startDate, endDate);
            }
        }
        return "Сотрудник не найден.";
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

    std::vector<std::shared_ptr<Service>> CarServiceManager::createTestServices() {
        std::vector<std::shared_ptr<Service>> testServices;
        
        testServices.push_back(std::make_shared<RepairService>("Ремонт двигателя", 500.0, "Двигатель"));
        testServices.push_back(std::make_shared<RepairService>("Ремонт тормозов", 300.0, "Тормоза"));
        testServices.push_back(std::make_shared<PaintingService>("Полная покраска", 800.0, "Красный"));
        testServices.push_back(std::make_shared<PaintingService>("Частичная покраска", 400.0, "Синий"));
        testServices.push_back(std::make_shared<WashingService>("Стандартная мойка", 50.0, false));
        testServices.push_back(std::make_shared<WashingService>("Химчистка", 150.0, true));
        testServices.push_back(std::make_shared<TuningService>("Тюнинг двигателя", 600.0, "Производительность"));
        testServices.push_back(std::make_shared<TuningService>("Тюнинг подвески", 450.0, "Управляемость"));
        
        return testServices;
    }

    void CarServiceManager::initializeTestData() {
        auto testServices = createTestServices();
        for (const auto& service : testServices) {
            addService(service);
        }
        
        auto testCars = Car::createTestCars(testServices);
        for (const auto& car : testCars) {
            addCar(car);
        }
        
        auto testClients = Client::createTestClients(testCars);
        for (const auto& client : testClients) {
            addClient(client);
        }
        
        auto testEmployees = Employee::createTestEmployees(testCars, testServices);
        for (const auto& employee : testEmployees) {
            addEmployee(employee);
        }
        
        if (!testServices.empty()) {
            auto firstService = testServices[0];
            for (const auto& service : testServices) {
                firstService->addServiceToCollection(service);
            }
            for (const auto& client : testClients) {
                firstService->addClientToCollection(client);
            }
            for (const auto& employee : testEmployees) {
                firstService->addEmployeeToCollection(employee);
            }
        }
    }

}

