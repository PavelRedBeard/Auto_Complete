#include "Trie.h"

void Trie::Insert(string str)
{
    Node* current = &root;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (current->children[str.at(i) - 'a'] == NULL)
        {
            current->children[str.at(i) - 'a'] = new Node;
            current->children[str.at(i) - 'a']->letter = str.at(i);
        }
        current = current->children[str.at(i) - 'a'];
    }
    current->endOfWord = true;
}

Node* Trie::Search(string str)
{
    Node* current = &root;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (current->children[str.at(i) - 'a'])
        {
            current = current->children[str.at(i) - 'a'];
        }
        else
        {
            current = NULL;
            break;
        }
    }
    return current;
}

void Trie::AutoComp(Node* current, string prefix, string suffix)
{
    if (current->endOfWord && suffix.size() != 0)
    {
        cout << prefix + suffix << endl;
    }
    for (size_t i = 0; i < ALPHABET; i++) 
    {
        string temp = suffix;
        if (current->children[i])
        {
            temp += current->children[i]->letter;
            AutoComp(current->children[i], prefix, temp);
        }
    }
}

