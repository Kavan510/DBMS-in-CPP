#include <bits/stdc++.h>
using namespace std;

void Delete(fstream &file,string name)
{
    fstream temp;
    temp.open("temp.txt",ios::out);

    string line;
    bool hasFound = false;
    while(!file.eof())
    {
       getline(file,line);
       if(line==name)
       {
           hasFound = true;
           continue;
       }
       temp << line << endl;
    }
    if(hasFound)
        cout<<"Name found"<<endl;
    else
        cout<<"Name not found"<<endl;

    temp.close();
    file.close();
    remove("names.txt");
    rename("temp.txt","names.txt");
}

void Write()
{
    
    
}

void remove_endl()
{
    fstream names;
    names.open("names.txt",ios::in);

    fstream temp;

}
string ExtractCol(string tuple,int colno)//<223,Kavan Kansodariya,07-10-2004>
{
    //tuple = <223,Kavan Kansodariya,07-10-2004>
    int comma=0;
    int i=1;
    while(comma<colno)
    {
        if(tuple[i]==',')
            comma++;
        i++;
    }
    
    string pk="";
    
    while(tuple[i]!=','&& tuple[i]!='>')
    {
        pk+=tuple[i];
        i++;
    }
        
    
    //cout<<"pk: "<<pk<<endl;
    return pk;
}
int main()
{
    
    system("cls");
    
    string s = "<223,Kavan Kansodariya,07-10-2004>";
    cout<<"extracted: "<<ExtractCol(s,2)<<endl;

    //Delete Krish
    //Delete(names,"DJ");

    //remove_endl();

}