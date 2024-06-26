#include <iostream>
#include <string>
#include <limits>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <vector>
#include <regex>
#include <cstdlib>
#include <ctime>

using namespace std;

// Variables for colors
#define AQUA 3
#define BLUE 9
#define GREEN 10
#define RED 12
#define BEIGE 14
#define WHITE 15

struct Food {
  string name;
  float price;
};

// Function Prototypes
void showMenu();
void chooseOrderType();
void chooseTable();
void displayTables(const vector<bool>& tables, int numOfRows, int numOfColumns);
void saveTableChoice(int tableNumber, const vector<int>& tableNumbers);
vector<int> loadTableChoices();
void chooseRestaurantMenu(int tableNumber);
void viewMainCourseMenu(int tableNumber);
void chooseOption(string food, int price, int tableNumber, int foodChoice);
void orderFood(string foodName, int foodPrice, int tableNumber, int foodChoice);
void viewSideDishMenu(int tableNumber);
void viewComboMealsMenu(int tableNumber);
void viewPastriesMenu(int tableNumber);
void viewDessertsMenu(int tableNumber);
void viewBeveragesMenu(int tableNumber);
int ingredients(int choice);
int viewNutrientFacts(int choice);
void forDiscount(int tableNumber);
void displayReceipt(int tableNumber);
void choosePayment(int tableNumber);
void cashPayment(double total);
void cardPayment(double total);
void eWalletPayment(double total);
bool cardNumberValid(const string& cardNumber);
bool expiryMonthValid(int month);
bool isValidExpiryYear(int year);
bool isValidCVV(int cvv);
bool isValidNumberAndPin(const string& mobileNumber, const string& pin);
void thankCustomer();
void changeConsoleColor(int color);

// Global Variables
int orderChoice; // 1 for Dine In and 2 for Take out
int foodCount = 0; // 1 - Main Course, 2 - Side Dish, 3 - Combo Meal, 4 - Pastries, 5 - Beverages, 6 - Desserts
string tableFile = "table_allocation.txt"; // Table file name for table allocation
bool verifiedPWDOrSenior, validVoucher; // Boolean values for verification of PWD or Senior and if the Voucher is valid.
int modeOfPayment; // 1 - Cash, 2 - Card, 3 - E-Wallet
int notComboMeal; // Checks if the type of item they are ordering is not a combo meal.

int main() {
    showMenu();
    return 0;
}

void showMenu() { // Shows the greetings when the user first launches the program.
    changeConsoleColor(AQUA);
    cout << "\n\n";
    cout << " \t\t\t\t ***        ***  **********  ***         **********  **********  ******    ******  ********** " << '\n';
    cout << " \t\t\t\t ***        ***  **********  ***         **********  **********  ******    ******  ********** " << '\n';
    cout << " \t\t\t\t ***        ***  ***         ***         ***         ***    ***  ******    ******  ***        " << '\n';
    cout << " \t\t\t\t ***        ***  ***         ***         ***         ***    ***  ***   ****   ***  ***        " << '\n';
    cout << " \t\t\t\t ***        ***  **********  ***         ***         ***    ***  ***   ****   ***  ********** " << '\n';
    cout << " \t\t\t\t ***  ****  ***  **********  ***         ***         ***    ***  ***   ****   ***  ********** " << '\n';
    cout << " \t\t\t\t ***  ****  ***  ***         ***         ***         ***    ***  ***   ****   ***  ***        " << '\n';
    cout << " \t\t\t\t ***  ****  ***  ***         ***         ***         ***    ***  ***   ****   ***  ***        " << '\n';
    cout << " \t\t\t\t ******  ******  ***         ***         ***         ***    ***  ***          ***  ***        " << '\n';
    cout << " \t\t\t\t ******  ******  **********  **********  **********  **********  ***          ***  ********** " << '\n';
    cout << " \t\t\t\t ******  ******  **********  **********  **********  **********  ***          ***  ********** " << '\n';
    cout << "\n\n";
    cout << " \t\t\t\t\t\t\t\t **********  ********** " << '\n';
    cout << " \t\t\t\t\t\t\t\t **********  ********** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ***    *** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ***    *** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ***    *** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ***    *** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ***    *** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ***    *** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ***    *** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ********** " << '\n';
    cout << " \t\t\t\t\t\t\t\t    ****     ********** " << '\n';
    cout << "\n\n";
    cout << " \t\t\t\t\t\t                                        *****   ***             " << '\n';
    cout << " \t\t\t\t\t\t **********                            **   *****               " << '\n';
    cout << " \t\t\t\t\t\t **********                                                      " << '\n';
    cout << " \t\t\t\t\t\t ***         ***    ***  **********  *****       ***  ********** " << '\n';
    cout << " \t\t\t\t\t\t ***         ***    ***  **********  *** ***     ***  ********** " << '\n';
    cout << " \t\t\t\t\t\t ***         ***    ***  ***         ***  ***    ***  ***    *** " << '\n';
    cout << " \t\t\t\t\t\t **********  ***    ***  **********  ***   ***   ***  ***    *** " << '\n';
    cout << " \t\t\t\t\t\t **********  ***    ***  **********  ***    ***  ***  ***    *** " << '\n';
    cout << " \t\t\t\t\t\t        ***  ***    ***  ***         ***     *** ***  ***    *** " << '\n';
    cout << " \t\t\t\t\t\t        ***  ***    ***  ***         ***      ******  ***    *** " << '\n';
    cout << " \t\t\t\t\t\t **********  **********  **********  ***        ****  ********** " << '\n';
    cout << " \t\t\t\t\t\t **********  **********  **********  ***         ***  ********** " << '\n';
    cout << "\n\n\n\t\t\t\t\t\t\t";

	system("pause");

  chooseOrderType();
}

void chooseOrderType() { // Lets the user choose if they want to Dine In or Take Out.
    int tableChoice;

    system("cls");

    cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';
    cout << "\t\t\t\t\t\t\t\t  Please select your option " << '\n';
    cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';

    cout << endl;

    cout << "\t\t\t\t\t\t\t --------------------\t" << "--------------------" << '\n';
    cout << "\t\t\t\t\t\t\t -                  -\t" << "-                  -" << '\n';
    cout << "\t\t\t\t\t\t\t -     DINE IN      -\t" << "-     TAKE OUT     -" << '\n';
    cout << "\t\t\t\t\t\t\t -                  -\t" << "-                  -" << '\n';
    cout << "\t\t\t\t\t\t\t -      [ 1 ]       -\t" << "-       [ 2 ]      -" << '\n';
    cout << "\t\t\t\t\t\t\t -                  -\t" << "-                  -" << '\n';
    cout << "\t\t\t\t\t\t\t --------------------\t" << "--------------------" << '\n';
    cout << endl; 
    do {
        cout << "\t\t\t\t\t\t\t\tEnter choice: ";
        while (!(cin >> orderChoice)) {
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	
            changeConsoleColor(RED);
            cout << "\n\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl;
            changeConsoleColor(AQUA);
            cout << "\t\t\t\t\t\t\t\tEnter choice: ";
        }
        if (orderChoice != 1 && orderChoice != 2) {
            changeConsoleColor(RED);
            cout << "\n\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl;
            changeConsoleColor(AQUA);
        }
    } while (orderChoice != 1 && orderChoice != 2);

    if (orderChoice == 1) {
        chooseTable();
        orderChoice = 1; // 1 For Dine In
    } else {
        chooseRestaurantMenu(tableChoice);
        orderChoice = 2; // 2 For Take Out
    }

}

