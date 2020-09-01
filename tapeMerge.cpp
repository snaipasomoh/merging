#include <iostream>
#include <vector>
#include <iterator>

void tapeMerge (std::vector<int> const &a, std::vector<int> const &b,
	            std::vector<int> &c){
	c.clear();
	if (a.empty()){
		c = b;
		return;
	}
	else if (b.empty()){
		c = a;
		return;
	}
	
	for (auto i = a.begin(); i != a.end();){
		for (auto j = b.begin(); j != b.end();){
			c.push_back(*i < *j ? *(i++) : *(j++));
			i == a.end() ? c.insert(c.end(), j, b.end()), j = b.end(), 0 : 0;
			j == b.end() ? c.insert(c.end(), i, a.end()), i = a.end(), 0 : 0;
		}
	}

}

int main (int argc, char **argv){
	std::vector<int> a = {1, 3, 5, 7, 9, 11, 13, 17};
	std::vector<int> b = {};
	std::vector<int> c;
	tapeMerge(a, b, c);
	
	for (auto i : c){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}