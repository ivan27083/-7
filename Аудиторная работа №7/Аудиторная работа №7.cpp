#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

class Backtrack {
    int n;
    vector<Point> figures;
public:
    Backtrack() {
        n = 8;
    }
    void backtrack(int current_y) {
        for (int i = 1; i <= n; i++) {
            if (!intersect(i, current_y)) {
                figures.push_back({ i, current_y });
                if (figures.size() != n) {
                    backtrack(current_y + 1);
                    figures.pop_back();
                }
            }
        }
        if (figures.size() != n) {
            if (figures.size() == current_y) figures.pop_back();
        }
        else {
            for (int i = 0; i < figures.size(); i++) {
                cout << "( " << figures[i].x << ", " << figures[i].y << " )" << "  ";
            }
            cout << endl;
        }
    }
    bool intersect(int x, int y) {
        for (int i = 0; i < figures.size(); i++)
        {
            if (figures[i].x == x || figures[i].y == y || abs(figures[i].x - x) == abs(figures[i].y - y)) return true;
        }
        return false;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    Backtrack chess;
    chess.backtrack(1);

    return 0;
}
