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
    
    with open('.gitignore', 'a+') as f:
        f.write('\n' +  os.path.join(dir_path,filename) + '\n')

    pass


if __name__ == '__main__':
    assert len(sys.argv) == 2
    project_name = str(sys.argv[1]).strip()
    main(project_name)
