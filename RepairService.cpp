#include "RepairService.h"

namespace CarService {

    RepairService::RepairService(const std::string& name, double price, const std::string& repairType)
        : Service(name, price), repairType(repairType) {
    }

    std::string RepairService::getDescription() const {
        return "Услуга ремонта: " + name + " (Тип: " + repairType + ", Цена: " + std::to_string(price) + ")";
    }

    std::string RepairService::getServiceType() const {
        return "Ремонт";
    }

    std::string RepairService::getRepairType() const {
        return repairType;
    }

}

