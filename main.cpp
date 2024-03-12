#include <iostream>

// Структура узла стека
struct Node {
    int data;
    Node* next;
};

// Структура стека
struct Stack {
    Node* top;
};

// Инициализация стека
void init(Stack &s) {
    s.top = nullptr;
}

// Проверка на пустоту стека
bool isEmpty(Stack &s) {
    return s.top == nullptr;
}

// Добавление элемента в стек
void push(Stack &s, int newItem) {
    Node* newNode = new Node;
    newNode->data = newItem;
    newNode->next = s.top;
    s.top = newNode;
    std::cout << "Элемент " << newItem << " добавлен в стек." << std::endl;
}

// Удаление элемента из стека
void pop(Stack &s) {
    if (isEmpty(s)) {
        std::cout << "Стек пуст, невозможно удалить элемент." << std::endl;
    } else {
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
}

// Получение верхнего элемента стека
int top(Stack &s) {
    if (isEmpty(s)) {
        std::cout << "Стек пуст." << std::endl;
        return -1;
    } else {
        return s.top->data;
    }
}

// Получение всех элементов стека
void getAllElements(Stack &s) {
    if (isEmpty(s)) {
        std::cout << "Стек пуст." << std::endl;
    } else {
        std::cout << "Элементы стека: ";
        Node* current = s.top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

// Пример использования
int main() {
    setlocale (0,"ru")
    Stack stack;
    init(stack);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    getAllElements(stack);

    std::cout << "Верхний элемент стека: " << top(stack) << std::endl;

    pop(stack);
    pop(stack);

    getAllElements(stack);

    return 0;
}
