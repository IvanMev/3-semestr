#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include "Service.h"
#include "RepairService.h"
#include "PaintingService.h"
#include "WashingService.h"
#include "TuningService.h"
#include "Car.h"
#include "Client.h"
#include "Employee.h"
#include "CarServiceManager.h"

using namespace CarService;

int main() {
    CarServiceManager manager;

    std::vector<std::shared_ptr<Service>> services;

    services.push_back(std::make_shared<RepairService>("Engine Repair", 500.0, "Engine"));
    services.push_back(std::make_shared<RepairService>("Brake Repair", 300.0, "Brakes"));
    services.push_back(std::make_shared<PaintingService>("Full Body Paint", 800.0, "Red"));
    services.push_back(std::make_shared<PaintingService>("Partial Paint", 400.0, "Blue"));
    services.push_back(std::make_shared<WashingService>("Standard Wash", 50.0, false));
    services.push_back(std::make_shared<WashingService>("Dry Cleaning", 150.0, true));
    services.push_back(std::make_shared<TuningService>("Engine Tuning", 600.0, "Performance"));
    services.push_back(std::make_shared<TuningService>("Suspension Tuning", 450.0, "Handling"));

    for (const auto& service : services) {
        manager.addService(service);
    }

    std::cout << "=== Services Collection (Polymorphism Demo) ===" << std::endl;
    for (size_t i = 0; i < services.size(); ++i) {
        std::cout << "Service " << (i + 1) << ": " << services[i]->getDescription() << std::endl;
        std::cout << "  Type: " << services[i]->getServiceType() << std::endl;
        std::cout << "  Price: $" << services[i]->getPrice() << std::endl;
        std::cout << std::endl;
    }

    auto car1 = std::make_shared<Car>("ABC123", "Toyota", "Camry", 2020);
    car1->addProblem("Engine overheating");
    car1->addProblem("Brake pads worn");
    car1->addService(services[0]);
    car1->addService(services[1]);

    auto car2 = std::make_shared<Car>("XYZ789", "Honda", "Civic", 2019);
    car2->addProblem("Paint scratches");
    car2->addService(services[2]);

    auto car3 = std::make_shared<Car>("DEF456", "Ford", "Focus", 2021);
    car3->addProblem("Interior cleaning needed");
    car3->addService(services[5]);

    manager.addCar(car1);
    manager.addCar(car2);
    manager.addCar(car3);

    auto client1 = std::make_shared<Client>("John Doe", "555-0101", true);
    client1->addCar(car1);
    client1->addCar(car2);

    auto client2 = std::make_shared<Client>("Jane Smith", "555-0102", false);
    client2->addCar(car3);

    manager.addClient(client1);
    manager.addClient(client2);

    auto employee1 = std::make_shared<Employee>("Mike Johnson", "Mechanic");
    auto employee2 = std::make_shared<Employee>("Sarah Williams", "Painter");
    auto employee3 = std::make_shared<Employee>("Tom Brown", "Detailer");

    std::time_t now = std::time(nullptr);
    std::time_t yesterday = now - 86400;
    std::time_t lastWeek = now - 7 * 86400;

    employee1->addWorkRecord(car1, services[0], yesterday, 4.5);
    employee1->addWorkRecord(car1, services[1], yesterday, 2.0);
    employee2->addWorkRecord(car2, services[2], lastWeek, 6.0);
    employee3->addWorkRecord(car3, services[5], now, 3.0);

    manager.addEmployee(employee1);
    manager.addEmployee(employee2);
    manager.addEmployee(employee3);

    std::cout << "\n=== Task 1: List of Services with Prices ===" << std::endl;
    std::cout << manager.getServicesList() << std::endl;

    std::cout << "\n=== Task 2: List of Cars in Service ===" << std::endl;
    std::cout << manager.getCarsList() << std::endl;

    std::cout << "\n=== Task 3: Car Information (Services Provided) ===" << std::endl;
    std::cout << manager.getCarInfo("ABC123") << std::endl;

    std::cout << "\n=== Task 4: Employee Work Report (Last 7 Days) ===" << std::endl;
    std::time_t startDate = now - 7 * 86400;
    std::time_t endDate = now;
    std::cout << manager.getEmployeeWorkReport("Mike Johnson", startDate, endDate) << std::endl;

    std::cout << "\n=== Task 5: Calculate Service Costs for Clients ===" << std::endl;
    double cost1 = manager.calculateClientCost("John Doe");
    double cost2 = manager.calculateClientCost("Jane Smith");
    
    std::cout << "Client: John Doe (Regular - 10% discount)" << std::endl;
    std::cout << "Total cost: $" << cost1 << std::endl;
    std::cout << "\nClient: Jane Smith (Regular - no discount)" << std::endl;
    std::cout << "Total cost: $" << cost2 << std::endl;

    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}

