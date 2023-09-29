#include <iostream>
#include <cmath>

using namespace std;

struct point // структура точки
{
    float x;
    float y;
};

float dist(float x1, float y1, float x2, float y2)
{
    return (sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2))); //дистанция по формуле
}
int main()
{
    cout << "count: ";
    int n;
    cin >> n;
    point *a = new point[n];
    float ans = -1;
    int numb;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " x,y: ";
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; i++) // перебор всех точек
    {
        float sm = 0;
        for (int j = 0; j < n; j++)
        {
            sm += dist(a[i].x, a[i].y, a[j].x, a[j].y); // сумма расстояний
        }
        if (sm > ans)
        {
            ans = sm;
            numb = i;
        }
    }
    cout << numb + 1 << ' (' << a[numb].x << ',' << a[numb].y << ') ' << ans << endl;
    return 0;
}