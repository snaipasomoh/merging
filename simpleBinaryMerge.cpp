#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<int>::const_iterator binarySearch(
	                                        std::vector<int>::const_iterator l,
	                                        std::vector<int>::const_iterator r,
	                                        int x){
	while (l <= r){
		auto m = l + (r - l) / 2;
		if (*m < x){
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	return l;
}

void SBMerge (std::vector<int> const &a, std::vector<int> const &b,
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
	auto ab = a.begin();
	auto ae = a.end();
	auto bb = b.begin();
	auto be = b.end();
	
	while (ae - ab){
		if(ae - ab > be - bb){
			std::swap(ae, be);
			std::swap(ab, bb);
		}
		auto p = binarySearch(bb, be, *(ae - 1));
		c.insert(c.end(), std::make_reverse_iterator(be),
		                  std::make_reverse_iterator(p));
		c.push_back(*(ae - 1));
		ae--;
		be = p;
	}
	c.insert(c.end(), std::make_reverse_iterator(be),
		              std::make_reverse_iterator(bb));
	std::reverse(c.begin(), c.end());
}

int main (int argc, char **argv){
	std::vector<int> a = {1, 3, 5, 7, 7, 7, 7, 9, 11, 13, 17};
	std::vector<int> b = {2, 4, 6, 6, 6, 7, 7, 8, 9};
	std::vector<int> c;
	SBMerge(a, b, c);
	
	for (auto i : c){
		std::cout << i << " ";
	}
	std::cout << std::endl;


}