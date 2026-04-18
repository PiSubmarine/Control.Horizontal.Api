#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/Horizontal/Api/IController.h"

namespace PiSubmarine::Control::Horizontal::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetTarget, (const Command& target), (override));
    };
}
