#include<iostream>
#include <fstream>
#include<string>
#include"Trie.h"
using namespace std;

int main()
{
    Trie tree;
    fstream file;
    string word;
    file.open("words.txt", fstream::in);
    if (!file.is_open())
    {
        cout << "File not open";
        return 0;
    }
    while (!file.eof())
    {
        getline(file, word);
        tree.Insert(word);
    }
    while (true)
    {
        cout << "Enter word or 0 for exit: "<<endl;
        cin >> word;
        if (word == "0")
        {
            return 0;
        }
        cout << "-----------------------------------\n";
        Node* current = tree.Search(word);

        if (current == NULL || current == &tree.root)
        {
            cout << "Suggestion not found" << endl;
        }
        else
        {
            bool children = false;
            for (size_t i = 0; i < ALPHABET; i++)
            {
                if (current->children[i] != NULL)
                {
                    children = true;
                    break;
                }
            }

            if (children == false)
            {
                cout << "Suggestion not found" << endl;
            }
            else
            {
                cout << "Suggestion words: " << word << endl;
                tree.AutoComp(current, word, "");
                cout << "-----------------------------------\n";
            }
        }
    }
    return 0;
};