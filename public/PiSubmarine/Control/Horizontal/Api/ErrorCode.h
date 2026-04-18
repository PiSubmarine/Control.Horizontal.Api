#pragma once

#include <system_error>

namespace PiSubmarine::Control::Horizontal::Api
{
    enum class ErrorCode
    {
        MagnitudeExceeded = 1
    };

    [[nodiscard]] std::error_code make_error_code(ErrorCode errorCode) noexcept;
}

namespace std
{
    template<>
    struct is_error_code_enum<PiSubmarine::Control::Horizontal::Api::ErrorCode> : true_type
    {
    };
}
