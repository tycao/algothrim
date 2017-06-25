#include <iostream>
#include <string>
using namespace std;

#include "link_queue_node.h"


struct dancer
{
    string name;
    char sex = ' ';
};

int main()
{
    cout << "请输入舞者总数：" << endl;
    int num;
    cin >> num;
    LinkQueue<dancer> Mdancer;
    LinkQueue<dancer> Fdancer;
    for (int i = 0; i != num; ++i)
    {
        char sex;
        string name;
        cout << "请输入舞者性别（f or m）: " << endl;
        cin >> sex;
        cout << "请输入舞者姓名：" << endl;
        cin >> name;
        dancer newdancer;
        newdancer.name = name;
        newdancer.sex = sex;
        if ('f' == sex)
            Fdancer.EnQueue(newdancer);
        else if ('m' == sex)
            Mdancer.EnQueue(newdancer);
    }

    while (!Mdancer.IsEmpty() && !Fdancer.IsEmpty())
        cout << Mdancer.DelQueue().name << "\t------------->\t" << Fdancer.DelQueue().name << endl;
    if (!Mdancer.IsEmpty())
        cout << "Mr. " << Mdancer.GetFront().name << "is watiting..." << endl;
    else if (!Fdancer.IsEmpty())
        cout << "Miss. " << Fdancer.GetFront().name << "is waiting..." << endl;
    else
        cout << "男女舞伴匹配完美！" << endl;

    return 0;
}
