#!/usr/bin/python  coding:utf8

import sys
from datetime import datetime
import re
import os


HEADER_TEMPLATE = """\
// author: yqq
// date: {}
// descriptions:
"""


CPP_TEMPLATE = """\
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
using namespace std;





int main()
{
    cout << "hello world" << endl;
    return 0;
}

"""


GOLANG_TEMPLATE = """\
package main
import "fmt"




func main() {
    fmt.Println("hello world")
}

"""


RUST_TEMPLATE = """



fn main(){
    println!("hello world")
}

"""


MAKEFILE_TEMPLATE = """include ../../Comman.mk"""


def check_projectname(project_name):
    """
    项目名必须符合格式: [0-9]{4}_.*
    """
    ret = re.findall('[0-9]{4}_.*', project_name)
    try:
        assert len(ret) == 1
        assert ret[0] == project_name
    except Exception as e:
        raise Exception("项目目录名称非法, 必须符合 [0-9]{4}_.*")
    pass


def main(project_name):
    check_projectname(project_name)

    dir_path = os.path.join('./src/', project_name)
    os.mkdir(dir_path)

    filename = project_name[project_name.find('_')+1:]
    filename = filename.strip()
    # print(filename)

    infos = {
        ".cc": CPP_TEMPLATE,
        ".go": GOLANG_TEMPLATE,
        ".rs": RUST_TEMPLATE,
        "Makefile": MAKEFILE_TEMPLATE
    }

    for suffix, template in infos.items():
        if suffix == 'Makefile':
            filepath = os.path.join(dir_path, "Makefile")
            code = MAKEFILE_TEMPLATE
        else:
            filepath = os.path.join(dir_path, filename+suffix)
            code = HEADER_TEMPLATE.format(
                datetime.now().strftime('%Y-%m-%d %H:%M:%S'))
            code += template
        f = open(filepath, 'w')
        f.write(code)
        f.close()

    # 忽略可执行文件(包括调试)
    with open('.gitignore', 'a+') as f:
        f.write(os.path.join(os.path.join('src/', project_name), filename )+ '\n')

    pass


if __name__ == '__main__':
    assert len(sys.argv) == 2
    project_name = str(sys.argv[1]).strip()
    # 将所有 '-' 换乘下划线
    project_name = project_name.replace('-', '_')
    main(project_name)
