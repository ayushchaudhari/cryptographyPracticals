#include <bits/stdc++.h>

using namespace std;

//<-------------------------------function_1 ()-------------------------------->//
string generate_key(string text,string keyword){
    string key;
    
    int text_len=text.length();
    int keyword_len=keyword.length();
    for(size_t i=0;i<text_len;i++){
        key.push_back(keyword[i%(keyword_len)]);
    }
    
    return key;
}



//<-------------------------------function_2 ()-------------------------------->//
string vigenere_cipher(string text,string key){
    string encrypted_text;
    
    for(size_t i=0;i<text.size();i++){
        int asc_text_char=text[i]-97;
        int asc_key_char=key[i]-97;
        
        char char_of_encrypted_text=(char)((int)((asc_text_char+asc_key_char)%26)+97);
 
        encrypted_text.push_back(char_of_encrypted_text);
    }
    
    return encrypted_text;
}


//<-------------------------------MAIN FUNCTION ()-------------------------------->//
int main()
{
    // taking inputs
    string text;
    getline(cin,text);  //text to encrpyt
    string keyword;
    getline(cin,keyword); //keyword given
    
    
    // Generating key from keyword
    string key=generate_key(text,keyword);

    string encrpyted_text=vigenere_cipher(text,key);//text_len or key_len can also be passed
    cout<<"---------------------------Vigenere Cipher---------------------------\n";
    cout<<"Text - '"<<text<<"'\n'";
    cout<<"Keyword - '"<<keyword<<"'\n'";
    cout<<"Encrypted Vigenere Cipher Message is - '"<<encrpyted_text<<"'\n";
    cout<<"---------------------------------------------------------------------";
    
    return 0;
}