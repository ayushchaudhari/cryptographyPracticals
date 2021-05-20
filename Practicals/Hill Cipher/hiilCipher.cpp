#include<bits/stdc++.h>

using namespace std;

//<-----------------------FUNCTION_1 ()------------------------>//

//this function takes input of the given key matrix
vector<vector<int>> getKeyMatrix(){
    vector<vector<int>> key_matrix;
    for(auto i=0;i<3;i++){
        string keyline;
        getline(cin,keyline);
        
        vector<int> keyline_integer;
        
        for(auto j=0;j<keyline.size();j++){
            string element;
            while(keyline[j]!=' ' && j!=keyline.size()){
                element.push_back(keyline[j]);
                j++;
            }
            keyline_integer.push_back(stoi(element));   
        }
        key_matrix.push_back(keyline_integer);
    }
    return key_matrix;
}



//<------------------------FUNCTION_2 ()----------------------->//

vector<vector<int>> msg_format_and_convertInInt(string message,size_t col_key_mat){
    remove(message.begin(), message.end(), ' ');
    size_t row_msg_mat=col_key_mat;
    size_t col_msg_mat=message.size()/row_msg_mat; 
    size_t len=0;
    
    vector<vector<int>> converted_msg_matrix(row_msg_mat,vector<int>(col_msg_mat,0));
    
    while(len<message.size()){
        for(size_t col=0;col<col_msg_mat;col++){
            vector<int> row_elements;
            for(size_t row=0;row<row_msg_mat;row++){
                converted_msg_matrix[row][col]=(((int)message[len++])-65);
            }
        }
        len++;
    }
    
    return converted_msg_matrix;
}



//<-----------------------FUNCTION_3 ()------------------------>//

//this function multiplies key and msg matrix and mod every element by 26 and we get the hill_cipher_matrix
vector<vector<int>> hill_cipher_encrypter(vector<vector<int>> key_matrix,vector<vector<int>> converted_msg_matrix){
    vector<vector<int>> hill_cipher_matrix(key_matrix.size(),vector<int> (converted_msg_matrix[0].size(),0));
    
    for(size_t row=0;row<key_matrix.size();row++){
        for(size_t col=0;col<converted_msg_matrix[row].size();col++){
            for(size_t itr=0;itr<key_matrix.size();itr++){
                hill_cipher_matrix[row][col]+=key_matrix[row][itr]*converted_msg_matrix[itr][col];
            }
            hill_cipher_matrix[row][col]%=26;
        }
    }
     
    return hill_cipher_matrix; 
}


//<------------------------FUNCTION_3 ()----------------------->//

// this function transform the hill_cipher_matrix to hill_cipher_message
string tranform_mat_2_msg(vector<vector<int>> hill_cipher_matrix){
    string hill_cipher_message;
    for(size_t col=0;col<hill_cipher_matrix[0].size();col++){
        for(size_t row=0;row<hill_cipher_matrix.size();row++){
            hill_cipher_message.push_back((char)(hill_cipher_matrix[row][col]+65));
        }
    }
    
    return hill_cipher_message;
}


//<-----------------------MAIN FUNCTION ()------------------------>//

int main(){
    //getKeyMatrix is the function to input the given key matrix
    vector<vector<int>> key_matrix=getKeyMatrix();
    cout<<"-----------------------------Hill Cipher------------------------------\n";
    // displaying the key matrix given as input
    cout<<"Displaying the Key Matrix -\n";
    for(size_t i=0;i<key_matrix.size();i++){
        for(size_t j=0;j<key_matrix[i].size();j++)
            cout<<key_matrix[i][j]<<"\t";
        cout<<"\n";
    }
    // message to given to convert to hill cipher
    string message;
    getline(cin,message);
    cout<<"Message to be Encrypted - "<<message<<endl;
    
    vector<vector<int>> converted_msg_matrix=msg_format_and_convertInInt(message,key_matrix[0].size());
    cout<<"After formating the given message and converting the alphabets in required number format and transforming all this in message matrix we get-\n";
    for(size_t i=0;i<converted_msg_matrix.size();i++){
        for(size_t j=0;j<converted_msg_matrix[i].size();j++)
            cout<<converted_msg_matrix[i][j]<<"\t";
        cout<<"\n";
    }
    
    // from here just there is code to encrypt the message in hill cipher using the key
    vector<vector<int>> hill_cipher_matrix=hill_cipher_encrypter(key_matrix,converted_msg_matrix);
    cout<<"Now the encrypted HILL CIPHER matrix is-\n";
    for(size_t i=0;i<hill_cipher_matrix.size();i++){
        for(size_t j=0;j<hill_cipher_matrix[i].size();j++)
            cout<<hill_cipher_matrix[i][j]<<"\t";
        cout<<"\n";
    }
    
    //tranforming the hill_cipher_matrix to an encrypted hill_cipher_message
    string hill_cipher_message=tranform_mat_2_msg(hill_cipher_matrix);
    cout<<"\nSo the encrypted HILL CIPHER message extracted by encrypted HILL CIPHER matrix is-"<<hill_cipher_message;
    cout<<"\n------------------------------------------------------------------------";
    
    return 0;
}
