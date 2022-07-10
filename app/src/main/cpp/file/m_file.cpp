//
// Created by 程磊 on 2022/7/10.
//
#include <iostream>
#include <fstream>
#include "m_file.h"
using namespace std;

void MFileOperator::createFile(){
    ifstream ifile;
    LOGE("文件路径：%s", FILE_NAME.c_str());
    ifile.open(FILE_NAME);
    if (ifile){
        LOGE("存在该文件,跳过");
        return;
    } else{
        LOGE("文件不存在，创建");
    }
    ofstream file;
    file.open(FILE_NAME, ios::app);
    if (!file){
        LOGE("创建文件失败");
    } else {
        file.close();
    }
}


void MFileOperator::writeFile() {
    ofstream file(FILE_NAME);
    file << "hello" << "\n";
    file.flush();
    file.close();

}

void MFileOperator::readFile() {
    ifstream file;
    file.open(FILE_NAME, ios::in);
    if (!file){
        LOGE("文件读取失败");
    } else {
        string content;
        file >> content;
        LOGE("读取文件内容：%s", content.c_str());
        file.close();
    }
}

void MFileOperator::operatorFile() {
    createFile();
    writeFile();
    readFile();
}

void MFileOperator::initMinePath(string path) {
    FILE_NAME = path += "/demo.txt";
    LOGE("FILE_NAME初始化为%s", FILE_NAME.c_str());
}

string MFileOperator::FILE_NAME="";