void chooseTable() {
  int numOfRows = 3; // Number of Rows for Table
  int numOfColumns = 3; // Number of Columns for Table
  int tableChoice;
  bool validChoice = false;
  vector<bool> tables(numOfRows * numOfColumns, true); // Initializes vector that contains all of the tables

  vector<int> tableNumbers = loadTableChoices(); // Load all table choices

  for (int tableNumber : tableNumbers) {
    if (tableNumber > 0 && tableNumber <= tables.size()) {
      tables[tableNumber - 1] = false; // Makes the table allocated.
    }
  }

  displayTables(tables, numOfRows, numOfColumns); // Calls the function displayTables. Passes through the vector tables and the num of rows and columns.

  do {
    cout << "\t\t\t\t\t\t\t\tChoose a table: ";

    while (!(cin >> tableChoice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (tableChoice > 0 && tableChoice <= tables.size()) {

      if (tables[tableChoice - 1]) {
        validChoice = true;
      } else {
        changeConsoleColor(RED);
        cout << "\n\t\t\t\t\t\t\t\tTable " << tableChoice << " is already occupied. Please choose another option." << '\n';
        changeConsoleColor(AQUA);
      }

    } else {
      changeConsoleColor(RED);
      cout << "\n\t\t\t\t\t\t\t\tInvalid choice. Please choose an available table." << '\n';
      changeConsoleColor(AQUA);
    }

  } while (!validChoice);

  saveTableChoice(tableChoice, tableNumbers); // Save the new table choice along with the existing choices
  tables[tableChoice - 1] = false;
  cout << "\n\t\t\t\t\t\t\t\tYou have chosen Table " << tableChoice << "." << '\n';

  cout << "\n\t\t\t\t\t\t\t\t";
  system("pause");

  chooseRestaurantMenu(tableChoice);
}

void displayTables(const vector<bool>& tables, int numOfRows, int numOfColumns) { // Function that displays the available tables.
  int tableNumber = 1;

  system("cls");

  cout << "\t\t\t\t\t\t\t\t     -------------------- " << '\n';
  cout << "\t\t\t\t\t\t\t\t           Dine In        " << '\n';
  cout << "\t\t\t\t\t\t\t\t     -------------------- " << '\n';
  cout << "\t\t\t\t\t\t\t\t       Tables available:  " << '\n';
  cout << endl; cout << endl;

  for (int i = 0; i < numOfRows; i++) { // For loop that displays the rows of the tables.
    for (int j = 0; j < numOfColumns; j++) { // For loop that displays the columns of the tables.
      if (tableNumber <= tables.size()) {
        cout << " \t\t\t\t [ " << (tables[tableNumber - 1] ? to_string(tableNumber) : "X") << " ] ";
        tableNumber++;

      } else {
        break;
      }
    }
    cout << "\n\n";
  }
  cout << "\n\n";
}

void saveTableChoice(int tableNumber, const vector<int>& tableNumbers) { // Saves the table number to the file.
  ofstream file(tableFile);

  if (file.is_open()) {
    for (int num : tableNumbers) {
      file << num << " "; // Write all existing table numbers to the file
    }
    file << tableNumber << " "; // Append the new table number
    file.close();
  } else {
    cerr << "\t\t\t\t\t\t\tError! File can't be opened.\n";
  }
}

vector<int> loadTableChoices() { // Loads the table numbers from the file and returns the table numbers that are allocated.
  ifstream file(tableFile);
  vector<int> tableNumbers;
  int tableNumber;

  if (file.is_open()) {
    while (file >> tableNumber) {
      tableNumbers.push_back(tableNumber);
    }
    file.close(); // Closes the File
  } else {
    cerr << "\t\t\t\t\t\t\tUnable to open file.\n";
  }

  return tableNumbers;
}

void chooseRestaurantMenu(int tableNumber) { // Function that lets the user choose their category for different types of foods.
  system("cls");

  int choice;
  cout << " \t\t\t\t\t\t\t    -------------------------------------------- " << endl;
  cout << " \t\t\t\t\t\t\t    Please choose your category within our menu  " << '\n';
  cout << " \t\t\t\t\t\t\t    -------------------------------------------- " << '\n';
  
  cout << "\n\n";

  cout << " \t\t\t\t\t\t -------------------- " << " \t -------------------- " << " \t -------------------- " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
  cout << " \t\t\t\t\t\t -   MAIN COURSE    - " << " \t -    SIDE DISH     - " << " \t -       COMBO      - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -       MEALS      - " << '\n';
  cout << " \t\t\t\t\t\t -  --------------  - " << " \t -  --------------  - " << " \t -  --------------  - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
  cout << " \t\t\t\t\t\t -      [ 1 ]       - " << " \t -       [ 2 ]      - " << " \t -      [ 3 ]       - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
  cout << " \t\t\t\t\t\t -------------------- " << " \t -------------------- " << " \t -------------------- " << '\n';

  cout << "\n\n";
  
  cout << " \t\t\t\t\t\t -------------------- " << " \t -------------------- " << " \t -------------------- " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
  cout << " \t\t\t\t\t\t -     PASTRIES     - " << " \t -    BEVERAGES     - " << " \t -     DESSERTS     - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
  cout << " \t\t\t\t\t\t -  --------------  - " << " \t -  --------------  - " << " \t -  --------------  - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
  cout << " \t\t\t\t\t\t -      [ 4 ]       - " << " \t -       [ 5 ]      - " << " \t -      [ 6 ]       - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
  cout << " \t\t\t\t\t\t -------------------- " << " \t -------------------- " << " \t -------------------- " << '\n';
  cout << '\n';
  
  do {
    cout << "\t\t\t\t\t\t\tPlease input your option: ";
 
    while (!(cin >> choice)) {
      
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\t\tInvalid choice. Please try again." << '\n';
      changeConsoleColor(AQUA);
      cout << "\t\t\t\t\t\t\tPlease input your option: ";
    }

    if (choice < 1 || choice > 6) {
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\t\tInvalid choice. Please input a proper choice." << '\n';
      changeConsoleColor(AQUA);
    }

  } while (choice < 1 || choice > 6);
  
  switch (choice) { // Switch case for different menus.
    case 1:
      foodCount = 1; // 1 = Main Course
      viewMainCourseMenu(tableNumber);
      break;
  
    case 2:
      foodCount = 2; // 2 = Side Dish
      viewSideDishMenu(tableNumber);
      break;

    case 3:
      foodCount = 3; // 3 = Combo Meals
      viewComboMealsMenu(tableNumber);
      break;
      
    case 4:
      foodCount = 4; // 4 = Pastries
      viewPastriesMenu(tableNumber);
      break;
      
    case 5:
      foodCount = 5; // 5 = Beverages
      viewBeveragesMenu(tableNumber);
      break;

    case 6:
      foodCount = 6; // 6 = Desserts
      viewDessertsMenu(tableNumber);
      break;
  }
}

void viewMainCourseMenu(int tableNumber) { // Lets the user view the main course menu
	int choice, choice2;
  int customerTable = tableNumber;
  notComboMeal = 1;

    // Creates an array to hold main course items
    Food mainCourse[8];
    
    // Initialize main course items with names and prices
    mainCourse[0] = {"Sinigang na Baboy", 149.00};
    mainCourse[1] = {"Sinigang na Hipon", 149.00};
    mainCourse[2] = {"Sinigang na Bangus", 149.00};
    mainCourse[3] = {"Sinigang na Salmon", 199.00};
    mainCourse[4] = {"Kare-Kare", 149.00};
    mainCourse[5] = {"Lechon Kawali", 139.00};
    mainCourse[6] = {"Bistek Tagalog", 109.00};
    mainCourse[7] = {"Pork Sisig", 109.00};

    // Display the main course menu
	do {
    system("cls");
		cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================= " << endl;
		cout << " \t\t\t\t\t                                    ==Main Course==                                    " << '\n';
		cout << " \t\t\t\t\t = [1] Sinigang na Baboy                                              PHP 149.00       " << '\n';
		cout << " \t\t\t\t\t = [2] Sinigang na Hipon                                              PHP 149.00       " << '\n';
		cout << " \t\t\t\t\t = [3] Sinigang na Bangus                                             PHP 149.00       " << '\n';
		cout << " \t\t\t\t\t = [4] Sinigang na Salmon                                             PHP 199.00       " << '\n';
		cout << " \t\t\t\t\t = [5] Kare-Kare                                                      PHP 149.00       " << '\n';
		cout << " \t\t\t\t\t = [6] Lechon Kawali                                                  PHP 139.00       " << '\n';
		cout << " \t\t\t\t\t = [7] Bistek Tagalog                                                 PHP 109.00       " << '\n';
		cout << " \t\t\t\t\t = [8] Pork Sisig                                                     PHP 109.00       " << '\n';
		cout << " \t\t\t\t\t ===================================================================================== " << '\n';
		cout << " \t\t\t\t\t Choose your item: ";

		while (!(cin >> choice)) { // Get user choice for main course
			cin.clear(); // Clears cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores cin newline
			cout << " \t\t\t\t\t Choose your item: ";
		}

	} while (choice < 1 || choice > 8);
  chooseOption (mainCourse[choice - 1].name, mainCourse[choice - 1].price, customerTable, choice);
}

void viewSideDishMenu(int tableNumber) { // Function that lets the user view the side dish menu.
  int choice;
  int customerTable = tableNumber;
  notComboMeal = 1;

  // Creates an array to hold side dish items
  Food sideDish[8];

  // Initialize side dish items with names and prices
  sideDish[0] = {"Garlic Mashed Potatoes", 99.00};
  sideDish[1] = {"Grilled Vegetables", 99.00};
  sideDish[2] = {"Coleslaw", 99.00};
  sideDish[3] = {"Steamed Asparagus", 99.00};
  sideDish[4] = {"Roasted Brussels Sprouts", 99.00};
  sideDish[5] = {"Caprese Salad", 99.00};
  sideDish[6] = {"Quinoa Salad", 99.00};
  sideDish[7] = {"Sautéed Spinach", 99.00};
  
  do {
      system("cls");
      cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================== " << endl;
      cout << " \t\t\t\t\t                                    ==Side Dish==                                       " << '\n';
      cout << " \t\t\t\t\t = [1] Garlic Mashed Potatoes                                             PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t = [2] Grilled Vegetables                                                 PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t = [3] Coleslaw                                                           PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t = [4] Steamed Asparagus                                                  PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t = [5] Roasted Brussels Sprouts                                           PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t = [6] Caprese Salad                                                      PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t = [7] Quinoa Salad                                                       PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t = [8] Sautéed Spinach                                                    PHP 99.00     " << '\n';
      cout << " \t\t\t\t\t ====================================================================================== " << '\n';
      cout << " \t\t\t\t\t Choose your item: ";

      while (!(cin >> choice)) { // Get user choice for main course
        cin.clear(); // Clears cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores cin newline
        cout << " \t\t\t\t\t Enter item: ";
      }

    } while (choice < 1 || choice > 8);

  chooseOption(sideDish[choice - 1].name, sideDish[choice - 1].price, customerTable, choice);
}

void viewComboMealsMenu(int tableNumber) { // Function that lets the user view the combo meals menu.

  int choice;
  int customerTable = tableNumber;
  notComboMeal = 0;

  Food comboMeal[8];

  comboMeal[0] = {"COMBO MEAL 1", 399.00};
  comboMeal[1] = {"COMBO MEAL 2", 320.00};
  comboMeal[2] = {"COMBO MEAL 3", 329.00};
  comboMeal[3] = {"COMBO MEAL 4", 429.00};
  comboMeal[4] = {"COMBO MEAL 5", 459.00};
  comboMeal[5] = {"COMBO MEAL 6", 489.00};
  comboMeal[6] = {"COMBO MEAL 7", 359.00};
  
  do {
    system("cls");
    cout << " \t\t\t\t\t ==================================== SUEÑO RESTAURANT =======================================" << endl;
    cout << " \t\t\t\t\t                                      ==Combo Meals==                                         " << '\n';
    cout << " \t\t\t\t\t = [1] Sinigang na Baboy, Garlic Mashed Potatoes, Macarons, Coke                   PHP 399.00 " << '\n';
    cout << " \t\t\t\t\t = [2] Sinigang na Hipon, Grilled Vegetables, Ensaymada, Coke Zero                 PHP 320.00  " << '\n';
    cout << " \t\t\t\t\t = [3] Sinigang na Bangus, Coleslaw, Pan de Coco, Iced Tea                         PHP 329.00  " << '\n';
    cout << " \t\t\t\t\t = [4] Sinigang na Salmon, Steamed Asparagus, Croissant, Lemonade                  PHP 429.00  " << '\n';
    cout << " \t\t\t\t\t = [5] Kare-Kare, Roasted Brussels Sprouts,Éclair, Iced Coffee                    PHP 459.00 " << '\n';
    cout << " \t\t\t\t\t = [6] Lechon Kawali, Caprese Salad, Tiramisu, Watermelon Shake                    PHP 489.00 " << '\n';
    cout << " \t\t\t\t\t = [7] Bistek Tagalog, Quinoa Salad, Churros, Mango Shake                          PHP 359.00 " << '\n';
    cout << " \t\t\t\t\t =============================================================================================" << '\n';
    cout << " \t\t\t\t\t Choose your item: ";

  while (!(cin >> choice)) { // Get user choice for main course
    cin.clear(); // Clears cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores cin newline
    cout << " \t\t\t\t\t Enter item: ";
  }

	} while (choice < 1 || choice > 7);

  chooseOption(comboMeal[choice - 1].name, comboMeal[choice - 1].price, customerTable, choice);
}


void viewPastriesMenu(int tableNumber) { // Function that lets the user view the pastries menu.
  int choice;
  int customerTable = tableNumber;
  notComboMeal = 1;

  Food pastries[7];

  pastries[0] = {"Macarons", 120.00};
  pastries[1] = {"Ensaymada", 55.00};
  pastries[2] = {"Pan de Coco", 65.00};
  pastries[3] = {"Croissant", 110.00};
  pastries[4] = {"Éclair", 130.00};
  pastries[5] = {"Tiramisu", 200.00};
  pastries[6] = {"Churros", 100.00};

  do {
    system("cls");
		cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================== " << endl;
		cout << " \t\t\t\t\t                                      ==Pastries==                                      " << '\n';
		cout << " \t\t\t\t\t = [1] Macarons                                                              PHP 120.00 " << '\n';
		cout << " \t\t\t\t\t = [2] Ensaymada                                                             PHP 55.00  " << '\n';
		cout << " \t\t\t\t\t = [3] Pan de Coco                                                           PHP 65.00  " << '\n';
		cout << " \t\t\t\t\t = [4] Croissant                                                             PHP 110.00 " << '\n';
		cout << " \t\t\t\t\t = [5] Éclair                                                                PHP 130.00 " << '\n';
		cout << " \t\t\t\t\t = [6] Tiramisu                                                              PHP 200.00 " << '\n';
		cout << " \t\t\t\t\t = [7] Churros                                                               PHP 100.00 " << '\n';
		cout << " \t\t\t\t\t ====================================================================================== " << '\n';
		cout << " \t\t\t\t\t Choose your item: ";

		while (!(cin >> choice)) { // Get user choice for main course
			cin.clear(); // Clears cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores cin newline
			cout << " \t\t\t\t\t Choose your item: ";
		}

	} while (choice < 1 || choice > 8);
  chooseOption (pastries[choice - 1].name, pastries[choice - 1].price, customerTable, choice);
}

void viewBeveragesMenu(int tableNumber) { // Function that lets the user view the beverages menu.
  int choice;
  int customerTable = tableNumber;
  notComboMeal = 1;

  Food beverages[8];

  beverages[0] = {"Coke", 50.00};
  beverages[1] = {"Coke Zero", 49.00};
  beverages[2] = {"Iced Tea", 40.00};
  beverages[3] = {"Lemonade", 55.00};
  beverages[4] = {"Iced Coffee", 130.00};
  beverages[5] = {"Watermelon Shake", 80.00};
  beverages[6] = {"Mango Shake", 90.00};
  beverages[7] = {"Water", 20.00};
  
do {
    system("cls");
		cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ==================================== " << endl;
		cout << " \t\t\t\t\t                                     ==Beverages==                                        " << '\n';
		cout << " \t\t\t\t\t = [1] Coke                                                                PHP 50.00      " << '\n';
		cout << " \t\t\t\t\t = [2] Coke Zero                                                           PHP 49.00      " << '\n';
		cout << " \t\t\t\t\t = [3] Iced Tea                                                            PHP 40.00      " << '\n';
		cout << " \t\t\t\t\t = [4] Lemonade                                                            PHP 55.00      " << '\n';
		cout << " \t\t\t\t\t = [5] Iced Coffee                                                         PHP 130.00     " << '\n';
		cout << " \t\t\t\t\t = [6] Watermelon Shake                                                    PHP 80.00      " << '\n';
		cout << " \t\t\t\t\t = [7] Mango Shake                                                         PHP 90.00      " << '\n';
		cout << " \t\t\t\t\t = [8] Water                                                               PHP 20.00      " << '\n';
		cout << " \t\t\t\t\t ======================================================================================== " << '\n';
		cout << " \t\t\t\t\t Choose your item: ";

		while (!(cin >> choice)) { // Get user choice for main course
			cin.clear(); // Clears cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores cin newline
			cout << " \t\t\t\t\t Choose your item: ";
		}

	} while (choice < 1 || choice > 8);
  chooseOption (beverages[choice - 1].name, beverages[choice - 1].price, customerTable, choice);
}

void viewDessertsMenu(int tableNumber) { // Function that lets the user view the desserts menu.
  int choice;
  int customerTable = tableNumber;
  notComboMeal = 1;

  Food desserts[8];

  desserts[0] = {"Halo-Halo", 90.00};
  desserts[1] = {"Leche Flan", 99.00};
  desserts[2] = {"Banana Cue", 59.00};
  desserts[3] = {"Taho", 69.00};
  desserts[4] = {"Turon", 89.00};
  desserts[5] = {"Puto Cheese", 60.00};
  desserts[6] = {"Suman", 70.00};
  desserts[7] = {"Pichi-Pichi", 85.00};
  
do {
    system("cls");
		cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================== " << endl;
		cout << " \t\t\t\t\t                                      ==Desserts==                                      " << '\n';
		cout << " \t\t\t\t\t = [1] Halo-Halo                                                              PHP 90.00 " << '\n';
		cout << " \t\t\t\t\t = [2] Leche Flan                                                             PHP 99.00 " << '\n';
		cout << " \t\t\t\t\t = [3] Banana Cue                                                             PHP 59.00 " << '\n';
		cout << " \t\t\t\t\t = [4] Taho                                                                   PHP 69.00 " << '\n';
		cout << " \t\t\t\t\t = [5] Turon                                                                  PHP 89.00 " << '\n';
		cout << " \t\t\t\t\t = [6] Puto Cheese                                                            PHP 60.00 " << '\n';
		cout << " \t\t\t\t\t = [7] Suman                                                                  PHP 70.00 " << '\n';
		cout << " \t\t\t\t\t = [8] Pichi-Pichi                                                            PHP 85.00 " << '\n';
		cout << " \t\t\t\t\t ====================================================================================== " << '\n';
		cout << " \t\t\t\t\t Choose your item: ";

		while (!(cin >> choice)) { // Get user choice for main course
			cin.clear(); // Clears cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores cin newline
			cout << " \t\t\t\t\t Choose your item: ";
		}

	} while (choice < 1 || choice > 8);
  chooseOption (desserts[choice - 1].name, desserts[choice - 1].price, customerTable, choice); // Takes in the food, the price, table number, and choice.
}

void chooseOption (string food, int price, int tableNumber, int foodChoice) { // Allows the user to choose options from the food that they chose
  int choice;
  bool returnToMenu;

  do {
    system("cls");
    cout << "\n\n\n";

    if (notComboMeal == 1) {
      cout << "\t\t\t\t\tYou have chosen to view " << food << ". What would would you like to do?" << endl;
    } else if (notComboMeal == 0) {
      cout << "\t\t\t\t\tYou have chosen to view Combo Meal " << foodChoice << ". What would would you like to do?" << endl;
    }

    cout << "\n\n";
    cout << "\t\t\t\t -------------------- " << " \t -------------------- " << " \t -------------------- " << " \t -------------------- " << '\n';
    cout << "\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
    cout << "\t\t\t\t -    ORDER ITEM    - " << " \t -       VIEW       - " << " \t -       VIEW       - " << " \t -      RETURN      - " << '\n';
    cout << "\t\t\t\t -                  - " << " \t -    INGREDIENTS   - " << " \t -  NUTRIENT FACTS  - " << " \t -   TO MAIN MENU   - " << '\n';
    cout << "\t\t\t\t -  --------------  - " << " \t -  --------------  - " << " \t -  --------------  - " << " \t -  --------------  - " << '\n';
    cout << "\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
    cout << "\t\t\t\t -      [ 1 ]       - " << " \t -       [ 2 ]      - " << " \t -      [ 3 ]       - " << " \t -      [ 4 ]       - " << '\n';
    cout << "\t\t\t\t -                  - " << " \t -                  - " << " \t -                  - " << " \t -                  - " << '\n';
    cout << "\t\t\t\t -------------------- " << " \t -------------------- " << " \t -------------------- " << " \t -------------------- " << '\n';
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\tPlease input your choice: ";

    cin.clear();
    
    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\t\tPlease input your choice (1 - 4 only): ";
      changeConsoleColor(AQUA);
    }

    switch (choice) {
      case 1:
        orderFood(food, price, tableNumber, foodChoice); // Takes in the food choice and the corresponding price.
        break;

      case 2:
        returnToMenu = ingredients(foodChoice);
        break;

      case 3:
        returnToMenu = viewNutrientFacts(foodChoice);
        break;

      case 4:
        chooseRestaurantMenu(tableNumber);
        break;

      default:
        changeConsoleColor(RED);
        cout << "\t\t\t\t\t\t\tInvalid choice. Please try again." << endl;
        changeConsoleColor(AQUA);
        break;
    }


  } while (choice < 1 || choice > 4 || returnToMenu);
}

int ingredients(int choice) {

  system("cls");

  cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================== " << endl;
  cout << " \t\t\t\t\t\t\t\t\t     FOOD INGREDIENTS LIST                                                        " << '\n';

  // Main Course Ingredients List
  string sinigangBaboyIngredients[10] = {
    "Pork",
    "Tomates",
    "Onion",
    "Fish Sauce",
    "Gabi",
    "Radish",
    "Vegetables",
    "Tamarind",
    "Banana",
    "Chili Peppers"
  };

   string sinigangHiponIngredients[10] = {
    "Shrimp",
    "Tomatoes",
    "Onion",
    "Fish Sauce",
    "Gabi",
    "Radish",
    "Vegetables",
    "Tamarind",
    "Banana",
    "Chili peppers"
  };

   string sinigangBangusIngredients[10] = {
    "Bangus (Milkfish)",
    "Tomatoes",
    "Onion",
    "Fish Sauce",
    "Gabi",
    "Radish",
    "Vegetables",
    "Tamarind",
    "Chili peppers"
  };

   string sinigangSalmonIngredients[10] = {
    "Salmon",
    "Tomatoes",
    "Onion",
    "Fish Sauce",
    "Gabi",
    "Radish",
    "Vegetables",
    "Tamarind",
    "Banana",
    "Chili Peppers"
  };

   string kareKareIngredients[10] = {
    "Oxtail",
    "Tripes",
    "Peanut Sauce",
    "String Beans",
    "Eggplant",
    "Banana Heart",
    "Annatto Seeds"
  };

   string LechonKawaliIngredients[10] = {
    "Pork Belly",
    "Cooking Oil",
    "Salt",
    "Pepper"
  };

   string bistekIngredients[10] = {
    "Beef Sirloin",
    "Soy Sauce",
    "Calamansi",
    "Onion",
    "Garlic"
  };

   string porkSisigIngredients[10] = {
    "Pork Ears",
    "Pork Belly",
    "Onion",
    "Calamansi",
    "Red and Green Chili",
    "Mayonnaise"
  };

  // Side Dish Ingredients List
  string mashedPotatoesIngredients[10] = {
    "Potatoes",
    "Garlic",
    "Butter",
    "Milk",
    "Salt",
    "Pepper"
  };

  string grilledVegetablesIngredients[10] = {
    "Assorted Vegetables (e.g., zucchini, bell peppers, muishrooms)",
    "Olive Oil",
    "Garlic",
    "Herbs and Spices",
    "Salt",
    "Pepper"
  };

  string coleslawIngredients[10] = {
    "Cabbage",
    "Carrots",
    "Mayonnaise",
    "Vinegar",
    "Sugar",
    "Salt",
    "Pepper"
  };

  string steamedAsparagusIngredients[10] = {
    "Asparagus",
    "Olive oil",
    "Lemon Juice",
    "Salt",
    "Pepper"
  };

  string brusselsSproutsIngredients[10] = {
    "Brussels Sprouts",
    "Olive Oil",
    "Balsamic Vinegar",
    "Honey",
    "Salt",
    "Pepper"
  };

  string capreseSaladIngredients[10] = {
    "Tomatoes",
    "Fresh Mozzarella",
    "Basil",
    "Balsamic Glaze",
    "Olive Oil",
    "Salt",
    "Pepper"
  };

  string quinoaSaladIngredients[10] = {
    "Quinoa",
    "Cucumber",
    "Cherry Tomatoes",
    "Red Onion",
    "Feta Cheese",
    "Olive Oil",
    "Lemon Juice",
    "Salt",
    "Pepper"
  };

  string spinachIngredients[10] = {
    "Spinach",
    "Olive Oil",
    "Garlic",
    "Lemon Juice",
    "Salt",
    "Pepper"
  };

  // Pastries Ingredients List

  string macaronsIngredients[10] = {
    "White Sugar",
    "Almond Flour",
    "Salt",
    "Egg Whites",
    "Granulated Sugar",
    "Vanilla Extract",
    "Food Coloring",
    "Unsalted Butter",
    "Heavy Cream"
  };

  string ensaymadaIngredients[10] = {
    "All-Purpose Flour",
    "Melted Butter",
    "White Sugar",
    "Salt",
    "Grated Cheddar Cheese",
    "Eggs",
    "Milk"
  };

  string panDeCocoIngredients[10] = {
    "Carbonated Water",
    "Aspartame",
    "Caramel Color",
    "Phosphoric Acid",
    "Natural Flavors",
    "Potassium Citrate",
    "Acesulfame Potassium",
    "Potassium Benzoate"
  };

  string croissantIngredients[10] = {
    "Warm Water",
    "White Sugar",
    "All-purpose Flour",
    "Milk",
    "Salt",
    "Vegetable Oil",
    "Unsalted Butter",
    "Egg",
    "Water"
  };

  string eclairIngredients[10] = {
    "Butter",
    "All-purpose flour",
    "Salt",
    "Eggs",
    "Milk",
    "Instant Vanilla Pudding",
    "Heavy cream",
    "Confectioners' sugar",
    "Vanilla Extract"
    "Semisweet Chocolate"
  };

  string tiramisuIngredients[10] = {
    "Egg Yolks",
    "Sugar",
    "Milk",
    "Cream",
    "Vanilla",
    "Mascarpone",
    "Coffee",
    "Rum",
    "Ladyfingers",
    "Cocoa Powder"
  };

  string churrosIngredients[10] = {
    "Water",
    "Sugar",
    "Salt",
    "Oil",
    "Flour",
    "Cinnamon"
  };

  // Beverage Ingredients List
  string cokeIngredients[10] = {
    "Carbonated Water",
    "High Fructose Corn Syrup",
    "Caramel Color",
    "Phosphoric Acid",
    "Natural Flavors",
    "Caffeine"
  };

  string cokeZeroIngredients[10] = {
    "Carbonated Water",
    "Caramel Color",
    "Natural Flavors",
    "Aspartame",
    "Potassium Benzoate",
    "Potassium Citrate",
    "Acesulfame Potassium",
    "Caffeine"
  };

  string icedTeaIngredients[10] = {
    "Black Tea Powder",
    "Sugar",
    "Water",
    "Lemon"
  };

  string lemonadeIngredients[10] = {
    "Sugar",
    "Water",
    "Lemon Juice",
    "Ice"
  };

  string icedCoffeeIngredients[10] = {
    "Instant Coffee Granules",
    "Sugar",
    "Ice",
    "Cold Milk"
  };

  string watermelonShakeIngredients[10] = {
    "Diced Watermelons",
    "Milk",
    "White Sugar"
  };
  string mangoShakeIngredients[10] = {
    "Mango",
    "Sugar",
    "Ice",
    "Milk"
  };

  string waterIngredients[10] = {
    "H20"
  };

  // Desserts Ingredients List
  string haloHaloIngredients[10] = {
    "Shaved Ice",
    "Evaporated Milk",
    "Nata de Coco",
    "Sugar Palm Fruit",
    "Shredded Macapuno",
    "Ube Jam",
    "Leche Flan"
  };

  string lecheFlanIngredients[10] = {
    "Eggs",
    "Condensed Milk",
    "Evaporated Milk",
    "Sugar",
    "Vanilla Extract"
  };

  string bananaCueIngredients[10] = {
    "Saba Bananas",
    "Brown Sugar",
    "Cooking Oil"
  };

  string tahoIngredients[10] = {
    "Tofu",
    "Sago Pears",
    "Arnibal"
  };

  string turonIngredients[10] = {
    "Saba Bananas",
    "Brown Sugar",
    "Spring Roll Wrappers",
    "Cooking Oil"
  };

  string putoCheeseIngredients[10] = {
    "Rice Flour",
    "Sugar",
    "Baking Powder",
    "Water",
    "Grated Cheese (Toppings)"
  };

  string sumanIngredients[10] = {
    "Glutinous Rice",
    "Coconut Milk",
    "Sugar",
    "Banana Leaves (Wrapping)"
  };

  string pichiPichiIngredients[10] = {
    "Grated Cassava",
    "Sugar",
    "Water",
    "Pandan Leaves",
    "Grated Coconut"
  };


  cout << "\n";

  switch (foodCount) {
    case 1: // Main Course
      
      switch (choice) {
        case 1:
          cout << "\t\t\t\t\t\t\tIngredients for Sinigang na Baboy: " << '\n';
          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangBaboyIngredients[i] << endl;
          }
          break;

        case 2:
          cout << "\t\t\t\t\t\t\tIngredients for Sinigang na Hipon: " << '\n';
          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangHiponIngredients[i] << endl;
          }
          break;

        case 3:
          cout << "\t\t\t\t\t\t\tIngredients for Sinigang na Bangus: " << '\n';
          for (int i = 0; i < 9; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangBangusIngredients[i] << endl;
          }
          break;

        case 4:
          cout << "\t\t\t\t\t\t\tIngredients for Sinigang na Salmon: " << '\n';
          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangSalmonIngredients[i] << endl;
          }
          break;

        case 5:
          cout << "\t\t\t\t\t\t\tIngredients for Kare-Kare: " << '\n';
          for (int i = 0; i < 7; i++) {
            cout << "\t\t\t\t\t\t\t" << kareKareIngredients[i] << endl;
          }
          break;

        case 6:
          cout << "\t\t\t\t\t\t\tIngredients for Lechon Kawali: " << '\n';
          for (int i = 0; i < 4; i++) {
            cout << "\t\t\t\t\t\t\t" << LechonKawaliIngredients[i] << endl;
          }
          break;

        case 7:
          cout << "\t\t\t\t\t\t\tIngredients for Bistek Tagalog: " << '\n';
          for (int i = 0; i < 5; i++) {
            cout << "\t\t\t\t\t\t\t" << bistekIngredients[i] << endl;
          }
          break;

        case 8:
          cout << "\t\t\t\t\t\t\tIngredients for Pork Sisig: " << '\n';
          for (int i = 0; i < 6; i++) {
            cout << "\t\t\t\t\t\t\t" << porkSisigIngredients[i] << endl;
          }
          break;
      }

      break;

    case 2: // Side Dish

      switch (choice) {
        case 1:
          cout << "\t\t\t\t\t\t\tIngredients for Garlic Mashed Potatoes: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << mashedPotatoesIngredients[i] << endl;
          }
          break;

        case 2:
          cout << "\t\t\t\t\t\t\tIngredients for Grilled Vegetables: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << grilledVegetablesIngredients[i] << endl;
          }
          break;

        case 3:
          cout << "\t\t\t\t\t\t\tIngredients for Coleslaw: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << coleslawIngredients[i] << endl;
          }
          break;

        case 4:
          cout << "\t\t\t\t\t\t\tIngredients for Steamed Asparagus: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << steamedAsparagusIngredients[i] << endl;
          }
          break;

        case 5:
          cout << "\t\t\t\t\t\t\tIngredients for Roasted Brussels Sprouts: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << brusselsSproutsIngredients[i] << endl;
          }
          break;

        case 6:
          cout << "\t\t\t\t\t\t\tIngredients for Caprese Salad: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << capreseSaladIngredients[i] << endl;
          }
          break;

        case 7:
          cout << "\t\t\t\t\t\t\tIngredients for Quinoa Salad: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << quinoaSaladIngredients[i] << endl;
          }
          break;

        case 8:
          cout << "\t\t\t\t\t\t\tIngredients for Sautéed Spinach: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << spinachIngredients[i] << endl;
          }
          break;

      }
      break;

    case 3: // Combo Meal

      switch (choice) { 
        case 1: // Displays Combo Meal 1 Ingredients
          cout << "\t\t\t\t\t\t\tViewing Ingredients for Combo Meal 1" << '\n';

          cout << "\n\t\t\t\t\t\t\tIngredients for Sinigang na Baboy: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangBaboyIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Garlic Mashed Potatoes: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << mashedPotatoesIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Macarons: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << macaronsIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Coke: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << cokeIngredients[i] << endl;
          }

          break;

        case 2: // Displays Combo Meal 2 Ingredients
          cout << "\t\t\t\t\t\t\tViewing Ingredients for Combo Meal 2" << '\n';

          cout << "\n\t\t\t\t\t\t\tIngredients for Sinigang na Hipon: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangHiponIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Grilled Vegetables: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << grilledVegetablesIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Ensaymada: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << ensaymadaIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Coke Zero: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << cokeZeroIngredients[i] << endl;
          }

          break;

        case 3: // Displays Combo Meal 3 Ingredients
          cout << "\t\t\t\t\t\t\tViewing Ingredients for Combo Meal 3" << '\n';

          cout << "\n\t\t\t\t\t\t\tIngredients for Sinigang na Bangus: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangBangusIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Coleslaw: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << coleslawIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Pan de Coco: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << panDeCocoIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Iced Tea: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << icedTeaIngredients[i] << endl;
          }

          break;

        case 4: // Displays Combo Meal 4 Ingredients
          cout << "\t\t\t\t\t\t\tViewing Ingredients for Combo Meal 4" << '\n';

          cout << "\n\t\t\t\t\t\t\tIngredients for Sinigang na Salmon: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sinigangSalmonIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Steam Asparagus: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << steamedAsparagusIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Croissant: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << croissantIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Lemonade: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << lemonadeIngredients[i] << endl;
          }

          break;

        case 5: // Displays Combo Meal 5 Ingredients
          cout << "\t\t\t\t\t\t\tViewing Ingredients for Combo Meal 5" << '\n';

          cout << "\n\t\t\t\t\t\t\tIngredients for Kare-Kare: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << kareKareIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Roasted Brussel Sprouts: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << brusselsSproutsIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Eclair: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << eclairIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Iced Coffee: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << icedCoffeeIngredients[i] << endl;
          }

          break;

        case 6: // Displays Combo Meal 6 Ingredients
          cout << "\t\t\t\t\t\t\tViewing Ingredients for Combo Meal 6" << '\n';

          cout << "\n\t\t\t\t\t\t\tIngredients for Lechon Kawali: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << LechonKawaliIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Caprese Salad: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << capreseSaladIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Tiramisu: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << tiramisuIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Watermelon Shake: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << watermelonShakeIngredients[i] << endl;
          }

          break;

        case 7: // Displays Combo Meal 7 Ingredients
          cout << "\t\t\t\t\t\t\tViewing Ingredients for Combo Meal 7" << '\n';

          cout << "\n\t\t\t\t\t\t\tIngredients for Bistek Tagalog: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << bistekIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Quinoa Salad: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << quinoaSaladIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Churros: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << churrosIngredients[i] << endl;
          }

          cout << "\n\t\t\t\t\t\t\tIngredients for Mango Shake: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << mangoShakeIngredients[i] << endl;
          }

          break;

      }
      break;

    case 4: // Pastries

      switch (choice) {
        case 1:
          cout << "\t\t\t\t\t\t\tIngredients for Macarons: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << macaronsIngredients[i] << endl;
          }
          break;

        case 2:
          cout << "\t\t\t\t\t\t\tIngredients for Ensaymada: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << ensaymadaIngredients[i] << endl;
          }
          break;

        case 3:
          cout << "\t\t\t\t\t\t\tIngredients for Pan De Coco: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << panDeCocoIngredients[i] << endl;
          }
          break;

        case 4:
          cout << "\t\t\t\t\t\t\tIngredients for Croissant: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << croissantIngredients[i] << endl;
          }
          break;

        case 5:
          cout << "\t\t\t\t\t\t\tIngredients for Eclair: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << eclairIngredients[i] << endl;
          }
          break;

        case 6:
          cout << "\t\t\t\t\t\t\tIngredients for Tiramisu: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << tiramisuIngredients[i] << endl;
          }
          break;

        case 7:
          cout << "\t\t\t\t\t\t\tIngredients for Churros: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << churrosIngredients[i] << endl;
          }
          break;

      }

      break;

    case 5: // Beverages

      switch (choice) {
        case 1:
          cout << "\t\t\t\t\t\t\tIngredients for Coke: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << cokeIngredients[i] << endl;
          }
          break;

        case 2:
          cout << "\t\t\t\t\t\t\tIngredients for Coke Zero: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << cokeZeroIngredients[i] << endl;
          }
          break;

        case 3:
          cout << "\t\t\t\t\t\t\tIngredients for Iced Tea: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << icedTeaIngredients[i] << endl;
          }
          break;

        case 4:
          cout << "\t\t\t\t\t\t\tIngredients for Lemonade: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << lemonadeIngredients[i] << endl;
          }
          break;

        case 5:
          cout << "\t\t\t\t\t\t\tIngredients for Iced Coffee: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << icedCoffeeIngredients[i] << endl;
          }
          break;

        case 6:
          cout << "\t\t\t\t\t\t\tIngredients for Watermelon Shake: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << watermelonShakeIngredients[i] << endl;
          }
          break;

        case 7:
          cout << "\t\t\t\t\t\t\tIngredients for Mango Shake: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << mangoShakeIngredients[i] << endl;
          }
          break;

        case 8:
          cout << "\t\t\t\t\t\t\tIngredients for Water: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << waterIngredients[i] << endl;
          }
          break;
      }
      break;

    case 6: // Desserts Ingredients Output
      switch (choice) {
        case 1: // Shows ingredients for Halo-Halo
          cout << "\t\t\t\t\t\t\tIngredients for Halo-Halo: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << haloHaloIngredients[i] << endl;
          }
          break;

        case 2: // Shows ingredients for Leche Flan
          cout << "\t\t\t\t\t\t\tIngredients for Leche Flan: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << lecheFlanIngredients[i] << endl;
          }
          break;

        case 3: // Shows ingredients for Banana Cue
          cout << "\t\t\t\t\t\t\tIngredients for Banana Cue: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << bananaCueIngredients[i] << endl;
          }
          break;

        case 4: // Shows ingredients for Taho
          cout << "\t\t\t\t\t\t\tIngredients for Taho: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << tahoIngredients[i] << endl;
          }
          break;

        case 5: // Shows ingredients for Turon
          cout << "\t\t\t\t\t\t\tIngredients for Turon: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << turonIngredients[i] << endl;
          }
          break;

        case 6: // Shows ingredients for Puto Cheese
          cout << "\t\t\t\t\t\t\tIngredients for Puto Cheese: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << putoCheeseIngredients[i] << endl;
          }
          break;

        case 7: // Shows ingredients for Suman
          cout << "\t\t\t\t\t\t\tIngredients for Suman: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << sumanIngredients[i] << endl;
          }
          break;

        case 8: // Shows ingredients for Pichi-Pchi
          cout << "\t\t\t\t\t\t\tIngredients for Pichi-Pichi: " << '\n';

          for (int i = 0; i < 10; i++) {
            cout << "\t\t\t\t\t\t\t" << pichiPichiIngredients[i] << endl;
          }
          break;

      }
      break;

  }

  cout << "\n\n";
  cout << "\t\t\t\t\t\t\tPress any key to return to the previous menu...";
  _getch(); // User inputs any key to return to the main menu.
  return true;
}

