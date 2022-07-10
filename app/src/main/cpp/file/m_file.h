//
// Created by 程磊 on 2022/7/10.
//

#ifndef CPP_M_FILE_H
#define CPP_M_FILE_H

#endif //CPP_M_FILE_H

#include "base.h"
#include <string>


class MFileOperator {
public:
    void operatorFile();

    MFileOperator() {
        LOGE("构造MFileOperator");
    }

    ~MFileOperator() {
        LOGE("销毁MFileOperator");
    }

    static
    string FILE_NAME;

    static
    void initMinePath(string path);


private:
    void createFile();

    void writeFile();

    void readFile();

};

