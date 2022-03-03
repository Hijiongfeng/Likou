#include<iostream>
#include<vector>

using namespace std;

template<typename Object>
class matrix{
public:
    matrix(int rows,int cols) : array(rows) {
        for(auto & thisRow : array){
            thisRow.resize(cols);
        }
    }

    matrix(vector<vector<Object>> v) : array{v}{

    }

    matrix(vector<vector<Object>> && v) : array{std::move(v)}{
        
    }

    const vector<Object> & operator[](int row) const {
        return array[row];
    }

    vector<Object> & operator[](int row){
        return array[row];
    }


    int numrows() const{
        return array.size();
    }

    int numcols() const{
        return numrows ? array[0].size() : 0;
    }

private:
    vector<vector<Object>> array;
};


int main(int argc, char const *argv[])
{
    matrix<int> mat(3,3);
    mat[0][0] = 1;
    vector<int> row = mat[0];
    system("pause");
    return 0;
}
