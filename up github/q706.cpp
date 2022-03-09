#include<iostream>
#include<map>
using namespace std;
#include<vector>


/*
ʵ�� MyHashMap �ࣺ

MyHashMap() �ÿ�ӳ���ʼ������
void put(int key, int value) �� HashMap ����һ����ֵ�� (key, value) ����� key �Ѿ�������ӳ���У���������Ӧ��ֵ value ��
int get(int key) �����ض��� key ��ӳ��� value �����ӳ���в����� key ��ӳ�䣬���� -1 ��
void remove(key) ���ӳ���д��� key ��ӳ�䣬���Ƴ� key ��������Ӧ�� value ��

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