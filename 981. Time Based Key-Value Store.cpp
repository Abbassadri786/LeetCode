class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string, int> temp = {value, timestamp};
        mp[key].push_back(temp);
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end() ||  timestamp < mp[key].front().second){
            return "";
        }
        const auto& vec = mp[key];
        int l = 0, h = vec.size() - 1;

        while(l<=h){
            int mid = (l+h)/2;
            if(vec[mid].second > timestamp){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return vec[h].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
