#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function prototypes
// length functions
float metricLengthConvert(float num1, string currentUnits, string desiredUnits);
float imperialLengthConvert(float num1, string currentUnits, string desiredUnits);

// weight functions
float metricWeightConvert(float num1, string currentUnits, string desiredUnits);
float imperialWeightConvert(float num1, string currentUnits, string desiredUnits);

// temperature function
float temperatureConvert(float num1, string currentUnits);

int main() 
{
  float num1, num2;
  string currentUnits, desiredUnits;
  string conversionType;
  string currentSystem, desiredSystem;
  
  cout << "Welcome to the Unit Converter app! This app allows you to convert between various metric and imperial units." << endl;
  cout << "What type of conversion are you doing (length, weight, temperature)? ";
  cin >> conversionType;
  
  // ensures user inputs one of the available conversions
  while (conversionType != "length" && conversionType != "Length" && conversionType != "LENGTH" && conversionType != "weight" && conversionType != "Weight" && conversionType != "WEIGHT" && conversionType != "temperature" && conversionType != "Temperature" && conversionType != "TEMPERATURE")
    {
        cout << "Incorrect input. Please enter 'length', 'weight' or 'temperature'" << endl;
        cin.ignore();
        cin >> conversionType;
    }

  cout << "What measuring system are you starting with (metric or imperial)? ";
  cin >> currentSystem;

  // ensures user inputs metric or imperial
  while (currentSystem != "metric" && currentSystem != "Metric" && currentSystem != "METRIC" && currentSystem != "imperial" && currentSystem != "Imperial" && currentSystem != "IMPERIAL")
  {
    cout << "Incorrect input. Please enter 'metric' or 'imperial'." << endl;
    cin.ignore();
    cin >> currentSystem;
  }

  // if-else statement for length, weight, temperature
  if (conversionType == "length" || conversionType == "Length" || conversionType == "LENGTH")
  { 
    if(currentSystem == "metric" || currentSystem == "Metric" || currentSystem == "METRIC")
    {
      desiredSystem = "imperial";

      cout << "What units are you starting with (mm, cm, m, km)? ";
      cin >> currentUnits;

      // ensures user inputs available units
      while (currentUnits != "mm" && currentUnits != "cm" && currentUnits != "m" && currentUnits != "km")
      {
        cout << "Incorrect input. Please enter 'mm', 'cm', 'm', or 'km'." << endl;
        cin.ignore();
        cin >> currentUnits;
      }

      cout << "How many " << currentUnits << " do you have? ";
      cin >> num1;

      // ensures user inputs a number and prevents infinite loop
      while (cin.fail())
      {
        cout << "Incorrect input. Please enter a number." << endl;
        cin.clear();    // clears fail state
        cin.ignore();   // ignores previous bad input
        cin >> num1;
      }

      cout << "What units do you want (in, ft, yd, mi)? ";
      cin >> desiredUnits;

      // ensures user inputs available units
      while (desiredUnits != "in" && desiredUnits != "ft" && desiredUnits != "yd" && desiredUnits != "mi")
      {
        cout << "Incorrect input. Please enter 'in', 'ft', 'yd', or 'mi'." << endl;
        cin.ignore();
        cin >> desiredUnits;
      }

      num2 = metricLengthConvert(num1, currentUnits, desiredUnits);
    }
    else if (currentSystem == "imperial" || currentSystem == "Imperial" || currentSystem == "IMPERIAL")
    {
      desiredSystem = "metric";

      cout << "What units are you starting with (in, ft, yd, mi)? ";
      cin >> currentUnits;

      // ensures user inputs available units
      while (currentUnits != "in" && currentUnits != "ft" && currentUnits != "yd" && currentUnits != "mi")
      {
        cout << "Incorrect input. Please enter 'in', 'ft', 'yd', or 'mi'." << endl;
        cin.ignore();
        cin >> currentUnits;
      }
      
      cout << "How many " << currentUnits << " do you have? ";
      cin >> num1;

      // ensures user inputs a number and prevents infinite loop
      while (cin.fail())
      {
        cout << "Incorrect input. Please enter a number." << endl;
        cin.clear();    // clears fail state
        cin.ignore();   // ignores previous bad input
        cin >> num1;
      }

      cout << "What units do you want (mm, cm, m, km)? ";
      cin >> desiredUnits;

      // ensures user inputs available units
      while (desiredUnits != "mm" && desiredUnits != "cm" && desiredUnits != "m" && desiredUnits != "km")
      {
        cout << "Incorrect input. Please enter 'mm', 'cm', 'm', or 'km'." << endl;
        cin.ignore();
        cin >> desiredUnits;
      }

      num2 = imperialLengthConvert(num1, currentUnits, desiredUnits);
    }

  }
  else if (conversionType == "weight" || conversionType == "Weight" || conversionType == "WEIGHT")
  {
    if (currentSystem == "metric" || currentSystem == "Metric" || currentSystem == "METRIC")
    {
      desiredSystem = "imperial";

      cout << "What units are you starting with (mg, g, kg)? ";
      cin >> currentUnits;

      // ensures user inputs available units
      while (currentUnits != "mg" && currentUnits != "g" && currentUnits != "kg")
      {
        cout << "Incorrect input. Please enter 'mg', 'g', or 'kg'." << endl;
        cin.ignore();
        cin >> currentUnits;
      }

      cout << "How many " << currentUnits << " do you have? ";
      cin >> num1;

      // ensures user inputs a number and prevents infinite loop
      while (cin.fail())
      {
        cout << "Incorrect input. Please enter a number." << endl;
        cin.clear();    // clears fail state
        cin.ignore();   // ignores previous bad input
        cin >> num1;
      }

      cout << "What units do you want (oz, lb, ton)? ";
      cin >> desiredUnits;

      // ensures user inputs available units
      while (desiredUnits != "oz" && desiredUnits != "lb" && desiredUnits != "ton")
      {
        cout << "Incorrect input. Please enter 'oz', 'lb', or 'ton'." << endl;
        cin.ignore();
        cin >> desiredUnits;
      }

      num2 = metricWeightConvert(num1, currentUnits, desiredUnits);
    }
    else if (currentSystem == "imperial" || currentSystem == "Imperial" || currentSystem == "IMPERIAL")
    {
      desiredSystem = "metric";

      cout << "What units are you starting with (oz, lb, ton)? ";
      cin >> currentUnits;

      // ensures user inputs available units
      while (currentUnits != "oz" && currentUnits != "lb" && currentUnits != "ton")
      {
        cout << "Incorrect input. Please enter 'oz', 'lb', or 'ton'." << endl;
        cin.ignore();
        cin >> currentUnits;
      }

      cout << "How many " << currentUnits << " do you have? ";
      cin >> num1;

      // ensures user inputs a number and prevents infinite loop
      while (cin.fail())
      {
        cout << "Incorrect input. Please enter a number." << endl;
        cin.clear();    // clears fail state
        cin.ignore();   // ignores previous bad input
        cin >> num1;
      }

      cout << "What units do you want (mg, g, kg)? ";
      cin >> desiredUnits;

      // ensures user inputs available units
      while (desiredUnits != "mg" && desiredUnits != "g" && desiredUnits != "kg")
      {
        cout << "Incorrect input. Please enter 'mg', 'g', or 'kg'." << endl;
        cin.ignore();
        cin >> desiredUnits;
      }      

      num2 = imperialWeightConvert(num1, currentUnits, desiredUnits);
    }
  }
  else if (conversionType == "temperature" || conversionType == "Temperature" || conversionType == "TEMPERATURE")
  {
    if (currentSystem == "metric" || currentSystem == "Metric" || currentSystem == "METRIC")
    {
      currentUnits = "°C";
      desiredUnits = "°F";

      cout << "How much " << currentUnits << " do you have? ";
      cin >> num1;

      // ensures user inputs a number and prevents infinite loop
      while (cin.fail())
      {
        cout << "Incorrect input. Please enter a number." << endl;
        cin.clear();    // clears fail state
        cin.ignore();   // ignores previous bad input
        cin >> num1;
      }

      num2 = temperatureConvert(num1, currentUnits);
    }
    else if (currentSystem == "imperial" || currentSystem == "Imperial" || currentSystem == "IMPERIAL")
    {
      currentUnits = "°F";
      desiredUnits = "°C";

      cout << "How much " << currentUnits << " do you have? ";
      cin >> num1;

      // ensures user inputs a number and prevents infinite loop
      while (cin.fail())
      {
        cout << "Incorrect input. Please enter a number." << endl;
        cin.clear();    // clears fail state
        cin.ignore();   // ignores previous bad input
        cin >> num1;
      }

      num2 = temperatureConvert(num1, currentUnits);
    }
  }
  
  cout << num1 << currentUnits << " is equal to " << num2 << desiredUnits;
  
  return 0;
}

