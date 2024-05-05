#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// Variables for colors
#define AQUA 3
#define BLUE 9
#define GREEN 10
#define RED 12
#define BEIGE 14
#define WHITE 15

// Function Prototypes
void mainMenu();
void managerConfirmation();
void employeeConfirmation();
void employeePage();
void managerPage();
void addEmployees();
void viewOrders();
void viewSupplies();
void addSupplies();
bool isProperId(int idNumber);
void changeConsoleColor(int color);

// Struct for supplies

struct Supply {
  string category;
  string name;
  int quantity;
};

// Global Variables
string employeeDatabase = "employee_database.txt";
int verifyManager; // Verification status of manager

int main() {

  mainMenu();

  return 0;
}

void mainMenu() { // Menu that lets the user choose if they are the manager or the employee.
  int choice;

  changeConsoleColor(AQUA);

  system("cls");

  cout << "\t\t\t\t\t\t ---------------------------" << '\n';
  cout << "\t\t\t\t\t\t         Welcome! " << '\n';
  cout << "\t\t\t\t\t\t ---------------------------" << '\n';
  cout << "\t\t\t\t\t\t Please select your option" << '\n';
  cout << "\t\t\t\t\t\t ---------------------------" << '\n';
  cout << '\n';
  cout << "\t\t\t\t\t --------------------\t" << "--------------------" << '\n';
  cout << "\t\t\t\t\t -                  -\t" << "-                  -" << '\n';
  cout << "\t\t\t\t\t -     EMPLOYEE     -\t" << "-      MANAGER     -" << '\n';
  cout << "\t\t\t\t\t -                  -\t" << "-                  -" << '\n';
  cout << "\t\t\t\t\t -      [ 1 ]       -\t" << "-       [ 2 ]      -" << '\n';
  cout << "\t\t\t\t\t -                  -\t" << "-                  -" << '\n';
  cout << "\t\t\t\t\t --------------------\t" << "--------------------" << '\n';
  cout << '\n';
  cout << '\n';

  do {
    cout << "\t\t\t\t\t\tPlease choose your option: ";

    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\t\t\t\t\t\tPlease choose your option: ";
    }

    if (choice < 1 || choice > 2) {
      cout << "\t\t\t\t\t\tPlease choose a correct option." << '\n';
    }

  } while (choice < 1 || choice > 2);

  switch (choice) {
    case 1:
      employeeConfirmation();
      break;

    case 2:
      managerConfirmation();
      break;
  }
}

void managerConfirmation() {
  string managerUsername, managerPassword;

  system("cls");

  cout << "\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\tPlease input your username: ";
  cin >> managerUsername;
  cout << "\t\t\t\t\tPlease input your password: ";
  
  char passKey;
  managerPassword = "";

  while (true) { // Changes password to asterisks(*) so that no one can see you typing your password
    passKey = _getch();

    if (passKey == 13)
      break;

    if (passKey == 8) { // Removes password using backspace (Previously adds asterisk when pressing backspace)

      if (!managerPassword.empty()) {
        managerPassword.pop_back();
        cout << "\b \b";
      }

    } else {
        managerPassword.push_back(passKey);
        cout << '*';
    }   
  }

  cin.ignore();

  if (managerUsername == "admin" && managerPassword == "admin123") { // If credentials matches, it goes to the main page.
    managerPage();
  }

  while (managerUsername != "admin" && managerPassword != "admin123") { // If the manager inputs the wrong username or password.
    system("cls");

    changeConsoleColor(RED); // Changes text to red
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\tYour username or password is incorrect." << "\n\n";

    changeConsoleColor(AQUA);

    // Just a copy of the code from above.

    cout << "\t\t\t\t\tPlease input your username: ";
    cin >> managerUsername;
    cout << "\t\t\t\t\tPlease input your password: ";

    while (true) { 
      passKey = _getch();

      if (passKey == 13)
        break;

      if (passKey == 8) { 

        if (!managerPassword.empty()) {
          managerPassword.pop_back();
          cout << "\b \b";
        }

      } else {
          managerPassword.push_back(passKey);
        cout << '*';
      }
    }

    if (managerUsername == "admin" && managerPassword == "admin123") {
      managerPage();
    }
  }
}

