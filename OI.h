#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OI.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, ClassGroup = "Common", meta = (DisplayName = "OI Number"))
class OICORE_API UOI : public UObject
{
	GENERATED_BODY()	
private:
	static const double vsn;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OI Numbers")
	double Value;

public:
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double ConstantOI(double n);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double FromInt32(int i); 
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double SafeSigmoid(double i);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double ToOI(double n);

	UFUNCTION(BlueprintCallable, Category = "OI Numbers")
	static double RandomOI();
	UFUNCTION(BlueprintCallable, Category = "OI Numbers")
	static double QuantumOI(double linearRandom, double expectation, double upperConfidence, double lowerConfidence, int scale);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double AccuracyCurve(double linearRandom, double confidence);

	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double Invert(double n);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double Scale(double source, double mod);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double InvertedScale(double source, double mod);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double Grow(double source, double mod);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double Decay(double source, double mod);
	UFUNCTION(BlueprintPure, Category = "OI Numbers")
	static double SigmoidPush(double source, double mod);
	
};
