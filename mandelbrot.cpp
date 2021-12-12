//Ts ts ts. Wer wird denn hier in andrer Leute Code schnüffeln?
//Das hier ist schlechter Code.
//Ich möchte nicht mit diesem Code in Verbindung gebracht werden.
//Dieser Code ist nur hier, damit irgendwas hier ist.
//Also husch husch, verschwinde und mach weiter mit der Übung

#include <iostream>
#include <iomanip>
#include <complex>
#include <sys/ioctl.h>
#include <unistd.h>

#define REAL -0.5
#define IMAG 0
#define ZOOM 1

#define ITERATIONS 1000

void mandelbrot(double xmid, double ymid, double zoom, unsigned long long iterations);

int main(int argc, const char* argv[])
{
    double xmid=REAL;
    double ymid=IMAG;
    double zoom=ZOOM;
    unsigned long long iterations=ITERATIONS;
    if (argc >= 3)
    {
        xmid=atof(argv[1]);
        ymid=atof(argv[2]);
    } 
    if (argc >= 4) zoom=atof(argv[3]);
    if (argc >= 5) iterations=atoll(argv[4]);

    if (zoom!=0)
        mandelbrot(xmid,ymid,1/zoom,iterations);
}

void mandelbrot(double xmid, double ymid, double zoom, unsigned long long iterations)
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    int zeilen=size.ws_row-2;
    int spalten=size.ws_col-20;

    for(int x=0; x<spalten; x=x+10)
        {
            double real=zoom*(double)x/spalten+xmid-zoom/2.0;
            if (x%10==0) std::cout << std::setw(10) << real;
            else std::cout << "          ";
        }
        std::cout << '\n';
        for (int y=0; y<zeilen; y++)
        {
            double imag=-zoom*(double)y/zeilen+ymid+zoom/2.0;
            if (y%5 == 0) std::cout << std::setw(10) << imag;
            else std::cout << "          ";
            for(int x=0; x<spalten; x++)
            {
                double real=2*zoom*(double)x/spalten+xmid-zoom;
                std::complex<double> c(real,imag);
                std::complex<double> z(0,0);
                for (unsigned long long i=0; i<iterations; i++)
                {
                    z=z*z+c;
                    if(std::abs(z)>2)break;
                }
                double betrag=std::abs(z);
                if (betrag < 2) std::cout << '*';
                else std::cout << ' ';
            }
            std::cout << '\n';
        }
}
