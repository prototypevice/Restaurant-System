#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>
#include <algorithm>

using namespace std;

struct MenuItem {
    string name;
    float price;
};

vector<MenuItem> cart;

float total = 0.0;
const double DELIVERY_FEE = 49.00;
bool isVoucherCodeValid = false;
bool cartHasContents = cart.empty();
string voucherCode;
string name, address, contactNo, payMethod;

int order;

// Menu Category
void mainMenu();
void menuCategory();

// Ordering Functions
void orderMainCourse();
void orderSideDish();
void orderComboMeals();
void orderPastries();
void orderBeverages();
void orderDesserts();
void chooseOption(string food, float price, int orderChoice, float & total);

// Display Options
void displayItems();
void displayCart();
void preparationAndDelivery();
void displayOrderSummary(string &name, string &address, string &contactNo, vector<MenuItem> &cart, float &total, string paymentMethod);

// Payment Processing
char enterVoucherCode(bool &isVoucherCodeValid);
void customerDetails(string& name, string& address, string& contactNo);
void GETcustomerDetails(string& name, string& address, string& contactNo);
void checkOut(float &total);
void paymentProcess(float & total, string &payMethod);
void paymentE(float &total, string &payMethod);
void paymentC(float &total, string &payMethod);


int main(){
    
    while(true){
        menuCategory();
    }
    
}

void mainMenu(){
	system("cls");
    cout << "--------------------------------" << endl;
    cout << "   WELCOME TO SUENO ONLINE " << endl;
    cout << "--------------------------------" << endl;
    cout << "   [1]. Main Course " << endl;
    cout << "   [2]. Side Dish " << endl;
    cout << "   [3]. Combo Meals" << endl;
    cout << "   [4]. Pastries " << endl;
    cout << "   [5]. Beverages" << endl;
    cout << "   [6]. Desserts " << endl;
    cout << endl;
    cout << "   [V]. View Cart" << endl;
    cout << "   [C]. Check Out Order" << endl;
    cout << endl;
    cout << "   [A]. About Us " << endl;
    cout << "   [X]. Exit" << endl;
}

