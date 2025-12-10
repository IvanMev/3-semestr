#pragma once

#include "Service.h"
#include <string>

namespace CarService {

    class RepairService : public Service {
    public:
        RepairService(const std::string& name, double price, const std::string& repairType);
        virtual ~RepairService() = default;

        std::string getDescription() const override;
        std::string getServiceType() const override;

        std::string getRepairType() const;

    private:
        std::string repairType;
    };

}

