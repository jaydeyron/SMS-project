#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;  // Maximum number of items in the stock record

// Class to represent an item in the stock record
class Item {
 public:
  Item(string name, int quantity, double price)
      : name_(name), quantity_(quantity), price_(price) {}

  string name() const { return name_; }
  int quantity() const { return quantity_; }
  double price() const { return price_; }

  void setQuantity(int quantity) { quantity_ = quantity; }
  void setPrice(double price) { price_ = price; }

 private:
  string name_;
  int quantity_;
  double price_;
};

// Class to represent the stock management system
class StockSystem {
 public:
  StockSystem() : numItems_(0) {}

  // Add a new item to the stock record
  void addItem(const Item& item) {
    // Check if the item already exists in the stock record
    bool found = false;
    for (int i = 0; i < numItems_; i++) {
      if (stock_[i].name() == item.name()) {
        stock_[i].setQuantity(stock_[i].quantity() + item.quantity());
        found = true;
        break;
      }
    }

    // If the item does not already exist, add it to the stock record
    if (!found) {
      stock_[numItems_++] = item;
    }
  }

  // Delete an item from the stock record
  void deleteItem(const string& name) {
    // Find the item in the stock record
    bool found = false;
    int index = -1;
    for (int i = 0; i < numItems_; i++) {
      if (stock_[i].name() == name) {
        found = true;
        index = i;
        break;
      }
    }

    // If the item was found, delete it from the stock record
    if (found) {
      for (int i = index; i < numItems_ - 1; i++) {
        stock_[i] = stock_[i + 1];
      }
      numItems_--;
    } else {
      cout << "Item not found." << endl;
    }
  }

  // Modify an existing item in the stock record
  void modifyItem(const string& name, int quantity, double price) {
    // Find the item in the stock record
    bool found = false;
    int index = -1;
    for (int i = 0; i < numItems_; i++) {
      if (stock_[i].name() == name) {
        found = true;
        index = i;
        break;
      }
    }

    // If the item was found, modify its quantity and price
    if (found) {
      stock_[index].setQuantity(quantity);
      stock_[index].setPrice(price);
    } else {
      cout << "Item not found." << endl;
    }
  // View the current stock record
  void viewStock() const {
    cout << "Name\tQuantity\tPrice" << endl;
    for (int i = 0; i < numItems_; i++) {
      cout << stock_[i].name() << "\t" << stock_[i].quantity() << "\t\t"
           << stock_[i].price() << endl;
    }
  }

  // Generate a report of the weekly stock activity
  void generateReport() const {
    cout << "Weekly stock report:" << endl;
    cout << "Name\tQuantity\tPrice" << endl;
    for (int i = 0; i < numItems_; i++) {
      cout << stock_[i].name() << "\t" << stock_[i].quantity() << "\t\t"
           << stock_[i].price() << endl;
    }
  }

 private:
  Item stock_[MAX_ITEMS];  // Array to store the stock record
  int numItems_;  // Number of items currently in the stock record
};

int main() {
  StockSystem system;

  // Initialize the stock record with some test data
  system.addItem(Item("Apples", 50, 0.99));
  system.addItem(Item("Bananas", 30, 0.79));
  // ... add more test data here ...

  // Main loop to process user commands
  while (true) {
    cout << "Enter command (add/delete/modify/view/report): ";
    string command;
    cin >> command;

    if (command == "add") {
      cout << "Enter name of item to add: ";
      string name;
      cin >> name;

      cout << "Enter quantity: ";
      int quantity;
      cin >> quantity;

      cout << "Enter price: ";
      double price;
      cin >> price;

      system.addItem(Item(name, quantity, price));
    } else if (command == "delete") {
      cout << "Enter name of item to delete: ";
      string name;
      cin >> name;

      system.deleteItem(name);
    } else if (command == "modify") {
      cout << "Enter name of item to modify: ";
      string name;
      cin >> name;

      cout << "Enter new quantity: ";
      int quantity;
      cin >> quantity;

      cout << "Enter new price: ";
      double price;
      cin >> price;

      system.modifyItem(name, quantity, price);
    } else if (command == "view") {
      system.viewStock();
    } else if (command == "report") {
      system.generateReport();
    } else {
      cout << "Invalid command. Try again." << endl;
    }
  }

  return 0;
}
  // View the current stock record
  void viewStock() const {
    cout << "Name\tQuantity\tPrice" << endl;
    for (int i = 0; i < numItems_; i++) {
      cout << stock_[i].name() << "\t" << stock_[i].quantity() << "\t\t"
           << stock_[i].price() << endl;
    }
  }

  // Generate a report of the weekly stock activity
  void generateReport() const {
    cout << "Weekly stock report:" << endl;
    cout << "Name\tQuantity\tPrice" << endl;
    for (int i = 0; i < numItems_; i++) {
      cout << stock_[i].name() << "\t" << stock_[i].quantity() << "\t\t"
           << stock_[i].price() << endl;
    }
  }

 private:
  Item stock_[MAX_ITEMS];  // Array to store the stock record
  int numItems_;  // Number of items currently in the stock record
};

int main() {
