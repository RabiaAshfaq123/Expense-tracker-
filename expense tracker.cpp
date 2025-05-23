

#include <iostream>
using namespace std;

struct Expense {
    int id;
    string description;
    float amount;
    Expense* next;
};

class ExpenseTracker {
private:
    Expense* head;
    int nextId;

public:
    ExpenseTracker() {
        head = nullptr;
        nextId = 1;
    }

    void addExpense(string desc, float amt) {
        Expense* newExp = new Expense{nextId++, desc, amt, head};
        head = newExp;
        cout << "Expense added successfully.\n";
    }

    void viewExpenses() {
        Expense* temp = head;
        if (!temp) {
            cout << "No expenses to show.\n";
            return;
        }
        cout << "\nAll Expenses:\n";
        while (temp) {
            cout << "ID: " << temp->id << ", Description: " << temp->description << ", Amount: $" << temp->amount << endl;
            temp = temp->next;
        }
    }

    void deleteExpense(int id) {
        Expense *temp = head, *prev = nullptr;
        while (temp && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Expense with ID " << id << " not found.\n";
            return;
        }
        if (!prev)
            head = head->next;
        else
            prev->next = temp->next;
        delete temp;
        cout << "Expense deleted successfully.\n";
    }

    void editExpense(int id, string newDesc, float newAmt) {
        Expense* temp = head;
        while (temp && temp->id != id) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Expense with ID " << id << " not found.\n";
            return;
        }
        temp->description = newDesc;
        temp->amount = newAmt;
        cout << "Expense updated successfully.\n";
    }

    void generateReport() {
        float total = 0;
        Expense* temp = head;
        while (temp) {
            total += temp->amount;
            temp = temp->next;
        }
        cout << "Total Expense: $" << total << endl;
    }
};

// Main function to demonstrate usage
int main() {
    ExpenseTracker tracker;
    int choice;
    do {
        cout << "\n1. Add Expense\n2. View All Expenses\n3. Edit Expense\n4. Delete Expense\n5. Generate Report\n6. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string desc;
                float amt;
                cout << "Enter description: ";
                getline(cin, desc);
                cout << "Enter amount: ";
                cin >> amt;
                tracker.addExpense(desc, amt);
                break;
            }
            case 2:
                tracker.viewExpenses();
                break;
            case 3: {
                int id;
                string newDesc;
                float newAmt;
                cout << "Enter ID of expense to edit: ";
                cin >> id;
                cin.ignore();
                cout << "Enter new description: ";
                getline(cin, newDesc);
                cout << "Enter new amount: ";
                cin >> newAmt;
                tracker.editExpense(id, newDesc, newAmt);
                break;
            }
            case 4: {
                int id;
                cout << "Enter ID of expense to delete: ";
                cin >> id;
                tracker.deleteExpense(id);
                break;
            }
            case 5:
                tracker.generateReport();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}