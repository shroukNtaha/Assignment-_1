#include <iostream>

using namespace std;
string* addEntry( string *dynamicArray, int &size, string newEntry);
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);
int main()
{
    int n=5,choise;
    string x,y;
    string* Array = new string[5];
    for(int i=0;i<5;i++)
    {
        cin>>Array[i];
    }
     while(true)
    {
        cout<<"1.Add"<<"   "<<"2.Delete"<<"   "<<"3.Exit"<<endl;
        cout<<"choise : ";
        cin>>choise;
        if(choise==1)
        {
            cin>>x;
            Array= addEntry( Array, n , x );
            for(int i=0;i<n;i++)
            {
                cout<<Array[i]<<" ";
            }
            cout<<endl;
            delete Array;
        }
        else if(choise==2)
        {
            cin>>y;
            Array=deleteEntry(Array,n,y);
            for(int i=0;i<n;i++)
            {
                cout<<Array[i]<<" ";
            }
            cout<<endl;
            delete Array;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
string* addEntry( string *dynamicArray, int &size, string newEntry)
{
    string* newArray= new string[size+1];
    for(int i=0;i<size;i++)
    {
        newArray[i]=dynamicArray[i];
    }
    newArray[size]=newEntry;
    size++;
    return newArray;
}
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete)
{
    int sum=0,j=0;
    for(int i=0;i<size;i++)
    {
        if(dynamicArray[i]==entryToDelete)
        {
            sum++;
        }
    }
    string* newArray = new string[size-sum];
    for(int i=0;i<size;i++)
    {
        if(dynamicArray[i]!=entryToDelete)
        {
            newArray[j]=dynamicArray[i];
            j++;
        }
    }
    size-=sum;
    return newArray;
}
