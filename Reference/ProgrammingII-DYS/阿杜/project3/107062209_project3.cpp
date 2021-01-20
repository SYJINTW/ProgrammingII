#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>


int player;
const int SIZE = 8;

std::array<std::array<int, SIZE>, SIZE> value = {{{200,-100,100,75,75,100,-100,200},
{-100,-150,100,50,50,100,-150,-100},
{100,100,100,60,60,100,100,100},
{75,50,60,60,60,60,50,75},
{75,50,60,60,60,60,50,75},
{100,100,100,60,60,100,100,100},
{-100,-150,100,50,50,100,-150,-100},
{200,-100,100,75,75,100,-100,200}}};

struct Point {
    int x, y, point_value;
	Point() : Point(0, 0) {}
	Point(float x, float y) : x(x), y(y) {}
	bool operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Point& rhs) const {
		return !operator==(rhs);
	}
	Point operator+(const Point& rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	int set_value(){
        return point_value = value[this->x][this->y];
	}
};

std::array<std::array<int, SIZE>, SIZE> board;
std::vector<Point> next_valid_spots;

class State{
public:
    enum SPOT_STATE {
        EMPTY = 0,
        BLACK = 1,
        WHITE = 2
    };
    std::array<std::array<int,SIZE>,SIZE> cur_board;
    int heuristic;
    int eat;
    int state_player = player;
    int prevx = -1;
    int prevy = -1;
    std::vector<Point> next_valid_nodes;
    std::array<int, 3> disc_count;
    const std::array<Point, 8> directions{{
    Point(-1, -1), Point(-1, 0), Point(-1, 1),
    Point(0, -1), /*{0, 0}, */Point(0, 1),
    Point(1, -1), Point(1, 0), Point(1, 1)
    }};

    State(std::array<std::array<int,SIZE>,SIZE> board) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                this->cur_board[i][j] = board[i][j];
        get_valid_spots();
    }

    State(State& s) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cur_board[i][j] = s.cur_board[i][j];
        heuristic = s.heuristic;
        get_valid_spots();
    }

    void update(int newx,int newy){
        this->cur_board[newx][newy] = this->state_player;
        get_valid_spots();
        set_heuristic(newx,newy);
        this->prevx = newx;
        this->prevy = newy;
    }
    void set_heuristic(int x,int y){
        int eat_weight;
        if(disc_count[EMPTY]>=50)
            eat_weight = 5;
        else if(disc_count[EMPTY]>=30)
            eat_weight = 10;
        else if(disc_count[EMPTY]>=10)
            eat_weight = 25;
        this->heuristic = value[x][y]*1 + (this->eat)*eat_weight;
    }
    int get_next_player(int player) const {
        return 3 - player;
    }
    bool is_spot_on_board(Point p) const {
        return 0 <= p.x && p.x < SIZE && 0 <= p.y && p.y < SIZE;
    }
    int get_disc(Point p) const {
        return board[p.x][p.y];
    }
    void set_disc(Point p, int disc) {
        board[p.x][p.y] = disc;
    }
    bool is_disc_at(Point p, int disc) const {
        if (!is_spot_on_board(p))
            return false;
        if (cur_board[p.x][p.y] != disc)
            return false;
        return true;
    }
    bool is_spot_valid(Point center) const {
        if (cur_board[center.x][center.y] != 0)
            return false;
        for (Point dir: directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(this->state_player)))
                continue;
            p = p + dir;
            while (is_spot_on_board(p) && cur_board[p.x][p.y] != 0) {
                if (is_disc_at(p, player))
                    return true;
                p = p + dir;
            }
        }
        return false;
    }
    std::vector<Point> get_valid_spots(){
        std::vector<Point> valid_spots;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Point p = Point(i, j);
                if (board[i][j] != 0)
                    continue;
                if (is_spot_valid(p))
                    valid_spots.push_back(p);
            }
        }
        this->next_valid_nodes = valid_spots;
        return valid_spots;
    }

    void flip_discs(Point center) {
        for (Point dir: directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(state_player)))
                continue;
            std::vector<Point> discs({p});
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, state_player)) {
                    for (Point s: discs) {
                        set_disc(s, state_player);
                    }
                    disc_count[state_player] += discs.size();
                    disc_count[get_next_player(state_player)] -= discs.size();
                    break;
                }
                discs.push_back(p);
                p = p + dir;
            }
        }
    }
    void reset() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = EMPTY;
            }
        }
        board[3][4] = board[4][3] = BLACK;
        board[3][3] = board[4][4] = WHITE;
        state_player = BLACK;
        disc_count[EMPTY] = 8*8-4;
        disc_count[BLACK] = 2;
        disc_count[WHITE] = 2;
    }
    std::vector<Point> get_valid_spots() const{
        std::vector<Point> valid_spots;
        valid_spots = next_valid_spots;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Point p = Point(i, j);
                if (board[i][j] != EMPTY)
                    continue;
                if (is_spot_valid(p))
                    valid_spots.push_back(p);
            }
        }
        return valid_spots;
    }
    bool put_disc(Point p) {
        set_disc(p, state_player);
        disc_count[state_player]++;
        disc_count[EMPTY]--;
        flip_discs(p);
        // Give control to the other player.
        state_player = get_next_player(state_player);
        next_valid_nodes = get_valid_spots();
        // Check Win
        if (next_valid_spots.size() == 0) {
            state_player = get_next_player(state_player);
            next_valid_spots = get_valid_spots();
            if (next_valid_spots.size() == 0) {
                // Game ends
                int white_discs = disc_count[WHITE];
                int black_discs = disc_count[BLACK];
                /*if (white_discs == black_discs) winner = EMPTY;
                else if (black_discs > white_discs) winner = BLACK;
                else winner = WHITE;*/
            }
        }
        return true;
    }

};



