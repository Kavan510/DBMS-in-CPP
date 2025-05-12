#include <bits/stdc++.h>
using namespace std;

vector<string>Tokens;

void DisplayTokens()
{
    for(string x:Tokens)
        cout<<x<<",";
}

void ParseIntoTokens(string Query)
{
    // stringstream space(Query);
    // string i;

    // while(getline(space,i,' '))
    //     Tokens.push_back(i);

    string temp="";

    for(char c:Query)
    {
        if(c==' ' || c=='(' || c==')' || c==',' || c==';')
        {
            if(temp!="")
                Tokens.push_back(temp);
            if(c!=' ')
                Tokens.push_back(string(1,c));
            
            temp = "";
        }
        else 
        {
            temp += c; 
        }
    }
    if(temp!="")
        Tokens.push_back(temp);

}

void Execute()
{
    if(Tokens.empty()){
        cout<<"Please enter some commmand"<<endl;
    }
    else if(Tokens[0]=="create" && Tokens[1]=="table") 
    {
        cout<<"== create table"<<endl;
    }
    else if(Tokens[0]=="drop" && Tokens[1]=="table")
    {
        cout<<"== drop table"<<endl;
    }
    else if(Tokens[0]=="describe")
    {
        cout<<"== describe"<<endl;
    }
    else if(Tokens[0]=="insert" && Tokens[1]=="into")
    {
        cout<<"== insert into"<<endl;
    }
    
    else if(Tokens[0]=="delete" && Tokens[1]=="from")
    {
        cout<<"== delete from"<<endl;
    }
    else if(Tokens[0]=="update")
    {
        cout<<"== update"<<endl;
    }
    else if(Tokens[0]=="select")
    {
        cout<<"== select table"<<endl;
    }
    else if(Tokens[0]=="help" && Tokens[1]=="tables")
    {
        cout<<"== help tables"<<endl;
    }
    else if(Tokens[0]=="help")
    {
        cout<<"== help cmd"<<endl;
    }
    else if(Tokens[0]=="quit")
    {
        cout<<"== quit"<<endl;
        exit(0);
    }
    else{
        cout<<"Unrecognized command"<<endl;
    }
    
}

int main()
{
    system("cls");
    string Query;
    
    while(1)
    {
        Tokens.clear(); 
        cout<<endl<<">> ";

        getline(cin,Query);
        
        ParseIntoTokens(Query);
        DisplayTokens();
        // Execute();  
    }
    
    return 0;
}