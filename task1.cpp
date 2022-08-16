#include <Arduino.h>
#include "task1.h"

static void switchVariables(uint32_t *pdata, uint32_t *pdata2)
{
    uint32_t prueba;
    prueba = *pdata;
    *pdata = *pdata2;
    *pdata2 = prueba;
}

static void printVar(const char *varName, uint32_t value)
{
    printf("%s = %d\n", varName, value);
}

void task1()
{
    enum class Task1States
    {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
        // evento 1:
        if (Serial.available() > 0)
        {
            int datarx = Serial.read();

                uint32_t a = 10;
                uint32_t b = 20;
                printVar("a", a);
                printVar("b", b);
                switchVariables(&a, &b);
                printVar("a", a);
                printVar("b", b);

        }
        break;
    }

    default:
    {
        break;
    }
    }
}