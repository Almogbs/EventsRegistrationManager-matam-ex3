/** Exceptions */
class BadInput : public std::exception {};


bool isLegalInput(int start, int step, int stop, int size){
    if(start < 0 || start >= size || stop < 0 || stop > size || step <= 0){
        return false;
    }
    return true;
}


template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop){
    if(!isLegalInput(start, step, stop, vec.size())){
        throw BadInput();
    }
    std::shared_ptr<std::vector<T>> sliced(new std::vector<T>);
    if(start >= stop){
        return *sliced;
    }
    for(int i = start; i < stop; i += step){
        sliced->push_back(vec[i]);
    }
    return *sliced;
}


class A {
public:
    std::vector<std::shared_ptr<int>> values;
    void add(int x){ 
        std::shared_ptr<int> new_int(new int(x));
        values.push_back(new_int); 
    }
};


int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
     sliced.values = slice(a.values, 1, 1, 4); 
     *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}