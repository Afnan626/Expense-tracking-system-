#include <iostream>
#include <string>
using namespace std;

struct Expense {
    int id;
    string expenseName;
    float price;
    string quantity;
    Expense* next;
};

class ExpenseTracker {
private:
    Expense* head;
    int nextId;

public:
    ExpenseTracker() {
        head = NULL;
        nextId = 1;
    }

    void addExpense(string name, float price, string quantity) {
        Expense* newExpense = new Expense;
        newExpense->id = nextId++;
        newExpense->expenseName = name;
        newExpense->price = price;
        newExpense->quantity = quantity;
        newExpense->next = NULL;

        if (head == NULL) {
            head = newExpense;
        } else {
            Expense* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newExpense;
        }

        cout << "\n? Expense added successfully!\n";
    }

    void updateExpense(int id) {
        Expense* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Enter new expense name: ";
                cin >> temp->expenseName;
                cout << "Enter new price: ";
                cin >> temp->price;
                cout << "Enter new quantity: ";
                cin >> temp->quantity;
                cout << "\n?? Expense updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\n? Expense with ID " << id << " not found.\n";
    }

    void deleteExpense(int id) {
        Expense* temp = head;
        Expense* prev = NULL;

        while (temp != NULL) {
            if (temp->id == id) {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "\n??? Expense deleted successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "\n? Expense with ID " << id << " not found.\n";
    }

    void displayExpenses() {
        if (head == NULL) {
            cout << "\n?? No expenses recorded.\n";
            return;
        }

        cout << "\n?? All Expenses:\n";
        cout << "-------------------------------------------------\n";
        cout << " ID | Expense Name |   Price   |  Quantity\n";
        cout << "-------------------------------------------------\n";

        Expense* temp = head;
        while (temp != NULL) {
            cout << " " << temp->id
                 << "  | " << temp->expenseName
                 << "          | $" << temp->price
                 << "   | " << temp->quantity << "\n";
            temp = temp->next;
        }

        cout << "-------------------------------------------------\n";
    }

    ~ExpenseTracker() {
        while (head != NULL) {
            Expense* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;

    do {
        cout << "\n====== Expense Tracker Menu ======\n";
        cout << "1. Add Expense\n";
        cout << "2. Update Expense\n";
        cout << "3. Delete Expense\n";
        cout << "4. View All Expenses\n";
        cout << "5. Exit\n";
        cout << "==================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, quantity;
                float price;
                cout << "Enter expense name: ";
                cin >> name;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;
                tracker.addExpense(name, price, quantity);
                break;
            }
            case 2: {
                int id;
                cout << "Enter expense ID to update: ";
                cin >> id;
                tracker.updateExpense(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter expense ID to delete: ";
                cin >> id;
                tracker.deleteExpense(id);
                break;
            }
            case 4:
                tracker.displayExpenses();
                break;
            case 5:
                cout << "\n?? Exiting the Expense Tracker. Goodbye!\n";
                break;
            default:
                cout << "\n? Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
