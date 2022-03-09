#include<iostream>
#include<map>
using namespace std;
#include<vector>


/*
实现 MyHashMap 类：

MyHashMap() 用空映射初始化对象
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。

*/
class MyHashMap {
private:
    const int max = 97;
    vector<vector<pair<int, int>>>mhp;
public:
    MyHashMap() {
        mhp.resize(max);
    }

    void put(int key, int value) {
        for (auto it = mhp[key % max].begin();it!=mhp[key % max].end();it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        mhp[key % max].push_back(make_pair(key, value));
    }

    int get(int key) {
        for (auto it = mhp[key % max].begin();it != mhp[key % max].end();it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
      
    }

    void remove(int key) {
        for (auto it = mhp[key % max].begin();it != mhp[key % max].end();it++) {
            if (it->first == key) {
                mhp[key % max].erase(it);
                return;
            }
        }
    }
};


int main() {

    MyHashMap m;
    m.put(1, 1);
    m.put(2, 2);
    cout << m.get(1) << endl;
    cout << m.get(3) << endl;
    m.put(2, 1);
    cout << m.get(2) << endl;
    m.remove(2);
    m.get(2);
    system("pause");
}