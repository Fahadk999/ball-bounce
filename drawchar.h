class DrawChar
{
    private:
        struct Position
        {
            int x = 0;
            int y = 0;
        } pos;
        char ch = '#';

    public:
        DrawChar () = default;
        DrawChar (int x, int y, char ch)
            :   pos{x, y}, ch(ch) {}

        Position getPosition () const { return pos; }
        char getChar () const { return ch; }

        void setChar (char ch) { this->ch = ch; }
        void move (int newX, int newY);
        void setPosition (int x, int y);
};
