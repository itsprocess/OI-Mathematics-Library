# Open Unit Interval (OI) Mathematics Library - README

## What is the OI Mathematics Library?

The **Open Unit Interval (OI) Mathematics Library** is a tool designed to represent and manipulate values strictly within the open interval `(0, 1)` (exclusive of 0 and 1). This library provides a set of functions for working with **OI numbers**, ensuring that all operations remain bounded, realistic, and consistent within this range. By defining all properties within `(0, 1)`, OI Mathematics provides a structured approach to modeling attributes such as growth, decay, randomness, and balance without ever exceeding the boundaries.

The OI Mathematics Library is particularly useful for developers working on procedural generation, games, or simulations where values like skill levels, resource quality, or probability need to evolve in a balanced and natural manner.

## Why Use OI Numbers?

In traditional systems, many values (such as skill, health, or quality) are represented on arbitrary scales, which can lead to **unbounded growth**, **arbitrary scaling**, and **imbalances**. OI Mathematics addresses these challenges by:

- **Keeping Values Balanced**: OI numbers remain between 0 and 1, preventing extreme values and promoting stability.
- **Modeling Natural Behaviors**: The provided operations—such as scaling, growth, decay, and the Quantum distribution—allow developers to model real-world phenomena in a way that naturally avoids runaway effects or imbalances.
- **Ensuring Realistic Interactions**: Each interaction involving OI numbers results in a value that remains in the open interval `(0, 1)`, reflecting diminishing returns, inherent limitations, and natural balances.

This library provides a consistent framework that enables emergent behaviors and realistic progression without the need for arbitrary adjustments or unrealistic extremes.

## Key Features

- **Multiplication and Scaling**: Combine OI numbers to represent interactions between properties while ensuring the results stay within bounds.
- **Inversion**: Obtain the complementary value of an OI number, useful for modeling opposing forces or attributes.
- **Growth and Decay**: Use growth and decay functions to simulate advancement or regression with diminishing returns as the value approaches 1 or near-zero.
- **Quantum Distribution Function**: Generate probabilistic OI values that reflect the expected outcome while allowing variability, making randomness weighted and more controlled.
- **Random OI Generation**: Generate random numbers strictly within the OI range for use in procedural or randomized systems.

## Example Use Cases

- **Game Development**: Model skill progression, crafting quality, or resource availability using OI numbers to ensure balanced progression without overpowered extremes.
- **Simulations**: Represent population growth, environmental changes, or resource decay in a way that naturally limits runaway effects, creating realistic and stable simulations.
- **Procedural Generation**: Use OI numbers as the foundation for generating balanced properties or probabilistic outcomes that evolve naturally over time.

## Getting Started
To get started, include the **OI Mathematics Library** in your Unity project and begin by creating OI numbers:

```csharp
OINumber skill = new OINumber(0.75);
OINumber practiceFactor = new OINumber(0.3);
OINumber improvedSkill = skill.Grow(practiceFactor);
Console.WriteLine(improvedSkill.Value); // Output remains within (0, 1)
```

For more detailed documentation and examples, please refer to the **Full Guide** or explore the functions in the library directly.

## License
This library is open source and available under the MIT License.

