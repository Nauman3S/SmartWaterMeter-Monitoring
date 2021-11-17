#include <OneButton.h>

int IOPins[11] = {12, 19, 18, 5, 25, 26, 4, 15, 27, 14};
int Gallons[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
OneButton btn[11];
void hc1()
{
    int oldGallons = Gallons[0];
    int newGallons = oldGallons + 1;
    Gallons[0] = newGallons;
    Serial.println("GPIO12 Long Press Stop");
    Serial.print("Gallon[0]=");
    Serial.println(Gallons[0]);
}
void hc2()
{
    int oldGallons = Gallons[1];
    int newGallons = oldGallons + 1;
    Gallons[1] = newGallons;
}
void hc3()
{
    int oldGallons = Gallons[2];
    int newGallons = oldGallons + 1;
    Gallons[2] = newGallons;
}
void hc4()
{
    int oldGallons = Gallons[3];
    int newGallons = oldGallons + 1;
    Gallons[3] = newGallons;
}
void hc5()
{
    int oldGallons = Gallons[4];
    int newGallons = oldGallons + 1;
    Gallons[4] = newGallons;
}
void hc6()
{
    int oldGallons = Gallons[5];
    int newGallons = oldGallons + 1;
    Gallons[5] = newGallons;
}
void hc7()
{
    int oldGallons = Gallons[6];
    int newGallons = oldGallons + 1;
    Gallons[6] = newGallons;
}
void hc8()
{
    int oldGallons = Gallons[7];
    int newGallons = oldGallons + 1;
    Gallons[7] = newGallons;
}
void hc9()
{
    int oldGallons = Gallons[8];
    int newGallons = oldGallons + 1;
    Gallons[8] = newGallons;
}
void hc10()
{
    int oldGallons = Gallons[9];
    int newGallons = oldGallons + 1;
    Gallons[9] = newGallons;
}

// void (*func_ptr[11])() = {hc1, hc2, hc3, hc4, hc5, hc6, hc7, hc8, hc9, hc10};

void setupGPIO()
{
    for (int i = 0; i < 10; i++)
    {
        pinMode(IOPins[i], INPUT);
        btn[i] = OneButton(
            IOPins[i], // Input pin for the button
            true,      // Button is active LOW
            true       // Enable internal pull-up resistor
        );

        
        btn[i].setPressTicks(1000);
    }
    btn[0].attachLongPressStop(hc1);
    btn[1].attachLongPressStop(hc2);
    btn[2].attachLongPressStop(hc3);
    btn[3].attachLongPressStop(hc4);
    btn[4].attachLongPressStop(hc5);
    btn[5].attachLongPressStop(hc6);
    btn[6].attachLongPressStop(hc7);
    btn[7].attachLongPressStop(hc8);
    btn[8].attachLongPressStop(hc9);
    btn[9].attachLongPressStop(hc10);
}

void loopGPIO()
{

    for (int i = 0; i < 10; i++)
    {
        btn[i].tick();
    }
}

String getGPIOValues()
{
    String v = "";
    for (int i = 0; i < 10; i++)
    {
        v = v + String(Gallons[i]) + String(",");
    }
    return v;
}