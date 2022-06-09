#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Ant{
    public:
        int r;
        int c;
        string direction;
    Ant(int r, int c){
        this-> r = r;
        this-> c = c;
        this->direction = "N";
    }

    void updateR(int r){
        this-> r = r;
    }

    void updateC(int c){
        this-> c = c;
    }

    void updateDirection(string dir){
        this-> direction = dir;
    }
};

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

void takeStep(vector<Ant> ants ,vector< vector<string> > board, int it){
   
    it = it - 1; // decrementing the iteration value to avoid infinite loop...
    vector<Ant> nextAnts; // list of ants will send to the next iteration...

    // move every ant on the ants vector...
    for(int ant = 0; ant < ants.size(); ant++){

        Ant currAnt = ants[ant]; 

        int r = currAnt.r;
        int c = currAnt.c;

        string color = board[r][c];

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
        if(currAnt.direction == "E"){
            currAnt.updateDirection("N");
            currAnt.updateR(currAnt.r - 1);
            if(currAnt.r < 0){
                currAnt.updateR(board.size()-1);
            }

        }else if(currAnt.direction == "W"){
            currAnt.updateDirection("S");
            currAnt.updateR(currAnt.r + 1);
             if(currAnt.r >= board.size()){
                currAnt.updateR(0);
             }

        }else if(currAnt.direction == "S"){
            currAnt.updateDirection("E");
            currAnt.updateC(currAnt.c + 1);
            if(currAnt.c >= board[0].size()){
                currAnt.updateC(0);
            }

        }else{
            // dir must be N...
            currAnt.updateDirection("W");
            currAnt.updateC(currAnt.c - 1);
            if(currAnt.c < 0){
                currAnt.updateC(board[0].size() - 1);
            }
        }

    }else{
        // white color...
        // must turn 90 degrees to right...
        if(currAnt.direction == "E"){
            currAnt.updateDirection("S");
             currAnt.updateR(currAnt.r + 1);
             if(currAnt.r >= board.size()){
                currAnt.updateR(0);
             }

        }else if(currAnt.direction == "W"){
            currAnt.updateDirection("N");
            currAnt.updateR(currAnt.r - 1);
            if(currAnt.r < 0){
                currAnt.updateR(board.size()-1);
            }

        }else if(currAnt.direction == "S"){
            currAnt.updateDirection("W");
            currAnt.updateC(currAnt.c - 1);
            if(currAnt.c < 0){
                currAnt.updateC(board[0].size() - 1);
            }

        }else{
            // dir must be N...
            currAnt.updateDirection("E");
            currAnt.updateC(currAnt.c + 1);
            if(currAnt.c >= board[0].size()){
                currAnt.updateC(0);
            }
        }
    }

        nextAnts.push_back(currAnt);
    }

    // Printing the grid after every iteration...
    cout << "\n" << endl;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j];
        }
        if(i < board.size() - 1){
             cout << "" << endl;
        }
    }

    // Taking another step if the number of iterations is still greater than 0...
    if(it > 0){
        takeStep(nextAnts, board, it);
    }

}

int main(){
    // store all the ants in the vector...
    vector<Ant> ants;

    // Number of iterations and number of ants...
    string it;
    std::getline(cin, it);
    vector<string> it_ants = split(it);
    int T = stoi(it_ants[0]); 
    int A = stoi(it_ants[1]);

    // grid/board size input
    string boardIn;
    std::getline(cin, boardIn);
    vector< vector<string> > board;
    vector<string> gridSize = split(boardIn);
    int r = stoi(gridSize[0]);
    int c = stoi(gridSize[1]);

    // ants position
    for(int i = 0; i < A; i++){
        string input;
        std::getline(cin, input);
        vector<string> data = split(input);
        int m = stoi(data[0]); // r
        int n = stoi(data[1]); // c

        Ant ant = Ant(m, n);
        ants.push_back(ant);
    }
    
   
    // init board with zeros...
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

    takeStep(ants, board, T);

    return 0;
}

  