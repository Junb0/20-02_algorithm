#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename U>
class Node
{
public:
	U data;
	int color;

	Node* parent;
	Node* left;
	Node* right;

	Node(U value)
	{
		data = value;
		this->color = 1;

		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

	int compare(Node* other)
	{
		if (this->data > other->data) return 1;
		else if (this->data < other->data) return -1;
		else return 0;
	}
};

template <typename T>
class RB_tree
{
private:
	const int RED = 0;
	const int BLACK = 1;
	
	Node<T>* NIL;
	Node<T>* root;
	int size;

	void printInOrder(Node<T>* node)
	{
		if (node != NIL)
		{
			printInOrder(node->left);

			std::cout << node->data << "(";
			if (node->color == 0) std::cout << "RED";
			else if (node->color == 1) std::cout << "BLACK";
			std::cout << ") ";

			printInOrder(node->right);
		}
	}

	void print2DUtil(Node<T>* root, int space, int &count)
	{
		// Base case  
		if (root == NIL)
			return;

		// Increase distance between levels  
		space += 10;

		// Process right child first  
		print2DUtil(root->right, space);

		// Print current node after space  
		// count  
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		std::cout << root->data;
		if (root->color == 0)
			std::cout << "[R]";
		else
			std::cout << "[B]";
		std::cout << std::endl;

		// Process left child  
		print2DUtil(root->left, space);
	}

	void left_rotate(Node<T>* node)
	{
		Node<T>* child = node->right;

		node->right = child->left;
		if (child->left != NIL) child->left->parent = node;
		child->parent = node->parent;

		if (node->parent == NIL)
			root = child;
		else if (node->parent->left == node)
			node->parent->left = child;
		else
			node->parent->right = child;

		child->left = node;
		node->parent = child;
	}

	void right_rotate(Node<T>* node)
	{
		Node<T>* child = node->left;

		node->left = child->right;
		if (child->right != NIL) child->right->parent = node;
		child->parent = node->parent;

		if (node->parent == NIL)
			root = child;
		else if (node->parent->left == node)
			node->parent->left = child;
		else
			node->parent->right = child;

		child->right = node;
		node->parent = child;
	}

	void insert_fixup(Node<T>* target)
	{
		while (target->parent != NIL && target->parent->color == RED)
		{
			if (target->parent == target->parent->parent->left)
			{
				Node<T> *uncle = target->parent->parent->right;

				if (uncle->color == RED) // Case 1
				{
					target->parent->color = BLACK;
					target->parent->parent->color = RED;
					uncle->color = BLACK;
					target = target->parent->parent;
				}
				else // Case 2
				{
					if (target == target->parent->right) // Case 2-1
					{
						target = target->parent;
						left_rotate(target);
					}
					// Case 2-2
					target->parent->color = BLACK;
					target->parent->parent->color = RED;
					target = target->parent->parent;					
					right_rotate(target);
				}
			}
			else
			{
				Node<T>* uncle = target->parent->parent->left;

				if (uncle->color == RED) // Case 1
				{
					target->parent->color = BLACK;
					target->parent->parent->color = RED;
					uncle->color = BLACK;
					target = target->parent->parent;
				}
				else // Case 2
				{
					if (target == target->parent->left) // Case 2-1
					{
						target = target->parent;
						right_rotate(target);
					}
					// Case 2-2
					target->parent->color = BLACK;
					target->parent->parent->color = RED;
					target = target->parent->parent;
					left_rotate(target);
				}
			}
		}
		root->color = BLACK;
	}

	void remove_fixup(Node<T>* target)
	{
		while (target != root && target->color == BLACK)
		{
			if (target == target->parent->left)
			{
				Node<T>* sib = target->parent->right;

				if (sib->color == RED) // Case 2-4
				{
					sib->color = BLACK;
					target->parent->color = RED;
					left_rotate(target->parent);
					sib = target->parent->right;
				}

				if (sib->left->color == BLACK && sib->right->color == BLACK) // Case 1-1, 2-1
				{
					sib->color = RED;
					target = target->parent;
				}
				else
				{
					if (sib->left->color == RED) // Case *-3
					{
						sib->left->color = BLACK;
						sib->color = RED;
						right_rotate(sib);
						sib = target->parent->right;
					}
					// Case *-2
					sib->color = target->parent->color;
					sib->right->color = BLACK;
					target->parent->color = BLACK;
					left_rotate(target->parent);

					target = root;
				}
			}
			else
			{
				Node<T>* sib = target->parent->left;

				if (sib->color == RED) // Case 2-4
				{
					sib->color = BLACK;
					target->parent->color = RED;
					right_rotate(target->parent);
					sib = target->parent->left;
				}

				if (sib->left->color == BLACK && sib->right->color == BLACK) // Case 1-1, 2-1
				{
					sib->color = RED;
					target = target->parent;
				}
				else
				{
					if (sib->right->color == RED) // Case *-3
					{
						sib->right->color = BLACK;
						sib->color = RED;
						left_rotate(sib);
						sib = target->parent->left;
					}
					// Case *-2
					sib->color = target->parent->color;
					sib->left->color = BLACK;
					target->parent->color = BLACK;
					right_rotate(target->parent);

					target = root;
				}
			}
		}
		target->color = BLACK; // Case 1-1
	}

