#pragma once

#include "PiSubmarine/Control/Horizontal/Api/ErrorCode.h"
#include "PiSubmarine/Error/Api/ErrorCondition.h"
#include "PiSubmarine/Error/Api/MakeError.h"
#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/SignedNormalizedFraction.h"

namespace PiSubmarine::Control::Horizontal::Api
{
    class Command
    {
    public:
        [[nodiscard]] static constexpr Error::Api::Result<Command> Create(
            const SignedNormalizedFraction surge,
            const SignedNormalizedFraction yaw) noexcept
        {
            const double surgeValue = surge;
            const double yawValue = yaw;

            if ((surgeValue * surgeValue) + (yawValue * yawValue) > 1.0)
            {
                return std::unexpected(Error::Api::MakeError(
                    Error::Api::ErrorCondition::ContractError,
                    make_error_code(ErrorCode::MagnitudeExceeded)));
            }

            return Command(surge, yaw);
        }

        [[nodiscard]] constexpr SignedNormalizedFraction Surge() const noexcept
        {
            return m_Surge;
        }

        [[nodiscard]] constexpr SignedNormalizedFraction Yaw() const noexcept
        {
            return m_Yaw;
        }

        [[nodiscard]] constexpr bool operator==(const Command&) const = default;

    private:
        constexpr Command(
            const SignedNormalizedFraction surge,
            const SignedNormalizedFraction yaw) noexcept
            : m_Surge(surge),
              m_Yaw(yaw)
        {
        }

        SignedNormalizedFraction m_Surge;
        SignedNormalizedFraction m_Yaw;
    };
}
