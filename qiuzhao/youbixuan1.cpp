
//
// Created by Administrator on 2019/9/3.
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <iostream>

using namespace std;
const double eps = 1e-6;

int i, j, k;
void guassian_kernel(double *kernel, int size, double sigma) {
  double sum = 0;
  double *data = kernel;

  for (i = 0; i < size; ++i) {
    double index = (size >> 1) - i;
    if (size & 1)
      *(data + i) = exp(-(index * index) / (2 * sigma * sigma + eps));
    else {
      index -= 0.5;
      *(data + i) = exp(-(index * index) / (2 * sigma * sigma + eps));
    }
    sum += *(data + i);
  }

  for (i = 0; i < size; ++i) {
    *(data + i) /= sum;
  }
}

void matproduct(double a[], double b[], double c[], int m, int n, int p) {
  for (i = 0; i < m; ++i) {
    for (j = 0; j < p; ++j) {
      double sum = 0;
      for (k = 0; k < n; ++k) {
        sum += a[i * n + k] * b[k * p + j];
      }
      c[i * p + j] = sum;
    }
  }
}

void kernelshow(double a[], int m, int n) {
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      printf("%.7f ", a[i * n + j]);
    }
    printf("\n");
  }
}

void guassian_kernel_2d(double *kernel, int sizeX, int sizeY, double sigmaX, double sigmaY) {
  double *matx = (double *) malloc(sizeX * sizeof(double));
  double *maty = (double *) malloc(sizeY * sizeof(double));
  guassian_kernel(matx, sizeX, sigmaX);
  guassian_kernel(maty, sizeY, sigmaY);
  matproduct(matx, maty, kernel, sizeX, 1, sizeY);
  free(matx);
  free(maty);
}

int main(int argc, char *argv[]) {
  int kernel_size;
  float sigma;
  cin>>kernel_size;
  cin>>sigma;

  int sizeX = kernel_size;
  int sizeY = kernel_size;
  double *kernel = (double *) malloc(sizeX * sizeY * sizeof(double));

  guassian_kernel_2d(kernel, sizeX, sizeY, sigma, sigma);
  kernelshow(kernel, sizeX, sizeY);
  free(kernel);
  return 0;
}