	Node<T>* search_node(Node<T>* node, int value)
	{
		if (node != NIL)
		{
			if (node->data == value)
				return node;
			else if (node->data > value)
				return search_node(node->left, value);
			else
				return search_node(node->right, value);
		}
		return NIL;
	}

	Node<T>* successor(Node<T>* node)
	{
		if (node->right != NIL)
			return getMin(node->right);

		Node<T>* parent = node->parent;

		while (parent != NIL && node == parent->right)
		{
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}

	Node<T>* getMin(Node<T>* node)
	{
		if (node != NIL)
		{
			if (node->left == NIL)
				return node;
			else
				return getMin(node->left);
		}
		return NIL;
	}
public:
	RB_tree()
	{
		NIL = new Node<T>(NULL);
		NIL->parent = NIL;
		NIL->left = NIL;
		NIL->right = NIL;

		root = NIL;
		
		size = 0;
	}

	void insert(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->color = 0;
		newNode->parent = NIL;
		newNode->left = NIL;
		newNode->right = NIL;
		
		Node<T> *target = root;
		Node<T> *parent = NIL;

		while (target != NIL)
		{
			parent = target;
			if (target->compare(newNode) > 0)
				target = target->left;
			else
				target = target->right;
		}

		if (parent == NIL)
			root = newNode;
		else if (parent->compare(newNode) > 0)
			parent->left = newNode;
		else
			parent->right = newNode;

		newNode->parent = parent;
		size++;

		insert_fixup(newNode);
	}

	void print_all()
	{
		int count = 0;
		print2DUtil(root,0,count);
		std::cout << std::endl;
		printInOrder(root);
		std::cout << std::endl;
	}
	
	void search(T value)
	{
		Node<T>* result = search_node(root, value);
		if (result != NIL)
			std::cout << "Data " << result->data <<" Found"<< std::endl;
		else
			std::cout << "Data Not Found" << std::endl;
	}

	T remove(T value)
	{
		Node<T>* removeNode = search_node(root, value);

		if (removeNode == NIL) return NULL;

		Node<T>* target = NIL;

		if (removeNode->left == NIL || removeNode->right == NIL)
			target = removeNode;
		else
			target = successor(removeNode);

		Node<T>* child = NIL;

		if (target->left != NIL)
			child = target->left;
		else
			child = target->right;

		child->parent = target->parent;

		if (target->parent == NIL)
			root = child;
		else if (target == target->parent->left)
			target->parent->left = child;
		else
			target->parent->right = child;

		T result_data = removeNode->data;

		if (target != removeNode)
			removeNode->data = target->data;			

		if (target->color == BLACK)
			remove_fixup(child);

		return result_data;
	}
};

int main()
{
	srand((unsigned int)time(0));
	RB_tree<int>* tree = new RB_tree<int>();

	int num = 0;
	while (1)
	{
		std::cout << "Number of data : ";
		std::cin >> num;
		
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invaild input" << std::endl;
		}
		else if (num <= 0)
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invaild input" << std::endl;
		}
		else
			break;
	}

	int* data = new int[num];
	for (int i = 0; i < num; i++)
	{
		int value = rand() % 100 + 1;
		data[i] = value;
		std::cout << "Inserting : " << value << std::endl;
		tree->insert(value);
		
		tree->print_all();
		std::cout << std::endl << std::endl;
	}

	for (int i = num-1; i >= 0; i--)
	{
		int value = data[i];
		int result = tree->remove(value);

		if (result != NULL)
			std::cout << "Data " << result << " has been removed" << std::endl;
		else
			std::cout << "Data Not Found" << std::endl;
		tree->print_all();
		std::cout << std::endl << std::endl;
	}
	
	delete tree;
	return 0;
}