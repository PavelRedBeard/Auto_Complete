#pragma once
#include<iostream>
using namespace std;
constexpr auto ALPHABET = 26;
class Node
{
public:
    Node* children[ALPHABET];
    bool endOfWord;
    char letter;
    Node() 
    {
        endOfWord = false;
        for (int i = 0; i < ALPHABET; i++)
        {
            children[i] = NULL;
        }
        letter = '\0';
    }
};
class Trie
{
public:
    Node root;
    void Insert(string str);
    Node* Search(string str);
    void AutoComp(Node* current, string prefix, string suffix);
};

