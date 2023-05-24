#include <stdio.h>
void printVsetkyHodnoty (double m, double T, double v, double H, double g, double vsoft, double dt){
    printf("m=%.3lf\nT=%.3lf\nv0=%.3lf\nH=%.3lf\ng=%.3lf\nvsoft=%.3lf\ndt=%.3lf\n", m, T, v, H, g, vsoft, dt);
}

double vypocetA (double T, double m){
    return T/m;
}

double vypocetdf (double A, double g, double H){
    return ((A-g)*H)/A;
}

int vypocetMotora (double h0, double H, double vsoft, double df, double v){
    if (H < h0-df){
        if (v < vsoft) return 1;
        else return 0;
    }
    else return 0;
}

double vypocetVysky (double H, double v, double dt, double A, double g, int s){
    if (s == 0) return (H+v*dt)+((-g)*(dt*dt)/2);
    else return (H+v*dt)+((A-g)*(dt*dt)/2);
}

double vypocetRychlosti(double v, double A, double g, double dt, int s){
    if (s == 0) return v+(-g*dt);
    else return v+((A-g)*dt);
}
void vypisSondy(double t, double H, double v, int s){
    if (s == 1 || s == 0) printf("t=%.3lf h=%.3lf v=%.3lf s=%i\n", t, H, v, s);
    else printf("t=%.3lf h=%.3lf v=%.3lf\n", t, H, v);
}

void main() {
    double m, T, v, H, g, vsoft, dt, df, A, t = 0.000, total = 0.000, h0; int s = 0;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &m, &T, &v, &H, &g, &vsoft, &dt);
    h0 = H;

    printVsetkyHodnoty(m, T, v, H, g, vsoft, dt);
    A = vypocetA(T, m);
    printf("df=%.3lf\n", df = vypocetdf(A, g, H));
    while (1 == 1){
        s = vypocetMotora(h0, H, vsoft, df, v);
        vypisSondy(t, H, v, s);
        H = vypocetVysky(H, v, dt, A, g, s);
        v = vypocetRychlosti(v, A, g, dt, s);
        if (s == 1) total += dt;
        t += dt;
        if (H <= 0){
            vypisSondy(t, H, v, 2);
            break;
        }
    }
    printf("total=%.3lf", total);
}