void chooseOption(string food, float price, int orderChoice, float & total) {
    char choice;
    int quantity;

    cout << "You chose: " << food << " - PHP " << price << endl;

    // Ask user for the quantity of the item
    cout << "Enter the quantity you would like to order: ";
    cin >> quantity;

    // Validate input
    while (quantity <= 0) {
        cout << "Invalid quantity. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> quantity;
    }

    // Add the selected item to the cart with the specified quantity
    for (int i = 0; i < quantity; ++i) {
        cart.push_back({food, price});
    }
    total+= (price*quantity);

    cout << "Item(s) added to cart." << endl;
    do {
    	cout << endl;
        cout << "Do you want to:" << endl;
        cout << "A. Add more items to your cart" << endl;
        cout << "B. Proceed to checkout" << endl;
        cout << "Enter your choice (A/B): ";
        cin >> choice;

        choice = toupper(choice);

        if (choice == 'A') {
            break; // Return to menu category to add more items
        } else if (choice == 'B') {
           checkOut(total); // Proceed to checkout
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'A' && choice != 'B');
}

void menuCategory() {
    char category;

    mainMenu();

    do {
        cout << "Enter your choice: ";
        cin >> category;
        category = toupper(category); // Convert to uppercase to handle both cases
        
        system("cls");
        if ((category < '1' || category > '6') && category != 'V' && category != 'C' && category != 'X' && category != 'A') {
            cout << "Invalid choice. Please input a number between 1 and 6, 'V' to view cart, 'C' to checkout, or 'X' to go back to the main menu." << endl;
            system("pause"); system("cls");
            menuCategory();
        }
    } while ((category < '1' || category > '6') && category != 'V' && category != 'C' && category != 'X' && category != 'A');

    switch (category) {
        case '1':
            orderMainCourse();
            break;
        case '2':
            orderSideDish();
            break;
        case '3':
            orderComboMeals();
            break;
        case '4':
            orderPastries();
            break;
        case '5':
            orderBeverages();
            break;
        case '6':
            orderDesserts();
            break;
        case 'A':
            cout << "\t\t\t\t\t\t\t\t\t == About Us == " << endl;
            cout << "\t\t\t\t\t\t\t\t == Welcome to Sueno Restaurant! == " << endl;
            cout << endl;
            cout << " In response to the changing demands of the restaurant business our Restaurant Management System (RMS) was created in C++. " << endl;
    		cout << " Compared with traditional systems, the RMS simplifies restaurant operations and meets the needs of contemporary guests." << endl;
    		cout << " It functions as an all-inclusive point-of-sale system, effectively handling orders, payments, and transactions." << endl;
    		cout << " Additionally, it connects with internet platforms to give users freedom and convenience. In addition to transactional features, " << endl;
    		cout << " the RMS fosters customer happiness and business success by improving operational efficiency through automated inventory control " << endl;
    		cout << " and real-time data analytics. " << endl;
    		cout << endl;
    		cout << " In summary, the RMS represents a major technological innovation in restaurants that enables these enterprises to adapt to changing customer needs and " << endl;
    		cout << " provide outstanding eating experiences. " << endl;
    		cout << endl;
    		cout << "    Our team members:  " << endl;
    		cout << "\t =  Lopez, Sean Patrick B." << endl;
    		cout << "\t =  Morano, Raven Rose E." << endl;
    		cout << "\t =  Santander, Josephine J." << endl;
    		cout << endl;
            break;
        case 'V':
        	displayCart();
            break;
        case 'C':
            checkOut(total);
            break;
        case 'X':
            exit(0);
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
            break;
    }
    system("pause");
}

void orderMainCourse() {
    MenuItem mainCourse[8];
	
	mainCourse[0] = {"Sinigang na Baboy", 149.00};
    mainCourse[1] = {"Sinigang na Hipon", 149.00};
    mainCourse[2] = {"Sinigang na Bangus", 149.00};
    mainCourse[3] = {"Sinigang na Salmon", 199.00};
    mainCourse[4] = {"Kare-Kare", 149.00};
    mainCourse[5] = {"Lechon Kawali", 139.00};
    mainCourse[6] = {"Bistek Tagalog", 109.00};
    mainCourse[7] = {"Pork Sisig", 109.00};

    system("cls");
    cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================= " << endl;
    cout << " \t\t\t\t\t                                    ==Main Course==                                    " << endl;
    cout << " \t\t\t\t\t = [1] Sinigang na Baboy                                              PHP 149.00       " << endl;
    cout << " \t\t\t\t\t = [2] Sinigang na Hipon                                              PHP 149.00       " << endl;
    cout << " \t\t\t\t\t = [3] Sinigang na Bangus                                             PHP 149.00       " << endl;
    cout << " \t\t\t\t\t = [4] Sinigang na Salmon                                             PHP 199.00       " << endl;
    cout << " \t\t\t\t\t = [5] Kare-Kare                                                      PHP 149.00       " << endl;
    cout << " \t\t\t\t\t = [6] Lechon Kawali                                                  PHP 139.00       " << endl;
    cout << " \t\t\t\t\t = [7] Bistek Tagalog                                                 PHP 109.00       " << endl;
    cout << " \t\t\t\t\t = [8] Pork Sisig                                                     PHP 109.00       " << endl;
    cout << " \t\t\t\t\t ===================================================================================== " << endl;
    cout << "Enter your choice: ";

    while (!(cin >> order) || order < 1 || order > 8) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a number between 1 and 8: ";
    }

    chooseOption(mainCourse[order - 1].name, mainCourse[order - 1].price, order, total);
    
}

