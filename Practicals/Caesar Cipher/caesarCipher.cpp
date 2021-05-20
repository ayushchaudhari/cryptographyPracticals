#include <bits/stdc++.h>

using namespace std;

string caesar_cipher(string text, int shift){
        string encrpyted_text;
        for(size_t i=0;i<text.size();i++){
            if(text[i]>'A' && text[i]<'Z')
                encrpyted_text.push_back(((((int)text[i])-65+shift)%26)+65);
            else
                encrpyted_text.push_back(((((int)text[i])-97+shift)%26)+97);
        }
        return encrpyted_text;
}


int main()
{
    // taking inputs
    string text;
    getline(cin,text);  //text to encrpyt
    string shift_in;
    getline(cin,shift_in);
    int shift = stoi(shift_in);
    
    string encrpyted_text=caesar_cipher(text,shift);
    cout<<"-----------------------------Caesar Cipher------------------------------\n";
    cout<<"Text - '"<<text<<"'\n";
    cout<<"Shift - '"<<shift<<"'\n";
    cout<<"Encrypted Message - '"<<encrpyted_text<<"'\n";
    
    string decrypted_text=caesar_cipher(encrpyted_text,26-shift);
    cout<<"Decrypted Message - '"<<decrpyted_text<<"'\n";
    cout<<"------------------------------------------------------------------------";
    
    return 0;
}