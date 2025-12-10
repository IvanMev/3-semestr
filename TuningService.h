#pragma once

#include "Service.h"
#include <string>

namespace CarService {

    class TuningService : public Service {
    public:
        TuningService(const std::string& name, double price, const std::string& tuningCategory);
        virtual ~TuningService() = default;

        std::string getDescription() const override;
        std::string getServiceType() const override;

        std::string getTuningCategory() const;

    private:
        std::string tuningCategory;
    };

}

