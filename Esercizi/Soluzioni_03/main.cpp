#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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

    rational operator+(const rational& b) const {
        // Porto a e b allo stesso denominatore
        int mcm = den_ / gcd(den_, b.den_) * b.den_;
        int numa = num_ * mcm / den_;
        int numb = b.num_ * mcm / b.den_;
        // Sommo i numeratori
        int s = numa + numb;
        // Riduco ai minimi termini 
        int MCD = gcd(abs(s), mcm);
        return rational{s / MCD, mcm / MCD};
    }
    bool operator==(const rational& other) const {
        return num_==other.num_ && den_==other.den_;
    }

    bool operator<(const rational& other) const {
        // Porto a e b allo stesso denominatore
        int mcm = den_ / gcd(den_, other.den_) * other.den_;
        int numa = num_ * mcm / den_;
        int numb = other.num_ * mcm / other.den_;
        return numa < numb;
    }

    bool operator>(const rational& other) const {
        //return !(*this<other) && !(*this==other);
        return !(*this<other || *this==other);
    }

    friend std::ostream& operator<<(std::ostream& os, const rational& r) {
        os << r.num_;
        if (r.den_ != 1) {
            os << "/" << r.den_;
        }
        return os;
    }
};

int main()
{
    std::vector<rational> v = { rational(1,2), 1, rational(-3,4) };

    std::sort(begin(v), end(v), std::greater<rational>());

    copy(begin(v), end(v), std::ostream_iterator<rational>(std::cout,", "));

    return 0;
}