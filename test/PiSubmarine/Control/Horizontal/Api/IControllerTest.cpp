#include <gtest/gtest.h>

#include "PiSubmarine/Control/Horizontal/Api/IController.h"

namespace PiSubmarine::Control::Horizontal::Api
{
    TEST(IControllerTest, HasVirtualDestructor)
    {
        static_assert(std::has_virtual_destructor_v<IController>);
        SUCCEED();
    }
}
