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
