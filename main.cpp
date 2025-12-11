#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <locale>
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

    std::setlocale(LC_ALL, "Russian");

    CarServiceManager manager;

    std::vector<std::shared_ptr<Service>> services;

    services.push_back(std::make_shared<RepairService>("Ремонт двигателя", 500.0, "Двигатель"));
    services.push_back(std::make_shared<RepairService>("Ремонт тормозов", 300.0, "Тормоза"));
    services.push_back(std::make_shared<PaintingService>("Полная покраска", 800.0, "Красный"));
    services.push_back(std::make_shared<PaintingService>("Частичная покраска", 400.0, "Синий"));
    services.push_back(std::make_shared<WashingService>("Стандартная мойка", 50.0, false));
    services.push_back(std::make_shared<WashingService>("Химчистка", 150.0, true));
    services.push_back(std::make_shared<TuningService>("Тюнинг двигателя", 600.0, "Производительность"));
    services.push_back(std::make_shared<TuningService>("Тюнинг подвески", 450.0, "Управляемость"));

    for (const auto& service : services) {
        manager.addService(service);
    }

    std::cout << "=== Коллекция услуг (демо полиморфизма) ===" << std::endl;
    for (size_t i = 0; i < services.size(); ++i) {
        std::cout << "Service " << (i + 1) << ": " << services[i]->getDescription() << std::endl;
        std::cout << "  Type: " << services[i]->getServiceType() << std::endl;
        std::cout << "  Price: $" << services[i]->getPrice() << std::endl;
        std::cout << std::endl;
    }

    auto car1 = std::make_shared<Car>("ABC123", "Toyota", "Camry", 2020);
    car1->addProblem("Перегрев двигателя");
    car1->addProblem("Изношены тормозные колодки");
    car1->addService(services[0]);
    car1->addService(services[1]);

    auto car2 = std::make_shared<Car>("XYZ789", "Honda", "Civic", 2019);
    car2->addProblem("Царапины на покрытии");
    car2->addService(services[2]);

    auto car3 = std::make_shared<Car>("DEF456", "Ford", "Focus", 2021);
    car3->addProblem("Требуется уборка салона");
    car3->addService(services[5]);

    manager.addCar(car1);
    manager.addCar(car2);
    manager.addCar(car3);

    auto client1 = std::make_shared<Client>("Иван Петров", "555-0101", true);
    client1->addCar(car1);
    client1->addCar(car2);

    auto client2 = std::make_shared<Client>("Мария Смирнова", "555-0102", false);
    client2->addCar(car3);

    manager.addClient(client1);
    manager.addClient(client2);

    auto employee1 = std::make_shared<Employee>("Андрей Иванов", "Механик");
    auto employee2 = std::make_shared<Employee>("Сергей Петров", "Маляр");
    auto employee3 = std::make_shared<Employee>("Дмитрий Сидоров", "Детейлер");

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

    std::cout << "\n=== Задача 1: Список услуг с ценами ===" << std::endl;
    std::cout << manager.getServicesList() << std::endl;

    std::cout << "\n=== Задача 2: Список автомобилей в сервисе ===" << std::endl;
    std::cout << manager.getCarsList() << std::endl;

    std::cout << "\n=== Задача 3: Информация об автомобиле ===" << std::endl;
    std::cout << manager.getCarInfo("ABC123") << std::endl;

    std::cout << "\n=== Задача 4: Отчёт по сотруднику (последние 7 дней) ===" << std::endl;
    std::time_t startDate = now - 7 * 86400;
    std::time_t endDate = now;
    std::cout << manager.getEmployeeWorkReport("Андрей Иванов", startDate, endDate) << std::endl;

    std::cout << "\n=== Задача 5: Расчёт стоимости для клиентов ===" << std::endl;
    double cost1 = manager.calculateClientCost("Иван Петров");
    double cost2 = manager.calculateClientCost("Мария Смирнова");
    
    std::cout << "Клиент: Иван Петров (постоянный - скидка 10%)" << std::endl;
    std::cout << "Итоговая стоимость: " << cost1 << std::endl;
    std::cout << "\nКлиент: Мария Смирнова (без скидки)" << std::endl;
    std::cout << "Итоговая стоимость: " << cost2 << std::endl;

    std::cout << "\nНажмите Enter для выхода...";
    std::cin.get();

    return 0;
}

