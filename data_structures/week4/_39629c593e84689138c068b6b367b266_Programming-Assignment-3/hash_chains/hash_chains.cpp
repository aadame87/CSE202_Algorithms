#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::deque;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    //vector<string> elems;
    vector< deque< string > > data_;
    vector<string> results;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count),
    data_(bucket_count), results() {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) {
        string r0 = was_found ? "yes" : "no";
        results.push_back(r0);
    }

    void insert(string s){
      size_t bk = hash_func(s);
      auto &q = data_[bk];
      //if (std::find(data_[bk].begin(),data_[bk].end(),s)==data_[bk].end()){
        //data_[bk].push_front(s);
      //}
      if (std::find(q.begin(),q.end(),s)==q.end())
        q.push_front(s);
    }

    bool find(string s){
      size_t bk = hash_func(s);
      return std::find(data_[bk].begin(),data_[bk].end(),s)!=data_[bk].end();

    }

    void remove(string s){
      size_t bk = hash_func(s);
      auto i = std::find(data_[bk].begin(),data_[bk].end(),s);
      if (i!=data_[bk].end()){
        data_[bk].erase(i);
      }
    }

    string check(size_t i){
      string s="";
      if (data_[i].empty()) return s;
      else
        for (auto iter = data_[i].begin();iter!=data_[i].end();++iter){
          s = s + *iter + " ";
        }
        return s;


    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            //for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                //if (hash_func(elems[i]) == query.ind)
                    //std::cout << elems[i] << " ";
            //std::cout << "\n";
            string s = check(query.ind);
            results.push_back(s);
        } else {
            //vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                //writeSearchResult(it != elems.end());
                writeSearchResult(find(query.s));
            else if (query.type == "add") {
                //if (it == elems.end())
                    //elems.push_back(query.s);
                insert(query.s);

            } else if (query.type == "del") {
                //if (it != elems.end())
                    //elems.erase(it);
                remove(query.s);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());

        for (const auto& r : results)
            std::cout << r << "\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
