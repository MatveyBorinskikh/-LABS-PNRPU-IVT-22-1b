#ifndef EDGE_H
#define EDGE_H


class EDGE
{
public:
    EDGE();
    EDGE(int X_from, int Y_from, int X_to, int Y_to, int Weight, int Type);

public:
    int x_from;
    int y_from;
    int x_to;
    int y_to;
    int weight;
    int type;
};

#endif // EDGE_H
