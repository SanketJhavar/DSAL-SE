/*
Sanket Ganesh Jhavar
Roll no.:21138
SE-1     F-1  Batch
*/
#include <iostream>
using namespace std;
#define n 100
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    friend class binaryTree;
    friend class stack;
};

class stack
{
    Node *arr[n];
    int top;

public:
    stack()
    {
        top = -1;
    }
    void push(Node *nd)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = nd;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    Node *Top()
    {
        if (top == n - 1)
        {
            cout << "No element in Stack" << endl;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1; // here it will return true if the stack is empty and else false.
    }
};

class binaryTree
{
    Node *root = new Node();
    bool root_exist = 0;

public:
    void createTree(Node *temp)
    {
        int choice, element;

        if (root_exist == 0)
        {
            cout << "\nEnter Root Element of Tree : ";
            cin >> temp->data;
            root_exist = 1;
        }

        while (temp->left == NULL || temp->right == NULL)
        {
            cout << "\nYour are at Element : " << temp->data << endl;
            cout << "1.Add Left Element." << endl;
            cout << "2.Add Right Element." << endl;
            cout << "3.Exit" << endl;

            cout << "\nEnter your Choice : ";
            cin >> choice;

            if (choice == 1)
            {
                if (temp->left != NULL)
                {
                    cout << "Left Element to " << temp->data << " is already Added." << endl;
                }
                else
                {
                    Node *new_node = new Node();
                    cout << "Enter Left Element to " << temp->data << " : ";
                    cin >> new_node->data;
                    temp->left = new_node;
                    createTree(temp->left);
                }
            }

            else if (choice == 2)
            {
                if (temp->right != NULL)
                {
                    cout << "Right Element to " << temp->data << " is already Added." << endl;
                }
                else
                {
                    Node *new_node = new Node();
                    cout << "Enter Right Element to " << temp->data << " : ";
                    cin >> new_node->data;
                    temp->right = new_node;
                    createTree(temp->right);
                }
            }

            else if (choice == 3)
            {
                return;
            }

            else
            {
                cout << "Enter a valid choice" << endl;
            }
        }
    }

    void display(Node *temp)
    {
        if (temp == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        int choice;
        while (true)
        {
            cout << "\n1.Inorder Traversal." << endl;
            cout << "2.Preorder Travesal." << endl;
            cout << "3.Postorder Travesal." << endl;
            cout << "4.Exit" << endl;

            cout << "\nEnter your Choice : ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Recursive or iterative???" << endl;
                string in;
                cin >> in;
                if (in == "iterative" || in == "i" || in == "I" || in == "Iterative")
                {
                    cout << "\n\nIterative Inorder Traversal of Binary Tree : " << endl;
                    inorderIterative(temp);
                    cout << endl;
                }
                else
                {
                    cout << "\n\nRecursive Inorder Traversal of Binary Tree : " << endl;
                    inorder(temp);
                    cout << endl;
                }
            }
            else if (choice == 2)
            {
                cout << "Recursive or iterative???" << endl;
                string in;
                cin >> in;
                if (in == "iterative" || in == "i" || in == "I" || in == "Iterative")
                {
                    cout << "\n\nIterative Preorder Traversal of Binary Tree : " << endl;
                    preorderIterative(temp);
                    cout << endl;
                }
                else
                {
                    cout << "\n\nRecursive preorder Traversal of Binary Tree : " << endl;
                    preorder(temp);
                    cout << endl;
                }
            }
            else if (choice == 3)
            {
                cout << "Recursive or iterative???" << endl;
                string in;
                cin >> in;
                if (in == "iterative" || in == "i" || in == "I" || in == "Iterative")
                {
                    cout << "\n\nIterative Postorder Traversal of Binary Tree : " << endl;
                    postorderIterative(temp);
                    cout << endl;
                }
                else
                {
                    cout << "\n\nRecursive postorder Traversal of Binary Tree : " << endl;
                    postorder(temp);
                    cout << endl;
                }
            }
            else if (choice == 4)
            {
                break;
            }
            else
            {
                cout << "Enter a valid choice" << endl;
            }
        }
    }

    void inorder(Node *temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
        else
        {
            cout << "Tree is empty" << endl;
        }
    }

    void inorderIterative(Node *root)
    { // left-root-right
        stack stk;
        Node *temp = root;
        bool isCompleted = false;

        while (!isCompleted)
        {
            if (temp != NULL)
            {
                stk.push(temp);
                temp = temp->left;
            }
            else
            {
                if (stk.empty())
                    isCompleted = true;
                else
                {
                    temp = stk.Top();
                    cout << temp->data << " ";
                    stk.pop();

                    temp = temp->right;
                }
            }
        }
    }