// function for converting metric length units to imperial length units
float metricLengthConvert(float num1, string currentUnits, string desiredUnits)
{
  float num2;

  if (currentUnits == "mm")
  {
    if (desiredUnits == "in")
    {
      num2 = num1 / 25.4;       // converts millimeters to inches
    }
    else if (desiredUnits == "ft")
    {
      num2 = num1 / 304.8;      // converts millimeters to feet
    }
    else if (desiredUnits == "yd")
    {
      num2 = num1 / 914.4;      // converts millimeters to yard
    }
    else if (desiredUnits == "mi")
    {
      num2 = num1 / 1609000.0;    // converts millimeters to miles
    }
  }
  else if (currentUnits == "cm")
  {
    if (desiredUnits == "in")
    {
      num2 = num1 / 2.54;       // converts centimeters to inches
    }
    else if (desiredUnits == "ft")
    {
      num2 = num1 / 30.48;      // converts centimeters to feet
    }
    else if (desiredUnits == "yd")
    {
      num2 = num1 / 91.44;      // converts centimeters to yards
    }
    else if (desiredUnits == "mi")
    {
      num2 = num1 / 160934.4;   // converts centimeters to miles
    }
  }
  else if (currentUnits == "m")
  {
    if (desiredUnits == "in")
    {
      num2 = num1 * 39.37;      // converts meters to inches
    }
    else if (desiredUnits == "ft")
    {
      num2 = num1 * 3.281;      // converts meters to feet
    }
    else if (desiredUnits == "yd")
    {
      num2 = num1 * 1.094;      // converts meters to yards
    }
    else if (desiredUnits == "mi")
    {
      num2 = num1 / 1609.344;   // converts meters to miles
    }
  }
  else if (currentUnits == "km")
  {
    if (desiredUnits == "in")
    {
      num2 = num1 * 39370.079;  // converts kilometers to inches
    }
    else if (desiredUnits == "ft")
    {
      num2 = num1 * 3280.84;    // converts kilometers to feet
    }
    else if (desiredUnits == "yd")
    {
      num2 = num1 * 1093.613;   // converts kilometers to yards
    }
    else if (desiredUnits == "mi")
    {
      num2 = num1 / 1.609;      // converts kilometers to miles
    }
  }
  return num2;
}

