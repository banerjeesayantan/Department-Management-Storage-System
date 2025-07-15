#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int max_ele = 100;
int productCount = 0;
string savedItems[100];
int savedCount = 0;

class optionUser; // Forward declaration

// === Admin Product Class ===
class optionAdmin {
    string productName, productId, companyName;
    float price;
    int stockIn, stockSold;

    friend class optionUser;

public:
    void addProduct();
    void displayProduct(int index);
    void editProduct();
    string getProductId();
    string getProductName();
    string getCompanyName();
    float getPrice();
    int getStockIn();
    int getStockSold();
    void reduceStock(int qty);
    void increaseSold(int qty);
    void setData(string id, string name, string comp, float p, int stock, int sold);
};

optionAdmin products[max_ele];

// === Getter Methods ===
string optionAdmin::getProductId() { return productId; }
string optionAdmin::getProductName() { return productName; }
string optionAdmin::getCompanyName() { return companyName; }
float optionAdmin::getPrice() { return price; }
int optionAdmin::getStockIn() { return stockIn; }
int optionAdmin::getStockSold() { return stockSold; }
void optionAdmin::reduceStock(int qty) { stockIn -= qty; }
void optionAdmin::increaseSold(int qty) { stockSold += qty; }

// === File Operations ===
void saveProductsToFile() {
    ofstream out("products.txt");
    for (int i = 0; i < productCount; ++i) {
        out << products[i].getProductId() << ","
            << products[i].getProductName() << ","
            << products[i].getCompanyName() << ","
            << products[i].getPrice() << ","
            << products[i].getStockIn() << ","
            << products[i].getStockSold() << "\n";
    }
    out.close();
}

void loadProductsFromFile() {
    ifstream in("products.txt");
    string line;

    while (getline(in, line) && productCount < max_ele) {
        string id, name, company;
        float price;
        int stock, sold;

        size_t pos = 0;
        int field = 0;
        string fields[6];

        for (int i = 0; i < 6; ++i) {
            pos = line.find(',');
            if (pos != string::npos) {
                fields[i] = line.substr(0, pos);
                line.erase(0, pos + 1);
            } else {
                fields[i] = line;
                break;
            }
        }

        id = fields[0];
        name = fields[1];
        company = fields[2];
        price = stof(fields[3]);
        stock = stoi(fields[4]);
        sold = stoi(fields[5]);

        products[productCount].setData(id, name, company, price, stock, sold);
        productCount++;
    }
    in.close();
}

// === Admin Methods ===
void optionAdmin::addProduct() {
    cout << "Enter Product Name: ";
    cin >> productName;
    cout << "Enter Product ID: ";
    cin >> productId;
    cout << "Enter Company Name: ";
    cin >> companyName;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Stock In: ";
    cin >> stockIn;
    stockSold = 0;
}

void optionAdmin::displayProduct(int index) {
    cout << "\t" << index + 1 << "\t|\t"
         << productName << "\t|\t"
         << productId << "\t|\t"
         << companyName << "\t|\t"
         << price << "\t|\t"
         << stockIn << "\t|\t"
         << stockSold << "\n";
}

void optionAdmin::editProduct() {
    cout << "Enter New Product Name: ";
    cin >> productName;
    cout << "Enter New Product ID: ";
    cin >> productId;
    cout << "Enter New Company Name: ";
    cin >> companyName;
    cout << "Enter New Price: ";
    cin >> price;
    cout << "Enter New Stock In: ";
    cin >> stockIn;
}

void optionAdmin::setData(string id, string name, string comp, float p, int stock, int sold) {
    productId = id;
    productName = name;
    companyName = comp;
    price = p;
    stockIn = stock;
    stockSold = sold;
}

// === User Class ===
class optionUser {
public:
    void viewAndBuyProduct();
    void viewSavedItems();
};

