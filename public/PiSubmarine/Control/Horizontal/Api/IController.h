#pragma once

#include "PiSubmarine/Control/Api/Input/Horizontal.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Control::Horizontal::Api
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual Error::Api::Result<void> SetTarget(
            const Control::Api::Input::Horizontal& target) = 0;
    };
}
