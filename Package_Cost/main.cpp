#include <iostream>

int main()
{

    int length{}, width{}, height{};
    const double baseCost{2.50};

    const int tierOneThreshold{100};
    const int tierTwoThreshold{500};

    const int maxDimensionLength{10};

    const double tierOneSurcharge{0.10};
    const double tierTwoSurcharge{0.50};

    int packageVolume{};

    std::cout << "Welcome to the package cost calculator" << std::endl;
    std::cout << "Enter Length, Width and height of package separated by spaces: ";
    std::cin >> length >> width >> height;

    if (length > maxDimensionLength || width > maxDimensionLength || length > maxDimensionLength)
    {
        std::cout << "Sorry your package is rejected - Dimension exceeded" << std::endl;
    }
    else
    {
        double packageCost{};
        packageVolume = length * width * height;
        packageCost = baseCost;

        if (packageVolume > tierTwoThreshold)
        {
            packageCost += packageCost * tierTwoSurcharge;
            std::cout << "Adding tier 2 Surcharge" << std::endl;
        }
        else if (packageVolume > tierOneThreshold)
        {
            packageCost += packageCost * tierOneSurcharge;
            std::cout << "Adding tier 1 Surcharge" << std::endl;
        }

        std::cout << "The volume of your package is " << packageVolume << std::endl;
        std::cout << "Your package will cost $" << packageCost << " to ship." << std::endl;
    }

    return 0;
}