// function for converting imperial length units to metric length units
float imperialLengthConvert(float num1, string currentUnits, string desiredUnits)
{
  float num2;

  if (currentUnits == "in")
  {
    if (desiredUnits == "mm")
    {
      num2 = num1 * 25.4;       // converts inches to millimeters
    }
    else if (desiredUnits == "cm")
    {
      num2 = num1 * 2.54;       // converts inches to centimeters
    }
    else if (desiredUnits == "m")
    {
      num2 = num1 / 39.37;      // converts inches to meters
    }
    else if (desiredUnits == "km")
    {
      num2 = num1 / 39370.079;  // converts inches to kilometers
    }
  }
  else if (currentUnits == "ft")
  {
    if (desiredUnits == "mm")
    {
      num2 = num1 * 304.8;      // converts feet to millimeters
    }
    else if (desiredUnits == "cm")
    {
      num2 = num1 * 30.48;      // converts feet to centimeters
    }
    else if (desiredUnits == "m")
    {
      num2 = num1 / 3.281;      // converts feet to meters
    }
    else if (desiredUnits == "km")
    {
      num2 = num1 / 3280.84;    // converts feet to kilometers
    }
  }
  else if (currentUnits == "yd")
  {
    if (desiredUnits == "mm")
    {
      num2 = num1 * 914.4;      // converts yards to millimeters
    }
    else if (desiredUnits == "cm")
    {
      num2 = num1 * 91.44;      // converts yards to centimeters
    }
    else if (desiredUnits == "m")
    {
      num2 = num1 / 1.094;      // converts yards to meters
    }
    else if (desiredUnits == "km")
    {
      num2 = num1 / 1093.613;   // converts yards to kilometers
    }
  }
  else if (currentUnits == "mi")
  {
    if (desiredUnits == "mm")
    {
      num2 = num1 * 1609000.0;    // converts miles to millimeters
    }
    else if (desiredUnits == "cm")
    {
      num2 = num1 * 160934.4;   // converts miles to centimeters
    }
    else if (desiredUnits == "m")
    {
      num2 = num1 * 1609.344;   // converts miles to meters
    }
    else if (desiredUnits == "km")
    {
      num2 = num1 * 1.609;      // converts miles to kilometers
    }
  }
  return num2;
}

