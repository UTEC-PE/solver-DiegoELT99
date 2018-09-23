#ifndef NODE_H
#define NODE_H

#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

static map<char,int> Memory;

struct Node
{
    //Attributes of each node.
    string data; //Value
    Node* left; //Node to the left
    Node* right; //Node to the right

    //Functions of each node.
    Node(string value)
    {
        this -> data = value; //Constructor
    }

    int findPriority()
    {
        int parenthesisCounter = 0;

        for (int i = 0; i < data.length(); ++i)
        {
            if (this -> data[i] == '(') parenthesisCounter++;
            else if(this -> data[i] == ')') parenthesisCounter--;

            if ((data[i] == '+' || data[i] == '-') && parenthesisCounter == 0)
            {
                left = new Node(data.substr(0,i));
                right = new Node(data.substr(i+1,data.length()-1));
                data = data[i];

                left -> findPriority();
                right -> findPriority();

                return i;
            }


        }

        for (int i = 0; i < data.length(); ++i)
        {
            if (this -> data[i] == '(') parenthesisCounter++;
            else if(this -> data[i] == ')') parenthesisCounter--;

            if ((data[i] == '*' || data[i] == '/') && parenthesisCounter == 0)
            {
                left = new Node(data.substr(0,i));
                right = new Node(data.substr(i+1,data.length()-1));
                data = data[i];

                left -> findPriority();
                right -> findPriority();

                return i;
            }

        }

        for (int i = 0; i < data.length(); ++i)
        {
            if (this -> data[i] == '(') parenthesisCounter++;
            else if(this -> data[i] == ')') parenthesisCounter--;

            if ((data[i] == '^' && parenthesisCounter == 0))
            {
                left = new Node(data.substr(0,i));
                right = new Node(data.substr(i+1,data.length()-1));
                data = data[i];

                left -> findPriority();
                right -> findPriority();

                return i;
            }
        }

        if (data[0] == '(' && data[data.length() - 1] == ')')
        {
            data = data.substr(1, data.length()-2);
            findPriority();
        }

    }

    double operate()
    {
        switch(data[0])
        {
            case '+':
                return left -> operate() + right -> operate();
            case '-':
                return left -> operate() - right -> operate();
            case '*':
                return left -> operate() * right -> operate();
            case '/':
                return left -> operate() / right -> operate();
            case '^':
                return pow(left -> operate(),  right -> operate());
            default:
            {
                if ((data[0] >= 65 && data[0] <= 90) || (data[0] >= 97 && data[0] <= 122))
                {
                    if(Memory.find(data[0]) == Memory.end())
                    {
                        int variable;
                        cout << "Ingrese una variable " << data[0] << ": " << endl;
                        cin >> variable;
                        cout << endl;
                        Memory.insert(pair<char,int>(data[0],variable));
                        return variable;
                    }
                    else

                        return Memory.find(data[0])->second;

                }
                else
                    return atof(data.c_str());
            }
        }
    }
};

#endif