void managerPage() {
  int choice;
  verifyManager = 1; // 1 means that the user is the Manager

  system("cls");

  cout << "\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t\t\t\tLoading Manager's Page";

  for (int i = 0; i < 5; i++) {
    cout << ".";
    Sleep(500);
  }

  system("cls");

  cout << "\n\n\n\n";
  cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t\t       Welcome Manager!     " << '\n';
  cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t\t  Please select your option " << '\n';
  cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';
  cout << " " << '\n';
  cout << "\t\t\t\t--------------------" << "\t--------------------" << "\t--------------------" << "\t--------------------" << "\t--------------------" << '\n';
  cout << "\t\t\t\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << '\n';
  cout << "\t\t\t\t-       ADD        -" << "\t-       VIEW       -" << "\t-       VIEW       -" << "\t-       SERVE      -" << "\t-     SIGN OUT     -" << '\n';
  cout << "\t\t\t\t-     EMPLOYEES    -" << "\t-      ORDERS      -" << "\t-     SUPPLIES     -" << "\t-      ORDERS      -" << "\t-                  -" << '\n';
  cout << "\t\t\t\t-  --------------  -" << "\t-  --------------  -" << "\t-  --------------  -" << "\t-  --------------  -" << "\t-  --------------  -" << '\n';
  cout << "\t\t\t\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << '\n';
  cout << "\t\t\t\t-      [ 1 ]       -" << "\t-       [ 2 ]      -" << "\t-      [ 3 ]       -" << "\t-      [ 4 ]       -" << "\t-      [ 5 ]       -" << '\n';
  cout << "\t\t\t\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << '\n';
  cout << "\t\t\t\t--------------------" << "\t--------------------" << "\t--------------------" << "\t--------------------" << "\t--------------------" << '\n';
  cout << '\n';
  cout << '\n';

  do {
    cout << "\t\t\t\t\t\t\t\tPlease choose your option: ";
    
    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\t\t\t\t\t\t\t\tPlease choose your option: ";
    }

    if (choice < 1 || choice > 5) {
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\t\t\tPlease choose a proper option." << '\n';
      changeConsoleColor(AQUA);
    }

    switch (choice) {
      case 1:
        addEmployees();
        break;
      
      case 2:
        viewOrders();
        break;

      case 3:
        viewSupplies();
        break;

      case 4:
        break;

      case 5:
        mainMenu();
        break;
    }

  } while (choice < 1 || choice > 5);
}

void employeeConfirmation() {
  string employeeName, line;
  int employeeID;
  bool employeeExists;

  system("cls");

  cout << "\n\n\n\n\n\n\n\n";

  do {

    cout << "\n\t\t\t\t\tPlease input your full name: ";
    cin.ignore();
    getline(cin, employeeName);
    cout << "\n\t\t\t\t\tPlease input your ID Number: ";
    cin >> employeeID;

    ifstream employeeFile(employeeDatabase);

    if (employeeFile.is_open()) {

      while (getline(employeeFile, line)) {

        if (line.find(employeeName) != string::npos && line.find(to_string(employeeID)) != string::npos) {
          employeeExists = true;
          employeePage();
        }

      }

      if (!employeeExists) {
        changeConsoleColor(RED);
        cout << "\n\t\t\t\t\tEmployee not found. Please input your name and ID correctly." << '\n';

        changeConsoleColor(AQUA);

      }

    } else {
        cout << "\t\t\t\t\tFailed to open the employee database file." << '\n';

    }

    employeeFile.close();

  } while(!employeeExists);

}

