
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#define DEPTH_MAX 6
#define FLIP_WEIGHT 20
#define STABILITY_WEIGHT 20
using namespace std;
int rand_list[100] = {1,5,7,6,9,2,4,466,2,3,566,78,492,231,48,543,5468,84,31,56,3,54,22,13,4,54,3,2,2354,6,2332,4,446,32121,54,3,3,21};
int num_rand = 0;
std::ofstream fout2("my_log.txt"); //new by me
std::ofstream fstate_value("my_log_state_value.txt");
int score_map[8][8] =
{
    {200 , -100 , 50 , 50 , 50 , 50 , -100 , 200  },
    {-100, -200 , 5  , 5  , 5  , 5  , -200 , -100 },
    {50  , 5    , 10 , 10 , 10 , 10 , 5    ,  50  },
    {50  , 5    , 10 , 5  , 5  , 10 , 5    ,  50  },
    {50  , 5    , 10 , 5  , 5  , 10 , 5    ,  50  },
    {50  , 5    , 10 , 10 , 10 , 10 , 5    ,  50  },
    {-100, -200 , 5  , 5  , 5  , 5  , -200 , -100 },
    {200 , -100 , 50 , 50 , 50 , 50 , -100 , 200  }
};

struct Point {
    int x, y;
	Point() : Point(0, 0) {}
	Point(float x, float y) : x(x), y(y) {}
	Point& operator=(const Point& rhs)
	{
	    this->x = rhs.x;
	    this->y = rhs.y;
	    return *this;
	}
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
};  //new by me
class OthelloBoard {
public:
    enum SPOT_STATE {
        EMPTY = 0,
        BLACK = 1,
        WHITE = 2
    };
    static const int SIZE = 8;
    const std::array<Point, 8> directions{{
        Point(-1, -1), Point(-1, 0), Point(-1, 1),
        Point(0, -1), /*{0, 0}, */Point(0, 1),
        Point(1, -1), Point(1, 0), Point(1, 1)
    }};
    std::array<std::array<int, SIZE>, SIZE> board;
    std::vector<Point> next_valid_spots;
    std::array<int, 3> disc_count;
    int cur_player;
    bool done;
    int winner;
    Point prev_action;
    int num_prev_flip = 0;
    int stability = 0;
private:
    //如果現在是player 1 的話，那3-1=2  next player 2
    int get_next_player(int player) const {
        return 3 - player;
    }

    bool is_spot_on_board(Point p) const {
        return 0 <= p.x && p.x < SIZE && 0 <= p.y && p.y < SIZE;
    }
    int get_disc(Point p) const {
        return board[p.x][p.y];
    }
    //將棋盤p處紀錄下哪個顏色
    void set_disc(Point p, int disc) {
        board[p.x][p.y] = disc;
    }
    //disk(1==黑 2==白) 和p點的顏色是否相符
    bool is_disc_at(Point p, int disc) const {
        if (!is_spot_on_board(p))
            return false;
        if (get_disc(p) != disc)
            return false;
        return true;
    }
    bool is_spot_valid(Point center) const {
        //這點已經有子了
        if (get_disc(center) != EMPTY)
            return false;
        for (Point dir: directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            //若現在是黑棋下，
            if (!is_disc_at(p, get_next_player(cur_player)))
                continue;
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, cur_player))
                    return true;
                p = p + dir;
            }
        }
        return false;
    }
    //處理落子之後的翻轉
    void flip_discs(Point center) {

        int flip_before_n = disc_count[cur_player];
        for (Point dir: directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(cur_player))) //若是我這個方向的鄰居並非對手的話就跳過
                continue;

            std::vector<Point> discs({p});

            p = p + dir; //再往同個方向推一顆
            //確認p點非空的
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, cur_player)) {
                    for (Point s: discs) {
                        set_disc(s, cur_player);
                    }

                    //fstate_value<<"before  flip number = "<<num_prev_flip<<endl;
                    disc_count[cur_player] += discs.size();

                    //num_prev_flip += discs.size();

                    //fstate_value<<"after  flip number = "<<num_prev_flip<<endl;
                    disc_count[get_next_player(cur_player)] -= discs.size();
                    break;
                }
                discs.push_back(p);
                p = p + dir;
            }
        }
        num_prev_flip = disc_count[cur_player] - flip_before_n;
        fstate_value<<"  flip number = "<<num_prev_flip<<endl;
    }
