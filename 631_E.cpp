/*
Author: Nachiket Kanore
Created: Sunday 21 February 2021 11:43:36 PM IST
(ツ) Always tell the truth. That way, you don't have to remember what you said.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int INF = 1e18;
 
struct ConvexHullDynamic
{
    struct Line
    {
        int a, b; //y = ax + b
        double xLeft; //Stores the intersection wiith previous line in the convex hull. First line has -INF
 
        enum Type {line, maxQuery, minQuery} type;
        int val;
 
        explicit Line(int aa=0, int bb=0): a(aa), b(bb), xLeft(-INF), type(Type::line), val(0) {}
 
        int valueAt(int x) const
        {
            return a*x + b;
        }
        friend bool isParallel(const Line &l1, const Line &l2)
        {
            return l1.a == l2.a;
        }
        friend double intersectX(const Line &l1, const Line &l2)
        {
            return isParallel(l1, l2)?INF:1.0*(l2.b-l1.b)/(l1.a-l2.a);
        }
        
        bool operator<(const Line& l2) const
        {
            if(l2.type == line)
                return this->a < l2.a;
            if(l2.type == maxQuery)
                return this->xLeft < l2.val;
            if(l2.type == minQuery)
                return this->xLeft > l2.val;
            return 0;
        }
    };
 
    bool isMax;
    set<Line> hull;
 
    bool hasPrev(set<Line>::iterator it)
    {
        return it!=hull.begin();
    }    
    bool hasNext(set<Line>::iterator it)
    {
        return it!=hull.end() && next(it)!=hull.end();
    }
    bool irrelevant(const Line &l1, const Line &l2, const Line &l3)
    {
        return intersectX(l1, l3) <= intersectX(l1, l2);
    }
    bool irrelevant(set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it) && ( 
            (isMax && irrelevant(*prev(it), *it, *next(it))) 
            || (!isMax && irrelevant(*next(it), *it, *prev(it))));
    }
    //Updates xValue of line pointed by it
    set<Line>::iterator updateLeftBorder(set<Line>::iterator it)
    {
        if( (isMax && !hasPrev(it)) || (!isMax && !hasNext(it)))
            return it;
        double val=intersectX(*it, isMax?(*prev(it)):(*next(it)));
        Line temp(*it);
        it=hull.erase(it);
        temp.xLeft=val;
        it=hull.insert(it, temp);
        return it;
    }
 
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}
 
    void addLine(int a, int b) //Add ax + b in logN time
    {
        Line l3=Line(a, b);
        auto it=hull.lower_bound(l3);
 
        //If parallel liune is already in set, one of the lines becomes irrelevant
        if(it!=hull.end() && isParallel(*it, l3))
        {
            if( (isMax && it->b<b) || (!isMax && it->b>b))
                it=hull.erase(it);
            else
                return;
        }
 
        it=hull.insert(it, l3);
        if(irrelevant(it))
        {
            hull.erase(it);
            return;
        }
 
        //Remove lines which became irrelevant after inserting
        while(hasPrev(it) && irrelevant(prev(it)))
            hull.erase(prev(it));
        while(hasNext(it) && irrelevant(next(it)))
            hull.erase(next(it));
 
        //Update xLine
        it=updateLeftBorder(it);
        if(hasPrev(it))
            updateLeftBorder(prev(it));
        if(hasNext(it))
            updateLeftBorder(next(it));
    }
 
    int getBest(int x)
    {
        Line q;
        q.val=x;
        q.type = isMax?Line::Type::maxQuery : Line::Type::minQuery;
 
        auto bestLine=hull.lower_bound(q);
        if(isMax)
            --bestLine;
        return bestLine->valueAt(x);
    }
};

const int N = 2e5 + 5;
int n, a[N], pref[N], orig_ans, delta_left = INF, delta_right = -INF;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i,1,n) {
		cin >> a[i];
		orig_ans += i * a[i];
		pref[i] = pref[i-1] + a[i];
	}
	ConvexHullDynamic left_shift(false), right_shift(true);
	FOR (R,1,n) {
		if (R > 1) {
			int get = pref[R] + left_shift.getBest(R);
			cmin(delta_left, get);
		}
		left_shift.addLine(-a[R], R * a[R] - pref[R]);
	}
	for (int L = n; L; --L) {
		if (L < n) {
			int get = -pref[L-1] + right_shift.getBest(L);
			cmax(delta_right, get);
		}
		right_shift.addLine(a[L], pref[L-1] - L * a[L]);
	}
	cout << max({orig_ans, orig_ans - delta_left, orig_ans + delta_right}) << '\n';
}