void employeePage() {
  int choice;
  verifyManager = 0; // 0 means that the user is an employee.

  system("cls");

  cout << "\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t\t\t\tLoading Employee's Page";

  for (int i = 0; i < 5; i++) {
    cout << ".";
    Sleep(500);
  }

  system("cls");

  cout << "\n\n\n\n";
  cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t\t       Welcome Employee!     " << '\n';
  cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t\t  Please select your option " << '\n';
  cout << "\t\t\t\t\t\t\t\t ---------------------------" << '\n';
  cout << " " << '\n';
  cout << "\t\t\t\t\t\t--------------------" << "\t--------------------" << "\t--------------------" << "\t--------------------" << '\n';
  cout << "\t\t\t\t\t\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << '\n';
  cout << "\t\t\t\t\t\t-       VIEW       -" << "\t-       VIEW       -" << "\t-       SERVE      -" << "\t-     SIGN OUT     -" << '\n';
  cout << "\t\t\t\t\t\t-      ORDERS      -" << "\t-     SUPPLIES     -" << "\t-      ORDERS      -" << "\t-                  -" << '\n';
  cout << "\t\t\t\t\t\t-  --------------  -" << "\t-  --------------  -" << "\t-  --------------  -" << "\t-  --------------  -" << '\n';
  cout << "\t\t\t\t\t\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" << '\n';
  cout << "\t\t\t\t\t\t-       [ 1 ]      -" << "\t-       [ 2 ]      -" << "\t-       [ 3 ]      -" << "\t-       [ 4 ]      -" <<'\n';
  cout << "\t\t\t\t\t\t-                  -" << "\t-                  -" << "\t-                  -" << "\t-                  -" <<'\n';
  cout << "\t\t\t\t\t\t--------------------" << "\t--------------------" << "\t--------------------" << "\t--------------------" << '\n';
  cout << '\n';
  cout << '\n';

  do {
    cout << "\t\t\t\t\t\tPlease choose your option: ";
    
    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\t\t\t\t\t\tPlease choose your option: ";
    }

    if (choice < 1 || choice > 4) {
      changeConsoleColor(RED);
      cout << "\t\t\t\t\t\tPlease choose a proper option." << '\n';
      changeConsoleColor(AQUA);
    }

    switch (choice) {
      case 1:
        viewOrders();
        break;
      
      case 2:
        viewSupplies();
        break;

      case 3:
        break;

      case 4:
        mainMenu();
        break;
    }

  } while (choice < 1 || choice > 4);
}

void addEmployees() {
  string employeeName;
  int idNumber;

  system("cls");

  ofstream employeeFile(employeeDatabase, ios::app);

  cout << "\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t\t      You have chosen to add an employee.    " << '\n';
  cout << "\t\t\t\t\t\t\t --------------------------------------------" << '\n';
  cout << "\t\t\t\t\t\t\t Please input the name of the employee: ";
  cin.ignore();
  getline(cin, employeeName);

  do {
    cout << "\t\t\t\t\t\t\t Please input the desired ID Number: ";
    cin >> idNumber;

    if (!isProperId(idNumber)) {
      cout << "\n\t\t\t\t\t\t\t ID Number must be exactly five digits." << '\n';
    }

  } while (!isProperId(idNumber));

  system("cls");

  cout << "\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t\t\t\t Adding employee to the database";

  for (int i = 0; i < 5; i++) {
    cout << ".";
    Sleep(500);
  }
  
  if (employeeFile.is_open()) {
    employeeFile << employeeName << " " << idNumber << endl;
    employeeFile.close();
    cout << "\n\t\t\t\t\t\t\t\t\t Employee added successfully." << "\n\n";
  } else {
    cout << "\n\t\t\t\t\t\t\t\t\t File can't be opened." << "\n\n";
  }

  cout << "\t\t\t\t\t\t\t\t\t";
  system("pause");

  managerPage();
}

