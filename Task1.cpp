#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> split(string word){
    vector<string> list;

    string item = "";
    for(int i = 0; i < word.length(); i++){
        if(word[i] == ' '){
            list.push_back(item);
            item = "";
        }else{
            item += word[i];
        }
    }

    if(item != ""){
        list.push_back(item);
    }

    return list;
}

int main(){

    string input;
    getline(cin, input);
    vector<string> gridSize = split(input);
    vector< vector<string> > board;

    int r = stoi(gridSize[0]);
    int c = stoi(gridSize[1]);

    for(int i = 0 ; i < r; i++){
        string gridInput;
        getline(cin, gridInput);
        board.push_back(split(gridInput));
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << board[i][j];
        }
        if(i < r - 1){
             cout << "" << endl;
        }
    }

    return 0;
}

  