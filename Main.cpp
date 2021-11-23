//считывает текст из файла и выводит на экран 
//сначала вопросительные, а затем восклицательные предложения

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

void outputSentences(const string& text, int len) {
    string S;
    stringstream stream;
    int beg = 0;

    for (int i = 0; i < len; i++) {
        
        if (text[i] == '?') {
            while (text[beg] == ' ') beg++;
            stream << text.substr(beg, i + 1 - beg) << '\n';
            beg = i + 1;
        }

        else if (text[i] == '!') {
            while (text[beg] == ' ') beg++;
            S += text.substr(beg, i + 1 - beg) + '\n';
            beg = i + 1;
        }

        else if (text[i] == '.' || text[i] == '\n') {
            beg = i + 1;
        }
    }

    stream << S;
    cout << stream.str() << endl;
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    ifstream in("1.txt");

    try {
        if (!in.is_open()) {
            throw "\nFile open error";
        }
    }
    catch (const char* exc) {
        cout << exc << endl;
        return 1;
    }
    
    string text, tmp;
    while (getline(in, tmp)) {
        text += tmp + "\n";
    }
    int len = text.size();

    outputSentences(text, len);
    
    in.close();
    return 0;
}