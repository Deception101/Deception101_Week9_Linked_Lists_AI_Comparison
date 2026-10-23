#include <iostream>
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    // Insert at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    // Insert at the beginning
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    // Delete first occurrence of value
    void remove(int value) {
        if (head == nullptr)
            return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    // Search for a value
    bool contains(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }
    // Print the list
    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;

    // Start with an empty list
    std::cout << "Empty list: ";
    list.display();

    // Build the list with new values
    std::cout << "\n--- Adding values ---" << std::endl;
    list.append(42);
    list.append(17);
    list.append(88);
    list.append(63);
    list.prepend(1);
    list.display();

    // Search for values that are and aren't in the list
    std::cout << "\n--- Searching ---" << std::endl;
    std::cout << "Contains 88: " << (list.contains(88) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 99: " << (list.contains(99) ? "Yes" : "No") << std::endl;

    // Remove from the middle, the front, and the end
    std::cout << "\n--- Removing values ---" << std::endl;
    std::cout << "Remove 17 (middle): ";
    list.remove(17);
    list.display();

    std::cout << "Remove 1 (first node): ";
    list.remove(1);
    list.display();

    std::cout << "Remove 63 (last node): ";
    list.remove(63);
    list.display();

    // Remove a value that doesn't exist
    std::cout << "\n--- Removing a value that isn't there ---" << std::endl;
    std::cout << "Remove 500: ";
    list.remove(500);
    list.display();

    // Confirm the removed value is really gone
    std::cout << "\nContains 17 after removal: "
              << (list.contains(17) ? "Yes" : "No") << std::endl;

    // Empty the list completely
    std::cout << "\n--- Emptying the list ---" << std::endl;
    list.remove(42);
    list.remove(88);
    list.display();

    return 0;
}