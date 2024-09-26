#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;
string order;
int r, c;
void print (vector <vector<char>>);
void seatsOpen (vector <vector<char>>);
void pickseat (vector<vector<char>> &);
bool vaildRes(string);
void taken(vector<vector<char>> &,string, int, int);

int main()
{
    cout << "Enter how many rows you would like: ";
    cin >> r;
    cout << "Enter how many columns you would like : ";
    cin >> c;

    vector<vector<char>> seat(r, vector<char>(c, '0'));
    for (int i = 0; i < (r * c + 50); i++){
        print(seat);
        seatsOpen(seat);
        pickseat(seat);
    }
    cout << "\n\n\n\n\n\n";
    return 0;
}
void print (vector <vector<char>> seat){
    int i, j;
    cout << " " << setw(5);
    for (i = 0; i < c; i++)
        cout << char('A' + i) << setw(5);
    cout << "\n";
    for (i = 0; i < r; i++){
        cout << i + 1;
        for (j = 0; j < c; j++){
            cout <<  setw(5) << seat.at(i).at(j);
        }
        cout << endl;
    }
}
void seatsOpen (vector <vector<char>> seat){
    int i, j, ans;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (seat.at(i).at(j) == '0')
                ans++;
    cout << "0: Available   " << "X: Unavailable" << endl;
    cout << ans << " Seats are still available" << endl;
    cout << "Order assigned: " << order << endl;
}
void pickseat (vector <vector<char>> & seat){
    string s;
    bool f = false;
    int i, j;
    while (f == false){
    cout << "Pick your seat by entering the number followed by the letter : ";
    cin >> s;
    s[1] = toupper(s[1]); // Makes all of the letters capital
    f = vaildRes(s); // checks to see if the response is valid
    if (!f)
        cout << "\n\nInvaild response please try again!!!\n\n" << endl;
    }
    for (i = 0; i < r; i++)
        if (s[0] == char(49 + i))
            for(j = 0; j < c; j++)
                if (s[1] == char('A' + j))
                    taken(seat, s, i, j);


}
bool vaildRes(string s){
    bool ans = true;
    if (s.length() != 2)
        ans = false;
    if (int(s[1]) < 65 || int(s[1]) > 65 + c - 1) // This is checking the ascii value to see if the second letter is A - the number of rows
        ans = false;
    if (int(s[0]) < 49 || int(s[0]) > 49 + r - 1) // This is checking if its a number 1 - the number of columns
        ans = false;
    return ans;
}
void taken(vector<vector<char>> & seat,string s, int a , int b){
    if (seat.at(a).at(b) == 'X')
        cout << "\n\nThis seat is already taken!!!\n\n" << endl;
    else {
        order += s + ", ";
        seat.at(a).at(b) = 'X';
    }
}
