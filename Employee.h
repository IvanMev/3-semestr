#pragma once

#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include "Car.h"
#include "Service.h"

namespace CarService {

    struct WorkRecord {
        std::shared_ptr<Car> car;
        std::shared_ptr<Service> service;
        std::time_t workDate;
        double hoursWorked;
    };

    class Employee {
    public:
        Employee(const std::string& name, const std::string& specialization);
        
        std::string getName() const;
        std::string getSpecialization() const;
        
        void addWorkRecord(std::shared_ptr<Car> car, std::shared_ptr<Service> service, std::time_t date, double hours);
        std::vector<WorkRecord> getWorkRecords() const;
        
        std::vector<WorkRecord> getWorkRecordsForPeriod(std::time_t startDate, std::time_t endDate) const;
        int getCarsServicedCount(std::time_t startDate, std::time_t endDate) const;
        double getTotalHoursWorked(std::time_t startDate, std::time_t endDate) const;
        
        std::string getWorkReport(std::time_t startDate, std::time_t endDate) const;

    private:
        std::string name;
        std::string specialization;
        std::vector<WorkRecord> workRecords;
    };

}