void viewOrders() {
  int choice;
  char choice1;
  string line;

  system("cls");

  cout << "\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t\t\t\tLoading Existing Tables";

  for (int i = 0; i < 5; i++) {
    cout << ".";
    Sleep(500);
  }

  do {
    system("cls");

    cout << "\n\n\n\n\n";

    bool atLeastOneTableExists = false; // Verification that at least a table with an order exists.

    for (int tableNumber = 1; tableNumber <= 10; tableNumber++) {
      string tableFile = "OrderTable_" + to_string(tableNumber) + ".txt"; // Searches for all of the available tables in the file.
      ifstream file(tableFile.c_str());

      if (file) { // If it exists, it displays the available files in the console.
        cout << "\t\t\t\t\t\t[ " << tableNumber << " ] - View Orders for Table Number " << tableNumber << "." << '\n';
        atLeastOneTableExists = true; // Sets the verification to true meaning, a table with an order exists.
      }

      file.close(); // Closes the file.
    }

    if (!atLeastOneTableExists) { // If the verification returns false, the program displays no tables exists and will return back to the main page.
      cout << "\n\t\t\t\t\t\tNo tables exist." << '\n';
      cout << "\n\t\t\t\t\t\t";
      
      if (verifyManager == 1) {
        managerPage();
      } else {
        employeePage();
      }
    }

    cout << "\n\t\t\t\t\t\tChoose the table number to view orders: ";

    while (!(cin >> choice) || choice < 1 || choice > 10) { // Checks if the user input is correct.
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\n\t\t\t\t\t\tInvalid option. Please choose a valid table number: ";
    }

    string chosenTableFile = "OrderTable_" + to_string(choice) + ".txt";
    ifstream chosenFile(chosenTableFile);

    cout << "\n\t\t\t\t\t\tOrders for Table " << choice << ": " << '\n';

    while (getline(chosenFile, line)) {
      cout << "\t\t\t\t\t\t" << line << endl;
    }

    chosenFile.close();

    cout << "\n\t\t\t\t\t\t";
    system("pause");

    cout << "\t\t\t\t\t\tDo you want to view other orders? (Y / N): ";
    cin >> choice1;
  } while (choice1 == 'Y' || choice1 == 'y');

  if (verifyManager == 1) {
    managerPage();
  } else {
    employeePage();
  }
}

void viewSupplies() {
    vector<Supply> supplies;
    string line;
    string currentCategory = "";
    int choice;
    int itemNumber = 1;

    ifstream file("supplies.txt");

    if (!file.is_open()) {
        cout << "Unable to open supplies file." << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        Supply supply;
        getline(ss, supply.category, ',');
        getline(ss, supply.name, ',');
        ss >> supply.quantity;
        supplies.push_back(supply);
    }

    file.close();

    system("cls");

    cout << "\t\t\t\t\t\t ==============================" << endl;
    cout << "\t\t\t\t\t\t        List of Supplies       " << '\n';
    cout << "\t\t\t\t\t\t ==============================" << '\n';

    for (const auto& supply : supplies) {

      if (supply.category != currentCategory) {
          currentCategory = supply.category;
          cout << "\n\t\t\t\t\t\t Category: " << currentCategory << '\n';
          cout << "\t\t\t\t\t\t ---------------------------------" << '\n';
          cout << "\t\t\t\t\t\t [ No. ] Name              Quantity" << '\n';
          cout << "\t\t\t\t\t\t ---------------------------------" << '\n';
          itemNumber = 1;
      }

      cout << "\t\t\t\t\t\t [" << setw(2) << right << itemNumber << " ] " << setw(20) << left << supply.name << supply.quantity << endl;
      itemNumber++;
    }

    cout << "\n\t\t\t\t\t\t ";
    system("pause");

    cout << "\n\t\t\t\t\t\t Choose an option: " << '\n';
    cout << "\t\t\t\t\t\t [ 1 ] - Add Supplies  " << '\n';
    cout << "\t\t\t\t\t\t [ 2 ] - Return back to Manager's Page " << '\n';
    cin >> choice;

    switch (choice) {
      case 1:
        addSupplies();
        break;

      case 2:
        managerPage();
        break;

    }
}

