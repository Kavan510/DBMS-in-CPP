#include <bits/stdc++.h>
#include "functions.cpp"
using namespace std;

vector<string> Tokens;

void DisplayTokens()
{
    for (string x : Tokens)
        cout << x << "\n";
}

void ParseIntoTokens(string Query)
{

    string temp = "";

    for (int i = 0; i < Query.size(); i++)
    {
        char c = Query[i];

        if (c == ' ' || c == '(' || c == ')' || c == ',' || c == ';')
        {
            if (temp != "")
                Tokens.push_back(temp);

            temp = "";
        }
        else if (Query[i] == '!' && Query[i + 1] == '=')
        {
            if (temp != "")
                Tokens.push_back(temp);
            temp = "";

            Tokens.push_back("!=");
            i++;
        }
        else if (c == '<' || c == '>' || c == '=') // OR other operators
        {
            if (temp != "")
                Tokens.push_back(temp);
            temp = "";

            Tokens.push_back(string(1, c));
        }
        else
        {
            temp += c;
        }
    }
    if (temp != "")
        Tokens.push_back(temp);
}


void Execute()
{
    if (Tokens.empty())
    {
        cout << "Please enter some commmand" << endl;
        return;
    }
    else if (Tokens[0] == "create" && Tokens[1] == "table")
    {
        CreateTable(Tokens);
    }
    else if (Tokens[0] == "drop" && Tokens[1] == "table")
    {
        cout << "== drop table" << endl;
    }
    else if (Tokens[0] == "describe")
    {
        cout << "== describe" << endl;
    }
    else if (Tokens[0] == "insert" && Tokens[1] == "into")
    {
        cout << "== insert into" << endl;
    }

    else if (Tokens[0] == "delete" && Tokens[1] == "from")
    {
        cout << "== delete from" << endl;
    }
    else if (Tokens[0] == "update")
    {
        cout << "== update" << endl;
    }
    else if (Tokens[0] == "select")
    {
        cout << "== select table" << endl;
    }
    else if (Tokens[0] == "help" && Tokens[1] == "tables")
    {
        cout << "== help tables" << endl;
    }
    else if (Tokens[0] == "help")
    {
        cout << "== help cmd" << endl;
    }
    else if (Tokens[0] == "quit")
    {
        cout << "== quit" << endl;
        exit(0);
    }
    else
    {
        cout << "Unrecognized command" << endl;
    }
}

int main()
{
    system("cls");
    string Query;

    while (1)
    {
        Tokens.clear();
        cout << endl
             << ">> ";

        getline(cin, Query);

        ParseIntoTokens(Query);
        // DisplayTokens();
        Execute();
    }

    return 0;
}