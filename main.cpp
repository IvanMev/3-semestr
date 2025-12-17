#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include "CarServiceManager.h"

using namespace CarService;

int main() {
    CarServiceManager manager;
    manager.initializeTestData();

    auto services = manager.getAllServices();

    std::cout << "=== Коллекция услуг (демо полиморфизма) ===" << std::endl;
    for (size_t i = 0; i < services.size(); ++i) {
        std::cout << "Услуга " << (i + 1) << ": " << services[i]->getDescription() << std::endl;
        std::cout << "  Тип: " << services[i]->getServiceType() << std::endl;
        std::cout << "  Цена: " << services[i]->getPrice() << std::endl;
        std::cout << std::endl;
    }

    std::time_t now = std::time(nullptr);

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