void orderSideDish() {
    MenuItem sideDish[8];

    sideDish[0] = {"Garlic Mashed Potatoes", 99.00};
    sideDish[1] = {"Grilled Vegetables", 99.00};
    sideDish[2] = {"Coleslaw", 99.00};
    sideDish[3] = {"Steamed Asparagus", 99.00};
    sideDish[4] = {"Roasted Brussels Sprouts", 99.00};
    sideDish[5] = {"Caprese Salad", 99.00};
    sideDish[6] = {"Quinoa Salad", 99.00};
    sideDish[7] = {"Sautéed Spinach", 99.00};

    system("cls");

    cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================== " << endl;
    cout << " \t\t\t\t\t                                    ==Side Dish==                                       " << endl;
    cout << " \t\t\t\t\t = [1] Garlic Mashed Potatoes                                             PHP 99.00     " << endl;
    cout << " \t\t\t\t\t = [2] Grilled Vegetables                                                 PHP 99.00     " << endl;
    cout << " \t\t\t\t\t = [3] Coleslaw                                                           PHP 99.00     " << endl;
    cout << " \t\t\t\t\t = [4] Steamed Asparagus                                                  PHP 99.00     " << endl;
    cout << " \t\t\t\t\t = [5] Roasted Brussels Sprouts                                           PHP 99.00     " << endl;
    cout << " \t\t\t\t\t = [6] Caprese Salad                                                      PHP 99.00     " << endl;
    cout << " \t\t\t\t\t = [7] Quinoa Salad                                                       PHP 99.00     " << endl;
    cout << " \t\t\t\t\t = [8] Sautéed Spinach                                                    PHP 99.00     " << endl;
    cout << " \t\t\t\t\t ====================================================================================== " << endl;
    cout << "Enter your choice: ";

    while (!(cin >> order) || order < 1 || order > 8) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a number between 1 and 8: ";
    }
    chooseOption(sideDish[order - 1].name, sideDish[order - 1].price, order, total);
}

void orderComboMeals() {
    MenuItem comboMeals[8];

    comboMeals[0] = {"Garlic Mashed Potatoes", 99.00};
    comboMeals[1] = {"Grilled Vegetables", 99.00};
    comboMeals[2] = {"Coleslaw", 99.00};
    comboMeals[3] = {"Steamed Asparagus", 99.00};
    comboMeals[4] = {"Roasted Brussels Sprouts", 99.00};
    comboMeals[5] = {"Caprese Salad", 99.00};
    comboMeals[6] = {"Quinoa Salad", 99.00};
    comboMeals[7] = {"Sautéed Spinach", 99.00};

    system("cls");
    cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================ " << endl;
    cout << " \t\t\t\t\t                                     ==Combo Meals==                                  " << endl;
    cout << " \t\t\t\t\t = [1] Garlic Mashed Potatoes                                          PHP 99.00      " << endl;
    cout << " \t\t\t\t\t = [2] Grilled Vegetables                                              PHP 99.00      " << endl;
    cout << " \t\t\t\t\t = [3] Coleslaw                                                        PHP 99.00      " << endl;
    cout << " \t\t\t\t\t = [4] Steamed Asparagus                                               PHP 99.00      " << endl;
    cout << " \t\t\t\t\t = [5] Roasted Brussels Sprouts                                        PHP 99.00      " << endl;
    cout << " \t\t\t\t\t = [6] Caprese Salad                                                   PHP 99.00      " << endl;
    cout << " \t\t\t\t\t = [7] Quinoa Salad                                                    PHP 99.00      " << endl;
    cout << " \t\t\t\t\t = [8] Sautéed Spinach                                                 PHP 99.00      " << endl;
    cout << " \t\t\t\t\t ==================================================================================== " << endl;
    cout << "Enter your choice: ";
    
    while (!(cin >> order) || order < 1 || order > 8) {
    	cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a number between 1 and 8: ";
	}
	chooseOption(comboMeals[order - 1].name, comboMeals[order - 1].price, order, total);
}

