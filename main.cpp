#include <iostream>
using namespace std;
class Comp
{
public:
    int data;
    Comp* next;
    Comp(int _data) :data(_data) {};
};
class Stack
{
public:
    Comp* head;
    Stack()
    {
        this->head = NULL;
    }
    void show_all()
    {
        Comp* temp_comp = head;
        int i = 1;
        cout << "All heads" << endl;
        while (temp_comp)
        {
            cout << i << ": " << temp_comp->data << endl;
            temp_comp = temp_comp->next;
            i++;
        }
    }
    void pop_num(int N) {
        Comp* temp_comp = head;
        Comp* prev = NULL;
        while (temp_comp != NULL) 
        {
            if (temp_comp->data == N) {
                if (temp_comp == head) {
                    head = temp_comp->next;

                    temp_comp->data = NULL;
                    temp_comp->next = NULL;
                }
                else
                {
                    prev->next = temp_comp->next;
                    temp_comp->data = NULL;
                    temp_comp->next = NULL;
                }
            }
            prev = temp_comp; 
            temp_comp = temp_comp->next;
        }
    }
    void push(int data)
    {
        Comp* temp_comp = new Comp(data);
        if (head != NULL)
        {
            temp_comp->next = head;
            head = temp_comp;
        }
        else head = temp_comp;
    }
    void show_last()
    {
        cout << "Last element: " << head->data << endl;
    }
    void pop_last()
    {
        if (head == NULL) return;
        Comp* temp_comp = head;
        head = temp_comp->next;
        delete temp_comp;
    }
};
int main()
{
    setlocale(0, "ru");
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(2);
    st.show_last();
    st.pop_last();
    st.show_last();
    st.show_all();
    st.pop_num(3);
    st.show_all();
}
