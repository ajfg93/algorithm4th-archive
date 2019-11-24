#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
bool isSorted(vector<T> &ivec){
    for(size_t i = 0; i < ivec.size() - 1; i++){
        if(ivec[i] > ivec[i+1])
            return false;
    }
    return true;
}

template<typename T>
class MergeTopDown{
public:
    static void sort(std::vector<T> &a, std::vector<T> &aux, unsigned &count){
        count = 0;
        sort(a, aux, 0, a.size() - 1, count);
    }
private:
    static const int cutoff = 7;
    static void sort(std::vector<T> &a, std::vector<T> &aux, int lo, int hi, unsigned &count){
        // if(hi - lo <= cutoff){
        //     InsertionSort::sort(a, lo, hi);
        //     return;
        // }
        int mid = lo + (hi - lo) / 2;
        if(hi <= lo) return;
        sort(a, aux, lo, mid, count);
        sort(a, aux, mid+1, hi, count);
        merge(a, aux, lo, mid, hi, count);
    }
    static void merge(std::vector<T> &a, std::vector<T> &aux, int lo, int mid, int hi, unsigned &count){
        // if(a[mid] < a[mid+1])
        //     return;

        for(int k = lo; k <= hi; k++){
            aux[k] = a[k];
        }

        int i = lo, j = mid+1;

        for(int k = lo; k <= hi; k++){
            if(i > mid){
                a[k] = aux[j++];
            }else if (j > hi){
                a[k] = aux[i++];
            }else if(aux[i] <= aux[j]){
                //还有这里，那应该不是stable sort了
                a[k] = aux[i++];
            }else{
                //修改了这里
                count += mid - i + 1;
                a[k] = aux[j++];
            }
        }
    }
};


int main(){
//     vector<char> ivec = {'E','X','A','M','P','L','E'};
//     vector<char> ivec = {'E','X','A','M'};

    vector<char> ivec = {'D','C','B', 'A'};
//    vector<char> ivec = {'D','C', 'B'};
//    vector<char> ivec = {'P','L', 'E'};
//    vector<char> ivec = {'E','E', 'A', 'E'};

    vector<char> aux(ivec.size());
    unsigned cnt = 0;
    MergeTopDown<char>::sort(ivec, aux, cnt);
    assert(isSorted(ivec));
    cout << cnt << endl;
    return 0;
}