void orderPastries() {
	MenuItem pastries[7];
	
	pastries[0] = {"Macarons", 120.00};
    pastries[1] = {"Ensaymada", 55.00};
  	pastries[2] = {"Pan de Coco", 65.00};
  	pastries[3] = {"Croissant", 110.00};
  	pastries[4] = {"Éclair", 130.00};
  	pastries[5] = {"Tiramisu", 200.00};
  	pastries[6] = {"Churros", 100.00};

    system("cls");
    cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================ " << endl;
    cout << " \t\t\t\t\t                                     ==Pastries==                                      " << endl;
    cout << " \t\t\t\t\t = [1] Macarons                                                            PHP 120.00       " << endl;
    cout << " \t\t\t\t\t = [2] Ensaymada                                                           PHP 55.00        " << endl;
    cout << " \t\t\t\t\t = [3] Pan de Coco                                                         PHP 50.00        " << endl;
    cout << " \t\t\t\t\t = [4] Croissant                                                      	   PHP 150.00       " << endl;
    cout << " \t\t\t\t\t = [5] Éclair                                                              PHP 180.00       " << endl;
    cout << " \t\t\t\t\t = [6] Tiramisu                                                            PHP 70.00        " << endl;
    cout << " \t\t\t\t\t = [7] Churros                                                             PHP 60.00        " << endl;
    cout << " \t\t\t\t\t ==================================================================================== " << endl;
    cout << "Enter your choice: ";
    
    while (!(cin >> order) || order < 1 || order > 7) {
    	cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a number between 1 and 7: ";
	}
	chooseOption(pastries[order - 1].name, pastries[order - 1].price, order, total);
}

void orderBeverages() {
	MenuItem beverages[8];
	
	beverages[0] = {"Coke", 50.00};
  	beverages[1] = {"Coke Zero", 49.00};
  	beverages[2] = {"Iced Tea", 40.00};
  	beverages[3] = {"Lemonade", 55.00};
  	beverages[4] = {"Iced Coffee", 130.00};
  	beverages[5] = {"Watermelon Shake", 80.00};
  	beverages[6] = {"Mango Shake", 90.00};
  	beverages[7] = {"Water", 20.00};

    system("cls");
    cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ==================================== " << endl;
		cout << " \t\t\t\t\t                                 ==Beverages==                                        " << endl;
		cout << " \t\t\t\t\t = [1] Coke                                                            PHP 50.00      " << endl;
		cout << " \t\t\t\t\t = [2] Coke Zero                                                       PHP 49.00      " << endl;
		cout << " \t\t\t\t\t = [3] Iced Tea                                                        PHP 40.00      " << endl;
		cout << " \t\t\t\t\t = [4] Lemonade                                                        PHP 55.00      " << endl;
		cout << " \t\t\t\t\t = [5] Iced Coffee                                                     PHP 130.00     " << endl;
		cout << " \t\t\t\t\t = [6] Watermelon Shake                                                PHP 80.00      " << endl;
		cout << " \t\t\t\t\t = [7] Mango Shake                                                     PHP 90.00      " << endl;
		cout << " \t\t\t\t\t = [8] Water                                                           PHP 20.00      " << endl;
		cout << " \t\t\t\t\t ======================================================================================== " << endl;
    cout << "Enter your choice: ";
    
    while (!(cin >> order) || order < 1 || order > 8) {
    	cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a number between 1 and 8: ";
	}
	chooseOption(beverages[order - 1].name, beverages[order - 1].price, order, total);
}