void addSupplies() {
  vector<Supply> supplies;
  string line;
  string currentCategory = "";
  int categoryChoice, supplyChoice, quantity;
  string selectedSupply;
  int categoryNumber = 1;
  vector<string> categories;
  int supplyNumber = 1;

  ifstream file("supplies.txt");

  if (!file.is_open()) {
    cout << "Unable to open supplies file." << endl;
    return;
  }

  while (getline(file, line)) {
      stringstream ss(line);
      Supply supply;
      getline(ss, supply.category, ',');
      getline(ss, supply.name, ',');
      ss >> supply.quantity;
      supplies.push_back(supply);
  }

  file.close();

  system("cls");

  cout << "\t\t\t\t\t\t ==============================" << endl;
  cout << "\t\t\t\t\t\t          Add Supplies         " << '\n';
  cout << "\t\t\t\t\t\t ==============================" << '\n';

  cout << "\n\t\t\t\t\t\t Choose a category: " << '\n';
  for (const auto& supply : supplies) {

    if (supply.category != currentCategory) {
      currentCategory = supply.category;
      categories.push_back(currentCategory);
      cout << "\n\t\t\t\t\t\t [" << categoryNumber << "] " << currentCategory << '\n';
      categoryNumber++;
    }

  }

  cout << "\n\t\t\t\t\t\t Select category: ";
  cin >> categoryChoice;
  if (categoryChoice < 1 || categoryChoice > categories.size()) {
    cout << "\n\t\t\t\t\t\t Invalid category choice." << '\n';
    return;
  }

  currentCategory = categories[categoryChoice - 1];

  system("cls");

  cout << "\t\t\t\t\t\t ==============================" << '\n';
  cout << "\t\t\t\t\t\t          Add Supplies         " << '\n';
  cout << "\t\t\t\t\t\t ==============================" << '\n';

  cout << "\n\t\t\t\t\t\t Choose a supply from " << currentCategory << ":" << '\n';
  
  for (const auto& supply : supplies) {

    if (supply.category == currentCategory) {
        cout << "\n\t\t\t\t\t\t [" << supplyNumber << "] " << supply.name << '\n';
        supplyNumber++;
    }

  }

  cout << "\n\t\t\t\t\t\t Select supply: ";
  cin >> supplyChoice;
  if (supplyChoice < 1 || supplyChoice > supplyNumber) {
    cout << "\n\t\t\t\t\t\t Invalid supply choice." << '\n';
    return;
  }

  for (const auto& supply : supplies) {
    if (supply.category == currentCategory) {
      supplyChoice--;

      if (supplyChoice == 0) {
        selectedSupply = supply.name;
        break;
      }
      
    }
  }

  cout << "\n\t\t\t\t\t\t Enter quantity for " << selectedSupply << ": ";
  cin >> quantity;
  if (quantity <= 0) {
    cout << "\n\t\t\t\t\t\t Invalid quantity." << '\n';
    return;
  }

  for (auto& supply : supplies) {
    if (supply.category == currentCategory && supply.name == selectedSupply) {
      supply.quantity += quantity;
      break;
    }
  }

  ofstream suppliesFile("supplies.txt");
  if (!suppliesFile.is_open()) {
    cout << "\n\t\t\t\t\t\t Supplies file doesn't exist." << '\n';
    return;
  }

  for (const auto& supply : supplies) {
    suppliesFile << supply.category << "," << supply.name << "," << supply.quantity << '\n';
  }

  suppliesFile.close();

  cout << "\n\t\t\t\t\t\t Supplies added successfully." << '\n';
  cout << "\n\t\t\t\t\t\t ";
  system("pause");
}

bool isProperId(int idNumber) {

  return (idNumber >= 10000 && idNumber <= 99999);

}

void changeConsoleColor(int color) { // Function that allows to change the console's text easily.
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color);
}