// === Admin Menu ===
void adminMenu() {
    char choice;
    do {
        cout << "\n====== Admin Menu ======\n";
        cout << "1. Add Product\n2. Show All Products\n3. Return to Main Menu\nChoice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int addCount;
                cout << "Number of products to add: ";
                cin >> addCount;

                if (productCount + addCount > max_ele)
                    cout << "Limit exceeded. Max allowed: " << max_ele << "\n";
                else {
                    for (int i = 0; i < addCount; ++i) {
                        cout << "\nAdding Product " << (productCount + 1) << "\n";
                        products[productCount].addProduct();
                        productCount++;
                    }
                    saveProductsToFile();
                }
                break;
            }

            case '2': {
                if (productCount == 0) {
                    cout << "No products to show.\n";
                    break;
                }

                cout << "\n====== Product List ======\n";
                cout << "\tNo\t|\tName\t|\tID\t|\tCompany\t|\tPrice\t|\tStock\t|\tSold\n";
                for (int i = 0; i < productCount; ++i) {
                    products[i].displayProduct(i);
                }

                char subChoice;
                cout << "\nEdit (E), Delete (D), or Back (B)? ";
                cin >> subChoice;

                if (subChoice == 'E' || subChoice == 'e') {
                    string idToEdit;
                    cout << "Enter Product ID to edit: ";
                    cin >> idToEdit;
                    bool found = false;

                    for (int i = 0; i < productCount; ++i) {
                        if (products[i].getProductId() == idToEdit) {
                            products[i].editProduct();
                            found = true;
                            saveProductsToFile();
                            break;
                        }
                    }
                    if (!found) cout << "Product not found.\n";

                } else if (subChoice == 'D' || subChoice == 'd') {
                    string idToDelete;
                    cout << "Enter Product ID to delete: ";
                    cin >> idToDelete;
                    bool found = false;

                    for (int i = 0; i < productCount; ++i) {
                        if (products[i].getProductId() == idToDelete) {
                            for (int j = i; j < productCount - 1; ++j)
                                products[j] = products[j + 1];
                            productCount--;
                            found = true;
                            cout << "Product deleted successfully.\n";
                            saveProductsToFile();
                            break;
                        }
                    }
                    if (!found) cout << "Product not found.\n";
                }
                break;
            }

            case '3':
                return;

            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (true);
}

// === User Methods ===
void optionUser::viewAndBuyProduct() {
    if (productCount == 0) {
        cout << "No products available.\n";
        return;
    }

    cout << "\n====== Available Products ======\n";
    cout << "\tNo\t|\tName\t|\tID\t|\tCompany\t|\tPrice\t|\tStock\n";
    for (int i = 0; i < productCount; ++i) {
        cout << "\t" << (i + 1) << "\t|\t"
             << products[i].getProductName() << "\t|\t"
             << products[i].getProductId() << "\t|\t"
             << products[i].getCompanyName() << "\t|\t"
             << products[i].getPrice() << "\t|\t"
             << products[i].getStockIn() << "\n";
    }

    char userChoice;
    cout << "\nChoose an option:\n1. Buy Product\n2. Save for Later\n3. Back\nChoice: ";
    cin >> userChoice;

    if (userChoice == '1') {
        string id;
        int quantity;
        cout << "Enter Product ID to buy: ";
        cin >> id;
        bool found = false;

        for (int i = 0; i < productCount; ++i) {
            if (products[i].getProductId() == id) {
                found = true;
                cout << "Enter quantity: ";
                cin >> quantity;

                if (quantity <= 0 || quantity > products[i].getStockIn())
                    cout << "Invalid or insufficient stock.\n";
                else {
                    products[i].reduceStock(quantity);
                    products[i].increaseSold(quantity);
                    saveProductsToFile();
                    cout << "Purchase successful.\n";
                }
                break;
            }
        }
        if (!found) cout << "Product not found.\n";

    } else if (userChoice == '2') {
        string id;
        cout << "Enter Product ID to save: ";
        cin >> id;
        bool found = false;

        for (int i = 0; i < productCount; ++i) {
            if (products[i].getProductId() == id) {
                savedItems[savedCount++] = id;
                cout << "Product saved successfully.\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Product not found.\n";
    }
}

void optionUser::viewSavedItems() {
    if (savedCount == 0) {
        cout << "No saved items.\n";
        return;
    }

    cout << "\n====== Saved Items ======\n";
    for (int i = 0; i < savedCount; ++i) {
        for (int j = 0; j < productCount; ++j) {
            if (products[j].getProductId() == savedItems[i]) {
                cout << "\t" << products[j].getProductName()
                     << " (ID: " << products[j].getProductId()
                     << ", Price: " << products[j].getPrice() << ")\n";
                break;
            }
        }
    }
}

// === User Menu ===
void userMenu() {
    optionUser user;
    char choice;
    do {
        cout << "\n====== User Menu ======\n";
        cout << "1. View & Buy Products\n2. View Saved Items\n3. Back to Main Menu\nChoice: ";
        cin >> choice;

        switch (choice) {
            case '1': user.viewAndBuyProduct(); break;
            case '2': user.viewSavedItems(); break;
            case '3': return;
            default: cout << "Invalid choice.\n";
        }
    } while (true);
}

// === Main ===
int main() {
    loadProductsFromFile();
    char option;

    cout << "==== Department Store Management System ====\n";
    do {
        cout << "\n1. Admin\n2. User\n*. Exit\nChoose option: ";
        cin >> option;

        switch (option) {
            case '1': adminMenu(); break;
            case '2': userMenu(); break;
            case '*': cout << "Exiting...\n"; return 0;
            default: cout << "Invalid option.\n";
        }
    } while (true);
}