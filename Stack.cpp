#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> data;
public:
    void push(T number) {
        data.push_back(number);
    }

    void pop() {
        if (data.size() > 0) {
            data.pop_back();
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }

    int peek() const {
        if (data.size() > 0) {
            return data.back();
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }

    bool isEmpty() const {
        return data.size() == 0;
    }
};

int main() {
    Stack <int> s;
    s.push(5);
    s.push(2);
    s.push(1);
    cout << s.peek() << " "; // 1
    s.pop();
    cout << s.peek() << " "; // 2
    s.pop();
    cout << s.peek() << " "; // 5
    s.pop();
    s.pop(); //Stack is empty
    cout << s.isEmpty(); // 1 because it is empty
}
