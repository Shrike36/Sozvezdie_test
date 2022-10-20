#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

void get_files(vector<string>& files, int& file_size, const string& directory_path);
