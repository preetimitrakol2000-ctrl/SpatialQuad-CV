# SpatialQuad-CV

A lightweight computer vision preprocessing architecture built entirely from scratch in C99. By utilizing a Quadtree data structure, this engine recursively downsamples and compresses multi-dimensional pixel arrays based on spatial homogeneity, mimicking foundational layers in structural object detection pipelines.

## 📊 Computational Complexity
* **Tree Construction:** $O(N \log N)$ where $N$ is the total pixel count.
* **Spatial Query Range:** $O(\log N)$
* **Memory Optimization:** Dynamically deallocates uniform regions into unified leaf nodes.

## 📦 Compilation & Execution
```bash
gcc main.c quadtree.c -o spatialquad -lm
./spatialquad
