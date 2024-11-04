using System;

namespace OIMathLibrary
{
    /// <summary>
    /// Represents an Open Unit Interval (OI) number between 0 and 1 (exclusive).
    /// Provides methods for operations that ensure results stay within the OI range.
    /// </summary>
    public class OINumber
    {
        private const double vsn = 1e-6;
        public double Value { get; private set; }

        /// <summary>
        /// Initializes a new instance of the OINumber class with a specified value.
        /// </summary>
        public OINumber(double initialValue)
        {
            Value = ToOI(initialValue);
        }

        /// <summary>
        /// Converts a number to an OI number, ensuring it stays within (vsn, 1-vsn).
        /// </summary>
        public static double ToOI(double n)
        {
            if (n < vsn) return vsn;
            if (n > 1 - vsn) return 1 - vsn;
            return n;
        }

        /// <summary>
        /// Returns the inverted value of the current OI number.
        /// </summary>
        public OINumber Invert()
        {
            return new OINumber(1 - Value);
        }

        /// <summary>
        /// Scales two OI numbers and ensures the result stays in the OI range.
        /// </summary>
        public OINumber Scale(OINumber mod)
        {
            return new OINumber(Value * mod.Value);
        }

        /// <summary>
        /// Scales two OI numbers using inversion.
        /// </summary>
        public OINumber InvertedScale(OINumber mod)
        {
            return new OINumber(1 - ((1 - Value) * (1 - mod.Value)));
        }

        /// <summary>
        /// Applies a Sigmoid push to the value based on a modifier.
        /// </summary>
        public OINumber SigmoidPush(OINumber mod)
        {
            return new OINumber(Math.Pow(Value, 1.0 / (1.0 + SafeSigmoid(mod.Value))));
        }

        /// <summary>
        /// Grows the value by a modifier, pushing towards 1.
        /// </summary>
        public OINumber Grow(OINumber mod)
        {
            return new OINumber(Math.Pow(Value, 1.0 / Invert().Value));
        }

        /// <summary>
        /// Decays the value by a modifier, pushing towards vsn.
        /// </summary>
        public OINumber Decay(OINumber mod)
        {
            return new OINumber(Math.Pow(Value, Invert().Value));
        }

        /// <summary>
        /// Generates a random OI number.
        /// </summary>
        public static OINumber RandomOI()
        {
            Random random = new Random();
            double randomValue = random.NextDouble() * (1 - 2 * vsn) + vsn;
            return new OINumber(randomValue);
        }

        /// <summary>
        /// Generates an OI number from an integer using a safe sigmoid function.
        /// </summary>
        public static OINumber FromInt32(int i)
        {
            double value = 1 / (1 + Math.Exp(-vsn * i));
            return new OINumber(value);
        }

        /// <summary>
        /// Applies a safe sigmoid function to a number.
        /// </summary>
        public static double SafeSigmoid(double n)
        {
            if (n < -1 + vsn) return -1 + vsn;
            if (n > 1 - vsn) return 1 - vsn;
            return n;
        }

        /// <summary>
        /// Applies the Quantum function to generate a probabilistic OI value.
        /// </summary>
        public static OINumber QuantumOI(double random, OINumber expectation, OINumber upperConfidence, OINumber lowerConfidence, int scale)
        {
            int s = Math.Abs(scale);
            double numerator = 1.0;
            double denominator = -NthRoot(1 - ToOI(random), 2 * upperConfidence.Value * s + 1) + NthRoot(ToOI(random), 2 * lowerConfidence.Value * s + 1) + 1;
            double v = Math.Pow(expectation.Value, numerator / denominator);

            return new OINumber(v);
        }

        /// <summary>
        /// Generates an accuracy curve based on random input and confidence level.
        /// </summary>
        public static OINumber AccuracyCurve(double random, OINumber confidence)
        {
            double r = ToOI(random);
            double c = confidence.Value;
            double result = Math.Pow(c, (1.0 / (2.0 * r))) * (1.0 / Math.Sqrt(c));

            return new OINumber(result);
        }

        /// <summary>
        /// Utility function to calculate the nth root of a number.
        /// </summary>
        private static double NthRoot(double x, double n)
        {
            return Math.Pow(x, 1.0 / n);
        }
    }
}
