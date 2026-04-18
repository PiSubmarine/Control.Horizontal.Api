# Control.Horizontal.Api

`PiSubmarine.Control.Horizontal.Api` defines the low-level horizontal movement control boundary.

## Responsibility

An `IController` implementation is responsible for:

- accepting a validated horizontal target in the form of `Control::Horizontal::Api::Command`

The interface is intentionally narrow so that concrete implementations remain free to choose their own strategy, for example:

- direct arcade-style thruster mixing
- closed-loop heading stabilization
- trajectory tracking based on additional telemetry

## Non-responsibilities

`IController` does not expose transport concerns, ticking mechanics, or raw actuator wiring.

If a concrete controller needs ticking, it may additionally implement `Time::ITickable`, but that capability is intentionally kept outside this API boundary.

Concrete implementations are expected to use composition for dependencies such as:

- telemetry/state providers
- thruster actuator interfaces
- estimator or stabilization components
