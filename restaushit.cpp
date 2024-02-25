#include <iostream>
#include <windows.h>
#include <conio.h>
#include <limits>
#include <string>

using namespace std;

// Variables for colors
#define AQUA 3
#define BLUE 9
#define GREEN 10
#define RED 12
#define BEIGE 14
#define WHITE 15

// Function Prototypes
void showMenu();
void chooseOrderType();
void changeConsoleColor(int color);
void chooseTable();
void chooseRestaurantMenu();
void viewMainCourseMenu();
void viewSideDishMenu();
void viewSandwichesMenu();
void viewPizzaMenu();
void viewBeveragesMenu();
void viewDessertsMenu();

// Global Variables
int orderChoice;
char tables[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

int main() {
  showMenu();
  return 0;                                                                                                                               
}

// Lets the user choose what order type they want.
void chooseOrderType() {
  cout << "\t\t\t    Welcome to our restaurant!" << endl;
  cout << "\t\t\t    ==========================" << endl;
  cout << "\t\t\t    Please choose your option." << endl;
  cout << endl;
  cout << "\t\t---------------------\t      ---------------------" << endl;
  cout << "\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t|      DINE IN      |\t      |      TAKE OUT     |" << endl;
  cout << "\t\t|    ===========    |\t      |    ===========    |" << endl;
  cout << "\t\t|      [  1  ]      |\t      |      [  2  ]      |" << endl;
  cout << "\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t---------------------\t      ---------------------" << endl;
  cout << endl;
  cout << endl;                   

  do {
    changeConsoleColor(RED);
    cout << "\t\t\t Please choose your option: ";

    while (!(cin >> orderChoice)) {
      cout << "\t\t\tInvalid input. Please try again." << endl;
      cout << "\t\t\t Please choose your option: ";
      cin.clear();
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (orderChoice != 1 && orderChoice != 2) {
      cout << "\t\t\tInvalid input. Please try again." << endl;
    }
  } while (orderChoice != 1 && orderChoice != 2);

  if (orderChoice == 1) {
    chooseTable();
  } else {
    chooseRestaurantMenu();
  }
}

void chooseTable() {
  changeConsoleColor(WHITE);
  system("cls");

  int tableNumber, tableChoice;

  cout << "\t\t\tYou have chosen dine in." << endl;
  cout << "\t\t\t------------------------" << endl;
  cout << "\t\t\tPlease choose your table: " << endl;
  cout << endl;
  cout << "\t\t\tTables available: " << endl;
  cout << endl;

  // Displays the table available
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tableNumber = i * 3 + j;
      cout << "\t\t [ " << tableNumber << " ] ";
    }
    cout << endl;
    cout << endl;
  }

  do {
    cout << "\t\tPlease choose your table (0 - 8): ";

    while (!(cin >> tableChoice)) {
      cout << "\t\tInvalid choice. Please try again." << endl;
      cout << "\t\tPlease choose your table (0 - 8): ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (tableChoice < 0 || tableChoice > 8 || tables[tableChoice] == 'X') {
      cout << "\t\tInvalid table number or table is already taken. Please choose an available table between 0 and 8." << endl;
    }

  } while (tableChoice < 0 || tableChoice > 8 || tables[tableChoice] == 'X');

  tables[tableChoice] = 'X'; // If user chooses a specific table, it will be marked X or occupied.
  system("cls");

  cout << "\t\t\tYou have chosen table " << tableChoice << "." << endl;
  cout << endl;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tableNumber = i * 3 + j;
      cout << "\t\t[ " << (tables[tableNumber] == 'X' ? "X" : to_string(tableNumber)) << " ] ";
    }
    cout << endl;
    cout << endl;
  }

  cout << "\t\t   ";
  system("pause");
  
  chooseRestaurantMenu();
}