    void preorder(Node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void preorderIterative(Node *root)
    { // root-left-right
        if (root == NULL)
            return;
        stack st;
        Node *curr = root;
        while (!st.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                cout << curr->data << " ";
                if (curr->right)
                    st.push(curr->right);

                curr = curr->left;
            }
            if (st.empty() == false)
            {
                curr = st.Top();
                st.pop();
            }
        }
    }

    void postorder(Node *temp)
    { // left-right-root
        if (temp != NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }

    void postorderIterative(Node* root)
    {
        stack st;
        if (root == NULL)
            return;

        do
        {
            while (root)
            {
                if (root->right)
                    st.push(root->right);
                st.push(root);
                root = root->left;
            }
            root = st.Top();
            st.pop();

            if (root->right && st.Top() == root->right)
            {
                st.pop();         
                st.push(root);  
                root = root->right; 
            }
            else 
            {
                cout<<root->data<<" ";
                root = NULL;
            }
        } while (!st.empty());
    }

    int height(Node *node)
    {
        if (node == NULL)
            return -1;
        else
        {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            if (leftHeight > rightHeight)
                return (leftHeight + 1);
            else
                return (rightHeight + 1);
        }
    }

    int leafcount(Node *node)
    {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
            return 1;
        else
            return leafcount(node->left) +
                   leafcount(node->right);
    }

    int countNonleaf(Node *root)
    {
        if (root == NULL || (root->left == NULL &&
                             root->right == NULL))
            return 0;
        return 1 + countNonleaf(root->left) +
               countNonleaf(root->right);
    }

    Node *deleteTree(Node *&node)
    {
        if (node == NULL)
        {
            // cout << "Nothing to delete" << endl;
            return node;
        }

        deleteTree(node->left);
        deleteTree(node->right);

        cout << "\n Deleting node: " << node->data << endl;
        delete node;

        node = NULL;
        return node;
    }

    void operator=(binaryTree &op)
    {

        root = copy(op.root);
    }

    Node *copy(Node *cpy)
    {
        Node *a;
        if (cpy != NULL)
        {
            a = new Node;
            a->data = cpy->data;
            a->left = copy(cpy->left);
            a->right = copy(cpy->right);
            return a;
        }
        return cpy;
    }

    void swap(Node *swp)
    {
        if (swp != NULL)
        {
            swap(swp->left);
            swap(swp->right);
            if (swp->left != NULL && swp->right != NULL)
            {

                Node *ptr;
                ptr = swp->left;
                swp->left = swp->right;
                swp->right = ptr;
            }
        }
        else
            return;
    }
    Node *get_root()
    {
        return root;
    }

    void set_root()
    {
        root_exist = 0;
        root = new Node();
    }
};

int main()
{
    int choice;
    binaryTree BT;
    while (1)
    {
        cout << "\n1.Create Binary Tree." << endl;
        cout << "2.Display Binary Tree." << endl;
        cout << "3.Find height of tree." << endl;
        cout << "4.Count leaf nodes." << endl;
        cout << "5.Count internal nodes." << endl;
        cout << "6.Copy the tree." << endl;
        cout << "7.Delete tree." << endl;
        cout << "8.Swap the tree." << endl;
        cout << "9.Exit." << endl;

        cout << "\nEnter your Choice : ";
        cin >> choice;
        if (choice == 1)
        {
            BT.set_root();
            BT.createTree(BT.get_root());
        }
        else if (choice == 2)
        {
            BT.display(BT.get_root());
        }
        else if (choice == 3)
        {
            cout << "Height of the binary tree is : " << BT.height(BT.get_root()) << endl;
        }
        else if (choice == 4)
        {
            cout << "Leaf count of the tree is: " << BT.leafcount(BT.get_root()) << endl;
        }
        else if (choice == 5)
        {
            cout << "Number of internal nodes are: " << BT.countNonleaf(BT.get_root()) << endl;
        }
        else if (choice == 6)
        {
            binaryTree cpy;
            cpy = BT;
            Node *cpy1 = cpy.copy(cpy.get_root());
            cout << "Tree copied succesfully!!!!!" << endl;
            cout << "Your inorder traversal for the copied tree is: " << endl;
            BT.inorder(cpy1);
        }
        else if (choice == 7)
        {
            Node *root = BT.get_root();
            Node *deleted = BT.deleteTree(root);
            BT.display(deleted);
        }
        else if (choice == 8)
        {
            BT.swap(BT.get_root());
            cout << "Tree is swapped succesfully\n";
        }
        else if (choice == 9)
        {
            break;
        }
        else
        {
            cout << "Enter a valid choice" << endl;
        }
    }

    return 0;
}
