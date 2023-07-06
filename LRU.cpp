int capacity ;
    stack<pair<int,int> > lru;
    unordered_map<int, int> maps;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;   
    }
    
    //Function to return value corresponding to the key.
    void findValStack(int &key, int value = -1)
    {
        if(lru.empty())
        {
            return;
        }
        pair<int, int> top = lru.top();
        if(top.first == key)
        {
            // top.second = value;
            lru.pop();
            return;
        }
        lru.pop();
        findValStack(key, value);
        lru.push(top);
        
    }
    int GET(int &key)
    {
        if(maps.find(key) != maps.end())
        {
            //delete val
            findValStack(key);
            //push val
            lru.push({key, maps[key]});
            return maps[key];
        }
        else return -1;
    }
    
    int deleteBottom(int count = 0)
    {
        if(count == capacity - 1)
        {
            int bottomkey = lru.top().first;
            lru.pop();
            return bottomkey;
        }
        pair<int, int> top = lru.top();
        lru.pop();
        int btmkey = deleteBottom(count + 1);
        lru.push(top);
        return btmkey;
        
    }
    //Function for storing key-value pair.
    void SET(int &key, int &value)
    {
        //key present
        if(maps.find(key) != maps.end())
        {
            //delete val
            findValStack(key, value);
            //push val
            lru.push({key, value});
            maps[key] = value;
        }
        else
        {
            if(lru.size() == capacity)
            {
                //delete least reacently used
                int bottomkey = deleteBottom();
                //erase bottom key
                maps.erase(bottomkey);
                lru.push({key, value});
                maps[key] = value;
            }
            else if(lru.size() < capacity)
            {
                lru.push({key, value});
                maps[key] = value;
            }
        }
    }
