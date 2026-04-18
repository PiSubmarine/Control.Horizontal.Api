#include "PiSubmarine/Control/Horizontal/Api/ErrorCode.h"

namespace PiSubmarine::Control::Horizontal::Api
{
    namespace
    {
        class ErrorCategory final : public std::error_category
        {
        public:
            [[nodiscard]] const char* name() const noexcept override
            {
                return "PiSubmarine.Control.Horizontal.Api";
            }

            [[nodiscard]] std::string message(const int condition) const override
            {
                switch (static_cast<ErrorCode>(condition))
                {
                case ErrorCode::MagnitudeExceeded:
                    return "horizontal command must lie within the unit circle";
                }

                return "unknown control horizontal api error";
            }
        };

        [[nodiscard]] const std::error_category& GetErrorCategory() noexcept
        {
            static const ErrorCategory Category;
            return Category;
        }
    }

    [[nodiscard]] std::error_code make_error_code(const ErrorCode errorCode) noexcept
    {
        return {static_cast<int>(errorCode), GetErrorCategory()};
    }
}
