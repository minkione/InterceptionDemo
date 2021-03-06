// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\CalculatorsSvr\CalculatorsSvr_i.h"


int main() {
	::CoInitialize(nullptr);

	CComPtr<ICalculatorFactory> spFactory;
	auto hr = spFactory.CoCreateInstance(__uuidof(CalculatorFactory));
	if (SUCCEEDED(hr)) {
		CComPtr<ICalculator> spCalculator;
		hr = spFactory->CreateCalculator(&spCalculator);
		if (SUCCEEDED(hr)) {
			double result;
			spCalculator->Add(3, 4, &result);
			printf("3 + 4 = %f\n", result);

			spCalculator->put_Radians(VARIANT_FALSE);
			spCalculator->Sin(30, &result);
			printf("Sin(30 degrees): %f\n", result);

			spCalculator->put_Radians(VARIANT_TRUE);
			spCalculator->Sin(30, &result);
			printf("Sin(30 radians): %f\n", result);

		}
	}

	return 0;
}

