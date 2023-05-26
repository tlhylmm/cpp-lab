#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<algorithm> //for converting to lowercase 
using namespace std;

int main(){
    queue<char> qStr;
    stack<char> sStr;
    string str;
    cout << "Bir ifade giriniz" << endl;
    getline(cin, str);
    //convert all to lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    //eliminate punctuation, spaces and fill the queue and stack
    int i = 0;
    while(i < str.size()){
        if(str[i] != '.' && str[i] != ',' && str[i] != ';' && str[i] != '"' &&
           str[i] != ':' && str[i] != ' ' && str[i] != '\''){
            qStr.push(str[i]);
            sStr.push(str[i]);
        }
        i++;
    }

    //check if it is a palindrome
    bool isPalindrome = true;
    while(!qStr.empty() && !sStr.empty()){
        if(qStr.front() != sStr.top()){
            isPalindrome = false;
            break;
        }
        qStr.pop();
        sStr.pop();
    }

    if(isPalindrome) cout << "Girdiginiz ifade bir palindromdur." << endl;
    else cout << "Girdiginiz ifade bir palindrom degildir." << endl;
 
    return 0;
}