void orderDesserts() {
	MenuItem desserts[8];
	
	desserts[0] = {"Halo-Halo", 90.00};
  	desserts[1] = {"Leche Flan", 99.00};
    desserts[2] = {"Banana Cue", 59.00};
  	desserts[3] = {"Taho", 69.00};
  	desserts[4] = {"Turon", 89.00};
  	desserts[5] = {"Puto Cheese", 60.00};
  	desserts[6] = {"Suman", 70.00};
  	desserts[7] = {"Pichi-Pichi", 85.00};

    system("cls");
    cout << " \t\t\t\t\t ================================== SUEÑO RESTAURANT ================================ " << endl;
    cout << " \t\t\t\t\t                                      ==Desserts==                                    " << endl;
    cout << " \t\t\t\t\t = [1] Halo-Halo                                                     PHP 90.00        " << endl;
    cout << " \t\t\t\t\t = [2] Leche Flan                                             		 PHP 99.00        " << endl;
    cout << " \t\t\t\t\t = [3] Banana Cue                                                    PHP 59.00        " << endl;
    cout << " \t\t\t\t\t = [4] Taho                                                          PHP 69.00        " << endl;
    cout << " \t\t\t\t\t = [5] Turon                                                         PHP 89.00        " << endl;
    cout << " \t\t\t\t\t = [6] Puto Cheese                                                   PHP 60.00        " << endl;
    cout << " \t\t\t\t\t = [7] Suman                                                         PHP 70.00        " << endl;
    cout << " \t\t\t\t\t = [8] Pichi-Pichi                                                   PHP 85.00        " << endl;
    cout << " \t\t\t\t\t ==================================================================================== " << endl;
    cout << "Enter your choice: ";
    
    while (!(cin >> order) || order < 1 || order > 8) {
    	cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a number between 1 and 8: ";
	}
	chooseOption(desserts[order - 1].name, desserts[order - 1].price, order, total);
}

void displayItems() {
    int itemNumber = 1; // Initialize item number counter
    
    // Iterate over each item in the cart
    for (size_t i = 0; i < cart.size(); ++i) {
        // Check if the current item has been already processed
        bool processed = false;
        for (size_t j = 0; j < i; ++j) {
            if (cart[i].name == cart[j].name) {
                processed = true;
                break;
            }
        }
        // If the current item hasn't been processed yet, display it
        if (!processed) {
            // Calculate the total quantity of the current item
            int totalQuantity = 0;
            for (size_t k = i; k < cart.size(); ++k) {
                if (cart[i].name == cart[k].name) {
                    totalQuantity++;
                }
            }
            // Display item number, name, price, and total quantity
            cout << "[" << itemNumber++ << "] " << cart[i].name << " - PHP " << cart[i].price << " x " << totalQuantity << endl;
        }
    }
}

void displayCart() {
	
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "           YOUR CART " << endl;
    cout << "--------------------------------" << endl;
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
    } else {
        displayItems();
        cout << "--------------------------------" << endl;
        cout << "Total: PHP " << total << endl;
    }
}

void ApplyDiscount(float &total, bool &isVoucherCodeValid){ // checks if voucher is valid. if not returns original price
    float discountPercentage;
    if (isVoucherCodeValid) {
            discountPercentage = 0.25; // 25% discount
            cout << "Voucher Discount (25%): - PHP " << total*discountPercentage << endl; // can be made into a strikethrough
            total *= (1 - discountPercentage);
            cout << "Current Total Price with Voucher: PHP " << total << endl;
    }
}

