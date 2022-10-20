#include <iostream>
#include <fstream>
#include <experimental/filesystem>

using namespace std;

vector<uint8_t> read_contents(string& file_path);
vector<string> find_duplicates(string& file_path, vector<string>& files);
