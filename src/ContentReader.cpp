#include "ContentReader.h"

vector<uint8_t> read_contents(string& file_path)
{
    ifstream f(file_path, ios::in | ios::binary);
    vector<uint8_t> vec((istreambuf_iterator<char>(f)),
                        istreambuf_iterator<char>());

    return vec;
}

vector<string> find_duplicates(string& file_path, vector<string>& files)
{
    vector<string> duplicates;
    vector<uint8_t> original_file_contents = read_contents(file_path);

    vector<uint8_t> contents;

    for (auto path : files)
    {
        contents = read_contents(path);
        if (contents == original_file_contents)
        {
            duplicates.push_back(path);
        }
    }

    return duplicates;

    //for (auto i: original_file_contents)
    //{
        //int value = i;
        //cout << "data: " << value << endl;
    //}
}
