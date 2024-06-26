#include <iostream>
#include <cstdlib>
#include <limits>
#include <windows.h>
#include <conio.h>

using namespace std;

// Variables for colors
#define AQUA 3
#define BLUE 9
#define GREEN 10
#define RED 12
#define BEIGE 14
#define WHITE 15

// Function declaration
void launchMenu();
void changeConsoleColor(int color);

int main() {
  
  launchMenu();

  return 0;
}

void launchMenu() {
  int choice;

  do {
    system("cls");
    changeConsoleColor(AQUA);

    cout << "\t\t\t\tPlease choose your option." << "\n\n";
    cout << "\t\t\t----------------------\t ----------------------" << '\n';
    cout << "\t\t\t|       LAUNCH       |\t |       LAUNCH       |" << '\n';
    cout << "\t\t\t|     DINE IN OR     |\t |       ONLINE       |" << '\n';
    cout << "\t\t\t|      TAKE OUT      |\t |      DELIVERY      |" << '\n';
    cout << "\t\t\t|      SERVICES      |\t |      SERVICES      |" << '\n';
    cout << "\t\t\t|    ===========     |\t |    ===========     |" << '\n';    
    cout << "\t\t\t|      [  1  ]       |\t |      [  2  ]       |" << '\n';      
    cout << "\t\t\t----------------------\t ----------------------" << '\n';
    cout << endl;
    cout << endl;
    cout << "\t\t\t----------------------\t ----------------------" << '\n';
    cout << "\t\t\t|       LAUNCH       |\t |                    |" << '\n';
    cout << "\t\t\t|     RESTAURANT     |\t |        EXIT        |" << '\n';
    cout << "\t\t\t|     MANAGEMENT     |\t |       PROGRAM      |" << '\n';
    cout << "\t\t\t|       SYSTEM       |\t |     ===========    |" << '\n';
    cout << "\t\t\t|    ===========     |\t |       [  4  ]      |" << '\n';    
    cout << "\t\t\t|      [  3  ]       |\t |                    |" << '\n';      
    cout << "\t\t\t----------------------\t ----------------------" << '\n';
    cout << "\n";

    changeConsoleColor(WHITE);

    cout << "\t\t\tPlease input your choice: ";
    
    while (!(cin >> choice)) {
      cout << "\t\t\tInvalid Choice. Please try again." << '\n';
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\t\t\tPlease input your choice: ";
    }

    switch (choice) {
      case 1:
        system("cls");
        system("DineInTakeOutService.exe");
        break;
      
      case 2:
        system("cls");
        system("Online_Delivery.exe");
        break;

      case 3:
        system("Restaurant_Management.exe");
        break;

      case 4:
        system("cls");
        changeConsoleColor(AQUA);
        cout << "Exiting program";

        for (int i = 0; i < 5; i++) {
          cout << ".";
          Sleep(300);
        }

        system("cls");

        cout << "Thank you for using the program!" << '\n';
        break;

      default:
        changeConsoleColor(RED);
        cout << "Please input a proper choice." << '\n';
    }

  } while (choice != 4);
}

// Changes the text color of the program.
void changeConsoleColor(int color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}