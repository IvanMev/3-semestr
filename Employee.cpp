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

}