void chooseRestaurantMenu() {
  system("cls");
  int choice;

  cout << "\t\t\t    Please choose your category within our menu." << endl;
  cout << "\t\t\t    =============================================" << endl;
  cout << endl;
  cout << "\t\t\t---------------------\t      ---------------------" << endl;
  cout << "\t\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t\t|    MAIN COURSE    |\t      |     SIDE DISH     |" << endl;
  cout << "\t\t\t|    ===========    |\t      |    ===========    |" << endl;
  cout << "\t\t\t|      [  1  ]      |\t      |      [  2  ]      |" << endl;
  cout << "\t\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t\t---------------------\t      ---------------------" << endl;
  cout << endl;
  cout << endl;
  cout << "\t\t\t---------------------\t      ---------------------" << endl;
  cout << "\t\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t\t|     SANDWICHES    |\t      |       PIZZA       |" << endl;
  cout << "\t\t\t|     ==========    |\t      |    ===========    |" << endl;
  cout << "\t\t\t|      [  3  ]      |\t      |      [  4  ]      |" << endl;
  cout << "\t\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t\t---------------------\t      ---------------------" << endl;
  cout << endl;
  cout << endl;
  cout << "\t\t\t---------------------\t      ---------------------" << endl;
  cout << "\t\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t\t|     BEVERAGES     |\t      |      DESSERTS     |" << endl;
  cout << "\t\t\t|    ===========    |\t      |    ===========    |" << endl;
  cout << "\t\t\t|      [  5  ]      |\t      |      [  6  ]      |" << endl;
  cout << "\t\t\t|                   |\t      |                   |" << endl;
  cout << "\t\t\t---------------------\t      ---------------------" << endl;
  cout << endl;

  do {
    cout << "\t\t\tPlease input your option: ";
    
    while (!(cin >> choice)) {
      cout << "\t\t\tInvalid choice. Please try again." << endl;
      cout << "\t\t\tPlease input your option: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

    if (choice < 0 || choice > 6) {
      cout << "\t\t\tInvalid choice. Please input a proper choice." << endl;
    }

  } while (choice < 0 || choice > 6);


  switch (choice) {
    case 1:
      viewMainCourseMenu();
      break;
    
    case 2:
      viewSideDishMenu();
      break;
    
    case 3:
      viewSandwichesMenu();
      break;

    case 4:
      viewPizzaMenu();
      break;

    case 5:
      viewBeveragesMenu();
      break;
    
    case 6:
      viewDessertsMenu();
      break;
  }
}

void viewMainCourseMenu() {

}

void viewSideDishMenu() {

}

void viewSandwichesMenu() {

}

void viewPizzaMenu() {

}

void viewBeveragesMenu() {

}

void viewDessertsMenu() {

}

// Changes the text color of the program by just calling the function and inputting the needed arguments.
void changeConsoleColor(int color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

// Function that shows the logo of the restaurant
void showMenu() {
changeConsoleColor(AQUA);
cout << endl;
cout << endl;
cout << endl;
cout << endl;
cout << "\t\t\t\t$$$$$$$\\                        $$\\                                                       $$\\                                           $$\\" << endl;                    
cout << "\t\t\t\t$$  __$$\\                       $$ |                                                      $$ |                                          $$ |   " << endl;                              
cout << "\t\t\t\t$$ |  $$ | $$$$$$\\   $$$$$$$\\ $$$$$$\\    $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$$$$$\\  $$$$$$$\\ $$$$$$\\          $$$$$$$\\ $$\\   $$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\  $$$$$$\\$$$$\\" << endl; 
cout << "\t\t\t\t$$$$$$$  |$$  __$$\\ $$  _____|\\_$$  _|   \\____$$\\ $$ |  $$ |$$  __$$\\ \\____$$\\ $$  __$$\\_$$  _|        $$  _____|$$ |  $$ |$$  _____|\\_$$  _|  $$  __$$\\ $$  _$$  _$$\\ " << endl;
cout << "\t\t\t\t$$  __$$< $$$$$$$$ |\\$$$$$$\\    $$ |     $$$$$$$ |$$ |  $$ |$$ |  \\__|$$$$$$$ |$$ |  $$ | $$ |          \\$$$$$$\\  $$ |  $$ |\\$$$$$$\\    $$ |    $$$$$$$$ |$$ / $$ / $$ |" << endl;
cout << "\t\t\t\t$$ |  $$ |$$   ____| \\____$$\\   $$ |$$\\ $$  __$$ |$$ |  $$ |$$ |     $$  __$$ |$$ |  $$ | $$ |$$\\        \\____$$\\ $$ |  $$ | \\____$$\\   $$ |$$\\ $$   ____|$$ | $$ | $$ |" << endl;
cout << "\t\t\t\t$$ |  $$ |\\$$$$$$$\\ $$$$$$$  |  \\$$$$  |\\$$$$$$$ |\\$$$$$$  |$$ |     \\$$$$$$$ |$$ |  $$ | \\$$$$  |      $$$$$$$  |\\$$$$$$$ |$$$$$$$  |  \\$$$$  |\\$$$$$$$\\ $$ | $$ | $$ |" << endl;
cout << "\t\t\t\t\\__|  \\__| \\_______|\\_______/    \\____/  \\_______| \\______/ \\__|      \\_______|\\__|  \\__|  \\____/       \\_______/  \\____$$ |\\_______/    \\____/  \\_______|\\__| \\__| \\__|" << endl;
cout << "\t\t\t\t                                                                                                                  $$\\   $$ |                                            " << endl;
cout << "\t\t\t\t                                                                                                                 \\$$$$$$  |                                            " << endl;
cout << "\t\t\t\t                                                                                                                  \\______/                                             " << endl;
cout << endl;
cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
system("pause");
system("cls");

chooseOrderType();
}

