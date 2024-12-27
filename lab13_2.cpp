#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool[][M], int, int, int);

void showImage(const bool[][M]);

int main()
{
    bool image[N][M] = {};
    int s, x, y;
    do
    {
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image, s, x, y);
    } while (s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool paper[][M], int s, int x, int y)
{
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (sqrt(pow(i - x, 2.0) + pow(j - y, 2.0)) <= s - 1)
            {
                paper[i][j] = true;
            }
        }
    }
}

void showImage(const bool paper[][M])
{
    for (int y = -1; y < N+1; y++)
    {
        for (int x = -1; x < M+1; x++)
        {
            if (y==-1 || y==N)
            {
                cout << "-";
            }
            else
            {
                if (x==-1||x==M)
                {
                    cout << "|";
                }
                else 
                {
                    if (paper[y][x])
                        cout << "*";
                    else 
                        cout << " ";
                }
            }
        }
        cout << "\n";
    }
}