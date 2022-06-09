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

void takeStep(string dir, string color, int r, int c, vector< vector<string> > board, int it){
   
   it = it - 1;
   if(color == "1"){
        board[r][c] = "0";
    }else{
        board[r][c] = "1";
    }
   
    if(color == "1"){ 
        // black color
        // get the direction it is facing... 
        // must turn 90 degrees to left... 
        // move one unit forward...
        if(dir == "E"){
            dir = "N";
            r -= 1;

        }else if(dir == "W"){
            dir = "S";
            r += 1;

        }else if(dir == "S"){
            dir = "E";
            c += 1;

        }else{
            // dir must be N...
            dir = "W";
            c -= 1;
        }

    }else{
        // white color...
        // must turn 90 degrees to right...
        if(dir == "E"){
            dir = "S";
             r += 1;

        }else if(dir == "W"){
            dir = "N";
            r -= 1;

        }else if(dir == "S"){
            dir = "W";
             c -= 1;

        }else{
            // dir must be N...
            dir = "E";
             c += 1;
        }
    }

    cout << "\n" << endl;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j];
        }
        if(i < board.size() - 1){
             cout << "" << endl;
        }
    }

    string newColor = board[r][c];

    if(it > 0){
        takeStep(dir, newColor, r, c, board, it);
    }
    

}

int main(){

    string iterations;
    getline(cin, iterations);

    string boardIn;
    getline(cin, boardIn);

    vector< vector<string> > board;
    vector<string> gridSize = split(boardIn);

    int r = stoi(gridSize[0]);
    int c = stoi(gridSize[1]);


    string input;
    getline(cin, input);

    vector<string> data = split(input);

    int m = stoi(data[0]); // r
    int n = stoi(data[1]); // c
    string d = "N";

    for(int i = 0 ; i < r; i++){
        vector<string> temp;
        for(int j = 0; j < c; j++){
            temp.push_back("0");
        }
        board.push_back(temp);
    }

    // print board initially empty...
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j];
        }
        if(i < board.size() - 1){
             cout << "" << endl;
        }
    }

    string color = board[m][n];
    
    takeStep(d, color, m, n, board, stoi(iterations));
    
    return 0;
}

  