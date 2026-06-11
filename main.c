#include <stdio.h>
#include <stdlib.h>
#include "quadtree.h"

int main() {
    printf("🖼️  Initializing SpatialQuad-CV Computer Vision Engine...\n\n");

    int size = 4;
    int** mock_image = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) mock_image[i] = (int*)malloc(size * sizeof(int));

    // Seed raw image data array (High variance quadrant transition)
    mock_image[0][0] = 10;  mock_image[0][1] = 10;  mock_image[0][2] = 250; mock_image[0][3] = 250;
    mock_image[1][0] = 12;  mock_image[1][1] = 10;  mock_image[1][2] = 255; mock_image[1][3] = 250;
    mock_image[2][0] = 10;  mock_image[2][1] = 11;  mock_image[2][2] = 10;  mock_image[2][3] = 12;
    mock_image[3][0] = 12;  mock_image[3][1] = 10;  mock_image[3][2] = 11;  mock_image[3][3] = 10;

    QuadNode* root = build_spatial_tree(mock_image, 0, 0, size, 50.0);

    printf("📈 Spatial Analysis Metrics Computed:\n");
    printf("   • Root Space Processing Level Status: %s\n", root->is_leaf ? "Leaf Node" : "Split Node");
    printf("   • Global Mean Intensity Value: %.2f\n", root->mean_intensity);
    printf("   • North-West Subtree Leaf Flag: %d\n", root->nw->is_leaf);

    for (int i = 0; i < size; i++) free(mock_image[i]);
    free(mock_image);
    free_quad_tree(root);
    return 0;
}
