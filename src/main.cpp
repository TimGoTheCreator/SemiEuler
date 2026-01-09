#include"conf.h"
#include<fstream>

int main() {
    Particle earth(0, 0, 0, 0, 5.97e24);
    Particle moon(384400000, 0, 0, 1022, 7.35e22);

    std::ofstream out("positions.csv");
    out << "time,earth_x,earth_y,moon_x,moon_y\n";

    double dt = 50.0; // time step in seconds
    double time = 0.0;

    // write initial positions
    out << time << ',' << earth.x << ',' << earth.y << ',' << moon.x << ',' << moon.y << '\n';

    for(int step = 0; step < 40000; ++step)
    {
        Gravity(earth, moon, dt);
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        moon.x += moon.vx * dt;
        moon.y += moon.vy * dt;

        time += dt;
        out << time << ',' << earth.x << ',' << earth.y << ',' << moon.x << ',' << moon.y << '\n';
    }

    out.close();
}
