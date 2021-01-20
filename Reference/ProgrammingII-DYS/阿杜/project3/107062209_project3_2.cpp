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
    int x, y;
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
        return value[this->x][this->y];
	}
};

std::array<std::array<int, SIZE>, SIZE> board;
std::vector<Point> next_valid_spots;

class State{
public:
    std::array<std::array<int,SIZE>,SIZE> cur_board;
    int heuristic;
    int state_player = player;
    int prevx = -1;
    int prevy = -1;
    std::vector<Point> next_valid_nodes;
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
    int get_next_player(int player) const {
        return 3 - player;
    }
    bool is_spot_on_board(Point p) const {
        return 0 <= p.x && p.x < SIZE && 0 <= p.y && p.y < SIZE;
    }
    bool is_disc_at(Point p, int disc) const {
        if (!is_spot_on_board(p))
            return false;
        if (cur_board[p.x][p.y] != disc)
            return false;
        return true;
    }
    void set_heuristic(int x,int y){
        this->heuristic = value[x][y];
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
    void get_valid_spots(){
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
        this->next_valid_nodes = next_valid_spots;
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
        // Choose random spot. (Not random uniform here)
        //int index = (rand() % n_valid_spots);
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