int minimax(State cur_state,int depth,int a,int b,int cur_player){
    int value;
    if(depth==3||cur_state.next_valid_nodes.size()==0){
        return cur_state.heuristic;
    }
    if(cur_player==player){
        int value = -200;
        for(auto child:cur_state.next_valid_nodes){
            State next_state = cur_state;
            next_state.update(child.x,child.y);
            if(next_state.heuristic>value){
                value = next_state.heuristic;
            }
            next_state.eat = next_state.disc_count[cur_player]-cur_state.disc_count[cur_player];
            minimax(next_state,depth+1,a,b,3-player);
            a = a > value ? a : value;
            if(a>=b)
                break;
        }
        return value;
    }
    else {
        int value = 250;
        for(int i=0;i<cur_state.next_valid_nodes.size();i++){
            Point child = cur_state.next_valid_nodes[i];
            State next_state = cur_state;
            next_state.update(child.x,child.y);
            if(next_state.heuristic<value){
                value = next_state.heuristic;
            }
            minimax(next_state,depth+1,a,b,3-cur_player);
            if(b<=a)
                break;
        }
        return value;
    }
}


void read_board(std::ifstream& fin) {
    fin >> player;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> board[i][j];
        }
    }
}

void read_valid_spots(std::ifstream& fin) {
    int n_valid_spots;
    fin >> n_valid_spots;
    int x, y;
    for (int i = 0; i < n_valid_spots; i++) {
        fin >> x >> y;
        next_valid_spots.push_back({x, y});
    }
}

void write_valid_spot(std::ofstream& fout) {
    int n_valid_spots = next_valid_spots.size();
    // Keep updating the output until getting killed.
    while (true) {
        State cur_state(board);
        Point p;
        int value = minimax(cur_state,0,250,-200,cur_state.state_player);
        for(int i = 0;i < n_valid_spots;i++){
            if(next_valid_spots[i].set_value()==value)
                p = next_valid_spots[i];
        }
        // Remember to flush the output to ensure the last action is written to file.
        fout << p.x << " " << p.y << std::endl;
        fout.flush();
    }
}



int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    read_valid_spots(fin);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}
