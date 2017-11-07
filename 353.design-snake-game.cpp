#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int rs[4] = {0, 0, 1, -1};
const int cs[4] = {1, -1, 0, 0};

struct KSPoint {
  int x, y;
  KSPoint() { }
  KSPoint(int d1, int d2) : x(d1), y(d2) {}
  KSPoint(const KSPoint& p) {
    x = p.x, y = p.y;
  }
  bool operator < (const KSPoint& rhs) const {
    if (x != rhs.x) return x < rhs.x;
    return y < rhs.y;
  }
};

class SnakeGame {
  set<KSPoint> snake;
  list<KSPoint> path;
  KSPoint cur_food;
  queue<KSPoint> fq;
  int row, col, score;
 public:
  /** Initialize your data structure here.
      @param width - screen width
      @param height - screen height
      @param food - A list of food positions
      E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the
     second is at [1,0]. */
  SnakeGame(int width, int height, vector<pair<int, int>> food) {
    row = height, col = width;
    snake.clear();
    path.clear();
    score = 0;
    fq = queue<KSPoint>();

    path.push_back(KSPoint(0, 0));
    snake.insert(KSPoint(0, 0));

    for (auto& p : food) {
      if (isInBoarder(p.first, p.second)) {
        fq.push(KSPoint(p.first, p.second));
      }
    }
    
    PutFood();
  }

  /** Moves the snake.
      @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
      @return The game's score after the move. Return -1 if game over.
      Game over when snake crosses the screen boundary or bites its body. */
  int move(string direction) {
    int dir = dir2idx(direction);
    int nx = path.front().x + rs[dir], ny = path.front().y + cs[dir];
    if (!isInBoarder(nx, ny)) return -1;

    int tx = path.back().x, ty = path.back().y;

    if (nx != cur_food.x || ny != cur_food.y) {
      path.pop_back();  
      snake.erase(KSPoint(tx, ty));
    }

    if (snake.count(KSPoint(nx, ny))) return -1;
    if (nx == cur_food.x && ny == cur_food.y) {
      ++score;
      PutFood();
    }

    path.push_front(KSPoint(nx, ny));
    snake.insert(KSPoint(nx, ny));

    return score;
  }

  void PutFood() {
    if (fq.size()) {
      cur_food = fq.front();
      fq.pop();
    } else {
      cur_food = KSPoint(-1, -1);
    }
  }

  inline bool isInBoarder(int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  // const int rs[4] = {0, 0, 1, -1};
  // const int cs[4] = {1, -1, 0, 0};
  inline int dir2idx(const string& s) {
    if (s == "U") return 3;
    if (s == "D") return 2;
    if (s == "L") return 1;
    if (s == "R") return 0;
    return -1;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int w, h;
  scanf("%d%d", &w, &h);

  vector<pair<int, int>> food;
  int food_cnt;
  scanf("%d", &food_cnt);
  for (int i = 0; i < food_cnt; ++i) {
    int d1, d2;
    scanf("%d%d", &d1, &d2);
    food.emplace_back(make_pair(d1, d2));
  }

  SnakeGame game(w, h, food);
  int m;
  scanf("%d", &m);
  while (m--) {
    string str;
    cin >> str;
    int ans = game.move(str);
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}
#endif

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