// function for converting metric weight units to imperial length units
float metricWeightConvert(float num1, string currentUnits, string desiredUnits)
{
  float num2;

  if (currentUnits == "mg")
  {
    if (desiredUnits == "oz")
    {
      num2 = num1 / 28349.523;    // converts milligrams to ounces
    }
    else if (desiredUnits == "lb")
    {
      num2 = num1 / 453592.37;    // converts milligrams to pounds
    }
    else if (desiredUnits == "ton")
    {
      num2 = num1 / 907200000.0;    // converts milligrams to tons
    }
  }
  else if (currentUnits == "g")
  {
    if (desiredUnits == "oz")
    {
      num2 = num1 / 28.35;        // converts grams to ounces
    }
    else if (desiredUnits == "lb")
    {
      num2 = num1 / 453.592;      // converts grams to pounds
    }
    else if (desiredUnits == "ton")
    {
      num2 = num1 / 907184.74;    // converts grams to tons
    }
  }
  else if (currentUnits == "kg")
  {
    if (desiredUnits == "oz")
    {
      num2 = num1 * 35.274;       // converts kilograms to ounces
    }
    else if (desiredUnits == "lb")
    {
      num2 = num1 * 2.205;        // converts kilograms to pounds
    }
    else if (desiredUnits == "ton")
    {
      num2 = num1 / 907.185;      // converts kilograms to tons
    }
  }
  return num2;
}

// function for converting imperial weight units to metric length units
float imperialWeightConvert(float num1, string currentUnits, string desiredUnits)
{
  float num2;

  if (currentUnits == "oz")
  {
    if (desiredUnits == "mg")
    {
      num2 = num1 * 28349.523;    // converts ounces to milligrams
    }
    else if (desiredUnits == "g")
    {
      num2 = num1 * 28.35;        // converts ounces to grams
    }
    else if (desiredUnits == "kg")
    {
      num2 = num1 / 35.274;       // converts ounces to kilograms
    }
  }
  else if (currentUnits == "lb")
  {
    if (desiredUnits == "mg")
    {
      num2 = num1 * 453592.37;    // converts pounds to milligrams
    }
    else if (desiredUnits == "g")
    {
      num2 = num1 * 453.592;      // converts pounds to grams
    }
    else if (desiredUnits == "kg")
    {
      num2 = num1 / 2.205;        // converts pounds to kilograms
    }
  }
  else if (currentUnits == "ton")
  {
    if (desiredUnits == "mg")
    {
      num2 = num1 * 907200000.0;    // converts tons to milligrams
    }
    else if (desiredUnits == "g")
    {
      num2 = num1 * 907184.74;    // converts tons to grams
    }
    else if (desiredUnits == "kg")
    {
      num2 = num1 * 907.185;      // converts tons to kilograms
    }
  }
  return num2;
}

// function for converting celsius to fahrenheit and vice versa
float temperatureConvert(float num1, string currentUnits)
{
  float num2;

  if (currentUnits == "°C")
  {
    num2 = (num1 * (9.0/5.0)) + 32;   // converts celsius to fahrenheit
  }
  else if (currentUnits == "°F")
  {
    num2 = (num1 - 32) * (5.0/9.0);   // converts fahrenheit to celsius
  }
  return num2;
}