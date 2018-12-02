//
// Created by Shania Paul on 12/2/2018.
//

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main()
{
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    //for (unsigned int i = 0;i < files.size();i++) {
      //  cout << i << files[i] << endl;
    //}

    ifstream inFile;
    inFile.open(files[2]);
    if(inFile.is_open()){
        cout << "File Open" << endl;
    }

    string s;
    inFile >> s;

    cout << s << endl;

    return 0;
}