public:
    OthelloBoard() {

    }
    OthelloBoard(array<std::array<int, SIZE>, SIZE> input_board)
    {
        this->board = input_board;
    }
    OthelloBoard(const OthelloBoard& in)
    {
        this->board = in.board;
        this-> next_valid_spots = in.next_valid_spots;
        this-> disc_count = in.disc_count;
        this-> cur_player = in.cur_player;
        this->disc_count = in.disc_count;
        this->cur_player = in.cur_player;
        this->done = in.done;
        this->winner = in.winner;
        this->prev_action = in.prev_action;
        this->num_prev_flip = in.num_prev_flip;
        this->stability = in.stability;
    }

    std::vector<Point> get_valid_spots() const {
        std::vector<Point> valid_spots;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Point p = Point(i, j);
                if (board[i][j] != EMPTY)
                    continue;
                if (is_spot_valid(p))
                    valid_spots.push_back(p);
            }
        }
        return valid_spots; //回傳一串valid spot
    }
    //處理落子會發生的所有事情
    bool put_disc(Point p) {
        //在違法地方落子
        if(!is_spot_valid(p)) {
            winner = get_next_player(cur_player);
            done = true;
            return false;
        }

        set_disc(p, cur_player);//將棋盤p處紀錄下哪個顏色
        //set_stability(p);
        prev_action = p;  //new by me 紀錄下是哪一個動作造成現在的盤面
        disc_count[cur_player]++;
        disc_count[EMPTY]--;
        flip_discs(p);
        // Give control to the other player.

        cur_player = get_next_player(cur_player);
        next_valid_spots = get_valid_spots();
        // Check Win
        if (next_valid_spots.size() == 0) {
            cur_player = get_next_player(cur_player);//再換玩家，因為敵方無子可下
            next_valid_spots = get_valid_spots();
            if (next_valid_spots.size() == 0) { //雙方都沒有子可下了
                // Game ends
                done = true;
                int white_discs = disc_count[WHITE];
                int black_discs = disc_count[BLACK];
                if (white_discs == black_discs) winner = EMPTY;
                else if (black_discs > white_discs) winner = BLACK;
                else winner = WHITE;
            }
        }
        return true;
    }
    int set_stability(Point action)
    {

        for(auto d: directions)
        {
            Point p = action;
            bool meet_different = false;
            while(p.x>=0 && p.x<=SIZE &&p.y>=0 && p.y<=SIZE)
            {
                p.x += d.x;
                p.y += d.y;
                if(get_disc(p) == get_next_player(cur_player)) //遇到敵人了
                {
                    meet_different = true;
                    break;
                }
            }

            if(meet_different == false) stability++;
        }
    }


};


int player;
const int SIZE = 8;
std::array<std::array<int, SIZE>, SIZE> board;
std::vector<Point> next_valid_spots;
int build_tree(int ,OthelloBoard,int ,int);  //new by me
void debug(OthelloBoard ,int  ,int );


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
    srand(time(NULL));
    Point p = next_valid_spots[0];
    int max_val = INT_MIN;
    fout2<<"THE ALL PLAYER = "<<player;
    fout2<<"    "<<((player==1)?'O':'X');
    fout2<<"\n\n\n\n";
    int alpha =INT_MIN;
    int beta = INT_MAX;
    for(auto pp: next_valid_spots)
    {
        OthelloBoard new_board(board);
        new_board.cur_player = player;
        new_board.put_disc(pp);
        int n = build_tree(1,new_board,alpha,beta) ;

        //fstate_value<<"for point("<<pp.x<<", "<<pp.y<<")   value = "<<n<<endl;
        if(n>max_val)
        {
            max_val = n;
            alpha = n;

            p = pp;
            fout << p.x << " " << p.y << std::endl;
            fout.flush();
        }
    }
    fstate_value<<"fiinal choose point("<<p.x<<", "<<p.y<<")   value = "<<max_val<<endl;
    // Remember to flush the output to ensure the last action is written to file.
    fout << p.x << " " << p.y << std::endl;
    fout.flush();
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

