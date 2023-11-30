#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

class rational {
    int num_, den_;
public:
    static int gcd(int m, int n)
    {
        while (n != 0) {
            int tmp = m % n;
            m = n;
            n = tmp;
        }
        return m;
    }

    rational(int num = 0, int den = 1) {
        assert(den != 0);
        if (den > 0) {
            num_ = num;
            den_ = den;
        }
        else {
            num_ = -num;
            den_ = -den;
        }
        int MCD = gcd(abs(num_), den_);
        num_ /= MCD;
        den_ /= MCD;
    }

    rational& operator+=(const rational& b) {
        // Porto a e b allo stesso denominatore
        int mcm = den_ / gcd(den_, b.den_) * b.den_;
        int numa = num_ * mcm / den_;
        int numb = b.num_ * mcm / b.den_;
        // Sommo i numeratori
        int s = numa + numb;
        // Riduco ai minimi termini 
        int MCD = gcd(abs(s), mcm);
        num_ = s / MCD;
        den_ = mcm / MCD;
        return *this;
    }
    friend rational operator+(rational lhs, const rational& rhs) {
        lhs += rhs; // reuse compound assignment
        return lhs; // return the result by value (uses move constructor)
    }

    friend bool operator==(const rational& lhs, const rational& rhs) {
        return lhs.num_==rhs.num_ && lhs.den_==rhs.den_;
    }
    friend bool operator!=(const rational& lhs, const rational& rhs) { return !(lhs == rhs); }

    friend bool operator<(const rational& lhs, const rational& rhs) {
        int mcm = lhs.den_ / gcd(lhs.den_, rhs.den_) * rhs.den_;
        int numa = lhs.num_ * mcm / lhs.den_;
        int numb = rhs.num_ * mcm / rhs.den_;
        return numa < numb;
    }
    friend bool operator> (const rational& lhs, const rational& rhs) { return rhs < lhs; }
    friend bool operator<=(const rational& lhs, const rational& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const rational& lhs, const rational& rhs) { return !(lhs < rhs); }

    friend std::ostream& operator<<(std::ostream& os, const rational& r) {
        os << r.num_;
        if (r.den_ != 1) {
            os << "/" << r.den_;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, rational& r) {
        char slash; 
        int num, den = 1;
        // 5   12 /4  3/2  25/44
        if (!(is >> num)) {
            //is.setstate(std::ios::failbit);
            return is;
        }

        if (is >> slash) {
            if (slash == '/'){
                // Leggo il denominatore
                if (!(is >> den)) {
                    //is.setstate(std::ios::failbit);
                    return is;
                }
            } else {
                //is.setstate(std::ios::failbit);
                is.putback(slash);
            }
        } else {
            if (is.eof()){
                is.clear();
            }
        }

        // Create the rational object with the extracted numerator and denominator
        r = rational(num, den);
        return is;
    }

    size_t GetHash() const {
        std::hash<int> hash_obj;
        auto num_hash = hash_obj(num_);
        auto den_hash = hash_obj(den_);
        return num_hash + den_hash;
    }
    // struct hash{
    //     size_t operator()(const rational &r) const {
    //         return r.GetHash();
    //     }
    // };
};

namespace std {
    template<>
    struct hash<rational> {
        size_t operator()(const rational &r) const {
            return r.GetHash();
        }
    };

}

int main()
{
    std::vector<rational> v = { rational(1,2), 1, rational(-3,4) };

    v[0] += 5;
    v[1] = v[0] + v[2];

    // std::sort(begin(v), end(v), std::greater<rational>());
    // copy(begin(v), end(v), std::ostream_iterator<rational>(std::cout,", "));

    std::ifstream ifs("rational_numbers.txt");

    if (!ifs.is_open()) {
        std::cerr << "Error opening the file.\n";
        return 1;
    }

    std::vector<rational> rational_numbers;
    rational temp_rational;

    while (ifs >> temp_rational) {
        rational_numbers.push_back(temp_rational);
    }

    ifs.close(); // Close the file
    
    std::unordered_map<rational, int> rational_count;

    for (const auto& number : rational_numbers) {
        auto it = rational_count.find(number);
        if (it == rational_count.end()) {
            rational_count[number] = 1;
        } else {
            it->second++;
        }
        //rational_count[number]++;
    }

    // Display the count of each rational number
    for (const auto& pair : rational_count) {
        std::cout << pair.first << " compare " << pair.second << " volte nel file\n";
    }


    // Display the read rational numbers
    std::unordered_set<rational> s(rational_numbers.begin(), rational_numbers.end());
    for (const auto& number : s) {
        std::cout << number << '\n';
    }

    return 0;
}