void checkOut(float &total) {
    char choice; char c;
    displayCart();
    if (cart.empty()) {
        return;
    }
    else{
        c = enterVoucherCode(isVoucherCodeValid); 
        if(c == 'x' || c=='X'){
            return;
        }
        else{
            do{
                system("pause"); 
                system("cls");
                displayCart();
                ApplyDiscount(total, isVoucherCodeValid); 
                cout << "Shipping Fee: PHP " << DELIVERY_FEE << "\n";
                total += DELIVERY_FEE;
                cout << "--------------------------------" << endl;
                cout << "Total (w/ Shipping Fee): " << total << "\n";
                // Display menu options
                cout << endl;
                cout << "   [P]. Proceed to Payment" << endl;
                cout << "   [R]. Remove item from cart" << endl;
                cout << "   [X]. Back to Menu Category" << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                // Clear input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case 'P':
                    case 'p':
                        system("cls");
                        paymentProcess(total, payMethod); system("pause");system("cls");
                        preparationAndDelivery(); system("pause"); system("cls");
                        displayOrderSummary(name, address, contactNo, cart, total, payMethod);
                        total = 0.0;
                        cart.clear();
                        break;
                    case 'R':
                    case 'r':
                        int index;
                        cout << "Enter the index of the item to remove: ";
                        if (!(cin >> index)) {
                            cout << "Invalid input." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            if (index >= 1 && index <= static_cast<int>(cart.size())) {
                                cout << cart[index - 1].name << " removed from cart." << endl;
                                cart.erase(cart.begin() + index - 1);
                                total -= cart[index-1].price;
                            } else {
                                cout << "Invalid item index." << endl;
                            }
                        }
                        checkOut(total); // Redisplay the cart after removal
                        break;
                    case 'X':
                    case 'x':
                        total -= 49;
                        if(isVoucherCodeValid) total /= (1-0.25);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        checkOut(total); // Redisplay the cart if the choice is invalid
                        break;
                }
            }while((tolower(choice) != 'x') && (tolower(choice) != 'p') && (tolower(choice) != 'r'));
        }
        
    }
}

char enterVoucherCode(bool & isVoucherCodeValid) {
    char answer;

    cout << "Do you have a voucher? (y/n) X to return to Menu: ";
    cin >> answer;
    cin.ignore(); // Clear input buffer

    if (answer == 'y' || answer == 'Y') {
        string voucherCode;
        do {
            cout << "Enter voucher code (otherwise press 'X'): ";
            getline(cin, voucherCode);

            if (voucherCode == "POGINISIRPURA" || voucherCode == "RMSPROGRAM" || voucherCode == "2NDTERM") {
                cout << "Voucher applied! You get a 25% discount." << endl;
                isVoucherCodeValid = true; // Set flag for valid code
                 // Proceed to display checkout information
                return answer; // Exit the function after applying the voucher
            } else if (voucherCode == "X" || voucherCode == "x") {
                isVoucherCodeValid = false;
                return answer;
            } else {
                cout << "Invalid voucher code. No discount applied." << endl;
            }
        } while (true); // Loop until valid code or empty input
    }else if (answer == 'n' || answer == 'N') {
        isVoucherCodeValid = false;
        return answer;
    
    }
    else if(answer == 'X' || answer == 'x'){
        cout << "Returning to Menu...\n";
    }
    else {
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        enterVoucherCode(isVoucherCodeValid); // Ask again if the input is invalid
    }
    return answer;
}

