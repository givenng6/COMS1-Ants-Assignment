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

vector<string> takeStep(string dir, string color, int r, int c){
    vector<string> output;

    if(color == "1"){ // black color
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

    if(color == "1"){
        color = "0";
    }else{
        color = "1";
    }

    output.push_back(color);
    output.push_back(to_string(r));
    output.push_back(to_string(c));
    output.push_back(dir);

    return output;
}

int main(){

    string color;
    getline(cin, color);

    string input;
    getline(cin, input);

    vector<string> data = split(input);
    int m = stoi(data[0]); // r
    int n = stoi(data[1]); // c
    string d = data[2];
    
    vector<string> output = takeStep(d, color, m, n);
    cout << output[0] << endl;
    cout << output[1];
    cout << " ";
    cout << output[2];
     cout << " ";
    cout << output[3];

    return 0;
}

  