int viewNutrientFacts(int foodChoice) {
  system("cls");

  // Food list of main course
  string mainCourseList[] = {
    "Sinigang na Baboy",
    "Sinigang na Hipon",
    "Sinigang na Bangus",
    "Sinigang na Salmon",
    "Kare Kare",
    "Lechon Kawali",
    "Bistek Tagalog",
    "Pork Sisig"
  };

  // Food list of side dishes
  string sideDishList[] = {
    "Garlic Mashed Potatoes",
    "Grilled Vegetables",
    "Coleslaw",
    "Steamed Asparagus",
    "Roasted Brussels Sprouts",
    "Caprese Salad",
    "Quinoa Salad",
    "Sautéed Spinach"
  };

  // List of combo meals
  string comboMealsList[] = {
    "Combo Meal 1",
    "Combo Meal 2",
    "Combo Meal 3",
    "Combo Meal 4",
    "Combo Meal 5",
    "Combo Meal 6",
    "Combo Meal 7" 
  };

  // Food list of pastries
  string pastriesList[] = {
    "Macarons",
    "Ensaymada",
    "Pan de Coco",
    "Croissant",
    "Éclair",
    "Tiramisu",
    "Churros"
  };

  // Drink list of beverages
  string beverageList[] = {
    "Coke",
    "Coke Zero",
    "Iced Tea",
    "Lemonade",
    "Iced Coffee",
    "Watermelon Shake",
    "Mango Shake",
    "Water"
  };

  // Food list of desserts
  string dessertsList[] = {
    "Halo-Halo",
    "Leche Plan",
    "Banana Cue",
    "Taho",
    "Turon",
    "Puto Cheese",
    "Suman",
    "Pichi-Pichi"
  };

  string nutrientFactsMainCourse[] = {
    "Sinigang na Baboy: 290 calories, 47g fat, 34g protein",
    "Sinigang na Hipon: 139 calories, 1.71g fat, 20.78g protein",
    "Sinigang na Bangus: 281 calories, 12.40g fat, 38.22g protein",
    "Sinigang na Salmon: 170 calories, 9g fat, 20.79g protein",
    "Kare Kare: 523 calories, 36g fat, 31g protein",
    "Lechon Kawali: 322 calories, 26.09g fat, 18.06g protein",
    "Bistek Tagalog: 210 calories, 12g fat, 19g protein",
    "Pork Sisig: 215 calories, 14.45g fat, 16.24g protein" 
  };

  string nutrientFactsSideDish[] = {
    "Garlic Mashed Potatoes: 200 calories, 8g fat, 4g protein",
    "Grilled Vegetables: 120 calories, 5g fat, 3g protein",
    "Coleslaw: 150 calories, 10g fat, 2g protein",
    "Steamed Asparagus: 40 calories, 2g fat, 4g protein",
    "Roasted Brussels Sprouts: 90 calories, 6g fat, 3g protein",
    "Caprese Salad: 250 calories, 18g fat, 10g protein",
    "Quinoa Salad: 180 calories, 6g fat, 8g protein",
    "Sautéed Spinach: 70 calories, 5g fat, 4g protein"
  };

  string nutrientFactsPastries[] = {
    "Macarons: 160 calories, 3g of fat, 4g of protein",
    "Ensaymada: 244 calories, 17g of fat, 3.6g of protein",
    "Pan de Coco: 146 calories, 6g of fat, 17g of protein",
    "Croissant: 231 calories, 12g of fat, 5g of protein",
    "Éclair: 355 calories, 12g of fat, 4g of protein",
    "Tiramisu: 513 calories, 35g of fat, 9g of protein",
    "Churros: 70 calories, 4g of fat, 1g of protein"
  };

  string nutrientFactsBeverages[] = {
    "Coke: 140 calories, 0g fat, 0g protein",
    "Coke Zero: 0 calories, 0g fat, 0g protein",
    "Iced Tea: 40 calories, 0g fat, 0g protein",
    "Lemonade: 110 calories, 0g fat, 0g protein",
    "Iced Coffee: 2 calories, 0.1g fat, 0.3g protein",
    "Watermelon Shake: 80 calories, 0.5g fat, 1g protein",
    "Mango Shake: 120 calories, 0.5g fat, 1g protein",
    "Water: 0 calories, 0g fat, 0g protein"
  };

  string nutrientFactsDesserts[] = {
    "Halo Halo: 350 calories, 10g fat, 5g protein",
    "Leche Flan: 200 calories, 8g fat, 4g protein",
    "Banana Cue: 150 calories, 5g fat, 2g protein",
    "Taho: 180 calories, 6g fat, 3g protein",
    "Turon: 220 calories, 8g fat, 4g protein",
    "Puto Cheese: 120 calories, 4g fat, 2g protein",
    "Suman: 160 calories, 5g fat, 3g protein",
    "Pichi-Pichi: 250 calories, 12g fat, 5g protein"
  };

  switch (foodCount) { // Switch case for viewing of the nutrient facts of different items in the menu.
    case 1:
      cout << "\t\t\t\t\tYou have chosen to view the nutrient facts of " << mainCourseList[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsMainCourse[foodChoice - 1] << '\n';
      cout << "\n\n";
      cout << "\t\t\t\t\t";
      break;

    case 2:
      cout << "\t\t\t\t\tYou have chosen to view the nutrient facts of " << sideDishList[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsSideDish[foodChoice - 1] << '\n';
      cout << "\n\n";
      cout << "\t\t\t\t\t";
      break;

    case 3:
      cout << "\t\t\t\t\tYou have chosen to view the nutrient facts of " << comboMealsList[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsMainCourse[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsSideDish[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsPastries[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsBeverages[foodChoice - 1] << '\n';
      cout << "\n\n";
      cout << "\t\t\t\t\t";
      break;

    case 4:
      cout << "\t\t\t\t\tYou have chosen to view the nutrient facts of " << pastriesList[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsPastries[foodChoice - 1] << '\n';
      cout << "\n\n";
      cout << "\t\t\t\t\t";
      break;

    case 5:
      cout << "\t\t\t\t\tYou have chosen to view the nutrient facts of " << beverageList[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsBeverages[foodChoice - 1] << '\n';
      cout << "\n\n";
      cout << "\t\t\t\t\t";
      break;

    case 6:
      cout << "\t\t\t\t\tYou have chosen to view the nutrient facts of " << dessertsList[foodChoice - 1] << '\n';
      cout << '\n';
      cout << "\t\t\t\t\tNutrient Facts for " << nutrientFactsDesserts[foodChoice - 1] << '\n';
      cout << "\n\n";
      cout << "\t\t\t\t\t";
      break;
  }

  cout << "Press any key to return to the previous menu...";
  _getch(); // User inputs any key to return to the main menu.
  return true;
}

// Function that takes in the order of the customer
void orderFood(string foodName, int foodPrice, int tableNumber, int foodChoice) { // Takes in food, price, and table number.
  int numOfFood;
  char choice;
  double total = 0;
  string fileName, takeoutFileName;
  ofstream orders;
  ofstream takeOutOrders;
  
  if (orderChoice == 1) {
    fileName = "OrderTable_" + to_string(tableNumber) + ".txt"; // File name for Dine In orders.
  } else if (orderChoice == 2) {
    takeoutFileName = "TakeOut.txt"; // File name for Take Out orders
  }
  

  if (notComboMeal == 1) {
    cout << "\n\t\t\t\t\t\t\tHow many " << foodName << " would you like to order? ";
  } else if (notComboMeal == 0) {
    cout << "\n\t\t\t\t\t\t\tHow many Combo Meal " << foodChoice << " would you like to order? ";
  }
  
  while (!(cin >> numOfFood) || numOfFood <= 0) { // Input checking in case user types a letter or a negative number.
    changeConsoleColor(RED);
    cout << "\t\t\t\t\t\t\tInvalid quantity. Please input a positive number: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    changeConsoleColor(AQUA);
  }

  total = foodPrice * numOfFood;

  cout << "\n\t\t\t\t\t\t\tYour order for " << numOfFood << " " << foodName << " has been placed." << '\n';

  if (orderChoice == 1) {
    orders.open(fileName, ios::app); // Creates a file for dine in orders. app allows for file to append food items
  } else if (orderChoice == 2) {
    takeOutOrders.open(takeoutFileName, ios::app); // Creates a file for take out orders. app allows for file to append food items

    if (takeOutOrders.is_open()) {
      takeOutOrders << "Item: " << foodName << ", Quantity: " << numOfFood << ", PHP " << total << endl; // Inputs the order of the customer into the txt file.
      takeOutOrders.close();
      
      cout << "\n\t\t\t\t\t\t\t";

      system("pause");

      cout << "\n\t\t\t\t\t\t\tDo you want to continue ordering? (Y / N): ";

      cin >> choice;

      if (choice == 'Y' || choice == 'y') {
        chooseRestaurantMenu(tableNumber);

      } else if (choice == 'N' || choice == 'n') {
        cout << "\n\t\t\t\t\t\t\tSaving orders";

        for (int i = 0; i < 5; i++) {
          cout << ".";
          Sleep(500);
        }
        cout << "\n\n\t\t\t\t\t\t\t";
        system("pause");

        forDiscount(tableNumber);
      }
    } else {
        changeConsoleColor(RED);
        cout << "\t\t\t\t\t\t\tSystem Error: Order files can't be opened." << '\n';
        changeConsoleColor(AQUA);
    }
  }

  if (orders.is_open()) { // Check if the dine in order file is open.
    orders << "Item: " << foodName << ", Quantity: " << numOfFood << " PHP " << total << endl; // Inputs the order of the customer into the txt file.
    orders.close();
    
    cout << "\n\t\t\t\t\t\t\t";

    system("pause");

    do {
      cout << "\n\t\t\t\t\t\t\tDo you want to continue ordering? (Y / N): ";
      cin >> choice;

      if (choice == 'Y' || choice == 'y') {
        chooseRestaurantMenu(tableNumber);

      } else if (choice == 'N' || choice == 'n') {

        cout << "\t\t\t\t\t\t\tSaving orders";

        for (int i = 0; i < 5; i++) {
          cout << ".";
          Sleep(500);
        }

        cout << "\n\n\t\t\t\t\t\t\t";
        system("pause");

        forDiscount(tableNumber);
      }

      if (cin.fail(), choice != 'y', choice != 'Y', choice != 'N', choice != 'n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

    } while (cin.fail(), choice != 'y', choice != 'Y', choice != 'N', choice != 'n');

  } else {
    changeConsoleColor(RED);
    cout << "\t\t\t\t\t\t\tSystem Error: Order files can't be opened." << '\n';
    changeConsoleColor(AQUA);
  }
}

void forDiscount(int tableNumber) {
  int choice, idNumber;
  bool appliedVoucherDiscount = false; // Flag to indicate if voucher discount applied
  bool goBackToDiscountMenu = true; // Set to true to enter the loop initially

  do {
    system("cls");

    cout << "\t\t\t\t\t\t\t\t\t -------------" << '\n';
    cout << "\t\t\t\t\t\t\t\t\t For Discount " << '\n';
    cout << "\t\t\t\t\t\t\t\t\t -------------" << '\n';

    cout << '\n';

    cout << " \t\t\t\t\t\t -------------------- " << " -------------------- " << " -------------------- " << '\n';
    cout << " \t\t\t\t\t\t -                  - " << " -                  - " << " -                  - " << '\n';
    cout << " \t\t\t\t\t\t -    PWD/Senior    - " << " -      VOUCHER     - " << " -      PAYMENT     - " << '\n';
    cout << " \t\t\t\t\t\t -                  - " << " -                  - " << " -                  - " << '\n';
    cout << " \t\t\t\t\t\t -       [ 1 ]      - " << " -       [ 2 ]      - " << " -       [ 3 ]      - " << '\n';
    cout << " \t\t\t\t\t\t -                  - " << " -                  - " << " -                  - " << '\n';
    cout << " \t\t\t\t\t\t -------------------- " << " -------------------- " << " -------------------- " << '\n';
    cout << "\n\n";
    cin.clear();

    cout << "\t\t\t\t\t\t\t\tPlease choose your option: ";

    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\t\t\tPlease choose your option: ";
      changeConsoleColor(AQUA);
    }

    if (choice == 1) {
      // PWD/Senior discount
      system("cls");
      cout << " \t\t\t\t\t\t     -----------------------------" << endl;
      cout << " \t\t\t\t\t\t     Senior Citizen / PWD ID Form " << '\n';
      cout << " \t\t\t\t\t\t     -----------------------------" << '\n';
      cout << endl;
      cout << endl;
      cout << " \t\t\t\t\t    Please fill out the following forms: " << '\n';

      string name;
      cout << " \n\t\t\t\t\t    Name: ";
      cin.ignore(); // Ignore previous newline character
      getline(cin, name); // Gets the customer's name

      do {

        cout << "\n\t\t\t\t\t    ID Number (5 Digits): ";
        cin >> idNumber; // Gets the customer's ID Number

        if (cin.fail() || idNumber < 10000 || idNumber > 99999) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            changeConsoleColor(RED);
            cout << "\t\t\t\t\t    Please enter a valid 5-digit ID Number." << '\n';
            changeConsoleColor(AQUA);
        }

      } while (cin.fail() || idNumber < 10000 || idNumber > 99999);

        verifiedPWDOrSenior = true;

        cout << "\t\t\t\t\t    Verifying ID";
        
        for (int i = 0; i < 6; i++) {
            cout << ".";
            Sleep(500);
        }

          system("cls");
          cout << "\n\n\n\n\n";
          cout << "\t\t\t\t\t ID Successfully Verified." << '\n';

          cout << "\n\t\t\t\t\t";
          system("pause");

      } else if (choice == 2) {
          // Voucher discount
          string voucher;

      do {

        system("cls");
        cout << " \t\t\t\t\t\t     -----------------------------" << '\n';
        cout << " \t\t\t\t\t\t                Voucher           " << '\n';
        cout << " \t\t\t\t\t\t     -----------------------------" << '\n';
        cout << "\t\t\t\t\tEnter voucher code (or press 'x' to go back to the For Discount Menu): ";
        cin.clear();
        cin >> voucher;

        if (voucher == "POGINISIRPURA" || voucher == "RMSPROGRAM" || voucher == "2NDTERM") {
            cout << "\n\t\t\t\t\tVoucher applied! You get a 10% discount." << '\n';
            validVoucher = true;
            break;
        } else if (voucher == "x" || voucher == "X") {
            // Go back to the discount menu
            validVoucher = false;
            break;
        } else {
            cout << "\n\t\t\t\t\tInvalid voucher code. No discount applied." << '\n';
            system("pause");
        }

      } while (true);

      } else if (choice == 3) {

          // Proceed to payment
          if (!verifiedPWDOrSenior && !validVoucher) {
              cout << "\n\t\t\t\t\tNo discount applied." << '\n';
          }

          cout << "\n\t\t\t\t\t";
          system("pause");
          choosePayment(tableNumber);

      }

      // Ask if the user wants to go back to the discount menu
      char goBackChoice;
      do {
          cout << "\n\t\t\t\t\tDo you want to go back to the For Discount menu (y/n): ";
          cin >> goBackChoice;
          if (tolower(goBackChoice) == 'y' || tolower(goBackChoice) == 'n') {
              break;
          } else {
              cout << "\n\t\t\t\t\tInvalid input. Please enter 'y' for Yes or 'n' for No." << '\n';
          }
      } while (true);

    goBackToDiscountMenu = (tolower(goBackChoice) == 'y'); // Update the loop control variable

  } while (goBackToDiscountMenu);


  if (!goBackToDiscountMenu) { // If the user chooses not to go back to the discount menu, proceed to payment
    choosePayment(tableNumber);
  }

}

void choosePayment(int tableNumber) {
  int choice;
    
  system ("cls");
  cout << " \t\t\t\t\t\t\t --------------------------------------------" << endl;
  cout << " \t\t\t\t\t\t\t      Please choose your payment option"       << '\n';
  cout << " \t\t\t\t\t\t\t --------------------------------------------" << '\n';
  cout << "\n\n";
  cout << " \t\t\t\t\t\t -------------------- " << " -------------------- " << " -------------------- " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " -                  - " << " -                  - " << '\n';
  cout << " \t\t\t\t\t\t -       CASH       - " << " -       CARD       - " << " -    E - WALLET    - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " -                  - " << " -                  - " << '\n';
  cout << " \t\t\t\t\t\t -  --------------  - " << " -  --------------  - " << " -  --------------  - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " -                  - " << " -                  - " << '\n';
  cout << " \t\t\t\t\t\t -       [ 1 ]      - " << " -       [ 2 ]      - " << " -       [ 3 ]      - " << '\n';
  cout << " \t\t\t\t\t\t -                  - " << " -                  - " << " -                  - " << '\n';
  cout << " \t\t\t\t\t\t -------------------- " << " -------------------- " << " -------------------- " << '\n';
  cout << "\n\n";

  do {
    cout << "\t\t\t\t\t\t\t Please input your option: ";
 
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        changeConsoleColor(RED);
        cout << "\t\t\t\t\t\t\t Invalid choice. Please try again." << '\n';
        changeConsoleColor(AQUA);
        cout << "\t\t\t\t\t\t\t Please input your option: ";
    }

    if (choice < 1 || choice > 3) {
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\t\t Invalid choice. Please input a proper choice." << '\n';
      changeConsoleColor(AQUA);
    }

    switch (choice) {
      case 1:
        // Sets mode of payment to 1 for cash
        modeOfPayment = 1;
        break;

      case 2:
        // Sets mode of payment to 2 for card
        modeOfPayment = 2;
        break;

      case 3:
        // Sets mode of payment to 3 for e-wallet
        modeOfPayment = 3;
        break;
    }
  } while (choice < 1 || choice > 3);

  cout << "\t\t\t\t\t\t\t";
  system("pause");

  displayReceipt(tableNumber);
}

int getRandomOrderNumber() {
	srand(time(0)); //random number generator
	return rand() % 9999 + 1000; // generate a random number between 1000 to 9999
}

void displayReceipt(int tableNumber) { // Displays the receipt of the orders.
  string fileName;
  string line;
  double total = 0;
  double discount = 0;
  double discountVoucher = 0;

  if (orderChoice == 1) {
    fileName = "OrderTable_" + to_string(tableNumber) + ".txt";
  } else if (orderChoice == 2) {
    fileName = "TakeOut.txt";
  }

  ifstream file(fileName);

  system("cls");

  if (file.is_open()) {
    cout << "\t\t\t\t\t\t ======================================================== " << '\n';
    cout << "\t\t\t\t\t\t           O  R  D  E  R     R  E  C  E  I  P  T          " << '\n';
    cout << "\t\t\t\t\t\t ======================================================== " << '\n';
    cout << "\t\t\t\t\t\t                     <<<- SUEÑO ->>>                      " << '\n';

    if (orderChoice == 1) {
      cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';
      cout << "\t\t\t\t\t\t                         DINE IN                          " << '\n';
    } else if (orderChoice == 2) {
      cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';
      cout << "\t\t\t\t\t\t                         TAKE OUT                         " << '\n';
    }
    cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';
    
    while (getline(file, line)) { // Gets the orders from the file using a while loop.
      size_t itemPos = line.find("Item: ");
      size_t quantityPos = line.find("Quantity: ");
      size_t totalPos = line.find("PHP ");

      if (itemPos != string::npos && quantityPos != string::npos && totalPos != string::npos) { 

          string item = line.substr(itemPos + 6, quantityPos - itemPos - 8);
          string quantity = line.substr(quantityPos + 10, totalPos - quantityPos - 11);
          string totalStr = line.substr(totalPos + 4);
          total += stod(totalStr);

          cout << "\t\t\t\t\t\t " << setw(15) << left << quantity << setw(30) << left << item << setw(10) << right << totalStr << endl;

      }
    }

    if (verifiedPWDOrSenior && validVoucher) { // Applies a 20% discount for verified senior citizens or PWDs.

      discount = total * 0.20;
      discountVoucher = total * 0.10;
      total -= (discount + discountVoucher);
      cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';
      cout << "\t\t\t\t\t\t SENIOR CITIZEN (20%)" << setw(31) << "-" << discount << '\n';
      cout << "\t\t\t\t\t\t VOUCHER        (10%)" << setw(31) << "-" << discountVoucher << '\n'; 

    } else if (verifiedPWDOrSenior) {
      cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';
      cout << "\t\t\t\t\t\t SENIOR CITIZEN (20%)" << setw(31) << "-" << discount << '\n';
    } else if (validVoucher) {
      cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';
      cout << "\t\t\t\t\t\t VOUCHER        (10%)" << setw(31) << "-" << discountVoucher << '\n'; 
    }

    cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';
    cout << "\t\t\t\t\t\t Total: " << setw(43) << right << "PHP " << total << '\n';
    cout << "\t\t\t\t\t\t -------------------------------------------------------- " << '\n';


    file.close();

  } else {

    cout << "\t\t\t\t\t\tFile can't be opened." << '\n'; 

  }

  cout << "\t\t\t\t\t\t\t\t";
  system("pause");

  switch (modeOfPayment) { // Switch statement for mode of payment.
    
    case 1:
      cashPayment(total);
      break;

    case 2:
      cardPayment(total);
      break;

    case 3:
      eWalletPayment(total);
      break;
    
  }

  choosePayment(total);
}

void cashPayment(double total) {
  int cash;
  bool validCash = false;
  cout << "\n\n\n";
  cout << "\t\t\t\t\t\t\t--------------------------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t   You have chosen cash as payment option   " << '\n';
  cout << "\t\t\t\t\t\t\t--------------------------------------------" << '\n';
  cout << "\t\t\t\t\t\t\tTotal: PHP " << total << "\n\n\n";

  do {
      cout << "\t\t\t\t\t\t\tEnter Received Cash: ";
      cin >> cash;

      if (cash < total) {
        changeConsoleColor(RED);
        cout << "\t\t\t\t\t\t\tYou don't have enough funds. Please enter a higher amount.\n";
        changeConsoleColor(AQUA);
      } else {
        validCash = true;
      }

  } while (!validCash);

  cout << "\n\t\t\t\t\t\t\tYour Change is " << cash - total << "\n";

  cout << "\n\t\t\t\t\t\t\t";

  system("pause");

  thankCustomer();
}

void cardPayment(double total) {
  string cardNumber;
  int cardExpireMonth, cardExpireYear;
  int cvv;

  cout << "\n\n\n";
  cout << "\t\t\t\t\t\t\t--------------------------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t   You have chosen cash as payment option   " << '\n';
  cout << "\t\t\t\t\t\t\t--------------------------------------------" << '\n';
  cout << "\t\t\t\t\t\t\tTotal: PHP " << total << "\n\n\n";

  do { // Gets the card's number.

    cout << "\t\t\t\t\t\t\tEnter Card Number: ";
    cin >> cardNumber;

    if (!cardNumberValid(cardNumber)) {
      
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\t\tInvalid card number. Please enter a valid 16-digit card number.\n";
      changeConsoleColor(AQUA);
      
    }

  } while(!cardNumberValid(cardNumber));

  do { // Gets the card's expiry month.

    cout << "\n\t\t\t\t\t\t\tEnter Expiry Month (MM): ";
    cin >> cardExpireMonth;

    if (!expiryMonthValid(cardExpireMonth)) {
      changeConsoleColor(RED);
      cout << "\n\t\t\t\t\t\t\tInvalid expiry month. Please enter a valid month (1-12).\n";
      changeConsoleColor(AQUA);
    }

  } while (!expiryMonthValid(cardExpireMonth));

  do { // Gets the card's expiry year.
    cout << "\n\t\t\t\t\t\t\tEnter Expiry Year (YYYY): ";
    cin >> cardExpireYear;

    if (!isValidExpiryYear(cardExpireYear)) {
        changeConsoleColor(RED);
        cout << "\n\t\t\t\t\t\t\tInvalid expiry year. Please enter a valid year (2022-2030).\n";
        changeConsoleColor(AQUA);
    }

    } while (!isValidExpiryYear(cardExpireYear));

  do { // Gets the card's CVV.
    cout << "\n\t\t\t\t\t\t\tEnter CVV: ";
    cin >> cvv;

    if (!isValidCVV(cvv)) {
        changeConsoleColor(RED);
        cout << "\n\t\t\t\t\t\t\tInvalid CVV. Please enter a valid 3-digit CVV.\n";
        changeConsoleColor(AQUA);
    }

  } while (!isValidCVV(cvv));

  cout << "\n\t\t\t\t\t\t\t";

  system("pause");

  thankCustomer();
}

void eWalletPayment(double total) {
  string mobileNumber, pin;

  cout << "\n\n\n";
  cout << "\t\t\t\t\t\t\t--------------------------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t You have chosen E-Wallet as payment option " << '\n';
  cout << "\t\t\t\t\t\t\t--------------------------------------------" << '\n';
  cout << "\t\t\t\t\t\t\tTotal: PHP " << total << "\n\n\n";

  do {
    cout << "\n\t\t\t\t\t\t\tPlease input your Mobile Number: ";
    cin >> mobileNumber;

    cout << "\n\t\t\t\t\t\t\tEnter your PIN: ";
    cin >> pin;

    if (!isValidNumberAndPin(mobileNumber, pin)) {
      changeConsoleColor(RED);
      cout << "\n\t\t\t\t\t\t\tInvalid mobile number or PIN length." << '\n';
      changeConsoleColor(AQUA);
    }

  } while (!isValidNumberAndPin(mobileNumber, pin));

  cout << "\n\t\t\t\t\t\t\t";

  system("pause");

  thankCustomer();
}

void thankCustomer() {
  system("cls");

  cout << "\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t\tProcessing payment";

  for (int i = 0; i < 5; i++) {
    cout << ".";
    Sleep(500);
  }

  system("cls");

   cout << "\n\n\n\n\n\n\n\n";

  cout << "\t\t\t\t\t\t\t\t\tWe have received your payment!" << "\n\n";

  cout << "\t\t\t\t\t\t\t\t\tThank you for ordering with us!" << "\n\n";

  cout << "\t\t\t\t\t\t\t\t\t";
  system("pause");

  exit(1);
}

bool cardNumberValid(const string& cardNumber) { // Validates if the card number is valid or not using regex.

  return regex_match(cardNumber,regex("\\d{16}"));

}

bool expiryMonthValid(int month) { // Checks if the month given is correct.

  return month >= 1 && month <= 12;

}

bool isValidExpiryYear(int year) { // Validates the card to check if it expired already.

  return year >= 2022 && year <= 2030;

}

bool isValidCVV(int cvv) {

  return cvv >= 100 && cvv <= 999;

}

bool isValidNumberAndPin(const string& mobileNumber, const string& pin) {
  return (mobileNumber.length() == 11 && pin.length() == 4);
}

void changeConsoleColor(int color) { // Function that allows to change the console's text easily.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}