int build_tree(int depth , OthelloBoard cur_board , int alpha ,int beta)
{
    int state_value;
    if(depth == DEPTH_MAX)//到達我要的深度
    {
        if(cur_board.cur_player!=player)  //若現在棋盤的下個玩家相反的話，那syaye_value也要相反
        {
            state_value = INT_MAX;
            for(auto p:cur_board.next_valid_spots)
            {
                int n= - (score_map[p.x][p.y]+cur_board.num_prev_flip*FLIP_WEIGHT );
                n -= cur_board.stability* STABILITY_WEIGHT;
                //fout2<<"next spots ("<<p.x<<","<<p.y<<")  n= "<<n<<endl;
                if(n<state_value) state_value = n;
            }
            //加負號   因為讓敵人走到c位要加分

        }
        else
        {
            state_value = INT_MIN;
            for(auto p:cur_board.next_valid_spots)
            {
                int n =  score_map[p.x][p.y]+cur_board.num_prev_flip*FLIP_WEIGHT;
                n += cur_board.stability * STABILITY_WEIGHT;
                if(n>state_value) state_value = n;
            }
        }
        debug(cur_board,depth,state_value);
        return state_value;
    }

    if(cur_board.cur_player == player) //取max
    {
        state_value = INT_MIN;
        for(auto pp: cur_board.next_valid_spots)
        {
            if(alpha>beta) break;
            OthelloBoard new_board(cur_board);
            new_board.put_disc(pp);
            int n = build_tree(depth+1,new_board,alpha,beta);
            n -= (score_map[cur_board.prev_action.x][cur_board.prev_action.y] + cur_board.num_prev_flip*FLIP_WEIGHT); //表示prev_avtion是敵方
            n -= cur_board.stability * STABILITY_WEIGHT;
            if(n>state_value)
            {
                alpha = n;
                state_value = n;
            }

        }
    }
    else // 取min
    {
        state_value = INT_MAX;
        for(auto pp: cur_board.next_valid_spots)
        {
            if(alpha>beta) break;

            OthelloBoard new_board(cur_board);
            new_board.put_disc(pp);
            int n = build_tree(depth+1,new_board ,alpha,beta);
            n += score_map[cur_board.prev_action.x][cur_board.prev_action.y] + cur_board.num_prev_flip*FLIP_WEIGHT;
            n += cur_board.stability * STABILITY_WEIGHT;
            if(n<state_value)
            {
                state_value = n;
                beta = n;
            }
        }
    }
    debug(cur_board,depth,state_value);
    return state_value;

}
void debug(OthelloBoard cur_board , int depth ,int value)
{
    vector<Point> next_valid_spots = cur_board.get_valid_spots();
    fout2<<"===============================\n";
    fout2<<"depth = "<<depth<<"\n";
    fout2<<"state value = "<<value<<"\n";
    fout2<<"num_prev_flip = "<<cur_board.num_prev_flip<<"\n";
    fout2<<"prev_action = ("<<cur_board.prev_action.x<<","<<cur_board.prev_action.y<<")\n";
    fout2<<"stability = "<<cur_board.stability<<endl;
    fout2<<"  ";
    for(int i=0;i<SIZE ;i++) fout2<<i<<" ";
    fout2<<"\n------------------------\n";
    for(int i=0;i<SIZE;i++)
    {
        fout2<<i<<"|";
        for(int j=0 ; j<SIZE ;j++)
        {
            if(cur_board.board[i][j] == 0)fout2<<"  ";
            else if(cur_board.board[i][j] == 1)fout2<<"O ";
            else if(cur_board.board[i][j] == 2)fout2<<"X ";
        }
        fout2<<"\n";
    }
    fout2<<"cur_player:  "<<cur_board.cur_player<<endl;
    for(int i=0 ; i<next_valid_spots.size() ;i++)
    {
        fout2<<" "<<next_valid_spots[i].x<<" , "<<next_valid_spots[i].y<<std::endl;
    }
    fout2<<"---------------------------\n\n";
}
