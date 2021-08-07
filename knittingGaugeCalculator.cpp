#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

float convert(float userGauge, float patternGauge)
{
    float stitchGauge = userGauge / patternGauge;
    float value = (int)(stitchGauge * 100 + .5);
    return (float)value / 100;
}

void newStitch()
{
    float userGauge = 0;
    float patternGauge = 0;
    float castOn = 0;
    cout << "Enter Pattern Gauge | # of stiches per 4 in/10cm" << endl;
    cin >> patternGauge;
    cout << "Enter your Gauge | # of stitches per 4 in/10cm" << endl;
    cin >> userGauge;
    cout << "Enter the # of cast on stitches the pattern calls for: " << endl;
    cin >> castOn;
    float newGauge = convert(userGauge, patternGauge);
    float newStitches = newGauge * castOn;
    cout << "New # of Cast On Stitches " << round(newStitches) << endl;
}

void newNeedle()
{
    float inch = 0;
    float patternGauge = 0;
    float needleSize = 0;
    cout << "Measure the width of thirty stitches in your swatch." << endl;
    cout << "Enter the width (in inches)" << endl;
    cin >> inch;
    cout << "Enter Pattern Gauge" << endl;
    cin >> patternGauge;
    cout << "Enter needle size used to knit swatch" << endl;
    cin >> needleSize;

    float calc = (30 / inch) * 4;

    if (calc > patternGauge)
    {
        while (calc > patternGauge)
        {
            needleSize++;
            inch += 0.5;
            calc = (30 / inch) * 4;
        }
    }
    else if (calc < patternGauge)
    {
        while (calc < patternGauge)
        {
            needleSize--;
            inch -= 0.5;
            calc = (30 / inch) * 4;
        }
    }

    cout << "Use Needle Size " << needleSize << " to get gauge of " << round(calc) << endl;
}

int main()
{
    int option;
    cout << "Knitting Gauge Calculator" << endl;
    cout << "--Select an Option--" << endl;
    cout << "1. Adjust cast on stitches" << endl;
    cout << "2. Adjust needle size (use 30 stitch magic swatch)" << endl;
    cin >> option;
    if (option < 1 && option > 2)
    {
        cout << "Invalid option" << endl;
    }
    if (option == 1)
    {
        newStitch();
    }
    else if (option == 2)
    {
        newNeedle();
    }
}