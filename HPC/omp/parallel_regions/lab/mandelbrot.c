#include <stdio.h>
#include <omp.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    
    if (argc != 5) {
        printf("you should pass from comand line: width of grid, height of grid, number of threads and number of maximum iterations\n");
        return 1;
    }

    //
    //
    /* we will assume that num_threads is smaller or equal to pix_height */ 
    //
    //

    const unsigned int pix_width = atoi(argv[1]);   // number of pixels in width 
    const unsigned int pix_height = atoi(argv[2]);   // number of pixels in height 
    int num_threads = atoi(argv[3]);
    const int max_iter = atoi(argv[4]);    // maximum number of iterations (after that we
                                           // assume that the point is in the set)

    // we take a square grid of side 40 centered in the origin
    const short int x_min = -2;
    const short int x_max = 2;
    const short int y_min = -2;
    const short int y_max = 2;

    // x and y distances between pixels 
    const double delta_x = (double)(x_max - x_min) / pix_width;
    const double delta_y = (double)(y_max - y_min) / pix_height;

    const unsigned int N_lines = pix_height / num_threads;   // number of lines for each num_threads
    const unsigned int N_lines_rem = pix_height % num_threads;   // number of remaining lines
    
    int grid[pix_width * pix_height];   // array of pixels

    omp_set_num_threads(num_threads);
   #pragma omp parallel
    {
        int myid = omp_get_thread_num();
        double x[pix_width];   // array of x coordinates
        double y[N_lines];   // array of y coordinates
        

        // initializing the x and y coordinates
        for (int i = 0; i < pix_width; i++)
            x[i] = x_min + i * delta_x;

        const double y_min_id = y_min + myid * N_lines;
        for (int i = 0; i < N_lines; i++)
            y[i] = y_min_id + i * delta_y;


        // computing the mandelbrot set 
        for (int i=0; i<N_lines; i++) {

            double yy2 = y[i] * y[i];
            for (int j=0; j<pix_width; j++) {

                double xx = x[j];
                double xx2 = xx * xx;
                double z2 = 0;   // square of the term of the series
                int iter = 0;   // iteraton counter
                
                while (z2 < 4 && iter < max_iter) {
                    double z2 = z2*z2 + xx2 + 2*xx*z2 + yy2;
                    iter++;
                }
                
                int offset = myid * N_lines * pix_width;
                grid[offset + i*pix_width + j] = iter;
            }
        }
    }


    // taking care of the remaining lines 
    if (N_lines_rem != 0) {

        const double y_offset = y_max - N_lines_rem * delta_y;
        const unsigned int offset = num_threads * N_lines * pix_width;

        num_threads = N_lines_rem;

        omp_set_num_threads(num_threads);
       #pragma omp parallel
        {
            int myid = omp_get_thread_num();
            double x[pix_width];   // array of x coordinates
            double yy = y_offset + myid * delta_y;
            double yy2 = yy * yy;

            for (int j=0; j<pix_width; j++) {

                double xx = x[j];
                double xx2 = xx * xx;
                double z2 = 0;   // square of the term of the series
                int iter = 0;   // iteraton counter
                
                while (z2 < 4 && iter < max_iter) {
                    double z2 = z2*z2 + xx2 + 2*xx*z2 + yy2;
                    iter++;
                }
                
                grid[offset + myid*pix_width + j] = iter;
            }
        }
    }


    // printing the grid
    for (int i=pix_height-1; i>=0; i--) {
        for (int j=pix_width-1; j>=0; j--) {
            printf("%d ", grid[i*pix_width + j]);
        }
        printf("\n");
    }
            

    return 0;
}
