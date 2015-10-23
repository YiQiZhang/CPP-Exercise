// 动态连通性问题
// 加权union-find算法无法复原路径

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istringstream;
using std::string;

class unionFind
{
private:
	vector<int> tree;		// 储存全部树
	vector<int> sz;			// 记录树的节点数
	int countNum;				// 连接数量

	// 找到根节点
	int find(int p)
	{
		while(p != tree[p])
			p = tree[p];

		return p;
	}
public:
	unionFind(size_t size)
	{
		countNum = size;
		for(size_t i = 0; i < size; ++i) {
			tree.push_back(i);
			sz.push_back(1);
		}
	}

	// 返回连接数
	int count()
	{
		return countNum;
	}

	// 测试两个点是否联通
	bool connected(int a, int b)
	{
		return find(a) == find(b);
	}

	// 联通两个点
	void unionTwoPoint(int a, int b)
	{
		int aRoot = find(a);
		int bRoot = find(b);

		if (sz[aRoot] < sz[bRoot]) {
			tree[aRoot] = bRoot;
			sz[bRoot] += sz[aRoot];
		} else {
			tree[bRoot] = aRoot;
			sz[aRoot] += sz[bRoot];
		}

		--countNum;
	}
};

int main(int argc, char **argv)
{
	string line;
	int mapSize;
	cin >> mapSize;
	unionFind uf(mapSize);

	while(getline(cin, line)) {
		if (line == "q") {
			break;
		}
		istringstream in(line);
		int a, b;
		in >> a >> b;
		if (uf.connected(a, b)) {
			continue;
		} else {
			uf.unionTwoPoint(a, b);
			cout << a << " " << b << endl;
		}
	}
	cout << uf.count() << " components" << endl;

	return 0;
}