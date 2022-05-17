/*
Sanket Ganesh Jhavar
Roll no.:21138
SE-1     F-1  Batch
*/
#include <iostream>
#include <string.h>
#include<string>
#include<cstring>
using namespace std;

class node
{
    string k;
    string m;
    node *left;
    node *right;

public:
    node()
    {
        k = ' ';
        m = ' ';
        left = NULL;
        right = NULL;
    }
    friend class dict;
};

class dict
{
    node *root = new node();
    bool root_exist = 0;

public:
    void create(node *temp);
    void disp(node *);
    void insert(node *root, node *temp);
    int search(node *, string);
    int update(node *, string);
    node *del(node *, string);
    void Ascending_order(node* root);
	void Descending_order(node* root);
    node *min(node *);
    node *get_root();
    void set_root();
};

void dict ::create(node *temp)
{
    int ch;
    do
    {
        temp = new node();
        cout << "\nEnter Keyword:";
        cin.ignore();
        getline(cin,temp->k);
        cout << "\nEnter Meaning:";
        getline(cin,temp->m);

        if (!root_exist)
        {
            root = temp;
            root_exist=1;
        }
        else
        {
            insert(root, temp);
        }
        cout << "\nDo u want to add more (y=1/n=0):";
        cin >> ch;
    } while (ch == 1);
}

void dict ::insert(node *root, node *temp)
{
    if (temp->k < root->k )
    {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else
    {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}

void dict::disp(node *root)
{
    if (root != NULL)
    {
        disp(root->left);
        cout << "\n Key Word :" << root->k;
        cout << "\t Meaning :" << root->m;
        disp(root->right);
    }
}

int dict ::search(node *root, string k)
{
    int c = 0;
    if(root==NULL)
    {
        cout<<"Keyword not found"<<endl;
    }
    while (root != NULL)
    {
        c++;
        if (k == root->k)
        {
            cout << "\nNo of Comparisons:" << c;
            return 1;
        }
        if (k < root->k)
            root = root->left;
        if (k > root->k)
            root = root->right;
    }

    return -1;
}
int dict ::update(node *root,string k)
{
    while (root != NULL)
    {
        if (k == root->k)
        {
            cout << "\nEnter New Meaning of Keyword: " << root->k;
            cin.ignore();
            getline(cin,root->m);
            return 1;
        }
        if (k < root->k)
            root = root->left;
        if (k > root->k)
            root = root->right;
    }
    return -1;
}
node *dict ::del(node *root, string k)
{
    node *temp;

    if (root == NULL)
    {
        cout << "\nElement Not Found";
        return root;
    }

    if (k < root->k)
    {
        root->left = del(root->left, k);
        return root;
    }
    if (k > root->k)
    {
        root->right = del(root->right, k);
        return root;
    }

    if (root->right == NULL && root->left == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    else if (root->left == NULL)

    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }
    temp = min(root->right);
    root->k = temp->k;
    root->right = del(root->right, temp->k);
    return root;
}

node *dict ::min(node *q)
{
    while (q->left != NULL)

    {
        q = q->left;
    }
    return q;
}
node *dict::get_root()
{
    return root;
}

void dict ::set_root()
{
    root_exist = 0;
    root = new node();
}

void dict::Ascending_order(node* root)
	{
		//For ascending order we will do inorder traversal of BST
		node* temp=root;
		if(temp!=NULL)
		{
			Ascending_order(temp->left);
			cout<<temp->k<<" "<<temp->m<<"\n";
			Ascending_order(temp->right);
		}
	}
void dict::Descending_order(node* root)
	{
		node* temp=root;
		if(temp!=NULL)
		{
			Descending_order(temp->right);
			cout<<temp->k<<" "<<temp->m<<"\n";
			Descending_order(temp->left);
		}
	}

int main()
{
    int ch;
    dict d;
    do
    {
        cout << "\nMenu\n1.Create Dictionary\n2.Display the keyword and its meaning\n3.Search the keyword\n4.Update keyword's meaning\n5.Delete the keyword\n6.Ascending order\n7.Descending order\n8.Exit\nEnter your choice:";
        cin>>ch;

        switch (ch)
        {
        case 1:
            d.set_root();
            d.create(d.get_root());
            break;
        case 2:
            d.disp(d.get_root());

            break;
        case 3:
        {
            cout << "\nEnter Keyword which u want to search: ";
            string k;
            cin.ignore();
            getline(cin,k);

            if (d.search(d.get_root(), k) == 1)
                cout << "\nKeyword Found";
            else
                {
                    cout << "\nKeyword Not Found";
                }
            break;
        }
        case 4:
        {
            cout << "\nEnter Keyword whose meaning you want to update: ";
            string k;
            cin.ignore();
            getline(cin,k);
            if (d.update(d.get_root(), k) == 1)
                cout << "\nMeaning Updated";
            else
                cout << "\nKeyword Not Found";
            break;
        }
        case 5:
        {
            cout << "\nEnter Keyword which u want to delete: ";
            string k;
            cin.ignore();
            getline(cin,k);
            node* temp = d.del(d.get_root(), k);
            break;
        }
        case 6:
            {
            if(d.get_root() == NULL)
	    	 	{
	    			cout<<"\nNo Keyword Present";
                    break;
	    	 	}
	        else
	    	   {
	    		   d.Ascending_order(d.get_root());
                   break;
	    	   }
            }
            
		case 7:
		        {
                if(d.get_root() == NULL)
	    	 		{
	    	 			cout<<"\nNo Keyword Present";
                        break;
	    	 		}
	    	    else
	    	       {
	    		     d.Descending_order(d.get_root());
                     break;
	    	       }
                }
        case 8:
            break;
        }
    } while (ch <= 7);
    return 0;
}