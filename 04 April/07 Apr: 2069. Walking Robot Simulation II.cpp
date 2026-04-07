class Robot {
private:
    int w, h, per, pos;
    bool moved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        per = 2 * (width + height - 2);
        pos = 0;
        moved = false;
    }
    
    void step(int num) {
        moved = true;
        pos = (pos + num) % per;
    }
    
    vector<int> getPos() {
        int p = pos;
        if (p < w) return {p, 0};
        if (p < w + h - 1) return {w - 1, p - (w - 1)};
        if (p < 2 * w + h - 2) return {(w - 1) - (p - (w + h - 2)), h - 1};
        return {0, per - p};
    }
    
    string getDir() {
        int p = pos;
        if (p == 0) return moved ? "South" : "East";
        if (p < w) return "East";
        if (p < w + h - 1) return "North";
        if (p < 2 * w + h - 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
