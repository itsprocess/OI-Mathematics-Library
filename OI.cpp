#include "OI.h"
#include <cmath>

// Function to calculate the nth root of a number
static double nthRoot(double x, double n) {
    return pow(x, 1.0 / n);
}

const double UOI::vsn = 0.000001;

double UOI::ToOI(double n)
{
    if (n < vsn)
    {
        return vsn;
    }
    if (n > 1 - vsn)
    {
        return 1 - vsn;
    }
    return n;
}

double UOI::Invert(double n)
{
    return 1 - ToOI(n);
}

double UOI::Scale(double source, double mod)
{
    return ToOI(source) * ToOI(mod);
}

double UOI::InvertedScale(double source, double mod)
{
    return Invert(Invert(source) * Invert(mod));
}

double UOI::SigmoidPush(double source, double mod)
{
    return pow(ToOI(source), 1.0 / 1 + SafeSigmoid(mod));
}

double UOI::Grow(double source, double mod)
{
    return pow(ToOI(source), Invert(mod));
}

double UOI::Decay(double source, double mod)
{
    return pow(ToOI(source), 1.0 / Invert(mod));
}

double UOI::RandomOI()
{
    float RandomFloat = FMath::FRand();
    double RandomDouble = static_cast<double>(RandomFloat);
    return RandomDouble * (1 - 2 * vsn) + vsn;
}

double UOI::ConstantOI(double n)
{
    return ToOI(n);
}

double UOI::FromInt32(int i)
{
    double d = 1 / (1 + exp(-vsn * (double)i));
    return ToOI(d);
}

double UOI::SafeSigmoid(double n)
{
    double t = n;
    if (n < -1 + vsn) t = -1 + vsn;
    if (n > 1 - vsn) t = 1 - vsn;
    return t;
}

double UOI::QuantumOI(double random, double expectation, double upperConfidence, double lowerConfidence, int scale)
{
    int s = abs(scale);
    double numerator = 1.0;
    double denominator = -nthRoot(1 - ToOI(random), 2 * ToOI(upperConfidence) * s + 1) + nthRoot(ToOI(random), 2 * ToOI(lowerConfidence) * s + 1) + 1;
    double v = pow(ToOI(expectation), numerator / denominator);

    return v;
}

double UOI::AccuracyCurve(double random, double confidence)
{
    double r = ToOI(random);
    double c = ToOI(confidence);
    double result = pow(c, (1.0 / (2.0 * r))) * (1.0 / sqrt(c));

    return result;
}
