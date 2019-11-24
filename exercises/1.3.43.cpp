#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include "doublelinkedlist.h"
using namespace std::filesystem;
using namespace ythlearn;
using namespace std;


struct FileDes{
    FileDes():xfilename(""), xdepth(0){}
    FileDes(string xfilename, int xdepth): xfilename(xfilename), xdepth(xdepth){}
    string xfilename;
    int xdepth;
};

template<typename T>
void Foo(DLinkList<T>& dl, string path = "./", int depth = 0){
    for(const auto& p : directory_iterator(path)){
        if(p.path().filename().string()[0] == '.')
            continue;
        if(p.is_directory()){
            Foo(dl, p.path(), depth + 1);
        }else{
            FileDes item(p.path().string(), depth);
            dl.push_right(item);            
        }
    }
}

int main()
{
    DLinkList<FileDes> dl;    
    Foo(dl);
    while(!dl.isEmpty()){
        auto fuck = dl.pop_left();
        for(int i = 0; i < fuck.xdepth; i++){
            cout << "-----";
        }
        cout << fuck.xfilename << endl;
        
    }
}

