#include <iostream>
#include<string>
#include<map>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;


void FileRead(multimap<string, int> &mp)
{
    cout << "Имя файла: ";
    int count = 0;
    string name; cin >> name;
    ifstream File; File.open(name);
    if (File.is_open())
    {
        string line;
        while (getline(File, line))
        {
            istringstream iss(line);//разделение слов 
            while (iss >> line)
            {
                auto it = mp.find(line);// если не найдено, возвращает end()
                if (it != mp.end()) 
                {
                    it->second++;
                }
                else 
                {
                    mp.insert(make_pair(line,1)); // если не найдено,создаем
                }
            }
        }

    }
    else
        cout << "Error!" << endl;
        File.close();
}

void print(multimap<string, int> &mp)
{
    // Вывод
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->second << " - " << it->first << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    multimap<string, int> mp;
    FileRead(mp);
    print(mp);

    return 0;
                
}