void paymentE(float & total, string & payMethod) {
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "      E-WALLET PAYMENT         " << endl;
    cout << "--------------------------------" << endl;
    
    string username, password;
    cout << "Enter your e-wallet username: ";
    cin >> username;
    cout << "Enter your e-wallet password: ";
    cin >> password;

    bool isAuthenticated = true; // Replace with actual authentication logic

    if (isAuthenticated) {
        cout << "--------------------------------" << endl;
        cout << "      PAYMENT SUMMARY          " << endl;
        cout << "--------------------------------" << endl;
        cout << "Total: PHP " << total << endl;
        cout << endl;
        cout << "Confirm payment? (Y/N): ";
        
        char confirmChoice;
        cin >> confirmChoice;

        if (confirmChoice == 'Y' || confirmChoice == 'y') {
            
            bool paymentSuccess = true; // Replace with actual payment logic

            if (paymentSuccess) {
                cout << "Payment successful! Amount of PHP " << total << " deducted from your e-wallet." << endl;
            } else {
                cout << "Payment failed. Please try again later." << endl;
            }
        } else {
            cout << "Payment cancelled." << endl;
        }
    } else {
        cout << "Authentication failed. Please check your username and password." << endl;
    }
        payMethod = "E-Wallet";
        displayOrderSummary(name, address, contactNo, cart, total, payMethod);

}
void paymentC(float & total, string &payMethod) {
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "         CARD PAYMENT         " << endl;
    cout << "--------------------------------" << endl;
    
    int num, otp;
    cout << "Enter your Card Number: ";
    cin >> num;
    cout << "Enter OTP: ";
    cin >> otp;

    bool isAuthenticated = true; // Replace with actual authentication logic

    if (isAuthenticated) {
        cout << "--------------------------------" << endl;
        cout << "      PAYMENT SUMMARY          " << endl;
        cout << "--------------------------------" << endl;
        cout << "Total: PHP " << total << endl;
        cout << endl;
        cout << "Confirm payment? (Y/N): ";
        
        char confirmChoice;
        cin >> confirmChoice;

        if (confirmChoice == 'Y' || confirmChoice == 'y') {
            
            bool paymentSuccess = true; // Replace with actual payment logic

            if (paymentSuccess) {
                cout << "Payment successful! Amount of PHP " << total << " deducted from your Card." << endl;
                
            } else {
                cout << "Payment failed. Please try again later." << endl;
            }
        } else {
            cout << "Payment cancelled." << endl;
        }
    } else {
        cout << "Authentication failed. Please check your username and password." << endl;
    }
        payMethod = "Card";
        displayOrderSummary(name, address, contactNo, cart, total, payMethod);
}

void paymentProcess(float &total, string &payMethod) {
    GETcustomerDetails(name, address, contactNo); 
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "         PAYMENT PROCESS        " << endl;
    cout << "--------------------------------" << endl;
    cout << "Choose your payment method:" << endl;
    cout << "[1]. Cash on Delivery" << endl;
    cout << "[2]. Card" << endl;
    cout << "[3]. E-Wallet" << endl;
    cout << endl;
    cout << "[X]. Back to Menu Category" << endl;
    cout << endl;

    char choice;
    bool validChoice = false;
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case '1':
                // Process cash on delivery payment
                cout << "You have chosen cash on delivery. You will pay upon delivery." << endl;
                payMethod = "Cash On Delivery";
                displayOrderSummary(name, address, contactNo, cart, total, payMethod);
                validChoice = true;
                break;
            case '2':
                // Process card payment
                cout << "Redirecting to Card Payment..." << endl;
                paymentC(total, payMethod);
                // Code for processing card payment
                cout << "Payment successful! Thank you for your order." << endl;
                validChoice = true;
                break;
            case '3':
                // Process online payment gateway
                cout << "Redirecting to E-Wallet..." << endl;
                // Code for redirecting to online payment gateway
                paymentE(total, payMethod);
                cout << "Payment successful! Thank you for your order." << endl;
              
                validChoice = true;
                break;
            case 'X':
            case 'x':
                total -= 49;
                if(isVoucherCodeValid) total /= (1-0.25); system("cls");
                menuCategory();
                validChoice = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (!validChoice);
}

