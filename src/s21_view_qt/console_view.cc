#include "console_view.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void ConsoleView::displayMenu()
{
    std::cout << "=========" << std::endl;
    std::cout << " M E N U " << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "1. 8 + x" << std::endl;
    std::cout << "2. 8 - x" << std::endl;
    std::cout << "3. 8 * x" << std::endl;
    std::cout << "4. 8 / x" << std::endl;
    std::cout << "5. Reset a number" << std::endl;
    std::cout << "0. Quit" << std::endl << std::endl;
}

int ConsoleView::performChoice()
{
    int choice;
    std::cout << "Input a menu item digit: ";
    std::cin >> choice;
    return choice;
} 

double ConsoleView::performNumericInput()
{    
    double number;
    std::cout << "Input a decimal number: ";
    std::cin >> number;
    return number;
} 

void ConsoleView::startEventLoop()
{
    while (true) 
    {
        double result;
        displayMenu();
        switch ((Choice)performChoice())
        {
        case SUM:
            result = calc_controller->StartCalc("8+X", performNumericInput());
            break;
        
        case SUB:
            result = calc_controller->StartCalc("8-X", performNumericInput());
            break;

        case MUL:
            result = calc_controller->StartCalc("8*X", performNumericInput());
            break;

        case DIV:
            result = calc_controller->StartCalc("8/X", performNumericInput());
            break;

        case RES:
            calc_controller->Reset();
            result = 0.0;
            break;

        case EXIT:
            exit(0);

        default:
            std::cout << "Wrong menu item number!";
            continue;
        }

        std::cout << "Current result is: " << result << std::endl;
    }
}
