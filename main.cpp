#include <iostream>
#include <fstream>
#include <FilesFinder.h>
#include <ContentReader.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    string file_path;
    string directory_path;

    int sw = 0;
    cout << endl << "If you want to use default pathes press '0'" << endl;
    cin >> sw;
    if (sw == 0)
    {
        file_path = "/home/nick/test_1/1/name";
        directory_path = "/home/nick/test_1/2";
    }
    else
    {
        do
        {
            cout << endl << "Enter file path:" << endl;
            cin >> file_path;
        }
        while ((!fs::exists(file_path)) || (fs::is_directory(file_path)));

        do
        {
            cout << endl << "Enter directory path:" << endl;
            cin >> directory_path;
        }
        while ((!fs::exists(directory_path)) || (!fs::is_directory(directory_path)));
    }

    int file_size = fs::file_size(file_path);
    vector<string> files;

    get_files(files, file_size, directory_path);

    vector<string> duplicates = find_duplicates(file_path, files);


    if (duplicates.size() > 0)
    {
        cout << endl <<"Duplicate pathes: " << endl;
        for (int i = 0; i < duplicates.size(); i++) cout << endl << duplicates[i] << endl;
    } else
    {
        cout << "There are no duplicates in this directory";
    }

    return 0;
}