void preparationAndDelivery() {
    // Constants for preparation and delivery time
    const int preparationTimeInSeconds = 60;  // 60 seconds for demonstration
    const int deliveryTimeInSeconds = 60;      // 60 seconds for demonstration

    // Get the current time for preparation start
    auto preparationStartTime = chrono::system_clock::now();
    time_t preparationStartTime_t = chrono::system_clock::to_time_t(preparationStartTime);

    // Calculate total preparation time for all items in the cart
    int totalPreparationTime =  cart.size() * preparationTimeInSeconds;

    // Calculate total delivery time for the order
    int totalDeliveryTime = deliveryTimeInSeconds;

    // Display preparation start time
    cout << "--------------------------------" << endl;
    cout << "   PREPARATION AND DELIVERY    " << endl;
    cout << "--------------------------------" << endl;
    cout << "Restaurant started preparing the meal at: " << ctime(&preparationStartTime_t);

    // Start preparation timer
    cout << "Preparation started..." << flush;
    for (int i = 0; i < totalPreparationTime; ++i) {
        cout << "\rPreparing... " << totalPreparationTime - i << " seconds remaining." << flush;
        this_thread::sleep_for(chrono::seconds(1)); 
    }
    cout << "\rPreparation completed!" << endl;
    cout << endl;

    // Get the current time for rider pickup
    auto riderPickupTime = chrono::system_clock::now();
    time_t riderPickupTime_t = chrono::system_clock::to_time_t(riderPickupTime);

    // Display rider pickup time
    cout << "Rider picked up the order at: " << ctime(&riderPickupTime_t);
    cout << endl;

    // Start delivery timer
    cout << "Delivery started..." << flush;
    for (int i = 0; i < totalDeliveryTime; ++i) {
        cout << "\rDelivering... " << totalDeliveryTime - i << " seconds remaining." << flush;
        this_thread::sleep_for(chrono::seconds(1)); 
    }
    cout << "\rDelivery completed!" << endl;
    cout << endl;

    // Get the current time for order arrival
    auto orderArrivalTime = chrono::system_clock::now();
    time_t orderArrivalTime_t = chrono::system_clock::to_time_t(orderArrivalTime);

    // Display order arrival time
    cout << "Order arrived at: " << ctime(&orderArrivalTime_t);
}


void GETcustomerDetails(string& name, string& address, string& contactNo) {
    system("cls");
    // Additional code for delivery process using customer details
    cout << "Customer Details: " << endl;
    cout << "Name: "; getline(cin, name);
    cout << "Address: "; getline(cin, address);
    cout << "Contact Number: "; getline(cin, contactNo);
    
    cout << endl;
}
void customerDetails(string& name, string& address, string& contactNo) {
    system("cls");
    // Additional code for delivery process using customer details
    cout << "Customer Details: " << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Contact Number: " << contactNo << endl;
}

void displayOrderSummary(string &name, string &address, string &contactNo, vector<MenuItem> &cart, float &total, string paymentMethod) {
    system("cls");
    // Generate a random order number
    srand(time(0));
    int orderNumber = rand() % 9000 + 1000; // Generate a random number between 1000 and 9999
    int itemNumber = 1;
    

    // Display the order summary
    cout << "--------------------------------" << endl;
    cout << "         ORDER SUMMARY          " << endl;
    cout << "--------------------------------" << endl;
    cout << "Order Number: " << orderNumber << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Delivery Address: " << address << endl;
    cout << "Contact Number: " << contactNo << endl;
    cout << endl;
    cout << "Order Details:" << endl;
    // Iterate over each item in the cart
    for (size_t i = 0; i < cart.size(); ++i) {
        // Check if the current item has been already processed
        bool processed = false;
        for (size_t j = 0; j < i; ++j) {
            if (cart[i].name == cart[j].name) {
                processed = true;
                break;
            }
        }
        // If the current item hasn't been processed yet, display it
        if (!processed) {
            // Calculate the total quantity of the current item
            int totalQuantity = 0;
            for (size_t k = i; k < cart.size(); ++k) {
                if (cart[i].name == cart[k].name) {
                    totalQuantity++;
                }
            }
            // Display item number, name, price, and total quantity
            cout << "[" << itemNumber++ << "] " << cart[i].name << " - PHP " << cart[i].price << " x " << totalQuantity << endl;
        }
    }
    cout << "--------------------------------" << endl;
    cout << "Shipping Fee: PHP " << DELIVERY_FEE << endl;
    cout << "Total: PHP " << total << endl;
    cout << endl;
    cout << "Payment Method: " << paymentMethod << endl;
    cout << endl;
    cout << "Thank you for your order!" << endl;
     }

