#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

#include <math.h>
int main() {

  screen s;
  color c;
  struct matrix *edges;
  edges = new_matrix(4, 4);
  printf("Generated new 4x4 matrix\n");
  print_matrix(edges);
  struct matrix * two;
  two = new_matrix(4,4);
  printf("Making identity matrix\n");
  ident(two);
  print_matrix(two);
  printf("\nAdding edges\n");
  add_edge(edges, 250, 250, 0, 350, 250, 0);
  add_edge(edges, 250, 250, 0, 250, 350, 0);
  add_edge(edges, 250, 250, 0, 150, 250, 0);
  add_edge(edges, 250, 250, 0, 250, 150, 0);
  print_matrix(edges);
  printf("\nMultiplying by identity matrix\n");
  matrix_mult(edges, two);
  print_matrix(edges);
  free_matrix(edges);
  edges = new_matrix(4, 4);
  add_edge(edges, 2, 2, 0, 2, 2, 0);
  add_edge(edges, 2, 2, 0, 2, 2, 0);
  struct matrix * three;
  three = new_matrix(4, 4);
  add_edge(three, 1, 1, 0, 1, 1, 0);
  add_edge(three, 1, 1, 0, 1, 1, 0);
  printf("\nTesting multiplication\n");
  print_matrix(three);
  printf("\n");
  print_matrix(edges);
  matrix_mult(edges, three);
  printf("\nMultiplied\n");
  print_matrix(three);

  free_matrix(edges);
  edges = new_matrix(4, 4);
  add_edge(edges, 250, 250, 0, 350, 250, 0);
  add_edge(edges, 250, 250, 0, 250, 350, 0);
  add_edge(edges, 250, 250, 0, 150, 250, 0);
  add_edge(edges, 250, 250, 0, 250, 150, 0);
  
  c.red = 255;
  c.green = 255;
  c.blue = 255;
  
  /***
  //background to white
  c.red = 255;
  c.green = 255;
  c.blue = 255;
  for (int y = 0; y < YRES; y ++) {
    for (int x = 0; x < XRES; x ++) {
      s[x][y] = c;
    }
  }
  
  //big disc
  c.red = 0;
  c.green = 0;
  c.blue = 0;
  edges = new_matrix(4, 40);
  for (double i = 0; i < 2 * M_PI; i += 0.001) {
    add_edge(edges, 250, 250, 0, 250 + (250 * cos(i)), 250 + (250 * sin(i)), 0);
  }
  draw_lines(edges, s, c);
  free(edges);
  
  //colored stuff
  edges = new_matrix(4, 40);
  c.red = 255;
  c.green = 255;
  c.blue = 255;
  for (double i = 0; i < 2 * M_PI; i += 0.001) {
    if ((i < M_PI / 6 || i > (11 * M_PI / 6)) || (i > 5 * M_PI / 6 && i < 7 * M_PI / 6)) {
      add_edge(edges, 250, 250, 0, 250 + (250 * cos(i)), 250 + (250 * sin(i)), 0);
    }
    else {
      add_edge(edges, 250, 250, 0, 250 + (75 * cos(i)), 250 + (75 * sin(i)), 0);
    }
  }
  draw_lines(edges, s, c);

  //red tape
  free_matrix(edges);
  edges = new_matrix(4, 40);
  for (int i = 0; i < 150; i ++) {
    add_edge(edges, 350, 325 - i, 0, 500, 325 - i, 0);
  }
  c.red = 255;
  c.blue = 0;
  c.green = 0;
  ***/
  draw_lines(edges, s, c);
  save_extension(s, "matrix.png");
  display(s);
  
  free_matrix(edges);
  free_matrix(two);
  free_matrix(three);
}
