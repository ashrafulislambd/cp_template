template<typename T>
vector<pair<T,int>> group(vector<T> v) {
	T prev;
	bool isPrev = false;
	vector<pair<T, int>> toRet;

	int cnt = 0;

	for(T item : v) {
		if(isPrev && prev != item) {
			toRet.push_back({prev, cnt});
			cnt = 1;
		} else {
			cnt++;
		}
		prev = item;
		isPrev = true;
	}
	toRet.push_back({prev, cnt});
	return toRet;
}

vector<pair<char,int>> group(string v) {
	return group(vector<char>(v.begin(), v.end()));
}