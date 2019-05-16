#include <iostream>
#include <locale.h>
using namespace std;
class Node
{
	friend class Tree;
private:
	Node *left;
	Node *right;
	int value;
public:
	Node()
	{
		left  = nullptr;
		right = nullptr;
	}
};
class Tree
{
private:
	Node *root;
public:
	Tree()
	{
		root = nullptr;
	}
	void insert(int x)
	{
		if (root == nullptr)
		{
			root = new Node;
			root->value = x;
		}
		else
		{
			insertRecursion(root, x);
		}
	}
	void printReverse()
	{
		Node *curElem = root;
		if (curElem == nullptr)
		{
			cout << "Дерево пустое" << endl;
		}
		else
		{
			printReverseRecursion(curElem);
		}
	}
	void printSymmetric()
	{
		Node *curElem = root;
		if (curElem == nullptr)
		{
			cout << "Дерево пустое" << endl;
		}
		else
		{
			printSymmetricRecursion(curElem);
		}
	}
	void printStraight()
	{
		Node *curElem = root;
		if (curElem == nullptr)
		{
			cout << "Дерево пустое" << endl;
		}
		else
		{
			printStraightRecursion(curElem);
		}
	}
	void add(Tree &a)
	{
		Node *curElem = root;
		if (curElem == nullptr)
		{
			cout << "Дерево пустое" << endl;
		}
		else
		{
			addRecursion(curElem, a);
		}
	}
private:
	void insertRecursion(Node *curElem, int &x)
	{
		if (x == curElem->value)
		{
			cout << "Занято!";
		}
		else
		{
			if (x < curElem->value)
			{
				if (curElem->left == nullptr)
				{
					curElem->left = new Node;
					curElem->left->value = x;
				}
				else
				{
					insertRecursion(curElem->left, x);
				}
			}
			else
			{
				if (curElem->right == nullptr)
				{
					curElem->right = new Node;
					curElem->right->value = x;
				}
				else
				{
					insertRecursion(curElem->right, x);
				}
			}
		}
	}
	void addRecursion(Node *curElem, Tree &a)
	{
		a.insert(curElem->value);
		if (curElem->left != nullptr)
		{
			if (curElem->left->left != nullptr || curElem->left->right != nullptr)
			{
				addRecursion(curElem->left, a);
			}
			else
			{
				a.insert(curElem->left->value);
			}
		}
		if (curElem->right != nullptr)
		{
			if (curElem->right->left != nullptr || curElem->right->right != nullptr)
			{
				addRecursion(curElem->right, a);
			}
			else
			{
				a.insert(curElem->right->value);
			}
		}
	}
	void printStraightRecursion(Node *curElem)
	{
		cout << curElem->value << endl;
		if (curElem->left != nullptr)
		{
			if (curElem->left->left != nullptr || curElem->left->right != nullptr)
			{
				printStraightRecursion(curElem->left);
			}
			else
			{
				cout << curElem->left->value << endl;
			}
		}
		if (curElem->right != nullptr)
		{
			if (curElem->right->left != nullptr || curElem->right->right != nullptr)
			{
				printStraightRecursion(curElem->right);
			}
			else
			{
				cout << curElem->right->value << endl;
			}
		}
	}
	void printReverseRecursion(Node *curElem)
	{
		if (curElem->left != nullptr)
		{
			if (curElem->left->left != nullptr || curElem->left->right != nullptr)
			{
				printReverseRecursion(curElem->left);
			}
			else
			{
				cout << curElem->left->value << endl;
			}
		}
		if (curElem->right != nullptr)
		{
			if (curElem->right->left != nullptr || curElem->right->right != nullptr)
			{
				printReverseRecursion(curElem->right);
			}
			else
			{
				cout << curElem->right->value << endl;
			}
		}
		cout << curElem->value << endl;
	}
	void printSymmetricRecursion(Node *curElem)
	{
		if (curElem->left != nullptr)
		{
			if (curElem->left->left != nullptr || curElem->left->right != nullptr)
			{
				printSymmetricRecursion(curElem->left);
			}
			else
			{
				cout << curElem->left->value << endl;
			}
		}
		cout << curElem->value << endl;
		if (curElem->right != nullptr)
		{
			if (curElem->right->left != nullptr || curElem->right->right != nullptr)
			{
				printSymmetricRecursion(curElem->right);
			}
			else
			{
				cout << curElem->right->value << endl;
			}
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	Tree a;
	Tree b;
	a.insert(10);
	a.insert(5);
	a.insert(4);
	a.insert(6);
	a.insert(15);
	a.insert(14);
	a.insert(16);
	cout << "Дерево А, вывод обратный: " << endl;
	a.printReverse();
	cout << endl;
	b.insert(9);
	b.insert(3);
	b.insert(2);
	b.insert(7);
	b.insert(13);
	b.insert(11);
	b.insert(17);
	cout << "Дерево В, вывод семетричный: " << endl;
	b.printSymmetric();
	cout << endl;
	cout << "Дерево А, после добавления элементов дерева В (вывод дерева прямым проходом):" << endl;
	b.add(a);
	a.printStraight();
	system("pause");
	return 0;
}