#include <bits/stdc++.h>
#include "lodepng.h" // processing pngs. Credit to Lode Vandevenne
#include <windows.h>

using namespace std;
using namespace lodepng;

int main()
{
    string file = "City.png";

    vector<unsigned char> image;
    unsigned width, height;

    unsigned error = decode(image, width, height, file);
    if (error)
    {
        cout << "error " << error << lodepng_error_text(error) << endl;
    }

    vector<vector<vector<int> > > data(height, vector<vector<int> >(width, vector<int> (4, 0)));
    int t = 0;
    for (int x = 0; x < height; x++)
    {
        for(int y = 0; y < width; y++)
        {
            for(int z = 0; z < 4; z++)
            {
                data[x][y][z] = image[t];
                t++;
            }
        }
    }
    //Vardan's Code Here
    for (int x = 0; x < height; x+=5)
    {
        for (int y = 0; y < width; y+=10)
        {
            if (data[x][y][0] == data[x][y][1] && data[x][y][1] == data[x][y][2])
            {
                continue;
            }
            int alpha = data[x][y][3];
            float Rnew = (600 * data[x][y][0]/255)+ 1400;
            float Gnew = (600 * data[x][y][1]/255)+ 800;
            float Bnew = (600 * data[x][y][2]/255) + 200;
//Beep Function - (200-2000) ------- Beep( 750, 300 );  ------  example of beep Function in use
            if (alpha < 50)
            {
                Beep(Rnew, 200);
                Beep(Gnew, 200);
                Beep(Bnew, 200);
            }
            else if (alpha< 100)
            {
                Beep(Rnew, 200);
                Beep(Bnew, 200);
                Beep(Gnew, 200);
            }
            else if (alpha< 100)
            {
                Beep(Bnew, 200);
                Beep(Gnew, 200);
                Beep(Rnew, 200);
            }
            else if (alpha < 150)
            {
                Beep(Bnew, 200);
                Beep(Rnew, 200);
                Beep(Gnew, 200);
            }
            else if (alpha < 200)
            {
                Beep(Gnew, 200);
                Beep(Bnew, 200);
                Beep(Rnew, 200);
            }
            else
            {
                Beep(Bnew, 200);
                Beep(Gnew, 200);
                Beep(Rnew, 200);
            }
        }
    }
    return 0;
}
