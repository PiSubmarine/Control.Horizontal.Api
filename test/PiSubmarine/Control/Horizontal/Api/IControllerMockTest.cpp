#include <gtest/gtest.h>

#include "PiSubmarine/Control/Horizontal/Api/IControllerMock.h"

namespace PiSubmarine::Control::Horizontal::Api
{
    TEST(IControllerMockTest, SupportsSettingHorizontalTarget)
    {
        IControllerMock controller;
        const auto target = Command::Create(0.5, -0.25).value();

        EXPECT_CALL(controller, SetTarget(target))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(controller.SetTarget(target).has_value());
    }
}
