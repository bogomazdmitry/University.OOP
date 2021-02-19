#pragma once
#include <iostream>
#include <ctime>

using namespace std;

template <class T>
class Tree
{
private:
	template <class T>
	class Node
	{
	public:	
		T information;
		Node<T>* left = NULL;
		Node<T>* right = NULL;
	
		Node(Node<T>* left = NULL, Node<T>* right = NULL) :
			left(left),
			right(right) {}

		Node(const T& information_, Node<T>* left = NULL, Node<T>* right = NULL) :
			left(left),
			right(right),
			information(information_){}

		//������������ ������� Delete, OtpuingLR, Copy ����� ��� �������� ������� 
		friend void Delete(Node<T>*& top)
		{
			if (top)
			{
				Delete(top->left);
				Delete(top->right);
				delete top;
			}
			top = NULL;
		}

		friend void OutputingLR(Node<T>* top, std::ostream& os)
		{
			if (top)
			{
				OutputingLR(top->left, os);
				os << top->information << ' ';
				OutputingLR(top->right, os);
			}
		}

		friend void Copy(Node<T>*& top, Node<T>* other)
		{
			if (other)
			{
				top = new Node<T>;
				top->information = other->information;
				Copy(top->left, other->left);
				Copy(top->right, other->right);
			}
		}
	};

	Node<T>* top;

public:
	Tree():
		top(NULL)
	{}

	explicit Tree(T information)
	{
		top = new Node<T>(information);
	}

	explicit Tree(const Node<T>& other):
		Node()
	{
		Copy(top, other.top);
	}

	~Tree()
	{
		delate();
	}

	bool empty() const
	{
		return top == NULL;
	}
	//��������� ��������. ���� ������ ���� �����, � �������, ���� ������, �� ������
	void add_element(T newInformation)
	{
		if (top)
		{
			Node<T>* temp = top;
			while (temp)
			{
				if (newInformation >= temp->information)
				{
					if (temp->right)
						temp = temp->right;
					else
					{
						temp->right = new Node<T>(newInformation);
						break;
					}
				}
				else
				{
					if (temp->left)
						temp = temp->left;
					else
					{
						temp->left = new Node<T>(std::move(newInformation));
						break;
					}
				}
			}
		}
		else
		{
			top = new Node<T>(newInformation);
		}
	}

	//���������� ���������� �������
	template<class T = int>
	void random(int size, int random)
	{
		for (int i = 0; i < size; ++i)
		{
			add_element(rand() % random + 1);
		}
	}

	//�������� ������ � ������� ����������� �������
	void delate()
	{
		Delete(top);
	}

	//����� � ������� ����������� ������� � ������� �����������
	friend ostream& operator<< (ostream& os, const Tree<T>& top)
	{
		OutputingLR(top.top,os);
		return os;
	}

	//�������������� ������� � ��������� ���� � ������������ ���������
	void Del_max()
	{
		Node<T>* temp = top;
		if (!(top->right))
		{
			top = top->left;
			temp->left = NULL;
			delete temp;
		}
		else
		{
			while (temp->right->right)
			{
				temp = temp->right;
			}
			Node<T>* temp1 = temp->right;
			temp->right = temp->right->left;
			temp1->left = NULL;
			delete temp1;

		}
	}

	//������� ���������� ��������, ���� �� �������, �� NULL
	Node<T> find(T information)
	{
		Node<T>* temp = top;
		while (temp != NULL && temp->information != information)
		{
			if (information > temp->information)
			{
				temp = temp ->right;
			}
			else
			{
				temp = temp->left;
			}
		}
		if (temp != NULL)
		{
			return temp;
		}
		else
		{
			throw std::exception("Not found");
		}
	}
};

//���� � ������� ������� ���������� ��������
template<class T>	
std::istream& operator>> (std::istream& is, Tree<T>& top)
{
	top.delate();
	cout << "������� ���������� ����� � ������:" << endl;
	size_t sizeTree;
	is >> sizeTree;
	T number;
	cout << "������� ������:" << endl;
	for (size_t i = 0; i < sizeTree; ++i)
	{
		is >> number;
		top.add_element(number);
	}
	return is;
}