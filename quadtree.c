#include <stdlib.h>
#include <math.h>
#include "quadtree.h"

QuadNode* create_quad_node(int x, int y, int size) {
    QuadNode* node = (QuadNode*)malloc(sizeof(QuadNode));
    node->x = x; node->y = y; node->size = size;
    node->is_leaf = 1;
    node->nw = node->ne = node->sw = node->se = NULL;
    return node;
}

double compute_variance(int** image, int x, int y, int size, double* mean) {
    double sum = 0.0, sq_sum = 0.0;
    int count = size * size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int val = image[x + i][y + j];
            sum += val;
            sq_sum += val * val;
        }
    }
    *mean = sum / count;
    return (sq_sum / count) - ((*mean) * (*mean));
}

QuadNode* build_spatial_tree(int** image, int x, int y, int size, double threshold) {
    double mean = 0.0;
    double variance = compute_variance(image, x, y, size, &mean);
    QuadNode* node = create_quad_node(x, y, size);
    node->mean_intensity = mean;

    // Base Case: If variance is below threshold or minimal bounds hit
    if (variance <= threshold || size <= 2) {
        return node;
    }

    node->is_leaf = 0;
    int half = size / 2;
    node->nw = build_spatial_tree(image, x, y, half, threshold);
    node->ne = build_spatial_tree(image, x, y + half, half, threshold);
    node->sw = build_spatial_tree(image, x + half, y, half, threshold);
    node->se = build_spatial_tree(image, x + half, y + half, half, threshold);
    return node;
}

void free_quad_tree(QuadNode* root) {
    if (root == NULL) return;
    free_quad_tree(root->nw); free_quad_tree(root->ne);
    free_quad_tree(root->sw); free_quad_tree(root->se);
    free(root);
}
