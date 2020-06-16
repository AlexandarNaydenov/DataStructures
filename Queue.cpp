#include <iostream>
#include <stdexcept>
#include <list>
using namespace std;

template <typename T>
class Queue {
private:
    list<T> data;
public:
    void push(T newData) {
        data.push_back(newData);
    }

    void pop() {
        if (data.size() > 0) {
            data.pop_front();
        }
        else {
           cout << "Queue is empty" << endl;
        }
    }

    int peek() const {
        if (data.size() > 0) {
            return data.front();
        }
        else {
            cout << "Queue is empty" << endl;
        }
    }

    bool isEmpty() const {
        return data.size() == 0;
    }
};

int main() {
    Queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.isEmpty()) {
        cout << q.peek() << endl;
        q.pop();
    }

    q.pop();
}
