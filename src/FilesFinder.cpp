#include "FilesFinder.h"

void get_files(vector<string>& files, int& file_size, const string& directory_path){

    for (const auto& file : fs::directory_iterator(directory_path)){
        if (fs::is_directory(file)){
            get_files(files, file_size, file.path().string());
        }
        else{
            if ((fs::is_regular_file(file.path().string())) && fs::file_size(file.path().string()) == file_size)
            {
                files.push_back(file.path().string());
            }
        }
    }
}
