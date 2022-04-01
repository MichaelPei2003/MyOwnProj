#include <stdio.h>
#include <stdbool.h>
#include <process.h>

//default maze
int maze[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
int m = 8, n = 8;

struct Route {
    int i;
    int j;
    int direction;
};

struct Stack {
    struct Route route[100];
    int top;//top of stack
};

void CreateMaze() {
    int sel, i, j, cnt = 0;
    printf("Use default maze or create new one by yourself?\n");
    printf("0 = Use default, 1 = create new one.\nPlease enter:");
    scanf("%d", &sel);
    if (sel == 0) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%3d", maze[i][j]);
                cnt++;
                if (cnt % 10 == 0) {
                    printf("\n");
                }
            }
        }
        return;
    }
    printf("Maze format: Size = 10x10, 1 = wall, 0 = road, point[1][1]&[8][8] is enter and exit of the maze.\nDO NOT FORGET TO CREATE THE OUTER WALL!\n");
    printf("Please enter maze:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
}

bool path(int xs, int ys, int xe, int ye) {//x start, y start, x end, y end
    int i, j, k, di, find;//di = direction
    struct Stack st;
    st.top = -1;
    st.top++;
    st.route[st.top].i = xs;
    st.route[st.top].j = ys;
    st.route[st.top].direction = -1;//set default as going nowhere
    maze[xs][ys] = -1;//set start point as wall
    while (st.top > -1) {//member in stack
        i = st.route[st.top].i;
        j = st.route[st.top].j;
        di = st.route[st.top].direction;
        if (i == xe && j == ye) {//reached exit, print route
            printf("\nThe route found is:\n");
            for (k = 0; k <= st.top; k++) {//Print members of stack, k is top of stack
                printf("(%d, %d)", st.route[k].i, st.route[k].j);
                if ((k + 1) % 5 == 0) {
                    printf("\n");
                }
            }
            return true;
        }
        find = 0;
        while (di < 3 && find == 0) {//di>4 -> no point around available
            di++;
            switch (di) {
                case 0://step left
                    i = st.route[st.top].i - 1;
                    j = st.route[st.top].j;
                    break;
                case 1://step down
                    i = st.route[st.top].i;
                    j = st.route[st.top].j + 1;
                    break;
                case 2://step right
                    i = st.route[st.top].i + 1;
                    j = st.route[st.top].j;
                    break;
                case 3://step up
                    i = st.route[st.top].i;
                    j = st.route[st.top].j - 1;
                    break;
                default://unexpected value occurs
                    printf("Error, exit program.");
                    exit(0);
            }
            if (maze[i][j] == 0) {
                find = 1;
            }
        }
        if (find == 1) {
            st.top++;
            st.route[st.top].i = i;
            st.route[st.top].j = j;
            st.route[st.top].direction = -1;
            maze[i][j] = -1;//set as stepped
        } else {//no route forward found, step back
            maze[st.route[st.top].i][st.route[st.top].j] = -1;//set current position as available
            st.top--;//exit wrong position from stack
        }
    }
    return false;
}

int main() {
    CreateMaze();
    if (!path(1, 1, m, n)) {
        printf("Maze was not set properly, please check and run program again.");
    }
    return 0;
}