// String operations
#include<iostream> 
using namespace std; 
class Stringoperations
{
    string str ;
    int len=0;
    public :
    Stringoperations(string n="")
    {
        str = n;
        setlength();
    }
    void setlength()
    {
        for(int i = 0 ;str[i]!='\0';i++)
        {
            len++;
        }
    }

    // displaying the string
    void displaystr()
    {
        cout<<"String : "<<str<<endl;
    }
    // returns the length of the string 
    int  getlength()
    {
        return len;
    }

    // Change the string to upper case
    void change_upper()
    {
        for(int i = 0 ;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                str[i]-=32;
            }
        }
        cout<<"Changed to upper => ";
        displaystr();
    }

    // Changes string to lower case
    void change_lower()
    {
        for(int i = 0 ;i<len;i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]+=32;
            }
        }
        cout<<"Changed to lower => ";
        displaystr();
    }

    // this function toogle the letter in the string
    void toogling()
    {
        for(int i = 0 ;i<len;i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]+=32;
            }
            else if(str[i]>='a'&&str[i]<='z')
            {
                str[i]-=32;
            }
        }
        cout<<"Toogled letter => ";
        displaystr();
    }

    // Thid function tells the count of vowel and consonents 
    void count_vow_conso()
    {
        int vcount=0 , ccount = 0 , special = 0 ;
        for(int i = 0 ;i<len;i++)
        {
            if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='i'||str[i]=='I'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U')
            {
                vcount++;
            }
            else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
            {
                ccount++;
            }
            else
            {
                special++;
            }
        }
        cout<<"Vowel count : "<<vcount<<endl;
        cout<<"Consonent count : "<<ccount<<endl;
        cout<<"Special count : "<<special<<endl;
    }

    // validating the string to avoid the user to enter the invalid details
    void checkvalid()
    {
        int i ;
        for(i = 0 ; i <len ;i++)
        {
            // only alphanumeric characters
            if(!((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')))
            {
                cout<<"Invalid string !.."<<endl;
                break;
            }
        }
        if(i==len)
        {
            cout<<"Valid string...."<<endl;
        }
    }

    // tells number of words in the string 
    void no_of_words()
    {
        int count = 1 ;
        for(int i =  0 ;i<len ;i++)
        {
            if(str[i]==' '&&str[i-1]!=' ')
            {
                count++;
            }
        }
        cout<<"There are "<<count<<" number of words in the string"<<endl;
    }

    // Reverse the string 
    void reversestr()
    {
        for(int i = 0 ;i<len/2; i++)
        {
            char tem= str[i];
            str[i]=str[len-1-i];
            str[len-1-i]=tem;
        }
        cout<<"String is reversed => ";
        displaystr();
    }

    // checks wheather the string is palindrome or not 
    void checkpalindrome()
    {
        int i ;
        for(i = 0 ;i<len/2; i++)
        {
            if(str[i]!=str[len-1-i])
            {
                cout<<"String is not palindrome ..."<<endl;
                break;
            }
        }
        if(i==len)
        {
            cout<<"The string is palindrome"<<endl;
        }
    }
    
    // Finding duplicates in a string
    void find_duplicate()
    {
        long int x = 0 , h = 0 ;
        change_lower();
        // this condition is written is only for lower case
        for(int i = 0 ;i<len;i++)
        {
            x=1;
            x=x<<(str[i]-'a');
            if((x&h)>0)
            {
                cout<<str[i]<<" has a duplicate"<<endl;
            }
            else 
            {
                h=(h|x);
            }
        }
    }

};
int main() 
{ 
    Stringoperations s("DyT?_mINi2003");
    cout<<s.getlength()<<endl;
    s.displaystr();
    s.toogling();
    s.change_upper();
    s.change_lower();
    s.count_vow_conso();
    s.checkvalid();
    s.no_of_words();
    s.reversestr();
    s.checkpalindrome();
    s.find_duplicate();
  
    return 0 ;
}