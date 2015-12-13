include <stddef.h>

template <typename T>
class SimpleBinaryTree
{
    static SimpleBinaryTree* dup(const SimpleBinaryTree& tree)
    {
        return new SimpleBinaryTree(tree.value, dup(tree.left), dup(tree.right));
    }

    static void free(SimpleBinaryTree* tree)
    {
        if (tree->left)
            free(tree->left);

        if (tree->right)
            free(tree->right);

        delete tree;
    }

public:
    T value;
    SimpleBinaryTree *left, *right;

    SimpleBinaryTree(): left(NULL), right(NULL) {}

    SimpleBinaryTree(const T& _value): value(_value) {}

    SimpleBinaryTree(const T& _value, const SimpleBinaryTree& _left, const SimpleBinaryTree& _right):
            value(_value), left(dup(_left)), right(dup(_right)) {}

    SimpleBinaryTree(const T& _value, SimpleBinaryTree*& _left, SimpleBinaryTree*& _right):
            value(_value), left(_left), right(_right)
    {
        _left = _right = NULL;
    }

    SimpleBinaryTree(const SimpleBinaryTree& other): value(other.value), left(dup(other.left)), right(dup(other.right)) {}

    SimpleBinaryTree& operator=(const SimpleBinaryTree& other)
    {
        if (&other != this)
        {
            value = other.value;
            free(left);
            left = dup(other.left);
            free(right);
            right = dup(other.right);
        }

        return *this;
    }

    ~SimpleBinaryTree()
    {
        free(left);
        free(right);
    }
};
