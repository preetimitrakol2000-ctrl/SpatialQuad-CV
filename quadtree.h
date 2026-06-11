#ifndef QUADTREE_H
#define QUADTREE_H

typedef struct QuadNode {
    int x, y, size;
    double mean_intensity;
    int is_leaf;
    struct QuadNode* nw;
    struct QuadNode* ne;
    struct QuadNode* sw;
    struct QuadNode* se;
} QuadNode;

QuadNode* create_quad_node(int x, int y, int size);
QuadNode* build_spatial_tree(int** image, int x, int y, int size, double threshold);
void free_quad_tree(QuadNode* root);

#endif
