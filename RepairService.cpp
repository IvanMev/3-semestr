#include "RepairService.h"

namespace CarService {

    RepairService::RepairService(const std::string& name, double price, const std::string& repairType)
        : Service(name, price), repairType(repairType) {
    }

    std::string RepairService::getDescription() const {
        return "Repair Service: " + name + " (Type: " + repairType + ", Price: " + std::to_string(price) + ")";
    }

    std::string RepairService::getServiceType() const {
        return "Repair";
    }

    std::string RepairService::getRepairType() const {
        return repairType;
    }

}

