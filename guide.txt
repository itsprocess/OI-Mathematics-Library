# Open Unit Interval (OI) Mathematics Library - Full Guide

## Introduction

The **Open Unit Interval (OI) Mathematics Library** is designed to represent and manipulate values strictly within the open interval `(0, 1)`. This guide provides an in-depth look at each function available in the library, detailing their definitions, purposes, and practical examples of how they can be used. This document is intended to be language-agnostic, covering implementations for both the C++ Unreal Engine and C# Unity versions of the library.

## Core Concept of OI Numbers

OI numbers are values strictly between 0 and 1, excluding both boundaries. They are designed to represent **gradual, balanced, and naturally constrained values** that do not reach extremes. This characteristic is particularly useful in game development and simulations, where properties like growth rates, skill levels, or resource availability need to be modeled in a way that maintains consistency and avoids unrealistic outcomes.

The library provides several fundamental operations to manipulate OI numbers while ensuring they remain within this range.

## Functions Overview

### 1. Constructor: `OINumber(double initialValue)`
- **Purpose**: Initializes an OI number with a specified value between `(0, 1)`. If the input value is outside this range, it is constrained to remain between `(vsn, 1-vsn)`, where `vsn` is a very small value to prevent the boundaries from being reached.
- **Practical Use**: This ensures that properties modeled using OI numbers do not reach unrealistic extremes.
  ```csharp
  OINumber skill = new OINumber(0.75);
  ```
  ```cpp
  UOI* skill = NewObject<UOI>();
  skill->Value = skill->ToOI(0.75);
  ```

### 2. `ToOI(double n)`
- **Purpose**: Converts a number into an OI number by constraining it within the range `(vsn, 1-vsn)`.
- **Practical Use**: This function helps in converting any input into a valid OI number.
  ```csharp
  double constrainedValue = OINumber.ToOI(1.5); // Output: 0.999999
  ```
  ```cpp
  double constrainedValue = UOI::ToOI(1.5); // Output: 0.999999
  ```

### 3. `Invert()`
- **Purpose**: Returns the inverted value of an OI number, calculated as `1 - value`.
- **Practical Use**: Useful for modeling complementary behaviors, such as availability versus scarcity.
  ```csharp
  OINumber scarcity = skill.Invert();
  ```
  ```cpp
  double scarcity = skill->Invert(skill->Value);
  ```

### 4. `Scale(OINumber mod)`
- **Purpose**: Scales an OI number by multiplying it with another OI number, ensuring the result remains in the OI range.
- **Practical Use**: Represents the combined effect of two interacting properties, such as skill and tool effectiveness.
  ```csharp
  OINumber finalQuality = skill.Scale(new OINumber(0.8));
  ```
  ```cpp
  double finalQuality = skill->Scale(skill->Value, 0.8);
  ```

### 5. `InvertedScale(OINumber mod)`
- **Purpose**: Applies a scaling effect using the inverted value of both the current OI number and the modifier.
- **Practical Use**: Useful for modeling interactions where the combined effect reduces the overall value, such as diminishing returns.
  ```csharp
  OINumber reducedQuality = skill.InvertedScale(new OINumber(0.5));
  ```
  ```cpp
  double reducedQuality = skill->InvertedScale(skill->Value, 0.5);
  ```

### 6. `SigmoidPush(OINumber mod)`
- **Purpose**: Applies a sigmoid transformation to push the value closer to or further from `1` based on the modifier.
- **Practical Use**: Represents gradual progression or resistance to change, useful for modeling skill mastery or learning curves.
  ```csharp
  OINumber updatedSkill = skill.SigmoidPush(new OINumber(0.3));
  ```
  ```cpp
  double updatedSkill = skill->SigmoidPush(skill->Value, 0.3);
  ```

### 7. `Grow(OINumber mod)`
- **Purpose**: Grows the current OI value by a modifier, pushing it closer to `1`.
- **Practical Use**: Models growth or improvement, such as skill progression or resource increase.
  ```csharp
  OINumber improvedSkill = skill.Grow(new OINumber(0.2));
  ```
  ```cpp
  double improvedSkill = skill->Grow(skill->Value, 0.2);
  ```

### 8. `Decay(OINumber mod)`
- **Purpose**: Decays the current OI value by a modifier, pushing it towards `vsn`.
- **Practical Use**: Represents decay or decline, such as resource depletion or skill deterioration.
  ```csharp
  OINumber decayedSkill = skill.Decay(new OINumber(0.1));
  ```
  ```cpp
  double decayedSkill = skill->Decay(skill->Value, 0.1);
  ```

### 9. `RandomOI()`
- **Purpose**: Generates a random OI number strictly within the `(vsn, 1-vsn)` range.
- **Practical Use**: Useful for introducing randomness in procedural generation without exceeding the OI bounds.
  ```csharp
  OINumber randomValue = OINumber.RandomOI();
  ```
  ```cpp
  double randomValue = UOI::RandomOI();
  ```

### 10. `FromInt32(int i)`
- **Purpose**: Converts an integer to an OI number using a sigmoid transformation.
- **Practical Use**: Useful for mapping discrete values, like levels or experience, to a continuous OI range.
  ```csharp
  OINumber levelValue = OINumber.FromInt32(5);
  ```
  ```cpp
  double levelValue = UOI::FromInt32(5);
  ```

### 11. `QuantumOI(double random, OINumber expectation, OINumber upperConfidence, OINumber lowerConfidence, int scale)`
- **Purpose**: Generates a probabilistic OI value based on expectation, confidence levels, and randomness.
- **Practical Use**: Models uncertain outcomes in a way that is influenced by confidence and expectation, providing a weighted randomness.
  ```csharp
  OINumber probability = OINumber.QuantumOI(0.6, new OINumber(0.7), new OINumber(0.8), new OINumber(0.5), 2);
  ```
  ```cpp
  double probability = UOI::QuantumOI(0.6, 0.7, 0.8, 0.5, 2);
  ```

### 12. `AccuracyCurve(double random, OINumber confidence)`
- **Purpose**: Generates an accuracy value based on a random input and confidence level, constrained within the OI range.
- **Practical Use**: Represents accuracy or precision relative to a confidence value, useful in decision-making models.
  ```csharp
  OINumber accuracy = OINumber.AccuracyCurve(0.5, new OINumber(0.9));
  ```
  ```cpp
  double accuracy = UOI::AccuracyCurve(0.5, 0.9);
  ```

### 13. `NthRoot(double x, double n)` (Utility Function)
- **Purpose**: Calculates the nth root of a number.
- **Practical Use**: Used internally in other functions to apply non-linear transformations.
  ```csharp
  double rootValue = OINumber.NthRoot(16, 2); // Outputs: 4
  ```
  ```cpp
  double rootValue = nthRoot(16, 2); // Outputs: 4
  ```

## Conclusion

The **OI Mathematics Library** provides a robust framework for modeling bounded, realistic values that evolve in a consistent way. Whether you are developing a game, building a simulation, or exploring procedural generation, this library offers a set of tools to manage growth, decay, scaling, and randomness without exceeding the `(0, 1)` interval. The provided functions act as building blocks for complex, interconnected systems, ensuring that values remain stable, balanced, and naturally constrained.

