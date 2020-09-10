#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    getline(cin,s);
    //cout<<s;
    istringstream iss(s);
    string longest;
    int count = 0;
    map <string, int> words;

    do{
        string word;
        iss>>word;
        int counter = 0;
        if(words.find(word)==words.end())
        {
            words.insert(pair<string,int>(word,1));
        }
        else
        {
            map<string,int>::iterator wtr;
            wtr = words.find(word);
            if(wtr != words.end())
                wtr -> second = wtr->second + 1;
        }
        
        for(int i=0; i<word.length(); i++)
        {
            counter = counter + 1;
        }
        //cout<<word<<counter<<'\n';
        if (counter > count)
        {
            count = counter;
            longest = word;
        }

    }while(iss);
    cout<<"longest word in the string"<<"\n"<<longest<<"\n";
    map<string,int>::iterator str;
    cout<<"occurances of the words in string"<<"\n";
    for( str = words.begin(); str != words.end(); ++str){
        if(str->first != " ")
        {
            cout << "word => " << str->first << ", frequency => " << str->second << endl;      
        }
      } 
    
    map <char,int> table;
    for (int i=0; i<s.length(); i++)
    {
        char x = s.at(i);
        if(table.find(x)==table.end())
        {
            table.insert(pair<char,int>(x,1));
        }
        else
        {
            map<char,int>::iterator itr;
            itr = table.find(x);
            if (itr != table.end())
                //int val = itr->second;
                //val = val + 1;
                itr -> second = itr->second + 1;

        }
        
    }
    map<char,int>::iterator itr;
    cout<<"Occurance of each character in a string"<<"\n";
    for( itr = table.begin(); itr != table.end(); ++itr){
        if(itr->first != ' ')
        {
            cout << "character => " << itr->first << ", frequency => " << itr->second << endl;      
        }
      }
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    int i = 0,j=s.length()-1;
    while(i<j)
    {
        char temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    cout<<"reversed string"<<"\n"<<s;
    int t = 0,y=s.length()-1;
    while(t<y)
    {
        char temp;
        temp = s[t];
        s[t] = s[y];
        s[y] = temp;
        t++;
        y--;
    }
    bool flag = true;
    int a = 0,b=s.length()-1;
    while(a<b)
    {
        if(s[a] != s[b])
        {
            flag = false;
            //cout<<"\n false";
            break;
        }
        a++;
        b--;
    }

    if (flag == true)
        cout<<"\ngiven sring is a paindrome";
    else
    {
        cout<<"\ngiven string is not palindrome";
    }
    size_t index;
    string sub;
    cout<<"\nEnter the substring to be searched";
    cin>>sub;
    index = s.find(sub);
    if(index != string::npos)
    {
        cout<<"\nFirst occurance of subsring is at  "<<index;
    }
    else
    {
        cout<<"\n substring is not present";
    }
    
    return 0;
}