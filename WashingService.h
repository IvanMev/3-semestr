#pragma once

#include "Service.h"
#include <string>

namespace CarService {

    class WashingService : public Service {
    public:
        WashingService(const std::string& name, double price, bool isDryCleaning);
        virtual ~WashingService() = default;

        std::string getDescription() const override;
        std::string getServiceType() const override;

        bool isDryCleaningService() const;

    private:
        bool dryCleaning;
    };

}

