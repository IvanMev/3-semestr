#include "Employee.h"
#include <sstream>
#include <algorithm>
#include <ctime>

namespace CarService {

    Employee::Employee(const std::string& name, const std::string& specialization)
        : name(name), specialization(specialization) {
    }

    std::string Employee::getName() const {
        return name;
    }

    std::string Employee::getSpecialization() const {
        return specialization;
    }

    void Employee::addWorkRecord(std::shared_ptr<Car> car, std::shared_ptr<Service> service, std::time_t date, double hours) {
        WorkRecord record;
        record.car = car;
        record.service = service;
        record.workDate = date;
        record.hoursWorked = hours;
        workRecords.push_back(record);
    }

    std::vector<WorkRecord> Employee::getWorkRecords() const {
        return workRecords;
    }

    std::vector<WorkRecord> Employee::getWorkRecordsForPeriod(std::time_t startDate, std::time_t endDate) const {
        std::vector<WorkRecord> result;
        for (const auto& record : workRecords) {
            if (record.workDate >= startDate && record.workDate <= endDate) {
                result.push_back(record);
            }
        }
        return result;
    }

    int Employee::getCarsServicedCount(std::time_t startDate, std::time_t endDate) const {
        auto records = getWorkRecordsForPeriod(startDate, endDate);
        return static_cast<int>(records.size());
    }

    double Employee::getTotalHoursWorked(std::time_t startDate, std::time_t endDate) const {
        auto records = getWorkRecordsForPeriod(startDate, endDate);
        double total = 0.0;
        for (const auto& record : records) {
            total += record.hoursWorked;
        }
        return total;
    }

    std::string Employee::getWorkReport(std::time_t startDate, std::time_t endDate) const {
        std::ostringstream oss;
        auto records = getWorkRecordsForPeriod(startDate, endDate);
        
        char startDateStr[26];
        char endDateStr[26];
        ctime_s(startDateStr, sizeof(startDateStr), &startDate);
        ctime_s(endDateStr, sizeof(endDateStr), &endDate);
        
        oss << "Сотрудник: " << name << " (Специализация: " << specialization << ")\n";
        oss << "Период: " << startDateStr << " по " << endDateStr;
        oss << "Авто обслужено: " << records.size() << "\n";
        oss << "Всего часов: " << getTotalHoursWorked(startDate, endDate) << "\n";
        oss << "Детали работ:\n";
        
        for (const auto& record : records) {
            oss << "  - Авто: " << record.car->getInfo() 
                << ", Услуга: " << record.service->getName()
                << ", Часы: " << record.hoursWorked << "\n";
        }
        
        return oss.str();
    }

    std::vector<std::shared_ptr<Employee>> Employee::createTestEmployees(
        const std::vector<std::shared_ptr<Car>>& cars,
        const std::vector<std::shared_ptr<Service>>& services) {
        
        std::vector<std::shared_ptr<Employee>> testEmployees;
        
        auto employee1 = std::make_shared<Employee>("Андрей Иванов", "Механик");
        auto employee2 = std::make_shared<Employee>("Сергей Петров", "Маляр");
        auto employee3 = std::make_shared<Employee>("Дмитрий Сидоров", "Детейлер");
        
        std::time_t now = std::time(nullptr);
        std::time_t yesterday = now - 86400;
        std::time_t lastWeek = now - 7 * 86400;
        
        if (cars.size() > 0 && services.size() > 0) {
            employee1->addWorkRecord(cars[0], services[0], yesterday, 4.5);
        }
        if (cars.size() > 0 && services.size() > 1) {
            employee1->addWorkRecord(cars[0], services[1], yesterday, 2.0);
        }
        
        if (cars.size() > 1 && services.size() > 2) {
            employee2->addWorkRecord(cars[1], services[2], lastWeek, 6.0);
        }
        
        if (cars.size() > 2 && services.size() > 5) {
            employee3->addWorkRecord(cars[2], services[5], now, 3.0);
        }
        
        testEmployees.push_back(employee1);
        testEmployees.push_back(employee2);
        testEmployees.push_back(employee3);
        
        return testEmployees;
    }

}

