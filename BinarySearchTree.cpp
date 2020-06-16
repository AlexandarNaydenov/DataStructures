#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;

	Node<T>()
	{
		data = 0;
		left = nullptr;
		right = nullptr;
	}

	Node<T>(T newData)
	{
		data = newData;
		left = nullptr;
		right = nullptr;
	}

	Node<T> operator=(const Node<T>& cpy)
	{
		if (this != &cpy) {

			delete left;
			delete right;

			data = cpy.data;

			if (cpy.left) {
				left = new Node(*cpy.left);
			}
			if (cpy.right) {
				right = new Node(*cpy.right);
			}
		}
		return *this;
	}
};

template<typename T>
class BST
{
private:
	Node<T>* root = nullptr;

	Node<T>* _insert(T data, Node<T>* curr)
	{
		if (curr == nullptr) return new Node<T>(data);
		else
		{
			if (data > curr->data)
			{
				curr->right = _insert(data, curr->right);
			}
			if (data < curr->data)
			{
				curr->left = _insert(data, curr->left);
			}
		}
		return curr;
	}

	void _printInOrder(Node<T>* curr) const
	{
		if (curr) {
			_printInOrder(curr->left);
			cout << curr->data << "  ";
			_printInOrder(curr->right);
		}
	}

	bool _find(T data, Node<T>* curr) const
	{
		if (curr == nullptr) return false;
		else
		{
			if (curr->data == data) return true;
			if (data < curr->data) return _find(data, curr->left);
			if (data > curr->data) return _find(data, curr->right);
		}
	}

	Node<T>* _remove(int data, Node<T>* curr) {
		if (!curr) {
			return nullptr;
		}

		if (data < curr->data) {
			curr->left = _remove(data, curr->left);
		}
		else if (data > curr->data) {
			curr->right = _remove(data, curr->right);
		}
		else { // value = current->data;
			if (!curr->left && !curr->right) {
				free(curr);
				return nullptr;
			}
			else if (!curr->left) {
				Node<T>* tempRight = curr->right;
				free(curr);
				return tempRight;
			}
			else if (!curr->right) {
				Node<T>* tempLeft = curr->left;
				free(curr);
				return tempLeft;
			}
			else {
				Node<T>* swapWith = curr->right;
				while (swapWith->left) {
					swapWith = swapWith->left;
				}

				curr->data = swapWith->data;
				curr->right = _remove(swapWith->data, curr->right);
			}
		}

		return curr;
	}
public:

	void insert(T data)
	{
		root = _insert(data, root);
	}

	void printInOrder() const
	{
			_printInOrder(root);
			cout << endl;
	}

	bool find(T data) const
	{
		return _find(data,root);
		cout << endl;
	}

	void remove(T data)
	{
		root = _remove(data, root);
	}

	void BFS() const
	{
		queue<Node<T>*> q;
		q.push(root);

		while (!q.empty())
		{
			Node<T>* curr = q.front();
			q.pop();
			if (curr)
			{
				cout << curr->data << "  ";
				if (curr->left) {
					q.push(curr->left);
				}
				if (curr->right) {
					q.push(curr->right);
				}
			}
		}
		cout << endl;
	}

	void DFS() const
	{
		stack<Node<T>*> s;
		s.push(root);

		while (!s.empty())
		{
			Node<T>* curr = s.top();
			s.pop();
			if (curr)
			{
				cout << curr->data << "  ";
				if (curr->right) {
					s.push(curr->right);
				}
				if (curr->left) {
					s.push(curr->left);
				}
			}
		}
		cout << endl;
	}
};
int main()
{
	BST<int> tree;
	tree.insert(5);
	tree.insert(2);
	tree.insert(3);
	tree.insert(7);
	tree.printInOrder(); // 2 3 5 7
	tree.BFS(); // 5 2 7 3
	tree.DFS(); // 5 2 3 7
	tree.remove(3);
	tree.printInOrder(); // 2 5 7
	cout << tree.find(2); // true
}
