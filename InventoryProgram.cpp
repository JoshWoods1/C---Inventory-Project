#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

// Define the Item class to represent items in the inventory
class Item {
private:
    string name;
    int quantity;
public:
    Item(string n, int q) : name(n), quantity(q) {}

    // Getter methods
    string getName() const { return name; }
    int getQuantity() const { return quantity; }

    // Method to update the quantity of the item
    void updateQuantity(int q) { quantity += q; }
};

// Define the Inventory class to manage the collection of items
class Inventory {
private:
    vector<Item> items;
public:
    // Method to add an item to the inventory
    void addItem(const Item& item) {
        items.push_back(item);
    }

    // Method to remove an item from the inventory
    void removeItem(const string& name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == name) {
                items.erase(it);
                break;
            }
        }
    }

    // Method to display the current inventory
    void displayInventory() const {
        cout << "Current Inventory:\n";
        for (const auto& item : items) {
            cout << "Name: " << item.getName() << ", Quantity: " << item.getQuantity() << endl;
        }
    }

    // Method to search for an item by name
    void searchItem(const string& name) const {
        bool found = false;
        for (const auto& item : items) {
            if (item.getName() == name) {
                cout << "Item found - Name: " << item.getName() << ", Quantity: " << item.getQuantity() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item not found in the inventory.\n";
        }
    }
};

int main() {
    Inventory inventory;
    int choice;
    string name;
    int quantity;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Inventory\n";
        cout << "4. Search Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid choice.\n";
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush the input buffer
            continue; // Skip to next iteration of the loop
        }

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item quantity: ";
                cin >> quantity;
                inventory.addItem(Item(name, quantity));
                cout << "Item added to inventory.\n";
                break;
            case 2:
                cout << "Enter item name to remove: ";
                cin >> name;
                inventory.removeItem(name);
                cout << "Item removed from inventory.\n";
                break;
            case 3:
                inventory.displayInventory();
                break;
            case 4:
                cout << "Enter item name to search: ";
                cin >> name;
                inventory.searchItem(name);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}
