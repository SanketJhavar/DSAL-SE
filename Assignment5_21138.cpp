/*
Sanket Ganesh Jhavar
Roll no.:21138
SE-1     F-1  Batch
*/
#include <iostream>
using namespace std;

class Hashing
{
    string meaning, keyword;
    Hashing *next;

public:
    Hashing()
    {
        meaning = "";
        keyword = "";
        next = NULL;
    }
    Hashing(string keyword, string meaning)
    {
        this->keyword = keyword;
        this->meaning = meaning;
        next = NULL;
    }
    friend class HashTable;
};

class HashTable
{
    Hashing *table[100];

public:
    HashTable()
    {
        for (int i = 0; i < 100; i++)
        {
            table[i] = NULL;
        }
    }
    int Hash_Function(string keyword)
    {
        char key;
        int sum = 0;
        for (int i = 0; i < keyword.length(); i++)
        {
            key = keyword[i];
            sum += key;
        }
        return (sum % 100);
    }
    void insertWithChaining(string keyword, string meaning)
    {

        int i = Hash_Function(keyword);
        Hashing *curr = table[i], *prev = curr;

        if (curr == NULL)
        {
            table[i] = new Hashing(keyword, meaning);
            cout << "Insertion done!!" << endl
                 << endl;
            return;
        }

        while (curr != NULL)
        {
            if (meaning == curr->meaning)
            {
                cout << "Please enter unique number" << endl
                     << endl;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new Hashing(keyword, meaning);
        cout << "Insertion done!!" << endl
             << endl;
    }

    void display()
    {
        // Hashing *curr = table[i];
        cout << "Dictionary record!!!!!!!!" << endl
             << endl;
        for (int i = 0; i < 100; i++)
        {
            Hashing *curr = table[i];
            while(curr != NULL)
            {
                cout << "index: " << i << endl;
                cout << "Keyword: " << curr->keyword << endl;
                cout << "Meaning: " << curr->meaning << endl;
                curr = curr->next;
            }
        }
        cout << "--------------------------------------" << endl;
    }

    void searching(string keyword)
    {
        int index = Hash_Function(keyword);
        Hashing *curr = table[index];
        bool found = false;
        int count = 0;
        while (curr != NULL)
        {
            count++;
            if (curr->keyword == keyword)
            {
                found = true;
                break;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Record not found" << endl
                 << endl;
        }
        else
        {
            cout << "Record found" << endl;
            cout << "Number of comparisons: " << count << endl;
            cout << "Keyword: " << curr->keyword << endl;
            cout << "Meaning: " << curr->meaning << endl
                 << endl;
        }
    }
    void delete_keyword(string keyword)
    {
        int i = Hash_Function(keyword);
        Hashing *temp = table[i]; // here table[i] will act as a head node.
        Hashing *prev = temp;
        if (temp != NULL && temp->keyword == keyword)
        {
            table[i] = temp->next; // Changed head
            delete temp;           // free old head
            return;
        }

        // Else Search for the key to be deleted,
        // keep track of the previous node as we
        // need to change 'prev->next' */
        else
        {
            while (temp != NULL && temp->keyword != keyword)
            {
                prev = temp;
                temp = temp->next;
            }

            // If key was not present in linked list
            if (temp == NULL)
                return;

            // Unlink the node from linked list
            prev->next = temp->next;

            // Free memory
            delete temp;
        }
    }
};

int main()
{
    HashTable wc;
    string keyword;
    string meaning;

    while (true)
    {
        cout << "1. Create Entry" << endl;
        cout << "2. Display" <<endl;
        cout << "3. Search Entry" << endl;
        cout << "4. Delete Entry" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter your Keyword: ";
            cin >> keyword;

            cout << "Enter the meaning: ";
            cin >> meaning;

            cout << "Insertion with chaining done!!!!!!!" << endl
                 << endl;
            wc.insertWithChaining(keyword, meaning);
        }
        else if(choice == 2)
        {
            wc.display();
        }
        else if (choice == 3)
        {
            cout << "Enter the keyword to be searched: ";
            cin >> keyword;

            cout << "Searching started" << endl
                 << endl;
            wc.searching(keyword);
        }
        else if (choice == 4)
        {
            cout << "Enter the keyword to be deleted: ";
            cin >> keyword;
            wc.delete_keyword(keyword);
            cout<<"Keyword deleted Successfully!!!!!!!"<<endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}